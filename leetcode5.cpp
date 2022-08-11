#include <iostream>
#include <vector>
#include <string>
using namespace std;
// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string res;
        for (int i{0}; i < n; i++)
            res.append("a");
        int currenTotal{n};
        for (int i{n - 1}; i <= 0, k - currenTotal > 0; i--)
        {
            if (k - (currenTotal - 1) <= 26)
            {
                res[i] = 'a' + k - currenTotal;
                break;
            }
            else
            {
                res[i] = 'z';
                currenTotal += 'z' - 'a';
            }
        }
        return res;
    }
};

int main()
{
    Solution obj;
    string res = obj.getSmallestString(4, 33);
    for (auto x : res)
        cout << x;
}
// output
// 0:a
// 1:b
// 2:c
// 3:d
// 4:e
// 5:f
// 6:g
// 7:h
// 8:i
// 9:j
// 10:k
// 11:l
// 12:m
// 13:n
// 14:o
// 15:p
// 16:q
// 17:r
// 18:s
// 19:t
// 20:u
// 21:v
// 22:w
// 23:x
// 24:y
// 25:z