#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#pragma warning (disable:4996)
int main() {
	FILE *input, *output;

	input = fopen("cycle.inp", "rt");
	output = fopen("cycle.out", "wt");

	int T, n, m, a, b;
	
	fscanf(input, "%d", &T);
	for (int x = 0; x < T; x++) {
		fscanf(input, "%d %d", &n, &m);
		//int visit[1000000] = { 0 }, num[1000000] = { 0 }, stack[100000], top = 0;
		int check = 0;
		vector<bool>visit(n);//true false 확인 
		vector<int>com(n);//구별 1,2
		vector<vector<int> > d(n);
		//vector<int>d[100000];
		queue<int> q;//큐
		for (int i = 0; i < m; i++) {
			fscanf(input, "%d %d", &a, &b);
			d[a].push_back(b);
			d[b].push_back(a);
		}
		int key = 0;//시작
		visit[key] = true;
		com[key] = 1;
		q.push(key);
		while (!q.empty()) {
			key = q.front();
			q.pop();
			for (int i = 0; i < d[key].size(); i++) {
				if (visit[d[key][i]]==false) {//no search
					if (com[key] == 1) {//draw
						com[d[key][i]] = 2;
					}
					else {
						com[d[key][i]] = 1;
					}
					visit[d[key][i]] = true;//search
					q.push(d[key][i]);//q insert
				}
				else {
					if (com[key] == com[d[key][i]]) {
						check = 1;
						break;
					}
				}
			}
		}

		if (check == 1) {
			fprintf(output, "O\n");
		}
		else {
			fprintf(output, "X\n");
		}




	}
	fclose(input);
	fclose(output);
}
