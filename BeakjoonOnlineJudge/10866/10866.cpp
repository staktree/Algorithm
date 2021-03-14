/*
https://www.acmicpc.net/problem/10866
BOJ 10866번 덱

(1) 접근
덱 관련 명령어를 입력받으면 명령어에 맞게 출력하는 문제이다. 
덱은 스택과 큐의 장점을 합친 자료구조이고, 사용자가 원하는 순서로 입력과 출력을 할 수 있다.

(2) 해결
C++의 <deque> stl 컨테이너를 활용하여 구현하였다.
명령어를 입력받으면 이를 int형으로 맵핑하여 switch문을 동작시켜 해당 명령어에 맞는 동작을 수행하도록 한다.
*/
#include <deque>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int N;
deque <int> d;
map <string, int> command;

void settingCommand()
{
    command["push_front"] = 1;
    command["push_back"] = 2;
    command["pop_front"] = 3;
    command["pop_back"] = 4;
    command["size"] = 5;
    command["empty"] = 6;
    command["front"] = 7;
    command["back"] = 8;
}

void excuteCommand(string c)
{
    int X;

    switch (command[c])
        {
        case 1:
            cin >> X;
            d.push_front(X);
            break;
        case 2:
            cin >> X;
            d.push_back(X);
            break;
        case 3:
            if(d.size() > 0)
            {
                cout << d.front() << "\n";
                d.pop_front();
            }
            else cout << -1 << "\n";
            break;
        case 4:
            if(d.size() > 0)
            {
                cout << d.back() << "\n";;
                d.pop_back();
            }
            else cout << -1 << "\n";
            break;
        case 5:
            cout << d.size() << "\n";
            break;
        case 6:
            if(d.empty())
                cout << 1 << "\n";
            else cout << 0 << "\n";
            break;
        case 7:
            if(d.size() > 0)
                cout << d.front() << "\n";
            else cout << -1 << "\n";
            break;
        case 8:
             if(d.size() > 0)
                cout << d.back() << "\n";
            else cout << -1 << "\n";
            break;
        default:
            break;
        }
}

int main()
{
    cin.tie(0);
	cin.sync_with_stdio(false);

    string c;
    settingCommand();

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> c;
        excuteCommand(c);
    }

}
