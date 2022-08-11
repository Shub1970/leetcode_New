// https://leetcode.com/problems/queue-reconstruction-by-height/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution
{
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people)
    {
        sort(people.begin(), people.end(), [](pair<int, int> p1, pair<int, int> p2)
             { return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); });
        for (auto x : people)
            cout << "{" << x.first << "," << x.second << "},";
        cout << "\n";
        vector<pair<int, int>> sol;
        for (auto person : people)
        {
            sol.insert(sol.begin() + person.second, person);
            for (auto x : sol)
                cout << "{" << x.first << "," << x.second << "},";
            cout << "\n";
        }
        return sol;
    }
};

int main()
{
    vector<pair<int, int>> pai{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    Solution obj;
    obj.reconstructQueue(pai);
}

// out put
//  {7,0},{7,1},{6,1},{5,0},{5,2},{4,4},
//  {7,0},
//  {7,0},{7,1},
//  {7,0},{6,1},{7,1},
//  {5,0},{7,0},{6,1},{7,1},
//  {5,0},{7,0},{5,2},{6,1},{7,1},
//  {5,0},{7,0},{5,2},{6,1},{4,4},{7,1},