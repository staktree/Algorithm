/*
https://www.acmicpc.net/problem/17298
BOJ 17298번  오큰수

(1) 접근
수열에서 자신의 위치보다 왼쪽의 수 중 제일 먼저 나온 자신보다 큰 수를 찾아 배열을 만드는 문제이다. 
스택 자료구조를 이용하여 문제를 해결할 수 있었다.

(2) 해결
만약 입력받은 수가 스택의 top 값보다 크다면 입력받은 수를 '오큰수'로 한다. 오큰수를 구한 수는 팝한다. pop된 수의 '오큰수'는 자신의 입력받은 순서로 지정하여 저장한다. 입력받은 수는 다시 스택에 푸시한다. 이를 반복하다보면 '오큰수'가 있는 수들은 스택에서 모두 pop되고, '오큰수'가 없는 수들만 남게 된다. 
이 수들의 순서에는 -1을 넣어 저장한다. 마지막으로 순서에 맞게 저장된 값들을 차례대로 출력하면 정답이 된다.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int N;
int ans[1000000];
stack < pair<int, int> > numberStack;

int main()
{
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		while (numberStack.size() > 0 && temp > numberStack.top().first)
		{
			int index = numberStack.top().second;
			ans[index] = temp;
			numberStack.pop();
		}
		pair <int, int> inputNum(temp, i);
		numberStack.push(inputNum);
	}

	while (numberStack.size() > 0)
	{
		int index = numberStack.top().second;
		ans[index] = -1;
		numberStack.pop();
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}
} 