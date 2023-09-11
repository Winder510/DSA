#include<iostream>
#include<map>
using namespace std;

int main()
{
	// map<key,value>: các key đc tự dộng sx tăng dần
	map<int, int> mp;
	mp[1] = 2; //<1,2> 
	mp[2] = 3;//<2,3>
	mp.insert({ 3, 4 });//<3,4> <=>mp[3]=4
	// cac key se la duy nhat
	//cout << mp.size() << endl;
	mp[1] = 3;// thay <1,2> bằng <1,3>
	//cout << mp.size();


	// duyet
	for (pair<int, int> x : mp)
	{
		cout << x.first << " " << x.second;
		cout << endl;
	}
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		cout << (*it).first << " " << (*it).second;
		cout << endl;
	
	}
	for (auto it : mp)
	{
		cout << it.first << " " << it.second;
		cout << endl;
	}



	// tim kiem (key): find count như set
	if (mp.find(4) != mp.end())
	{
		cout << "found";
	}
	else cout << "Not found";


	// xoa: erase(key)
	mp.erase(1);
	cout << endl;
	for (auto it : mp)
	{
		cout << it.first << " " << it.second;
		cout << endl;
	}



	cout << "-------------------------------------^^-----------------------------------"<<endl;
	// BAI TOAN: Dem so lan xuat hien cua cac phan tu trong mang
	int a[100] = { 1,2,4,3,6,9,-5,3,5,2,5,1,9 }; // 13
	map<int, int> mpp;
	for (int i = 0; i < 13; i++)
		mpp[a[i]]++;
	for (auto it : mpp)
		cout << it.first << " " << it.second << endl;

	// dem cac ki tu trung nhau
	cout << "------------------------------------------------------------------------" << endl;
	map<string, int> m;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		m[s]++;
	}
	for (auto it : m)
		cout << it.first << " " << it.second << endl;
}