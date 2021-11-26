#include <stdio.h>
#include <stdlib.h>
//1. do the qsort
//2. find the upper bound and the lower bound
//
int swap(const void *a, const void *b){
    int A = *(int*)a;
    int B = *(int*)b;
    return A - B;
}
//upper bound is the first index which the element is bigger than the target
int upper_bound(int *arr, int target, int arr_size){
    int left = 0, right = arr_size, mid;
    while(left < right){
        mid = (right + left)/2;
        if(arr[mid] > target) right = mid;
        //when the element us equal to target
        //the left should move to the next index
        //since the element should be bigger than the target
        else left = mid + 1;
    }
    return right;
}
//lower bound is the smallest index which the element is equal to the target
int lower_bound(int *arr, int target, int arr_size){
    int left = 0, right = arr_size, mid;
    while(left < right){
        mid = (right + left)/2;
        if(arr[mid] >= target) right = mid;
        else left = mid + 1;
    }
    return right;
}
int main(){
    int n;
    int q;
    int t;
    int upper;
    int lower;
    int arr[100005] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), swap);
    scanf("%d", &q);
    for(int i = 0; i < q; ++i){
        scanf("%d", &t);
        lower = lower_bound(arr, t, n);
        upper = upper_bound(arr, t, n);
        printf("%d\n", upper - lower);
    }
    return 0;
}