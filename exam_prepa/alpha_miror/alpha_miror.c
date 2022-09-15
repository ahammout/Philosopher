#include<unistd.h>

int main(int ac, char **av)
{
    int i;
    int dest;

    i = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            dest = 0;
            if (av[1][i] >= 97 && av[1][i] <= 122)
            {
                if (av[1][i] >= 110)
                {
                    dest = av[1][i] - 110;
                    av[1][i] = 109 - dest;
                }
                else
                {
                    dest = 110 - av[1][i];
                    av[1][i] = 109 + dest;
                }

            }
            if (av[1][i] >= 65 && av[1][i] <= 90)
            {
                if (av[1][i] >= 78)
                {
                    dest = av[1][i] - 78;
                    av[1][i] = 77 - dest;
                }
                else
                {
                    dest = 78 - av[1][i];
                    av[1][i] = 77 + dest;
                }
            }
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write (1, "\n", 1);
}