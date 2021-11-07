//
// Created by amartya on 15/10/21.
//

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int sum ;
void *runner(void *param);  // threads calls this function

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
    pthread_create(&tid,&attr,runner,argv[1]);
    pthread_join(tid,NULL);
    printf("Sum = %d\n",sum);
}

void *runner(void *param)
{
    int i , upper=atoi(param);
    sum=0;
    for(i=1 ;i<=upper ;i++)
    {
        sum += i;
    }
    pthread_exit(0);
}