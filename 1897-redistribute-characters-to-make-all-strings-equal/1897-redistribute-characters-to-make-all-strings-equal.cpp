class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> hash(27,0);
        for(int i=0;i<words.size();i++){
            for(auto c : words[i]){
                hash[c-'a']++;
            }
        }
        for(int i=0;i<27;i++){
            if(hash[i]%(words.size())!=0){
                return false;
            }
        }
        return true;
    }
};