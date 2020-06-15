#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    char *points = ".!?";
    char *letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIIJKLMNOPQRSTUVWXYZ";
    int words = 1;
    int sentences = 0;
    int count_letters = 0;

    for (int i=0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            words++;
        } else if (strchr(points, text[i])) {
            sentences ++;
        } else if (strchr(letters, text[i])) {
            count_letters++;
        }
    }

    float lp100w = ((float) count_letters / (float) words) * 100;
    
    float sp100w = ((float) sentences / (float) words) * 100;
    
    float index = 0.0588 * lp100w - 0.296 * sp100w - 15.8;

    if (index < 1) {
        printf("Before Grade 1\n");
    } else if (index > 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", (int) rintf(index));
    }

}