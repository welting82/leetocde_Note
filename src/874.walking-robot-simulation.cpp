/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 */

// @lc code=start

class Solution {
public:
    void updateLocation(int &x, int &y, int dx, int dy, int k, int &maxi, set<string> &obstacle) {
        for (int i = 1; i <= k; i++) {
            x += dx;
            y += dy;
            string pos = to_string(x) + "#" + to_string(y);
            if (obstacle.find(pos) != obstacle.end()) {
                x -= dx;
                y -= dy;
                break;
            }
        }
        int distance = pow(x, 2) + pow(y, 2);
        maxi = max(maxi, distance);
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int i = 0;
        int maxi = 0;
        int x = 0, y = 0;

        set<string> obstacle;
        for (auto& ob : obstacles) {
            string pos = to_string(ob[0]) + "#" + to_string(ob[1]);
            obstacle.insert(pos);
        }

        for (auto& command : commands) {
            if (command == -1) {
                i = (i + 1) % 4;
            } else if (command == -2) {
                i = (i + 3) % 4;  // equivalent to (i - 1 + 4) % 4
            } else {
                updateLocation(x, y, directions[i].first, directions[i].second, command, maxi, obstacle);
            }
        }

        return maxi;
    }
};
// @lc code=end
