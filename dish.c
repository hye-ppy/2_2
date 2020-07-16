#include<stdio.h>
#pragma warning(disable:4996)
int main() {
	FILE *input_fp, *output_fp;

	input_fp = fopen("dish.inp", "rt");
	output_fp = fopen("dish.out", "wt");

	if ((input_fp = fopen("dish.inp", "rt")) == NULL) {
		fprintf(stderr, "can't open %s\n", "dish.inp");
	}

	if ((output_fp = fopen("dish.out", "wt")) == NULL) {
		fprintf(stderr, "can't open %s\n", "dish.out");
	}
	
	int T,N,result=0;
	char d,before;
	before = '/';

	fscanf(input_fp,"%d",&T);

	for (int i = 0; i < T; i++) {

		fscanf(input_fp, "%d", &N);
		if (N > 1000 && N < 3) break;

		fscanf(input_fp, "%c", &d);

		for (int j = 0; j < N; j++) {
			
			fscanf(input_fp, "%c", &d);
			if (before == d) {
				result += 5;
			}
			else if (before != d) {
				result += 10;
			}
			before = d;	
		}
		fprintf(output_fp, "%d", result);
		fprintf(output_fp, "\n");
		result = 0;
		before = '/';
		
	}
	
	fclose(input_fp);
	fclose(output_fp);

	return 0;

}