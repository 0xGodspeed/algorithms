#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll binExp(ll a, ll b) {
  ll ans = 1;
  while (b > 0) {
    if (b%2 == 1) ans *= a;
    a = a*a;
    b/=2;
  }
  return ans;
}
int main() {
  cout << binExp(2,4);
  cout << binExp(2,5);
  }
