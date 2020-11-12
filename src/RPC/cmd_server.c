#include "cmd.h"

char **
execute_cmd_1_svc(command *argp, struct svc_req *rqstp)
{
	static char * result;

	char cmd[50];
	strcpy(cmd, argp->cmd);
	system(cmd);

	result = "done";
	return &result;
}
