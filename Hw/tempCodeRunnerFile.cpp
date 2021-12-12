#include <stdio.h>
int upper_bound(int *arr, int n, int target){
    int left = 0, right = n, mid;
    while(left < right){
        mid = (left + right)/2;
        if(arr[mid] > target)right = mid;
        else left = mid+1;
    }
    return right;
}

int lower_bound(int *arr, int n, targ)