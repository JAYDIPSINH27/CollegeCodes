#include <bits/stdc++.h>
using namespace std;
int count1=0;

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

int main()
{
    int m, n, p, q, sum = 0;
    cout << "Enter dimension of matrix a (m n):";
    cin >> m >> n;
    cout << "Enter dimension of matrix B (p q):";
    cin >> p >> q;

    if (n == p)
    {
        cout<<"Enter matrix A:\n";
        int **a1 = makeMatrix(m, n);
        cout<<"Enter matrix B:\n";
        int **a2 = makeMatrix(p, q);

        int **a3 = new int *[m];
        for (int i = 0; i < m; i++)
        {
            a3[i] = new int[q];
        }

        for (int i = 0; i < m; i++)
        {
            count1++;
            for (int j = 0; j < q; j++)
            {
                count1++;
                for (int k = 0; k < p; k++)
                {
                    count1++;
                    sum += a1[i][k] * a2[k][j];
                }
                count1++;
                a3[i][j] = sum;
                count1++;
                sum = 0;
                count1++;
            }
        }
        cout<<"Multiplied Matrix:\n";
        printArray(a3, m, q);
    }
    else
        cout << "Can't multiply this two matrices";

    
    cout<<"\n Count:"<<count1;

    return 0;
}