#include <stdio.h>
int main(){
    int row;
    int column;
    int total;
    int min = 1000000001;
    scanf("%d", &row);
    scanf("%d", &column);
    total = row * column;
    for(int i = 0; i < total; ++i){
        int tmp;
        scanf("%d", &tmp);
        if(tmp < min) min = tmp;
    }
    printf("%d\n", min);
    return 0;
}