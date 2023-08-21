class Solution {
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
{
    int target = (rolls.size() + n) * mean - accumulate(rolls.begin(), rolls.end(), 0);
    if (target < n or target > n * 6)
    {
        return {};
    }

    vector<int> ans(n, 0);
    int index = 0;
    while (target > 0)
    {
        ans[index] += 1;
        index++;
        index %= n;
        target--;
    }
    return ans;
}
};