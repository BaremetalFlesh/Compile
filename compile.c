#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char exe[99];
    char arg[99];

    if (argc < 2) {
        printf("Usage: %s file.c\n", argv[0]);
    } else {
        strcpy(arg, argv[1]);

        // Check if the file extension is ".c", ".C", or ".cpp"
        if (!(strlen(arg) >= 3 && 
              (strcmp(&arg[strlen(arg) - 2], ".c") == 0 ||
               strcmp(&arg[strlen(arg) - 2], ".C") == 0 ||
               strcmp(&arg[strlen(arg) - 4], ".cpp") == 0))) {
            printf("Error: Input file must have a .c, .C, or .cpp extension\n");
            return 1;
        }

        // Remove the file extension
        arg[strlen(arg) - 2] = '\0';

        snprintf(exe, sizeof(exe), "%s", arg);
        snprintf(arg, sizeof(arg), "%s", argv[1]);

        char command[99];
        snprintf(command, sizeof(command), "gcc -o ./%s ./%s", exe, argv[1]);
        printf("Compiling ./%s as ./%s\n", argv[1], exe);

        system(command);
    }
    return 0;
}
