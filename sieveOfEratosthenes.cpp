#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

void printArr(vector<ll> arr) {
  for (int i = 0; i < arr.size(); i++) {
        cout << arr.at(i) << ' ';
    }
}

// simple sieve - uses a boolean vector
// whose indices represent a number and the 
// boolean value represents whether it is prime
// or not
//
// Time complexity: O(nloglogn)
// Space complexity: O(n)
void simpleSieve(ll n, vector<ll> &nprimes) {
  vector<bool> isPrime(n+1, true);
  isPrime[0] = isPrime[1] = false;
  for (ll i=2; i*i < n; i++) { 
    if (isPrime[i]) {
      for (ll j=i*i; j<=n; j+=i) {
        isPrime[j] = false;
      }
    }
  }
 
  for (ll i=2; i<=n; i++) {
    if (isPrime[i]) {
      nprimes.push_back(i);
      }
  } 
}

// segmented sieve - logically same as the
// simple sieve as well as the same time
// complexity
// but instead of O(n) space complexity
// it has O(s) where s=sqrt(n) in this function
// but could be any arbitary value
// it improves space complexity by running the
// simple sieve on smaller blocks (range) of 
// numbers rather than the initial input
//
// Time complexity: O(nloglogn)
// Space complexity: O(sqrt(n))

void segmentedSieve(ll n, vector<ll> &nprimes) {
  vector<ll> primes;
  ll s  = sqrt(n);
  simpleSieve(s, primes);
  ll high = 0;
  for (ll low=2; low <= n; low += s) {
    high = min(low+s-1, n-1);
    vector<bool> isPrime(high-low+1, true);
  // cout << "low:"<< low << " high:"<<high <<endl;
    for (ll p: primes) {
      ll m = (low/p)*p; 
      
      if (m < low) m+=p;
      if (m == p) m+=p;

      for (ll i=m; i<=high; i += p) {
        isPrime[i-low] = false;
      }
    }
    for (int i = 0; i < isPrime.size(); i++) {
      if (isPrime[i])
      {
          nprimes.push_back(i + low);
      }
    }
  }
}

int main() {
  vector<ll> nprimes;
  segmentedSieve(1000000, nprimes);
  printArr(primes);
}
