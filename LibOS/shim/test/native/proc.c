/* -*- mode:c; c-file-style:"k&r"; c-basic-offset: 4; tab-width:4; indent-tabs-mode:nil; mode:auto-fill; fill-column:78; -*- */
/* vim: set ts=4 sw=4 et tw=78 fo=cqt wm=0: */

/* a simple helloworld test */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char ** argv)
{
    for (int i = 0 ; i < 3 ; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(1);
        }

        if (pid) {
            waitpid(pid, NULL, 0);
            exit(0);
        }
    }

    struct dirent * dirent;

    DIR * dir = opendir("/proc");

    while ((dirent = readdir(dir)))
        printf("found %s\n", dirent->d_name);

    closedir(dir);

    return 0;
}
