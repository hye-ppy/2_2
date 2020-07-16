#include<stdio.h>
#pragma warning(disable:4996)
int main() {

	FILE *input, *output;

	input = fopen("add.inp", "rt");
	output = fopen("add.out", "wt");

	long long T, n, a[10000], temp, Temp;

	while (1) {
		long long result = 0;
		fscanf(input, "%lld", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			fscanf(input, "%lld", &a[i]);
		}
		for (long long i = 0; i < n - 1; i++) {
			for (long long j = 0; j < n - 1 - i; j++) {
				if (a[j] > a[j + 1]) {
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
		for (long long p = 0; p < n; p++) {
			
			if (p == 0) {
				a[p + 1] += a[p];
				result += a[p + 1];//더하면 결과에 넣자~~
				for (int q = p + 1; q < n - 1; q++) {
					if (a[q] > a[q + 1]) {
						temp = a[q];
						a[q] = a[q + 1];
						a[q + 1] = temp;
					}
					else break;
				}
				p++;
			}
			else if (p + 1 != n) {
				if (a[p] + a[p + 1] >= a[p] + a[p - 1]) {
					a[p] += a[p - 1];
					result += a[p];
					for (int q = p; q < n - 1; q++) {
						if (a[q] > a[q + 1]) {
							temp = a[q];
							a[q] = a[q + 1];
							a[q + 1] = temp;
						}
						else break;
					}
				}
				else if (a[p] + a[p + 1] < a[p] + a[p - 1]) {
					a[p + 1] += a[p];
					result += a[p + 1];
					for (int q = p + 1; q < n - 1; q++) {
						if (a[q] > a[q + 1]) {
							temp = a[q];
							a[q] = a[q + 1];
							a[q + 1] = temp;
						}
						else break;
					}
					p++;//다음항이랑 더하면!!!!
				}
			}
			else {
				a[p] += a[p - 1];
				result += a[p];
			}
			
		}
		fprintf(output, "%lld\n", result);

	}
	fclose(input);
	fclose(output);
}
