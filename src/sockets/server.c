// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
//#include<readline/readline.h> 
//#include<readline/history.h> 
#include <unistd.h>
#include <stdio.h>
#include <limits.h> // Contains PATH_MAX
#include <string.h>


#define PORT 8080
int readAndParseCmdLine(char **, char **);

void error(char *msg){
  perror(msg);
  printf("HELLO--");
  exit(1);
}
#define MAXCOM 1024 // max number of letters to be supported 
#define MAXLIST 100 // max number of commands to be supported 
  
  
int main(int argc, char const *argv[]) 
{ 
	int server_fd, new_socket, valread; 
	struct sockaddr_in address; 
	int opt = 1; 
	int addrlen = sizeof(address); 
	char buffer[1024] = {0}; 
	char *hello = "Hello from server"; 
	
	// Creating socket file descriptor 
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
	{ 
		perror("socket failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	// Forcefully attaching socket to the port 8080 
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt))) 
	{ 
		perror("setsockopt"); 
		exit(EXIT_FAILURE); 
	} 
	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons( PORT ); 
	
	// Forcefully attaching socket to the port 8080 
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	while(1){
	if (listen(server_fd, 3) < 0) 
	{ 
		perror("listen"); 
		exit(EXIT_FAILURE); 
	} 
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
					(socklen_t*)&addrlen))<0) 
	{ 
		perror("accept"); 
		exit(EXIT_FAILURE); 
	} 
	memset(buffer,0,strlen(buffer));
	valread = read( new_socket , buffer, 1024); 

	int n=fork();
	if(n>0)
		continue;	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	static char * result;

	char cmdd[50];
	strcpy(cmdd, buffer);
	//system(cmd);

	// Open file stream to read output of the executed cmdd command
	FILE *cmd=popen(cmdd,"r");
	char mid_result[24];
	char rs[1000];
	rs[0]='\0';
	char cwd[PATH_MAX]; // PATH_MAX is defined in limits.h


	if (getcwd(cwd, sizeof(cwd)) != NULL) 
	{
       		//printf("Current working dir: %s\n", cwd);
		strcat(rs,cwd);
		strcat(rs,"\n");
		strcat(cwd,"\n");
   	}
	printf("Hi, received your request to execute command!!!\n");
    	//system(cmdd);
	while (fgets(mid_result, sizeof(mid_result), cmd) !=NULL)
		strcat(rs,mid_result);
    	//printf("%s",rs);
	if(strcmp(rs,cwd)==0)
	{
		strcat(rs,"Sorry can't display results for this one. Either the desired command has been executed if it exists , else no such command exists in my vocabulary.");
	}

	pclose(cmd);
	result = rs;



	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	
	
	printf("Here is the entered bash command: %s\n",buffer);
	// printf("%s\n",buffer );

	send(new_socket , result, 1000, 0 );  
	break;
	}
	return 0; 

}

