#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>


// Function to count characters, words, or lines in a file //fn = file name
void count(char c, char *fn)
{
    int lc = 0, wc = 0, cc = 0, handle;
    char ch;

    // Open the file in read-only mode
    if ((handle = open(fn, O_RDONLY)) == -1)
    {
        perror("Error opening file");
        return;
    }

    // Read the file character by character
    while (read(handle, &ch, 1) > 0)
    {
        if (ch == ' ')
        {
            wc++; // Increment word count on encountering a space
        }
        else if (ch == '\n')
        {
            lc++; // Increment line count on encountering a newline
            wc++; // Increment word count as well, assuming end of a word
        }
        else
        {
            cc++; // Increment character count for other characters
        }
    }

    // Close the file
    close(handle);

    // Print the result based on the option provided
    switch (c)
    {
    case 'c':
        printf("Total No. of Characters = %d\n", cc);
        break;
    case 'w':
        printf("Total No. of Words = %d\n", wc);
        break;
    case 'l':
        printf("Total No. of Lines = %d\n", lc);
        break;
    default:
        printf("Invalid option\n");
        break;
    }
}

int main()
{
    char command[80], t1[20], t2[20], t3[20], t4[20];
    int n;

    // Clear the terminal screen at the start
    system("clear");

    // Infinite loop for the shell prompt
    while (1)
    {
        printf("myShell$ "); // Display the shell prompt
        fflush(stdout);      // Ensure prompt is printed before input

        // Get the user input command
        fgets(command, 80, stdin);
            /*
            if (fgets(command, 80, stdin) == NULL)
            {
                printf("\n");
                break; // Exit the loop if fgets fails (e.g., on EOF)
            }
            */

        // Remove the newline character from the command if present
        command[strcspn(command, "\n")] = 0;

        // Exit the shell if the command is "exit"
        if (strcmp(command, "exit") == 0)
        {
            break;
        }

        // Parse the command into separate strings
        n = sscanf(command, "%s %s %s %s", t1, t2, t3, t4);

        // Handle the command based on the number of arguments
        switch (n)
        {
        case 1:              // Command with no arguments
            if (fork() == 0) // Create a child process
            {
                execlp(t1, t1, NULL); // Execute the command
                perror(t1);           // If exec fails, print an error message
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
            if (strcmp(t1, "count") == 0)
            {
                count(t2[0], t3); // If the command is "count", call the count function
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

