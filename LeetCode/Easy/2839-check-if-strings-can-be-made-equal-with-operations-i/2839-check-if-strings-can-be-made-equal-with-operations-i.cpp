class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string s1ev = "", s2ev="", s1od="", s2od="";
        s1ev += s1[0];
        s1ev += s1[2];

        s1od += s1[1];
        s1od += s1[3];

        s2ev += s2[0];
        s2ev += s2[2];

        s2od += s2[1];
        s2od += s2[3];

        sort(s1ev.begin(),s1ev.end());
        sort(s1od.begin(),s1od.end());
        sort(s2ev.begin(),s2ev.end());
        sort(s2od.begin(),s2od.end());

        if(s1ev==s2ev && s1od==s2od) return true;

        return false;


    }
};