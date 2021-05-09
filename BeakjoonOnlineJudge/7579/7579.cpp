/*
https://www.acmicpc.net/problem/7579
BOJ 7579번 앱

(1) 접근
냅색문제의 변형 문제이다. 
어플을 실행할 때마다 메모리가 필요한데, 메모리는 제한되어 있어 동시에 실행할 수 있는 어플의 개수는 유한하다.
새로운 어플이 실행되어야 할때 메모리가 부족한 경우가 있는데, 이때 기존에 실행 중이던 어플을 비활성화시켜 메모리를 확보하여 실행한다.
하지만 비활성화시키는데도 비용이든다. 최소비용으로 새로운 어플을 실행하기 위한 메모리를 확보해야한다. 

(2) 해결
작은 비용으로 더 많은 메모리를 확보해야한다. 따라서 비용을 기준으로 최대의 메모리를 가질 수 있는 경우를 메모제이션하여 해결한다.
현재 실행 중인 어플의 메모리와 비용을 입력받고, 해당 비용의 메모리를 메모제이션된 값과 비교시켜 더 큰 값을 다시 메모제이션한다.
메모제이션된 값들에 다음 차례의 어플의 비용을 더하다보면 모든 조합가능한 비용들을 계산할 수 있기 때문에 비용이 계산될 때마다 비교하여 큰 값을 저장한다.
마지막으로 메모제이션된 값 중 필요한 메모리인 M이상인 최소비용을 출력하면 된다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    int memory[101] = {0, };
    int cost[101] = {0, };
    int DP[10001] = {0, }; 
    vector <int> calculatedCost;

    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &memory[i]);
    }
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &cost[i]);
    }

    for(int i = 0; i < N; i++)
    {   
        int preCal =  calculatedCost.size();
        for(int j = preCal - 1; j >=0; j--)
        {
            if(DP[cost[i] + calculatedCost[j]] == 0)
                calculatedCost.push_back(cost[i] + calculatedCost[j]);
            DP[cost[i] + calculatedCost[j]] = max(DP[cost[i] + calculatedCost[j]], DP[calculatedCost[j]] + memory[i]);
        }

        if(DP[cost[i]] == 0)
            calculatedCost.push_back(cost[i]); 
        DP[cost[i]] = max(DP[cost[i]], memory[i]);
        sort(calculatedCost.begin(), calculatedCost.end());
    }

    for(int i = 0; i < calculatedCost.size(); i++)
    {
        int index = calculatedCost[i];
        if(DP[index] >= M)
        {
            printf("%d\n", index);
            break;
        }   
    }
}
