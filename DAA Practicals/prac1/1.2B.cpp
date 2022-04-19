#include <bits/stdc++.h>
using namespace std;
int count1 = 0;

int fibonacci(int n)
{
    count1++;
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{

    int n;
    cout<<"Enter Number:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << fibonacci(i) << " ";
    }
    cout << endl
         << "Steps:" << count1;
    return 0;
}