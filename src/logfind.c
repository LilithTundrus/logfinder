#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

const char version[] = "0.0.1";

void die(const char *message)
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
        die(err_msg);
    }

    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
        if (strstr(argv[i], "-o"))
        {
            log_info("Switching to OR mode");
        } else {
            // do nothing
        }
    }

    return 0;
}