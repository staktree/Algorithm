/*
https://www.acmicpc.net/problem/1966
BOJ 1966번 프린터 큐

(1) 접근
프린터의 예약된 작업을 큐 형식으로 저장한다.
하지만 큐의 맨 앞에 있는 작업의 중요도보다 높은 작업이 존재한다면 맨 앞의 작업을 pop하여 맨 뒤로 미룬다. 이 때 찾기를 원하는 순서의 작업이 몇 번째로 출력되는지 계산하는 문제이다. STL의 queue 자료구조를 이용하여 문제를 구현했다.

(2) 해결
입력받은 값들을 순서대로 큐에 입력한다. 
다른 벡터에도 같은 순서로 값들을 입력한다.
벡터를 내림차순으로 정렬하여 중요도 순으로 정렬되도록 한다.
큐에서 작업을 수행할 떄마다 정렬된 벡터의 중요도와 비교하여 작업이 가능한지 체크한다. 가능한 작업이라면 큐에서 pop하고 count를 증가시킨다.
만약 원하는 순서의 작업이었다면 모든 반복을 중단시키고 count를 출력한다. 
*/

#pragma warning(disable: 4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int M, findPrintNum;
int temp;
int ans;
int priorityMax;

bool cmp(const pair<int , int> &v1, const pair<int, int> &v2)
{
	return v1.second > v2.second;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		ans = 0;
		queue < pair<int, int> > printQueue;
		vector < pair<int, int> > sortedQueue;
		
		cin >> M >> findPrintNum;
		for (int j = 0; j < M; j++)
		{
			cin >> temp;
			pair <int, int> tempPair(j, temp);
			printQueue.push(tempPair);
			sortedQueue.push_back(tempPair);
		}

		sort(sortedQueue.begin(), sortedQueue.end(), cmp);

		priorityMax = sortedQueue.front().second;
		while (true)
		{
			if (priorityMax == printQueue.front().second)
			{
				ans++;
				if (printQueue.front().first == findPrintNum)
					break;
				else
				{
					printQueue.pop();
					priorityMax = sortedQueue[ans].second;
				}
			}
			else
			{
				printQueue.push(printQueue.front());
				printQueue.pop();
			}
		}
		cout << ans << endl;
	}
} 