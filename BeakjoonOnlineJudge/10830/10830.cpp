/*
https://www.acmicpc.net/problem/10830
BOJ 10830번 행렬 제곱

(1) 접근
입력받은 행렬을 제곱하는 문제이다.
제곱의 특성을 이용하여 분할정복하는 문제이다.

(2) 해결
2의 8제곱은 4의 4제곱이고, 4의 4제곱은 16의 제곱이다. 
이 특성을 이용하여 분할정복하면 N제곱을 O(log(N))만에 수행할 수 있다. 
재귀함수를 이용하여 N이 홀수인지 짝수인지를 판단하여 그에 맞는 처리를 해주면 된다.
홀수라면 행렬의 N - 1제곱에 행렬을 한번 더 곱하고, 
짝수라면 행렬의 제곱을 N/2제곱한다.

(3) 마무리
행렬 곱셈과 제곱수를 분할정복하는 알고리즘을 알고 있으면 잘 풀 수 있는 문제입니다.
1000으로 나눈 나머지를 출력해야하기 때문에 행렬 값에 1000이 들어오는 경우를 체크하지 않아서 한번에 통과하지 못했네요.
앞으로는 엣지케이스를 더 잘 체크해야겠습니다.
*/
#include <iostream>
#include <vector>

using namespace std;
typedef vector< vector<long long int> > matrix;
long long int N;
long long int B;

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

matrix multiplyMatrix(matrix A, matrix B)
{
    matrix T = createMatrix(N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < N; k++)
            {
                T[i][j] = (T[i][j] + (A[i][k] * B[k][j])) % 1000;
            }   
        }
    }
    return T;
}

matrix power(matrix T, long long int squaredCount)
{
    if(squaredCount == 1)
        return T;
    else if(squaredCount % 2 == 0)
        return power(multiplyMatrix(T, T), squaredCount / 2);
    else
        return multiplyMatrix(T, power(T, squaredCount - 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    matrix M;

    cin >> N >> B;
    M = createMatrix(N);
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> M[i][j];
            M[i][j] %= 1000;
        }
    }
    
    M = power(M, B);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%lld ", M[i][j]);
        }
        printf("\n");
    }
}