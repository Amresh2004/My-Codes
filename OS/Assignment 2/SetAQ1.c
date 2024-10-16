#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>

void count(char c, char *fn) 
{
    int lc = 0, wc = 0, cc = 0, handle;
    char ch;

    if ((handle = open(fn, O_RDONLY)) == -1) 
    {
        perror("Error opening file");
        return;
    }

    while (read(handle, &ch, 1) > 0) 
    {
        if (ch == ' ') 
	{
            wc++;
        } 
	else if (ch == '\n') 
	{
            lc++;
            wc++;
        } 
	else 
	{
            cc++;
        }
    }

    close(handle);

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
    char cmd[80], t1[20], t2[20], t3[20], t4[20];
    int n;

    system("clear");

    while (1) 
    {
        printf("myShell$ ");
        fflush(stdout);

        fgets(cmd, 80, stdin);
        cmd[strcspn(cmd, "\n")] = 0;

        if (strcmp(cmd, "exit") == 0) 
	{
            break;
        }

        n = sscanf(cmd, "%s %s %s %s", t1, t2, t3, t4);

        if (strcmp(t1, "count") == 0) 
	{
		count(t2[0], t3);
	} 
	else 
	{
		printf("Error"); 
	}
    }
    printf("Exiting myShell.\n");
    return 0;
}
