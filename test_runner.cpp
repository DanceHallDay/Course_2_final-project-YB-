#include "test_runner.h"
using namespace std;
void Assert(const bool& c,const string& hint){
    AssertEqual(c,true,hint);
}
TestRunner::~TestRunner(){
    if (fail_count>0){
        cerr << "tests failed." << endl;
        exit(1);
    }
}
TestRunner::TestRunner() {
    fail_count=0;
}

