/*
 * my_exception.h
 *
 *  Author: Erwin
 */

#ifndef MY_EXCEPTION_H_
#define MY_EXCEPTION_H_

#include <iostream>
#include <stdexcept>

class my_exception : public std::runtime_error {
 public:
  using this_type = my_exception;
  using super_type = std::runtime_error;

 public:
  // Important constructor and deconstructor are suggested to 'noexcept' for
  // performance.

  my_exception(const char* msg) : super_type(msg) {}

  my_exception() = default;
  ~my_exception() = default;

 private:
  int code = 0;
};

class exception_test final {
 public:
  // It is suggedted to encapsulate "throw" to a function.
  [[noreturn]] void raise(const char* msg) {
    throw my_exception(msg);
    // warning: function declared ‘noreturn’ has a ‘return’ statement.
    // return;
  }

  void catch_test() {
    try {
      raise("error occured!");
      // It is suggedted to use only one 'catch'.
    } catch (const std::exception& e) {  // Suggested const &
      // Virtual function of exception.
      std::cout << e.what() << std::endl;
    }

    return;
  }

  // TODO: Situation?
  void funtion_try_test() try {
    raise("error occured!");
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  void noexcept_test() noexcept {
    std::cout << "noexcept" << std::endl;

    // warning: throw will always call terminate() [-Wterminate].
    // throw "Oh My God!";

    return;
  }
};

#endif  // MY_EXCEPTION_H_
