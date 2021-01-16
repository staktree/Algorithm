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