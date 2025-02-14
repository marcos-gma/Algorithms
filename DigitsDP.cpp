#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

ll dp[100][4][2];

int d, k;

vector<int> number;

ll solve (int pos, int cnt, bool smaller){
    if (cnt > k) return 0;  
    if (pos == number.size()){
        return cnt == k;
    }

    ll &ans = dp[pos][cnt][smaller];
    if(~ans) return ans;

    ans = 0;

    ll limit  = smaller ? 9 : number[pos];

    for(int i = 0; i <= limit; i++){

        bool isSmaller = smaller || i < number[pos];

        int new_cnt = cnt + (i != 0);

        ans += solve(pos+1, new_cnt, isSmaller);
    }

    return ans;
    
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    string n;
    
    cin >> n;

    for (auto c : n){
        number.push_back(c - '0');
    }

    cin >> k;

    memset(dp,-1,sizeof(dp));

    ll ans = solve(0,0,false);
    
    cout << ans;

	return 0;
}
