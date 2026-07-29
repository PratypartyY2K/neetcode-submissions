class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        // Step 1: Store tasks with their original indices: {enqueueTime, processingTime, originalIndex}
        vector<vector<int>> sortedTasks;
        for(int i = 0; i < n; i++) {
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        // Step 2: Sort tasks chronologically by enqueueTime
        sort(sortedTasks.begin(), sortedTasks.end());

        // Min-heap stores pairs of {processingTime, originalIndex}
        typedef pair<int, int> TaskPair;
        priority_queue<TaskPair, vector<TaskPair>, greater<TaskPair>> pq;

        vector<int> result;
        long long currentTime = 0; // Use long long to avoid potential overflow
        int taskIdx = 0;

        while(taskIdx < n || !pq.empty()) {
            
            // If CPU is idle and heap is empty, jump time forward to next available task
            if (pq.empty() && currentTime < sortedTasks[taskIdx][0]) {
                currentTime = sortedTasks[taskIdx][0];
            }

            // Push all tasks that have arrived by 'currentTime' into min-heap
            while(taskIdx < n && sortedTasks[taskIdx][0] <= currentTime) {
                pq.push({sortedTasks[taskIdx][1], sortedTasks[taskIdx][2]});
                taskIdx++;
            }

            // Execute the shortest task available
            auto [procTime, origIdx] = pq.top();
            pq.pop();

            result.push_back(origIdx);
            currentTime += procTime;
        }

        return result;
    }
};
