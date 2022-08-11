// https://leetcode.com/problems/score-after-flipping-matrix/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// class Solution
// {
// public:
//     int matrixScore(vector<vector<int>> &grid)
//     {
//         auto applyFlip = [&](string line, int index) -> int
//         {
//             if (line == "row")
//             {
//                 int countOne{0};
//                 for (int i{0}; i < grid[index].size(); i++)
//                 {
//                     grid[index][i] = abs(grid[index][i] - 1);
//                     countOne += grid[index][i];
//                 };
//                 return countOne;
//             }
//             else
//             {
//                 int countOne{0};
//                 for (int i{0}; i < grid.size(); i++)
//                 {
//                     grid[i][index] = abs(grid[i][index] - 1);
//                     countOne += grid[i][index];
//                 };
//                 return countOne;
//             }
//         };

//         for (int i{0}; i < grid.size(); i++)
//         {
//             if (grid[i][0] == 0)
//                 applyFlip("row", i);
//         }

//         size_t half{grid.size() >> 1};
//         for (int i{1}; i < grid[0].size(); i++)
//         {
//             int first{applyFlip("coloum", i)};
//             int second{applyFlip("coloum", i)};
//             if (first > second)
//                 applyFlip("coloum", i);
//         }
//         int total{0};
//         for (auto y : grid)
//         {
//             int index = y.size();
//             for (auto x : y)
//             {
//                 total += x * pow(2, --index);
//                 // cout << x << " ";
//             }
//             // cout << "\n";
//         }
//         return total;
//     }
// };

// sorter form solution

class Solution
{
public:
    int matrixScore(vector<vector<int>> &grid)
    {
        int row(grid[0].size()), coloum(grid.size());
        int result = (1 << row - 1) * coloum;
        for (int i{1}; i < row; i++)
        {
            int curSum{0};
            for (int j{0}; j < coloum; j++)
                curSum += grid[j][i] == grid[j][0];
            result += max(curSum, coloum - curSum) * (1 << row - i - 1);
        }
        return result;
    }
};
int main()
{
    vector<vector<int>> map{{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
    Solution obj;
    cout << obj.matrixScore(map);
}