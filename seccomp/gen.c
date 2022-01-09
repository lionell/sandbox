#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

unsigned char a[sizeof(ull)];

ull get() {
  for (int i = 0; i < sizeof(ull); i++) {
    a[i] = rand() % 256;
  }
  return *((ull*)a);
}

int main() {
  ull n = 100000000;
	FILE *fd = fopen("big", "w");
  fprintf(fd, "%llu ", n);
	for (ull i = 0; i < n; i++) {
    fprintf(fd, "%llu ", get());
	}
	fclose(fd);
	return 0;
}
