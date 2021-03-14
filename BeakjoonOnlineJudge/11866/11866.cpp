/*
https://www.acmicpc.net/problem/11866
BOJ 11866번 요세푸스 문제 0

(1) 접근
1 ~ N개의 수를 오름차순으로 정렬하고 원형으로 나열한 뒤 K번째의 수를 반복하여 추출했을 때 추출되는 순서에 따라서 생성되는 수열을 요세푸스 수열이라고 한다. 이 때 N과 K가 주어지고, 요세푸스 수열을 구하여 출력하는 문제이다.
큐 자료구조를 이용하여 해결하였다.

(2) 해결 
큐의 특성을 이용하여 K번째 이전 순서의 수들을 pop하여 다시 큐에 푸시하면 
K번째 수를 뽑을 때 반복적으로 맨 앞에서 부터 순서를 계산하여 이 수열을 구할 수 있다. 

ex) 5 3
1 2 3 4 5 -> 3번째 '3' 추출 -> 1 2 4 5
1 2 4 5 -> '4'에서 부터  3번째 수 추출 -> 마지막 순서인 '5'에서 '1'로 넘어가며 순서를 계산해야함 -> '1' 추출

큐를 사용한다면 '1', '2'가 맨뒤로 이동되고 '3'이 추출되면
4 5 1 2 -> 맨 처음부터 세번째인 '1' 추출

큐를 이용함으로써 구현이 용이해진다.
*/
#pragma warning (disable : 4996)
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int N;
int K;

queue <int> q;
vector <int> ans;

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}


	while (q.size() > 0)
	{
		for (int i = 0; i < K - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		ans.push_back(q.front());
		q.pop();
	}

	cout << "<";
	for (int i = 0; i < N; i++)
	{
		if (i == N - 1)
			cout << ans[i] << ">" << endl;
		else cout << ans[i] << ", ";
	}
}