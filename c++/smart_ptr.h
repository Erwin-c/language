/*
 * smart_ptr.h
 *
 *  Author: Erwin
 */

#ifndef SMRAT_PTR_H_
#define SMART_PTR_H_

#include <algorithm>

template <typename T>
class smart_ptr {
 public:
  explicit smart_ptr(T* ptr = nullptr) : ptr_(ptr) {}

  // Copy constructor
  // smart_ptr(smart_ptr& other) { ptr_ = other.release(); }

  // To do
  // Move constructor: If a move constructor is provided but a copy constructor
  // is not provided explicityly, the latter is automatically disabled.
  smart_ptr(smart_ptr&& other) { ptr_ = other.release(); }
  ~smart_ptr() { delete ptr_; }

  T* get() const { return ptr_; }

  T& operator*() const { return *ptr_; }
  T* operator->() const { return ptr_; }
  // TBD: How to use
  operator bool() const { return ptr_; }

  // If you pass it to another pointer, you don't own the object anymore.
  // Similar to auto_ptr.
  // smart_ptr& operator=(smart_ptr& rhs) {
  // '*this' refers to the new smart_ptr.
  // smart_ptr(rhs).swap(*this);
  // return *this;
  // }

  // Argument is constructed by constructor.
  // Similar to unique_ptr.
  smart_ptr& operator=(smart_ptr rhs) {
    rhs.swap(*this);
    return *this;
  }

 private:
  T* ptr_;

  // Release ownership of the pointer.
  T* release() {
    T* ptr = ptr_;
    ptr_ = nullptr;
    return ptr;
  }

  void swap(smart_ptr& rhs) {
    std::swap(ptr_, rhs.ptr_);
    return;
  }
};

#endif  // SMART_PTR_H_
