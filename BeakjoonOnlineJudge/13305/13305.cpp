/*
https://www.acmicpc.net/problem/13305
BOJ 13305번 : 주유소

(1) 접근
이 문제는 왼쪽 도시부터 오른쪽 도시까지 이동하는 최소 비용을 구하는 문제이다.  석유 가격이 더 낮은 도시를 만나기 전까지의 거리만큼 주유하고 다시 주유를 할 도시를 만나면 이를 반복한다.

(2) 해결
모든 입력을 받은 후 처음의 오일 가격을 저장한 후
다음 도시로 이동한다고 가정한다. 만약  다음 도시의 오일 가격이 더 저렴하다면 더 저렴한 기름을 주유하는 것으로 하고 더 비싸다면 기존의 저장된 가격의 오일을 주유하는 것으로 한다. 이 과정을 마지막 도시까지 반복한다.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

long long int totalPrice;
int N;
vector <long int> oilprice;
vector <long int> dist;
int nowPrice = 1000000000;

int main()
{
	int temp;

	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> temp;
		dist.push_back(temp);
	}

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		oilprice.push_back(temp);
	}

	for (int i = 0; i < N - 1; i++)
	{
		if (oilprice[i] < nowPrice)
			nowPrice = oilprice[i];
		totalPrice += (dist[i] * nowPrice);
	}

	cout << totalPrice;
} 