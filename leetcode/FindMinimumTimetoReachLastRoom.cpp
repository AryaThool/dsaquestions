class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
    int n = moveTime.size();
    int m = moveTime[0].size();

    vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.emplace(0, 0, 0);

    vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
    visited[0][0] = 0;

    while (!pq.empty()) {
        auto [time, x, y] = pq.top(); pq.pop();

        if (x == n - 1 && y == m - 1)
            return time;

        for (auto [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int nextTime = time + 1;

                // Wait if nextTime is <= moveTime[nx][ny]
                if (nextTime <= moveTime[nx][ny]) {
                    nextTime = moveTime[nx][ny] + 1;
                }

                if (nextTime < visited[nx][ny]) {
                    visited[nx][ny] = nextTime;
                    pq.emplace(nextTime, nx, ny);
                }
            }
        }
    }

    return -1;
    }
};
