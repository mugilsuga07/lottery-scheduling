#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "sysfunc.h"
#include "pstat.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;
  
  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since boot.
int
sys_uptime(void)
{
  uint xticks;
  
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

/* The following code is added by Mugil Suga and netid MXK230014
** Implementation of settickets system call
** Number of tickets should be greater than 0, if not return -1
*/
int
sys_settickets(void)
{
  int tickets;
  if(argint(0, &tickets) < 0)
    return -1;
  if (tickets < 1)
    return -1;
  setTicketsForProc(tickets);
  return 0;
}
/* End of code added */


/* The following code is added by Mahesh Annamalai and netid MXA220203
** Implementation of getpinfo system call
** Get the pinfo argument from user and assign it
*/
int
sys_getpinfo(void)
{
  struct pstat* p = NULL;
  if((argptr(0, (void*)&p, sizeof(struct pstat)) < 0) || !p) //If user passes NULL pointer return -1
    return -1;
  assignStats(p);  //Assign the pinfo
  return 0;
}
/* End of code added */
