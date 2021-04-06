/*
https://www.acmicpc.net/problem/18870
BOJ 18870번 좌표압축
 
(1) 접근
가장 작은 수를 0으로하여 수열의 큰 순서를 압축한다. 
100 10 1 을 압축하면 2 1 0이 된다. 
벡터와 맵을 활용하여 해결할 수 있었다.

(2) 해결
입력받은 수열을 복사하여 정렬하고, 정렬된 순서대로 mapping을 한다. 
map에 value가 없는 경우에만 count를 올리고 map[key] = count로 value를 설정한다.
다시 정렬되지 않은 수열을 순서대로 map에 넣어 mapping하면 압축된 값이 차례대로 출력된다. 
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N;
vector<int> number;
vector<int> sorted;
map <int,int> m;
vector<int> ans;
int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        number.push_back(temp);
    }

    sorted = number;
    sort(sorted.begin(), sorted.end());  

    int count = 0;
    for(int i = 0; i < N; i++)
    {
        if(m[sorted[i]] == 0)
        {
            count++;
            m[sorted[i]] = count;
        }
    }

    for(int i = 0; i < N; i++)
    {
        cout << m[number[i]] - 1 << " ";
    }
}