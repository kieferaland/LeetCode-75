#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * gcdOfStrings(char * str1, char * str2){
    // allocate pointer for output
    static char * out;
    // check which input string is longer
    if (strlen(str1) > strlen(str2)){
        int i;
        for (i=0;i<strlen(str1);i++){
            if (str1[i]==str2[i]){
                out = realloc(out, (i+1)*sizeof(char));
                out[i] = str1[i];
            }
        }
    }
    printf("%lu\n", strlen(out));
    return out;
    // else if (strlen(str1) > strlen(str2)){
        
    // }
}

int main(void)
{
    char * gcd = gcdOfStrings("ABC", "AB");
    printf("%s\n", gcd);
}
