class Solution {
public:
int solve(vector<int>& nums, int t,vector<int>&dp){
    if(nums.size()<=0||t<0){
        return 0;
    }
    if(t==0){
        return 1;
    }
    
    if(dp[t]!=-1){
        return dp[t];
    }
    
    int ans=0;
    for(int i=0;i<nums.size();i++){
        ans+=solve(nums,t-nums[i],dp);
    }
    dp[t]=ans;
    return dp[t];
}
    int combinationSum4(vector<int>& nums, int t) {
        vector<int> dp(t+1,-1);
        return solve(nums,t,dp);

        
    }
};