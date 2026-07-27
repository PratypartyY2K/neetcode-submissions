class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(int stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            int firstStone = maxHeap.top();
            maxHeap.pop();
            int secondStone = maxHeap.top();
            maxHeap.pop();
            if (firstStone > secondStone) {
                maxHeap.push(firstStone - secondStone);
            }
        }

        maxHeap.push(0);
        return maxHeap.top();
    }
};
