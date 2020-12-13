#import <stdio.h>
#import <cs50.h>
#import <string.h>
#import <math.h>

int main(void)
{
    string text = get_string("Text: ");
    float letters = 0, words = 1, sentences = 0;

    int index;

    for (int i = 0, j = strlen(text); i < j; ++i)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }

        else if (text[i] == ' ')
        {
            words++;
        }

        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    index = round(0.0588 * (letters / words) * 100 - 0.296 * (sentences / words) * 100 - 15.8);
    // printf("Letter(s): %f\nWord(s): %f\nSentence(s): %f\n", letters, words, sentences);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    
    else
    {
        printf("Grade %d\n", index);
    }
}
