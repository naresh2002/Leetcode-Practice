class Solution {
public:
    void merge(vector<int> &arr, int left, int mid, int right, vector<int> &tempArr) {
        int start1 = left;
        int start2 = mid + 1;
        int n1 = mid - left + 1;
        int n2 = right - (mid + 1) + 1;
        
        for (int i = 0; i < n1; i++) {
            tempArr[start1 + i] = arr[start1 + i];
        }
        for (int i = 0; i < n2; i++) {
            tempArr[start2 + i] = arr[start2 + i];
        }
        
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (tempArr[start1 + i] <= tempArr[start2 + j]) {
                arr[k] = tempArr[start1 + i];
                i++;
            }
            else {
                arr[k] = tempArr[start2 + j];
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            arr[k] = tempArr[start1 + i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = tempArr[start2 + j];
            j++;
            k++;
        }
    }
    
    void mergeSort(vector<int> &arr, int left, int right, vector<int> &tempArr) {
        if (left >= right) {
            return;
        }
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, tempArr);
        mergeSort(arr, mid + 1, right, tempArr);
        merge(arr, left, mid, right, tempArr);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> tempArr(n);
        mergeSort(nums, 0, n - 1, tempArr);
        return nums;
    }
};