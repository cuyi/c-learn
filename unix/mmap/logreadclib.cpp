#include <stdio.h>
#include <time.h>
/*
[chenndao@localhost log]$ ./logread 3000000.txt
Finished, total 3000000 lines
Cost time: 20 sec
*/
int main( int argc, char *argv[] )
{
    //Caculate how many lines in the log file.
    if ( argc != 2 )
    {
        printf("usage: \n readlog log.txt\n");
        return 0;
    }

    int lineNum = 0;
    char buff[256] = { 0 };
    time_t timeStart = time( NULL );
    char *data = NULL;
    FILE *fd = fopen( argv[1], "r" );

    if ( fd != NULL )
    {
        int len = 0;
        do
        {
            data = fgets( buff, 256, fd );
            if ( data != NULL )
            {
                int i = 0;
                for( ; i<256; i++)
                {
                    if ( buff[i] == '\n' )
                    {
                         lineNum++;
                         break;
                    }
                }
            }
        }while ( data );

        printf("Finished, total %d lines\n", lineNum);
        printf("Cost time: %d sec\n", time(NULL)-timeStart);
    }
    else
    {
        printf("Open file %s error\n", argv[1]);
    }
    return 0;
}
