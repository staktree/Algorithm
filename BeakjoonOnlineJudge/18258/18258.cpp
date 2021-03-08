/*
https://www.acmicpc.net/problem/18258

BOJ 18258번 큐2

(1) 접근
큐의 성질을 구현하는 문제이다. queue 자료구조를 사용하여 해결했다.

(2) 해결
switch문을 사용하기 위해서 map을 만들었고 이를 통해 입력받은 커맨드를 인트형으로 변환하여 스위치문을 사용하였다.
나머지는 queue자료구조의 라이브러리 함수를 사용하여 해결했다.
다만 cin, cout을 사용하면서 시간초과가 발생했는데, 원인을 몰라서 한참 헤매었다. 개행문자를 endl 대신 \n을 사용하고 main함수에 cin.tie(0);
	cin.sync_with_stdio(false); 코드를 추가하니 시간초과 없이 해결할 수 있었다.
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <string>

using namespace std;

int N;
string command;
int num;

map <string, int> m;

queue <int> q;

void settingCommand()
{
	m["push"] = 0;
	m["pop"] = 1;
	m["size"] = 2;
	m["empty"] = 3;
	m["front"] = 4;
	m["back"] = 5;
}

void excuteCommand(string command)
{
	switch (m[command])
	{
		case 0:
			cin >> num;
			q.push(num);
			break;
		case 1:
			if (q.empty())
				cout << -1 << '\n';
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
			break;
		case 2:
			cout << q.size() << '\n';
			break;
		case 3:
			if (q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
			break;
		case 4:
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
			break;
		case 5:
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		break;
		default:
			break;
	}
}
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	
	settingCommand();
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> command;
		excuteCommand(command);
	}
}