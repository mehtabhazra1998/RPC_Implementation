#include "cmd.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h> // Contains PATH_MAX
#include <string.h>

char ** execute_cmd_1_svc(command *argp, struct svc_req *rqstp)
{
	static char * result;

	char cmdd[50];
	strcpy(cmdd, argp->cmd);
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
	return &result;
}
