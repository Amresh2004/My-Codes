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
   while (read(handle, &ch, 1) > 0) 
   {
    if (ch == '\n') 
    {
        buff[j] = '\0'; j = 0;

        switch (c) 
        {
            case 'f':
                if (strstr(buff, s)) 
                { 
                    printf("%d : %s\n", i, buff); 
                    break; 
                }
                i++;
                break;

            case 'c':
                if (strstr(buff, s)) cnt++;
                i++;
                break;

            case 'a':
                if (strstr(buff, s)) 
                    printf("%d : %s\n", i, buff);
                i++;
                break;

            default:
                printf("Invalid option\n");
                return;  
        }
    } 
    else 
    {
        buff[j++] = ch;
    }
}

if (c == 'c') 
    printf("Total No. of Occurrences = %d\n", cnt);

    close(handle);
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
