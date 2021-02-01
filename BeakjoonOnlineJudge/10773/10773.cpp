/*
https://www.acmicpc.net/problem/10773
BOJ 10773번 제로

(1) 접근
스택을 이용하여 쉽게 해결할 수 있다.

(2) 해결
c++의 vector형식을 사용하여 스택을 구현했다.
0이 입력되었을 때 스택에서 pop하고 0 이외의 수가 입력되었을 때 그 수를 push한다.
모든 수를 입력받은 후에 스택의  모든 수를 더하면 정답이 도출된다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int K;
vector <int> stack;
int sum;

int main()
{
	int temp;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> temp;
		if (temp == 0)
			stack.pop_back();
		else stack.push_back(temp);
	}
	
	for (int i = 0; i < stack.size(); i++)
		sum += stack[i];

	cout << sum;
}
