#include "GameStream.h"
#include <cstdio>
#include <algorithm>
#include <deque>

inline extern void OutPut(int mp[5][5] , int& score) {
    printf("Score = %d\n", score); //分数即为最大的方块
    for (int j = 1; j <= 4; ++j) //输出上边框
        printf("------");
    printf("\n");
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            printf("|");
            if (mp[i][j]) { //如果元素不为0.输出，更新 score
                if (score < mp[i][j])
                    score = mp[i][j];
                printf("%5d" ,mp[i][j]);
            }
            else //元素为 0 空格填充
                printf("     ");

        }
        printf("|\n"); //元素与元素之间用 | 分隔
        for (int j = 1; j <= 4; ++j) //输出下边界
            printf("------");
        printf("\n");
    }
    printf("w : up  s : down  a : left  d : right\n"); //提示性语句
    // printf("push 'r' to start a new game\n");
    printf("push 'e' to exit game\n");
}

void extern Up(int (*mp)[5]) {
    std::deque<int> Num;
    for (int i = 1; i <= 4; i++) { //1 ~ 4 列
        Num.clear(); //清空
        for (int j = 1; j <= 4; j++) { //寻找该列非 0 项 
            if (mp[j][i] == 0) continue;
            Num.push_back(mp[j][i]);
            mp[j][i] = 0;
        }
        if (Num.empty()) continue; //空列
        int Head, Tail;
        while (true) {
            Head = Num.front();
            Num.pop_front();
            Num.push_back(Head); //将该列第一个元素加入队尾
            int Size = Num.size();
            for (int i = 2; i <= Size; i++) { //循环队列
                Tail = Num.back(); //取出队尾
                Head = Num.front(); //取出队头
                Num.pop_front();
                //此时的队头与队列尾是两个相邻的元素
                if (Head == Tail) { //合并
                    Num.pop_back();
                    Num.push_back(Tail + Head);
                }
                else { //无法合并
                    Num.push_back(Head);
                }
            }
            if (Size == Num.size()) break; //元素数量没有变化，退出
        }
        for (int j = 0; j < Num.size(); j++) { //update
            mp[j + 1][i] = Num[j];
        }
    }
}

void extern Down(int(*mp)[5]) {
    std::deque<int> Num;
    for (int i = 1; i <= 4; i++) {
        Num.clear();
        for (int j = 4; j >= 1; j--) {
            if (mp[j][i] == 0) continue;
            Num.push_back(mp[j][i]);
            mp[j][i] = 0;
        }
        if (Num.empty()) continue;
        int Head, Tail;
        while (true) {
            Head = Num.front();
            Num.pop_front();
            Num.push_back(Head);
            int Size = Num.size();
            for (int i = 2; i <= Size; i++) {
                Tail = Num.back();
                Head = Num.front();
                Num.pop_front();
                if (Head == Tail) {
                    Num.pop_back();
                    Num.push_back(Tail + Head);
                }
                else {
                    Num.push_back(Head);
                }
            }
            if (Size == Num.size()) break;
        }
        for (int j = 0, pos = 4; j < Num.size(); j++, pos--) {
            mp[pos][i] = Num[j];
        }
    }
}

void extern Left(int(*mp)[5]) {
    std::deque<int> Num;
    for (int i = 1; i <= 4; i++) { 
        Num.clear();
        for (int j = 1; j <= 4; j++) {
            if (mp[i][j] == 0) continue;
            Num.push_back(mp[i][j]);
            mp[i][j] = 0;
        }
        if (Num.empty()) continue;
        int Head, Tail;
        while (true) {
            Head = Num.front();
            Num.pop_front();
            Num.push_back(Head);
            int Size = Num.size();
            for (int i = 2; i <= Size; i++) {
                Tail = Num.back(); 
                Head = Num.front(); 
                Num.pop_front();
                if (Head == Tail) { 
                    Num.pop_back();
                    Num.push_back(Tail + Head);
                }
                else {
                    Num.push_back(Head);
                }
            }
            if (Size == Num.size()) break; 
        }
        for (int j = 0; j < Num.size(); j++) { 
            mp[i][j + 1] = Num[j];
        }
    }
}

void extern Right(int(*mp)[5]) {
    std::deque<int> Num;
    for (int i = 1; i <= 4; i++) {
        Num.clear();
        for (int j = 4; j >= 1; j--) {
            if (mp[i][j] == 0) continue;
            Num.push_back(mp[i][j]);
            mp[i][j] = 0;
        }
        if (Num.empty()) continue;
        int Head, Tail;
        while (true) {
            Head = Num.front();
            Num.pop_front();
            Num.push_back(Head);
            int Size = Num.size();
            for (int i = 2; i <= Size; i++) {
                Tail = Num.back();
                Head = Num.front();
                Num.pop_front();
                if (Head == Tail) {
                    Num.pop_back();
                    Num.push_back(Tail + Head);
                }
                else {
                    Num.push_back(Head);
                }
            }
            if (Size == Num.size()) break;
        }
        for (int j = 0, pos = 4; j < Num.size(); j++, pos--) {
            mp[i][pos] = Num[j];
        }
    }
}


bool extern Run(char op , int(*mp)[5]) {
    switch (op) { //检测，操作
    case 'w': //上
        Up(mp);
        return true;
        break;
    case 's': //下
        Down(mp);
        return true;
        break;
    case 'a': //左
        Left(mp);
        return true;
        break;
    case 'd': //右
        Right(mp);
        return true;
        break;
    default:
        printf("Please try again!\n");
        return false;
        break;
    }
}
