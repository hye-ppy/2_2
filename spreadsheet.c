#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#pragma warning (disable:4996)
int main() {
	FILE *input, *output;

	input = fopen("spreadsheet.inp", "rt");
	output = fopen("spreadsheet.out", "wt");

	int T;
	char p[1000000];

	fscanf(input, "%d", &T);
	for (int x = 0; x < T; x++) {
		char numb[1000000] = { 0 }, eng[100] = { 0 };
		int num = 0;
		double sum = 0;
		int check = 0;
		fscanf(input, "%s", p);
		for (int i = 0; i < strlen(p)-1; i++) {
				if (p[i] >= '0' && p[i] <= '9') {
					if (p[i + 1] >= 'A' && p[i + 1] <= 'Z') {
						num++;
					}
				}
				else if (p[i] >= 'A' && p[i] <= 'Z') {
					if (p[i + 1] >= '0' && p[i + 1] <= '9') {
						num++;
					}
				}
		}
		if (num == 1) {
			//int check = 0;
			for (int i = 0; i < strlen(p); i++) {
				if (p[i] >= 'A' && p[i] <= 'Z') {
					eng[i] = p[i];
					check++;
				}
				else if (p[i] >= '0' && p[i] <= '9') {
					numb[i - check] = p[i];
				}
			}
			for (int i = 0; i < strlen(eng); i++) {
				double result = 0;
				if (strlen(eng) - 1 - i == 0) {
					result = eng[i] - 64;
					sum += result;				
				}
				else {
					result = pow(26, strlen(eng) - 1 - i)*(eng[i] - 64);
					sum += result;
				}
			}
			fprintf(output, "R%sC%.0f\n", numb, sum);
		}


		else {
			//int check = 0;
			int check2 = 2;
			for (int i = 0; i < strlen(p); i++) {
				if (p[i] == 'R') continue;
				else if (p[i] == 'C') {
					check++;
				}
				else if (check == 0) {
					numb[i - 1] = p[i];
					check2++;
				}
				else if (check == 1) {
					eng[i - check2] = p[i];
				}
			}
			//fprintf(output, "%s %s", eng, numb);
			int change;
			change = atoi(eng);
			char eng[1000000] = { 0 };
			int k = 0;
			while (change != 0) {
				if (change / 26 > 27) {
					if (change % 26 == 0) {
						eng[k] = (change % 26) + 26 + 64;
						change = (change / 26) - 1;
					}
					else {
						eng[k] = (change % 26) + 64;
						change /= 26;
					}
					k++;
				}
				else {
					if (change % 26 == 0) {
						eng[k] = (change % 26) + 26 + 64;
						change = (change / 26) - 1;
					}
					else {
						eng[k] = (change % 26) + 64;
						change /= 26;
					}
					k++;
				}
			}
			for (int i = strlen(eng) - 1; i > -1; i--) {
				fprintf(output, "%c", eng[i]);
			}
			fprintf(output, "%s\n", numb);
		}
	}
	fclose(input);
	fclose(output);
}