#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    ll items, capacity;

    cin >> items >> capacity;

    vector<ll> weights(items);

    vector<ll> values(items);

    for(ll i = 0; i < items; i++){
        cin >> weights[i] >> values[i];
    }

    vector<ll> memo(capacity+1,0);

    for(ll i = 0; i < items; i++){
        for(ll j = capacity; j >= weights[i]; j--){
            memo[j] = max(memo[j],memo[j-weights[i]]+values[i]);
        }
    }

    cout << *max_element(memo.begin(),memo.end()) << endl;

	return 0;
}
