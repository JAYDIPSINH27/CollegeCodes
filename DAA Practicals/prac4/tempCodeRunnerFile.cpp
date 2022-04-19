#include<bits/stdc++.h>
using namespace std;

struct fknapsack{
    int value,weight;

    fknapsack(int value,int weight){
        this->value=value;
        this->weight=weight;
    }
};

bool cmp(struct fknapsack a,struct fknapsack b)
{
    double r1 = (double) a.value / (double) a.weight;
    double r2 = (double) b.value / (double) b.weight;
    return r1>r2;

}

double FractionalKnapsack(int W,struct fknapsack arr[],int n){

    sort(arr,arr+n,cmp);
    int curWeight=0;
    double finalvalue=0.0;

    for(int i=0;i<n;i++){
        if((curWeight + arr[i].weight) <= W){
            curWeight+=arr[i].weight;
            finalvalue+=arr[i].value;
        }
        else{
            int remain=W-curWeight;
            finalvalue+=arr[i].value*((double)remain / (double)arr[i].weight);
            break;
        }
    }
    return finalvalue;
}




int main(){
    int W=15;
    fknapsack arr[]={{1,2},{2,3},{5,4}};
    // fknapsack arr[]={{10,2},{5,3},{15,5},{7,7},{6,1},{18,4},{3,1}};
    // fknapsack arr[]={{12,4},{10,6},{8,5},{11,7},{14,3},{7,1},{9,6}};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"Maximum Gold dust he can take is ="<<FractionalKnapsack(W,arr,n);
    return 0;
}