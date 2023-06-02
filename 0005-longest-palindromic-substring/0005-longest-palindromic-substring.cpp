class Solution {
public:
    bool solve(vector<vector<bool>> &dp,int i,int j,string &s){
        if(i == j){
            return dp[i][j] = true;
        }
        if(j-i == 1){
            if(s[i] == s[j]){
                return dp[i][j] = true;
            }
            else{
                return dp[i][j] = false;
            }
        }
        if(s[i] == s[j] && dp[i+1][j-1] == true){
            return dp[i][j] = true;
        } else {
            return dp[i][j] = false;
        }
    
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int si=0,maxl=0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        for(int k=0;k<n;k++){
            for(int i=0,j=k;j<n;i++,j++){
                solve(dp,i,j,s);
                if(dp[i][j]==true){
                    if(j-i+1>maxl){
                        maxl=j-i+1;
                        si=i;
                            
                    }
                }
            }
        }
        
        return s.substr(si,maxl);
    }
};