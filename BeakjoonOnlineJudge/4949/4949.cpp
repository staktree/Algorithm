/*
https://www.acmicpc.net/problem/4949
BOJ 4949번 균형잡힌 세상

(1) 접근
괄호의 짝이 맞고, 괄호의 순서가 맞는지 체크하는 문제이다.
스택을 이용하여 문제를 해결할 수 있다.
문제를 잘못 읽어서 한참을 해메었다. 입력조건에서 '{', '}' 이 없다는 것과 마지막으로 '.'이 입력되었을 때도 yes를 출력하는 것으로 출력 조건을 이해하여 문제 해결 자체에는 문제가 없었음에도 시간을 너무 소비하게되었다. 
다음부터는 문제를 확실하게 읽도록 하자!

(2) 해결
입력받은 문자열에서 괄호만 따로 저장한다.
괄호들을 for 반목문을 이용하여 하나하나 비교하며 열린 괄호 '(','['라면 스택에 푸시한다. 만약 닫힌 괄호가 등장했다면 스택의 탑과 비교하여 짝이 맞는지 체크한다. 예를들어 ')'가 등장했다면 스택의 탑에 '('이 있어야한다. '('이 있다면 pop을 하고,  다른 괄호가 있다면 false를 리턴한다. 
또한 열린 괄호 또는 닫힌 괄호 더 많은 경우를 체크하여 false를 리턴한다.  
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string Text = "";
string braket = "";


bool check()
{
        // 괄호 조건을 체크하여 조건이 만족하는지 bool 변수로 리턴하는 함수
	vector <char> stack;

	if (braket.length() == 0) // 괄호가 없는 경우도 짝이 맞는 것으로 한다.
		return true;
	
	for (int i = 0; i < braket.length(); i++)
	{
		if (braket[i] == '(' || braket[i] == '[') // 열린 괄호라면 push
			stack.push_back(braket[i]);
		else if (stack.size() == 0) // 닫힌 괄호가 더 많은 경우
			return false;
		else if (stack.back() == '(' && braket[i] != ')') // 짝이 맞지 않는 경우1
			return false;
		else if (stack.back() == '[' && braket[i] != ']') // 짝이 맞지 않는 경우2
			return false;
		else stack.pop_back(); // 짝이 맞는다면 pop
	}
	
	if (stack.size() > 0) // 열린 괄호가 많은 경우
		return false;

	return true;
}

int main()
{
	while (true)
	{
		getline(cin, Text);

		if (Text == ".")
			break;

                // 입력 조건의 괄호만 따로 저장한다.
		for (int i = 0; i < Text.length(); i++)
		{
			if (Text[i] == '(' || Text[i] == '['
				|| Text[i] == ')' || Text[i] == ']')
				braket += Text[i];
		}

		if (check())
			cout << "yes" << endl;
		else cout << "no" << endl;

		braket = "";

	}
}