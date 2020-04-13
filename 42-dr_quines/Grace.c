#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

/*
	comment
*/
#define TXT "#include<unistd.h>%1$c#include<stdio.h>%1$c#include<fcntl.h>%1$c%1$c/*%1$c%4$ccomment%1$c*/%1$c#define TXT %2$c%3$s%2$c%1$c#define CLOSE(fd) close(fd)%1$c#define MAIN int main(void) {char *str=TXT;int fd=open(%2$cGrace_kid.c%2$c, O_CREAT|O_WRONLY|O_TRUNC);dprintf(fd, str, 10, 34, str, 9);CLOSE(fd);return 0;}%1$c%1$cMAIN;"
#define CLOSE(fd) close(fd)
#define MAIN int main(void) {char *str=TXT;int fd=open("Grace_kid.c", O_CREAT|O_WRONLY|O_TRUNC);dprintf(fd, str, 10, 34, str, 9);CLOSE(fd);return 0;}

MAIN;