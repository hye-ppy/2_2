#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int main() {
	FILE *input, *output;

	input = fopen("exam.inp", "rt");
	output = fopen("exam.out", "wt");

	int T, p;

	fscanf(input, "%d", &T);
	for (int x = 0; x < T; x++) {
		fprintf(output, "Test Case: #%d\n", x + 1);

		char g_code[26];
		char q_code[1000];
		
		fscanf(input, "%s", &g_code);
		fscanf(input, "%s", &q_code);
		
		fscanf(input, "%d", &p);
		for (int i = 0; i < p; i++) {
			char t_code[1000];
			int num;
			int plus=0;
			int result = 1;
			int check = 0;
			int q, g;
			fscanf(input, "%s", &t_code);
			num = strlen(t_code) - strlen(q_code) + 1;
			printf("%d\n", strlen(q_code));
			for (int j = 0; j<strlen(q_code); j++) {
				if(q_code[j]=='?'){
					for (int k = 0; k<strlen(g_code); k++) {
						if (t_code[j + plus] == g_code[k]) {
							result = 1;
							break;
						}
						else result = 0;
					}
				}
				else if (q_code[j] == '*') {
					if (num != 0) {
						plus = num - 1;
						for (int y = j; y < j+num; y++) {
							for (int k = 0; k<strlen(g_code); k++) {
								if (t_code[y] == g_code[k]) {
									check++;
								}
							}
						}
						if (check == num) result = 0;
					}
					else {
						result = 1;
						plus = -1;
					}
				}
				else {
					if (t_code[j + plus] == q_code[j]) result = 1;
					else result = 0;
				}
				if (result == 0) {
					fprintf(output, "No\n");
					break;
				}
			}
			if (result == 1) {
				fprintf(output, "Yes\n");
			}
		}
		
		
	}
}