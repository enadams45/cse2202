#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findCombinations(vector<int>& arr, int target, vector<int>& combination, int start, vector<vector<int>>& result) {
    if (combination.size() == 3) {
        int sum = combination[0] + combination[1] + combination[2];
        if (sum == target) {
            result.push_back(combination);
        }
        return;
    }

    for (int i = start; i < arr.size(); ++i) {
        // Skip duplicates
        if (i > start && arr[i] == arr[i - 1]) continue;

        // First number: If greater than target, stop further processing
        if (combination.size() == 0 && arr[i] > target) break;

        // Second number: If the sum of the first two exceeds the target, stop further search
        if (combination.size() == 1 && combination[0] + arr[i] > target) break;

        combination.push_back(arr[i]);
        findCombinations(arr, target, combination, i + 1, result);
        combination.pop_back();  // Backtrack
    }
}

vector<vector<int>> threeSumCombinations(vector<int>& arr, int target) {
    vector<vector<int>> result;
    vector<int> combination;

    // Sort the array to handle duplicates and apply pruning logic
    sort(arr.begin(), arr.end());

    findCombinations(arr, target, combination, 0, result);

    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int target = 10;

    vector<vector<int>> combinations = threeSumCombinations(arr, target);

    for (const auto& comb : combinations) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
