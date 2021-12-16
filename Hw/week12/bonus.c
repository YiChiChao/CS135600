#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int rem[11][200000];
int swap(const void* a, const void* b){
    long long int A = *(long long int*)a;
    long long int B = *(long long int*)b;
    return A-B;
}

long long int upper_bound(long long int bound_target, long long int *arr, int arr_size){
    long long int left = 0, right = arr_size;
    long long int mid;
    while(left < right){
        mid = (left+right)/2;
        if(arr[mid] > bound_target)right = mid;
        else left = mid+1;
    }
    return right;
}

long long int lower_bound(long long int bound_target, long long int *arr, int arr_size){
    long long int left = 0, right = arr_size;
    long long int mid;
    while(left < right){
        mid = (left+right)/2;
        if(arr[mid] >= bound_target)right = mid;
        else left = mid+1;
    }
    return right;
}
int main(){
    int digit;
    int n;
    long long int k;
    while(~(scanf("%d %lld", &n, &k))){
        memset(rem, 0, sizeof(int)*n);
        long long int count = 0;
        for(int i = 0; i < n; ++i){
            long long int ten = 10;
            scanf("%lld", &(rem[0][i]));
            //printf("%lld\n", rem[0][i]);
            for(int j = 1; j < 11; ++j){
                rem[j][i] = ((rem[0][i] % k) * (ten%k)) % k;
                ten *= 10;
                //printf("%lld ", rem[j][i]); 
            }
            //printf("\n");
        }
        for(int j = 1;j < 11; ++j){
            qsort(&(rem[j]), n, sizeof(long long int), swap);
        }
        for(int i = 0; i < n; ++i){
            //find the length
            digit = 1;
            long long int ten = 10;
            while(rem[0][i] >= ten){
                digit++;
                ten *= 10;
            }
            //printf("%lld digit = %d\n", rem[0][i], digit);
            long long int target = (k - (rem[0][i] % k))%k;
            //printf("find %d\n", target);
            
            //printf("----------------------\n");
            //printf("digit = %d\n", digit);
            /*for(int j = 0; j < n; ++j){
                printf("%lld\t", rem[digit][j]);
            }
            printf("\n");
            //printf("\n");*/
            count += upper_bound(target, (rem[digit]), n) - lower_bound(target, (rem[digit]), n);
            if(((rem[0][i]%k) * (ten%k))%k == target)count--;
            //printf("count = %d\n", count);
            //printf("----------------------\n");
        }
        printf("%lld\n", count);
        /*for(int i = 0; i < n; ++i){
            for(int j = 0; j < 10; ++j){
                printf("%lld\t", rem[j][i]);
            }
            printf("\n");
        }*/
    }
    return 0;
}