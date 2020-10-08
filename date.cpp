#include "date.h"
#include <iomanip>
using namespace std;
Date::Date(int new_year, int new_month, int new_day):year(new_year),month(new_month),day(new_day) {}
int Date::GetDay() const { return day;}
int Date::GetYear() const { return year;}
int Date::GetMonth() const { return month;}
Date ParseDate(istream& stream){
    int new_year,new_month,new_day;
    stream >> new_year;
    stream.ignore(1);
    stream >> new_month;
    stream.ignore(1);
    stream >> new_day;
    return Date(new_year,new_month,new_day);
}
ostream& operator<<(ostream& stream,const Date& date){
    stream << setw(4) << setfill('0') << date.GetYear() << "-" << setw(2) << setfill('0')  << date.GetMonth() << "-" <<setw(2) << setfill('0') << date.GetDay();
    return stream;
}
bool operator<(const Date& lhs,const Date& rhs){
    return lhs.GetYear()*365+lhs.GetMonth()*30+lhs.GetDay()<rhs.GetYear()*365+rhs.GetMonth()*30+rhs.GetDay();
}
bool operator==(const Date& lhs,const Date& rhs){
    return lhs.GetYear()*365+lhs.GetMonth()*30+lhs.GetDay()==rhs.GetYear()*365+rhs.GetMonth()*30+rhs.GetDay();
}