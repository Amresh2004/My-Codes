
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdlib.h> 
#include <string.h> 

void typeline(char *s, char *fn)
{
    int handle, i = 0, cnt = 0, n;
    char ch;

    // Open the file in read-only mode
    if ((handle = open(fn, O_RDONLY)) == -1)
    {
        printf("File %s not found\n", fn);
        return;
    }

    // If the argument is 'a', print the entire file
    if (strcmp(s, "a") == 0)
    {
        while (read(handle, &ch, 1) != 0)
        {
            printf("%c", ch);
        }
        close(handle);
        return;
    }

    // Convert the argument to an integer
    n = atoi(s);

    if (n > 0)
    {
        // Print the first 'n' lines of the file
        while (read(handle, &ch, 1) != 0)
        {
            if (ch == '\n')
                i++; // Count lines
            if (i == n)
                break; // Stop after printing 'n' lines
            printf("%c", ch);
        }
        printf("\n");
    }
    else if (n < 0)
    {
        // Count the total number of lines in the file
        while (read(handle, &ch, 1) != 0)
        {
            if (ch == '\n')
                cnt++; // Count lines
        }

        lseek(handle, 0, SEEK_SET); // Rewind the file to the beginning

        // Find the starting line (relative to the end) and print from there
        while (read(handle, &ch, 1) != 0)
        {
            if (ch == '\n')
                i++; // Count lines from the beginning
            if (i == cnt + n - 1)
                break; // Stop at the starting line
        }
        while (read(handle, &ch, 1) != 0)
        {
            printf("%c", ch); // Print the remaining lines
        }
        printf("\n");
    }

    close(handle); // Close the file descriptor
}

int main()
{
    char command[80], t1[20], t2[20], t3[20], t4[20];
    int n;

    // Clear the terminal screen
    system("clear");

    // Infinite loop to keep the shell running
    while (1)
    {
        printf("myShell$ "); // Display the shell prompt
        fflush(stdout);      // Ensure the prompt is printed

        // Read user input
        if (fgets(command, 80, stdin) == NULL)
        {
            printf("\n");
            break; // Exit if reading fails
        }

        // Remove newline character from input if present
        command[strcspn(command, "\n")] = 0;

        // Parse the command and its arguments
        n = sscanf(command, "%s %s %s %s", t1, t2, t3, t4);

        // Handle the command based on the number of arguments
        switch (n)
        {
        case 1: // Command with no arguments
            if (fork() == 0) // Create a child process
            {
                execlp(t1, t1, NULL); // Execute the command
                perror(t1);           // Print error if exec fails
                exit(EXIT_FAILURE);   // Exit child process on failure
            }
            break;

        case 2: // Command with one argument
            if (fork() == 0)
            {
                execlp(t1, t1, t2, NULL); // Execute the command with the argument
                perror(t1);
                exit(EXIT_FAILURE);
            }
            break;

        case 3: // Command with two arguments
            if (strcmp(t1, "typeline") == 0)
            {
                typeline(t2, t3); // If the command is "typeline", call the typeline function
            }
            else
            {
                if (fork() == 0)
                {
                    execlp(t1, t1, t2, t3, NULL); // Execute the command with two arguments
                    perror(t1);
                    exit(EXIT_FAILURE);
                }
            }
            break;

        case 4: // Command with three arguments
            if (fork() == 0)
            {
                execlp(t1, t1, t2, t3, t4, NULL); // Execute the command with three arguments
                perror(t1);
                exit(EXIT_FAILURE);
            }
            break;

        default: // Handle invalid command or too many arguments
            printf("Invalid command or too many arguments\n");
            break;
        }

        // Wait for all child processes to finish
        while (wait(NULL) > 0)
            ;
    }

    // Print exit message before terminating the shell
    printf("Exiting myShell.\n");
    return 0;
}

