#include <stdio.h> 
#include <string.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return(i);
}

char* FirstReverse(char *str) {
    int     i;
    int     j;
    char    c;

    i = 0;
    j = ft_strlen(str) - 1;
    while (i < j)
    {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
    return(str);
}

int main(void) { 
   
  // keep this function call here
    char *str  = strdup("strdup(Aissam)");
    printf("%s\n", FirstReverse(str));
    return 0;
    
}