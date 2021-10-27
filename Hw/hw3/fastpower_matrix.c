#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
typedef struct matrix{
    long long int matrix[2][2];
}Mat;

Mat *matrix_multiply(Mat *A, Mat *B){
    Mat *result = malloc(sizeof(Mat));
    //init result matrix
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            result->matrix[i][j] = 0;
        }
    }

    for(int i = 0; i < 2; ++i){
        for (int j = 0; j < 2; ++j){
            for(int k = 0; k < 2; ++k){
                result->matrix[i][j] += (A->matrix[i][k] * B->matrix[k][j]) % MOD;
            }
            result->matrix[i][j] = result->matrix[i][j] % MOD;
        }
    }
    return result;
}

Mat *fpw(Mat *A, long long int k){
    static int count = 0;
    count++;
    Mat *result = malloc(sizeof(Mat));
    if(k == 1){
        return A;
    }
    result = fpw(A, k/2);
    if(k % 2 == 1){
        return matrix_multiply(matrix_multiply(result, result), A);
    }
    else{
        //printf("count = %d\n", count);
        return matrix_multiply(result, result);
    } 
}

int main(){
    Mat *A = malloc(sizeof(Mat));
    Mat *B = malloc(sizeof(Mat));
    Mat *result = malloc(sizeof(Mat));
    //init matrices
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            A->matrix[i][j] = 0;
            B->matrix[i][j] = 0;
        }
    }

    //set the initial value of A and B;
    A->matrix[0][0] = 1;
    A->matrix[0][1] = 1;
    A->matrix[1][0] = 1;
    B->matrix[0][0] = 1;
    B->matrix[1][0] = 1;

    //printf the matrix
    /*printf("A\n");
    printf("\t%lld\t%lld\n",A->matrix[0][0], A->matrix[0][1]);
    printf("\t%lld\t%lld\n",A->matrix[1][0], A->matrix[1][1]);
    printf("B\n");
    printf("\t%lld\t%lld\n",B->matrix[0][0], B->matrix[0][1]);
    printf("\t%lld\t%lld\n",B->matrix[1][0], B->matrix[1][1]);
    */
    long long int k;
    while(scanf("%lld", &k) != EOF){
        if(k <= 2)printf("1\n");
        else{
            result = fpw(A, k-2);
            result = matrix_multiply(result, B);
            printf("%lld\n", result->matrix[0][0]);
        }
        //print out the final value
        
    }
    
    
}