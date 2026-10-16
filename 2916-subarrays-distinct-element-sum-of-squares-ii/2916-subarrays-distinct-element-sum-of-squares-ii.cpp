class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;   // sum of values
        long long sq = 0;    // sum of squares
        long long lazy = 0;  // lazy addition
    };

    vector<Node> tree;

    void apply(int node, int l, int r, long long x) {
        long long len = r - l + 1;

        // (a + x)^2 = a^2 + 2ax + x^2
        tree[node].sq =
            (tree[node].sq
            + 2LL * x % MOD * tree[node].sum
            + x * x % MOD * len) % MOD;

        tree[node].sum =
            (tree[node].sum + x * len) % MOD;

        tree[node].lazy =
            (tree[node].lazy + x) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;

        int mid = (l + r) / 2;
        long long x = tree[node].lazy;

        apply(node * 2, l, mid, x);
        apply(node * 2 + 1, mid + 1, r, x);

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, long long x) {

        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, x);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr, x);
        update(node * 2 + 1, mid + 1, r, ql, qr, x);

        tree[node].sum =
            (tree[node * 2].sum +
             tree[node * 2 + 1].sum) % MOD;

        tree[node].sq =
            (tree[node * 2].sq +
             tree[node * 2 + 1].sq) % MOD;
    }

    long long querySquareSum() {
        return tree[1].sq;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        tree.resize(4 * n + 5);

        unordered_map<int, int> last;

        long long ans = 0;

        /*
            At position i:

            Every subarray ending at i has a distinct-count.

            When nums[i] appears:
            - subarrays starting after its previous occurrence
              gain +1 distinct element.
        */

        for (int i = 0; i < n; i++) {

            int prev = -1;

            if (last.count(nums[i]))
                prev = last[nums[i]];

            // All subarrays starting from [prev+1 ... i]
            // gain one new distinct element.
            update(
                1, 0, n - 1,
                prev + 1, i,
                1
            );

            // Sum of squares of distinct counts
            // for all subarrays ending at i.
            ans = (ans + querySquareSum()) % MOD;

            last[nums[i]] = i;
        }

        return ans;
    }
};