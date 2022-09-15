#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int check_args(int ac, char **av)
{
    int i;
    int j;
    int sign;

    i = 1;
    j = 0;
    sign = 0;
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j] == '-')
            {
                sign++;
                j++;
            }
            if ((!(av[i][j] >= '0' && av[i][j] <= '9')) || sign > 1)
                return (1);
            j++;
        }
        i += 2;
    }
    i = 0;
    while (av[2][i])
        i++;
    if (i > 1)
        return (1);
    // if (i > 1 || ((!av[2]) || av[2][0] != '*' || av[2][0] != '/' 
    //     || av[2][0] != '%' || av[2][0] != '+' || av[2][0] != '-'))
    //     return (1);
    return (0);
}
int main(int ac, char **av)
{
    int op_1;
    int op_2;
    int res;

    if (ac == 4)
    {
        res = 0;
        if (check_args(ac, av) == 0)
        {
            op_1 = atoi(av[1]);
            op_2 = atoi(av[3]);
            if (op_1 > 2147483647 || op_1 < -2147483648 || op_2 > 2147483647 || op_2 < -2147483648)
            {
                // write (1, "\n", 1);
                return (0);
            }
            if (av[2][0] == '+')
                res = op_1 + op_2;
            else if (av[2][0] == '-')
                res = op_1 - op_2;
            else if (av[2][0] == '*')
                res = op_1 * op_2;
            else if (av[2][0] == '/')
                res = op_1 / op_2;
            else if(av[2][0] == '%')
                res = op_1 % op_2;
            printf("%d", res);
        }
    }
    write(1, "\n", 1);
}
