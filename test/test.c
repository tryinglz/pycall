#include <stdio.h>

#include "pycall.h"

int main(int argc, char *argv[])
{
    printf("C [Result]: the result is: %d\n", pycall("test", "testFunc", 
                "This is the message."));
    return 0;
}
