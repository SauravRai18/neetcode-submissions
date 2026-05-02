class Twitter {

    int time;

    unordered_map<int, list<pair<int, int>>> tweets;

    unordered_map<int, unordered_set<int>> follows;
public:
    Twitter() {

        time = 0;
        
    }
    
    void postTweet(int userId, int tweetId) {

        tweets[userId].push_front({time++, tweetId});
        
    }
       
    void follow(int followerId, int followeeId) {

        if(followerId != followeeId){

            follows[followerId].insert(followeeId);
        }
        
    }
    
    void unfollow(int followerId, int followeeId) {

        follows[followerId].erase(followeeId);
        
    }

     vector<int> getNewsFeed(int userId) {

        vector<int> res;

        priority_queue<pair<int,int>> pq;

        for( auto &t : tweets[userId]){

            pq.push(t);

        }

        for( auto f : follows[userId]){

            for(auto &t : tweets[f])

            pq.push(t);
        }

        int count = 0;

        while(!pq.empty() && count < 10){

            res.push_back(pq.top().second);

            pq.pop();

            count++;
        }

        return res;








        
    }

};
