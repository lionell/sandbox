#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

const int SIZE = 800000000;

typedef unsigned long long ull;

ull hash(ull *a) {
  ull ans = 0;
  for (int i = 0; i < SIZE / sizeof(ull); i++) {
    ans ^= a[i];
  }
  return ans;
}

int main(int argc, char **argv) {
	clock_t start = clock();
  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    printf("Error opening file");
  }
  char *src = mmap (0, SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
  if (src == MAP_FAILED) {
    printf("MMap failed");
  }
	printf("Reading %f seconds\n", (clock() - start) / (double)CLOCKS_PER_SEC);
	start = clock();
  printf("XOR: %llu\n", hash((ull*)src));
	printf("Computing %f seconds\n", (clock() - start) / (double)CLOCKS_PER_SEC);
  if (munmap(src, SIZE) == -1) {
    printf("Error unmapping.");
  }
  close(fd);
  return 0;
}
