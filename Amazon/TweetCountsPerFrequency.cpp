// Question link: https://leetcode.com/problems/tweet-counts-per-frequency/

class TweetCounts {
public:
    unordered_map <string, vector<int> > m;
    unordered_map <string, int> f = { {"minute", 60}, {"hour", 3600}, {"day", 86400} };
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector <int> count;
        for(int i = 0; i <= (endTime - startTime)/f[freq]; i++)
            count.push_back(0);
        for(auto time : m[tweetName])
        {
            if(time >= startTime && time <= endTime)
            {
                int idx = (time - startTime)/f[freq];
                count[idx]++;
            }
        }
        return count;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
