#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#include <bitset> 

using namespace std;

ll _sieve_size; 
bitset<10000010> bs; 
vector<int> primes; 

void sieve(ll upperbound) { 
    _sieve_size = upperbound + 1; 
    bs.set(); 
    bs[0] = bs[1] = 0; 
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
        for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
        primes.push_back((int)i); 
    } 
} 

bool isPrime(ll N) { 
    if (N <= _sieve_size) return bs[N]; 
    for (int i = 0; i < (int) primes.size(); i++)
    if (N % primes[i] == 0) return false;
    return true; 
} 


ll numDiv(ll N) {
    ll PF_idx = 0;
    ll PF = primes[PF_idx];
    ll ans = 1; 
    while (PF * PF <= N) {
        ll power = 0; 
        while (N % PF == 0) { N /= PF; power++; }
            ans *= (power + 1); 
            PF = primes[++PF_idx];
        }
        if (N != 1) ans *= 2; 
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve(1000000);

    int n;

    cin >> n;

    while(n--){
        int x;

        cin >> x;

        cout << numDiv(x) << endl;
    }

    
    return 0;
}
