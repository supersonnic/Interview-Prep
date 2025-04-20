/**
 * This program demonstrates the Quick Sort algorithm, which is a 
 * divide-and-conquer sorting technique. It places each number in its 
 * sorted position one at a time, by selecting a pivot and partitioning 
 * the array into two halves: one half with elements less than the pivot 
 * and the other half with elements greater than the pivot. After 
 * partitioning, we just need to sort the two halves. We can do this 
 * recursively, by calling the same function on each half.
 * 
 * In the average case, quick sort effectively divides the array into 
 * two equal halves, reducing the problem size by half at each level of 
 * recursion. This results in a time complexity of O(N log N). However, 
 * in the worst case, quick sort can degrade to O(N^2) if the pivot is 
 * always chosen as the smallest or largest element.
 * 
 * The space complexity of quick sort is O(log(N)) due to the recursive 
 * stack space, which can grow up to log2(N) levels deep. Quick sort is 
 * not a stable sort, meaning that it does not preserve the relative 
 * order of equal elements. However, it is an in-place sort.
 * 
 * @author Shervin Oloumi
 * @date 2023-10-01
 */
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (nums[j] < pivot) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[right]);
    return i;
}

void quick_sort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = partition(nums, left, right);
    quick_sort(nums, left, pivot - 1);
    quick_sort(nums, pivot + 1, right);
}

int main () {
    vector<int> nums = {5, 4, 2, 1, 9, 4};
    cout << "Unsorted vector:";
    for (auto num : nums) {
        cout << " " << num;
    }
    quick_sort(nums, 0, nums.size() - 1);
    cout << endl << "Sorted vector:";
    for (auto num : nums) {
        cout << " " << num;
    }
    return 0;
}