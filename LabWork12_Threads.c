//
// Created by amartya on 15/10/21.
//

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int sum, factorial;

// thread will call this function for sum
void *runnerSum(void *param) {
    int i, upper = atoi(param);
    sum = 0;
    for (i = 1; i <= upper; i++) {
        sum += i;
    }
    pthread_exit(0);
}

// thread will call this function for factorial
void *runnerFact(void *param) {
    int i, upper = atoi(param);
    factorial = 1;
    for (i = 1; i <= upper; i++)
        factorial *= i;
    pthread_exit(0);
}

int main(int argc, char *argv[]) {  //5 is set in configuration

    pthread_t tidSum, tidFact;
    pthread_attr_t attrSum, attrFact;
    if (argc != 2) {
        fprintf(stderr, "Usage: ./a.out <integer value>\n");
        return -1;
    }
    if (atoi(argv[1]) < 0) {
        fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
        return -1;
    }

    pthread_attr_init(&attrSum);
    pthread_create(&tidSum, &attrSum, runnerSum, argv[1]);
    pthread_join(tidSum, NULL);
    printf("Sum of first %d numbers is %d\n", atoi(argv[1]), sum);

    pthread_attr_init(&attrFact);
    pthread_create(&tidFact, &attrFact, runnerFact, argv[1]);
    pthread_join(tidFact, NULL);
    printf("Factorial of first %d numbers is %d\n", atoi(argv[1]), factorial);
}