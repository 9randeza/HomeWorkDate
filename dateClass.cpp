#include <iostream>

class Date{
	private:
		int year;
		int month;
		int day;
		
		bool isLeap(int year) {
			return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); // That's what Caesar said
		}
		
		void Normalize(){
			while (month > 12) {
            month -= 12;
            year++;
			}

			while (month < 1) {
            month += 12;
            year--;
			}
			
			while (day < 1) {
				month--;
				if (month < 1) {
					month += 12;
					year--;
				}
			
				if(month == 2){
					if(isLeap(year)){
						day += 29;
					}else{
						day += 28;
					}
				}
			
				if (month == 4 || month == 6 || month == 9 || month == 11){
					day += 30;
				}
				if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
					day += 31;
				}
			}
			
			int daysInMonth = 31;
			
			if (month == 4 || month == 6 || month == 9 || month == 11){
				daysInMonth = 30;
			}
			if(month == 2){
				if(isLeap(year)){
					daysInMonth = 29;
				}else{
					daysInMonth = 28;
				}
			}
			
			while (day > daysInMonth) {
				day -= daysInMonth;
				month++;
				if (month > 12) {
					month -= 12;
					year++;
				}
				daysInMonth = 31;
			
				if (month == 4 || month == 6 || month == 9 || month == 11){
					daysInMonth = 30;
				}
				if(month == 2){
					if(isLeap(year)){
						daysInMonth = 29;
					}else{
						daysInMonth = 28;
					}
				}
			}
		}
		
	public:
		Date(int y, int m, int d);
		Date(int d);
		int GetYear()const;
		int GetMonth()const;
		int GetDay()const;
		
		   Date operator+ (int d) const {
			int newDay = day + d;
			return Date(newDay, month, year);
			}

		Date operator- (int d) const{
			int newDay = day - d;
			return Date(newDay, month, year);
		}

		Date& operator+= (int d){
			day += d;
			
			Normalize();

        return *this;
		}
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
	 year = y;
     month = m;
     day = d;
     Normalize();
}

Date::Date(int d) {
    year = 0;
    month = 1;
    day = d;
    Normalize();
}

int main()
{
	Date d( 5343);
	std::cout << d.GetYear() << " ";
	std::cout << d.GetMonth() << " ";
	std::cout << d.GetDay() << std::endl;
	
	return 0;
	
}
