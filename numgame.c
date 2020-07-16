#include<stdio.h>
#pragma warning (disable:4996)
int main() {
	FILE *input, *output;

	input = fopen("numgame.inp", "rt");
	output = fopen("numgame.out", "wt");

	int T, k, com, st, ba;

	fscanf(input, "%d", &T);
	for (int x = 0; x < T; x++) {
		int new_arr[3024];
		int arr[3024];
		int num = 1234;
		for (int i = 0;;) {
			if (num / 1000 != 0 && (num % 1000) / 100 != 0 && ((num % 1000) % 100) / 10 != 0 && (((num % 1000) % 100) % 10) != 0 && num / 1000 != (num % 1000) / 100 && num / 1000 != ((num % 1000) % 100) / 10 && num / 1000 != (((num % 1000) % 100) % 10) && (num % 1000) / 100 != ((num % 1000) % 100) / 10 && (num % 1000) / 100 != (((num % 1000) % 100) % 10) && ((num % 1000) % 100) / 10 != (((num % 1000) % 100) % 10)) {
				arr[i] = num;
				if (num == 9876) break;
				i++;
			}
			num++;
		}
		int count_arr[3024] = { 0 };
		int count = 0;
		fscanf(input, "%d", &k);
		for (int i = 0; i < k; i++) {			
			fscanf(input, "%d %d %d", &com, &st, &ba);
			int a[4];
			int b[4];
			a[0] = com / 1000;
			a[1] = (com % 1000) / 100;
			a[2] = ((com % 1000) % 100) / 10;
			a[3] = (((com % 1000) % 100) % 10);
			for (int j = 0; j < 3024; j++) {
				int new_st = 0, new_ba = 0;
				b[0] = arr[j] / 1000;
				b[1] = (arr[j] % 1000) / 100;
				b[2] = ((arr[j] % 1000) % 100) / 10;
				b[3] = (((arr[j] % 1000) % 100) % 10);

				for(int k=0;k<4;k++)
					for (int z = 0; z < 4; z++)
					{
						if (a[k] == b[z])
						{
							if (k == z) new_st++;
							else new_ba++;
						}
					}
				/*for (int k = 0; k < 4; k++) {					
					if (a[k] == b[k]) {
						new_st++;
						printf("%d %d %d ", arr[j], com, new_st);
					}
				}
				for (int y = 0; y < 4; y++) {
					for (int z = 0; z < 4; z++) {
						if (a[y] == b[z]) {
							new_ba++;
						}
					}
				}*/
				if (st == new_st && ba == new_ba) {
					count_arr[j] += 1;
				}
			}			
		}
		
		for (int i = 0; i < 3024; i++) {
			if (count_arr[i] == k) {
				new_arr[count] = arr[i];
				count++;
			}
		}
		if (count < 7) {
			fprintf(output, "%d\n", count);
			for (int i = 0; i < count; i++) {
				fprintf(output, "%d\n", new_arr[i]);
			}
		}
		else {
			fprintf(output, "%d\n", count);
			for (int i = 0; i < 3; i++) {
				fprintf(output, "%d\n", new_arr[i]);
			}
			for (int i = count - 3; i < count ; i++) {
				fprintf(output, "%d\n", new_arr[i]);
			}
		}
	}








}