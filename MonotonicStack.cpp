#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> h(n);
    for (ll i = 0; i < n; i++) {
        cin >> h[i];
    }

    stack<ll> s;
    ll max_area = 0;

    for (ll i = 0; i <= n; i++) {

        ll cur_height;

        if(i == n) cur_height = 0;
        else cur_height = h[i];    
    
        while (!s.empty() && cur_height < h[s.top()]) {
            ll top = s.top();
            s.pop();
            ll width;
            if(s.empty()) width = i;
            else width = i - s.top() - 1;   
            max_area = max(max_area, h[top] * width);
        }
        s.push(i);
    }

    cout << max_area << endl;
    return 0;
}
