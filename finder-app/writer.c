#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>

/**
 * function for parse arguments.
 *      - file_path [out]
 *      - writestr [out]
 *      - argc [in]
 *      - argv [in]
 */
void parse_arguments(char **file_path, char **writestr, int argc, char *argv[]);


int main(int argc, char *argv[])
{
    char *file_path, *writestr;
    int fd, str_len;
    
    parse_arguments(&file_path, &writestr, argc, argv);

    str_len = strlen(writestr);

    /* opening file */
    fd = open(file_path, O_WRONLY | O_CREAT, 0664);

    /* opening syslog */
    openlog(NULL, 0, LOG_USER);

    if (-1 == fd) {
        perror("Opening File Error");
        syslog(LOG_ERR, "Opening %s File Error: %s\n", file_path, strerror(errno));
        exit(1);
    }

    /* writing to file */
    int written_len = write(fd, writestr, str_len);
    
    /* report with syslog */
    syslog(LOG_DEBUG, "Writing %s to %s\n", writestr, file_path);

    return 0;
}

void parse_arguments(char **file_path, char **writestr, int argc, char *argv[])
{
    if (2 > argc) {
        printf("file path is not specified\n");
        syslog(LOG_ERR, "file path is not specified\n");
        exit(1);
    }
    if  (3 > argc) {
        printf("writestr text is not specified\n");
        syslog(LOG_ERR, "writestr text is not specified\n");
        exit(1);
    }

    *file_path = argv[1];
    *writestr = argv[2];
}