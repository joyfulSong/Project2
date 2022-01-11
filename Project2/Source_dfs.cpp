// 2331.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int cnt[1000000];

// DFS로 방문해서 이전에 생성된 값 있으면 리턴하기
void DFS(int A, int P)
{
    int sum = 0;
    while (A)
    {
        sum = sum + pow(A % 10, P); // 각 자리수 제곱해서 더하기
        A = A / 10;
    }
    if (cnt[sum] < 2)
    {
        cnt[sum]++;
        DFS(sum, P);
    }
}

int main()
{
    int A = 0;
    int P = 0;
    int result = 0;

    cin >> A >> P;

    cnt[A]++;

    // 예외처리
    if (P < 1 || P > 5 || A < 1 || A > 9999)
    {
        cout << "잘못된 입력값입니다." << endl;
        return -1;
    }

    DFS(A, P);

    for (int i = 0; i < 1000000; i++)
    {
        if (cnt[i] == 1)
        {
            result++; // 최종 유니크한 방문지만 체크
        }
    }

    printf("%d\n", result);

    return 0;
}