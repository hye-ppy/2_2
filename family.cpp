#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>
#pragma warning (disable:4996)

int main() {
	FILE *input, *output;

	input = fopen("family.inp", "rt");
	output = fopen("family.out", "wt");

	int T, N, a, b;
	
	fscanf(input, "%d", &T);
	for (int x = 0; x < T; x++) {
		int m = 0;
		int temp;
		fscanf(input, "%d", &N);
		vector<int>check(N + 1);
		vector<int>fam(N + 1);
		for (int i = 0; i < N-1; i++) {
			fscanf(input, "%d %d", &a, &b);
			fam[b] = a;
			check[a] = 1;
		}
		for (int i = 1; i <= N; i++) {
			if (check[i] == 0) {
				int s = 0;
				temp = fam[i];
				while (1) {
					s += 1;
					temp = fam[temp];
					if (temp == 0) break;
				}
				if (s > m) m = s;
			}
		}
		fprintf(output, "%d\n", m+1);
	}
	fclose(input);
	fclose(output);

}