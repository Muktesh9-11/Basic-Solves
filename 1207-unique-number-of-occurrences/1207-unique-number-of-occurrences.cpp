class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        for(auto i : arr) mp[i]++;
        set<int> s;
        for(auto [n, f] :mp) s.insert(f);
        return mp.size() == s.size();
    }
};