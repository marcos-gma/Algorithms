#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

const ll n = 2;
const ll MOD = 1000000007;

class Matrix{
    public:
        ll mat[n][n] = {{0,0},{0,0}};
        
        Matrix operator * (const Matrix &other){
            Matrix ans;
            for(ll i = 0; i < n; i++){
                for(ll j = 0; j < n; j++){
                    for(ll k = 0; k < n; k++){
                        ans.mat[i][j] = (ans.mat[i][j] + (mat[i][k] % MOD) * (other.mat[k][j] % MOD) % MOD) % MOD;
                    }
                }
            }
            return ans;
        }
};

Matrix fexp(Matrix a, ll b){
    Matrix ans;
    for(ll i = 0; i < n; i++){
        ans.mat[i][i] = 1;
    }
    
    while(b){
        if(b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // tentando dnv

    ll num;
    cin >> num;

    if(num ==0) cout << 0 << endl;
    else if(num == 1) cout << 1 << endl;
    else{
        Matrix a;
        a.mat[0][0] = 1;
        a.mat[0][1] = 1;
        a.mat[1][0] = 1;
        a.mat[1][1] = 0;
        
        Matrix ans = fexp(a, num-1);
        
        cout << ans.mat[0][0] << endl;
    }

    return 0;
}
