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

printf("The string length of y is: %d\n", strlen(y)); 

int i;
  for (i = 0; y[i] != '\0'; i++) {
x[i] = y[i];
  }
  x[i+1] = '\0';
  
x = &x[i+1];

  
  return 0;

}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c) {
int i;
char *found;
for (i = 0; str[i] != '\0'; i++) {
if (str[i] == c) {
  printf("match at i: %d\n", i); 
  }
printf("The address is: %d\n", i); // Prints "2"
  found = &str[i];
  
  return 0;
  }
  
  
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
