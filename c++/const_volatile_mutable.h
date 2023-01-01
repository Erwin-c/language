/*
 * const_volatile_mutable.h
 *
 *  Author: Erwin
 */

#ifndef CONST_VOLATIlE_MUTABLE_H_
#define CONST_VOLATIlE_MUTABLE_H_

#include <iostream>

class const_volatile_mutable {
 public:
  using mutex_type = long;

  // The function is 'const'. The state of the object is not modified.
  int get_value() const {
    // Error: m_value’ in read-only object.
    // ++m_value;
    return m_value;
  }

  void save_data() const {
    ++m_mutex;
    return;
  }

  void volatile_test() {
    // 'const' appears in the runtime phase other than preprocessing phase.
    // 'volatile' disables compiler opitimization.
    const volatile int MAX_LEN = 1024;

    auto ptr = (int*)(&MAX_LEN);
    *ptr = 2048;
    // If there is no 'volatile', the result is still 1024.
    std::cout << MAX_LEN << std::endl;

    return;
  }

  void const_test() {
    std::string name = "uncharted";

    const std::string* ps1 = &name;
    // Error.
    // *ps1 = "spederman";
    std::cout << *ps1 << std::endl;

    std::string* const ps2 = &name;
    // Correct.
    *ps2 = "spidernan";
    std::cout << *ps2 << std::endl;

    return;
  }

 private:
  const long MAX_SIZE = 256;
  int m_value;
  // 'mutable' removes the limit of 'const'.
  // One case: mutex.
  mutable mutex_type m_mutex;
};

#endif  // CONST_VOLATIlE_MUTABLE_H_
