#include<stdio.h>
#pragma warning (disable:4996)
int main() {
	FILE *input, *output;

	input = fopen("line2.inp", "rt");
	output = fopen("line2.out", "wt");

	int T, n, a[1000], b[1000];

	fscanf(input, "%d", &T);
	for (int x = 0; x < T; x++) {
		int num[1000];
		int nn, temp;
		fscanf(input, "%d", &n);
		for (int i = 0; i < n; i++) {
			fscanf(input, "%d", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			fscanf(input, "%d", &b[i]);
		}
		for (int i = n-1; i > -1; i--) {
			for (int j = 0; j < n; j++) {
				if (a[i] == b[j]) {
					nn = a[i];
					num[nn] = i - j;
					temp = b[j];
					for (int p = 0; p < i - j; p++) {
						b[j + p] = b[j + p + 1];

					}
					b[i] = temp;
					break;
				}
			}
		}
		for (int i = 1; i < n+1; i++) {	
			fprintf(output, "%d ", num[i]);
		}
		fprintf(output, "\n");
	}
	fclose(input);
	fclose(output);
}