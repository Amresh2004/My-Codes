#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>

// Function to list directory contents or provide directory information
void list(char c, char *dn)
{
    DIR *dir;
    int cnt = 0;
    struct dirent *entry;
    struct stat buff;

    // Attempt to open the directory
    if ((dir = opendir(dn)) == NULL)
    {
        printf("Directory %s not found\n", dn);
        return;
    }

    // Perform the specified action based on the option passed ('f', 'n', 'i')
    switch (c)
    {
    case 'f': // List filenames
        while ((entry = readdir(dir)) != NULL)
        {
            printf("%s\n", entry->d_name);
        }
        break;

    case 'n': // Count the number of entries in the directory
        while ((entry = readdir(dir)) != NULL)
            cnt++;
        printf("Total No. of Entries = %d\n", cnt);
        break;

    case 'i': // List filenames along with their inode numbers
        while ((entry = readdir(dir)) != NULL)
        {
            // Fetch file information and print the inode number if successful
            if (stat(entry->d_name, &buff) == 0)
            {
                printf("%s\t%ld\n", entry->d_name, (long)buff.st_ino);
            }
            else
            {
                perror("stat"); // Print error if stat() fails
            }
        }
        break;

    default:
        printf("Invalid option\n"); // Handle invalid options
        break;
    }

    // Close the directory after processing
    closedir(dir);
}

int main()
{
    char command[80], t1[20], t2[20], t3[20], t4[20];
    int n;

    // Clear the terminal screen at the start
    system("clear");

    // Infinite loop to keep the shell running
    while (1)
    {
        printf("myShell$ "); // Display the shell prompt
        fflush(stdout);      // Ensure the prompt is printed before input

        // Read user input
        if (fgets(command, 80, stdin) == NULL)
        {
            printf("\n");
            break; // Exit loop if reading input fails
        }

        // Remove the newline character from the command string if present
        command[strcspn(command, "\n")] = 0;

        // Check if the user wants to exit the shell
        if (strcmp(command, "exit") == 0)
        {
            printf("Exiting myShell.\n");
            break; // Exit the shell loop
        }

        // Parse the command and its arguments
        n = sscanf(command, "%s %s %s %s", t1, t2, t3, t4);

        // If the command is "list", call the list function
        if (strcmp(t1, "list") == 0)
        {
            if (n >= 3)
                list(t2[0], t3); // Call the list function with the provided arguments
            else
                printf("Usage: list <option> <directory>\n"); // Print usage instructions
        }
        else
        {
            // Handle unknown commands and exit
            printf("Unknown command, exiting.\n");
            exit(0);
        }
    }

    return 0;
}

