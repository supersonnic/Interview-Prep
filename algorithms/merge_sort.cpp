/**
 * This file contains the implementation of the merge sort algorithm, which is a
 * divide-and-conquer sorting algorithm. It recursively divides the input array
 * into two halves, sorts each half, and then merges the sorted halves to produce
 * the final sorted array.
 * 
 * The vector is recursively divided into two halves until the base case of a
 * single element is reached. The splitting process happens about log2(N) times,
 * because each split reduces the size of the array by half. At each level, we
 * merge the two halves back together, which takes O(N) time. Therefore, the
 * overall time complexity of merge sort is O(N log N).
 * 
 * The space complexity of merge sort is O(log(N)) due to the recursive stack
 * space, which can grow up to log2(N) levels deep.
 * 
 * Merge sort is a stable sort, meaning that it preserves the relative order of
 * equal elements. However it is not an in-place sort, meaning additional data
 * structures are needed and the space complexity is not constant.
 * 
 * @author Shervin Oloumi
 * @date 2023-10-01
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            merged.push_back(left[i]);
            i++;
        } else {
            merged.push_back(right[j]);
            j++;
        }
    }
    while (i < left.size()) {
        merged.push_back(left[i]);
        i++;
    }
    while (j < right.size()) {
        merged.push_back(right[j]);
        j++;
    }
    return merged;
}

vector<int> merge_sort(const vector<int>& nums) {
    if (nums.size() == 1) {
        return nums;
    }
    int mid = nums.size() / 2;

    vector<int> left = merge_sort(vector<int>(nums.begin(), nums.begin() + mid));
    vector<int> right = merge_sort(vector<int>(nums.begin() + mid, nums.end()));

    return merge(left, right);
}

int main () {
    vector<int> nums = {5, 4, 2, 1, 9, 4};
    vector<int> sorted = merge_sort(nums);
    cout << "Unsorted vector:";
    for (auto num : nums) {
        cout << " " << num;
    }
    cout << endl << "Sorted vector:";
    for (auto num : sorted) {
        cout << " " << num;
    }
    return 0;
}