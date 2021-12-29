#include <stdio.h>
#include <stdlib.h>
int numstart[100000] = {0};
int numend[100000] = {0};
int swap1(const void *a, const void *b){
    int A = *(int*)a;
    int B = *(int*)b;
    return A-B; 
}


int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n ; ++i){
        scanf("%d %d", &numstart[i], &numend[i]);
    }
    qsort(numstart, n, sizeof(int), swap1);
    qsort(numend, n, sizeof(int), swap2);
    int ans = (numstart[n-1]-numstart[0]) + (numend[0]-numstart[n-1]) +num[end]
    return 0;
}