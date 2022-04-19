#include<bits/stdc++.h>
using namespace std;

int count1 = 1;
//Divide And Conquer
double power(int x, unsigned int y) {

    count1++;
    if (y == 0) {
        return 1;
    }
    double temp = power(x, y / 2);//Store Power Value Temporarily
    if (y % 2 == 0) {
        return temp * temp;//For Even Y
    }
    else {
        return x * temp * temp; //For Odd Y
    }
}


int main() {

   const char separator = ' ';
    const int nameWidth = 15;
    const int numWidth = 15;
    int x[3] = {2,7,5};
   unsigned int y[3]={6,25,34};
   int n=sizeof(x)/sizeof(x[0]);

   cout<<"Answer is:\n";

    cout << left << setw(nameWidth) << setfill(separator) << "I";
     cout << left << setw(nameWidth) << setfill(separator) << "X";
     cout << left << setw(nameWidth) << setfill(separator) << "Y";
     cout << left << setw(nameWidth) << setfill(separator) << "X^Y";
     cout << left << setw(nameWidth) << setfill(separator) <<"Count"<<"\n";

    for(int i=0;i<n;i++){
        cout << left << setw(nameWidth) << setfill(separator) << i;
     cout << left << setw(nameWidth) << setfill(separator) << x[i];
     cout << left << setw(nameWidth) << setfill(separator) << y[i];
     cout << left << setw(nameWidth) << setfill(separator) << power(x[i],y[i]);
     cout << left << setw(nameWidth) << setfill(separator) <<count1<<"\n";
        count1=0;
    }
  
    return 0;
}