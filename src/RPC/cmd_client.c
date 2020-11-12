

#include "cmd.h"
#include "stdio.h"


#define MAX_CMD_LENGTH 50

void cmd_prog_1(char *host, char *cmd)
{
	CLIENT *clnt;
	char * *result_1;
	command  execute_cmd_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, CMD_PROG, CMD_VER, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	strcpy(execute_cmd_1_arg.cmd, cmd);
	result_1 = execute_cmd_1(&execute_cmd_1_arg, clnt);
	if (result_1 == (char **) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else
	{
		printf("%s", *result_1);
	}
	
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int main(int argc, char *argv[])
{
	char *host;
	char cmd[MAX_CMD_LENGTH];

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];

	while (1){

		fgets(cmd, MAX_CMD_LENGTH - 1, stdin);
		cmd_prog_1(host, cmd);
	}
	
exit(0);
}
