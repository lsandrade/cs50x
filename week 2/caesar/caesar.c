#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


string caesar(string text, int key);
bool checkint(string argv);

int main(int argc, char **argv)
{
    if (argc != 2 || !checkint(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string text = get_string("plaintext: ");
        int key = atoi(argv[1]);

        printf("ciphertext: %s\n", caesar(text, key));
    }
}

string caesar(string text, int key)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            int ascii = isupper(text[i]) ? 65 : 97;
            int pi = text[i] - ascii;
            int ci = (pi + key) % 26;
            text[i] = ci + ascii;
        }
    }

    return text;
}

bool checkint(string argv)
{
    for (int i = 0; i < strlen(argv); i++)
    {
        if (!isdigit(argv[i]))
        {
            return false;
        }
    }
    return true;
}