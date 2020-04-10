#include<iostream>
using namespace std;

int main()
{
	int MonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year, month, day;	
	int sum = 0;

	while (cin >> year >> month >> day)
	{
        sum = 0;
		if (month > 0 && month <= 12 && day <= MonthDay[month])
		{
			for (int i = 1; i < month; i++)
			{
				sum += MonthDay[i];
			}

			sum += day;

			if (month >= 2)
			{
				if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
				{
					sum += 1;
				}
			}
			cout << sum << endl;;
		}
		else
		{
			return -1;
		}
	}

	system("pause");
	return 0;
	
}