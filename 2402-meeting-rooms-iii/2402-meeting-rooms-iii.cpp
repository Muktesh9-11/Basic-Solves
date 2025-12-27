#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> cnt(n,0);
        //if(meetings.size() <= n) return 0;
        sort(meetings.begin(),meetings.end());

        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        //int i;
        set<int> available;
        for(int i=0;i<n;i++){
            available.insert(i);
        }
        int i=0;
        while(i<meetings.size()){
            int nowst = meetings[i][0];
            int nowend = meetings[i][1];
            
            while(!pq.empty() && pq.top().first <= nowst){
                auto [end,roomno] = pq.top();
                pq.pop();
                available.insert(roomno);
            }

            //if(nowst <= end){
            //    cnt[roomno]++;
            //    pq.push((end+(nowend-nowst)),roomno);
            //    available.erase(roomno);
            //}
            //else{
            //    int smallest = *available.begin();
            //    available.erase(available.begin());
            //    cnt[smallest]++;
            //    pq.push(nowend,smallest);
            //}
            if(!available.empty()){
                int smallest = *available.begin();
                available.erase(available.begin());
                cnt[smallest]++;
                pq.push({nowend,smallest});
            }
            else{
                auto [end,roomno] = pq.top();
                pq.pop();
                cnt[roomno]++;
                pq.push({end+(nowend-nowst),roomno});
            }

            i++;
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            if(cnt[i]>cnt[ans]){
                ans = i;
            }
        }

        return ans;
    }
};