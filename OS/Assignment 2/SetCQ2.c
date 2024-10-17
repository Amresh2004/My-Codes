#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>


void typeline(char *s, char *fn)
{
    int handle = open(fn, O_RDONLY);

    if (strcmp(s, "a") == 0)
    {
        char ch;
        while (read(handle, &ch, 1) > 0)  putchar(ch);
    }
    else
    {
        int n = atoi(s);
        char ch;
        int lc = 0;

        if (n > 0)
        {
            while (read(handle, &ch, 1) > 0 && lc < n)
            {
                putchar(ch);
                if (ch == '\n')  lc++;
            }
        }
        else
        {
            int tl = 0;
            lseek(handle, 0, SEEK_SET);
            while (read(handle, &ch, 1) > 0)
            {
                if (ch == '\n')
                    tl++;
            }
            lseek(handle, 0, SEEK_SET); 
            lc = tl + n; 
            while (read(handle, &ch, 1) > 0)
            {
                if (lc <= 0)
                    putchar(ch);
                if (ch == '\n')
                    lc--;
            }
        }
    }
    close(handle);
}

int main() 
{
    char cmd[80], t1[20], t2[20], t3[20], t4[20];
    int n;

    system("clear");

    while (1) 
    {
        printf("myShell$ ");
        fgets(cmd, 80, stdin); 


             n = sscanf(cmd, "%s %s %s %s", t1, t2, t3, t4);

            if (strcmp(t1, "typeline") == 0) 
            {
                typeline(t2, t3);
            } 
            else 
            {
                printf("Error");
            }

        while (wait(NULL) > 0);
    }

    printf("Exiting myShell.\n");
    return 0;
}
