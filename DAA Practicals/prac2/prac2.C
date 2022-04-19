#include<stdio.h>
#include<stdlib.h>
int p=0,c=0;
void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
void BubbleSort(int a[],int n)
{
	int i,j=0,comparision=1,temp,exch=0,l=n;
	
	for(i=0;i<=n-2;i++)
	{
		exch=0;
	 for(j=0;j<=l-2;j++)
	 {
	 	if(a[j]>a[j+1])
	 	{
	 		temp=a[j];
	 		a[j]=a[j+1];
	 		a[j+1]=temp;
	 		exch++;
 		}
 		comparision++;
	 }
	 if(exch==0)
	 {
	 	printf("\nSorted array:\n");
		display(a,n);
		printf("\nNumber of Passes are:");
		printf("\n%d",i+1);
		printf("\nNumber of Comparisions are:");
		printf("\n%d",comparision);
		printf("\n");
		printf("\n");
		break;
	 }
	 else
	 l=l-1;
	}
	
}

void SelectionSort(int a[],int n)
{
	int i,j,minindex,temp,comparision=0;
	for(i=0;i<=n-2;i++)
	{
			minindex=i;
			for(j=i+1;j<=n-1;j++)
			{
				if(a[j]<a[minindex])
				{
					minindex=j;
				}
				comparision++;
			}
			if(minindex!=i)
			{
				temp=a[i];
	 			a[i]=a[minindex];
	 			a[minindex]=temp;
			}
			
	}
		printf("\nSorted array:\n");
		display(a,n);
		printf("\nNumber of Passes are:");
		printf("\n%d",i+1);
		printf("\nNumber of Comparisions are:");
		printf("\n%d",comparision);
		printf("\n");
		printf("\n");	
}

void InsertionSort(int a[],int n)
{
	int i,j,key,comp=0;
	for(i=1;i<=n-1;i++)
	{
		key=a[i];
		j=i-1;
		while((j>=0) && (a[j]>key))
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
		comp++;
	}
	printf("\nSorted array:\n");
		display(a,n);
		printf("\nNumber of Passes are:");
		printf("\n%d",i+1);
		printf("\nNumber of Comparisions are:");
		printf("\n%d",comp);
		printf("\n");
		printf("\n");	
}
void QuickSort(int a[],int left,int right)
{
	int pi,temp,i,j,k,temp2;
	p++;
		if(left<right)
		{
			k=(left+right)/2;
			temp=a[left];
			a[left]=a[k];
			a[k]=temp;
			
			temp2=a[left];
			i=left+1;
			j=right;
			while(i<=j)
			{
				while((i<=right) && (a[i] <= temp2))
				{
					i++;
				}
				while((j>=left) && (a[j] >temp2))
				{
					j--;
				}
				if(i<j)
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
				c++;
			}
			 	temp=a[left];
				a[left]=a[j];
				a[j]=temp;
				QuickSort(a,left,j-1);
				QuickSort(a,j+1,right);
		}	
}
int main()
{
	int *array,choice,n,i,cont;
	do{
		
	printf("Enter the number of elements:");
	scanf("%d",&n);
	array=(int*)malloc(n*sizeof(int));
	printf("Enter the elements:");
	for(i=0;i<n;i++)
	{
  	scanf("%d,",array+i);
	}
	printf("\nEntered elements:\n");
	display(array,n);
	printf("\n---->Options<----\n");
	printf("\n1)Bubble Sort\n2)Selection Sort\n3)Insertion Sort\n4)Quick Sort\n5)Exit");
	
	printf("\nEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			BubbleSort(array,n);
			 break;
		case 2:
			SelectionSort(array,n);
			 break;
		case 3:
			InsertionSort(array,n);
			 break;
		case 4:
			QuickSort(array,0,n-1);
			printf("\nSorted array:\n");
			display(array,n);
			printf("\nNumber of Passes are:");
			printf("\n%d",p);
			printf("\nNumber of Comparisions are:");
			printf("\n%d",c);
			printf("\n");
			printf("\n");
			 break;
		case 5:
			 exit(1);
		default:
				printf("Wrong choice");	
				break;
	}
	printf("\n Want to continue?( 1(yes) || 0(no) ):");
	scanf("%d",&cont);
 }while(cont!=0);
 printf("\n\n\t Jaydipsinh Padhiyar(19CE081)");
}
