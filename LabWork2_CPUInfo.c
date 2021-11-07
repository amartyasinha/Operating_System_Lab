//
// Created by amartya on 28/08/21.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("This Program Displays basic Information related to your CPU\n");
    int choice;

    do {
        printf("Choose your Option:\n1. Kernel Info\n2. CPU Model\n3. CPU Vendor\n4. CPU Family\n5. Exit Program\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("---------------------------------");
                printf("\nYour Kernel is ");
                fflush(stdout);
                system("cat /proc/sys/kernel/osrelease");
                printf("---------------------------------\n");
                break;
            }
            case 2: {
                printf("---------------------------------");
                printf("\nYour CPU Model is \n");
                system("cat /proc/cpuinfo | grep 'model'");
                printf("---------------------------------\n");
                break;
            }
            case 3: {
                printf("---------------------------------");
                printf("\nYour CPU Vendor is \n");
                system("cat /proc/cpuinfo | grep 'vendor'");
                printf("---------------------------------\n");
                break;
            }
            case 4: {
                printf("---------------------------------");
                printf("\nYour CPU Family is \n");
                system("cat /proc/cpuinfo | grep 'cpu family'");
                printf("---------------------------------\n");
                break;
            }
            case 5:
                exit(0);
        }
    } while (1);

    return 0;
}