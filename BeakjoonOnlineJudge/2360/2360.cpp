/*
https://www.acmicpc.net/problem/2630

BOJ 2360번 색종이 만들기

(1) 접근
정사각형으로 이루어진 정사각형 모양의 종이가 주어지고, 이는 하얀색 또는 파란색으로 색칠되어있다. 
이 종이를 4등분하여 나누어진 부분이 모두 같은 색이 아니라면 나누어진 부분을 다시 4등분한다. 이를 더 이상 나누어질 수 없을 때까지 반복하고, 만약 같은 색이라면 1개의 사각형으로 더 이상 나누지 않는다.
결과적으로 하얀색, 파란색의 사각형 개수를 각각 출력하는 문제이다. 
종이의 크기가 N x N이고 N은 2의 제곱수이므로 사각형을 나누는 과정을 재귀함수로 구현하여 큰 사각형이 점점 작은 사각형이 되도록 하였다.

(2) 해결 
직관적으로 생각하여 사각형을 나누는 재귀함수를 만들었다. 가장 작은 정사각형이 될 때까지 나누고, 만약 가장 작은 정사각형 4개가 같은 색이라면 해당 색을 리턴하고, 만약 다른 색이라면 색 별로 총 색깔 개수에 더한다. 
리턴받은 함수에서도 마찬가지로 리턴 받은 값들이 모두 같다면 해당 색을 리턴하고, 다르다면 이미 총 색깔개수에 포함되어 있기 때문에 이미 개수를 센 조각이라는 표시를 리턴한다.

이렇게 재귀함수를 구현하니 재귀함수의 모양이 깔끔하지않았다.
그래서 블로그를 참조하여 다시 문제를 해결하였다.
결국 같은 조각을 표시되기 위해서는 옆 사각형과 색이 같아야한다..
만약 아니라면 이를 기준으로 사각형을 나누고, 대칭이라면 조각의 개수를 카운트한다. 
*/
#include <iostream>
using namespace std;

int paperArray[128][128];
int totalBlue = 0;
int totalWhite = 0;

void dividePaper(int N, int startIndexY, int startIndexX)
{
	for (int i = startIndexY; i < startIndexY + N; i++)
	{
		for (int j = startIndexX; j < startIndexX + N; j++)
		{
			if (paperArray[startIndexY][startIndexX] != paperArray[i][j])
			{
				int dividedN = N / 2;
				dividePaper(dividedN, startIndexY, startIndexX);
				dividePaper(dividedN, startIndexY, startIndexX + dividedN);
				dividePaper(dividedN, startIndexY + dividedN, startIndexX);
				dividePaper(dividedN, startIndexY + dividedN, startIndexX + dividedN);
				return;
			}
		}
	}
	if (paperArray[startIndexY][startIndexX] == 0)
		totalWhite++;
	else totalBlue++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> paperArray[i][j];
	}

	dividePaper(N, 0, 0);

	cout << totalWhite << "\n";
	cout << totalBlue << "\n";

	return 0;
}