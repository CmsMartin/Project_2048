#include <iostream>
#include <cstdio>
#include <conio.h>
#include "GameStream.h"
#include <Windows.h>
using namespace std;

int Map[5][5] , score;

int Last[5][5];

int Num[] = { 2 , 4 , 8 , 16 , 32 , 64 , 128 , 256 , 512 , 1024 , 2048 };

void Init() {
	srand(unsigned(time(NULL)));
	Map[rand() % 4 + 1][rand() % 4 + 1] = 2;
}

void Update(int score) {
	int x = rand() % 4 + 1, y = rand() % 4 + 1;
	while (true) {
		if (Map[x][y] == 0) break;
		else x = rand() % 4 + 1, y = rand() % 4 + 1;
	}
	int set = 0;
	if (score == 2 || score == 4 || score == 8) set = 0;
	else if (score == 16 || score == 32) set = rand() % 2;
	else if (score == 64 || score == 128) set = rand() % 3;
	else if (score == 256 || score == 512) set = rand() % 4;
	else if (score == 1024 || score == 2048) set = rand() % 5;
	Map[x][y] = Num[set];
}

bool Lose(int(*mp)[5]) {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j < 4; j++) {
			if (mp[i][j + 1] == mp[i][j]) return false;
		}
	}
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j < 4; j++) {
			if (mp[j][i] == mp[j + 1][i]) return false;
		}
	}
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (mp[i][j] == 0) return false;
		}
	}
	return true;
}

bool Cmp(int(*mp)[5]) {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (mp[i][j] != Map[i][j]) return false;
		}
	}
	return true;
}

int main() {
	srand(time(0));
	Init();
	while (true) {
		Clean;
		OutPut(Map , score);
		if (score == 2048) { //胜利
			Clean;
			OutPut(Map, score);
			printf("You Win!\n");
			break;
		}
		if (Lose(Map) == true) { //失败
			Clean;
			OutPut(Map, score);
			printf("You Lose\n");
			break;
		}
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				Last[i][j] = Map[i][j];
			}
		}
		Again:
		char op = _getch();
		if (op == 'e') break;
		while (Run(op , Map) == false) { //处理不是 w ， a ， s ， d ， e 的异常字符
			op = _getch();
			if (op == 'e') break;
		}
		if (Cmp(Last)) {
			printf("This operation is meaningless!\nPlease try again!\n");
			goto Again;
		}
		Update(score);
	}
	Sleep(1);
	system("pause");
	return 0;
}