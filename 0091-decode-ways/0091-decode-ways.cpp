class Solution {
public:
 int f(int i,int n,string &s,vector<int>&dp){
    if(i==n)
      return 1;
      if(dp[i]!=-1)
      return dp[i];
      int take1=0,take2=0;
      if(s[i]!='0')
      take1=f(i+1,n,s,dp);
      if((i+1)<n &&( s[i]=='1' || s[i]=='2' && s[i+1]<'7') )
      take2=f(i+2,n,s,dp);
      return dp[i]=take1+take2;

}
    int numDecodings(string s) {
         int n=s.size();
    vector<int>dp(n,-1);
        return f(0,n,s,dp);
    }
};