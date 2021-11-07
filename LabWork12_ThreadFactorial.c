//
// Created by amartya on 15/10/21.
//

#include<stdlib.h>
#include <pthread.h>
#include <stdio.h>
int factorial; /* this data is shared by the thread(s) */
void *runner(void *param);
int main(int argc, char *argv[])    //5 is set in configuration
{
    pthread_t tid; /* the thread identifier */
    pthread_attr_t attr; /* set of thread attributes */
    if (argc != 2) {
        fprintf(stderr,"usage: a.out <integer value>\n");
        return -1;
    }
    if (atoi(argv[1]) < 0) {
        fprintf(stderr,"%d must be >= 0\n",atoi(argv[1]));
        return -1;
    }
/* get the default attributes */
    pthread_attr_init(&attr);
/* create the thread */
    pthread_create(&tid,&attr,runner,argv[1]);
/* wait for the thread to exit */
    pthread_join(tid,NULL);
    printf("factorial = %d\n", factorial);
}
/* The thread will begin control in this function */
void *runner(void *param)
{
    int i, upper = atoi(param);
    factorial = 1;
    for (i = 1; i <= upper; i++)
        factorial *= i;
    pthread_exit(0);
}