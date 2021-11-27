#pragma once

#define Clean system("cls");

inline extern void OutPut(int mp[5][5] , int& score);

void extern Up(int(*mp)[5]);

void extern Down(int(*mp)[5]);

void extern Left(int(*mp)[5]);

void extern Right(int(*mp)[5]);

bool extern Run(char op , int(*mp)[5]);