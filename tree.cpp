#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#pragma warning (disable:4996)
int main() {
	FILE *input, *output;

	input = fopen("tree.inp", "rt");
	output = fopen("tree.out", "wt");

	int a, b;
	
	int w = 1;
	while (1) {
		int i = 0, king = 0, ex = 0, y_ex = 0;
		vector<int>s;
		vector<int>e;
		while (1) {
			fscanf(input, "%d %d", &a, &b);
			if (a == 0 && b == 0 || a == -1 && b == -1) break;
			else {
				s.push_back(a);
				e.push_back(b);
				i++;
			}
		}
		if (a == -1 && b == -1) break;

		sort(s.begin(), s.end());
		sort(e.begin(), e.end());

		/*for (int x = 0; x < i; x++) {
			fprintf(output, "%d ", s[x]);
		}
		fprintf(output, "\n");
		for (int x = 0; x < i; x++) {
			fprintf(output, "%d ", e[x]);
		}
		fprintf(output, "\n");*/

		i--;
		int x = 0, y = 0, check = 1;
		while (1) {
			if (y_ex == e[y]) {//중복 검사
				check = 0;
				break;
			}
			if (ex == s[x]) {//전이랑 같으면 점프
				if (x == i) break;
				x++;
			}
			else if (s[x] == e[y]) {
				if (x == i) break;
				ex = s[x];
				x++;
				if (y != i) {
					y_ex = e[y];
					y++;
				}
			}
			else if (s[x] < e[y]) {
				if (king == 0) {
					king = s[x];
					ex = s[x];
					if (x == i) break;
					x++;
				}
				else if (king != 0) {
					check = 0;
					break;
				}
			}
			else if (s[x] > e[y]) {
				if (y == i) {
					if (king == 0) {
						king = s[x];
						ex = s[x];
						if (x == i) break;
						x++;
					}
					else if (king != 0) {
						check = 0;
						break;
					}
				}
				else if (y != i) {
					y_ex = e[y];
					y++;
				}
				
			}
			//if (x > i || y > i) break;
		}
		
		if (y != i) {
			while (1) {
				
				if (y_ex == e[y]) {//중복 검사
					check = 0;
					break;
				}
				if (y == i) break;
				y_ex = e[y];
				y++;

			}
		}
		if (check == 0) {
			fprintf(output, "Test Case %d: -1\n", w);
			w++;
		}
		else {
			if (king == 0) {
			fprintf(output, "Test Case %d: -1\n", w);
			w++;
			}
			if (king != 0) {
				fprintf(output, "Test Case %d: %d\n", w, king);
				w++;
			}
		}

		
	}








	fclose(input);
	fclose(output);
}