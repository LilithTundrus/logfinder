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

void help() {
    char help_message[] = 
    "USAGE: \n\nlogfind [argument] string, string ...\n\n[argument] can be -o, -a or -h\n";
    printf(help_message);
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

    // iterate over each argument, stuffing the 3rd+ args into an 
    // array to check a set of logs for
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
        if (strstr(argv[i], "-o"))
        {
            log_info("Switching to OR mode");
        }
        else if (strstr(argv[i], "-h"))
        {
            help();
            break;
        }
        else
        {
            // do nothing, we've already set the mode
        }
    }

    return 0;
}