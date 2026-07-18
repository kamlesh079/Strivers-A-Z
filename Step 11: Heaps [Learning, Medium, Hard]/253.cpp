// https://leetcode.com/problems/design-twitter

class Twitter {
    // tweet
    struct Tweet {
        int tweetId;
        int time;
        Tweet(int id, int t) : tweetId(id), time(t) {};
    };
    // global time
    int time;

    // post
    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> followings;

    // cmp
    class cmp {
    public:
        bool operator()(const Tweet& a, const Tweet& b) {
            return a.time > b.time; // minheap -> true -> goes down the heap
        }
    };

public:
    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(tweetId, time++));
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet, vector<Tweet>, cmp> minheap;
        // push usedId post
        if (tweets.find(userId) != tweets.end()) {
            for (auto tweet : tweets[userId]) {
                minheap.push(tweet);
                if (minheap.size() > 10)
                    minheap.pop();
            }
        }
        // add user followings's tweets
        if (followings.find(userId) != followings.end()) {
            auto myFollowings = followings[userId];
            // add tweets for each followee's
            for (auto followeeId : myFollowings) {
                if (tweets.find(followeeId) != tweets.end()) {
                    for (auto tweet : tweets[followeeId]) {
                        minheap.push(tweet);
                        if (minheap.size() > 10)
                            minheap.pop(); // remove the oldest tweet
                    }
                }
            }
        }
        vector<int> ans;
        while(!minheap.empty()){
            auto [id, time] = minheap.top();
            minheap.pop();
            ans.push_back(id);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;
        followings[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followings.find(followerId) != followings.end())
            followings[followerId].erase(followeeId);
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