/*
https://www.acmicpc.net/problem/10828

BOJ 10828번 스택

(1) 접근
벡터를 이용하여 쉽게 풀 수 있는 문제이다.
stack 자료형을 사용할 수도 있다. 

(2) 해결
vector 라이브러리를 활용하여 문제를 해결햇다.
v.push_back(value) : value를 vector의 마지막 인덱스로 삽입합니다.
v.pop() : vector의 마지막 값을 삭제합니다.
v.size() : vector에 저장된 값의 개수를 반환합니다.
v.empty() : vector가 비어있다면 true, 아니면
false를 반환합니다.
v. back() : vector의 마지막 값을 반환합니다.
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N;
string command;
int value;
vector <int> stack;

static map <string, int> m;

void settingCommand()
{
    m["push"] = 0;
    m["pop"] = 1;
    m["size"] = 2;
    m["empty"] = 3;
    m["top"] = 4;
}

void excuteCommand(string comm)
{
    switch (m[comm])
    {
        case 0:
            cin >> value;
            stack.push_back(value);
            break;
        case 1:
            if(stack.empty())
                cout << -1 << endl;
            else
            {
                value = stack.back();
                cout << value << endl;
                stack.pop_back();
            }
            break;
        case 2:
            cout << stack.size() << endl;
            break;
        case 3:
            if(stack.empty())
                cout << 1 << endl;
            else cout << 0 << endl;
            break;
        case 4:
            if(stack.empty())
                cout << -1 << endl;
            else cout << stack.back() << endl; 
            break;
        default:
            return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    settingCommand();
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> command;
        excuteCommand(command);
    }
}   