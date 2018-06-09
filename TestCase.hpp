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
  template<typename T> TestCase& check_equal(const T&, const T&);
  template<typename T> TestCase& check_different(const T&, const T&);
  //template<typename T> TestCase& check_function(std::function<int(const int&,T&,T&)>,const T&, const T&);
  template<typename T> TestCase& check_output(const T&, const string&);
  void print()const;
};