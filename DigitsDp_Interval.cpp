#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

ll dp[100][1000][2];

int d, k;

vector<int> number;

ll solve (int pos, int sum, bool smaller){
    if (pos == number.size()) return sum;   

    ll &ans = dp[pos][sum][smaller];
    if(~ans) return ans;

    ans = 0;

    ll limit  = smaller ? 9 : number[pos];

    for(int i = 0; i <= limit; i++){

        bool isSmaller = smaller || i < number[pos];

        ans += solve(pos+1, sum + i, isSmaller);
    }

    return ans;
    
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    ll x;
    string b;

    cin >> x;
    cin >> b;
    
    if( x != 0) x--;
    
    string a = to_string(x);

    while (a != "-1" and b != "-1"){
        
        for (auto c : b){
            number.push_back(c - '0');
        }
    
        memset(dp,-1,sizeof(dp));
    
        ll ans = 0;
    
        ans += solve(0,0,false);
    
        number.clear();
        
        for (auto c : a){
            number.push_back(c - '0');
        }
    
        memset(dp,-1,sizeof(dp));
    
        ans -= solve(0,0,false);
        
        cout << ans << endl;

        cin >> x;
        cin >> b;
        
        if( x != -1 and x != 0) x--;
        
        a = to_string(x);

        number.clear();
    }

	return 0;
}
