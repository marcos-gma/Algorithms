#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void bfs(vector<string> &bitmap, vector<vector<int>> &dist, int height, int width) {
    queue<pair<int, int>> q;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (bitmap[i][j] == '1') {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= 0 && nx < height && ny >= 0 && ny < width && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases;
    cin >> cases;

    while (cases--) {
        int height, width;
        cin >> height >> width;

        vector<string> bitmap(height);
        vector<vector<int>> dist(height, vector<int>(width, -1));

        for (int i = 0; i < height; i++) {
            cin >> bitmap[i];
        }

        bfs(bitmap, dist, height, width);

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }

    }

    return 0;
}
