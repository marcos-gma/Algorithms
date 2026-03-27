#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> c;
    
    int i = 0, j = 0;
    
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            c.push_back(left[i++]);
        } else {
            c.push_back(right[j++]);
        }
    }
    
    while (i < left.size()) {
        c.push_back(left[i++]);
    }
    
    while (j < right.size()) {
        c.push_back(right[j++]);
    }
    
    return c;
}

ll merge_sort(vector<int>& a, int l, int r) {
    if (l >= r) {
        return 0;
    }

    int m = l + (r - l) / 2;
    
    ll inversions = 0;
    inversions += merge_sort(a, l, m);
    inversions += merge_sort(a, m + 1, r);

    vector<int> left(a.begin() + l, a.begin() + m + 1);
    vector<int> right(a.begin() + m + 1, a.begin() + r + 1);

    int R = 0;
    for (int x : left) {
        while (R < right.size() && right[R] < x) {
            R++;
        }
        inversions += R;
    }

    vector<int> c = merge(left, right);
    
    for (int i = l; i <= r; i++) {
        a[i] = c[i - l];
    }

    return inversions;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cases;
    
    cin >> cases;
    
    while(cases--){
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i]; 
        }

        ll ans = merge_sort(a, 0, n - 1);
        
        cout << ans << endl;
    }

    return 0;
}
