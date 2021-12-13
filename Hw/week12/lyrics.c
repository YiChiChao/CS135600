#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node{
    int used;
    int vowels;
    char last_vowel;
}Lyrics;
Lyrics lyrics[100005];

Lyrics init_word(char* input){
    Lyrics word;
    int tmp = 0;
    int n = strlen(input);
    for(int i = 0; i < n; ++i){
        if(input[i] == 'a' || input[i] == 'e' ||
        input[i] == 'i' || input[i] == 'o' ||
        input[i] == 'u'){
            tmp++;
            word.last_vowel = input[i];
        }
    }
    word.vowels = tmp;
    word.used = 0;
    return word;
}
int main(){
    int x;
    char buffer[200];
    scanf("%d", &x);
    for(int i = 0; i < x; ++i){
        scanf("%s", buffer);
        lyrics[i] = init_word(buffer);
        printf("%d\n", lyrics[i].vowels);
    }
}