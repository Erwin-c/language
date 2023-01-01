/*
 * wrapper.c
 *
 *  Author: Erwin
 */

#include <iostream>

enum class shape_type {
  circle,
  triangle,
  rectangle,
};

class shape {
 public:
  shape() { std::cout << "shape()" << std::endl; }
  virtual ~shape() { std::cout << "~shape()" << std::endl; }

  virtual void show() {
    std::cout << "shape::show()" << std::endl;
    return;
  }
};

class circle : public shape {
 public:
  circle() { std::cout << "circle()" << std::endl; }
  ~circle() { std::cout << "~circle()" << std::endl; }

  void show() {
    std::cout << "circle::show()" << std::endl;
    return;
  }
};

class triangle : public shape {};

class rectangle : public shape {};

class shape_wrapper {
 public:
  explicit shape_wrapper(shape* ptr = nullptr) : ptr_(ptr) {}

  ~shape_wrapper() { delete ptr_; }

  shape* get() const { return ptr_; }

 private:
  shape* ptr_;
};

shape* create_shape(shape_type type) {
  switch (type) {
    case shape_type::circle:
      return new circle;
    case shape_type::triangle:
      return new triangle;
    case shape_type::rectangle:
      return new rectangle;
    default:
      return nullptr;
  }
}

int main() {
  shape_wrapper ptr_wrapper(create_shape(shape_type::circle));

  ptr_wrapper.get()->show();

  return 0;
}

// g++ translate
// new circle(...) {
//   void* temp = operator new(sizeof(circle));
//   try {
//     circle* ptr = static_cast<circle*>(temp);
//     ptr->circle(...);
//     return ptr;
//   } catch (...) {
//     operator delete(ptr);
//     throw;
//   }
// }

// delete
// if (ptr != nullptr) {
//   ptr->~shape();
//   operator delete(ptr);
// }
