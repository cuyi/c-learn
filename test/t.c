#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    //void ar[9];
    /*
    int y;
    if ( !((7&8) == 8))
    {
        y = ~7&0X000B;
    }
    printf("%d\n", y++);
    */

    /*
    register int num = 10;
    int *point = &num; // wrong , register variable may not saved in memory
    *point = 11;
    printf("%d %d\n", num, *point);
    */

    /* segment fault
    char *point1 = NULL;
    char *point2 = 0;
    strcpy(point1, "a");
    strcpy(point2, "phrase");

    printf("\n%s %s", point1, point2);
    */

    /* Segment Fault
    int n;
    scanf("%d", n);  // this line?
    printf("%d", n);
    */

    /*
    int x = 257;
    int i = {
        printf("e" "gg")
    };

    for(x = 0; x < i; x++)
    {
        printf("%x", x);
    }
    printf("\n");
    */
    /*
    static char *arr[]={"abcde","abcde","abcd","abcdef"};
    char **ptr[]={arr+3, arr+2, arr+1, arr}, ***p;
    p = ptr;
    ++p;
    printf("%s\n", **p+1);

    (double)(char)3.0;
    */
    /*
    int num;
    scanf("%d", &num);
    ungetc(num, stdin);
    scanf("%d", &num);
    printf("%d\n", num);
    */
    /*
    static int i;
    for(;;)
        if(i+++"Nokia")
            printf("Helllo Nokia");
        else
            break;
    */
    float fp = 0.2;
    if(fp == 0.2)
        printf("same\n");
    else
        printf("not same\n");
    return 0;
}
