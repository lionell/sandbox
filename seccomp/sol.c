#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef unsigned long long ull;

ull hash(ull *a, int size) {
  ull ans = 0;
  for (int i = 0; i < size; i++) {
    ans ^= a[i];
  }
  return ans;
}

int main() {
	printf("sizeof(ll) = %ld\n", sizeof(ull));
	int n;
	scanf("%d", &n);
	ull *a = (ull*)malloc(n * sizeof(ull));
	clock_t start = clock();
	for (int i = 0; i < n; i++) {
		scanf("%llu", &a[i]);
	}
	printf("Reading %f seconds\n", (clock() - start) / (double)CLOCKS_PER_SEC);
	start = clock();
  printf("XOR: %llu\n", hash(a, n));
	printf("Computing %f seconds\n", (clock() - start) / (double)CLOCKS_PER_SEC);
	free(a);
	return 0;
}
