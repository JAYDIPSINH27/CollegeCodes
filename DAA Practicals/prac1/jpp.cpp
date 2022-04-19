#include<iostream>
using namespace std;
int main()
{
    int n,ele,count=0,Inst=0;
    cout<<"Enter the Size of array: ";
    cin>>n;

    int *arr = new int(n);
    cout<<endl;
    cout<<"Enter the elements of array: "<<endl;

    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<endl;
    cout<<"Enter the element you want to search: ";
    cin>>ele;
    cout<<endl;


    // Linear Search


    cout<<"Linear Search Result is: "<<endl;

    for(int i=0;i<n;i++)
    {
        Inst++;
        if(arr[i]==ele)
        {
            cout<<"The element search at index number: "<<i;
            break;
        }
        count++;
    }
    if(count>n)
    {
        cout<<"Element is not found"<<endl;
    }

    cout<<endl;
    cout<<"Number of Instruction are: "<<Inst<<endl;


    // Binary Search

    cout<<endl;
    cout<<"Binary Search Result is: "<<endl;

    int min=0, max, mid, Inst1=0;
    max=n-1;

    while(min<=max)
    {
        mid=(min+max)/2;
        if(arr[mid] < ele)
        {
            Inst1++;
            min=mid+1;
        }
        else if(arr[mid] > ele)
        {
            Inst1++;
            max=mid-1;
        }
        else
        {
            Inst1++;
cout<<"The element search at index number: "<<mid<<endl;
            break;
        }
    }
    if(min>max)
    {
        printf("The number is not the element of array\n");
    }
    cout<<"Number of Instruction are: "<<Inst1<<endl;
}
