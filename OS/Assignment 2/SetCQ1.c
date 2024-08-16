#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

// Function to search for a string in a file
void search(char c, char *s, char *fn)
{
    int handle, i = 1, cnt = 0, j = 0;
    char ch, buff[80];

    // Open the file in read-only mode
    if ((handle = open(fn, O_RDONLY)) == -1)
    {
        perror("Error opening file");
        return;
    }

    // Process the file based on the option provided
    switch (c)
    {
    case 'f': // Find and print the first occurrence of the string
        while (read(handle, &ch, 1) > 0)
        {
            if (ch == '\n')
            {
                buff[j] = '\0';
                j = 0;
                if (strstr(buff, s) != NULL)
                {
                    printf("%d : %s\n", i, buff);
                    break; // Stop after the first occurrence
                }
                i++;
            }
            else
                buff[j++] = ch;
        }
        break;

    case 'c': // Count the total number of occurrences of the string
        while (read(handle, &ch, 1) > 0)
        {
            if (ch == '\n')
            {
                buff[j] = '\0';
                j = 0;
                if (strstr(buff, s) != NULL)
                {
                    cnt++;
                }
                i++;
            }
            else
                buff[j++] = ch;
        }
        printf("Total No. of Occurrences = %d\n", cnt);
        break;

    case 'a': // Print all occurrences of the string
        while (read(handle, &ch, 1) > 0)
        {
            if (ch == '\n')
            {
                buff[j] = '\0';
                j = 0;
                if (strstr(buff, s) != NULL)
                    printf("%d : %s\n", i, buff);
                i++;
            }
            else
                buff[j++] = ch;
        }
        break;

    default:
        printf("Invalid option\n");
        break;
    }

    // Close the file
    close(handle);
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

        // If the command is "search", call the search function
        if (strcmp(t1, "search") == 0)
        {
            if (n == 4) // Ensure all required arguments are provided
            {
                search(t2[0], t3, t4);
            }
            else
            {
                printf("Invalid number of arguments\n");
            }
        }
        else
        {
            // Handle unknown commands
            printf("Unknown command, exiting.\n");
            break;
        }
    }

    return 0;
}
