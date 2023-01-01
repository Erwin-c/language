/*
 * node.h
 *
 *  Author: Erwin
 */

#ifndef NODE_H_
#define NODE_H_

// #include <cassert>
// #include <memory>

class node final {
 public:
  using this_type = node;
  using shared_type = std::shared_ptr<this_type>;

  shared_type next;
};

class node2 final {
 public:
  using this_type = node2;
  // 'weak_ptr' can overcome 'loop reference'.
  using shared_type = std::weak_ptr<this_type>;

  shared_type next;
};

#if 0
class smart_ptr {
 public:
  void unique_ptr_test() {
    std::unique_ptr<int> ptr1(new int(10));
    assert(*ptr1 == 10);
    assert(ptr1 != nullptr);

    std::unique_ptr<std::string> ptr2(new std::string("hello"));
    assert(*ptr2 == "hello");
    assert(ptr2->size() == 5);

    // Error: no match for ‘operator++’ (operand type is
    // ‘std::unique_ptr<int>’).
    // ++ptr1;
    // Error: no match for ‘operator+=’ (operand types are
    // ‘std::unique_ptr<std::__cxx11::basic_string<char> >’ and ‘int’).
    // ptr2 += 2;

    // Operation on nullptr, Segmentation fault (core dumped).
    // Initialization is essential.
    // std::unique_ptr<int> ptr3;
    // *ptr3 = 42;

    return;
  }

  void make_unique_test() {
    // More efficient.
    auto ptr1 = std::make_unique<int>(42);
    assert(ptr1 != nullptr && *ptr1 == 42);

    auto ptr2 = std::make_unique<std::string>("god of war");
    assert(!ptr2->empty());

    return;
  }

  void move_test() {
    auto ptr1 = std::make_unique<int>(42);
    assert(ptr1 != nullptr && *ptr1 == 42);

    // Error: use of deleted function.
    // Not use '=' for 'unique_ptr'.
    // auto ptr2 = ptr1;

    auto ptr2 = std::move(ptr1);
    assert(ptr1 == nullptr);

    return;
  }

  void shared_ptr_test() {
    auto ptr1 = std::make_shared<int>(42);

    assert(ptr1 != nullptr && ptr1.unique());

    // Different from 'unique_ptr'.
    auto ptr2 = ptr1;
    assert(ptr1 != nullptr && ptr2 != nullptr);
    assert(ptr1 == ptr2);

    // Reference count.
    assert(!ptr1.unique() && ptr1.use_count() == 2);
    assert(!ptr2.unique() && ptr2.use_count() == 2);

    return;
  }

  void loop_ref_test() {
    auto n1 = std::make_shared<node>();
    auto n2 = std::make_shared<node>();

    assert(n1.use_count() == 1);
    assert(n2.use_count() == 1);

    // 'loop reference' happends which contributes memory leak.
    n1->next = n2;
    n2->next = n1;

    assert(n1.use_count() == 2);
    assert(n2.use_count() == 2);

    return;
  }

  void weak_ptr_test() {
    auto n1 = std::make_shared<node2>();
    auto n2 = std::make_shared<node2>();

    n1->next = n2;
    n2->next = n1;

    assert(n1.use_count() == 1);
    assert(n2.use_count() == 1);

    if (!n1->next.expired()) {
      auto ptr = n1->next.lock();
      assert(ptr == n2);
    }

    return;
  }
};
#endif

#endif  // NODE_H_
