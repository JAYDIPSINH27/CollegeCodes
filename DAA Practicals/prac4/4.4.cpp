/*
In a conference, N people from a company XYZ are present to attend maximum number of presentations. Each
presentation is scheduled between 8:00 and 8:00. Here the
second 8:00 means 8:00 pm. Our task is to assign people
to presentations such that the number of unique
presentations attended by XYZ as a company is
maximized. Input Format Input is provided in the form a
file (taken as command line argument). The first line
contains N i.e # of people. Second line contains M i.e # of
presentation on that day. M lines follow each containing
start and end time of presentation. Time will be in format
of HH:MM.
Sample Input#01
2
5
09:00 08:00
08:00 12:00
12:00 08:00
08:00 08:00
08:00 08:00 Sample
Output#01 3 Explanation#01 One person can cover the 8-
12 presentation and the 12-8 presentation. The other
person can cover one of the all-day presentations.
*/

#include<bits/stdc++.h>
using namespace std;

struct node
{
	int s;
	int e;
};

bool comp(node a, node b)
{
	return (a.e < b.e);
}



int main()
{

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif


	int n;
	//scanf("%d",&n);
	cin >> n;
	int p;
	//scanf("%d",&p);
	cin >> p;
	vector<int> v[n];
	vector<node> v2;
	for (int i = 0; i < p; i++)
	{
		string str;
		cin >> str; //09:00
		//cout<<"hi"<<endl;
		char h1, h2, m1, m2;
		//cin>>h1>>h2;
		h1 = str[0];        //"0"
		h2 = str[1];        //"9"
		int t = 0;
		t = t * 10 + h1 - '0'; //0
		t = t * 10 + h2 - '0'; //9
		//cout<<"t: "<<t<<endl;
		int s = 0;
		if (t >= 8)
		{
			s += (t - 8) * 60; //60
		}
		else
		{
			s += (t + 4) * 60;
		}
		char z, z2;
		//cin>>z;
		//cin>>m1>>m2;
		m1 = str[3];//"0"
		m2 = str[4];//"0"
		t = 0;
		t = t * 10 + m1 - '0';//0
		t = t * 10 + m2 - '0';//0
		s += t;//60

		cin >> str;
		h1 = str[0];//0
		h2 = str[1];//8
		m1 = str[3];//0
		m2 = str[4];//0
		//cin>>z;
		//cin>>h1>>h2>>z>>m1>>m2;


		t = 0;
		t = t * 10 + h1 - '0';//0
		t = t * 10 + h2 - '0';//8
		//cout<<"h1: "<<h1<<" "<<h2<<" "<<t<<endl;
		int e = 0;
		if (t > 8)
		{
			e += (t - 8) * 60;
		}
		else
		{
			e += (t + 4) * 60;//720
		}


		//cin>>z;
		//cin>>m1>>m2;
		int t2 = 0;
		t2 = t2 * 10 + m1 - '0';//0
		t2 = t2 * 10 + m2 - '0';//0

		if (t == 8 && t2 > 0)
		{
			e = 0;
			e += (t - 8) * 60;
		}
		e += t2;//720
		node temp;
		temp.s = s;
		temp.e = e;
		v2.push_back(temp);
		//cout<<s<<" "<<e<<endl;

	}

	sort(v2.begin(), v2.end(), comp);
	for (int i = 0; i < n; i++)
	{
		v[i].push_back(0);
	}

	for (int i = 0; i < p; i++)
	{
		int f = 0;
		int max = -1;
		int ind = -1;
		for (int j = 0; j < n; j++)
		{
			if (v2[i].s >= v[j][v[j].size() - 1] && v[j][v[j].size() - 1] > max)
			{
				max  = v[j][v[j].size() - 1];
				ind = j;
			}
		}
		if (ind != -1)
			v[ind].push_back(v2[i].e);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = ans + v[i].size() - 1;
	}
	//int ans = func(v2,v,n,p,0);
	cout << ans << endl;
	//cin>>n;
	return 0;
}

