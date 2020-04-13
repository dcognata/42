#include<stdio.h>
/*
	Comment
*/
void ptr(){};
int main()
{
	/*
		Comment
	*/
	ptr();
	char*a="#include<stdio.h>%1$c/*%1$c%2$cComment%1$c*/%1$cvoid ptr(){};%1$cint main()%1$c{%1$c%2$c/*%1$c%2$c%2$cComment%1$c%2$c*/%1$c%2$cptr();%1$c%2$cchar*a=%3$c%4$s%3$c;%1$c%2$cprintf(a,10,9,34,a);%1$c%2$creturn (0);%1$c}";
	printf(a,10,9,34,a);
	return (0);
}