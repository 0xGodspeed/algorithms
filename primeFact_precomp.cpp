// This uses trial division on a precomputed
// array of primes (till sqrt(n)) instead of 
// on all numbers till n or sqrt(n).
// Primes are precomputed by segmented sieve
//
// Time complexity  of the precomputation is 
// O(nlognlogn) and of the  factorization is 
// O(sqrt(n))

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

// -----precomputation-----
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

void segmentedSieve(ll n, vector<ll> &nprimes) {
  vector<ll> primes;
  ll s  = sqrt(n);
  simpleSieve(s, primes);
  ll high = 0;
  for (ll low=2; low <= n; low += s) {
    high = min(low+s-1, n-1);
    vector<bool> isPrime(high-low+1, true);
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

//-------------------------
vector<ll> factorization(ll n) {
  vector<ll> nprimes;
  segmentedSieve(sqrt(n), nprimes);
  vector<ll> factorization;
  for (ll d : nprimes) {
    if (d * d > n) break;
    while (n % d == 0) {
      factorization.push_back(d);
      n /= d;
}
}
  if (n > 1)
    factorization.push_back(n);
  return factorization;
}


int main() {
  vector<ll> pfactorization = factorization(606494922153120000);
  printArr(pfactorization);
}
