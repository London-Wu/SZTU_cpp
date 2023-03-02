#include <iostream>
using namespace std;

int main()
{
	const char* months[12] =
	{
		"January","February","March","April","May","June","July","Aguest","September","October","November","December"
	}; 
	
	int t, input_month;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> input_month;
		if (input_month >= 1 && input_month <= 12)
		{
			cout << months[input_month-1] << endl;
		}
		else
		{
			cout << "error" << endl;
		}
	}
	
	return 0;
}
