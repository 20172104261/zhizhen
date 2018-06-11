// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;

class date
{
protected:
	int years;
	int months;
	int days;
public:
	void yunsuan(int year, int month, int day);
	virtual void display();
	date operator -(date&oj);
};

void date::yunsuan(int year, int month, int day)
{
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (year % 4 == 0 && year % 100 != 0 || years % 400 == 0)
	{
		a[2] = 29;
	}
	day += 1;
	if (day > a[month])
	{
		day -= a[month];
		month += 1;
		if (month > 12)
		{
			year += 1;
			month -= 12;
		}
	}
	years = year;
	months = month;
	days = day;
}

void date::display()
{
	cout << years << "年" << months << "月" << days << "日" << " 基类"<<endl;
}

date date::operator -(date&oj)
{
	date ok;
	ok.yunsuan(oj.years - years, oj.months - months, oj.days - days);
	return ok;
}

class CMydate :public date
{
public:
	void display();
};

void CMydate::display()
{
	cout << years << "年" << months << "月" << days << "日" <<" 派生类" <<endl;
}

int main()
{
	date *p;
	p = new CMydate;
	p->yunsuan(1,2,3);
	p->display();
	p->date::display();
    return 0;
}

