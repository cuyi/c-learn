#pragma once
#include <cstdint>
#include <climits>
#include <sys/utsname.h>
#include <cstring>

int getProgramBits()
{
    return sizeof(void*) * CHAR_BIT;
}

int getSystemBits()
{
    struct utsname unameObj;
    
    uname(&unameObj);
    char *pchar = unameObj.machine;

    if(0 == strcmp(pchar, "x86_64"))
        return 64;
    else if(0 == strcmp(pchar, "i686") ||
            0 == strcmp(pchar, "i386"))
        return 32;
    else
    {
        return -1;
    }
}
