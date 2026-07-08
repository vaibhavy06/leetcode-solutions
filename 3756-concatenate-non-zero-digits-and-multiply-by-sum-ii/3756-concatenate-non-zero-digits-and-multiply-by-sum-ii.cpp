static constexpr int MOD = 1e9 + 7, N = 1e5 + 1;
template<size_t N , int MOD>
constexpr array<long long,N> generate_power(){
    array<long long,N> res{};
    res[0] = 1;
    for(int i = 1; i < N; ++i) res[i] = (res[i - 1] * 10) % MOD;
    return res;
} 
static constexpr auto pow10 = generate_power<N , MOD>();
static long long pref[N] = {0};
static int sz[N] = {0}, sum[N] = {0};
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int n = s.length();
        for(int i = 0; i < n; ++i){
            const int num = s[i] - '0';
            pref[i + 1] = (pref[i] * (num ? 10 : 1) + num) % MOD;
            sz[i + 1] = sz[i] + (num > 0);
            sum[i + 1] = sum[i] + num;
        }
        const int m = queries.size();
        vector<int> res(m);
        for(int i = 0; i < m; ++i){
            const int l = queries[i][0], r = queries[i][1];
            long long currsum = sum[r + 1] - sum[l];
            int len = sz[r + 1] - sz[l];
            long long digits = (pref[r + 1] - (pref[l] * pow10[len]) % MOD + MOD) % MOD;
            res[i] = (digits * currsum) % MOD;
        }
        return res;
    }
};