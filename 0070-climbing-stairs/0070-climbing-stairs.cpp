class Solution {
public:
    int climbStairs(int n) {
        if(n==0){
            return 1;
        }
        if(n==1||n==2||n==3){
            return n;
        }
                int *a=new int[n+1];
        a[0]=1;
        a[1]=1;
        a[2]=2;
       
        for(int i=3;i<=n;i++){
            a[i]=a[i-1]+a[i-2];

        }
        return a[n];
    
        
    }
};