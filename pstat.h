/* The following code is added by Mugil(MXK230014) and Mahesh(MXA220203)
** Structure of pstat defined here
*/
#ifndef _PSTAT_H_
#define _PSTAT_H_
#include "param.h"
struct pstat {
 int inuse[NPROC]; // whether this slot of the process table is in use (1 or 0)
 int tickets[NPROC]; // the number of tickets this process has
 int pid[NPROC]; // the PID of each process
 int ticks[NPROC]; // the number of ticks each process has accumulated
};
#endif // _PSTAT_H_
/* End of code added */
