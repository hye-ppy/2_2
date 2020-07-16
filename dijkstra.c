#include<stdio.h>
#pragma warning (disable:4996)
int result;
int sum(int n_arr[][2], int arr[][3], int com, int m, int j);
int main() {
	FILE *input, *output;

	input = fopen("dijkstra.inp", "rt");
	output = fopen("dijkstra.out", "wt");

	int n_arr[100][2], arr[100][3];
	int n, m, start = 0;
	fscanf(input, "%d %d", &n, &m);
	for (int x = 0; x < m; x++) {
		n_arr[x][0] = 0;
		n_arr[x][1] = 0;
	}
	for (int x = 0; x < m; x++) {
		fscanf(input, "%d %d %d", &arr[x][0], &arr[x][1], &arr[x][2]);
	}
	n_arr[0][0] = 0;
	n_arr[0][1] = 1;//Á¢±ÙÇÔ~
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[j][0] == start) {
				result = 0;
				if (sum(n_arr, arr, arr[j][0], m, j) == 1) {
					if (n_arr[arr[j][2]][0] > -1 && n_arr[arr[j][2]][1] != 1) {
						if (n_arr[arr[j][2]][0] >= result) {
							n_arr[arr[j][2]][0] = result;
						}
						n_arr[arr[j][2]][1] = 1;
					}
				}
			}
		}
		if (i == 0) {
			for (int p = 1; p < m; p++) {
				if (n_arr[p][0] == 0) n_arr[p][0] = -1;
			}
		}
		int max = 0, min, min_index;
		for (int p = 1; p < m; p++) {
			if (n_arr[p][1] != 1 && n_arr[p][0] > -1) {
				if (max < n_arr[p][0]) {
					max = n_arr[p][0];
					min_index = p;
				}
			}
		}
		min = max;
		for (int p = 1; p < m; p++) {
			if (n_arr[p][1] != 1 && n_arr[p][0] > -1) {
				if (min > n_arr[p][0]) {
					min = n_arr[p][0];
					min_index = p;
				}
			}
		}
		start = min_index;
		int check = 0;
		for (int p = 1; p < m; p++) {
			if (n_arr[p][0] != -1) {
				if (n_arr[p][1] == 0) check = 1;
			}
			if (check == 1) break;
		}
		if (check == 1) break;
	}
	for (int x = 0; x < m; x++) {
		fprintf(output, "%d ", n_arr[x][0]);
	}

	fclose(input);
	fclose(output);
}
int sum(int n_arr[][2], int arr[][3], int com, int m, int j) {
	if (com == 0) {
		result += arr[j][2];
		return 1;
	}
	else {
		for (int x = 0; x < m; x++) {
			if (com == arr[x][1]) {
				if (sum(n_arr, arr, arr[x][0], m, j) == 1) {
					result += arr[j][2];
					return 1;
				}
			}
			
		}
		return 0;
	}
}
	
