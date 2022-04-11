struct Building {
    Building(const vector<int>& building) : start(building[0]), end(building[1]), height(building[2]) {}
    Building() : Building({0, 0, 0}) {}
    int start;
    int end;
    int height;
};

struct Compare {
    inline bool operator()(const Building& lhs, const Building& rhs) {
        return lhs.height < rhs.height;
    }
};

class Solution {
public:
    
    // Priority queue
    //  - We'll iterate across 0 .. n where n is the length of the skyline
    //  - As we do so we'll accumulate buildings in our priority queue
    //  - When we reach the end of one building we'll delete it from our pq
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int64_t skylineLength = 0;
        for (auto& building : buildings) {
            skylineLength = std::max(skylineLength, static_cast<int64_t>(building[1]));
        }
        
        
        vector<vector<int>> segments;
        
        int buildingIdx = 0, previousHeight = 0;
        priority_queue<Building, vector<Building>, Compare> q;
        for (int64_t i = 0; i < skylineLength; ++i) {
            // Load buildings that are now in bounds
            while (buildingIdx < buildings.size() && buildings[buildingIdx][0] <= i) {
                q.push(Building(buildings[buildingIdx]));
                buildingIdx++;
            }
            
            // Outside of range seek to start of next building
            if (q.empty()) {
                i = buildings[buildingIdx][0] - 1;
                continue;
            }

            
            // Drain any out of range results
            while (!q.empty() && q.top().end <= i) {
                q.pop();   
            }
            
            // We've purged everything, we are at zero
            if (q.empty()) {
                segments.push_back({(int)i, 0});
                previousHeight = 0;
                i = buildings[buildingIdx][0] - 1;
                continue;
            } 
            
            
            // We may have a new top or not 
            auto top = q.top();
            if (top.height != previousHeight) {
                segments.push_back({(int)i, top.height});
                previousHeight = top.height;
            }
            
            // Seek to next critical point
            i = (buildingIdx < buildings.size() && buildings[buildingIdx][0] < q.top().end) ? buildings[buildingIdx][0] - 1 : q.top().end - 1;
        }
        
        if (!q.empty()) {
            segments.push_back({q.top().end, 0});
        }
        
        return segments;
    }
    
#if 0
    // BF 2
    //   - For each start and end check all other buildings to see if we have a match
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> segments;
        unordered_set<int> poi;
        for (auto& building : buildings) {
            poi.insert(building[0]);
            poi.insert(building[1]);
        }
        
        vector startsAndEnds(poi.begin(), poi.end());
        std::sort(startsAndEnds.begin(), startsAndEnds.end());
        
        int previousValue = -1;
        for (auto& point : startsAndEnds) {
            // printf("checking point\n");
            vector<int> segment;
            int height = getHeight(buildings, point);
            // printf("height for point is %d == %d\n", height, point);
            if (previousValue == -1) {
                // printf("start , height %d\n", height);
                previousValue = height;
                segments.push_back({point, height});
            } else if (previousValue != -1 && previousValue != height) {
                // printf("change in height prev %d, height %d\n", previousValue, height);
                previousValue = height;
                segments.push_back({point, height});
            }
        }
        
        return segments;
    }
    
    int getHeight(const vector<vector<int>>& buildings, int val) {
        int maxHeight = 0;
        for (auto& building : buildings) {
            if (val >= building[0] && val < building[1]) {
                maxHeight = std::max(maxHeight, building[2]);
            }
        }
        
        return maxHeight;
    }
#endif    
    
#if 0
    // Brute forceish - runs out of memory
    //   - Create a cache array to mark the max height at any point in the buildings
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> segments;
        if (buildings.size() == 1) {
            segments.push_back({ buildings[0][0], buildings[0][2] });
            segments.push_back({ buildings[0][1], 0 });
            return segments;
        }
        // Get how long the skyline will be 
        int64_t skylineLength = 0;
        for (auto& building : buildings) {
            skylineLength = std::max(skylineLength, static_cast<int64_t>(building[1]));
        }
        
        // Create our height cache
        vector<int64_t> heights(skylineLength + 1, 0);
        
        // Now build the skyling
        for (auto& building : buildings) {
            for (int64_t i = building[0]; i < building[1]; ++i) {
                heights[i] = std::max(heights[i], static_cast<int64_t>(building[2]));
            }
        }
        
        // Grab the completed segments
        int64_t prevValue = -1;
        for (int i = 0; i < heights.size(); ++i) {
            if (prevValue == -1 && heights[i] != 0) {
                segments.push_back({i, (int)heights[i]});
                prevValue = heights[i];
            } else if (prevValue != -1 && prevValue != heights[i]) {
                segments.push_back({i, (int)heights[i]});
                prevValue = heights[i];
            }
        }
        // print(heights);
        
        return segments;
    }
#endif
    
    void print(const std::vector<int64_t>& v) {
        printf("[");
        for (auto x : v) {
            printf("%ld, ", x);
        }
        printf("]\n");
    }
};
