#include<stdio.h>
#pragma warning (disable:4996)
int main() {
	FILE *input, *output;

	input = fopen("paper.inp", "rt");
	output = fopen("paper.out", "wt");

	int T, n, m, result;
	char con = 't';
	int na[50][50], ma[50][50];

	fscanf(input, "%d", &T);
	for (int x = 0; x < T; x++) {
		char con = 't';
		fscanf(input, "%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m - 1; j++) {
				fscanf(input, "%d", &na[i][j]);
			}
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				fscanf(input, "%d", &ma[i][j]);
			}
		}
		for (int i = 0; i < n - 1; i++) {
			if (con == 'f') break;
			for (int j = 0; j < m-1; j++) {
				result = ma[i][j] + ma[i][j + 1] + na[i][j] + na[i + 1][j];
				if (result == 1 || result == 3) {
					con = 't';
				}
				else {
					con = 'f';
				}
				if (con == 'f') break;
			}
		}
		if (con == 'f') {
			fprintf(output, "0 ");
		}
		else if (con == 't') {
			fprintf(output, "1 ");
		}
	}
	fclose(input);
	fclose(output);
}