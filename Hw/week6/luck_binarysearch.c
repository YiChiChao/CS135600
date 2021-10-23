#include <stdio.h>
int num[2000005] = {0};
int binary_search(int target, int left, int right){
    int mid = left + ((right - left)/2);
    if(left > right)return -1;
    if(num[mid] == target)return mid;
    else if(num[mid] > target){
        return binary_search(target, left, mid-1);
    }
    else {
        return binary_search(target, mid+1, right);
    }
    return -1;
}

int main(){
    int n, q;
    int target;
    while(scanf("%d %d", &n, &q) != EOF){
        for(int i = 1; i <= n; ++i){
            scanf("%d", &num[i]);
        }
        for(int i = 0; i < q; ++i){
            int ans;
            scanf("%d", &target);
            ans = binary_search(target, 1, n);
            if(ans == -1)printf("Break your bridge!\n");
            else printf("%d\n", ans);
        }
    }
    return 0;
}