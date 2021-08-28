//
// Created by amartya on 28/08/21.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("This Program Displays basic Information related to your Memory (RAM)\n");
    int choice;

    do {
        printf("Choose your Option:\n1. Configured Memory\n2. Free Memory\n3. Used Memory\n4. Available Memory\n5. Exit Program\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("---------------------------------");
                printf("\nYour Configured Memory through meminfo is \n");
                system("cat /proc/meminfo | grep 'MemTotal'");
                printf("\nYour Configured Memory through vmstat is \n");
                system("vmstat -s | grep 'total memory'");
                printf("---------------------------------\n");
                break;
            }
            case 2: {
                printf("---------------------------------");
                printf("\nYour Free Memory through meminfo is \n");
                system("cat /proc/meminfo | grep 'MemFree'");
                printf("\nYour Free Memory through vmstat is \n");
                system("vmstat -s | grep 'free memory'");
                printf("---------------------------------\n");
                break;
            }
            case 3: {
                printf("---------------------------------");
                printf("\nYour Used Memory through vmstat is \n");
                system("vmstat -s | grep 'used memory'");
                printf("---------------------------------\n");
                break;
            }
            case 4: {
                printf("---------------------------------");
                printf("\nYour Available Memory through meminfo is \n");
                system("cat /proc/meminfo | grep 'MemAvailable'");
                printf("---------------------------------\n");
                break;
            }
            case 5:
                exit(0);
        }
    } while (1);

    return 0;
}