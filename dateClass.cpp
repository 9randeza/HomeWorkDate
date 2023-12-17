#include <iostream>

struct WrongDay{
	int day;
};

struct WrongMonth{
	int month;
};

struct WrongYear{
	int year;
};

class Date{
	private:
		int year;
		int month;
		int day;
		
		bool isLeap(int year) {
			return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); // That's what Caesar said
		}
	public:
		Date(int y, int m, int d)
		{
			if(y < 1){
				throw WrongYear(y);
			}
			
			if(m < 1 || m > 12){
				throw WrongMonth(m);
			}
			
			if(isLeap(y)){
				if(m == 2){
					if(d > 29 || d < 1){
						throw WrongDay(d);
					}
				}
			}else if(m == 2){
				if(d > 28 || d < 1){
					throw WrongDay(d);
				}
			}
			if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
				if(d < 1 || d > 31){
					throw WrongDay(d);
				}
			}
			if(m == 4 || m == 6 || m == 9 || m == 11){
				if(d < 1 || d > 30){
					throw WrongDay(d);
				}
			}
		}
		
};

int main()
{
	try{
	Date d(-12, 5, 23);
	 }

    catch (const WrongDay& d) {
        std::cerr << "Wrong day" << std::endl;
        return 1;
    }

    catch (const WrongMonth& m) {
        std::cerr << "Wrong month" << std::endl;
        return 1;
    }

    catch (const WrongYear& y) {
        std::cerr << "Wrong year" << std::endl;
        return 1;
    }

    catch (const std::istream::failure& ex)
    {
        std::cerr << "Data could not be read " << ex.what() << "\n";
        return 2;
    }

    catch (...)
    {
        std::cerr << "other failure " << "\n";
        return -1;
    }
    
	return 0;
	
}
