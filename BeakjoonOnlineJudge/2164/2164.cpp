/*
https://www.acmicpc.net/problem/2164
BOJ 2164번 카드2

(1) 접근
1 부터 N까지의 카드를 1을 젤 위에 놓고 정렬한다. 맨 위의 카드를 1장 버린 후 다시 맨 위의 카드는 맨 아래에 놓는다. 이렇게 카드가 1장이 될 때까지 반복한다.
큐 자료구조를 사용하면 쉽게 해결할 수 있다.

(2) 해결
1 ~ N까지를 큐에 푸시한다. 큐에서 pop하고 큐의 front를 푸시한다. 이를 size가 1이 될 때까지 반복한다.
*/
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

queue <int> q;
int N;

int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        q.push(i);
    } 

    while (q.size() > 1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    
    cout << q.front();
}