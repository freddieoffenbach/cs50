// Prints out a half-pyramid of a specified height

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt and validate user input
    int height;
    int max_height = 23;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > max_height);

    // draw the half pyramid
    int row, n_spaces, n_hashes;
    for (int i = 0; i < height; i++)
    {
        // nth row is index plus one
        row = i + 1;

        // number of spaces is height minus row
        n_spaces = height - row;

        // number of hashes is row plus one for an additional hash
        n_hashes = row + 1;

        // print spaces
        for (int j = 0; j < n_spaces; j++)
        {
            printf(" ");
        }

        // print hashes
        for (int j = 0; j < n_hashes; j++)
        {
            printf("#");
        }

        // print new line
        printf("\n");
    }
}
