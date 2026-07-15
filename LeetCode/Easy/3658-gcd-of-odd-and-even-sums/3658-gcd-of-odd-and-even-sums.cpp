class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int evsum = 0;
        int odsum = 0;
        int num = 2;
        int num2 = 1;
        for(int i=0;i<n;i++){
            evsum += num;
            num += 2;
            odsum += num2;
            num2 += 2;
        }

        return __gcd(evsum, odsum);
    }
};