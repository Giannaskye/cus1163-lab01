#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "file_operations.h"

int create_and_write_file(const char *filename, const char *content) {
	   int fd;
    ssize_t bytes_written;

    printf("file creating: %s\n", filename);
    
    printf("content writing: %s\n", content);
    
    fd = open(filename, O_CREAT |O_WRONLY | O_TRUNC, 0644);
		if(fd ==-1)
		{
			perror("error open failed");
			return -1;
		}
			
    printf("file descriptor %d\n:",fd);

   
    bytes_written = write(fd,content,strlen(content));
       if(bytes_written == -1)
       {
		   perror("error write failed");
		   close(fd);
		   return -1;
		}
    
	printf("Successfully wrote %zd bytes to %s\n", bytes_written,filename);
    
	close(fd);
	
	if(fd ==-1)
	{
	perror("error close failed");
	return -1;
	}
    
    printf("file closed successfully");
    return 0;
}

int read_file_contents(const char *filename) 
{
    int fd;
  
    char buffer[1024];
 
	ssize_t bytes_read;
 
    printf("file reading %s\n", filename);

    fd= open(filename, O_RDONLY);
    if(fd==-1)
	{
		perror("error file faield to open");
		return -1;
	}
	printf("file descriptor %d:", fd);
    
	printf("---- File Contents ----\n");
    

	while((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0)
	{ 
		buffer[bytes_read] = '\0';
		printf("%s", buffer);
	}
	 if (bytes_read == -1) {
        perror("error read failed");
        close(fd);
        return -1;
    }
    
    printf("\n---- End of File Contents ----\n");

    
		close(fd);
		if(fd == -1)
		{
			perror("file not closed");
			return -1;
			}
			printf("File successfully closed");
    
    return 0;
}
    

