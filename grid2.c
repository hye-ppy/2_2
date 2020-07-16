#include<stdio.h>
#pragma warning(disable:4996)
int main() {
	FILE *input_fp, *output_fp;

	input_fp = fopen("grid2.inp", "rt");
	output_fp = fopen("grid2.out", "wt");

	int T, n, m, t, s, k;

	fscanf(input_fp, "%d", &T);
	for (int x = 0; x < T; x++) {
		fscanf(input_fp, "%d %d %d %d %d", &n, &m, &t, &s, &k);
		int sum = 0, result = 0, a = 0, b = 0, c = 0, d = 0;
		int asum = 0, bsum = 0, csum = 0, dsum = 0;
		int asum1 = 0, bsum1 = 0, csum1 = 0, dsum1 = 0;
		int m1, n1;
		m1 = m;
		n1 = n;
		if (t == 3 && s == 1) {
			for (sum = 0; sum < k; sum++) {
				if (asum1 != m) {
					a++;
					if (a == m) {
						asum += a;
						asum1 += a;
						a = 0;
					}
				}
				else if (bsum1 != (n - 1)) {
					b++;
					if (b == n - 1) {
						bsum += b;
						bsum1 += b;
						b = 0;
					}
				}
				else if (csum1 != (m - 1)) {
					c++;
					if (c == m - 1) {
						csum += c;
						csum1 += c;
						c = 0;
					}
				}
				else if (dsum1 != (n - 2)) {
					d++;
					if (d == n - 2) {
						dsum += d;
						dsum1 += d;
						d = 0;
						m-=2;
						n-=2;
						asum1 = 0;
						bsum1 = 0;
						csum1 = 0;
						dsum1 = 0;
						
					}
				}
			}
			asum += a;
			bsum += b;
			csum += c;
			dsum += d;
			//fprintf(output_fp, "%d %d %d %d\n", asum, bsum, csum, dsum);
			result = asum + (bsum*m1) - csum - (dsum*m1);
			fprintf(output_fp, "%d\n", result);
		}
		else if (t == 3 && s == 2) {
			for (sum = 0; sum < k; sum++) {
				if (asum1 != n) {
					a++;
					if (a == n) {
						asum += a;
						asum1 += a;
						a = 0;
					}
				}
				else if (bsum1 != (m - 1)) {
					b++;
					if (b == m - 1) {
						bsum += b;
						bsum1 += b;
						b = 0;
					}
				}
				else if (csum1 != (n - 1)) {
					c++;
					if (c == n - 1) {
						csum += c;
						csum1 += c;
						c = 0;
					}
				}
				else if (dsum1 != (m - 2)) {
					d++;
					if (d == m - 2) {
						dsum += d;
						dsum1 += d;
						d = 0;
						m -= 2;
						n -= 2;
						asum1 = 0;
						bsum1 = 0;
						csum1 = 0;
						dsum1 = 0;

					}
				}
			}
			asum += a;
			bsum += b;
			csum += c;
			dsum += d;
			//fprintf(output_fp, "%d %d %d %d\n", asum, bsum, csum, dsum);
			result = asum * m1 - bsum - csum * m1 + dsum;
			fprintf(output_fp, "%d\n", result);
		}
		else if (t == 3 && s == 3) {
			for (sum = 0; sum < k; sum++) {
				if (asum1 != m) {
					a++;
					if (a == m) {
						asum += a;
						asum1 += a;
						a = 0;
					}
				}
				else if (bsum1 != (n - 1)) {
					b++;
					if (b == n - 1) {
						bsum += b;
						bsum1 += b;
						b = 0;
					}
				}
				else if (csum1 != (m - 1)) {
					c++;
					if (c == m - 1) {
						csum += c;
						csum1 += c;
						c = 0;
					}
				}
				else if (dsum1 != (n - 2)) {
					d++;
					if (d == n - 2) {
						dsum += d;
						dsum1 += d;
						d = 0;
						m -= 2;
						n -= 2;
						asum1 = 0;
						bsum1 = 0;
						csum1 = 0;
						dsum1 = 0;

					}
				}
			}
			asum += a;
			bsum += b;
			csum += c;
			dsum += d;
			//fprintf(output_fp, "%d %d %d %d\n", asum, bsum, csum, dsum);
			result = ((m1*n1) + 1) - asum - bsum * m1 + csum + dsum * m1;
			fprintf(output_fp, "%d\n", result);
		}
		else if (t == 3 && s == 4) {
			for (sum = 0; sum < k; sum++) {
				if (asum1 != n) {
					a++;
					if (a == n) {
						asum += a;
						asum1 += a;
						a = 0;
					}
				}
				else if (bsum1 != (m - 1)) {
					b++;
					if (b == m - 1) {
						bsum += b;
						bsum1 += b;
						b = 0;
					}
				}
				else if (csum1 != (n - 1)) {
					c++;
					if (c == n - 1) {
						csum += c;
						csum1 += c;
						c = 0;
					}
				}
				else if (dsum1 != (m - 2)) {
					d++;
					if (d == m - 2) {
						dsum += d;
						dsum1 += d;
						d = 0;
						m -= 2;
						n -= 2;
						asum1 = 0;
						bsum1 = 0;
						csum1 = 0;
						dsum1 = 0;

					}
				}
			}
			asum += a;
			bsum += b;
			csum += c;
			dsum += d;
			//fprintf(output_fp, "%d %d %d %d\n", asum, bsum, csum, dsum);
			result = ((m1*n1) + 1) - asum * m1 + bsum + csum * m1 - dsum;
			fprintf(output_fp, "%d\n", result);

		}
		else if (t == 4 && s == 1) {
			for (sum = 0; sum < k; sum++) {
				if (asum1 != n) {
					a++;
					if (a == n) {
						asum += a;
						asum1 += a;
						a = 0;
					}
				}
				else if (bsum1 != (m - 1)) {
					b++;
					if (b == m - 1) {
						bsum += b;
						bsum1 += b;
						b = 0;
					}
				}
				else if (csum1 != (n - 1)) {
					c++;
					if (c == n - 1) {
						csum += c;
						csum1 += c;
						c = 0;
					}
				}
				else if (dsum1 != (m - 2)) {
					d++;
					if (d == m - 2) {
						dsum += d;
						dsum1 += d;
						d = 0;
						m -= 2;
						n -= 2;
						asum1 = 0;
						bsum1 = 0;
						csum1 = 0;
						dsum1 = 0;

					}
				}
			}
			asum += a;
			bsum += b;
			csum += c;
			dsum += d;
			//fprintf(output_fp, "%d %d %d %d\n", asum, bsum, csum, dsum);
			result = -(m1-1) + asum * m1 + bsum - csum * m1 - dsum;
			fprintf(output_fp, "%d\n", result);
		}
		else if (t == 4 && s == 2) {
			for (sum = 0; sum < k; sum++) {
				if (asum1 != m) {
					a++;
					if (a == m) {
						asum += a;
						asum1 += a;
						a = 0;
					}
				}
				else if (bsum1 != (n - 1)) {
					b++;
					if (b == n - 1) {
						bsum += b;
						bsum1 += b;
						b = 0;
					}
				}
				else if (csum1 != (m - 1)) {
					c++;
					if (c == m - 1) {
						csum += c;
						csum1 += c;
						c = 0;
					}
				}
				else if (dsum1 != (n - 2)) {
					d++;
					if (d == n - 2) {
						dsum += d;
						dsum1 += d;
						d = 0;
						m -= 2;
						n -= 2;
						asum1 = 0;
						bsum1 = 0;
						csum1 = 0;
						dsum1 = 0;

					}
				}
			}
			asum += a;
			bsum += b;
			csum += c;
			dsum += d;
			//fprintf(output_fp, "%d %d %d %d\n", asum, bsum, csum, dsum);
			result = (m1 + 1) - asum + bsum * m1 + csum - dsum * m1;
			fprintf(output_fp, "%d\n", result);
		}
		else if (t == 4 && s == 3) {
			for (sum = 0; sum < k; sum++) {
				if (asum1 != n) {
					a++;
					if (a == n) {
						asum += a;
						asum1 += a;
						a = 0;
					}
				}
				else if (bsum1 != (m - 1)) {
					b++;
					if (b == m - 1) {
						bsum += b;
						bsum1 += b;
						b = 0;
					}
				}
				else if (csum1 != (n - 1)) {
					c++;
					if (c == n - 1) {
						csum += c;
						csum1 += c;
						c = 0;
					}
				}
				else if (dsum1 != (m - 2)) {
					d++;
					if (d == m - 2) {
						dsum += d;
						dsum1 += d;
						d = 0;
						m -= 2;
						n -= 2;
						asum1 = 0;
						bsum1 = 0;
						csum1 = 0;
						dsum1 = 0;

					}
				}
			}
			asum += a;
			bsum += b;
			csum += c;
			dsum += d;
			//fprintf(output_fp, "%d %d %d %d\n", asum, bsum, csum, dsum);
			result = ((m1*n1) + m1) - asum * m1 - bsum + csum * m1 + dsum;
			fprintf(output_fp, "%d\n", result);
		}
		else if (t == 4 && s == 4) {
			for (sum = 0; sum < k; sum++) {
				if (asum1 != m) {
					a++;
					if (a == m) {
						asum += a;
						asum1 += a;
						a = 0;
					}
				}
				else if (bsum1 != (n - 1)) {
					b++;
					if (b == n - 1) {
						bsum += b;
						bsum1 += b;
						b = 0;
					}
				}
				else if (csum1 != (m - 1)) {
					c++;
					if (c == m - 1) {
						csum += c;
						csum1 += c;
						c = 0;
					}
				}
				else if (dsum1 != (n - 2)) {
					d++;
					if (d == n - 2) {
						dsum += d;
						dsum1 += d;
						d = 0;
						m -= 2;
						n -= 2;
						asum1 = 0;
						bsum1 = 0;
						csum1 = 0;
						dsum1 = 0;

					}
				}
			}
			asum += a;
			bsum += b;
			csum += c;
			dsum += d;
			//fprintf(output_fp, "%d %d %d %d\n", asum, bsum, csum, dsum);
			result = ((m1*n1) - m1) + asum - bsum * m1 - csum + dsum * m1;
			fprintf(output_fp, "%d\n", result);
		}


	}


	fclose(input_fp);
	fclose(output_fp);
}