class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int inc = 0;
        int ex = 0;
        int* a = new int[10001]();
        
        for (auto x : nums) {
            a[x]++;
        }
        
        for (int i = 1; i <= 10000; i++) {
            int ni = ex + a[i] * i;
            int ne = max(inc, ex);
            inc = ni;
            ex = ne;
        }
        
        return max(inc, ex);
    }
};
