vector<vector<int>> dp;
class Solution {
public:
    
    int rec(int l,int r,vector<int>& nums){
        if(l>r){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int ans = 0;
        for(int mid = l;mid<=r;mid++){
            ans = max(ans,rec(l,mid-1,nums)+rec(mid+1,r,nums)+nums[l-1]*nums[r+1]*nums[mid]);
        }
        return dp[l][r] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n+2,vector<int>(n+2,-1));
        vector<int> temp;
        temp.push_back(1);
        for(int x : nums) temp.push_back(x);
        temp.push_back(1);
        return rec(1,n,temp);
    }
};