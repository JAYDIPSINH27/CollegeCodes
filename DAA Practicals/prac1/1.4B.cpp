#include<bits/stdc++.h>
using namespace std;
int count1=0;
int Bsearch(int *a,int l,int r,int f){
    while(l<=r){
        count1++;

        int m=(l+r)/2; count1++;

        if(a[m]==f){
             count1++;
            return m; 
        } 
        

        if(a[m]<f){
             count1++;
            l=m+1;
        } 
        
        else{
             count1++;
            r=m-1;
        } 
    }
     count1++;
      return -1;  
}
int main(){
    int n,f;
    cout<<"Enter the elements number:";
    cin>>n;
    int *a=new int(n);
    cout<<"Enter Elements:";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter element to be searched:";
    cin>>f;
    int find=Bsearch(a,0,n-1,f);
    (find==-1) ? cout<< "Element is not present in array" : cout << "Element is present at index " << find;
    cout<<"\nCount:"<<count1;
    return 0;
}