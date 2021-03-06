#ifndef _CMD_H_RPCGEN
#define _CMD_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct command {
	char cmd[50];
};
typedef struct command command;

#define CMD_PROG 0x20000001
#define CMD_VER 1

#if defined(__STDC__) || defined(__cplusplus)
#define EXECUTE_CMD 1
extern  char ** execute_cmd_1(command *, CLIENT *);
extern  char ** execute_cmd_1_svc(command *, struct svc_req *);
extern int cmd_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define EXECUTE_CMD 1
extern  char ** execute_cmd_1();
extern  char ** execute_cmd_1_svc();
extern int cmd_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_command (XDR *, command*);

#else /* K&R C */
extern bool_t xdr_command ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CMD_H_RPCGEN */
