/*
 * auto_decltype.h
 *
 *  Author: Erwin
 */

#ifndef AUTO_DECLTYPE_H_
#define AUTO_DECLTYPE_H_

#include <iostream>
#include <set>
#include <typeinfo>

class auto_decltype {
 public:
  using set_type = std::set<int>;

  // Deduce return value.
  auto get_a_set() {
    set_type s = {1, 2, 3};

    // 'range-based for'
    for (const auto& i : s) {
      std::cout << i << ",";
    }
    std::cout << std::endl;

    return s;
  }

  void auto_test() {
    // 'auto' is used in initialization situation, such as '=', '{}'.
    auto x = 10L;  // Deduced to 'long'.
    auto y = &x;   // Deduced to 'long*'.
    auto z{&x};    // Deduced to 'long*'.

    auto str = "hello";  // We hope 'std::string', but deduced to 'const char*'.
    // TBD: auto str2 = "hello"s;  // Deduced to 'std::string'.

    auto& x1 = x;        // Deduced to 'long'.
    auto* x2 = &x;       // Deduced to 'long&'.
    const auto& x3 = x;  // Deduced to 'const long&'.
    auto x4 = &x3;       // Deduced to 'const long*'.
    auto x5 = x3;        // Deduced to 'long', different from 'decltype'.

    std::cout << typeid(x).name() << std::endl;
    std::cout << typeid(y).name() << std::endl;
    std::cout << typeid(z).name() << std::endl;

    std::cout << typeid(str).name() << std::endl;

    std::cout << typeid(x1).name() << std::endl;
    std::cout << typeid(x2).name() << std::endl;
    std::cout << typeid(x3).name() << std::endl;
    std::cout << typeid(x4).name() << std::endl;
    std::cout << typeid(x5).name() << std::endl;

    return;
  }

  void decltype_test() {
    int x = 0;

    // Advanced form of 'auto'.
    decltype(x) x1;
    decltype(x)& x2 = x;
    decltype(x)* x3;
    decltype(&x) x4;
    decltype(&x)* x5;
    // 'decltype' does not only deduce the 'value type', but also deduce the
    // reference type', which is the 'original type' of a expression.
    decltype(x2) x6 = x2;

    std::cout << typeid(x).name() << std::endl;
    std::cout << typeid(x1).name() << std::endl;
    std::cout << typeid(x2).name() << std::endl;
    std::cout << typeid(x3).name() << std::endl;
    std::cout << typeid(x4).name() << std::endl;
    std::cout << typeid(x5).name() << std::endl;
    std::cout << typeid(x6).name() << std::endl;

    return;
  }

  void decltype_auto_test() {
    int x = 0;

    decltype(auto) x1 = (x);  // Deduced to 'int&'.
    decltype(auto) x2 = &x;   // Deduced to 'int*'.
    decltype(auto) x3 = x1;   // Deduced to 'int&'.

    std::cout << typeid(x2).name() << std::endl;
    std::cout << typeid(x3).name() << std::endl;

    return;
  }

 private:
  // auto a = 10;
  // It is not allowed in non-static class member initialization, but allowed in
  // static class member.
  set_type m_set;

  using iter_type = decltype(m_set.begin());

  iter_type m_pos;
};

#endif  // AUTO_DECLTYPE_H_
