/*
https://www.acmicpc.net/problem/9375
BOJ 9375번 패션왕 신해빈

(1) 접근
의상의 종류와 개수에 따라서 만들 수 있는 조합을 구하는 공식을 구하고,
map 자료구조를 사용하여 해결할 수 있다.

(2) 해결
문제의 공식을 구하면 
(종류 별 의상 개수 + 1) * (종류 별 의상 개수 + 1) * ... * (종류 별 의상 개수 + 1) - 1 이다. 
종류 key로 하여 map을 만들고 중복되는 키가 입력되었다면 key에 Hashing된  의상 개수를 1 증가시킨다. 중복되는 키가 없다면 새로운 키로 삽입한다.
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int N;
int M;
int cnt;
string temp;
string key;
map <string, int> clothMap;

int calFasionCount()
{
	for (map<string, int>::iterator it = clothMap.begin(); it != clothMap.end(); it++) {
		cnt = cnt * (it->second + 1);
	}
	return cnt - 1;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cnt = 1;
		clothMap.clear();
		cin >> M;
		for (int j = 0; j < M; j++)
		{
			cin >> temp >> key;
			if (clothMap.count(key))
				clothMap[key]++;
			else
				clothMap.insert(pair<string, int>(key, 1) );
		}
		cout << calFasionCount() << endl;
	}
} 