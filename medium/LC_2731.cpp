class Solution {
public:
    using ll = long long;
    int sumDistance(vector<int>& nums, string s, int d) {
        ll n = nums.size(), ans = 0, sum = 0, mod = 1e9+7;
        for(int i = 0; i<n; ++i){
            nums[i]+= s[i] == 'L' ? -d : d;
            sum = (sum+nums[i]) % mod;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; ++i){
            ll diff = (ll)(n-i)*nums[i];
            ans = (ans + sum - diff) % mod;
            ans = (ans+mod) % mod;
            sum = (sum-nums[i]+mod) % mod;
        }
        return ans%mod;
    }
};
