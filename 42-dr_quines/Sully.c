#include<strings.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#define TXT "#include<strings.h>%1$c#include<unistd.h>%1$c#include<stdlib.h>%1$c#include<stdio.h>%1$c#include<fcntl.h>%1$c#define TXT %3$c%4$s%3$c%1$cint main(){%1$cint i = %2$d;%1$cint fd = 0;char *str = TXT;char filename[64];char command[64];bzero(filename, 64);bzero(command, 64);if(i>0){sprintf(filename, %3$cSully_%5$cd.c%3$c, i);fd = open(filename, O_RDWR|O_CREAT|O_TRUNC, 0666);sprintf(command, %3$cclang -Wall -Wextra -Werror %5$cs -o Sully_%5$cd && ./Sully_%5$cd%3$c, filename, i, i);dprintf(fd, str, 10, i - 1, 34, str, 37);close(fd);system(command);}else if(i == 0){sprintf(filename, %3$cSully_%5$cd.c%3$c, i);fd = open(filename, O_RDWR|O_CREAT|O_TRUNC, 0666);sprintf(command, %3$cclang -Wall -Wextra -Werror %5$cs -o Sully_%5$cd%3$c, filename, i);dprintf(fd, str, 10, i - 1, 34, str, 37);close(fd);system(command);}return (0);}%1$c"
int main(){
int i = 5;
int fd = 0;char *str = TXT;char filename[64];char command[64];bzero(filename, 64);bzero(command, 64);if(i>0){sprintf(filename, "Sully_%d.c", i);fd = open(filename, O_RDWR|O_CREAT|O_TRUNC, 0666);sprintf(command, "clang -Wall -Wextra -Werror %s -o Sully_%d && ./Sully_%d", filename, i, i);dprintf(fd, str, 10, i - 1, 34, str, 37);close(fd);system(command);}else if(i == 0){sprintf(filename, "Sully_%d.c", i);fd = open(filename, O_RDWR|O_CREAT|O_TRUNC, 0666);sprintf(command, "clang -Wall -Wextra -Werror %s -o Sully_%d", filename, i);dprintf(fd, str, 10, i - 1, 34, str, 37);close(fd);system(command);}return (0);}
