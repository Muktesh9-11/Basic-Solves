class AuctionSystem {
public:

    map<pair<int,int>, int> amount;
    // {itemid,userid}, bidamt

    unordered_map<int,set<pair<int,int>>> bids;
    // Itemid, set{bidamt,userid}

    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {

        //auto itr = amount.find({itemId,userId});
        //if(itr != amount.end()){
        //    int sum = itr->second;
        //    bids[itemId].erase({sum,userId});
        //}
        int sum = amount[{itemId,userId}];
        if(sum){
            bids[itemId].erase({sum,userId});
        }

        bids[itemId].insert({bidAmount,userId});

        amount[{itemId,userId}] = bidAmount;
        
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        int sum = amount[{itemId,userId}];
        bids[itemId].erase({sum,userId});
        bids[itemId].insert({newAmount,userId});
        amount[{itemId,userId}] = newAmount;
    }
    
    void removeBid(int userId, int itemId) {
        int sum = amount[{itemId,userId}];
        amount.erase({itemId,userId});
        bids[itemId].erase({sum,userId});
    }
    
    int getHighestBidder(int itemId) {
        if(bids[itemId].empty())
            return -1;

        return bids[itemId].rbegin()->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */