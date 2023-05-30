class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int *a=new int[n+1];
        a[0]=cost[0];
        a[1]=cost[1];
        for(int i=2;i<n;i++){
            a[i]=cost[i]+min(a[i-1],a[i-2]);
        }
        return  min(a[n-1],a[n-2]);
        
    }
};