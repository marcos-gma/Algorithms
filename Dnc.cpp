#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

struct Query {
    int l, r, idx;
};

const int MAXN = 200005;
int a[MAXN];
int ans[MAXN]; 

void dnc(int l, int r, const vector<Query>& queries) {
    if (l > r || queries.empty()) return;

    int m = l + (r - l) / 2;
    vector<Query> left, right, cur;

    for (Query qr : queries) {
        if (qr.l <= m && m <= qr.r) cur.push_back(qr);
        else if (qr.r < m) left.push_back(qr);
        else right.push_back(qr);
    }

    dnc(l, m - 1, left);
    dnc(m + 1, r, right);

    if (cur.empty()) return;

    vector<int> suf = {a[m]};
    vector<int> pref = {a[m]};

    for (int i = m - 1; i >= l; i--) {
        suf.push_back(min(a[i], suf.back()));
    }
    
    for (int i = m + 1; i <= r; i++) {
        pref.push_back(min(a[i], pref.back()));
    }

    for (Query qr : cur) {
        ans[qr.idx] = min(suf[m - qr.l], pref[qr.r - m]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        
        queries[i].l--;
        queries[i].r--;
        
        queries[i].idx = i;
    }

    dnc(0, n - 1, queries);

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
