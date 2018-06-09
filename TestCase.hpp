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
  template<typename T> TestCase& check_equal(const T& a, const T& b){
      total++;
      if((T)a == (T)b) passed++;
      else{
          failed++;
          output_stream << test_name << ": Failure in test #" << total;
          output_stream << ": " << b << "  should equal  " << a <<"!" << endl;
      } 
      return *this;
  }

  template<typename T> TestCase& check_different(const T& a, const T& b){
      total++;
      if((T)a != (T)b) passed++;
      else{
          failed++;
          output_stream << test_name << ": Failure in test #" << total;
          output_stream << ": " << b << "  shouldn't equal  " << a <<"!" << endl;
      } 
      return *this;
  }
  /**
  template<typename T> TestCase& check_function(std::function<int(const int&,T&,T&)>func,const T& a, const T& b){
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
  template<typename T> TestCase& check_output(const T& a, const string& str){
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