/*
 * demo_class.h
 *
 *  Author: Erwin
 */

#ifndef DEMO_CLASS_H_
#define DEMO_CLASS_H_

#include <string>
#include <vector>

class demo_interface {};

// 'final': Inheritation is forbidden.
// It is suggested to use 'public' inheritation.
// It may be confused to use 'virtual' and 'protected'.
class demo_class final : public demo_interface {
 public:
  // 'using': Type Alias.
  using string_type = std::string;
  using vector_type = std::vector<int>;

  // 6 functions:
  // These functions shall be implemented automatically by the complier.
  // Constructor: Default(No paramter), Copy, Move.
  // Assignment: Copy, Move.
  // Destructor:

  // 'default': Tell the compiler explicitly to use the default implementation.
  demo_class() = default;

  demo_class(const demo_class&) = delete;

  // Copy assignment is forbidden.
  demo_class& operator=(const demo_class&) = delete;

  // 'explicit': To prevent accidental type conversion due to implicit
  //             construction and implicit transform.
  // Mainly for:
  // Constructors: Only one parameter.
  //               One parameter and other parameters with default value.
  // Transform operator functions:
  explicit demo_class(const string_type& str);
  // std::string str = "string";
  // DemoClass demo = str;

  // conversion from ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} to
  // non-scalar type ‘DemoClass’ requested.

  explicit operator bool();

  ~demo_class() = default;

 private:
  // In-class member initializer: To avoid the pitfalls of not initializing.
  int a = 10;
  string_type s = "hello";
  vector_type v{1, 2, 3};
};

class demo_delegating final {
 public:
  using string_type = std::string;

  // Delegating(Basic) Constructor.
  demo_delegating(int x) : a(x) {}

  demo_delegating() : demo_delegating(0) {}

  demo_delegating(const string_type& s) : demo_delegating(stoi(s)) {}

 private:
  int a;
};

#endif  // DEMO_CLASS_H_
