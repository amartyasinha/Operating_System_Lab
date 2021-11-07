//
// Created by amartya on 15/10/21.
//

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int sum, factorial;
void *runnerSum(void *param);   // thread will call this function for sum
void *runnerFact(void *param);  // thread will call this function for factorial

int main(int argc , char *argv[])  //5 is set in configuration
{
    pthread_t tid;
    pthread_attr_t attr;
    if(argc!=2)
    {
        fprintf(stderr,"Usage : a.out<integer value>\n");
        return -1;
    }
    if(atoi(argv[1])<0)
    {
        fprintf(stderr,"%d must be >=0\n",atoi(argv[1]));
        return -1;
    }
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runnerSum, argv[1]);
    pthread_create(&tid, &attr, runnerFact, argv[1]);
    pthread_join(tid,NULL);
    printf("Sum = %d\n",sum);
    printf("Factorial = %d\n",factorial);
}

void *runnerSum(void *param)
{
    int i , upper = atoi(param);
    sum = 0;
    for(i = 1; i <= upper; i++)
    {
        sum += i;
    }
    pthread_exit(0);
}

void *runnerFact(void *param){
    int i, upper = atoi(param);
    factorial = 1;
    for (i = 1; i <= upper; i++)
        factorial *= i;
    pthread_exit(0);
}