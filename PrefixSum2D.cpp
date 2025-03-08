#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;




int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    ll size, queries;

    cin >> size >> queries;
    vector<vector<ll>> ps;

    ps.resize(size+1, vector<ll>(size+1, 0));

    string line;

    for (ll i = 1; i <= size; i++){
        cin >> line;
        for (ll j = 1; j <= size; j++){
            if (line[j-1] == '*'){
                ps[i][j] = 1 + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
            } else{
                ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
            }
        }
    }

    while(queries--){

        ll yi, xi, yf, xf;

        cin >> yi >> xi >> yf >> xf;

        cout << ps[yf][xf] - ps[yi-1][xf] - ps[yf][xi-1] + ps[yi-1][xi-1] << endl;
        
        

    }


    
    return 0;
}
