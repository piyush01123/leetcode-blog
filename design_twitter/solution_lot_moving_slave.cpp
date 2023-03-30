class Twitter {
    int ctr = 0;
    unordered_map<int, set<int>> users;
    unordered_map<int, vector<pair<int,int>>> tweets;
public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({ctr++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // cout<<"TWEETS\n";
        // for (auto &[k,v]: tweets)
        // {
        //     cout<<k<<':'; 
        //     for(auto pi: v)  cout<<pi.first<<','<<pi.second<<' '; 
        //     cout<<endl;
        // }
        // cout<<"/TWEETS\n";
        // cout<<"USERS\n";
        // for (auto &[k,v]: users)
        // {
        //     cout<<k<<':'; 
        //     for(auto vi: v)  cout<<vi<<','; 
        //     cout<<endl;
        // }
        // cout<<"/USERS\n";

        vector<pair<int,int>> twts;
        for (int user: users[userId]) twts.insert(twts.end(),tweets[user].begin(),tweets[user].end());
        twts.insert(twts.end(), tweets[userId].begin(), tweets[userId].end());
        sort(twts.rbegin(),twts.rend());
        vector<int> res;
        int lim = min(10, (int)twts.size());
        for (int i=0; i<lim; i++) res.push_back(twts[i].second);
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */