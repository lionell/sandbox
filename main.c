#include <stdio.h>
/* #include <unistd.h> */
/* #include <signal.h> */

int main() {
  printf("Hello, world");
	/* printf("MAIN PID: %d, PPID: %d, PGID: %d\n", getpid(), getppid(), getpgrp()); */
	/* kill(0, SIGKILL); */
  /* kill(19769, SIGKILL); */
	return 0;
}
