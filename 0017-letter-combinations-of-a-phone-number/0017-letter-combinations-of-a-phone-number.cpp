class Solution {
public:
    vector<string> combinations;
    vector<string> numpad{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void answer(string digits,int index,string temp){
        if(index==digits.size()){
            combinations.push_back(temp);
            return;
        }

       for(auto &letter : numpad[digits[index]-'0']){
            answer(digits,index+1,temp+letter);
       }
        
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        answer(digits,0,"");
        return combinations;
    }
};