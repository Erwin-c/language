/*
 * unique_ptr.cc
 *
 *  Author: Erwin
 */

#include <iostream>
#include <memory>

using namespace std;

int main() {
  {
    auto i = unique_ptr<int>(new int(10));
    cout << *i << endl;
  }

  auto w = std::make_unique<int>(10);
  cout << *(w.get()) << endl;
  // error: use of deleted function.
  // auto w2 = w;

  // w is nullptr.
  auto w2 = move(w);
  cout << (w.get() != nullptr ? *w.get() : -1) << endl;
  cout << (w2.get() != nullptr ? *w2.get() : -1) << endl;

  return 0;
}
