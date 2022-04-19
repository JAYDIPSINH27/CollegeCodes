#include<bits/stdc++.h>

using namespace std;


//Utility function that returns minimum number.

int min(int a,int b){
    return (a<b)?a:b;
}


int BinomialCoeff(int n,int k){
    int c[n+1][k+1];
    int i,j;

    //dp table for overlapping subproblem
    for(i=0;i<=n;i++){
        for(j=0;j<=min(i,k);j++){
            if(j==0||j==i){
                c[i][j]=1;
            }
            else
            c[i][j]=c[i-1][j-1] + c[i-1][j];
        }
    }

    return c[n][k];
}

int main(){

    //For dynamic

    // int n,k;
    // cout<<"\nEnter value of N:";cin>>n;
    // cout<<"\nEnter value of K:";cin>>k;

    // cout<<"\nValue of C["<<n<<"]["<<k<<"] is "<<BinomialCoeff(n,k);

    //Static test cases
    const char separator = ' ';
    const int nameWidth = 15;
    const int numWidth = 15;
    int x[3] = {5,11,12};
    int y[3]={2,6,5};
   int n=sizeof(x)/sizeof(x[0]);

   cout<<"Answer is:\n\n";

    cout << left << setw(nameWidth) << setfill(separator) << "I";
     cout << left << setw(nameWidth) << setfill(separator) << "N";
     cout << left << setw(nameWidth) << setfill(separator) << "K";
     cout << left << setw(nameWidth) << setfill(separator) << "C[N][K]"<<"\n";

    for(int i=0;i<n;i++){
        cout << left << setw(nameWidth) << setfill(separator) << i;
     cout << left << setw(nameWidth) << setfill(separator) << x[i];
     cout << left << setw(nameWidth) << setfill(separator) << y[i];
     cout << left << setw(nameWidth) << setfill(separator) << BinomialCoeff(x[i],y[i])<<"\n";
    }

    return 0;
}