/*
https://www.acmicpc.net/problem/9184
BOJ 9184번 신나는 함수 실행

(1) 접근
재귀함수를 사용해서는 시간초과가 예상되는 문제였다.
문제의 조건에 맞도록 3차원 배열을 생성 후 다이나믹 프로그래밍으로 해결하였다.

(2) 해결
3차원 배열을 선언하였다. 문제 조건이 20보다 큰 수가 입력되는 경우 무조건 w(20,20,20)으로 계산하기 때문에 각 차원 별로 20씩 크기를 할당하면 된다.
문제 조건에 맞게 DP를 구하는 함수를 만들었고, for문을 이용하여 w(0, 0, 0) 부터 w(20, 20, 20)까지를 3차원 배열에 저장하였다. 
이제 입력받은 수에 맞는 배열의 값을 출력하면 해결된다.
*/
#include <iostream>
#include <cstdio>

using namespace std;

int w[21][21][21] = {0, };
int first, second, third;

int calculateDP(int a, int b, int c)
{
    int aa = (a - 1 > 0) ? a - 1 : 0;
    int bb = (b - 1 > 0) ? b - 1 : 0;
    int cc = (c - 1 > 0) ? c - 1 : 0;
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if(a < b && b < c)
        return w[a][b][cc] + w[a][bb][cc] - w[a][bb][c]; 
    else return w[aa][b][c] + w[aa][bb][c] + w[aa][b][cc] - w[aa][bb][cc];
}

void initDPSetting()
{
    for(int i = 1; i < 21; i++)
    {
        for(int j = 1; j < 21; j++)
        {
            for(int k = 1; k < 21; k++)
            {
                w[i][j][k] = calculateDP(i, j, k);
            }
        }
    }
}

int main()
{
    initDPSetting();
    while(true)
    {
        cin >> first >> second >> third;
        if(first == -1 && second == -1 && third == -1)
            break;
        else 
        { 
            printf("w(%d, %d, %d) = ", first, second, third);
            if(first <= 0 || second <= 0 || third <= 0)
                cout << w[0][0][0] << endl;
            else if(first > 20 || second > 20 || third > 20)
                cout << w[20][20][20] << endl;
            else cout << w[first][second][third] << endl;
        }
    }
}