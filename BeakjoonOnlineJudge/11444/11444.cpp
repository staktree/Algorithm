/*
https://www.acmicpc.net/problem/11444
BOJ 11444번 피보나치 수 6

(1) 접근
피보나치 수를 행렬을 이용해서 구할 수 있다.
어떻게 풀어야할지 감이 오지 않아서 다른 블로그들을 참고하였다.
Fn+1 Fn = 1 1
Fn Fn-1     1.0 의 n제곱
이라는 행렬식이 등장하게 되는데 이는 행렬의 곱과 분할정복을 이용한 제곱 구하기를 통하여 문제를 해결할 수 있었다.

(2) 해결
10830번에서 행렬의 제곱에 대한 문제를 풀었었다.
그래서 이를 다시 한번 구현했고, 제곱할 행렬의 값을 위에서 설명한 행렬으로 설정했다. 
N을 입력받은 후, N 제곱한 후 Fn인 (1,0)의 값을 출력하면 된다.
*/
#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector< long long int> > matrix;
long long int N;

matrix createMatrix(int size)
{
    matrix T;
    for(int i = 0; i < size; i++)
    {
        vector <long long int> column;
        for(int j = 0; j < size; j++)
        {
            column.push_back(0);
        }
        T.push_back(column);
    }
    return T;
}

matrix multipleMatrix(matrix A, matrix B)
{
    matrix T = createMatrix(2);
    for(int i = 0; i < A.size(); i++)
    {
        for(int j = 0; j < A.size(); j++)
        {
            for(int k = 0; k < A.size(); k++)
            {
                T[i][j] = (T[i][j] + (A[i][k] * B[k][j])) % 1000000007;
            }
        }
    }
    return T;
}

matrix sqrtMatrix(matrix P, long long int N)
{
    if(N == 1)
        return P;
    else if(N % 2 == 0)
        return sqrtMatrix(multipleMatrix(P, P), N / 2);
    else 
        return multipleMatrix(P, sqrtMatrix(P, N -1));
}

int main()
{
    matrix P = createMatrix(2);
    P[0][0] = 1;
    P[0][1] = 1;
    P[1][0] = 1;
    P[1][1] = 0;
    scanf("%lld", &N);
    
    if(N < 1)
    {
        printf("%d\n", 0);
        return 0;
    }

    P = sqrtMatrix(P, N);
    printf("%lld\n", P[01][0] % 1000000007);

    return 0;
}
