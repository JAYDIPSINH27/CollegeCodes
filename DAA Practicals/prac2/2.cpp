#include<bits/stdc++.h>
using namespace std;
int count11=0;
void display(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
        cout<<a[i]<<" ";
	}
}
int *BubbleSort(int *arr,int n)
{
	for(int i=0;i<n;i++){
        count11++;
        int swap=0;
        for(int j=0;j<n-1;j++){
            count11++;
            if(arr[j]>arr[j+1]){
                count11++;
                int temp=arr[j];count11++;
                arr[j]=arr[j+1];count11++;
                arr[j+1]=temp;count11++;
                swap++;count11++;
            }
            
        }
        if(swap==0){
                count11++;
                return arr;
            }
    }
    return arr;
	
}

void SelectionSort(int *a,int n)
{
	int i,j,minindex,temp,count1=0;
	for(i=0;i<=n-2;i++)
	{
        count1++;
			minindex=i;
			for(j=i+1;j<=n-1;j++)
			{count1++;
				if(a[j]<a[minindex])
				{
                    count1++;
					minindex=j;count1++;
				}
				
			}
			if(minindex!=i)
			{
                count1++;
				temp=a[i];count1++;
	 			a[i]=a[minindex];count1++;
	 			a[minindex]=temp;count1++;
			}
			
	}
        cout<<"\nSorted array:\n";
		display(a,n);
        cout<<"\nNumber of Instructions are:";
        cout<<count1<<"\n\n";	
}

void InsertionSort(int a[],int n)
{
	int i,j,key,count1=0;
	for(i=1;i<=n-1;i++)
	{count1++;
		key=a[i];count1++;
		j=i-1;count1++;
		while((j>=0) && (a[j]>key))
		{
            count1++;
			a[j+1]=a[j];count1++;
			j=j-1;count1++;
		}
		a[j+1]=key;count1++;
		
	}
    cout<<"\nSorted array:\n";
		display(a,n);
		
        cout<<"\nNumber of Instructions are:";
        cout<<count1<<"\n\n";	
}

int main()
{
	int *array,choice=0,ch,n,i,*a;
	
		
	cout<<"Enter the number of elements:";
    cin>>n;
	array=new int(n);
	cout<<"Enter the elements:";
	for(i=0;i<n;i++)
	{
      cin>>array[i];
	}
	display(array,n);
    cout<<"\n---->Options<----\n";
    cout<<"\n1)Bubble Sort\n2)Selection Sort\n3)Insertion Sort\n4)Exit";
	
    cout<<"\nEnter your choice:";
    cin>>ch;
    choice=ch;
	switch(ch)
	{
		case 1:
			a=BubbleSort(array,n);
            cout<<"\nSorted array:\n";
            display(a,n);
            cout<<"\nNumber of Instructions are:";
            cout<<count11<<"\n\n";
            count11=0;
			 break;
		case 2:
			SelectionSort(array,n);
			 break;
		case 3:
			InsertionSort(array,n);
			 break;
		case 4:
			 exit(1);
		default:
                cout<<"Wrong choice";
				break;
	}

 cout<<"\n\n\t Jaydipsinh Padhiyar(19CE081)";
}
