#include<bits/stdc++.h>
using namespace std;

struct Golddust{
    int value,weight;

    Golddust(int value,int weight){
        this->value=value;
        this->weight=weight;
    }
};

bool cmp(struct Golddust a,struct Golddust b)
{
    double r1 = (double) a.value / (double) a.weight;
    double r2 = (double) b.value / (double) b.weight;
    return r1>r2;

}

double FractionalKnapsack(int W,struct Golddust arr[],int n){

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
    Golddust arr[]={{4,12},{2,1},{2,2},{1,1},{10,4}};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"Maximum Gold dust he can take is ="<<FractionalKnapsack(W,arr,n);
    return 0;
}