#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

ll values;

vector<ll> bit;

void update(ll pos, ll val){
    while( pos <= values){
        bit[pos] += val;
        pos += pos&(-pos);
    }
}

ll query(ll pos){
    ll sum = 0;
    while(pos > 0){
        sum += bit[pos];
        pos -= pos&(-pos);
    }
    return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    ll queries;

    cin >> values >> queries;
    ll type, a, b, value;
    
    bit.resize(values + 1,0);
    
    vector<ll> array(values + 1);
    
    for(ll i=1; i <= values; i++){
        cin >> value;
        array[i] = value;
        update(i,value);
    }

    while(queries--){
        cin >> type >> a >> b;

        if(type == 1){
            update(a, b - array[a]);  
            array[a] = b; 
        }

        else{
            cout << query(b) - query(a-1) << endl;
        }
    }

    

	return 0;
}
