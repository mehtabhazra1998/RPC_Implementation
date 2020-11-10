// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include <stdlib.h>
#define PORT 8080 
 
void error(char *msg)
{
perror(msg);
exit(0);
}

int main(int argc, char const *argv[]) 
{ 
	int sock = 0, valread; 
	struct sockaddr_in serv_addr; 
	// char *hello = "Hello from client";
	char hello[50]; 
	char buffer[1024] = {0}; 
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	
	printf("Please enter a command you want to run remotely.\n");
	// scanf("%s",hello);
	fgets(hello, sizeof(hello), stdin);
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
	{ 
		printf("\nInvalid address/ Address not supported \n"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{ 
		printf("\nConnection Failed \n"); 
		return -1; 
	} 
	int n=send(sock , hello , strlen(hello) , 0 );
	if(n<0)
	{
		perror("Error sending the RPC to the Remote machine!!!!!");
	} 
	printf("Hello message sent\n"); 
	valread = read( sock , buffer, 1024); 
	if(valread<0)
	{
		perror("Error receiving response from the Remote Machine!!!!!");
	}
	printf("%s\n",buffer ); 
	return 0; 
} 

