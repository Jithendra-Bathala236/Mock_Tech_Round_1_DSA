#include <iostream>
#include <vector>
using namespace std;

vector<int> findTargetInfo(const vector<int>& arr, int target) {
    
    int left = 0;
    int right = arr.size() - 1;
    int firstOccurrence = -1;
    int count = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            firstOccurrence = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (firstOccurrence == -1) {

        vector<int> result;
        result.push_back(-1);

        return result;
    }

    left = firstOccurrence;
    right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            count = mid - firstOccurrence + 1;
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    vector<int> result;
    result.push_back(firstOccurrence);
    result.push_back(count);

    return result;
}

int main() {
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(10);
    arr.push_back(10);
    arr.push_back(10);
    arr.push_back(20);
    int target = 5;

    vector<int> result = findTargetInfo(arr, target);


    if (result[0] == -1) {
        cout << "Target value not found in the array" << endl;
    } else {
        cout << "First occurrence of the target value: " << result[0] << endl;
        cout << "Number of occurrences of the target value: " << result[1] << endl;
    }

    return 0;
}