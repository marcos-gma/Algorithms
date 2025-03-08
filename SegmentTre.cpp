#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

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

    seg[no] = min(seg[e], seg[d]);
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

    seg[no] = min(seg[e],seg[d]);
}

void update(ll pos, ll val){
    updating(1,1,values,pos,val);
}

ll querying(ll no, ll l, ll r, ll lq, ll rq){
    if (rq < l || r < lq) return LLONG_MAX;
    if (lq <= l && r <= rq) return seg[no];

    ll mid = (l + r) / 2;
    ll e = no * 2;
    ll d = e + 1;

    return min(querying(e, l, mid, lq, rq), querying(d, mid + 1, r, lq, rq));
}

ll query(ll l, ll r){
    return querying(1,1,values,l,r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    ll queries;

    cin >> values >> queries;
    ll type, a, b, value;
    
    seg.resize(4 * values + 1,LLONG_MAX);
    
    vector<ll> array(values + 1);

    for (ll i = 1; i <= values; i++) {
        cin >> array[i];
    }

    build(1, 1, values, array); 

    while (queries--) {
        ll type, a, b;
        cin >> type >> a >> b;

        if (type == 1) {
            update(a, b);
        } else {
            cout << query(a, b) << endl;
        }
    }

    return 0;
}
