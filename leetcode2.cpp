#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        vector<vector<int>> map;
        map.resize(rowSum.size(), vector<int>(colSum.size(), 0));
        for (int x{0}; x < rowSum.size(); x++)
        {
            for (int y{0}; y < colSum.size(); y++)
            {
                map[x][y] = min(rowSum[x], colSum[y]);
                rowSum[x] -= map[x][y];
                colSum[y] -= map[x][y];
            }
        }
        return map;
    }
};

int main()
{
    vector<int> rowSum{4, 6, 8, 2, 3, 5, 2, 7};
    vector<int> colSum{34, 5, 3, 42, 34, 23, 54, 6};
    Solution obj;
    obj.restoreMatrix(rowSum, colSum);
}