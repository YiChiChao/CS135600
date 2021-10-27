//IEEE
#include <stdio.h>
int main(){
    float x;
    while((scanf("%f", &x)) != EOF){
        int y = *(int*)(&x);
    //printf("%d\n", y);
        for(int i = 31; i >= 0;--i){
            int BIT = (1 << i);//add number to the bit
            if((BIT & y) != 0) putchar('1');//to find if the digit is 1 or 0
            else putchar('0');
        }
        printf("\n");
    }
    return 0;   
}