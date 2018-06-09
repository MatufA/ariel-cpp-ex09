#include "TestCase.hpp"

TestCase :: TestCase(const string& test_name , std::ostream& stream): 
                    test_name(test_name), output_stream(stream), failed(0) , passed(0) , total(0){}
                    
TestCase :: TestCase(const TestCase& other): test_name(other.test_name), output_stream(other.output_stream),
                                            failed(other.failed), passed(other.passed), total(other.total){}

template<typename T> TestCase& TestCase :: check_equal(const T& a, const T& b){
    total++;
    if(a != b){
        failed++;
        output_stream << test_name << ": Failure in test #" << total;
        output_stream << b << "  should equal  " << a <<"!" << endl;
    } 
    else passed++;
    return *this;
}

template<typename T> TestCase& TestCase :: check_different(const T& a, const T& b){
    total++;
    if(a == b){
        failed++;
        output_stream << test_name << ": Failure in test #" << total;
        output_stream << b << "  shouldn't equal  " << a <<"!" << endl;
    } 
    else passed++;
    return *this;
}
/**
template<typename T> TestCase& TestCase :: check_function(std::function<int(const int&,T&,T&)>func,const T& a, const T& b){
    total++;
    if(func(a) == b){
      failed++;
      output_stream << test_name << ": Failure in test #" << total;
      output_stream << b << "  should equal  " << a <<"!" << endl;
    } 
    else passed++;
    return *this;
}
*/
template<typename T> TestCase& TestCase :: check_output(const T& a, const string& str){
    stringstream ss;
    if(str.compare(ss.str()) == 0 ) passed++;
    else{
        failed++;
        //Test MyStruct operators: Failure in test #3: string value should be MyStruct(5) but is MyStrct(5)
        output_stream << test_name << ": Failure in test #" << total;
        output_stream <<": string value should be " << str << " but is " << a <<"!" << endl;
    }
    return *this;
}
void TestCase :: print()const{
    output_stream << test_name << ": " << failed << " failed, ";
    output_stream << passed << " passed, " << total << " total";
    cout << output_stream << endl;
}