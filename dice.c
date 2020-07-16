#include<stdio.h>
#pragma warning (disable:4996)
int main() {

	FILE *input, *output;

	input = fopen("dice.inp", "rt");
	output = fopen("dice.out", "wt");

	int T, next = 0;
	int dice[10000][6], sum[6] = { 0 };
	int result = 0;

	//0-5 1-3 2-4
	fscanf(input, "%d", &T);
	for (int x = 0; x < T; x++) {
		for (int y = 0; y < 6; y++) {
			fscanf(input, "%d ", &dice[x][y]);
		}
	}
	for (int i = 0; i < 6; i++) {//경우의 수 6
		int a, b;
		a = i;
		for (int j = 0; j < T; j++) {
			int max = 0;
			if (a < 3) {
				if (a + 2 == 2) {
					b = 5;
				}
				else {
					b = a + 2;
				}
			}
			else {
				if (a - 2 == 3) {
					b = 0;
				}
				else {
					b = a - 2;
				}
			}
			for (int p = 0; p < 6; p++) {
				if (p != a && p != b) {
					if (dice[j][p] > max) {
						max = dice[j][p];
					}
				}
			}
			sum[i] += max;
			if (j + 1 != T) {
				for (int p = 0; p < 6; p++) {
					if (dice[j][b] == dice[j + 1][p]) {
						a = p;
					}
				}
			}
		}
	}
	
	for (int x = 0; x < 6; x++) {
		if (sum[x] > result) {
			result = sum[x];
		}
	}
	fprintf(output, "%d", result);

	fclose(input);
	fclose(output);
}