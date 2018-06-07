#include <iostream>
#include <sstream>
#include <string>
#include <functional>
using namespace std;

class TestCase{
  string test_name;
  ostream output_stream;
  int failed , passed , total;
public:
  TestCase();
  TestCase(const string& , ostream&);
  template<typename T> TestCase& check_equal(const T&, const T&);
  template<typename T> TestCase& check_different(const T&, const T&);
  template<typename T> TestCase& check_function(std::function<T(T,T)>,const T&, const T&);
  template<typename T> TestCase& check_output(const T&, const string&);
  template<typename T> void print();
};