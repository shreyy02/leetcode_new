class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int slow = i, fast = i;
            bool forward = nums[i] > 0;

            while (true) {
                // Move slow pointer one step
                slow = nextIndex(slow, nums);

                if (slow == -1 || (nums[slow] > 0) != forward)
                    break;

                // Move fast pointer one step
                fast = nextIndex(fast, nums);

                if (fast == -1 || (nums[fast] > 0) != forward)
                    break;

                // Move fast pointer another step
                fast = nextIndex(fast, nums);

                if (fast == -1 || (nums[fast] > 0) != forward)
                    break;

                // Cycle found
                if (slow == fast)
                    return true;
            }

            // Mark the visited path as zero
            slow = i;
            while ((nums[slow] > 0) == forward) {
                int next = nextIndex(slow, nums);

                if (next == -1)
                    break;

                nums[slow] = 0;
                slow = next;
            }
        }

        return false;
    }

private:
    int nextIndex(int i, vector<int>& nums) {
        int n = nums.size();

        // Self-loop is not allowed
        int next = ((i + nums[i]) % n + n) % n;

        if (next == i)
            return -1;

        return next;
    }
};