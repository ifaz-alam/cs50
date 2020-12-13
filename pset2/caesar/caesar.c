#import <stdio.h>
#import <cs50.h>
#import <stdlib.h> // atoi
#import <ctype.h> // isdigit
#import <string.h> // strlen

bool isInt(string s);
int main(int argc, string argv[])
{   
    // key value
    unsigned int k;
    
    // checks if user put a proper key
    if (argc != 2) 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    else
    {   
        // converts the key from a string to integer
        if (isInt(argv[1]))
        {
            k = atoi(argv[1]);
        }
        
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    // asks for user input
    string plain = get_string("plaintext: ");
    
    // prints ciphertext
    printf("ciphertext: ");
    
    for (int i = 0, j = strlen(plain); i < j; ++i)
    {   // shifts letters, preserving case
        if (plain[i] >= 'a' && plain[i] <= 'z')
        {
            printf("%c", (plain[i] - 'a' + k) % 26 + 'a');
        }
        else if (plain[i] >= 'A' && plain[i] <= 'Z')
        {
            printf("%c", (plain[i] - 'A' + k) % 26 + 'A');
        }
        // non-alphabetic characters are unchanged
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;
}

// function for checking if string is integer
bool isInt(string s)
{
    for (int i = 0, j = strlen(s); i < j; ++i)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
