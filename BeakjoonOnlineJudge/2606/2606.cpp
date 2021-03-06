/*
https://www.acmicpc.net/problem/2606

BOJ 2606번 바이러스

(1) 접근
1번 컴퓨터가 바이러스가 걸린다면
연결된 컴퓨터들은 모두 바이러스에 감염된다.
1번 컴퓨터가 감염시킨 컴퓨터의 개수를 구하는 문제이다. 
이는 DFS를 이용하면 쉽게 해결할 수 있다.

(2) 해결
기본적인 DFS를 사용하면 된다.
1번과 연결된 노드 중 방문되지 않은 노드가 있다면 count를 1 올려준다. 이를 연결된 노드로 이동하여 반복하면 모든 연결된 노드가 방문되었을 때 1번이 감염시킨 컴퓨터의 개수가 count에 저장된다. 
*/
#pragma warning(disable:4996)
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int comCount;
int nodeCount;
vector<int> com[101];
bool isCheckedNode[101] = {false, };
int  infectionCount = 0;

void DFS(int startNode)
{
	isCheckedNode[startNode] = true;
	for (int i = 0; i < com[startNode].size(); i++)
	{
		int endNode = com[startNode][i];
		if (!isCheckedNode[endNode])
		{
			infectionCount++;
			DFS(endNode);
		}
	}
}

int main()
{
	scanf("%d", &comCount);
	scanf("%d", &nodeCount);
	for (int i = 0; i < nodeCount; i++)
	{
		int startNode, endNode;
		scanf("%d %d", &startNode, &endNode);
		com[startNode].push_back(endNode);
		com[endNode].push_back(startNode);
	}

	DFS(1);
	printf("%d", infectionCount);
	return 0;
}