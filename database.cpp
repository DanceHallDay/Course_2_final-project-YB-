#include "database.h"
using namespace std;
void Database::Add(const Date &new_date, const string &new_event) {
    auto it = unique_database[new_date].insert(new_event);
    if (it.second) database[new_date].push_back(new_event);
}
void Database::Print(ostream& stream) const {
    for (const auto [key,value] : database)
        for (const auto c : value)
             stream << key << " " << c << endl;
}
pair<Date,string> Database::Last(const Date& new_date) const{
    auto it = database.upper_bound(new_date);
    if (it!=database.begin())
        return make_pair(prev(it)->first,prev(it)->second.back());
    throw invalid_argument("error");
}