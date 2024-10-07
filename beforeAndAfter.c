#include <stdio.h>
#include <string.h>

#define MAX_INPUT 21      // max input size 
#define MAX_LONG_STR 1000 // max size for string

// trim newline char from input
void trim_newline(char *str)
{
    char *newline = strchr(str, '\n');
    if (newline)
    {
        // replace newline with null to terminate
        *newline = '\0';
    }
}

int main()
{
    char input[MAX_INPUT];
    char longString[MAX_LONG_STR] = "";
    char temp[MAX_LONG_STR];

    while (1)
    {
        printf("Enter a string: ");
        fgets(input, MAX_INPUT, stdin);
        trim_newline(input);

        // check if user entered DONE
        if (strcmp(input, "DONE") == 0)
        {
            printf("%s\n", longString);
            return 0;
        }

        // check if input is already in long string
        if (strstr(longString, input) == NULL)
        {
            // compare inpute w long string
            if (strcmp(input, longString) < 0)
            {
                // if input is less than longString
                strcpy(temp, input);
                strcat(temp, " ");
                strcat(temp, longString);
                strcpy(longString, temp);
            }
            else
            {
                // if input greater than or equal append
                if (strlen(longString) > 0)
                {
                    // add space before appending
                    strcat(longString, " ");
                }
                // append input to longString
                strcat(longString, input);
            }
        }
        // display updated string
        printf("%s\n", longString);
    }
    return 0;
}