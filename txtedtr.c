#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void readFile(FILE *file)
{
	int c;
	while ((c = fgetc(file)) != EOF)
	{
		putchar(c);
  	}
}
void writeFile(FILE *file)
{
	char buffer[1024];
	printf("Enter text (press Ctrl+D or Ctrl+Z on windows to save):\n");
	while (fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
        	fputs(buffer, file);
    	}
}
int main()
{
	char filename[100];
	char mode[3];
	FILE *file;
	printf("Enter filename: ");
	scanf("%s", filename);
 	printf("Enter mode (r/w/a): ");
	scanf("%s", mode);
	if (strcmp(mode, "r") == 0)
	{
        	file = fopen(filename, "r");
    	}
	else if (strcmp(mode, "w") == 0)
	{
        	file = fopen(filename, "w");
    	}
	else if (strcmp(mode, "a") == 0)
	{
        	file = fopen(filename, "a");
    	}
	else
	{
        	printf("Invalid mode.\n");
        	return 1;
    	}

    	if (file == NULL)
	{
        	perror("Error opening file");
        	return 1;
    	}

    	if (strcmp(mode, "r") == 0)
	{
      		readFile(file);
    	}
	else
	{
     		 writeFile(file);
    	}
    	fclose(file);
	return 0;
}

