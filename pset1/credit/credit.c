// Determines whether a provided credit card number is valid according to Luhn’s algorithm

#include <cs50.h>
#include <stdio.h>

bool check_number();
string issuer();

int main(void)
{
    // prompt and validate user input
    long long card_number;
    do
    {
        card_number = get_long_long("Number: ");
    }
    while (card_number < 1);

    // check if card number is valid
    if (check_number(card_number))
    {
        // print card issuer
        printf("%s\n", issuer(card_number));
    }
    else
    {
        // print invalid message
        printf("INVALID\n");
    }

    return 0;
}

// Validates a credit card number
bool check_number(long long n)
{
    int checksum = 0;
    int digit;
    int parity = 1;
    while (n > 0)
    {
        // get last digit of number
        digit = n % 10;
        // check if parity is even
        if (parity % 2 == 0)
        {
            // multiply digit by 2
            digit *= 2;
            // check if product is double digit
            if (digit > 9)
            {
                // sum digits of product
                digit -= 9;
            }
        }
        // add digit to checksum
        checksum += digit;
        // flip parity
        parity = 1 - parity;
        // move digits right
        n /= 10;
    }
    // return checksum modulo 10 conditional
    return checksum % 10 == 0;
}

// Determines the credit card issuer
string issuer(long long n)
{
    long long issuer_number = n;

    // count number of digits
    int n_digits = 0;
    while (n > 0)
    {
        n_digits++;
        n /= 10;
    }

    // get first two digits of card number
    int n_moves = n_digits - 2;
    for (int i = 0; i < n_moves; i++)
    {
        issuer_number /= 10;
    }

    // check if card number matches any known company identifiers
    if (n_digits == 15 && (issuer_number == 34 || issuer_number == 37))
    {
        return "AMEX";
    }
    else if (n_digits == 16 && issuer_number >= 51 && issuer_number <= 55)
    {
        return "MASTERCARD";
    }
    else if ((n_digits == 16 || n_digits == 13) && issuer_number / 10 == 4)
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}
