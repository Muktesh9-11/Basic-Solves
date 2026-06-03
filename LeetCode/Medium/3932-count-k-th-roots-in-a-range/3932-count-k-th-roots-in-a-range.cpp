class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int st = ceil(pow(l, 1.0 / k) - 1e-9);
        int end = floor(pow(r, 1.0 / k) + 1e-9);
        return max(0, end - st + 1);
    }
};