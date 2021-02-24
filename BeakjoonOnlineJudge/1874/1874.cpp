/*https://www.acmicpc.net/problem/1874
BOJ 1874번 스택 수열

(1) 접근
수열을 입력 받은 후 1~N 까지를 입력받으며 수열과 일치하게 만들 수 있도록 스택에 push와 pop하는 과정을 출력하는 문제이다. 
만약 스택의 top이 입력받은 수열의 현재 인덱스에 저장된 값과 일치한다면 계속해서 pop하고, 그렇지 않다면  push만 하고 넘어가는 식으로 문제를 해결했다.

(2) 해결
vector를 선언하여 수열을 입력받았다.
for문을 통해서 1~N까지 stack에 푸시하고, while문을 통해 스택의 top과 수열의 특정 인덱스에 저장된 값을 비교한다. 만약 while문에 들어온다면 스택에서 pop하고 특정 인덱스++를 하여 다음 값을 비교한다. 
*/
#pragma warning(disable: 4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int N;
int temp;
int stackCount = 0;
vector <int> seq;
stack <int> numStack;
string ans;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		seq.push_back(temp);
	}

	for (int i = 1; i <= N; i++)
	{
		numStack.push(i);
		ans += '+';
		
		while (numStack.empty() == false && seq[stackCount] == numStack.top())
		{
			numStack.pop();
			ans += '-';
			stackCount++;
		}
	}

	if (numStack.empty() == false)
		cout << "NO";
	else
	{
		for (int i = 0; i < ans.size(); i++)
		{
			printf("%c\n", ans[i]);
		}
	}

	return 0;
} 