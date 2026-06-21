// myshell_step3.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAXLINE 1024
#define MAX_ARGS 100

void parse_command(char *line, char *argv[]) {
    int i = 0;
    char *token = strtok(line, " \t");
    while (token != NULL && i < MAX_ARGS - 1) {
        argv[i++] = token;
        token = strtok(NULL, " \t");
    }
    argv[i] = NULL;
}

int main(void) {
    char line[MAXLINE];
    char *argv[MAX_ARGS];

    while (1) {
        // Prompt
        printf("myshell> ");
        fflush(stdout);

        // Read
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("\n");
            break; // EOF or error
        }
        // Trim newline
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') line[len-1] = '\0';

        // Exit built-in
        if (strcmp(line, "exit") == 0) break;

        // Parse
        parse_command(line, argv);
        if (argv[0] == NULL) continue; // empty line

        // Fork
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            continue;
        }

        if (pid == 0) {
            // Child: execute the command
            execvp(argv[0], argv);
            // If execvp returns, an error occurred
            fprintf(stderr, "myshell: %s: %s\n", argv[0], strerror(errno));
            _exit(127); // child exits with failure code
        } else {
            // Parent: wait for child
            int status;
            if (waitpid(pid, &status, 0) == -1) {
                perror("waitpid");
            } else {
                if (WIFEXITED(status)) {
                    // child exited normally
                    // (you can inspect WEXITSTATUS(status) if desired)
                } else if (WIFSIGNALED(status)) {
                    // child was terminated by a signal
                    printf("myshell: child killed by signal %d\n", WTERMSIG(status));
                }
            }
        }
    }

    return 0;
}
