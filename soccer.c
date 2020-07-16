#include <stdio.h>
#pragma warning (disable:4996)
int main() {
	FILE *input, *output;
	input = fopen("soccer.inp", "rt");
	output = fopen("soccer.out", "wt");

	int T, n, k, x, y, a, b;
	char l;
	int a_goal[41], h_goal[41], a_nogoal[41], h_nogoal[41], goal[41], nogoal[41];
	int point[41], rank[41];

	fscanf(input, "%d", &T);
	for (int i = 0; i < T; i++) {
		fscanf(input, "%d %d", &n, &k);
		for (int p = 1; p < n+1; p++) {
			a_goal[p] = 0;
			h_goal[p] = 0;
			a_nogoal[p] = 0; 
			h_nogoal[p] = 0;
			point[p] = 0;
			goal[p] = 0;
			nogoal[p] = 0;
		}
		for (int j = 0; j < 2 * k*(n - 1)*(n / 2); j++) {
			fscanf(input, "%d%c%d %d %d ", &x, &l, &y, &a, &b);
			a_goal[x] += a;
			a_nogoal[x] += b;
			h_goal[y] += b;
			h_nogoal[y] += a;
			if (a > b) {
				point[x] += 3;
			}
			else if (a < b) {
				point[y] += 3;
			}
			else if (a == b) {
				point[x] += 1;
				point[y] += 1;
			}
		}
		for (int q = 1; q < n+1; q++) {
			goal[q] = a_goal[q] + h_goal[q];
			nogoal[q] = a_nogoal[q] + h_nogoal[q];
		}
		for (int v = 1; v < n + 1; v++) {
			rank[v] = 1;
			for (int w = 1; w < n + 1; w++) {
				if (point[v] < point[w]) {
					rank[v]++;
				}
				else if (point[v] == point[w]) {
					if (goal[v] - nogoal[v] < goal[w] - nogoal[w]) {
						rank[v]++;
					}
					else if (goal[v] - nogoal[v] == goal[w] - nogoal[w]) {
						if (a_goal[v] < a_goal[w]) {
							rank[v]++;
						}
					}
				}
			}
		}
		fprintf(output, "Test Case #%d:", i + 1);
		for (int p = 1; p < n + 1; p++) {
			//fprintf(output, "%d    %d %d %d %d %d %d %d\n", p, a_goal[p], a_nogoal[p], h_goal[p], h_nogoal[p], point[p], goal[p], nogoal[p]);
			fprintf(output, " %d", rank[p]);
		}
		fprintf(output, "\n");
	}
	
	fclose(input);
	fclose(output);
}
