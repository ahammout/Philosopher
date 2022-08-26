#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int x  = 0;
pthread_mutex_t mutex;
void    *routine(void *ptr)
{
    int i = 0;

    printf("this is from the first thread\n");
    while (i <= 1000000)
    {
        pthread_mutex_lock(&mutex);
        i++;
        x++;
        pthread_mutex_unlock(&mutex);
    }
    return(NULL);
}

int main(void)
{
    pthread_t   t1, t2;

    pthread_mutex_init(&mutex, NULL);
    pthread_create(&t1, NULL, routine, NULL);
    pthread_create(&t2, NULL, routine, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("The value of x: %d\n", x);
}