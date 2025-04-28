/*

1311. Get Watched Videos by Your Friends

There are n people, each person has a unique id between 0 and n-1. Given the arrays watchedVideos and friends, where watchedVideos[i] and friends[i] contain the list of watched videos and the list of friends respectively for the person with id = i.

Level 1 of videos are all watched videos by your friends, level 2 of videos are all watched videos by the friends of your friends and so on. In general, the level k of videos are all watched videos by people with the shortest path exactly equal to k with you. Given your id and the level of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least to greatest. 

*/

class Solution {
    private:
        static bool cmp(std::pair<std::string, int> &a, std::pair<std::string, int> &b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    public:
        vector<string> watchedVideosByFriends(
            vector<vector<string>>& watchedVideos, 
            vector<vector<int>>& friends, 
            int id, 
            int level
        ) {
            int n = friends.size();
    
            std::vector<int> d(n, INT_MAX);
            std::vector<std::string> videos;
            
            std::queue<int> q;
    
            q.push(id);
            d[id] = 0;
    
            while (!q.empty()) {
                int n = q.front();
                q.pop();
    
                for (auto it: friends[n]) {
                    if (d[n] + 1 < d[it]) {
                        d[it] = d[n] + 1;
                        q.push(it);
                    }
                }
            }
    
            for (int i = 0; i < d.size(); ++i) {
                if (d[i] == level) {
                    for (int j = 0; j < watchedVideos[i].size(); ++j) {
                        videos.push_back(watchedVideos[i][j]);
                    }
                }
            }
    
            std::unordered_map<std::string, int> m;
    
            for (int i = 0; i < videos.size(); ++i) {
                m[videos[i]]++;
            }
    
            std::vector<std::pair<std::string, int>> vec;
    
            for (auto it = m.begin(); it != m.end(); ++it) {
                vec.push_back({ it->first, it->second });
            }
    
            std::sort(vec.begin(), vec.end(), cmp);
    
            std::vector<std::string> res;
    
            for (std::pair<std::string, int> &p: vec) {
                res.push_back(p.first);
            }
    
            return res;
        }
    };