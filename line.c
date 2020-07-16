#include<stdio.h>
#pragma warning(disable:4996)
int main() {
	FILE *input, *output;

	input = fopen("line.inp", "rt");
	output = fopen("line.out", "wt");

	int T, m, q, a;

	fscanf(input, "%d", &T);
	for (int x = 0; x < T; x++) {
		int min = 0, max = 0;
		fscanf(input, "%d", &m);
		int y;
		for (y = 0; y < m; y++) {
			fscanf(input, "%d %d", &q, &a);
			int sum = 0, sum1 = 0;
			int e, f;
			if (a == 1) {
				if (q > min) {
					min = q;
				}
			}
			else {
				for (int i = 1; i < a - 1; i++) {
					sum += i;
				}
				for (int i = 1; i < a; i++) {
					sum1 += i;
				}
				if ((q - sum1) % a != 0) {
					e = (q - sum1) / a;
					e++;
				}
				else e = (q - sum) / a;
				f = (q - sum - 1) / (a - 1);
				if (min == 0) {
					min = e;
				}
				if (max == 0) {
					max = f;
				}
				if (e > min) {
					min = e;
				}
				if (f < max) {
					max = f;
				}
			}
			
			//fprintf(output, "%d %d\n", min,max);
			if (max == min) {
				fprintf(output, "%d %d\n", y + 1, min);
				break;
			}
		}
		for (y += 1; y < m; y++) {
			fscanf(input, "%d %d", &q, &a);
		}
		if (max != min) {
			fprintf(output, "-1\n");
		}
	}
	fclose(input);
	fclose(output);
}