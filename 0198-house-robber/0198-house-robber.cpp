class Solution {
public:
int rob(int n,int i,int*a,vector<int>& nums){
    if(i>=n){
        return 0;
    }
    if(a[i]!=-1){
        return a[i];
    }
    int ninc=rob(n,i+1,a,nums);
    int inc=rob(n,i+2,a,nums)+nums[i];
    a[i]= max(ninc,inc);
    return a[i];
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        int*a=new int[n];
        
        for(int i=0;i<n;i++){
            a[i]=-1;
        }
        return rob(n,0,a,nums);
        
    }
};