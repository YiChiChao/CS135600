#include <stdio.h>
#include <string.h>
char str_target[200005] = {0};
int sum[200005]={0};
char str[100000005] = {0};
long long int a, b, n;
int main(){
    long long int q, l;
    long long int index = 0;
    long long int count = 0;
    scanf("%lld %lld %lld", &a, &b, &n);
    scanf("%s", str);
    long long int zero = b-a;
    for(long long int i = 0; i < zero; ++i){
        str[n+i]= '0';
    }
    str[n+zero] = '\0';
    scanf("%d %d", &q, &l);//l = how many 0, q = testcase
    for(int i = 0; i < l;++i){
        str_target[i]='0';
    }
    str_target[l]='\0';
    long long int total;
    total = n + zero;
    while(index <= total){
        if(strncmp(str+(index), str_target, l) == 0){
            sum[index++] = ++count;
        }
        else {
            sum[index] = count;
            index++;
        }
    }
    
    for(int i = 0; i < q;++i){
        long long int start, end;
        scanf("%d %d", &start, &end);
        long long int num = end - l + 1;
        long long int tmp;
        if(num < 0) tmp = 0;
        else tmp = sum[end - l + 1]-sum[start - 1];
        printf("%lld\n", tmp);
    }
    return 0;   
}