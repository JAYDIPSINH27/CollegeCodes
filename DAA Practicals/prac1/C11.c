#include <stdio.h>
#include <stdlib.h>

// #define SIZE 10
// #define SIZE 15
//  #define SIZE 20
//  #define SIZE 25
 #define SIZE 30

int count1=0;
void swap(int *a, int *b);
void sort(int *a,const int size);

int main()
{
    // int a[SIZE] = {3, 4 , 6, 1, 5, 8, 7, 9, 0, 2};
    // int a[SIZE] = {0,1,2,3,4,5,6,7,8,9};
    // int a[SIZE] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    // int a[SIZE] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    // int a[SIZE] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
    // int a[SIZE] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29};
    // int a[SIZE] = {29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    // int a[SIZE] = {24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    // int a[SIZE] = {19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    // int a[SIZE] = {14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    // int a[SIZE] = {9,8,7,6,5,4,3,2,1,0};
    //  int a[SIZE] = {9,8,7,6,5,4,3,2,1,0};
    // int a[SIZE] = {3, 4 , 6, 1, 5, 8, 7, 9, 0, 2};
    // int a[SIZE] = {0,3, 4 , 6, 1, 5, 8, 7, 9, 0, 2, 10,12,47,35};
    // int a[SIZE] = {0,3, 4 , 6, 1, 5, 8, 7, 9, 0, 2, 10,12,47,35,34,33,56,58,60};
    // int a[SIZE] = {0,3, 4 , 6, 1, 5, 8, 7, 9, 0, 2, 10,12,47,3534,33,56,58,60,63,65,67,69,70};
    int a[SIZE] = {0,3, 4 , 6, 1, 5, 8, 7, 9, 0, 2, 10,12,47,3534,33,56,58,60,63,65,67,69,70,74,75,89,90};

    sort(a, SIZE);

    int i;
     printf("Array before sorting:\n");
    //  printf("3 4 6 1 5 8 7 9 0 2 \n");
    //  printf("0 1 2 3 4 5 6 7 8 9\n");
     printf("9 8 7 6 5 4 3 2 1 0 \n");
   // display(a,SIZE);
printf("Array After sorting:\n");
    for(i = 0; i < SIZE; i++)
    {

        printf("%d ",a[i]);
    }

    printf("\n Count:: %d",count1);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int *a,const int size)
{

    int i,j, k;
    for (i = 1; i < size; ++i)
    {
        k = a[i]; count1++;
        j = i - 1;  count1++;
        while ((j >= 0) && (k < a[j]))
        {
            count1++;
            a[j + 1] = a[j];
            count1++;
            --j;
            count1++;
        }
        count1++;
        a[j + 1] = k;
    }
}
