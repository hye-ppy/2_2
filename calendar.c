#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int change(int year, int month, int check, char yil[][4]);
int whatDay(int year1, int month1, int day1, int year2, int month2, int day2);
int main() {

	FILE*input, *output;

	input = fopen("calendar.inp", "rt");
	output = fopen("calendar.out", "wt");

	int monthsum[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int year1 = 0, month1 = 0, day1 = 0, check1 = 0;
	int year2 = 0, month2 = 0, day2 = 0, check2 = 0;
	char yo[7][4] = { "Sun","Mon","Tue","Wed","Tue","Fri","Sat" };
	char yil1[1][4], yil2[1][4];

	int type;
	char t, r, a, s, h, hh;


	while (1) {
		int result;
		fscanf(input, "%d", &type);
		if (type == -1) break;
		if (type == 0) {
			fscanf(input, "%d%c%d%c%d %d%c%d%c%d", &year1, &t, &month1, &r, &day1, &year2, &a, &month2, &s, &day2);
			result = whatDay(year1, month1, day1, year2, month2, day2);
			fprintf(output, "%d\n", result);
		}
		if (type == 1) {
			fscanf(input, "%d%c%d%c%d %d%c%d%c%d%c%s", &year1, &t, &month1, &r, &day1, &year2, &a, &month2, &s, &check2, &h, &yil2);
			int day2;
			day2 = change(year2, month2, check2, yil2);
			if (day2 == -1) {
				fprintf(output, "-1\n");
			}
			else {
				result = whatDay(year1, month1, day1, year2, month2, day2);
				fprintf(output, "%d\n", result);
			}

		}
		if (type == 2) {
			fscanf(input, "%d%c%d%c%d%c%s %d%c%d%c%d", &year1, &t, &month1, &r, &check1, &a, &yil1, &year2, &s, &month2, &h, &day2);
			int day1;
			day1 = change(year1, month1, check1, yil1);
			if (day1 == -1) {
				fprintf(output, "-1\n");
			}
			else {
				result = whatDay(year1, month1, day1, year2, month2, day2);
				fprintf(output, "%d\n", result);
			}
		}
		if (type == 3) {
			fscanf(input, "%d%c%d%c%d%c%s %d%c%d%c%d%c%s", &year1, &t, &month1, &r, &check1, &a, &yil1, &year2, &h, &month2, &s, &check2, &hh, &yil2);
			int day1, day2;
			day1 = change(year1, month1, check1, yil1);
			day2 = change(year2, month2, check2, yil2);
			if (day1 == -1 || day2 == -1) {
				fprintf(output, "-1\n");
			}
			else {
				result = whatDay(year1, month1, day1, year2, month2, day2);
				fprintf(output, "%d\n", result);
			}
		}

	}

	fclose(input);
	fclose(output);
}
int whatDay(int year1, int month1, int day1, int year2, int month2, int day2) {
	int monthsum[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int monthsum1[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int monthsum2[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int Sum = 0;
	int Sum1 = 0, sum1 = 0;
	int Sum2 = 0, sum2 = 0;
	int result = 0;
	monthsum1[2] = 28;
	monthsum2[2] = 28;
	if ((year1 % 4 == 0 && (year1 % 100 != 0)) || (year1 % 400 == 0)) {
		monthsum1[2] = 29;
	}
	if ((year2 % 4 == 0 && (year2 % 100 != 0)) || (year2 % 400 == 0)) {
		monthsum2[2] = 29;
	}
	if (monthsum1[month1] < day1 || monthsum2[month2] < day2) {
		return -1;
	}
	else {
		for (int i = 1; i < 13; i++) {
			Sum1 += monthsum1[i];
		}
		for (int i = 1; i < month1; i++) {
			sum1 += monthsum1[i];
		}
		for (int i = 1; i < 13; i++) {
			Sum2 += monthsum2[i];
		}
		for (int i = 1; i < month2; i++) {
			sum2 += monthsum2[i];
		}
		sum1 += day1;
		sum2 += day2;
		if (year1 < year2) {
			for (int i = year1 + 1; i < year2; i++) {
				monthsum[2] = 28;
				if ((i % 4 == 0 && (i % 100 != 0)) || (i % 400 == 0)) {
					monthsum[2] = 29;
				}
				for (int j = 1; j < 13; j++) {
					Sum += monthsum[j];
				}
			}
			result = Sum1 - sum1 + sum2 + Sum;
			return result;
		}
		else if (year1 == year2) {
			if (month1 < month2) {
				result = sum2 - sum1;
				return result;
			}
			else if (month1 == month2) {
				if (day1 < day2) {
					result = day2 - day1;
					return result;
				}
				else if (day1 > day2) {
					result = day1 - day2;
					return result;
				}
				else if (day1 == day2) {
					return 0;
				}
			}
			else if (month1 > month2) {
				result = sum1 - sum2;
				return result;
			}
		}
		else if (year1 > year2) {
			for (int i = year2 + 1; i < year1; i++) {
				monthsum[2] = 28;
				if ((i % 4 == 0 && (i % 100 != 0)) || (i % 400 == 0)) {
					monthsum[2] = 29;
				}
				for (int j = 1; j < 13; j++) {
					Sum += monthsum[j];
				}
			}
			result = Sum2 - sum2 + sum1 + Sum;
			return result;
		}
	}
}
int change(int year, int month, int check, char yil[][4]) {
	int monthsum[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	char yo[7][4] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	int one = 1, sum = 1;
	int yoyil, day, sub = 0;

	monthsum[2] = 28;

	for (int i = 0; i < 7; i++) {
		if (yo[i][0] == yil[0][0] && yo[i][1] == yil[0][1]) {
			yoyil = i;
		}
	}
	if ((year % 4 == 0 && (year % 100 != 0)) || (year % 400 == 0)) {
		monthsum[2] = 29;
	}
	sum += (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	for (int i = 0; i < month; i++) {
		sum += monthsum[i];
	}
	one = sum % 7;

	for (int i = 0; i < one; i++) {
		sub++;
	}
	if (sub > yoyil) {
		check++;
	}
	day = ((check - 1) * 7) - sub + (yoyil + 1);
	if (day > monthsum[month]) {
		day = -1;
		return day;
	}
	else {
		return day;
	}
}