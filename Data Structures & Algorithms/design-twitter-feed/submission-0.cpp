class Twitter {
   private:
    struct Tweet {
        int id;
        int time;
        Tweet* next;                                                    // next tweet
        Tweet(int id, int time) : id(id), time(time), next(nullptr) {}  // constructor
    };

    int globalTime;
    unordered_map<int, Tweet*> userTweets; // userId -> head of linked list of tweets (newest first)
    unordered_map<int, unordered_set<int>> followees; // userId -> set of followeeIds

   public:
    Twitter() { globalTime = 0; }

    void postTweet(int userId, int tweetId){
        Tweet* newTweet = new Tweet(tweetId, globalTime++);
        newTweet->next = userTweets[userId]; // Prepend to linked list (O(1))
        userTweets[userId] = newTweet;
    }

    vector<int> getNewsFeed(int userId) {
        followees[userId].insert(userId); // Ensure user follows themselves so their own tweets show up

       // Max-heap stores: {timestamp, Tweet*}
        auto comp = [](Tweet* a, Tweet* b) {return a->time < b->time;}; // custom comparator
        priority_queue<Tweet*, vector<Tweet*>, decltype(comp) > maxHeap(comp); 

       // Step 1: Push the head (most recent tweet) of each followee into the heap
        for(int followeeId : followees[userId]) {
            if(userTweets.count(followeeId) && userTweets[followeeId]!=nullptr) {
                maxHeap.push(userTweets[followeeId]);
            }
        }

        vector<int> feed;
       // Step 2: Extract top 10 newest tweets across all followees (K-way merge)
        while(!maxHeap.empty() && feed.size() < 10) {
            Tweet *curr = maxHeap.top();
            maxHeap.pop();

            feed.push_back(curr->id);
           
            // Step 3: Advance to the next older tweet for this specific user
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
        if(followerId != followeeId) { // User cannot unfollow themselves
            followees[followerId].erase(followeeId);
        }
    }
};
