/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
class Twitter {
public:
    vector<pair<int,int>> tweettbl;
    vector<vector<bool>> userfoll;
    Twitter() {
        userfoll.resize(500,vector<bool>(500,false));
    }
    
    void postTweet(int userId, int tweetId) {
        tweettbl.insert(tweettbl.begin(),{tweetId,userId});
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> news;
        for(auto i:tweettbl)
        {
            if(i.second == userId || userfoll[userId][i.second])
            {
                news.push_back(i.first);
            }
            if(news.size() == 10) break;
        }
        return news;
    }
    
    void follow(int followerId, int followeeId) {
        userfoll[followerId][followeeId] = true;
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        userfoll[followerId][followeeId] = false;
        return;
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
// @lc code=end
/*
["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]\n
[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]\n
*/
