class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int q = queries.size();
        int d = dictionary.size();
        int n = queries[0].size();

        vector<string>ans;
        for(int i=0;i<q;i++){
            string word = queries[i];

            for(int j=0;j<d;j++){
                string dict = dictionary[j];
                int cnt = 0;
                for(int k=0;k<n;k++){
                    if(word[k] != dict[k]) cnt++;
                    if(cnt>2) break;
                }
                if(cnt<=2){
                    ans.push_back(word);
                    break;
                }
            }
        }

        return ans;
    }
};