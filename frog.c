#include<stdio.h>
#pragma warning (disable:4996)
int main() {
	FILE *input, *output;

	input = fopen("frog.inp", "rt");
	output = fopen("frog.out", "wt");

	int T, n, d, m;
	char s, t, h;
	char c_rock[200];
	int n_rock[200];

	fscanf(input, "%d", &T);
	for (int x = 0; x < T; x++) {
		int i, j = 0, w = 0, ex = 0;
		fscanf(input, "%d %d", &n, &d);
		c_rock[0] = 'A';
		n_rock[0] = 0;
		for (i = 1; i <= n; i++) {
			fscanf(input, "%c%c%c%d", &t, &s,&h, &m);
			c_rock[i] = s;
			n_rock[i] = m;
		}
		c_rock[n + 1] = 'E';
		n_rock[n + 1] = d;
		int p = 0;
		while (1) {
			if (w < n_rock[p] - ex) {
				w = n_rock[p] - ex;
			}
			ex = n_rock[p];
			if(c_rock[p]=='S') n_rock[p] = 0;
			if (c_rock[p] == 'S'&&c_rock[p + 1] == 'S') p++;
			if (c_rock[p] == 'E') {
				ex = d;
				break;
			}
			p++;
		}
		p--;
		while (1) {
			if (c_rock[p] == 'A') {
				if (w < ex - n_rock[p]) {
					w = ex - n_rock[p];
				}
				break;
			}
			if (c_rock[p] != 'A'&&n_rock[p] == 0) p--;
			else {
				if (w < ex - n_rock[p]) {
					w = ex - n_rock[p];
				}
				ex = n_rock[p];
				p--;
			}
		}
		fprintf(output, "Case %d: %d\n", x + 1, w);
	}

	fclose(input);
	fclose(output);
}