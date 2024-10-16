#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
void search(char c, char *s, char *fn)
{
    int handle, i = 1, cnt = 0, j = 0;
    char ch, buff[80];
    if ((handle = open(fn, O_RDONLY)) == -1)
    {
        perror("Error opening file");
        return;
    }
    switch (c)
    {
    case 'f':
        while (read(handle, &ch, 1) > 0)
        {
            if (ch == '\n')
            {
                buff[j] = '\0';
                j = 0;
                if (strstr(buff, s) != NULL)
                {
                    printf("%d : %s\n", i, buff);
                    break; 
                }
                i++;
            }
            else
                buff[j++] = ch;
        }
        break;
    case 'c': 
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
    case 'a': 
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
    close(handle);
}
int main()
{
    char command[80], t1[20], t2[20], t3[20], t4[20];
    int n;
    system("clear");
    while (1)
    {
        printf("myShell$ "); 
        fflush(stdout);      
        if (fgets(command, 80, stdin) == NULL)
        {
            printf("\n");
            break; 
        }
        command[strcspn(command, "\n")] = 0;
        n = sscanf(command, "%s %s %s %s", t1, t2, t3, t4);
        if (strcmp(t1, "search") == 0)
        {
            if (n == 4)
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
            printf("Unknown command, exiting.\n");
            break;
        }
    }
    return 0;
}
