class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         map<vector<int>, int> group_ind;
        vector<vector<string>> groups;
        int k = 0;
        vector<int> freq(26, 0);
        for(int i=0; i<strs.size(); i++){
            fill(freq.begin(), freq.end(), 0);
            for(auto ch: strs[i]){
                freq[ch-'a']++;
            }
            if(group_ind.find(freq) != group_ind.end()) groups[group_ind[freq]].push_back(strs[i]);
            else{
                group_ind[freq] = k;
                groups.push_back({strs[i]});
                k++; 
            }
        }
        return groups;
    }
};