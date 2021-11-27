#include "GameStream.h"
#include <cstdio>
#include <algorithm>
#include <deque>

inline extern void OutPut(int mp[5][5] , int& score) {
    printf("Score = %d\n", score); //������Ϊ���ķ���
    for (int j = 1; j <= 4; ++j) //����ϱ߿�
        printf("------");
    printf("\n");
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            printf("|");
            if (mp[i][j]) { //���Ԫ�ز�Ϊ0.��������� score
                if (score < mp[i][j])
                    score = mp[i][j];
                printf("%5d" ,mp[i][j]);
            }
            else //Ԫ��Ϊ 0 �ո����
                printf("     ");

        }
        printf("|\n"); //Ԫ����Ԫ��֮���� | �ָ�
        for (int j = 1; j <= 4; ++j) //����±߽�
            printf("------");
        printf("\n");
    }
    printf("w : up  s : down  a : left  d : right\n"); //��ʾ�����
    // printf("push 'r' to start a new game\n");
    printf("push 'e' to exit game\n");
}

void extern Up(int (*mp)[5]) {
    std::deque<int> Num;
    for (int i = 1; i <= 4; i++) { //1 ~ 4 ��
        Num.clear(); //���
        for (int j = 1; j <= 4; j++) { //Ѱ�Ҹ��з� 0 �� 
            if (mp[j][i] == 0) continue;
            Num.push_back(mp[j][i]);
            mp[j][i] = 0;
        }
        if (Num.empty()) continue; //����
        int Head, Tail;
        while (true) {
            Head = Num.front();
            Num.pop_front();
            Num.push_back(Head); //�����е�һ��Ԫ�ؼ����β
            int Size = Num.size();
            for (int i = 2; i <= Size; i++) { //ѭ������
                Tail = Num.back(); //ȡ����β
                Head = Num.front(); //ȡ����ͷ
                Num.pop_front();
                //��ʱ�Ķ�ͷ�����β���������ڵ�Ԫ��
                if (Head == Tail) { //�ϲ�
                    Num.pop_back();
                    Num.push_back(Tail + Head);
                }
                else { //�޷��ϲ�
                    Num.push_back(Head);
                }
            }
            if (Size == Num.size()) break; //Ԫ������û�б仯���˳�
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
    for (int i = 1; i <= 4; i++) { //1 ~ 4 ��
        Num.clear(); //���
        for (int j = 1; j <= 4; j++) { //Ѱ�Ҹ��з� 0 �� 
            if (mp[i][j] == 0) continue;
            Num.push_back(mp[i][j]);
            mp[i][j] = 0;
        }
        if (Num.empty()) continue; //����
        int Head, Tail;
        while (true) {
            Head = Num.front();
            Num.pop_front();
            Num.push_back(Head); //�����е�һ��Ԫ�ؼ����β
            int Size = Num.size();
            for (int i = 2; i <= Size; i++) { //ѭ������
                Tail = Num.back(); //ȡ����β
                Head = Num.front(); //ȡ����ͷ
                Num.pop_front();
                //��ʱ�Ķ�ͷ�����β���������ڵ�Ԫ��
                if (Head == Tail) { //�ϲ�
                    Num.pop_back();
                    Num.push_back(Tail + Head);
                }
                else { //�޷��ϲ�
                    Num.push_back(Head);
                }
            }
            if (Size == Num.size()) break; //Ԫ������û�б仯���˳�
        }
        for (int j = 0; j < Num.size(); j++) { //update
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
    switch (op) { //��⣬����
    case 'w': //��
        Up(mp);
        return true;
        break;
    case 's': //��
        Down(mp);
        return true;
        break;
    case 'a': //��
        Left(mp);
        return true;
        break;
    case 'd': //��
        Right(mp);
        return true;
        break;
    default:
        printf("Please try again!\n");
        return false;
        break;
    }
}