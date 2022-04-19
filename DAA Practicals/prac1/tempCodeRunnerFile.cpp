#include<bits/stdc++.h>
using namespace std;
int count1=0;
int search(int *a,int n,int f){
    for(int i=0;i<n;i++)
    {
        count1++;
        if(a[i]==f) return i;
        count1++;
    }
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
    cout<<"Enter element to be searched";
    cin>>f;
    int find=search(a,n,f);
    (find==-1) ? cout<< "Element is not present in array" : cout << "Element is present at index " << find;

    cout<<"\nCount:"<<count1;
    return 0;
}