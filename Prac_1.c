#include <stdio.h>
#include <string.h>

int isValidString(const char *str) {
    int i = 0;

    while (str[i] == 'a') {
        i++;
    }

    if (str[i] == 'b' && str[i + 1] == 'b' && str[i + 2] == '\0') {
        return 1; 
    } else {
        return 0; 
    }
    
}

int main() {
    char input[10]; 

    printf("Enter the string: ");
    scanf("%s", input); 

    if (isValidString(input)) {
        printf("Valid String\n");
    } else {
        printf("Invalid String\n");
    }

    return 0;
}
