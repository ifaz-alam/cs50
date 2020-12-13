#import <stdio.h>
#import <cs50.h>

int main(void)
{
    int height;

    // Handles user input accordingly
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);

    // Iterates through each row
    for (int row = 0; row < height; ++row)
    {
        // Prints spaces and hashes accordingly for left side
        for (int space = 0; space < height - (row + 1); ++space)
        {
            printf(" ");
        }

        for (int column = 0; column < row + 1; ++column)
        {
            printf("#");
        }

        // Prints centre spaces
        printf("  ");

        // Prints spaces for right side
        // Spaces are not needed for this
        for (int column = 0; column < row + 1; ++column)
        {
            printf("#");
        }

        printf("\n");
    }
}