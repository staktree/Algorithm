<<<<<<< HEAD

=======
https://www.acmicpc.net/problem/1037
BOJ 1037번 약수

(1) 접근
1과 자기자신을 제외한 약수가 주어졌을 때 가장 큰 값과 가장 큰 수를 곱하면 N을 구할 수 있다.

(2) 해결
vector의 라이브러리 함수를 사용하여 간단하게 해결했다.
sort 함수를 사용하여 정렬 후 vector.front() * vector.back()을 계산하여 
답을 도출한다.

algorithm 헤더파일을 추가하여 sort 함수를 사용한다.
vector.begin() : 벡터의 맨 처음 주소값
vector.end() : 벡터의 마지막 주소값
vector.front() : 벡터의 맨 처음 값
vector.back() : 벡터의 마지막 값
vector.erase(지우고 싶은 주소) : 해당 주소의 값을 삭제
>>>>>>> d9c1c460a5c6cf270987ec6c0269acf2aff5d318

(3) 소스코드
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector <int> realDivisor;

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        realDivisor.push_back(temp);
    }
    sort(realDivisor.begin(), realDivisor.end());

    cout << realDivisor.front() * realDivisor.back() << endl;
    return 0;
}