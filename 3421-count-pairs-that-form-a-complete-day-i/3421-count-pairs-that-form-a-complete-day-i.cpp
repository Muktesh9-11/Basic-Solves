class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int n;
        n=hours.size();
        for(int i=0;i<n;i++){
            hours[i]=hours[i]%24;
        }
        vector<int>hash(24,0);
        for(int i=0;i<n;i++){
            hash[hours[i]]++;
        }
        int count=0;
        count += (hash[0]*(hash[0]-1))/2;
        count += (hash[12]*(hash[12]-1))/2;
        for(int i=1;i<12;i++){
            count += hash[i]*hash[24-i];
        }
        return count;
    }
};