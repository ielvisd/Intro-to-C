#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*
    Duplicates the input string by dynamically allocating memory for 
    the duplicate string using `malloc` and then copying the string
    into the allocated memory. Returns a pointer to the allocated memory.
    You may want to use the string_length function to figure out the
    length of the input string.
*/
char *string_dup(char *src)
{
    // printf("Input string: %s\n", src);
    int lengthOfString;
    lengthOfString = strlen(src) + 1;
    char *duplicate;
    duplicate = malloc(1 * lengthOfString);

    int i;
    //as long as we are not at a null terminater we increase our counter i
    //and copy our string to this pointer x's memory
    for (i = 0; src[i] != '\0'; i++)
    {
        duplicate[i] = src[i];
        
    }
    //sets our last value to the null terminator
    duplicate[i] = '\0';

    //sets the x pointer to the null terminator
    // duplicate = &src;

    return duplicate;
}

/*
    A generic version of string_copy, mem_copy receives a block of memory
    of any type and copies its contents to the destination pointer (dest).
    You may want to cast the input pointers to char pointers first before
    performing the copying. `n` is the amount of data that should be copied
    from `src` to `dest`. 
*/
void mem_copy(void *dest, const void *src, int n)
{
    //Casts input pointers to char pointers instead of string pointers
    char *char_dest = (char *)dest;
    char *char_src = (char *)src;

    // int i;

    //Using our data size we assign every character from src to destination. 
    for (int i=0; i < n; i++) {
        char_dest[i] = char_src[i];
    }
}

/*
    Given a pointer of `malloc`'d memory, this function will 
    attempt to resize the allocated memory to the new specified
    size. Any data that was previously in the old `malloc`'d 
    memory should be intact in the new resized block of memory. 
    Some edge cases to consider: how should resizing be handled
    in the case when old_size < new_size? What about when 
    old_size > new_size?
    
    Do not use the `realloc` function from the standard libary.
*/
void *resize_memory(void *ptr, int old_size, int new_size)
{
//    printf("ptr : %s\n", ptr);
   
   char *characterPointer = (char *) ptr;
   
   char *newDataPointer = malloc(new_size);
    for (int i=0; i < old_size; i++) {
        newDataPointer[i] = characterPointer[i];
    }
    
    return newDataPointer;
}

#ifndef TESTING
int main(void)
{
    char *s = "Some string to duplicate.";
    char *dup = string_dup(s);

    printf("Duplicated string: %s\n", dup);

    int numbers[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int *target = malloc(n * sizeof(int));

    mem_copy(target, numbers, n * sizeof(int));

    printf("Copied array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", target[i]);
    }

    printf("\n");

    char *url = string_dup("http://lambdaschool.com");
    char *path = string_dup("/students/");
    int url_length = strlen(url);
    int path_length = strlen(path);

    int new_length = url_length - 1 + path_length;
    char *new_url = resize_memory(url, url_length, new_length);
    char *p = new_url + url_length;

    while (*path != '\0')
    {
        *p = *path;
        p++;
        path++;
    }

    printf("Full path string: %s\n", new_url);

    return 0;
}
#endif