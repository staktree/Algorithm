/*
https://www.acmicpc.net/problem/3036

BOJ 3036번 : 링

(1) 접근
첫번째 원이 한 바퀴 회전할 때마다 인접한 원이 얼마나 회전 하는지를 파악하는 문제이다.
인접한 두 원의 비율만큼 인접한 원이 회전하게된다.

(2) 해결
인접한 두 원의 최대공약수를 이용하여 비율을 구하면 된다. 
비율을 구한 후 앞의 원의 회전 수만큼 곱하면 된다. 
이는 첫 번째 원과 n 번째  원의 비율과 같아지므로 결국 첫 번째원과 n 번쨰 원의 최대공약수를 구하여 비율을 구하면 된다.
*/

#pragma warning(disable: 4996)
#include <iostream>

using namespace std;

int N;
int circle[101];

int GCD(int a, int b)
{
    if(b > a)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    return (a % b == 0) ? b : GCD(b, a % b);
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> circle[i];
    }

    for(int i = 1; i < N; i++)
    {
        int nowGDC = GCD(circle[0], circle[i]);
        cout << circle[0]/nowGDC << "/" << circle[i]/nowGDC << endl;
    }
}
