#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <sys/wait.h>

const double CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000.;

double run() {
	clock_t start = clock();
  pid_t pid = fork();
  if (pid == 0) {
    // child
    execvp("./main", NULL);
  }
  waitpid(pid, NULL, 0);
  return (clock() - start) / CLOCKS_PER_MS;
}

void bla() {
  /* printf("%d %d %d\n", getpid(), getppid(), getpgrp()); */
  /* printf("%d", kill(5664, SIGKILL)); */
}

const int TRIALS = 100;

int main() {
	printf("RUNNER PID: %d, PPID: %d, PGID: %d\n", getpid(), getppid(), getpgrp());
  run();
  printf("Bye!\n");
  /* bla(); */
  /* double sum = .0; */
  /* for (int i = 0; i < TRIALS; i++) { */
  /*   sum += run(); */
  /* } */
	/* printf("Execution took %f ms on average\n", sum / TRIALS); */
	return 0;
}
