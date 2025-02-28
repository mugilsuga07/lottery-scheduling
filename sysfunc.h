#ifndef _SYSFUNC_H_
#define _SYSFUNC_H_

// System call handlers
int sys_chdir(void);
int sys_close(void);
int sys_dup(void);
int sys_exec(void);
int sys_exit(void);
int sys_fork(void);
int sys_fstat(void);
int sys_getpid(void);
int sys_kill(void);
int sys_link(void);
int sys_mkdir(void);
int sys_mknod(void);
int sys_open(void);
int sys_pipe(void);
int sys_read(void);
int sys_sbrk(void);
int sys_sleep(void);
int sys_unlink(void);
int sys_wait(void);
int sys_write(void);
int sys_uptime(void);
int sys_getreadcount(void); 
/* The following code is added by Mugil(MXK230014) and Mahesh(MXA220203)
** Defining a new sys call handler for settickets and getpinfo
*/
int sys_settickets(void);
int sys_getpinfo(void);
/* End of code added */

#endif // _SYSFUNC_H_
