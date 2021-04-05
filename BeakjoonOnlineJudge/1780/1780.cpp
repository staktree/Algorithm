/*
https://www.acmicpc.net/problem/1780
BOJ 1780번 종이의 개수

(1) 접근
이전에 풀었던 쿼드트리 문제에서 나누는 종이의 개수가 4개에서 9개로 늘어난 문제이다. 

(2) 해결
쿼드트리에서도 현재 체크하고 있는 종이 덩어리에 다른 값이 있는지 없는지를 체크하고, 다른 것이 있다면 4등분하여 다시 이를 반복하여 체크하였다. 
이 문제는 9등분을 해야함으로 덩어리가 모두 같은 값인지 체크한 후 다른 값이 있다면 범위를 9등분하여 이를 반복적으로 체크한다. 또한 새로운 종이의 종류가  조건에 추가되어있기 떄문에 모두 같은 값일 때 체크하는 종류를 하나 더 추가하여 구현하면 해결된다. 
쿼드트리문제와 99% 유사한 문제라고 생각한다.
*/
#include <iostream>
using namespace std;

int paperArray[2187][2187];
int totalBlue = 0;
int totalWhite = 0;
int totalBlack = 0;

void dividePaper(int N, int startIndexY, int startIndexX)
{
	for (int i = startIndexY; i < startIndexY + N; i++)
	{
		for (int j = startIndexX; j < startIndexX + N; j++)
		{
			if (paperArray[startIndexY][startIndexX] != paperArray[i][j])
			{
				int dividedN = N / 3;
				dividePaper(dividedN, startIndexY, startIndexX);
				dividePaper(dividedN, startIndexY, startIndexX + dividedN);
				dividePaper(dividedN, startIndexY, startIndexX + ( 2 * dividedN));
				dividePaper(dividedN, startIndexY + dividedN, startIndexX);
				dividePaper(dividedN, startIndexY + dividedN, startIndexX + dividedN);
				dividePaper(dividedN, startIndexY + dividedN, startIndexX + (2 * dividedN));
				dividePaper(dividedN, startIndexY + (2 * dividedN), startIndexX);
				dividePaper(dividedN, startIndexY + (2 * dividedN), startIndexX + dividedN);
				dividePaper(dividedN, startIndexY + (2 * dividedN), startIndexX + (2 * dividedN));
				return;
			}
		}
	}
	if (paperArray[startIndexY][startIndexX] == -1)
		totalBlue++;
	else  if (paperArray[startIndexY][startIndexX] == 0)
		totalWhite++;
	else totalBlack++;
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

	cout << totalBlue << "\n";
	cout << totalWhite << "\n";
	cout << totalBlack << "\n";

	return 0;
}