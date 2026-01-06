#define pb push_back
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        vector<vector<string>> ans;
        sort(words.begin(),words.end());

        for(int i=0;i<n;i++){
            vector<string> temp;
            string top = words[i];
            temp.pb(top);
            for(int j=0;j<n;j++){
                string left = words[j];
                if(left == top) continue;
                else temp.pb(left);
                for(int k=0;k<n;k++){
                    string right = words[k];
                    if(right == left || right == top) continue;
                    else temp.pb(right);
                    for(int l=0;l<n;l++){
                        string bottom = words[l];
                        if(bottom == right || bottom == left || bottom == top) continue;
                        else temp.pb(bottom);

                        if(top[0]==left[0] && top[3]==right[0] && bottom[0]==left[3] && bottom[3]==right[3]){
                            ans.pb(temp);
                        }
                        temp.pop_back();
                    }
                    temp.pop_back();
                }
                temp.pop_back();
            }
            temp.pop_back();
        }

        //sort(ans.begin(),ans.end());
        return ans;
    }
};