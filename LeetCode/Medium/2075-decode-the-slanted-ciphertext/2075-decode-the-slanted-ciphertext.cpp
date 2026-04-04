class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n/rows;
        vector<string> vec(rows);
        int ptr = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                vec[i] += encodedText[ptr];
                ptr++;
            }
        }

        for(auto it : vec){
            cout<<it<<endl;
        }

        string ans = "";

        //int i = 0;
        int j = 0;
        int flag = 0;
        while(j<cols){
            int tempj = j;
            for(int i = 0;i<rows;i++){
                if(tempj >= cols){
                    flag = 1;
                    break;
                }
                ans += vec[i][tempj];
                tempj++;
            }
            if(flag) break;
            j++;
        }

        for(int i = ans.size()-1;i>=0;i--){
            if(ans[i] == ' '){
                if(!ans.empty()) ans.pop_back();
            }
            else break;
        }

        return ans;
    }
};