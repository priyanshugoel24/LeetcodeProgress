// Last updated: 02/05/2026, 22:36:53
class Solution {
public:
    // Query the segment tree for sum in range [qs, qe]
    long long querySegmentTree(int qs, int qe, int i, int l, int r, vector<long long>& segmentTree) {
        if (r < qs || l > qe) return 0;

        if (l >= qs && r <= qe) return segmentTree[i];

        int mid = l + (r - l) / 2;
        long long left = querySegmentTree(qs, qe, 2 * i + 1, l, mid, segmentTree);
        long long right = querySegmentTree(qs, qe, 2 * i + 2, mid + 1, r, segmentTree);

        return left + right;
    }

    // Update the segment tree at index idx
    void updateSegmentTree(int i, int l, int r, int idx, vector<long long>& segmentTree) {
        if (l == r) {
            segmentTree[i] = 1; // mark as visited
            return;
        }

        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            updateSegmentTree(2 * i + 1, l, mid, idx, segmentTree);
        } else {
            updateSegmentTree(2 * i + 2, mid + 1, r, idx, segmentTree);
        }

        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2]; // propagate update up
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> mp;

        // Map nums2[i] to index
        for (int i = 0; i < n; ++i) {
            mp[nums2[i]] = i;
        }

        // Segment tree with 4*n size
        vector<long long> segmentTree(4 * n, 0);
        long long result = 0;

        // Start inserting from the first element
        updateSegmentTree(0, 0, n - 1, mp[nums1[0]], segmentTree);

        for (int i = 1; i < n; ++i) {
            int idx = mp[nums1[i]];

            long long leftCommon = querySegmentTree(0, idx - 1, 0, 0, n - 1, segmentTree);
            long long leftNotCommon = i - leftCommon;
            long long elementsAfterIdx = n - 1 - idx;
            long long rightCommon = elementsAfterIdx - leftNotCommon;

            result += leftCommon * rightCommon;

            updateSegmentTree(0, 0, n - 1, idx, segmentTree);
        }

        return result;
    }
};
