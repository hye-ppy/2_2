#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>
#pragma warning (disable:4996)
int main() {
	FILE *input, *output;

	input = fopen("entrance.inp", "rt");
	output = fopen("entrance.out", "wt");

	int T, N, n;
	fscanf(input, "%d", &T);
	for (int x = 0; x < T; x++) {
		fscanf(input, "%d", &N);
		vector<vector<int> > a(N);
		int count = 0;
		for (int y = 0; y < N; y++) {
			int max = 0, index;
			fscanf(input, "%d", &n);
			if (y == 0) {
				a[count].push_back(n);
			}
			else {
				for (int i = 0; i <= count; i++) {
					if (n>*(a[i].end() - 1) &&*(a[i].end()-1) > max) {
						index = i;
						max = *(a[i].end() - 1);
					}
				}
				if (max == 0) {
					count++;
					a[count].push_back(n);
				}
				else {
					a[index].push_back(n);
				}
			}
		}
		fprintf(output, "%d\n", count + 1);
	}
	fclose(input);
	fclose(output);
}