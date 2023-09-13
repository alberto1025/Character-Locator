/*
Alberto Escalante
Math 230 (M/W)
Instructor: Mimi Rasky
Date: 03/07/2022
Lab #4: Strings, Pointers and Functions
*/

#include <stdio.h>
char *serchit(char *str, char ref_char);

int main()
{
    char myStr[30];
    char myChar;
    int i = 0;

    // prompt user to enter a string and a character to search for
    printf("Please enter a string: ");
    scanf("%[^\n]s", myStr);
    printf("Please enter a character to search for: ");
    scanf(" %c", &myChar);

    printf("The string is: %s\n", myStr);

    // count and print the length of the string 
    while(myStr[i])
    {
         i++;      
    }
    printf("The length of the string is: %d\n", i);
    
    char *ptr;

    //invoke method
    ptr = serchit(myStr, myChar);
    
    // if the value where the pointer is pointing at is the given char, print the following
    if(*ptr == myChar)
    {
        printf("%c was found in the string\n", myChar);
        printf("The string, beginning at %c is: %s\n\n", *ptr, ptr);
        printf("Address           Contents   Decimal   ASCII\n");

        // while the value is not null, print out the values of the char where pointer is pointing
        while(*ptr)
        {
            printf("%08X            0x%02x %9d %6c\n", ptr, *ptr, *ptr, *ptr);
            ptr++;
            
            // if the pointer value is now equal null, print out the values for null as well
            if(!*ptr)
            {
                printf("%08X            0x%02x %9d %6c\n", ptr, *ptr, *ptr, *ptr);
            }
        }
        
    }

    // if the char is not found within the string, print the following
    else
    {
        printf("%c was not found in the string\n", myChar);
        printf("\n");
        printf("Address           Contents   Decimal   ASCII\n");
        
        // traverse the string until you reach null, then print out the values of null
        while(*ptr)
        {
            ptr++;
        }

        printf("%08X            0x%02x %9d %6c\n", ptr, *ptr, *ptr, *ptr);
    
    }

    return 0;
}

// determine whether the char is found within the string
char *serchit(char *str, char ref_char)
{
    int i = 0;

    // increment the position while the value does not equal the reference char and also equals an ASCII value.
    /* once the iteration reaches null, it will leave the while loop because null is 0 which represents false
    and it will grab the address of null */
    while(str[i] != ref_char && str[i])
    {
        i++;
    }
    
    str = &str[i];

    return str;
    
}
