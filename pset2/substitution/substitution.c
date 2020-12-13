#import <stdio.h>
#import <cs50.h>
#import <stdlib.h> 
#import <ctype.h> 
#import <string.h> 

bool hasDuplicate(string s);
bool isKey(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    else if (!isKey(argv[1]))
    {
        if (strlen(argv[1]) == 2)
        {
            printf("Usage: ./substitution key\n");
        }
        else
        {
            printf("Key must contain 26 characters.\n");
        }
        return 1;
    }

    else if (hasDuplicate(argv[1]))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    string plain = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, j = strlen(plain); i < j; ++i)
    {
        if (islower(plain[i]))
        {
            if (islower(argv[1][plain[i] - 'a']))
            {
                printf("%c", argv[1][plain[i] - 'a']);
            }
            else
            {
                printf("%c", argv[1][plain[i] - 'a'] + ('a' - 'A'));
            }
        }
        else if (isupper(plain[i]))
        {
            if (islower(argv[1][plain[i] - 'A']))
            {
                printf("%c", argv[1][plain[i] - 'A'] - ('a' - 'A'));
            }
            else
            {
                printf("%c", argv[1][plain[i] - 'A']);
            }
        }
        else {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;
}

bool isKey(string s)
{
    if (strlen(s) != 26)
    {
        return false;
    }
    for (int i = 0, j = strlen(s); i < j; ++i)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}

bool hasDuplicate(string s)
{
    int count[26] = {0};
    for (int i = 0, j = strlen(s); i < j; ++i)
    {
        if (islower(s[i]))
        {
            count[s[i] - 'a']++;
        }

        else if (isupper(s[i]))
        {
            count[s[i] - 'A']++;
        }
    }

    for (int i = 0; i < 26; ++i)
    {
        if (count[i] != 1)
        {
            return true;
        }
    }
    return false;
}