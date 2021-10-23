#include <stdio.h>
#include <ctype.h>

int calculate(void);

int main(){
    printf("=%d\n", calculate());
    return 0;
}

int calculate(){
    int c;
    int ans;
    int op1, op2;

    c = getchar();
    if(isspace(c)){
        ans = calculate();//continue
    }
    else if (c == '+'){
        op1 = calculate();
        printf("+");
        op2 = calculate();
        ans = op1 + op2;
    }
    else if(c == '-'){
        op1 = calculate();
        printf("-");
        op2 = calculate();
        ans = op1 - op2;
    }
    else if(c == '*'){
        op1 = calculate();
        printf("*");
        op2 = calculate();
        ans = op1 * op2;
    }
    else if(isdigit(c)){
        ungetc(c, stdin);
        scanf("%d", &ans);
        printf("%d", ans);
    }
    return ans;
}
    
