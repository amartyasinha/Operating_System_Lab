//
// Created by amartya on 11/09/21.
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char a[100];
    int n;
    int fd1 = open("source.txt", O_RDONLY);
    int fd2 = open("target.txt", O_WRONLY | O_CREAT);

    if (fd1 < 0)
        printf("\nSource File cannot be opened.\n");

    if (fd2 < 0)
        printf("\nTarget File cannot be opened/created.\n");

    while ((n = read(fd1, a, 100)) > 0)
        write(fd2, a, n);

    write(fd2, "\0", 1);

    if (n < 0)
        printf("\nFile could not read the content.\n");

    close(fd1);
    close(fd2);
    fd2 = open("target.txt", O_RDONLY);
    printf("\nFile 1 has been Copied to File 2 and its Contents are\n");

    while ((n = read(fd2, a, 99)) > 0) {
        a[99] = '\0';
        printf("%s", a);
    }

    return 0;
}