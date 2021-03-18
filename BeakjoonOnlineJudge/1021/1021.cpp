/*
https://www.acmicpc.net/problem/1021
BOJ 1021번 회전하는 큐

(1) 접근
입력받은 순서대로 큐에서 pop하는 문제이다. 
큐의 특성 상 front만을 pop할 수 있기 때문에 순서대로 pop하기 위해서는
큐를 회전시켜야한다. 
왼쪽으로 한 칸 회전시키면 가장 앞에 있는 것이 맨 뒤로 이동되고, 
오른쪽으로 한 칸 회전시키면 가장 뒤에 있는 것이 맨 앞으로 이동된다.
그래서 왼쪽, 오른쪽으로 회전시킨 횟 수를 구하여 출력하는 문제이다.

(2) 해결
회전 시키기 위해서는 맨 뒤의 값을 pop하여 맨 앞에 위치시킬 수 있어야하고, 반대로 맨 앞의 값을 pop하여 맨 뒤로 위치시킬 수 있어야한다. 
이는 deque을 사용하면 간단해진다. 

다음으로 회전할 방향을 결정해야한다.
회전을 결정하기 위해서 뽑아야할 값의 위치를 앞에서 부터 n번째, 뒤로 부터 k번째로 계산한다. n과 k 둘중에 작은 것을 회전방향으로 결정한다. 

회전할 때마다 count에 1을 더하여 계산하고 마지막으로 출력한다. 
*/

#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>

using namespace std;

int N;
int M;
int ans;

deque <int> sequence;
deque <int> dq;

void calNum2(int count)
{
	for (int i = 0; i < count; i++)
	{
		dq.push_back(dq.front());
		dq.pop_front();
	}
	ans += count;
}

void calNum3(int count)
{
	for (int i = 0; i < count; i++)
	{
		dq.push_front(dq.back());
		dq.pop_back();
	}
	ans += count;
}

void compareSequence()
{
	int calCount;
	for (int i = 0, j = dq.size() - 1; i < dq.size(), j >= 0; i++, j--)
	{
		if (dq[i] == sequence.front())
		{
			calNum2(i);
			break;
		}
		else if (dq[j] == sequence.front())
		{
			calNum3(dq.size() - j);
			break;
		}
	}
}

int main()
{
	int temp;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		sequence.push_back(temp);
	}

	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}

	while (sequence.size() > 0)
	{
		if (dq.front() == sequence.front())
		{
			dq.pop_front();
			sequence.pop_front();
		}
		else
		{
			compareSequence();
		}
	}

	cout << ans;
}
