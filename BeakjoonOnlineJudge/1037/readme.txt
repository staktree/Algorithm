

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