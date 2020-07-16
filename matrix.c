#include<stdio.h>
#pragma warning(disable:4996)
int main() {
	FILE *input_fp, *output_fp;

	input_fp = fopen("matrix.inp", "rt");
	output_fp = fopen("matrix.out", "wt");

	int T, n, sum = 0, sum1 = 0;
	int a[300][300], b[300][300] ;
	int s, t;

	fscanf(input_fp, "%d", &T);
	for (int x = 0; x < T; x++) {
		int sum = 0, sum1 = 0;
		fscanf(input_fp, "%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fscanf(input_fp, "%d", &a[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				b[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] != 1) {
					sum++;
				}
			}
		}
		//fprintf(output_fp, "%d", sum);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] != 1) {
					for (s = 0; s < n; s++) {
						for (t = 0; t < n; t++) {
							//if (a[i][j] != 1) {
								if (a[i][j] == a[i][s] + a[t][j]) {
								//일단 여까지 성립하는거 출력
									b[i][j]++;
									//fprintf(output_fp, "b[%d][%d]\n", i, j);
									break;
								}
								if (s == n && t == n) {
									break;
								}
								//fprintf(output_fp, "a[%d][%d]  a[%d][%d]  a[%d][%d]\n", i, j, i, s, t, j);
						//	}
						}
						if (b[i][j] != 0)
							break;
						if (s == n && t == n) {
							break;
						}
					}
					if (s == n && t == n) {
						break;
					}
				}
			}
			if (s == n && t == n) {
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (b[i][j] == 1) {
					sum1++;
				}
			}
		}
		//fprintf(output_fp, "%d", sum1);
		if (sum1 < sum) {
			fprintf(output_fp, "0\n");
		}
		else {
			fprintf(output_fp, "1\n");
		}
	}
		fclose(input_fp);
		fclose(output_fp);
}