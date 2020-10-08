#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <exception>
#include <fstream>
#include <vector>
using namespace std;
template <class F,class S>
void AssertEqual(F a,S b,const string& hint){
    stringstream os;
    os << a << "!=" << b << " " << hint;
    if (a!=b) throw runtime_error(os.str());
}
void Assert(const bool& c,const string& hint);
template <class Q>
ostream& operator<<(ostream& stream,const vector<Q>& q){
    for (auto c : q)
        stream << c << " ";
    stream << endl ;
    return stream;
}

class TestRunner{
public:
    TestRunner();
    template <class T>
    void RunTest(T function,const string& test_name){
        try{
            function();
            cout << test_name << " is OK." << endl;
        }catch(runtime_error& ex){
            fail_count++;
            cerr << ex.what() << endl;
        }
        catch(...){
            fail_count++;
            cerr << "other mistakes" << endl;
        }
    }
    ~TestRunner();
private:
    int fail_count;};