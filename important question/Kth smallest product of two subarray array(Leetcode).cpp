using ll = long long;
class Solution {
public:
    int n,m;

    static ll floordiv(ll a, ll b) {
        ll q = a / b;
        ll r = a % b;
        if (r != 0 && ((r > 0) != (b > 0))) --q;
        return q;
    }

    static ll ceildiv(ll a, ll b) {
        ll q = a / b;
        ll r = a % b;
        if (r != 0 && ((r > 0) == (b > 0))) ++q;
        return q;
    }

   bool check(ll mid, vector<int>& nums1, vector<int>& nums2, ll k) {
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums1[i] == 0) {
                if (mid >= 0) cnt += m; 
            } 
            else if (nums1[i] > 0) {
                ll val = floordiv(mid,nums1[i]);
                cnt += upper_bound(nums2.begin(), nums2.end(), val) - nums2.begin();
            } 
            else { 
              ll val = ceildiv(mid,nums1[i]);
                cnt += nums2.end() - lower_bound(nums2.begin(), nums2.end(),val);
            }
        }
        return cnt >= k;
    }

    ll solve(ll k,vector<int>& nums1, vector<int>& nums2){
    const ll inf = 1e10+5;
    ll low = -inf,high = inf;

    ll ans = high;

    while(low<=high){
        ll mid = low+(high-low)/2;
        if(check(mid,nums1,nums2,k)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        n = nums1.size();
        m = nums2.size();
        return solve(k,nums1,nums2);
    }
};