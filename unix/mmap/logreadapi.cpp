#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
/*
[chenndao@localhost log]$ gcc -o logreadapi logreadapi.c
[chenndao@localhost log]$ ./logreadapi 3000000.txt
Finished, total 3000000 lines
Cost time: 72 sec
[chenndao@localhost log]$ 
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
    int fd = open( argv[1], O_RDONLY );
    
    if ( fd > 0 )
    {
        int len = 0;
        do
        {
            len = read( fd, buff, 256 );
            if ( len > 0 )
            {
                int i = 0;
                for( ; i<len; i++)
                {
                    if ( buff[i] == '\n' )
                    {
                        lineNum++;
                    }
                }
            }
        }while ( len > 0 );

        printf("Finished, total %d lines\n", lineNum);
        printf("Cost time: %d sec\n", time(NULL)-timeStart);
    }
    else
    {
        printf("Open file %s error\n", argv[1]);
    }

    return 1;
}

