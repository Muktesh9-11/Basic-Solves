#define ll long long
#define pb push_back

class Solution {
public:

    int n;
    //vector<ll, ll> ans;
    // [sum, cnt] 

    vector<pair<int,int>> move = {{-1,-1}, {-1,0}, {0,-1}};
    const int MOD = 1000000007;

    pair<ll,ll> solve(vector<string> & board, int i, int j, vector<vector<pair<ll,ll>>> & dp){
        if(i==0 && j == 0){
            return {0, 1};
        }

        if(dp[i][j].first != -1) return dp[i][j];

        ll sum=0, cnt=0;
        if(board[i][j]>='1' && board[i][j]<='9'){
            sum = board[i][j] - '0';
        }

        ll nxts = INT_MIN, nxtc = 0;
        for(auto & it : move){
            int xi = i + it.first;
            int yi = j + it.second;

            if(xi>=0 && yi>=0){
                char c = board[xi][yi];
                if(c == 'X') continue;
                
                pair<ll,ll> p = solve(board, xi, yi, dp);
                ll nextsum = p.first;
                ll nextcnt = p.second;
                if(nextsum == nxts){
                    nxtc = (nextcnt + nxtc) % MOD;
                }
                else if(nextsum > nxts){
                    nxts = nextsum;
                    nxtc = nextcnt % MOD;
                }
            }
        }

        sum += nxts;
        cnt = nxtc;

        if(nxts == INT_MIN){
            return dp[i][j] = {-1,0};
        }

        return dp[i][j] = {sum,cnt};

    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();

        //vector<vector<int>> vis(n, vector<int>(n,0));
        vector<vector<pair<ll,ll>>> dp(n+1, vector<pair<ll,ll>>(n+1, {-1,-1}));

        pair<ll,ll> ans = solve(board, n-1, n-1, dp);

        if(ans.first < 0) return {0,0};

        vector<int> fin;
        fin.pb(ans.first);
        fin.pb(ans.second);

        return fin;

    }
};