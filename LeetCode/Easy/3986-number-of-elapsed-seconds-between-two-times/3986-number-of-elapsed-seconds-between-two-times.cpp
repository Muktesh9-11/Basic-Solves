class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int hr = stoi(startTime.substr(0,2)) - stoi(endTime.substr(0,2));
        int min = stoi(startTime.substr(3,2)) - stoi(endTime.substr(3,2));
        int sec = stoi(startTime.substr(6,2)) - stoi(endTime.substr(6,2));

        int ans = 0;
        ans += hr*60*60;
        ans += min*60;
        ans += sec;

        return -ans;
    }
};