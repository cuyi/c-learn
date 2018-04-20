#include <iostream>
#include <unistd.h>

extern "C"{
#include "b.h"
}

void do_while()
{
	usleep(1000);
	printInfo();
}

int start(void)
{
	do_while();
}