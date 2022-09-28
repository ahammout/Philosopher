// allowed function : write - malloc - free;
// word = remembrming the first word;
// new string : fill from the first word after "word" with spliting the words by only on space;
//      +spaces: if facing any tab or space before or after the word delete it and replace it by only one space;
//      +input: "Hello world from rosting program that reverse the first word"
//      +output: "world from rosting program that reverse the first word Hello"

#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int is_white(char c)
{
    if (c == '\t' || c == ' ' || c == '\0')
        return (1);
    return (0);
}


int main(int ac, char **av)
{
    int i;
    int w;
    int check;
    char    *word;
    char    *new_str;

    i = 0;
    w = 0;
    check = 0;
    word = malloc(sizeof(char) * 1000);
    new_str = malloc(sizeof(char) * 1000);
    if (ac > 1)
    {
        while (is_white(av[1][i]))
            i++;
        while (is_white(av[1][i]) == 0)
        {
            word[w] = av[1][i];
            w++;
            i++;
        }
        word[w] = '\0';
        w = 0;
        while (av[1][i])
        {
            while (is_white(av[1][i]))
                i++;
            while (is_white(av[1][i]) == 0)
            {
                new_str[w] = av[1][i];
                w++;
                i++;
            }
            new_str[w] = ' ';
            w++;
        }
        i = 0;
        while (word[i] != '\0')
        {
            new_str[w] = word[i];
            i++;
            w++;
        }
        new_str[w] = '\0';
    }
    printf("%s\n", new_str);
}