#ifndef _SYSCALL_H_
#define _SYSCALL_H_

// System call numbers
#define SYS_fork    1
#define SYS_exit    2
#define SYS_wait    3
#define SYS_pipe    4
#define SYS_write   5
#define SYS_read    6
#define SYS_close   7
#define SYS_kill    8
#define SYS_exec    9
#define SYS_open   10
#define SYS_mknod  11
#define SYS_unlink 12
#define SYS_fstat  13
#define SYS_link   14
#define SYS_mkdir  15
#define SYS_chdir  16
#define SYS_dup    17
#define SYS_getpid 18
#define SYS_sbrk   19
#define SYS_sleep  20
#define SYS_uptime 21
#define SYS_getreadcount 22
/* The following code is added by Mugil(MXK230014) and Mahesh(MXA220203)
** Defining two new sys calls settickets and getpinfo with unique number
*/
#define SYS_settickets 23
#define SYS_getpinfo 24
/* End of code added */

#endif // _SYSCALL_H_
