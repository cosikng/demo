#include <stdio.h>
#include <string.h>
#include "trap.h"

char buf[128];
char s[]="a";
char format[]="%s";

int main() {
	sprintf(buf,format,s);
	nemu_assert(strcmp(buf, "a") == 0);

	//sprintf(buf, "%s", "Hello world!\n");
	//nemu_assert(strcmp(buf, "Hello world!\n") == 0);

	/*sprintf(buf, "%d + %d = %d\n", 1, 1, 2);
	nemu_assert(strcmp(buf, "1 + 1 = 2\n") == 0);

	sprintf(buf, "%d + %d = %d\n", 2, 10, 12);
	nemu_assert(strcmp(buf, "2 + 10 = 12\n") == 0);*/

	return 0;
}
