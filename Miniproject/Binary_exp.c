#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXEXPR 256
char expr[MAXEXPR];
typedef enum {VAR_A, VAR_B, VAR_C, VAR_D, OP_AND, OP_OR, END} TokenSet;
char sym[]="ABCD&|";
TokenSet getNext(int reset){
    static int idx = 0;
    TokenSet ret = END;
    int i;
    if (reset) {
        idx = 0;
        return END;
    }
    while (expr[idx]!='\0' && isspace(expr[idx]))idx++;
    if (expr[idx] == '\0') {
        return END;
    } else {
        for (i=0; (size_t)i<strlen(sym); i++) {
            if (sym[i]==expr[idx]){
                ret = i;
                break;
            } 
        }
        idx++;
        return ret;
    }
}

int evaluate(int A, int B, int C, int D){
    TokenSet tok;
    tok = getNext(0);
    if (tok == END) {
        tok = getNext(1);
        //printf("END\n");
        return evaluate(A, B, C, D);
    } else if (tok==OP_AND || tok==OP_OR) {
        int expr1, expr2;
        expr1 = evaluate(A, B, C, D);
        expr2 = evaluate(A, B, C, D);

        //printf("expr1 = %d expr2 = %d ", expr1, expr2);
        if (tok == OP_AND) {
            //printf("&\n");
            return (expr1 && expr2);
        } else {
            //printf("||\n");
            return (expr1 || expr2);
        }
    } else {
        switch (tok) {
        case VAR_A: return A;
        case VAR_B: return B;
        case VAR_C: return C;
        case VAR_D: return D;
        default: return -1;
        }
    }
}

int main(){
    size_t len;
    int i;
    fgets(expr, sizeof(expr), stdin);
    printf("%s\n", expr);
    len = strlen(expr);
    if (len > 0 && expr[len-1] == '\n') {
        --len;
        expr[len] = '\0';
    }
    for (i=0; i<16; i++) {
        printf("%d%d%d%d: %d\n", (i&8)>>3, (i&4)>>2, (i&2)>>1, i&1,
        evaluate((i&8)>>3,(i&4)>>2,(i&2)>>1, i&1));
    }
    return 0;
}