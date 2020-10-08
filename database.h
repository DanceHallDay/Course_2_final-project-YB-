#pragma once
#include "date.h"
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Database{
public:
    void Add(const Date& new_date,const string& new_event);
    void Print(ostream& stream) const;
    template <class Func>
    vector<pair<Date,string>> FindIf(Func func) const{
        vector<pair<Date,string>> result;
        for (auto it=database.begin();it!=database.end();it++)
        {
            for (auto it1=it->second.begin();it1!=it->second.end();it1++)
                if (func(it->first,*it1)) result.push_back(make_pair(it->first,*it1));
        }
        return result;

    }
    template <class Func>
    int RemoveIf(Func func){
        int result=0;
        for (auto it=database.begin();it!=database.end();)
        {
            auto it_begin= it->second.begin();
            auto it_end = it->second.end();
            int before=it->second.size();
            auto c = it->first;
            auto new_border = stable_partition(it_begin,it_end,[func,c](const string& s){
                return !func(c,s);
            });
            int dif = (int)(it_end-new_border);
            result+=dif;
            it++;
            if (new_border!=it_end){
                if (before-dif==0) {
                    unique_database.erase(c);
                    database.erase(c);
                }
                else if (dif>0) {
                    database[c].erase(new_border,it_end);
                    unique_database[c] = set<string>(it_begin,new_border);
                }
            }
        }
        return result;
    }
    pair<Date,string> Last(const Date& new_date) const;
private:
    map<Date,set<string>> unique_database;
    map<Date,vector<string>> database;
};
