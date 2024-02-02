#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool containsChar(char c)
{
    return c == '{' || c == '}' || c == '(' || c == ')' || c == '[' || c == ']';
}

bool validPair(char c1, char c2)
{
    return (c1 == '{' && c2 == '}') || (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']');
}

//code works for the most part, passes on all the tests except for btest, gtest, and extra credit.  
//For btest and gtest it mostly outputs the correct answer but it also outputs an additional incorrect set of { } as invalid
bool validSyntax(char c[], int lines[], int p)
{
    bool valid=true;
    char stack[1000];
    int lineStack[1000];
    int top = -1;

    for (int i = 0; c[i] != '\0'; i++) {
        char currentChar = c[i];
        int currentLine = lines[i];

        if (currentChar == '{' || currentChar == '[' || currentChar == '(') {
            stack[++top] = currentChar;
            lineStack[top] = currentLine;
        } else if (currentChar == '}' || currentChar == ']' || currentChar == ')') {
            if (top == -1 || !validPair(stack[top], currentChar)) {
                printf("Error: Invalid %c on line %d\n", currentChar, i + 1);
                valid=false;
            } else {
                top--;
            }
        }
    }

    while (top != -1) {
        printf("Error: Unmatched %c on line %d\n", stack[top--], lineStack[top]);
        valid=false;
    }

    return valid;
}

int main()
{
    // file parsing info
    FILE *file;
    char fileLine[1000];
    char chosenFile[1000];
    int line = 0;

    char checked[1000];
    int checkedLines[1000];
    int current = 0;

    while (true)
    {
        printf("Enter the name of the file you'd like to read from (Ex: readme.txt): ");
        scanf("%s", chosenFile);
        file = fopen(chosenFile, "r");
        if (file == NULL)
        {
            perror("Error\n");
            printf("Make sure the file is in the same directory as this program and also check spelling.\n");
        }
        else
        {
            break;
        }
    }

    while (fgets(fileLine, 1000, file) != NULL)
    {
        line++;
        for (int i = 0; i < strlen(fileLine); i++)
        {
            char currentChar = fileLine[i];
            if (currentChar == EOF)
            {
                break;
            }
            else if (currentChar == '/')
            {
                if (fileLine[i + 1] == '/')
                {
                    break;
                }
            }
            else if (containsChar(currentChar))
            {
                checked[current] = currentChar;
                checkedLines[current] = line;
                current++;
            }
        }
    }

 //this should be removed before submission, it's just here to test the code.
    bool valid = validSyntax(checked, checkedLines, current);
    if (!valid)
    {
        printf("Syntax errors found.\n");
    }
    else
    {
        printf("No syntax errors found.\n");
    }

    fclose(file);
    return 0;
}
