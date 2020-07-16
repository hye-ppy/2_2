#include<stdio.h>
#pragma warning (disable:4996)
int x, y;
void east(int dice[]);
void west(int dice[]);
void north(int dice[]);
void south(int dice[]);
int main() {
	FILE *input, *output;

	input = fopen("die.inp", "rt");
	output = fopen("die.out", "wt");

	int T, n, a, b, c, d, e, f;
	int dice[6];
	char star;
	int top, front;

	fscanf(input, "%d", &T);
	for (int i = 0; i < T; i++) {
		x = 0, y = 0;
		fscanf(input, "%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &top, &front);
		if (top == a && front == b) {
			dice[0] = top;
			dice[1] = d;
			dice[2] = c;
			dice[3] = f;
			dice[4] = front;
			dice[5] = e;
		}
		else if (top == a && front == f) {
			dice[0] = top;
			dice[1] = b;
			dice[2] = c;
			dice[3] = e;
			dice[4] = front;
			dice[5] = d;
		}
		else if (top == a && front == d) {
			dice[0] = top;
			dice[1] = e;
			dice[2] = c;
			dice[3] = b;
			dice[4] = front;
			dice[5] = f;
		}
		else if (top == a && front == e) {
			dice[0] = top;
			dice[1] = f;
			dice[2] = c;
			dice[3] = d;
			dice[4] = front;
			dice[5] = b;
		}
		else if (top == b && front == f) {
			dice[0] = top;
			dice[1] = c;
			dice[2] = e;
			dice[3] = a;
			dice[4] = front;
			dice[5] = d;
		}
		else if (top == b && front == a) {
			dice[0] = top;
			dice[1] = f;
			dice[2] = e;
			dice[3] = d;
			dice[4] = front;
			dice[5] = c;
		}
		else if (top == b && front == c) {
			dice[0] = top;
			dice[1] = d;
			dice[2] = e;
			dice[3] = f;
			dice[4] = front;
			dice[5] = a;
		}
		else if (top == b && front == d) {
			dice[0] = top;
			dice[1] = a;
			dice[2] = e;
			dice[3] = c;
			dice[4] = front;
			dice[5] = f;
		}
		else if (top == c && front == e) {
			dice[0] = top;
			dice[1] = d;
			dice[2] = a;
			dice[3] = f;
			dice[4] = front;
			dice[5] = b;
		}
		else if (top == c && front == d) {
			dice[0] = top;
			dice[1] = b;
			dice[2] = a;
			dice[3] = e;
			dice[4] = front;
			dice[5] = f;
		}
		else if (top == c && front == b) {
			dice[0] = top;
			dice[1] = f;
			dice[2] = a;
			dice[3] = d;
			dice[4] = front;
			dice[5] = e;
		}
		else if (top == c && front == f) {
			dice[0] = top;
			dice[1] = e;
			dice[2] = a;
			dice[3] = b;
			dice[4] = front;
			dice[5] = d;
		}
		else if (top == d && front == e) {
			dice[0] = top;
			dice[1] = a;
			dice[2] = f;
			dice[3] = c;
			dice[4] = front;
			dice[5] = b;
		}
		else if (top == d && front == a) {
			dice[0] = top;
			dice[1] = b;
			dice[2] = f;
			dice[3] = e;
			dice[4] = front;
			dice[5] = c;
		}
		else if (top == d && front == b) {
			dice[0] = top;
			dice[1] = c;
			dice[2] = f;
			dice[3] = a;
			dice[4] = front;
			dice[5] = e;
		}
		else if (top == d && front == c) {
			dice[0] = top;
			dice[1] = e;
			dice[2] = f;
			dice[3] = b;
			dice[4] = front;
			dice[5] = a;
		}
		else if (top == e && front == d) {
			dice[0] = top;
			dice[1] = c;
			dice[2] = b;
			dice[3] = a;
			dice[4] = front;
			dice[5] = f;
		}
		else if (top == e && front == c) {
			dice[0] = top;
			dice[1] = f;
			dice[2] = b;
			dice[3] = d;
			dice[4] = front;
			dice[5] = a;
		}
		else if (top == e && front == f) {
			dice[0] = top;
			dice[1] = a;
			dice[2] = b;
			dice[3] = c;
			dice[4] = front;
			dice[5] = d;
		}
		else if (top == e && front == a) {
			dice[0] = top;
			dice[1] = d;
			dice[2] = b;
			dice[3] = f;
			dice[4] = front;
			dice[5] = c;
		}
		else if (top == f && front == b) {
			dice[0] = top;
			dice[1] = a;
			dice[2] = d;
			dice[3] = c;
			dice[4] = front;
			dice[5] = e;
		}
		else if (top == f && front == a) {
			dice[0] = top;
			dice[1] = e;
			dice[2] = d;
			dice[3] = b;
			dice[4] = front;
			dice[5] = c;
		}
		else if (top == f && front == e) {
			dice[0] = top;
			dice[1] = c;
			dice[2] = d;
			dice[3] = a;
			dice[4] = front;
			dice[5] = b;
		}
		else if (top == f && front == c) {
			dice[0] = top;
			dice[1] = b;
			dice[2] = d;
			dice[3] = e;
			dice[4] = front;
			dice[5] = a;
		}
		fscanf(input, "%d ", &n);
		for (int j = 0; j < n; j++) {
			fscanf(input, "%c", &star);
			if (star == 'E') {
				east(dice);
			}
			else if (star == 'W') {
				west(dice);
			}
			else if (star == 'N') {
				north(dice);
			}
			else if (star == 'S') {
				south(dice);
			}
		}
		fprintf(output, "%d %d %d %d\n", x, y, dice[0], dice[4]);
	
	
	}





	fclose(input);
	fclose(output);
}
void east(int dice[]) {
	int temp;
	temp = dice[3];
	dice[3] = dice[2];
	dice[2] = dice[1];
	dice[1] = dice[0];
	dice[0] = temp;
	x++;
}
void west(int dice[]) {
	int temp;
	temp = dice[0];
	dice[0] = dice[1];
	dice[1] = dice[2];
	dice[2] = dice[3];
	dice[3] = temp;
	x--;
}
void north(int dice[]) {
	int temp1, temp2;
	temp1 = dice[4];
	temp2 = dice[5];	
	dice[4] = dice[2];
	dice[5] = dice[0];
	dice[0] = temp1;
	dice[2] = temp2;
	y++;
}
void south(int dice[]) {
	int temp1, temp2;
	temp1 = dice[4];
	temp2 = dice[5];
	dice[4] = dice[0];
	dice[5] = dice[2];
	dice[0] = temp2;
	dice[2] = temp1;
	y--;
}