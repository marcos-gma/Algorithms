#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

vector<ll> corals;

ll count(ll x){
    ll sum = 0;
    for (auto coral : corals){
        if(x > coral) sum += x - coral;
    }
    return sum;
}

ll binSearch(ll l, ll r, ll max_water){
    ll best = -1;
    while(l <= r){
        int mid = (l+r)/2;
        if (count(mid) <= max_water){
            best = mid;
            l = mid + 1;
        }
        else{
            r = mid -1;
        }
    }
    return best;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    ll cases;
    
    cin >> cases;
    
    while(cases--){
        ll columns, max_water;
        
        cin >> columns >> max_water;
        
        ll height;
        
        ll min_height = 1000000001;
        
        while(columns--){

            cin >> height;
            
            min_height = min(min_height,height);
            
            corals.push_back(height);
            
        }
        
        ll answer = binSearch(0, min_height + max_water, max_water);
        
        cout << answer << endl;
        
        corals.clear();
    }

	return 0;
}
