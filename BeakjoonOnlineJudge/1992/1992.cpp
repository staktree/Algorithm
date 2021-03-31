/*
https://www.acmicpc.net/problem/1992
BOJ 1992 쿼드트리

(1) 접근
이전에 풀었던 '색종이 자르기' 문제와 같은 문제이다.
압축할 영상의 맨 처음 값과 다른 모든 값을 비교하여 같다면 처음 값을 그대로 출력하고, 
다르다면 재귀함수를 이용하여 N을 2로 나누고 시작 지점을 지정하여 다시 반복시킨다.
'색종이 자르기 문제'와 다른점은 입력 방식이 문자열이라는 것과 출력 시 (,)을 사용해야하는 경우가 있다는 점이었다.

(2) 해결 
문자열으로 입력을 받기 때문에 이를 파싱하여야 한다.
2중포문으로 x축, y축을 나누었고, y축이 바뀔때마다 해당 줄의 라인을 입력받아 x축 순서대로 넣어주었다. 
출력 시에는 string을 반환하는 재귀함수를 만들어 처음과 끝에 (,)을 각각 붙여서 리턴하도록 했다. 
(1)접근 에서 설명했듯이 한 덩어리가 다른 값을 가지고 있는 지 체크했다. 만약 다른 값을 가지고 있다면 4등분으로 나누어 다시 덩어리별로 다른 값을 가지고 있는지 체크하도록했다. 나눈 덩어리들의 결과에 '(', ')'을 붙여서 리턴받는다. 만약 덩어리의 모든 값이 같다면 그 값을 리턴한다. 
*/
#include <iostream>
#include <string>

using namespace std;

int N;
char video[64][64];
string ans;

string quadTree(int N, int startIndexY, int startIndexX)
{   
    string resultVideo;
    for(int i = startIndexY; i < startIndexY + N; i++)
    {
        for(int j = startIndexX; j < startIndexX + N; j++)
        {
            if(video[startIndexY][startIndexX] != video[i][j])
            {  
                resultVideo += "(";
                resultVideo += quadTree(N / 2, startIndexY, startIndexX); 
                resultVideo += quadTree(N / 2, startIndexY, startIndexX + (N / 2)); 
                resultVideo += quadTree(N / 2, startIndexY+ (N / 2), startIndexX); 
                resultVideo += quadTree(N / 2, startIndexY+ (N / 2), startIndexX + (N / 2)); 
                resultVideo += ")";
                return resultVideo;
            }
        }
    }
    resultVideo = video[startIndexY][startIndexX];
    return resultVideo;
}

int main()
{
    string videoStr;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> videoStr;
        for(int j = 0; j< N; j++)
        {
             video[i][j] = videoStr[j];
        }
    }

    ans = quadTree(N, 0, 0);
    cout << ans << "\n";
}
