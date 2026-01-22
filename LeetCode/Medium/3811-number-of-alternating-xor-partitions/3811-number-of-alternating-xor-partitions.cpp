class Solution {
public:

    // to improve space complexity memoize dp states into a single key
    unordered_map<long long, int> memo;
    static const int MOD = 1e9 + 7;

    int solve(int index,int currentXor,bool isT1Turn,vector<int>& nums,int t1,int t2){
        if (index == nums.size()) {
            if ((isT1Turn && currentXor == t1) ||
                (!isT1Turn && currentXor == t2)) {
                return 1;
            }
            return 0;
        }

        // Most significant 32 bits -> index (<=1e5)
        // next bits are currentXor -> (<=1e5);
        // nowt -> Least significant bit -> 1bit
        long long stateKey =((long long)index << 32) |((long long)currentXor << 1) | isT1Turn;

        //You can also use string key such as:
        //string key = to_string(index) + "#" +
        //to_string(currentXor) + "#" +
        //to_string(isT1Turn);

        if (memo.count(stateKey)) return memo[stateKey];

        // case not changing currxor no matter what
        long long ways = 0;
        ways += solve(index + 1,currentXor ^ nums[index],isT1Turn,nums,t1,t2);

        // currxor flips case
        if ((isT1Turn && currentXor == t1) ||
            (!isT1Turn && currentXor == t2)) {
            ways += solve(index + 1,nums[index],!isT1Turn,nums,t1,t2);
        }

        return memo[stateKey] = ways % MOD;
        
    }
    
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        
        return solve(1, nums[0], true, nums, target1, target2);
        
    }
};