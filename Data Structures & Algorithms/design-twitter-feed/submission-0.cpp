class Twitter {
   private:
    struct Tweet {
        int id;
        int time;
        Tweet* next;                                                    // next tweet
        Tweet(int id, int time) : id(id), time(time), next(nullptr) {}  // constructor
    };

    int globalTime;
    unordered_map<int, Tweet*> userTweets;
    unordered_map<int, unordered_set<int>> followees;

   public:
    Twitter() { globalTime = 0; }

    void postTweet(int userId, int tweetId){
        Tweet* newTweet = new Tweet(tweetId, globalTime++);
        newTweet->next = userTweets[userId];
        userTweets[userId] = newTweet;
    }

    vector<int> getNewsFeed(int userId) {
        followees[userId].insert(userId);

        auto comp = [](Tweet* a, Tweet* b) {return a->time < b->time;};
        priority_queue<Tweet*, vector<Tweet*>, decltype(comp) > maxHeap(comp);

        for(int followeeId : followees[userId]) {
            if(userTweets.count(followeeId) && userTweets[followeeId]!=nullptr) {
                maxHeap.push(userTweets[followeeId]);
            }
        }

        vector<int> feed;
        while(!maxHeap.empty() && feed.size() < 10) {
            Tweet *curr = maxHeap.top();
            maxHeap.pop();

            feed.push_back(curr->id);

            if(curr->next != nullptr) {
                maxHeap.push(curr->next);
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            followees[followerId].erase(followeeId);
        }
    }
};
