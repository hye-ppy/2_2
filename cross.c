#include<stdio.h>
#pragma warning(disable:4996)
int main() {
	FILE *input_fp, *output_fp;

	input_fp = fopen("cross.inp", "rt");
	output_fp = fopen("cross.out", "wt");

	int T, N, sum = 0;
	int a[10001], b[10001];
	int c[10001], d[10001];

	int gpqls;

	fscanf(input_fp, "%d", &T);

	for (int x = 0; x < T; x++) {
		fscanf(input_fp, "%d", &N);
		for (int i = 0; i < N; i++) {
			fscanf(input_fp, "%d", &a[i]);
		}
		for (int j = 0; j < N; j++) {
			fscanf(input_fp, "%d", &b[j]);
		}
		for (int k = 0; k < N; k++) {
			c[k] = 0;
			d[k] = 0;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				/*if (a[i] == b[j]) {
					d[j]++;
					for (j; j < N; j++) {
						if (d[j+1] > 0) {
							c[i]++;
						}
					}
						//fprintf(output_fp, "%d\n", c[i]);
				}*/
				if (a[i] == b[j]) {
					for (gpqls = j; gpqls < N; gpqls++) {
						if (d[gpqls] > 0) {
							c[gpqls]++;
						}
					}
					d[j]++;
					//fprintf(output_fp, "%d\n", c[i]);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			sum += c[i];
		}
		fprintf(output_fp, "Case %d: %d\n", x + 1, sum);
		sum = 0;
		for (int k = 0; k < N; k++) {
			c[k] = 0;
			d[k] = 0;
		}
	}

	fclose(input_fp);
	fclose(output_fp);
}