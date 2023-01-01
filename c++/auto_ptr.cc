/*
 * auto_ptr.cc
 *
 *  Author: Erwin
 */

#include <iostream>
#include <memory>

using namespace std;

int main() {
  {
    auto_ptr<int> pI(new int(10));
    cout << *pI << endl;

    auto_ptr<string> languages[5] = {auto_ptr<string>(new string("C")),
                                     auto_ptr<string>(new string("Java")),
                                     auto_ptr<string>(new string("C++")),
                                     auto_ptr<string>(new string("Python")),
                                     auto_ptr<string>(new string("Rust"))};

    cout << "There are some computer languages here first time:" << endl;
    for (int i = 0; i < 5; ++i) {
      cout << *languages[i] << endl;
    }

    auto_ptr<string> pC;
    // languages[2] loses ownership.
    pC = languages[2];
    cout << "There are some computer languages here second time:" << endl;
    for (int i = 0; i < 2; ++i) {
      cout << *languages[i] << endl;
    }
    cout << "The winner is " << *pC << endl;

    // Segmentation fault (core dumped).
    cout << "There are some computer languages here third time:" << endl;
    for (int i = 0; i < 5; ++i) {
      cout << *languages[i] << endl;
    }
  }

  return 0;
}
