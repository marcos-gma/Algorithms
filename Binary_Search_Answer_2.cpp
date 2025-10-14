#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

vector<ll> arrayy;


ll count(ll x){
    ll y = 1;
    ll sum = 0;
    for(auto a : arrayy){
        if(sum + a <= x){
            sum += a;
        }else{
            sum = a;
            y++;
        }
    }
    return y;
}

ll binSearch(ll l, ll r, ll k){
    ll ans;
    while(l <= r){
        ll mid = (l+r)/2;
        if (count(mid) <= k){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    ll n,k;

    cin >> n >> k;

    arrayy.resize(n);
    
    ll totalSum = 0;
    
    ll maxElement = 0;

    for(int i=0; i < n; i++){
        cin >> arrayy[i];
        maxElement = max(maxElement,arrayy[i]);
        totalSum += arrayy[i];
    }
    
    // l -> se o segmento tiver tamanho 1 a resposta é o maior elemento
    // r -> se o segmento tiver o tamamanho do array a resposta é a soma dos elementos

    cout << binSearch(maxElement,totalSum,k) << endl;

	return 0;
}
