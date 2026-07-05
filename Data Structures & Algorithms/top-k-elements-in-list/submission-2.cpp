class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        vector<int> answer;
        for(int i=0; i < nums.size(); i++) {
            if(mp.find(nums[i])!= mp.end()) {
                mp[nums[i]]++;
            } else {
                mp[nums[i]] = 1;
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for(auto& itr: mp) {
            heap.push({itr.second, itr.first});
            if(heap. size() > k) {
                heap.pop();
            }
        }
        for(int i=0; i < k; i++) {
            answer.push_back(heap.top().second);
            heap.pop();
        }
        
        return answer;
    }
};
