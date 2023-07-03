#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// a short program to merge two words by alternating a char from each (starting with word1)
// once the shorter word is exhausted append the rest of the longer word to the end
char * mergeAlternately ( char *word1 , char *word2 ) {
    // initialize pointer for output
    static char* out;
    // allocate memory for output string plus the null terminator
    out = malloc((strlen(word1) + strlen(word2) + 1)*sizeof(char));
    // while neither string is exhausted alternate putting chars into the output
    for (int i = 0; ((i < strlen(word1)) && (i < strlen(word2))); i++){
        out[i*2] = word1[i];
        out[(i*2)+1] = word2[i];
    }
    // if the first word is shorter append the rest of the second to the output
    if (strlen(word1) < strlen(word2)){
        for (int i = 0; i < (strlen(word2)+strlen(word1)) - (strlen(word1)*2); i++){
            out[(strlen(word1)*2) + i] = word2[strlen(word1) + i];
        }
    // or vise versa
    } else if (strlen(word1) > strlen(word2)) { 
        for (int i = 0; i < (strlen(word1)+strlen(word2)) - (strlen(word2)*2); i++){ 
            out[(strlen(word2)*2) + i] = word1[strlen(word2) + i]; 
        }
    }
    // add the null char for string termination
    out[strlen(word1) + strlen(word2)] = '\0';
    //return the merged output string
    return out;
}

int main(void)
{
    // test case
    char * out = mergeAlternately("abcdefghijkl", "zyxwvu");
    // check output in stdout
    printf("%s\n", out);
    // free the allocated memory
    free(out);
    // TODO: what are the cases where we return -1?
    // such as: null valued output, or strings with no null terminator perhaps?
    return 0;
}
