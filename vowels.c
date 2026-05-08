/* Counting the number of vowels in a string */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int countVowels(char *str) {
    /* TODO: return the number of vowels in the string str */
    int n = 0;
    int vowelCount = 0;
    while (*(str+n) != '\0') {
        char chr = tolower(*(str+n));
        if (chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u') {
            vowelCount++;
        }
        n++;
    }
    return vowelCount;
}

int main() {
    int n;
    printf("Enter the maximum length of the string: ");
    scanf("%d", &n);

    char *str;  //pointer to the string
    int vowelCount; //variable to store the number of vowels

    /* TODO: Allocate memory to store the string. 
             If allocation is successful, then read a string and call count the number of vowels. 
                You can use fgets() toma read the string from stdin. 
                You may wish to consume any leftover newline character before reading your string using scanf(" ");
             If allocation is not successful, print "Memory allocation failed!" and exit with a return value of 1
             Tip: do not forget to free any memory that you allocated.
              */
    
    str = (char*)(malloc(n * sizeof(char)));

    if (str == NULL) {
        // then its failed
        printf("Memory allocation failed!");
        return 0;
    }
    // fill up each value with a default 'a' until '\0'

    for (int q = 0; q < n; q++) {
        *(str+q) = 'a';
    }
    *(str+n) = '\0';
    printf("Enter a string: ");

    scanf(" ");
    fgets(str,n,stdin);

    printf("%s",str);
    vowelCount = countVowels(str);
    free(str);
    
    printf("Number of vowels: %d\n", vowelCount);


    return 0;
}
