#include<bits/stdc++.h>
using namespace std;
int count1=0;

int *BubbleSort(int *arr,int n){

    for(int i=0;i<n;i++){
        count1++;
        int swap=0;
        for(int j=0;j<n-1;j++){
            count1++;
            if(arr[j]>arr[j+1]){
                count1++;
                int temp=arr[j];count1++;
                arr[j]=arr[j+1];count1++;
                arr[j+1]=temp;count1++;
                swap++;count1++;
            }
            
        }
        if(swap==0){
                count1++;
                return arr;
            }
            count1++;
    }
    return arr;
}

void PrintArray(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){

    int n;
    cout<<"Enter Number of element:";
    cin>>n;
    int *arr=new int(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    arr=BubbleSort(arr,n);
    PrintArray(arr,n);
    cout<<"\n Count:"<<count1;


    return 0;
}