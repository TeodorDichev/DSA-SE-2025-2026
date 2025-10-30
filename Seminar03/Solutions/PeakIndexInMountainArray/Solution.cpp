// Binary search by comparing two adjacent values (arr[mid] and arr[mid+1] to determine the slope of the function)
// This only works because the values are discrete
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1;
        int r = arr.size() - 2;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] < arr[mid + 1]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }

        }

        return l;
    }
};


// Ternary search solution - works even for continous values (check Coast Lifeguard task)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size() - 1;
        
        while(l < r) {
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;
            
            if(arr[mid1] < arr[mid2]) {
                l = mid1 + 1;
            }
            else {
                r = mid2 - 1;
            }
        }
        
        return l;
    }
};