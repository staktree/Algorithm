/*
https://www.acmicpc.net/problem/5430
BOJ 5430번 AC

(1) 접근
문제에서 주어진 명령어를 입력받고, 명령어를 수행한 결과를 출력한 문제이다.
명령어는 배열의 가장 앞의 값을 삭제하거나, 배열의 순서를 뒤집는 것이 있다.
문제 특성 상 큐 또는 덱을 이용하면 쉽게 해결할 수 있을 것이고 보고 문제를 해결했다.

(2) 해결
문제를 읽자마자 명령어를 입력받을 때마다 순서를 뒤집거나 가장 앞의 값을 삭제하는 것을 직접 구현하여 문제해결을 했다. 하지만 문제 해결 시간이 1초 미만이므로 시간 초과가 발생했다. 배열의 순서를 뒤집는 명령어를 입력받는 경우 바로 순서를 변경하는 것이 아니었다. 
이 명령어를 입력받으면 count를 1 추가했다. 그 count가 홀수인지 짝수인지를 판단하여 
홀수이면 순서가 뒤집어진 상태로, 짝수이면 입력받은 그대로의 상태로 보았다. 순서가 뒤집어진 상태에서 삭제 명령이 입력되면 가장 뒤의 값을 삭제하여 실제로 순서를 뒤집지 않고도 
수행할 수 있다. 이를 위해서 배열을 deque로 구현했다. 만약 삭제 시 이 deque가 비어있다면 error를 출력하고 남은 연산을 마무리한다. 마지막으로 출력 시 뒤집는 명령어의 개수count를 한번 더 체크하여 짝수라면 순서 그대로 출력하고, 홀수라면 거꾸로 출력한다.

문제를 해결하면서 필요한 연산들을 함수로 나누고, 이 함수에서 for문을 사용하니까 시간초과에 걸리는 경우가 많았다. 시간이 촉박한 경우 for문이 최소화될 수 있도록 노력해야겠다.
*/
#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

deque <int> numberPasser(string numbers)
{
    string temp = "";
    deque <int> q;
    for(int i = 1; i < numbers.length(); i++)
    {   
        if((numbers[i] == ',' || numbers[i] == ']') && temp != "") 
        {
            int num = stoi(temp);
            q.push_back(num);
            temp = "";
        }
        else temp += numbers[i];
    }
    return q;
}

int main()
{
    cin.tie(0);
	cin.sync_with_stdio(false);

    int T;
    int N;

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        string commands;
        string numbers;
        int Rcount = 0;
        bool isError = false;
        deque <int> numArray;

        cin >> commands;
        cin >> N;
        cin >> numbers;

        numArray = numberPasser(numbers);

        for (int j = 0; j < commands.length(); j++)
        {
            if (commands[j] == 'R')
            {
                Rcount++;
            }
            else if (commands[j] == 'D')
            {
                if (numArray.empty())
                {
                    isError = true;
                    cout << "error\n";
                    break;
                }
                else if (Rcount % 2 == 0)
                    numArray.pop_front();
                else if (Rcount % 2 == 1)
                    numArray.pop_back();
            }
        }

        if(!isError)
        {
            cout << "[";
            if (Rcount % 2 == 0)
            {
                for (int j = 0; j < numArray.size(); j++)
                {
                    cout << numArray[j];
                    if (j < numArray.size() - 1)
                        cout << ",";
                }
            }
            else
            {
                for (int j = numArray.size() - 1; j >= 0; j--)
                {
                    cout << numArray[j];
                    if (j > 0)
                        cout << ",";
                }
            }
            cout << "]\n";
        }
    }
    
    return 0;
}
