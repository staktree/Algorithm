/*
https://www.acmicpc.net/problem/2004
BOJ 2004번 조합 0의 개수

(1) 접근
이항계수를 구하고 맨 뒤부터의 0의 개수를 구하는 문제이다.
이항 개수는 N!/M!(N-M)!으로 구할 수 있었다.

(2) 해결
팩토리얼 0의 개수 문제(BOJ  1676번)에서 0을 구하는 방법을 이용하여 이항개수 식 각 항의 0의 개수를 구하면 된다.
N!의 2와 5가 나오는 개수에서 M!, (N-M)!의 2와5가 나오는 개수를 합하여 뺄셈하면 된다. 여기서 주의할 점은 2가 나오는 개수와 5가 나오는 개수를 각각 따로 계산하여 이 식을 계산한 후 2의 개수와 5의 개수 중 더 작은 것을 정답으로 출력한다.
*/
#include <iostream>
#include <cstdio>

using namespace std;

long long int N , M;
int fiveCount;
int twoCount;
int zeroCount;

int calFiveCount(int N)
{
	long long int five = 5;
	long long int forReturn = 0;
	while (N >= five)
	{
		forReturn += N / five;
		five *= 5;
	}
	return forReturn;
}

int calTwoCount(int N)
{
	long long int two = 2;
	long long int forReturn = 0;
	while (N >= two)
	{
		forReturn += N / two;
		two *= 2;
	}
	return forReturn;
}

int main()
{
	cin >> N >> M;

	fiveCount = calFiveCount(N) - (calFiveCount(M) + calFiveCount(N - M));
	twoCount = calTwoCount(N) - (calTwoCount(M) + calTwoCount(N - M));

	zeroCount = (fiveCount > twoCount) ? twoCount : fiveCount;
	cout << zeroCount;
	return 0;
} 