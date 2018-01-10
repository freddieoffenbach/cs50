// Calculates the minimum number of coins required to give a user change

#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // prompt and validate user input
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    // convert dollars to cents and round to nearest penny
    int cents = round(dollars * 100);

    // number of coins
    int coins = 0;

    // coin denominations
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    // dispense quarters while balance is greather than or equal to one quarter
    while (cents >= quarter)
    {
        coins++;
        cents -= quarter;
    }

    // dispense dimes while balance is greather than or equal to one dime
    while (cents >= dime)
    {
        coins++;
        cents -= dime;
    }

    // dispense nickels while balance is greather than or equal to one nickel
    while (cents >= nickel)
    {
        coins++;
        cents -= nickel;
    }

    // dispense pennies while balance is greather than or equal to one penny
    while (cents >= penny)
    {
        coins++;
        cents -= penny;
    }

    // print number of coins used
    printf("%i\n", coins);
}
