class Solution {
public:
int mp(int i,int j,string&s,vector<vector<int>>&dp){
    if(i>=j) return 0;
    else if(dp[i][j]!=-1)return dp[i][j];
    else if(s[i]==s[j]) return mp(i+1,j-1,s,dp);
    else{
        int p1= mp(i+1,j,s,dp);
        int p2= mp(i,j-1,s,dp);
        dp[i][j]=min(p1,p2)+1;
        
        return dp[i][j];
    }
    
    
}
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return mp(0,n-1,s,dp);
        
    }
};