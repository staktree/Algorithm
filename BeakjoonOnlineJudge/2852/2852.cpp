/*
https://www.acmicpc.net/problem/2852
BOJ 2852번 농구

(1) 접근
득점한 팀의 번호와 득접 시간을 입력받는다.
이를 통하여 각 팀이 리드(이기고 있음)한 시간을 구하여 출력한다. 
시간의 분, 초를 vector의 쌍으로 표현하고, 시간을 더하고 빼는 것을 함수로 만들어 
입력과 동시에 리드하고 있는 팀의 리딩시간을 계산하여 출력하였다.

(2) 해결
입력 개수인 N만큼 득점한 팀과 시간을 입력받는다. 
팀별로 점수를 변수로 저장하여, 득점한 팀의 점수를 추가한다.
이전 득점 시간이 있다면 현재 득점시간과 이전 득점시간의 뺄셈을 계산하여 득점한 팀의 리딩시간에 덧셈한다. 만약 이전 득점 시간이 없다면 00:00을 이전 득점시간으로 하여 계산한다. N개의 입력을 마치면 마지막으로 48분에서 이전 득점 시간을 뺄셈하여 이기고 리드하고 있는 팀의 점수로 계산한다. 
각각 팀의 계산된 시간을 출력한다.
*/
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N;

pair <int, int> A;
pair <int, int> B;

int scoreA = 0;
int scoreB = 0;

pair <int, int> minusTime(pair <int, int> pre, pair <int, int> now)
{
	int sec = now.second - pre.second;
	int min = now.first - pre.first;
	if (sec < 0)
	{
		min--;
		sec += 60;
	}
	pair <int, int> calced(min, sec);
	return calced;
		
}

pair <int, int> plusTime(pair <int, int> pre, pair <int, int> now)
{
	int sec = now.second + pre.second;
	int min = now.first + pre.first;
	if (sec >= 60)
	{
		min++;
		sec -= 60;
	}
	pair <int, int> calced(min, sec);
	return calced;
}

string printTime(int time)
{
	if (time < 10)
		return "0" + to_string(time);
	else return to_string(time);
}

int main()
{
	int scoredTeam;
	string scoredTime;
	int nowMin, nowSec;
	pair <int, int> preScoredTime(0, 0);

	cin >> N;
	for (int i = 0; i < N + 1; i++)
	{
		if (i < N)
		{
			cin >> scoredTeam >> scoredTime;
			nowMin = stoi(scoredTime.substr(0, 2));
			nowSec = stoi(scoredTime.substr(3, 2));	
		}
		else
		{
			nowMin = 48;
			nowSec = 0;
		}

		pair <int, int> nowScoredTime(nowMin, nowSec);

		if (scoreA > scoreB)
			A = plusTime(A, minusTime(preScoredTime, nowScoredTime));
		else if(scoreB > scoreA)
			B = plusTime(B, minusTime(preScoredTime, nowScoredTime));
		
		if (scoredTeam == 1)
			scoreA++;
		else scoreB++;

		preScoredTime = nowScoredTime;
	}

	cout << printTime(A.first) << ":" << printTime(A.second) << endl;
	cout << printTime(B.first) << ":" << printTime(B.second) << endl;
} 