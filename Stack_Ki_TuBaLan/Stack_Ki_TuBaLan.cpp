#include<iostream>
#include<string>
#include<stack>
using namespace std;
int Xuly(string expr)
{
	stack<int>  s;
	for(int i=0;i<expr.size();i++)
		if (isdigit(expr[i]))
		{
			int num = expr[i] - '0';
			s.push(num);
		}
		else
		{
			if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
			
			{
				int op1 = s.top(); s.pop();
				int op2 = s.top(); s.pop();
				int res = 0;
				switch (expr[i])
				{
				case '+': {  res = op1 + op2; break; }
				case '-': {  res = op1 - op2; break; }
				case '*': {  res = op1 * op2; break; }
				case '/': {  res = op1 / op2; break; }

				}
				s.push(res);
			}
		}
	return s.top();
}
int main()
{
	string expr;
	getline(cin, expr);

	int kq = Xuly(expr);
	cout << kq;


}