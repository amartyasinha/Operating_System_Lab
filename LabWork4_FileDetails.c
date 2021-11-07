//
// Created by amartya on 04/09/21.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    char array[200] = "";
    printf("The Filename that you have passed through argument is \"%s\"\n", argv[1]);
    printf("\nHere are details of the specified File\n\n--------------------------------------\n");
    strcat(array, "ls -l ");
    strcat(array, argv[1]);
    strcat(array, " | awk '{print $1, $6, $7, $8}'");

    printf("       ");
    fflush(stdout);
    system(array);

    printf("--------------------------------------\n");

    return 0;
}
