#include <iostream>
using namespace std;

int gcd(int m, int n) {
  int r = m % n;
  if (r == 0) {
    return n;
  } else {
    return gcd(n, r);
  }
}

int main() {
  cout << "hello" << endl;
  cout << gcd(22, 77) << endl;
  return 0;
}
