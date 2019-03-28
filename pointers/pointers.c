#include <stdio.h>
#include <string.h>
/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    // char *x which is the buffer

    // char * y which is the string to copy

    // printf("The string length of y is: %lu\n", strlen(y));

    int i;
    //as long as we are not at a null terminater we increase our counter i
    //and copy our string to this pointer x's memory
    for (i = 0; y[i] != '\0'; i++)
    {
        x[i] = y[i];
    }
    //sets our last value to the null terminator
    x[i + 1] = '\0';

    //sets the x pointer to the null terminator
    x = &x[i + 1];
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    int i;
    //sets a pointer found that we are going to return
    char *found;
    for (i = 0; str[i] != '\0'; i++)
    {
        //if our string matches the character we are looking for
        //we set found to this value
        if (str[i] == c)
        {
            // printf("match at i: %d\n", i);

            // printf("The address is: %d\n", i); // Prints "2"
            found = &str[i];
        }
    }

    //return the found pointer
    return found;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    int i;
    char *found;

    int lengthOfNeedle = strlen(needle);

    // printf("The string length of needle is: %d\n", lengthOfNeedle);

    // looping through the haystack
    for (i = 0; haystack[i] != '\0'; i++)
    {

        int j;

        //if our first character matches
        if (haystack[i] == needle[0])
        {
            // printf("match at i: %d\n", i);
            // printf("The address is: %d\n", i); // Prints "2"

            found = &haystack[i];

            //loop through the remaining characters checking for a match
            for (j = 0; j < (lengthOfNeedle + 1); j++)
            {
                // printf("i : %d\n", i);
                // printf("j : %d\n", j);
                // printf("found[i + j] : %c\n", found[i + j]);
                // printf("needle[j] : %c\n", needle[j]); // Prints "2"

                if (found[j] == needle[j])
                {
                    // printf("match at j: %d\n", j);

                    // printf("The address is: %d\n", i); // Prints "2"
                    found = &haystack[i];
                }

                //if you get to the end of the loop and get to the null terminator you have found the needle
                else if (needle[j] == '\0')
                {
                    // printf("Found needle in a haystack! : %c\n", *needle);

                    ;
                }
            }
        }
    }
    return found;
}

#ifndef TESTING
int main(void)
{

    char buffer[24]; //1024 after debugging

    string_copy(buffer, "Hello!");
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif