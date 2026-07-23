#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

int minTimeToBurn(Node* root, int targetVal) {
    if (root == nullptr)
        return 0;

    unordered_map<Node*, Node*> parentMap;
    Node* targetNode = nullptr;

    // Step 1: Map each node to its parent and locate target node
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr->val == targetVal)
            targetNode = curr;

        if (curr->left) {
            parentMap[curr->left] = curr;
            q.push(curr->left);
        }

        if (curr->right) {
            parentMap[curr->right] = curr;
            q.push(curr->right);
        }
    }

    if (targetNode == nullptr)
        return 0;  // Target not found

    // Step 2: BFS to simulate burning
    queue<Node*> burnQ;
    unordered_set<Node*> visited;

    burnQ.push(targetNode);
    visited.insert(targetNode);

    int time = 0;

    while (!burnQ.empty()) {
        int size = burnQ.size();
        bool burnedAny = false;

        for (int i = 0; i < size; i++) {
            Node* curr = burnQ.front();
            burnQ.pop();

            // Left child
            if (curr->left && !visited.count(curr->left)) {
                visited.insert(curr->left);
                burnQ.push(curr->left);
                burnedAny = true;
            }

            // Right child
            if (curr->right && !visited.count(curr->right)) {
                visited.insert(curr->right);
                burnQ.push(curr->right);
                burnedAny = true;
            }

            // Parent
            if (parentMap.count(curr) && !visited.count(parentMap[curr])) {
                visited.insert(parentMap[curr]);
                burnQ.push(parentMap[curr]);
                burnedAny = true;
            }
        }

        if (burnedAny)
            time++;
    }

    return time;
}
