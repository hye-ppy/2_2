#include<stdio.h>
#pragma warning(disable:4996)
int main() {
	FILE *input, *output;

	input = fopen("sequence.inp", "rt");
	output = fopen("sequence.out", "wt");

	long long a, l, a1;

	for (int i=1;;i++) {
		long long num = 1;
		fscanf(input, "%lld %lld", &a, &l);
		if (a < 0 && l < 0) break;
		a1 = a;
		for (;;) {
			if (a > l) break;
			else if (a == 1) break;
			
			else if (a % 2 == 0) {
				a /= 2;
				num++;
			}
			else if (a % 2 != 0) {
				a = (a * 3) + 1;
				if (a <= l) {
					num++;
				}
				else break;
			}
		}
		fprintf(output, "Case %d: A = %lld, limit = %lld, number of terms = %lld\n", i, a1, l, num);
	}
	
	fclose(input);
	fclose(output);
}