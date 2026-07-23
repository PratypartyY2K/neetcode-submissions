/************
The core trick behind the optimized DFS is **post-order traversal with dual return values**.

Instead of doing separate passes to measure heights, every recursive function call asks its left and right subtrees two questions at the exact same time:

1. *"How tall are you?"* $\rightarrow$ `height`
2. *"Is the fire (target node) anywhere inside you? If so, how far away is it?"* $\rightarrow$ `dist_to_target`

---

## 1. The Key Realization

When fire starts at a target node, it spreads in **two directions**:

1. **Downwards** into the target node's own subtrees.
2. **Upwards** to an ancestor, and then **downwards into the opposite branch** of that ancestor.

For any ancestor node $A$ sitting on the path above the target node:

```text
         Ancestor A
         /        \
   (Fire side)   (Other side)
      ...           ...
    Target         Deepest Leaf

```

The total time for fire to travel from the target, reach ancestor $A$, and burn all the way down $A$'s *other* side is:

$$\text{Time} = \text{Distance from } A \text{ to Target} + \text{Height of } A\text{'s Other Subtree}$$

If we calculate this value for **every ancestor node** on the path from the target to the root, the maximum value we get across all ancestors is our total burn time!

---

## 2. Why We Pass Two Values Upwards

As recursion bubbles back up from the bottom of the tree, each parent node gathers information from its two children:

```text
                 [Parent Node]
                 /           \
  (left_h, left_dist)     (right_h, right_dist)

```

At each parent node, exactly **one** of three scenarios happens:

### Scenario A: Current Node IS the Target

* **What it means:** The fire starts right here.
* **Calculation:** The time needed to burn downwards is simply the height of its taller child.
* **Return to parent:** Send up `dist_to_target = 1` (since the parent is 1 step away from the fire).

### Scenario B: Target is in the LEFT Subtree (`left_dist != -1`)

* **What it means:** Fire is coming up from the left side!
* **Calculation:** Fire will reach this parent in `left_dist` seconds, then needs `right_h` more seconds to reach the bottom of the right side.

$$\text{Max Time Candidate} = \text{left\_dist} + \text{right\_h}$$


* **Return to parent:** Send up `left_dist + 1` so the parent above knows how far away the fire is.

### Scenario C: Target is in the RIGHT Subtree (`right_dist != -1`)

* **What it means:** Fire is coming up from the right side!
* **Calculation:** Same logic reversed:

$$\text{Max Time Candidate} = \text{right\_dist} + \text{left\_h}$$


* **Return to parent:** Send up `right_dist + 1`.

---

## Summary of Efficiency

* **Single Pass:** Every node is visited **exactly once** ($O(N)$ time).
* **No Map needed:** The recursion stack acts as the "map" returning path distances implicitly.
* **Space efficient:** Uses only $O(H)$ stack space (where $H$ is the tree height, $O(\log N)$ for balanced trees) instead of $O(N)$ auxiliary space for parent pointers and BFS queues.
**************/
#include <iostream>
#include <algorithm>
#include <utility>

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

class Solution {
    int maxTime = 0;

    // Returns {height, distanceToTarget}
    // distanceToTarget = -1 if target is not in this subtree
    pair<int, int> dfs(Node* node, int target) {
        if (node == nullptr)
            return {0, -1};

        auto [leftHeight, leftDist] = dfs(node->left, target);
        auto [rightHeight, rightDist] = dfs(node->right, target);

        int currHeight = 1 + max(leftHeight, rightHeight);

        // Case 1: Current node is the target
        if (node->val == target) {
            maxTime = max(maxTime, max(leftHeight, rightHeight));
            return {currHeight, 1};
        }

        // Case 2: Target is in left subtree
        if (leftDist != -1) {
            maxTime = max(maxTime, leftDist + rightHeight);
            return {currHeight, leftDist + 1};
        }

        // Case 3: Target is in right subtree
        if (rightDist != -1) {
            maxTime = max(maxTime, rightDist + leftHeight);
            return {currHeight, rightDist + 1};
        }

        // Target not present
        return {currHeight, -1};
    }

public:
    int minTimeToBurn(Node* root, int target) {
        maxTime = 0;
        dfs(root, target);
        return maxTime;
    }
};
