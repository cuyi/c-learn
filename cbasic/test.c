#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void testInvalidAccessOnFunStackWithValAfter()
{
	int tempA = 0;
	int tempArray[4] = {0};
	int tempB = 21;

	printf("before invalid access, tempB = %d\n", tempB);
	tempArray[7] = 1; // invalid index of (4,5,6) will not change tempB, but 7 will change it. 
	printf("after  invalid access, tempB = %d\n", tempB);
}

void testInvalidAccessOnFunStackWithoutValAfter()
{
	int tempA = 0;
	int tempArray[4] = {0};

	tempArray[1000] = 1; // no warning and crash
}

void testInvalidAccessOnHeap()
{
	int tempA = 0;
	int* tempArray = (int*)malloc(4*sizeof(int));
	int tempB = 21;

	memset(tempArray, 0, 4*sizeof(int));
	printf("before invalid access, tempB = %d\n", tempB);
	tempArray[555] = 1; // no warning and crash
	printf("after  invalid access, tempB = %d\n", tempB);
}

int main(void)
{
	printf("stack test:\n");
	testInvalidAccessOnFunStackWithValAfter();
	//testInvalidAccessOnFunStackWithoutValAfter();
	printf("heap test:\n");
	testInvalidAccessOnHeap();
}
