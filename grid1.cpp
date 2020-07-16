#include<stdio.h>
#pragma warning(disable:4996)
int main() {
	FILE *input_fp, *output_fp;

	input_fp = fopen("grid1.inp", "rt");
	output_fp = fopen("grid1.out", "wt");

	if ((input_fp = fopen("grid1.inp", "rt")) == NULL) {
		fprintf(stderr, "can't open %s\n", "grid1.inp");
	}

	if ((output_fp = fopen("grid1.out", "wt")) == NULL) {
		fprintf(stderr, "can't open %s\n", "grid1.out");
	}
	int T, n, m, t, s, k;
	int num, result, ber;
		
	fscanf(input_fp, "%d", &T);

	for (int i=0; i < T; i++) {
		fscanf(input_fp, "%d %d %d %d %d", &n, &m, &t, &s, &k);		
		if (t == 1 && s == 1) {
			num = k / m;
			if (num % 2 != 0 && k%m != 0) {
				result = (num*m) + ((num + 1)*m) + 1 - k;
				fprintf(output_fp, "%d", result);
			}
			else if (num % 2 == 0 && k%m == 0) {
				result = (num*m) + ((num - 1)*m) + 1 - k;
				fprintf(output_fp, "%d", result);
			}
			else {
				fprintf(output_fp, "%d", k);
			}
		}
		else if (t == 1 && s == 2) {
			num = k / m;
			if (num % 2 == 0 && k%m != 0) {
				result = (num*m) + ((num + 1)*m) + 1 - k;
				fprintf(output_fp, "%d", result);
			}
			else if (num % 2 != 0 && k%m == 0) {
				result = (num*m) + ((num - 1)*m) + 1 - k;
				fprintf(output_fp, "%d", result);
			}
			else {
				fprintf(output_fp, "%d", k);
			}
		}
		else if (t == 1 && s == 3) {
			num = k / m;
			if (num % 2 != 0 && k%m != 0) {
				result = (num*m) + ((num + 1)*m) + 1 - k;
				result = (n*m + 1) - result;
				fprintf(output_fp, "%d", result);
			}
			else if (num % 2 == 0 && k%m == 0) {
				result = (num*m) + ((num - 1)*m) + 1 - k;
				result = (n*m + 1) - result;
				fprintf(output_fp, "%d", result);
			}
			else {
				k = (n*m + 1) - k;
				fprintf(output_fp, "%d", k);
			}
		}
		else if (t == 1 && s == 4) {
			num = k / m;
			if (num % 2 == 0 && k%m != 0) {
				result = (num*m) + ((num + 1)*m) + 1 - k;
				result = (n*m + 1) - result;
				fprintf(output_fp, "%d", result);
			}
			else if (num % 2 != 0 && k%m == 0) {
				result = (num*m) + ((num - 1)*m) + 1 - k;
				result = (n*m + 1) - result;
				fprintf(output_fp, "%d", result);
			}
			else {
				k = (n*m + 1) - k;
				fprintf(output_fp, "%d", k);
			}
			
		}
		else if (t == 2 && s == 1) {
			num = k / n;
			if (num % 2 != 0 && k%n != 0) {
				result = (num*n) + ((num + 1)*n) + 1 - k;
				if (result%n == 0) {
				ber = n - 1;
				}
				else {
				ber = result % n - 1;
				}
				if (result%n == 0) {
					result = (result / n) + (m*ber);
				}
				else {
				result = (result / n) + (m*ber) + 1;
				}
				fprintf(output_fp, "%d", result);
			}
			else if (num % 2 == 0 && k%n == 0) {
				result = (num*n) + ((num - 1)*n) + 1 - k;
				if (result%n == 0) {
					ber = n - 1;
				}
				else {
					ber = result % n - 1;
				}
				if (result%n == 0) {
					result = (result / n) + (m*ber);
				}
				else{
					result = (result / n) + (m*ber) + 1;
				}
				fprintf(output_fp, "%d", result);
			}
			else {
				if (k%n == 0) {
					ber = n - 1;
				}
				else {
					ber = k % n - 1;
				}
				if (k%n == 0) {
					k = (k / n) + (m*ber);
				}
				else {
					k = (k / n) + (m*ber) + 1;
				}
				fprintf(output_fp, "%d", k);
			}
		}
		else if (t == 2 && s == 2){
			num = k / n;
			if (num % 2 != 0 && k%n != 0) {
				result = (num*n) + ((num + 1)*n) + 1 - k;
				if (result%n == 0) {
					ber = n - 1;
				}
				else {
					ber = result % n - 1;
				}
				if (result%n == 0) {
					result = (m - 1) - (result / n) + (m*ber) + 2;
				}
				else {
					result = (m - 1) - (result / n) + (m*ber) + 1;
				}
				fprintf(output_fp, "%d", result);
			}
			else if (num % 2 == 0 && k%n == 0) {
				result = (num*n) + ((num - 1)*n) + 1 - k;
				if (result%n == 0) {
					ber = n - 1;
				}
				else {
					ber = result % n - 1;
				}
				if (result%n == 0) {
					result = (m - 1) - (result / n) + (m*ber) + 2;
				}
				else {
					result = (m - 1) - (result / n) + (m*ber) + 1;
				}
				fprintf(output_fp, "%d", result);
			}
			else {
				if (k%n == 0) {
					ber = n - 1;
				}
				else {
					ber = k % n - 1;
				}
				if (k%n == 0) {
					k = (m - 1) - (k / n) + (m*ber) + 2;
				}
				else {
					k = (m - 1) - (k / n) + (m*ber) + 1;
				}
				fprintf(output_fp, "%d", k);
			}
		}
		else if (t == 2 && s == 3) {
			num = k / n;
			if (num % 2 == 0 && k%n != 0) {
				result = (num*n) + ((num + 1)*n) + 1 - k;
				if (result%n == 0) {
					ber = n - 1;
				}
				else {
					ber = result % n - 1;
				}
				if (result%n == 0) {
					result = (m - 1) - (result / n) + (m*ber) + 2;
				}
				else {
					result = (m - 1) - (result / n) + (m*ber) + 1;
				}
				fprintf(output_fp, "%d", result);
			}
			else if (num % 2 != 0 && k%n == 0) {
				result = (num*n) + ((num - 1)*n) + 1 - k;
				if (result%n == 0) {
					ber = n - 1;
				}
				else {
					ber = result % n - 1;
				}
				if (result%n == 0) {
					result = (m - 1) - (result / n) + (m*ber) + 2;
				}
				else {
					result = (m - 1) - (result / n) + (m*ber) + 1;
				}
				fprintf(output_fp, "%d", result);
			}
			else {
				if (k%n == 0) {
					ber = n - 1;
				}
				else {
					ber = k % n - 1;
				}
				if (k%n == 0) {
					k = (m - 1) - (k / n) + (m*ber) + 2;
				}
				else {
					k = (m - 1) - (k / n) + (m*ber) + 1;
				}
				fprintf(output_fp, "%d", k);
			}
		}
		else if (t == 2 && s == 4) {
			num = k / n;
			if (num % 2 == 0 && k%n != 0) {
				result = (num*n) + ((num + 1)*n) + 1 - k;
				if (result%n == 0) {
					ber = n - 1;
				}
				else {
					ber = result % n - 1;
				}
				if (result%n == 0) {
					result = (result / n) + (m*ber);
				}
				else {
					result = (result / n) + (m*ber) + 1;
				}
				fprintf(output_fp, "%d", result);
			}
			else if (num % 2 != 0 && k%n== 0) {
				result = (num*n) + ((num - 1)*n) + 1 - k;
				if (result%n == 0) {
					ber = n - 1;
				}
				else {
					ber = result % n - 1;
				}
				if (result%n == 0) {
					result = (result / n) + (m*ber);
				}
				else {
					result = (result / n) + (m*ber) + 1;
				}
				fprintf(output_fp, "%d", result);
			}
			else {
				if (k%n == 0) {
					ber = n - 1;
				}
				else {
					ber = k % n - 1;
				}
				if (k%n == 0) {
					k = (k / n) + (m*ber);
				}
				else {
					k = (k / n) + (m*ber) + 1;
				}
				fprintf(output_fp, "%d", k);
			}
		}
		fprintf(output_fp, "\n");
	}

	fclose(input_fp);
	fclose(output_fp);

	return 0;
}