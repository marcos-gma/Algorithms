#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

// Segment Tree que retorna a soma de um intervalo

ll values;

vector<ll> seg;

void build(ll no, ll l, ll r, vector<ll> &array) {
    if (l == r) {
        seg[no] = array[l];
        return;
    }

    ll mid = (l + r) / 2;
    ll e = no * 2;
    ll d = e + 1;

    build(e, l, mid, array);
    build(d, mid + 1, r, array);

    seg[no] = seg[e] + seg[d]; 
}

void updating(ll no, ll l, ll r, ll pos, ll val){
    if(pos < l || pos > r) return;
    if(l == r){
        seg[no] = val;
        return;
    }

    ll mid = (l + r) / 2;
    ll e = no * 2;
    ll d = e + 1;

    updating(e,l,mid,pos,val);
    updating(d,mid+1,r,pos,val);

    seg[no] = seg[e] + seg[d]; 
}

void update(ll pos, ll val){
    updating(1,1,values,pos,val);
}

ll querying(ll no, ll l, ll r, ll lq, ll rq){
    if (lq <= l && r <= rq) return seg[no];

    ll mid = (l + r) / 2;
    ll e = no * 2;
    ll d = e + 1;
    
    if (rq <= mid) return querying(e, l, mid, lq, rq);
    if (lq > mid) return querying(d, mid + 1, r, lq, rq);

    return querying(e, l, mid, lq, rq) + querying(d, mid + 1, r, lq, rq);
}

bool query(ll l, ll r){
    ll totalAlcohol = querying(1, 1, values, l, r); 
    ll totalTime = (r - l + 1);
    return totalAlcohol > (totalTime * 60) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    ll m, queries;

    cin >> values >> m >> queries;
    ll type, a, b, value;
    
    seg.resize(4 * values + 1,0);

    vector<string> drinks(values + 1);
    
    vector<ll> array(values + 1);

    for (ll i = 1; i <= values; i++) {
        cin >> drinks[i];
    }

    map<string,ll> alcohol;

    for (ll i = 1; i <= m; i++) {
        string drink;
        int a;
        cin >> drink >> a;
        alcohol[drink] = a;
    }

    for (ll i = 1; i <= values; i++) {
        array[i] = alcohol[drinks[i]];
    }

    build(1, 1, values, array); 

    while (queries--) {
        ll type, a;
        cin >> type >> a;

        if (type == 1) {
            string b;
            cin >> b;
            update(a, alcohol[b]);
        } else {
            ll b;
            cin >> b;
            if(query(a,b)){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
