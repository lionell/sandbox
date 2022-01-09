#include <unistd.h>
#include <stdio.h>

int main() {
	printf("SLEEPER PID: %d, PPID: %d, PGID: %d\n", getpid(), getppid(), getpgrp());
	sleep(1000);
	return 0;
}
