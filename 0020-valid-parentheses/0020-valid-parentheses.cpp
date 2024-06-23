class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 != 0) return false; 

        for (int i = 0; i < n - 1; i++) {
            
            if ((s[i] == '(' && s[i + 1] == ')') || 
                (s[i] == '{' && s[i + 1] == '}') || 
                (s[i] == '[' && s[i + 1] == ']')) {
                s.erase(i, 2);  
                i = -1; 
                n -= 2; 
            }
        }
        return s.empty(); 
    }
};