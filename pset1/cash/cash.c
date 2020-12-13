#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    int change, coins = 0;
    do
    {
        change = round(get_float("Change Owed: ")*100);
    }
    while (change < 0);
    
    while (change - 25 >= 0)
    {
        change -= 25;
        coins++;
    }
    
    while (change - 10 >= 0)
    {
        change -= 10;
        coins++;
    }
    
    while (change - 5 >= 0)
    {
        change -= 5;
        coins++;
    }
    
    while (change - 1 >= 0)
    {
        change -= 1;
        coins++;
    }
    
    printf("%d\n", coins);
}