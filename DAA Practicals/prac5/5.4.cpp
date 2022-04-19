#include<bits/stdc++.h>
using namespace std;

string lcsubsequence(string a, string b)
{
	int n=a.size(),m=b.size();
	int matrix[n+1][m+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			matrix[i][j]=0;	
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0 || j==0)
			{
				matrix[i][j]=0;
			}
			else if(a[i-1]==b[j-1])
			{
				matrix[i][j]=matrix[i-1][j-1]+1;
			}
			else
			{
				matrix[i][j]=max(matrix[i-1][j],matrix[i][j-1]);
			}
		}
	}
	// to print table

	cout<<"\n   x ";
	for(int i=0;i<m;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	cout<<"y  ";
	for(int j=0;j<=m;j++)
	{
		cout<<matrix[0][j]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<a[i-1]<<"  ";
		for(int j=0;j<=m;j++)
		{
			cout<<matrix[i][j]<<" ";	
		}
		cout<<endl;
	}
	cout<<"\n\nlongest Common Subsequence's Length : "<<matrix[n][m]<<endl;
	
	int vrc=n,hrc=m;
	string ans;
	while(vrc>0|| hrc>0)
	{
		if(matrix[vrc-1][hrc]==matrix[vrc][hrc-1] && matrix[vrc][hrc-1]==matrix[vrc][hrc])
		{
			vrc--;
		}
		else if(matrix[vrc][hrc-1]==matrix[vrc][hrc])
		{
			hrc--;
		}
		else if(matrix[vrc-1][hrc]==matrix[vrc][hrc])
		{
			vrc--;
		}
		else
		{
			ans=a[vrc-1]+ans;
			//cout<<vrc<<" ";
			vrc--;
			hrc--;
		}
	}
	// cout<<"longest Common Subsequence : "<<ans<<"\n\n";
	return ans;
}

int main(){
	// string s1="Classical",s2="Musical";
	//Dynamic
	// cout<<"Enter string 1 : ";
	// cin>>s1;
	// cout<<"Enter string 2 : ";
	// cin>>s2;
	// cout<<endl;
	// lcsubsequence(s1,s2);
	// lcsubsequence(s2,s1);

	//Static test cases
    const char separator = ' ';
    const int nameWidth = 15;
    const int numWidth = 15;
    string s1[3] = {"ABCDAB","EXPONENTIAL","LOGARITHM"};
    string s2[3]={"BDCABA","POLYNOMIAL","ALGORITHM"};
	int n=3;
   cout<<"Answer is:\n\n";

    cout << left << setw(nameWidth) << setfill(separator) << "I";
     cout << left << setw(nameWidth) << setfill(separator) << "N";
     cout << left << setw(nameWidth) << setfill(separator) << "K";
     cout << left << setw(nameWidth) << setfill(separator) << "LCS"<<"\n";

    for(int i=0;i<n;i++){
        cout << left << setw(nameWidth) << setfill(separator) << i;
     cout << left << setw(nameWidth) << setfill(separator) << s1[i];
     cout << left << setw(nameWidth) << setfill(separator) << s2[i];
     cout << left << setw(nameWidth) << setfill(separator)<< lcsubsequence(s1[i],s2[i])<<"\n";
	}
	return 0;
}
