#include "TestCase.hpp"

TestCase :: TestCase(const string& test_name , std::ostream& stream): 
                    test_name(test_name), output_stream(stream), failed(0) , passed(0) , total(0){}

void TestCase :: print()const{
    output_stream << test_name << ": " << failed << " failed, ";
    output_stream << passed << " passed, " << total << " total" << endl;
}