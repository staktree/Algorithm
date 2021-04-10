/*
https://www.acmicpc.net/problem/11401
BOJ 11401번 이항계수3

(1) 접근
N개 중에서 K개를 뽑는 경우의 수인 '이항계수'를 구하는 문제이다. 
하지만 N의 범위가 4000000까지이기 때문에 
이항계수 nCk = n!/k!(n-k)!의 공식을 이용하여야 제한 시간 1초안에 문제를 해결할 수 있다.
하지만 P = 1000000007으로 나눈 나머지를 출력해야하기 때문에 
n!%P/k!(n-k)!%P로 계산하게되면 분모가 0이 될 수 있어서 이를 바로 계산할 수 없다.

그래서 페르마의 소정리를 사용해야한다. 
페르마의 소정리는 소수 P와 서로소인 수의 P-1승을 P로 나눈 나머지는 무조건 1이라는 정리이다.
이를 사용하면 1/k!(n-k)!%P를 k!(n-k)!의 제곱수 % P로 표현할 수 있다.  

(1/k!(n-k)!)의 P-1승을 P로 나눈다면 1이 될 것이다.
이를 
(1/k!(n-k)!)(1/k!(n-k)!)의 P-2승 % P = 1
으로 표현할 수 있다. 이를 다시 정리하면 
(1/k!(n-k)!) % P =  (1/k!(n-k)!)의 P-2승  % P이다. 

이항계수 공식을 이 식을 활용하여 표현한다면
n!%P * k!(n-k)의 P-2승 %P이 된다.

(2) 해결
제한 시간 1초안에 문제를 해결하기 위해서는 O(N^2)이 되서는 안된다.
이를 위해서 팩토리얼은 DP를 사용하여 O(N)의 시간복잡도로 전처리한다.
N과 K가 입력되면 K!(N-K)!를 미리 계산해놓은 팩토리얼 값을 이용하여 계산하고
P-2승을 계산해야한다. 이는 분할정복을 사용하면 O(log(P))의 시간복잡도로 계산할 수 있다. 마지막으로 N!를 미리 계산해놓은 팩토리얼 값에서 읽어와 곱셈하면 정답이 출력된다. 
*/
#include <cstdio>

using namespace std;

int N, K;
long long int fac[4000001];
long long int P = 1000000007; 

long long int power(long long int num, long long int powerOf)
{
    if(powerOf == 1)
        return num  % P;
    else if(powerOf % 2 == 0)
        return power((num * num) % P, powerOf / 2) % P;
    else return (num * power(num, powerOf - 1)) % P;
}

int main()
{
    fac[0] = 1;
    fac[1] = 1;
    for(int i = 2; i < 4000001; i++)
    {
        fac[i] = (fac[i - 1] * i) % P;
    }

    scanf("%d %d", &N, &K);
    long long int KfacNminusKfac = (fac[K] * fac[N - K]) % P;
    long long int KfacNminusKfacPower = power(KfacNminusKfac, P - 2);
    long long int ans = (fac[N] * KfacNminusKfacPower) % P; 
    printf("%lld", ans);
}