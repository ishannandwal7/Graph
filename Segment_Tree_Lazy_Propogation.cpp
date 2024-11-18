#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    vector<long long> tree, lazy;
    int n;

    void push(int node, int node_left, int node_right) {
        // Apply pending updates to the current node
        if (lazy[node] != 0) {
            // Apply the pending lazy value to the node
            tree[node] += (node_right - node_left + 1) * lazy[node];

            // Propagate the laziness to the children if it's not a leaf node
            if (node_left != node_right) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            // Clear the lazy value for this node
            lazy[node] = 0;
        }
    }

    void update_range(int node, int node_left, int node_right, int query_left, int query_right, long long value) {
        push(node, node_left, node_right);  // Ensure all previous lazy updates are applied

        if (node_right < query_left || node_left > query_right) {
            return;  // No overlap with the query range
        }

        if (node_left >= query_left && node_right <= query_right) {
            // Total overlap with the query range
            tree[node] += (node_right - node_left + 1) * value;
            if (node_left != node_right) {
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }
            return;
        }

        // Partial overlap, recurse for left and right children
        int mid = (node_left + node_right) / 2;
        update_range(2 * node + 1, node_left, mid, query_left, query_right, value);
        update_range(2 * node + 2, mid + 1, node_right, query_left, query_right, value);

        // Recompute the current node's value based on its children
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    long long query_range(int node, int node_left, int node_right, int query_left, int query_right) {
        push(node, node_left, node_right);  // Ensure all previous lazy updates are applied

        if (node_right < query_left || node_left > query_right) {
            return 0;  // No overlap with the query range
        }

        if (node_left >= query_left && node_right <= query_right) {
            // Total overlap with the query range
            return tree[node];
        }

        // Partial overlap, recurse for left and right children
        int mid = (node_left + node_right) / 2;
        long long left_query = query_range(2 * node + 1, node_left, mid, query_left, query_right);
        long long right_query = query_range(2 * node + 2, mid + 1, node_right, query_left, query_right);
        return left_query + right_query;
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * size, 0);  // Segment tree
        lazy.resize(4 * size, 0);  // Lazy array
    }

    // Range update: add value to all elements in the range [L, R]
    void update(int L, int R, long long value) {
        update_range(0, 0, n - 1, L, R, value);
    }

    // Range query: sum of elements in the range [L, R]
    long long query(int L, int R) {
        return query_range(0, 0, n - 1, L, R);
    }
};

int main() {
    int n = 10;  // Size of the array
    SegmentTree segTree(n);

    // Performing some updates
    segTree.update(0, 4, 5);  // Add 5 to all elements in range [0, 4]
    segTree.update(3, 6, 2);  // Add 2 to all elements in range [3, 6]

    // Performing some queries
    cout << "Sum of range [0, 4]: " << segTree.query(0, 4) << endl;
    cout << "Sum of range [3, 6]: " << segTree.query(3, 6) << endl;
    cout << "Sum of range [0, 9]: " << segTree.query(0, 9) << endl;

    return 0;
}
