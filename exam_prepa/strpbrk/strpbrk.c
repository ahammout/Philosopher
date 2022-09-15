#include<unistd.h>
#include<stdio.h>
#include<string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
                return ((char *)s1 + i);
            j++;
        }
        i++;
    }
    return (NULL);
}

int main(int ac, char **av)
{
    printf("%s\n", ft_strpbrk("helloworld", "bllank"));
    return (0);
}