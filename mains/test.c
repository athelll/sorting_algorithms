#include <stdio.h>

void string_reversal(char *string)
{
	char *holder = string;
	if (*string == '\0')
		return;
	string_reversal(++string);
	printf("%c", *holder);
}

void main(void)
{
	char baby[] = "hello baby";
	string_reversal(baby);
	printf("\n");
}
