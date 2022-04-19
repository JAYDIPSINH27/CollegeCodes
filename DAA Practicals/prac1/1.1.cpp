#include <bits/stdc++.h>
using namespace std;
double MachineA(int n)
{
	double result = pow(10, -4) * pow(2, n);
	return result;
}
double MachineB(int n)
{
	double result = pow(10, -6) * pow(2,n); //n3 n2
	return result;
}
double MachineC(int n)
{
	double result = pow(10, -2) * pow(n, 3);
	return result;
}

int main()
{

	const char separator = ' ';
	const int nameWidth = 15;
	const int numWidth = 15;
	int a[5] = {10, 15, 20, 30, 45};

	cout << left << setw(nameWidth) << setfill(separator) << "Number";
	cout << left << setw(nameWidth) << setfill(separator) << "Machine A";
	cout << left << setw(nameWidth) << setfill(separator) << "Machine B" << endl;
	for (int i : a)
	{
		double A = MachineA(i);
		double B = MachineB(i);
		cout << left << setw(nameWidth) << setfill(separator) << i;
		cout << left << setw(nameWidth) << setfill(separator) << A;
		cout << left << setw(nameWidth) << setfill(separator) << B;
		cout << left << setw(nameWidth) << setfill(separator) << ((A < B) ? ("Machine A is Faster then Machine B") : ("Machine B is Faster than Machine A")) << endl;
	}
	cout << endl;
	cout << left << setw(nameWidth) << setfill(separator) << "Number";
	cout << left << setw(nameWidth) << setfill(separator) << "Machine B";
	cout << left << setw(nameWidth) << setfill(separator) << "Machine C" << endl;
	for (int i : a)
	{
		double B = MachineB(i);
		double C = MachineC(i);
		cout << left << setw(nameWidth) << setfill(separator) << i;
		cout << left << setw(nameWidth) << setfill(separator) << B;
		cout << left << setw(nameWidth) << setfill(separator) << C;
		cout << left << setw(nameWidth) << setfill(separator) << ((C < B) ? ("Machine C is Faster then Machine B") : ("Machine B is Faster than Machine C")) << endl;
	}
	return 0;
}
