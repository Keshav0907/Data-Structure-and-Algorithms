class Solution {
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
{
    int target = (rolls.size() + n) * mean - accumulate(rolls.begin(), rolls.end(), 0);
    if (target < n or target > n * 6)
    {
        return {};
    }

    vector<int> ans;
    while(target) {
        int dice = min(6,target-n+1);
        ans.push_back(dice);
        n--;
        target -= dice;
        
    }
    return ans;
}
};