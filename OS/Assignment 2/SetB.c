#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>

void list(char c, char *dn) 
{
    DIR *dir;
    int cnt = 0;
    struct dirent *entry;
    struct stat buff;

    if ((dir = opendir(dn)) == NULL) 
    {
        printf("Directory %s not found\n", dn);
        return;
    }

    while ((entry = readdir(dir)) != NULL) 
    {
        switch (c) 
        {
            case 'f':
                printf("%s\n", entry->d_name);
                break;
            case 'n':
                cnt++;
                break;
            case 'i':
                stat(entry->d_name, &buff);
                printf("%s\t%ld\n", entry->d_name, (long)buff.st_ino);
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }
    closedir(dir);
}

int main() 
{
    char cmd[80], t1[20], t2[20], t3[20], t4[20];
    int n;
    while (1) 
    {
        printf("myShell$ ");
        fgets(cmd, 80, stdin);
        n = sscanf(cmd, "%s %s %s %s", t1, t2, t3, t4);

        if (strcmp(t1, "list") == 0) 
        {
            if (n >= 3)
                list(t2[0], t3);
            else
                printf("Usage: list <option> <directory>\n");
        } 
        else 
        {
            printf("Unknown command, exiting.\n");
            exit(0);
        }
    }

    return 0;
}
