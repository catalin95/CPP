// read file, open child process and analyse how many number, upper and lower case letters found, send the data to parent process

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define MAXCHAR 1000

int main()
{
    FILE *f;
    char str[MAXCHAR];
    char filename[MAXCHAR];
    int fd[2], ncount = 0, ucount = 0, lcount = 0, x, y, z, id;

    printf("Please insert the path to your file\n");
    scanf("%s",filename);

    f = fopen(filename, "r");

    if (f == NULL)
        printf("Could not open the file\n");
    else
    {
    	if (pipe(fd) == -1)
    		printf("Could not open the pipe\n");

    	id = fork();
    	// child process
    	if (id == 0)
    	{	
    		close(fd[0]);
	        while (fgets(str, MAXCHAR, f) != NULL)
	        {
	            for (int i = 0; i != strlen(str); i++)
	            {
	                if (isdigit(str[i]))    
	                		ncount++;
	                else
	                {
	                   if(isupper(str[i]))
	                   		ucount++;
	                    else
	                    {
	                    	if(islower(str[i]))
	                        	lcount++;
	                   	}
	                }
	            }
	        }
        fclose(f);
        write(fd[1], &ncount, sizeof(int));
        write(fd[1], &ucount, sizeof(int));
        write(fd[1], &lcount, sizeof(int));
    	close(fd[1]);
    	}
    	else
    	{
    		//parent process
    		close(fd[1]);
    		read(fd[0], &x, sizeof(int));
    		read(fd[0], &y, sizeof(int));
    		read(fd[0], &z, sizeof(int));
    		close(fd[1]);
    		printf("Numbers found: %d\n", x);
    		printf("Upper case letters found: %d\n", y);
    		printf("Lower case letters found: %d\n", z);
    		return 0;
    	}
    }
    
    return 0;
} 
