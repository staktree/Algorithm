/*
https://www.acmicpc.net/problem/11051
이항계수 11050번, 11051번 이항계수 1, 2

(1) 접근
이항계수는 N개의 수 중에서 K를 뽑는 경우의 수를 뜻한다.
11050번과 11051번은 입력 범위와 10007의 나머지를 출력하는 것만 다르고, 
11051번의 소스코드로 11050번도 통과할 수 있기때문에 한꺼번에 작성하였다.
11050번은 입력범위가 작기 때문에 팩토리얼 자체를 동적 프로그램(DP)으로 구한 후 N! / K!(N - K)!의 공식을 DP에서 값을 가져와 해결했다. 하지만 11051번은 
값의 범위가 크고 나머지끼리의 나눗셈으로 원래의 값의 나머지를 구하기가 어려웠다. 이항계수 자체를 DP 배열에 저장하여 해결해야했다.

(2) 해결
파스칼의 삼각형을 이용하여 이항계수 DP를 만들 수 있었다.
DP의 점화식을 표현하면
if (j == 0)
    factorialDP[i][j] = 1;
else
     factorialDP[i][j] = (factorialDP[i - 1][j] + factorialDP[i - 1][j - 1])
이고 이를 11051번에서는 10007의 나머지로 출력한다.
*/
#include <iostream>
#include <cstdio>

#define MOD 10007

using namespace std;

int N, K;
int answer;
int factorialDP[1001][1001] = {0,};

int main()
{
	cin >> N >> K;
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				factorialDP[i][j] = 1;
			else
				factorialDP[i][j] = (factorialDP[i - 1][j] + factorialDP[i - 1][j - 1]) % MOD;
		}	
	}
	cout << factorialDP[N][K];
}