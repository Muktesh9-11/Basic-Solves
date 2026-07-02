#define ll long long
#define pb push_back
class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<ll,ll>>> adj(n);
        vector<ll> ans = {-1,-1};

        for(auto & it : edges){
            ll ui = it[0];
            ll vi = it[1], ti = it[2];

            adj[ui].pb({vi,ti});
        }

        priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>>, greater<pair<ll,pair<ll,ll>>>> pq;
        // pq -> {time, {node, cost}};
        vector<vector<ll>> dist(n, vector<ll>(power + 1, LLONG_MAX));

        dist[source][power] = 0;
        pq.push({0,{source,power}});

        while(!pq.empty()){
            auto curr = pq.top();
            ll time = curr.first;
            ll node = curr.second.first;
            ll pwr = curr.second.second;

            pq.pop();

            if(time > dist[node][pwr]) continue;


            for(auto & it : adj[node]){
                ll nextnode = it.first;
                ll nxttime = it.second;

                if(pwr < cost[node]) continue;
                ll np = pwr - cost[node];

                if(dist[nextnode][np] > time + nxttime){
                    dist[nextnode][np] = time + nxttime;
                    pq.push({dist[nextnode][np], {nextnode,np}}); 
                }
            }
        }

        ll bestTime = LLONG_MAX;
        ll bestPower = -1;

        for(ll p = 0; p <= power; p++){

            if(dist[target][p] < bestTime){
                bestTime = dist[target][p];
                bestPower = p;
            }
            else if(dist[target][p] == bestTime){
                bestPower = max(bestPower, (ll)p);
            }
        }

        if(bestTime == LLONG_MAX)
            return {-1, -1};

        return {bestTime, bestPower};

    }
};