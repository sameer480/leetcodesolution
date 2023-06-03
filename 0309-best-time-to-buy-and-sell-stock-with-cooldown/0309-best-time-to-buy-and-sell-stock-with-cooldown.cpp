class Solution {
public:
int solve(int i,vector<int>&P,int bag,vector<vector<int>>&dp){
    if(i>=P.size()){
        return 0;
    }
    if(dp[i][bag]!=-1){
        return dp[i][bag];
    }
    if(bag==1){
        int op2= P[i]+solve(i+2,P,0,dp);
        int op3=solve(i+1,P,1,dp);
        return dp[i][bag]=max(op2,op3);
    }else{
        int op1=-P[i]+solve(i+1,P,1,dp);
        int op3= solve(i+1,P,0,dp);
        return dp[i][bag]=max(op1,op3);

    }
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,prices,0,dp);
        
    }
};