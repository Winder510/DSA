#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int sum = 0;
	
	// sắp xếp các phần tử theo thứ tự giảm dần 
	sort(s.begin(), s.end(), [](char a, char b)
		{
			return a > b;
		});


	for (int i = 0; i < s.length(); i++)
		sum += s[i] - '0';

	if (sum % 3 == 1) {
		bool check = false;	
		for (int i = s.length()-1; i >= 0; i--) {
			if ((s[i] - '0') % 3 == 1) {
				s.erase(i, 1);
				check = true;
				break;
			}
		}
		if (!check) {
			int cnt = 0;
			for (int i = s.length(); i >= 0; i--) {
				cnt++;
				if ((s[i] - '0') % 3 == 2) {
					cnt++;
					s.erase(i, 1);
					if (cnt == 2) break;
				}
			}
		}
	}
	else if(sum % 3 == 2) {
		bool check = false;
		for (int i = s.length() - 1; i >= 0; i--) {
			if ((s[i] - '0') % 3 == 2) {
				s.erase(i, 1);
				check = true;
				break;
			}
		}
		if (!check) {
			int cnt = 0;
			for (int i = s.length(); i >= 0; i--) {
				cnt++;
				if ((s[i] - '0') % 3 == 1) {
					cnt++;
					s.erase(i, 1);
					if (cnt == 2) break;
				}
			}
		}
	}
	cout << s << endl;
}