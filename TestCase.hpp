#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <functional>
using namespace std;

class TestCase{
protected:
  string test_name;
  ostream& output_stream;
  int failed , passed , total;
public:
  TestCase(const string& , ostream&);
  TestCase(const TestCase&);
  
  template<typename T> 
  TestCase& check_equal(const T& a, const T& b){
      total++;
      if((T)a == (T)b) passed++;
      else{
          failed++;
          output_stream << test_name << ": Failure in test #" << total;
          output_stream << ": " << b << "  should equal  " << a <<"!" << endl;
      } 
      return *this;
  }

  template<typename T> 
  TestCase& check_different(const T& a, const T& b){
      total++;
      if((T)a != (T)b) passed++;
      else{
          failed++;
          output_stream << test_name << ": Failure in test #" << total;
          output_stream << ": " << b << "  shouldn't equal  " << a <<"!" << endl;
      } 
      return *this;
  }

  template<typename R, typename T1, typename T2> 
  TestCase& check_function(R func,const T1& a, const T2& b){
      total++;
      T2 test = func(a);
      if((T2)test != (T2)b){
        failed++;
        //Test int operators: Failure in test #4: Function should return 25 but returned 125!
        output_stream << test_name << ": Failure in test #" << total;
        output_stream << ": Function should return " << b << " but returned " << test <<"!" << endl;
      } 
      else passed++;
      return *this;
  }

  template<typename T> 
  TestCase& check_output(const T& a, const string& str){
      stringstream ss;
      ss << (T)a;
      total++;
      if(str.compare(ss.str()) == 0 ) passed++;
      else{
          failed++;
          //Test MyStruct operators: Failure in test #3: string value should be MyStruct(5) but is MyStrct(5)
          output_stream << test_name << ": Failure in test #" << total;
          output_stream <<": string value should be " << str << " but is " << a <<"!" << endl;
      }
      return *this;
  }
    void print()const;
};