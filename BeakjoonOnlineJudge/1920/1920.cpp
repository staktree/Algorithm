/*
https://www.acmicpc.net/problem/1920
BOJ 1920번 수 찾기

(1) 접근 
이진 탐색 문제이다. 
이진 탐색 알고리즘이 어떤 것인지 간단히 정리하고 넘어가자면, 
이진 탐색은 선형적인 탐색을 했을 때의 O(n제곱)의 수행시간을 O(logN)의 시간으로 줄이는 획기적인 알고리즘이다. 이진 탐색을 수행하기 위해서는 탐색의 대상인 데이터가 정렬된 상태이어야한다. 정렬된 상태의 데이터의 중앙값과 탐색할 값과 비교하여  크다면 큰값부터 끝까지, 작다면 처음부터 mid보다 작은값까지로 범위를 반으로 축소하여 이를 반복한다. 

(2) 해결
이진탐색 알고리즘을 그대로 구현할 줄 안다면 쉽게 해결할 수 있다. 
값을 입력받을 때마다 이진탐색 알고리즘을 통해 값이 존재하는지 존재하지 않는지를 체크한다. 그리고 그 결과에 따른 값을 각각 출력한다. 

(3) 주의사항
iostream 대신 cstdio를 사용하여야한다. iosteam으로 인풋과 아웃풋을 구현하니 시간초과가 발생하였다.
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int M;
int A[100001];
int B;

bool findNumber(int num)
{
    int left = 0;
    int right = N - 1;

    if(A[left] > num || A[right] < num)
        return false;

    while (left <= right)
    {
        int mid = (left + right) / 2; 
        if(num < A[mid])
            right = mid - 1;
        else if(num > A[mid])
            left = mid + 1;
        else {
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    sort(A,A+N);

    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        scanf("%d", &B);
        if(findNumber(B))
            printf("1\n");
        else printf("0\n");
    }
    return 0;
}