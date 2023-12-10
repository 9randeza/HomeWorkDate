#include <iostream>

class Date{
	private:
		int year;
		int month;
		int day;
	public:
		Date(int y, int m, int d);
		int GetYear()const;
		int GetMonth()const;
		int GetDay()const;
};

int Date::GetYear()const{
	return year;
}

int Date::GetMonth()const{
	return month;
}

int Date::GetDay()const{
	return day;
}

Date::Date(int y, int m, int d){

}

int main()
{
	Date d(3, 4, 132);
	std::cout << d.GetYear() << " ";
	std::cout << d.GetMonth() << " ";
	std::cout << d.GetDay() << std::endl;
	
	return 0;
	
}
