/*
https://www.acmicpc.net/problem/2740
BOJ 2740번 행렬곱
(1) 접근 
행렬을 곱하는 문제이다. 
행렬을 곱하는 방법을 그대로 구현하면 된다.
(2) 해결
N * M 행렬과 M * K 행렬을 서로 곱하면 N * K의 행렬이 된다.
그러므로 행렬의 인덱스를 반복문을 이용하여 행렬 곱셈식 방법대로 각 행과 열의 곱셈결과를 더해주면
행렬의 곱셈을 완료할 수 있다.
*/
#include <iostream>

using namespace std;

int N, M, K;
int A[100][100];
int B[100][100];
int ANS[100][100];
int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }
    cin >> M >> K;
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < K; j++)
        {
            cin >> B[i][j];
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < K; j++)
        {
            for(int k = 0; k < M; k++)
            {
                ANS[i][j] += A[i][k] * B[k][j];  
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < K; j++)
        {
            cout << ANS[i][j] << " ";
        }
        cout << "\n";
    }
    
}