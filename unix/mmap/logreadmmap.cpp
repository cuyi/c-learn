#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <sys/mman.h>
#include <unistd.h>

/*
[chenndao@localhost log]$ ./maplogread 3000000.txt
Finished, total lines is 3000000 
total costed time 0 sec
[chenndao@localhost log]$ ./maplogread 3000000.txt
Finished, total lines is 3000000 
total costed time 1 secs
*/

int main( int argc, char *argv[] )
{
    if ( argc != 2 )
    {
        printf("usage: \n maplogread 50000.txt\n");
        return 0;
    }
  
    char *memory = NULL;
    int file_length = 0;
    //char *start_address = 0;
    int line_num = 0;
    int time_start = time(NULL);
    int fd = open( argv[1], O_RDONLY );
    if ( fd > 0 )
    {
        file_length = lseek(fd, 0L, SEEK_END);
        memory = (char*)mmap( NULL, file_length, PROT_READ, MAP_SHARED, fd, 0 );

        int i=0;
        for ( ; i<file_length; i++ )
        {
            if ( memory[i] == '\n' )
            {
                ++line_num;
            }
        }
      
        close( fd );
        munmap( memory, file_length );
        printf("Finished, total lines is %d \n", line_num);
        printf("total costed time %d sec\n", time(NULL) - time_start);
    }
  
    return 0;
}
