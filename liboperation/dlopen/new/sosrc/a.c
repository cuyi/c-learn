#include <stdio.h>
#include <unistd.h>

#include "b.h"

void do_while()
{
	do
	{
		usleep(1000000);
		printInfo();
	}while(1);
}

int start(void)
{
	do_while();
	return 0;
}