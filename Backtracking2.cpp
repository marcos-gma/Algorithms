#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

int n, m;

vector<vector<int>> seqs;

void backtracking(int pos, int last, vector<int>& seq){

    if(pos == n){
        seqs.push_back(seq);
        return;
    }

    for(int i = last + 10; i <= m - 10 * (n - pos - 1); i++){
        seq.push_back(i);
        backtracking(pos + 1, i, seq);
        seq.pop_back();
    }

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    cin >> n >> m;

    vector<int> seq;

    backtracking(0, -9, seq);

    cout << seqs.size() << endl;

    for(auto s : seqs){
        for(int i = 0; i < n; i++){
            cout << s[i] << " ";
        }
        cout << endl;
    }

	return 0;
}
