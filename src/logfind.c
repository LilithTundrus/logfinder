#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

const char version[] = "0.0.1";

void exit(const char *message)
{
    if (errno)
    {
        perror(message);
    }
    else
    {
        printf("Error: %s\n", message);
    }
}

int main(int argc, char *argv[])
{
    log_info("LogFind %s starting...", version);

    // We at least need a default string to look for
    if (argc < 2)
    {
        char err_msg[] = "You must give a string to search logs for a match";
        exit(err_msg);
    }

    for (int i = 0; i < argc; i++)
    {
        printf(argv[i]);
    }

    return 0;
}