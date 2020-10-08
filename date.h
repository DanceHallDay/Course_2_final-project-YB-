#pragma once
#include <fstream>
using namespace std;
class Date{
public:
   Date(int new_year,int new_month,int new_day);
   int GetYear() const;
   int GetMonth() const;
   int GetDay() const;
private:
   int year,month,day;
};
Date ParseDate(istream& stream);
ostream& operator<<(ostream& stream,const Date& date);
bool operator<(const Date& lhs,const Date& rhs);
bool operator==(const Date& lhs,const Date& rhs);
template <class F,class S>
ostream& operator<<(ostream& stream,pair<F,S> d){
    stream << d.first << " " << d.second;
    return stream;
}