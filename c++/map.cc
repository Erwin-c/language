/*
 * map.cc
 *
 *  Author: Erwin
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Display {
  void operator()(pair<string, double> info) {
    cout << info.first << ": " << info.second << endl;
  }
};

int main() {
  map<string, double> studentSocres;
  studentSocres["LiMing"] = 95.0;
  studentSocres["LiHong"] = 98.5;
  studentSocres.insert(pair<string, double>("Zhangsan", 100.0));
  studentSocres.insert(pair<string, double>("Lisi", 98.6));
  studentSocres.insert(pair<string, double>("Wangwu", 94.5));
  studentSocres.insert(map<string, double>::value_type("Zhaoliu", 95.5));
  studentSocres["Wangwu"] = 88.5;
  for_each(studentSocres.begin(), studentSocres.end(), Display());
  cout << endl;

  map<string, double>::iterator iter;
  iter = studentSocres.find("Zhaoliu");
  if (iter != studentSocres.end()) {
    cout << "Found the score is: " << iter->second << endl;
  } else {
    cout << "Didn't find the key." << endl;
  }

  iter = studentSocres.begin();
  while (iter != studentSocres.end()) {
    if (iter->second < 98.0) {
      studentSocres.erase(iter++);
    } else {
      ++iter;
    }
  }
  for_each(studentSocres.begin(), studentSocres.end(), Display());
  cout << endl;

  for (iter = studentSocres.begin(); iter != studentSocres.end(); ++iter) {
    if (iter->second <= 98.5) {
      iter = studentSocres.erase(iter);
    }
  }
  for_each(studentSocres.begin(), studentSocres.end(), Display());
  cout << endl;

  iter = studentSocres.find("Lisi");
  if (iter != studentSocres.end()) {
    studentSocres.erase(iter);
  }
  for_each(studentSocres.begin(), studentSocres.end(), Display());
  cout << endl;

  int n = studentSocres.erase("Zhangsan");
  cout << n << endl;
  for_each(studentSocres.begin(), studentSocres.end(), Display());

  studentSocres.erase(studentSocres.begin(), studentSocres.end());
  for_each(studentSocres.begin(), studentSocres.end(), Display());
  cout << endl;

  return 0;
}
