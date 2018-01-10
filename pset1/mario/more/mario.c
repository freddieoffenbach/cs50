// Prints out a double half-pyramid of a specified height

#include <cs50.h>
#include <stdio.h>

void print_repeat();

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

    // draw the pyramid
    int gap = 2;
    int row, n_spaces, n_hashes;
    for (int i = 0; i < height; i++)
    {
        // nth row is index plus one
        row = i + 1;

        // number of spaces is height minus row
        n_spaces = height - row;

        // number of hashes is the same as row
        n_hashes = row;

        // print left pyramid
        print_repeat(" ", n_spaces);
        print_repeat("#", n_hashes);

        // print gap
        print_repeat(" ", gap);

        // print right pyramid
        print_repeat("#", n_hashes);

        // print new line
        printf("\n");
    }
}

// Repeats printing a string
void print_repeat(string str, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s", str);
    }
}
