class Solution {
public:
    int passwordStrength(string password) {
        int cnt = 0;
        int n = password.size();
        unordered_map<char,int> mpp;
        for(int i=0;i<n;i++){
            if(mpp[password[i]]==0 && password[i]>= 'a' && password[i] <= 'z'){
                cnt += 1;
                mpp[password[i]]++;
            }
        }

        for(int i=0;i<n;i++){
            if(mpp[password[i]]==0 && password[i]>= 'A' && password[i] <= 'Z'){
                cnt += 2;
                mpp[password[i]]++;
                //break;
            }
        }

        for(int i=0;i<n;i++){
            if(mpp[password[i]]==0 && password[i]>= '0' && password[i] <= '9'){
                cnt += 3;
                mpp[password[i]]++;
                //break;
            }
        }

        for(int i=0;i<n;i++){
            if(mpp[password[i]]==0 && (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$')){
                cnt += 5;
                mpp[password[i]]++;
                //break;
            }
        }

        for(auto it : mpp){
            cout<<it.first<<" "<<it.second<<endl;
        }

        return cnt;
    }
};