/*
 * shared_ptr.cc
 *
 *  Author: Erwin
 */

#include <iostream>
#include <memory>

using namespace std;

int main() {
  {
    auto wA = shared_ptr<int>(new int(20));
    {
      auto wA2 = wA;
      cout << (wA2.get() != nullptr ? *wA2.get() : -1) << endl;
      cout << (wA.get() != nullptr ? *wA.get() : -1) << endl;
      cout << wA2.use_count() << endl;
      cout << wA.use_count() << endl;
    }

    cout << wA.use_count() << endl;
    cout << (wA.get() != nullptr ? *wA.get() : -1) << endl;
  }

  auto wAA = make_shared<int>(30);
  auto wAA2 = move(wAA);
  cout << (wAA.get() != nullptr ? *wAA.get() : -1) << endl;
  cout << (wAA2.get() != nullptr ? *wAA2.get() : -1) << endl;
  cout << wAA.use_count() << endl;
  cout << wAA2.use_count() << endl;

  return 0;
}
