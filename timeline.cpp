#include<stdio.h>
#include<iostream>
#pragma warning (disable:4996)
using namespace std;
#include<vector>
#include<algorithm>
int main() {
	FILE *input, *output;

	input = fopen("timeline.inp", "rt");
	output = fopen("timeline.out", "wt");

	int T, n;
	int x = 0, y = 0;
	int ye, ar, mon, th, d, ay;
	char t, r, a, s, h;
	int temp1, temp2;
	
	fscanf(input, "%d", &T);
	while (x != T) {
		y = 0;
		fscanf(input, "%d", &n);
		vector<vector<int> > arr(n);
		while (y != n) {
			fscanf(input, "%d%c%d%c%d%c%d%c%d%c%d", &ye, &t, &mon, &r, &d, &a, &ar, &s, &th, &h, &ay);
			temp1 = ye * 10000 + mon * 100 + d;
			temp2 = ar * 10000 + th * 100 + ay;
			arr[y].push_back(temp1);
			arr[y].push_back(temp2);
			y++;
		}
		sort(arr.begin(), arr.end());


		//이제 행개수 찾기~ count;
		int count = 0;
		vector<int> line(100000);
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				line[count]=arr[0][1];
			}
			else {
				for (int j = 0; j <= count; j++) {
					if (line[j] <= arr[i][0]) {
						line[j] = arr[i][1];
						break;
					}
					else if (j == count && line[j] >= arr[i][0]) {
						count++;
						line[count]=arr[i][1];
						break;
					}
					
				}
			}
		}
		fprintf(output, "%d\n", count + 1);
		x++;
	}
	
	fclose(input);
	fclose(output);

}