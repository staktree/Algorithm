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
