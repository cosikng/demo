#include "trap.h"
#include <string.h>

int main() {
	char s[]="Hello";
	char a[10];
	strcpy(a,s);

	nemu_assert(strcmp(s,"Hello")==0);
	return 0;
}
