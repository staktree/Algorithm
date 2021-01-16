/*
 https://www.acmicpc.net/problem/11724
 BOJ 11724번 연결 요소의 개수
 (1) 접근
 연결 요소란 그래프에서 연결된 노드끼리 묶었을 때 묶음의 개수이다.
 예제 입력1을 예로 들면
 1, 2, 5 / 3, 4, 6 두가지 묶음으로 표현된다. 즉, 연결 요소는 2개이다.

 (2) 해결
 BFS, DFS 를 이용하여 연결된 노드를 체크하고,
 다시 방문되지 않은 노드부터 이를 반복한다.
 반복 횟수를 출력하면 정답이다.
 */
#pragma warning(disable: 4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
int cnt = 0;
vector <int> Node[1001];
bool checkedNode[1001];

void BFS(int start)
{
    vector <int > queue;
    
    checkedNode[start] = true;
    for(int i = 0; i < Node[start].size(); i++)
    {
        queue.push_back(Node[start][i]);
        checkedNode[Node[start][i]] = true;
    }

    while (queue.size() > 0)
    {
        int firstIn = queue[0];
        for(int i = 0; i < Node[firstIn].size(); i++)
        {
            if(checkedNode[Node[firstIn][i]] == false)
            {
                queue.push_back(Node[firstIn][i]); 
                checkedNode[Node[firstIn][i]] = true; 
            }
        }
        queue.erase(queue.begin());
    }
}

int checkRemainNode()
{
    for(int i = 1; i <= N; i++)
    {
        if(!checkedNode[i])
            return i;
    }
    return -1;
}

int main()
{
    int start, arrive;
    int startNode;

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> start >> arrive;
        Node[start].push_back(arrive);
        Node[arrive].push_back(start);
    }

    while(true)
    {
        startNode = checkRemainNode();
        if(startNode < 0)
            break;
        
        BFS(startNode);
        cnt++;
    }

    cout << cnt << endl;
    
    return 0;
}