class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<vector<int>> sortedTasks;
        for(int i = 0; i < n; i++) {
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(sortedTasks.begin(), sortedTasks.end());

        typedef pair<int, int> TaskPair;
        priority_queue<TaskPair, vector<TaskPair>, greater<TaskPair>> pq;

        vector<int> result;
        long long currentTime = 0;
        int taskIdx = 0;

        while(taskIdx < n || !pq.empty()) {
            if (pq.empty() && currentTime < sortedTasks[taskIdx][0]) {
                currentTime = sortedTasks[taskIdx][0];
            }

            while(taskIdx < n && sortedTasks[taskIdx][0] <= currentTime) {
                pq.push({sortedTasks[taskIdx][1], sortedTasks[taskIdx][2]});
                taskIdx++;
            }

            auto [procTime, origIdx] = pq.top();
            pq.pop();

            result.push_back(origIdx);
            currentTime += procTime;
        }

        return result;
    }
};