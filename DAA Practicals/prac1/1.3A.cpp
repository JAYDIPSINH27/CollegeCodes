#include <bits/stdc++.h>
using namespace std;
int **makeMatrix(int m, int n)
{
    int **a = new int *[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    return a;
}
void printArray(int **a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// void sumArray(int **a,int **b,int m,int n){
//     int **c=new int*[m],count1=0;
//     for(int i=0;i<m;i++){
//         c[i]=new int[n];count1++;
//     }

//     for(int i=0;i<m;i++){
//         count1++;
//         for(int j=0;j<n;j++){
//             count1++;
//             c[i][j]=a[i][j]+b[i][j];
//             count1++;
//         }
//     }
//     cout<<"C:"<<endl;
//     printArray(c,m,n);
//     cout<<"\nCount:"<<count1;
// }

int main()
{
    int n, m, p, q;
    cout << "Enter dimension of Matrix A(m n):";
    cin >> m >> n;
    cout << "Enter dimension of Matrix B(m n):";
    cin >> p >> q;
    if (m == p && n == q)
    {
        cout << "Enter A:" << endl;
        int **a1 = makeMatrix(m, n);
        cout << "Enter B:" << endl;
        int **a2 = makeMatrix(p, q);
        // sumArray(a1,a2,m,n);

        int **c = new int *[m], count1 = 0;
        for (int i = 0; i < m; i++)
        {
            c[i] = new int[n];
            count1++;
        }

        for (int i = 0; i < m; i++)
        {
            count1++;
            for (int j = 0; j < n; j++)
            {
                count1++;
                c[i][j] = a1[i][j] + a2[i][j];
                count1++;
            }
        }
        cout << "C:" << endl;
        printArray(c, m, n);
        cout << "\nCount:" << count1;
    }
    else
        cout << "Can't sum this two Matrices";
    return 0;
}