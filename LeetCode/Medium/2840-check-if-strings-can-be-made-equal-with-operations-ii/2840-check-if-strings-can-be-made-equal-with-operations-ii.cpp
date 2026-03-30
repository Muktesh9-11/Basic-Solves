class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string s1ev = "", s2ev="", s1od="", s2od="";
        int n = s1.size();
        for(int i=0;i<n;i++){
            if(i%2 == 0){
                s1ev += s1[i];
                s2ev += s2[i];
            }
            else{
                s1od += s1[i];
                s2od += s2[i];
            }
        }

        sort(s1ev.begin(),s1ev.end());
        sort(s1od.begin(),s1od.end());
        sort(s2ev.begin(),s2ev.end());
        sort(s2od.begin(),s2od.end());

        cout<<s1ev<<" "<<s1od<<" "<<s2ev<<" "<<s2od<<endl;

        if(s1ev==s2ev && s1od==s2od) return true;

        return false;
    }
};