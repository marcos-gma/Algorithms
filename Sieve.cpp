#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

const int MAX_SQRT = 1000005; 
bitset<MAX_SQRT> bs;
vector<int> primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < MAX_SQRT; i++) {
        if (bs[i]) {
            for (ll j = i * i; j < MAX_SQRT; j += i) bs[j] = 0;
            primes.push_back((int)i);
        }
    }
}

bool isPrime(ll num) {
    if (num < MAX_SQRT) return bs[num]; 
    
    for (int p : primes) {
        if (1LL * p * p > num) break;
        if (num % p == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;
        
        ll candidate = n + 1;
        
        while(true) {
            if (isPrime(candidate)) {
                cout << candidate << endl;
                break;
            }
            candidate++;
        }
    }

    return 0;
}
