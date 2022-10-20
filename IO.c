#include "IO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Score.h"

#define BUFSIZE 512

int fgeti(int*, FILE*);

int getintinput(const char* message, const char* errormessage)
{
	int value = -1;
	while (value < 1)
	{
		printf("%s", message);
		printf("> ");
		if (fgeti(&value, stdin) == EOF || value < 1)
		{
			printf("%s", errormessage);
		}
	}
	return value;
}

void getnameinput(const char* message, const char* errormessage, name_t name)
{
	name[0] = '\0';
	while (name[0] == '\0')
	{
		printf("%s", message);
		printf("> ");
		fgets(name, size_namemax, stdin);
		if (name[0] == '\0')
		{
			printf("%s", errormessage);
		}
	}
	char* p = strchr(name, '\n');
	if (p) {
		*p = '\0';
	}
}

int fgeti(int* p, FILE* fp)
{
	char buf[BUFSIZE];
	if (fgets(buf, BUFSIZE, fp) == NULL)
	{
		return EOF;
	}
	*p = atoi(buf);
	if (*p == 0 && (strcmp(buf, "0\n") != 0))
	{
		return EOF;
	}
	return 1;
}