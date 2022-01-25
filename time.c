#include "types.h"
#include "stat.h"
#include "user.h"

int stdout = 1;
int stderr = 2;

void printTimeMilisecondsPrecision(int ticks) {
  int sec = ticks / 100;
  int milisec = ticks % 100;

  if(ticks < 0) {
    sec = 0;
    milisec = 0;
  }

  if (milisec >= 10 && milisec < 100) printf(stdout, "%d.0%d seconds\n", sec, milisec);
  else if (milisec < 10) printf(stdout, "%d.00%d seconds\n", sec, milisec);
  else printf(stdout, "%d.%d seconds\n", sec, milisec);
}

int
main(int argc, char *argv[])
{
  
  int sysTimeStart = time();
  int startTicks = uptime();
  int pid = fork();

  if (pid < 0){
    printf(2, "Error: Invalid PID!\n");
    exit();
  }

  if (pid > 0) wait();

  if (pid == 0) {
    if (exec(argv[1], argv + 1) < 0) {
      printf(2, "Error: Exec fails!\n");
      exit();
    }
  }

  int sysTimeEnd = time();
  int endTicks = uptime();

  int realTime = (endTicks - startTicks)*10;
  int sysTime = (sysTimeEnd - sysTimeStart)*10;
  int userTime = realTime - sysTime;

  printf(stdout, "real ");
  printTimeMilisecondsPrecision(realTime);
  printf(stdout, "user ");
  printTimeMilisecondsPrecision(userTime);
  printf(stdout, "sys ");
  printTimeMilisecondsPrecision(sysTime);
  
  exit();
  
}