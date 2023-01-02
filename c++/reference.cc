/*
 * reference.cc
 *
 *  Author: Erwin
 */

#include <iostream>

using namespace std;

int main() {
  int x = 20;
  int& ref1 = x;  // 定义引用时必须初始化.

  cout << ref1 << endl;

  const int y = 10;
  // int& ref2 = y;   // 非法: non-const 引用不能被 const 左值初始化.
  // int& ref3 = 10;  // 非法: non-const 引用不能被右值初始化.

  const int& ref2 = x;  // const 引用可以被 non-const 左值初始化.
  const int& ref3 = y;  // const 引用可以被 const 左值初始化.
  const int& ref4 = 9;  // const 引用可以被右值初始化.

  cout << ref2 << endl;
  cout << ref3 << endl;
  cout << ref4 << endl;

  int&& ref5 = 200;

  cout << ref5 << endl;

  // int&& ref6 = x;        // 非法: 右值引用无法被左值初始化.
  // const int&& ref7 = x;  // 非法: 右值引用无法被左值初始化.

  // 因为右值引用的目的是为了延长用来初始化对象的生命周期.
  // 对于左值, 其生命周期与其作用域有关, 你没有必要去延长, 这是我的理解.

  int&& ref6 = x * 2;  // x * 2 的结果是一个右值, ref6 延长其生命周期.
  int z = ref6 + 2;  // 重用 x * 2 的结果.

  cout << z << endl;

  // 一旦你初始化一个右值引用变量, 该变量就成为了一个左值, 可以被赋值.
  ref6 = 100;
  // 这点很重要, 初始化之后的右值引用将变成一个左值.
  // 如果是 non-const还可以被赋值！

  cout << ref6 << endl;

  return 0;
}
