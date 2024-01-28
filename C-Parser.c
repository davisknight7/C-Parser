#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
int main() {
    FILE *file;
    char fileLine[1000];
    char chosenFile[1000];
    char stack[1000];
    int stackLocation = 0;

    while (true) {
        printf("Enter the name of the file you'd like to read from (Ex: readme.txt): ");
        scanf("%s", chosenFile);
        file = fopen(chosenFile, "r");
        if (file == NULL) {
            perror("Error");
            printf("Make sure the file is in same directory as this program and also check spelling.\n");
        } else {
            break;
        }
    }

    while (fgets(fileLine, 1000, file) != NULL) { 
        for (int i = 0; i < strlen(fileLine); i++) {
            char currentChar = fileLine[i];
            if(currentChar == EOF) {
                break;
            } else if (currentChar == '/') {
                if (fileLine[i + 1] == '/') {
                    break;
                }
            } else {
                switch (currentChar) {
                    case '{':

                    case '}':
                    case '(':
                    case ')':
                    case '[':
                    case ']':
                }
        }



    }
    }



}