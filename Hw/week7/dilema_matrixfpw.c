#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
typedef struct matrix{
    long long int matrix[3][3];
} Mat;

Mat *matrix_multiply(Mat *A, Mat *B){
    Mat *result = malloc(sizeof(Mat));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result->matrix[i][j] = 0;
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                result->matrix[i][j] += (A->matrix[i][k]*B->matrix[k][j])%MOD;
            }
            result->matrix[i][j] = result->matrix[i][j] % MOD;
        }
    }
    return result;
}

Mat *fpw(Mat *A, long long int k){
    if(k == 1)return A;
    Mat *result = fpw(A, k/2);
    if(k % 2 == 1)return matrix_multiply(A, matrix_multiply(result, result));
    else return matrix_multiply(result, result);
}

int main(){
    Mat *A = malloc(sizeof(Mat));
    Mat *B = malloc(sizeof(Mat));
    Mat *result = malloc(sizeof(Mat));
    long long int k;
    long long int t;

    //init A B
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            A->matrix[i][j] = 0;
            B->matrix[i][j] = 0;
        }
    }
    A->matrix[0][0] = 1;
    A->matrix[0][1] = 2;
    A->matrix[0][2] = 1;
    A->matrix[1][0] = 1;
    A->matrix[2][1] = 1;
    B->matrix[0][0] = 13;
    B->matrix[1][0] = 12;
    B->matrix[2][0] = 1;
    scanf("%lld\n", &t);
    for(int i = 0; i < t; ++i){
        scanf("%lld", &k);
        if(k == 1)printf("1\n");
        else if(k == 2)printf("12\n");
        else if(k == 3)printf("13\n");
        else{
            result = fpw(A, k-3);
            result = matrix_multiply(result, B);
            printf("%lld\n", result->matrix[0][0]);
        }
    }
    return 0;
}


