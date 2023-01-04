/*
 * sequence.cc
 *
 *  Author: Erwin
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct Display {
  void operator()(int i) { cout << i << " "; }
};

int main() {
  int iArr[] = {1, 2, 3, 4, 5};

  vector<int> iVector(iArr, iArr + 4);
  list<int> iList(iArr, iArr + 4);
  deque<int> iDeque(iArr, iArr + 4);
  queue<int> iQueue(iDeque);
  stack<int> iStack(iDeque);
  priority_queue<int> iPQueue(iArr, iArr + 4);

  for_each(iVector.begin(), iVector.end(), Display());
  cout << endl;
  for_each(iList.begin(), iList.end(), Display());
  cout << endl;
  for_each(iDeque.begin(), iDeque.end(), Display());
  cout << endl;

  while (!iQueue.empty()) {
    cout << iQueue.front() << " ";
    iQueue.pop();
  }
  cout << endl;

  while (!iStack.empty()) {
    cout << iStack.top() << " ";
    iStack.pop();
  }
  cout << endl;

  while (!iPQueue.empty()) {
    cout << iPQueue.top() << " ";
    iPQueue.pop();
  }
  cout << endl;

  return 0;
}
