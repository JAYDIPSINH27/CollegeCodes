#include<bits/stdc++.h>
using namespace std;

int c1=0;

int assemblyLineScheduling(int n,vector<int> entry,vector<int> exit,vector<vector<int> > processing,vector<vector<int> > transfer){

    vector<vector<int> > dp(2,vector<int>(n+1));
    int i;
    
    //Initialization and entry to first station
    dp[0][0]=entry[0]+processing[0][0];
    dp[1][0]=entry[1]+processing[1][0];

    for(i=1;i<n;i++){
        //for being on station i of assembly line 1
        dp[0][i]=min(dp[0][i-1],dp[1][i-1]+transfer[1][i-1])+processing[0][i];
    
        //for being on station i of assembly line 2
        dp[1][i]=min(dp[1][i-1],dp[0][i-1]+transfer[0][i-1])+processing[1][i];
    }

    //exiting from the last station
    dp[0][n]=dp[0][n-1]+exit[0];
    dp[1][n]=dp[1][n-1]+exit[1];

    return min(dp[0][n],dp[1][n]);

}

int main(){

    int i,n;
    vector<int> entry(2),exit(2);

    cout<<"Enter the number of stations:";
    cin>>n;

    vector<vector<int> > processing(2,vector<int>(n));
    vector<vector<int> >transfer(2,vector<int> (n-1));

    cout<<"Enter the entry time for assembly line 1 & 2:\n";
    cin>>entry[0]>>entry[1];

    cout<<"Enter the exit time for assembly line 1 & 2:\n";
    cin>>exit[0]>>exit[1];

    cout<<"Enter the processing time at all station of assembly line 1:\n";
    for(i=0;i<n;i++)
        cin>>processing[0][i];

    cout<<"Enter the processing time at all station of assembly line 2:\n";
    for(i=0;i<n;i++)
        cin>>processing[1][i];
    
    cout<<"Enter the transfer time from each station of assembly line 1 to next station of assembly line 2:\n";
    for(i=0;i<n-1;i++)
        cin>>transfer[0][i];

    cout<<"Enter the transfer time from each station of assembly line 2 to next station of assembly line 1:\n";
    for(i=0;i<n-1;i++)
        cin>>transfer[1][i];

    
    cout<<"The minimum time required to get all the jobs done is: "
        <<assemblyLineScheduling(n,entry,exit,processing,transfer)<<"\n";
    

    return 0;
}

/*
test case
3
3 1
3 3
8 4 6
5 7 5
2 2
1 3
*/