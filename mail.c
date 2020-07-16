#include<stdio.h>
#pragma warning (disable:4996)
void AA(int com[], FILE*output);
void BB(int com[], FILE*output);
void CC(int com[], FILE*output);
void DD(int com[], FILE*output);
void EE(int com[], FILE*output);
void FF(int com[], FILE*output);
void GG(int com[], FILE*output);
void HH(int com[], FILE*output);

int main() {
	FILE *input, *output;
	input = fopen("mail.inp", "rt");
	output = fopen("mail.out", "wt");

	int T, N, com[6];

	fscanf(input, "%d", &T);
	for (int x = 0; x < T; x++) {
		fscanf(input, "%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 6; j++) {
				fscanf(input, "%1d", &com[j]);
				//fprintf(output, "%d\n", com[i]);
			}
			AA(com, output);
		}
		fprintf(output, "\n");
	}


	fclose(input);
	fclose(output);
}
void AA(int com[], FILE*output) {
	int A[6] = { 0,0,0,0,0,0 };
	int yes = 0, no = 0;
	for (int i = 0; i < 6; i++) {
		//fprintf(output, "%d %d\n", A[i], com[i]);
		if (A[i] == com[i]) {
			yes++;
		}
		else {
			no++;
		}
	}
	if (yes == 5 || yes == 6) {
		fprintf(output, "A");
	}
	else {
		BB(com, output);
	}
}
void BB(int com[], FILE*output) {
	int B[6] = { 0,0,1,1,1,1 };
	int yes = 0, no = 0;
	for (int i = 0; i < 6; i++) {
		if (B[i] == com[i]) {
			yes++;
		}
		else {
			no++;
		}
	}
	if (yes == 5 || yes == 6) {
		fprintf(output, "B");
	}
	else {
		CC(com, output);
	}
}
void CC(int com[], FILE*output) {
	int C[6] = { 0,1,0,0,1,1 };
	int yes = 0, no = 0;
	for (int i = 0; i < 6; i++) {
		if (C[i] == com[i]) {
			yes++;
		}
		else {
			no++;
		}
	}
	if (yes == 5 || yes == 6) {
		fprintf(output, "C");
	}
	else {
		DD(com, output);
	}
}
void DD(int com[], FILE*output) {
	int D[6] = { 0,1,1,1,0,0 };
	int yes = 0, no = 0;
	for (int i = 0; i < 6; i++) {
		if (D[i] == com[i]) {
			yes++;
		}
		else {
			no++;
		}
	}
	if (yes == 5 || yes == 6) {
		fprintf(output, "D");
	}
	else {
		EE(com, output);
	}
}
void EE(int com[], FILE*output) {
	int E[6] = { 1,0,0,1,1,0 };
	int yes = 0, no = 0;
	for (int i = 0; i < 6; i++) {
		if (E[i] == com[i]) {
			yes++;
		}
		else {
			no++;
		}
	}
	if (yes == 5 || yes == 6) {
		fprintf(output, "E");
	}
	else {
		FF(com, output);
	}
}
void FF(int com[], FILE*output) {
	int F[6] = { 1,0,1,0,0,1 };
	int yes = 0, no = 0;
	for (int i = 0; i < 6; i++) {
		if (F[i] == com[i]) {
			yes++;
		}
		else {
			no++;
		}
	}
	if (yes == 5 || yes == 6) {
		fprintf(output, "F");
	}
	else {
		GG(com, output);
	}
}
void GG(int com[], FILE*output) {
	int G[6] = { 1,1,0,1,0,1 };
	int yes = 0, no = 0;
	for (int i = 0; i < 6; i++) {
		if (G[i] == com[i]) {
			yes++;
		}
		else {
			no++;
		}
	}
	if (yes == 5 || yes == 6) {
		fprintf(output, "G");
	}
	else {
		HH(com, output);
	}
}
void HH(int com[], FILE*output) {
	int H[6] = { 1,1,1,0,1,0 };
	int yes = 0, no = 0;
	for (int i = 0; i < 6; i++) {
		if (H[i] == com[i]) {
			yes++;
		}
		else {
			no++;
		}
	}
	if (yes == 5 || yes == 6) {
		fprintf(output, "H");
	}
	else {
		fprintf(output, "X");
	}
}