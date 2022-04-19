#include<bits/stdc++.h>

int c=0;
//Display the Array
void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

//Main Quicksort Working
void QuickSort(int a[],int left,int right)
{
	c++;
	int pi,temp,i,j,k,temp2;
	
		if(left<right)
		{
			c++;
			k=(left+right)/2;	c++;
			temp=a[left];	c++;
			a[left]=a[k];	c++;
			a[k]=temp;	c++;
			
			temp2=a[left];	c++;
			i=left+1;	c++;
			j=right;	c++;
			while(i<=j)
			{
				c++;
				while((i<=right) && (a[i] <= temp2))
				{
					c++;
					i++;
				}
				while((j>=left) && (a[j] >temp2))
				{
					c++;
					j--;
				}
				if(i<j)
				{
					c++;
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
			 	temp=a[left];	c++;
				a[left]=a[j];	c++;
				a[j]=temp;	c++;
				QuickSort(a,left,j-1);	c++;
				QuickSort(a,j+1,right); c++;
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
	printf("\n1)Quick Sort\n0)Exit");
	
	printf("\nEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		
		case 1:
			QuickSort(array,0,n-1);
			printf("\nSorted array:\n");
			display(array,n);
			printf("\nCount:");
			printf("\n%d",c);
			printf("\n");
			printf("\n");
			 break;
		case 0:
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
