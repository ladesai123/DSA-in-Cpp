/*
 * Title: Maximum Powerful Integer
 * Description: Given a list of intervals and a threshold k, 
 * find the maximum integer that is present in at least k intervals.
 *
 * Approach:
 * We use a line sweep technique (also known as prefix sum or difference array) 
 * to track how many intervals overlap at each integer point.
 * 
 * 1. For each interval [start, end], we:
 *    - Add +1 at 'start' to mark the beginning of an interval
 *    - Add -1 at 'end + 1' to mark the end of an interval
 * 
 * 2. We use a map (ordered) to store these changes in overlap count.
 * 
 * 3. We iterate through the map while maintaining a running sum (current overlap).
 *    - When the overlap reaches or exceeds 'k', we mark the start of a powerful segment.
 *    - When it drops below 'k', we end the segment and update the maximum powerful integer.
 * 
 * Time Complexity: O(n log n)
 *  - Due to insertion and iteration over the ordered map (log n per insert).
 * 
 * Space Complexity: O(n)
 *  - We store two entries per interval: start and end+1.
 * 
 * Why this is optimal:
 * - Brute force checking each integer for all intervals takes O(n * range), which is inefficient.
 * - This approach is fast and elegant using event-based sweeping.
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int findMaxPowerfulInteger(vector<vector<int>>& intervals, int k) {
    map<int, int> lineSweep;

    // Mark +1 at start and -1 at end+1
    for (auto& interval : intervals) {
        int start = interval[0], end = interval[1];
        lineSweep[start] += 1;
        lineSweep[end + 1] -= 1;
    }

    int currentOverlap = 0;
    int maxPowerful = -1;
    int rangeStart = -1;

    // Iterate through all sorted keys
    for (auto& [point, delta] : lineSweep) {
        currentOverlap += delta;

        if (currentOverlap >= k) {
            // Beginning of a powerful range
            if (rangeStart == -1)
                rangeStart = point;
        } else {
            // End of powerful range
            if (rangeStart != -1) {
                maxPowerful = max(maxPowerful, point - 1);
                rangeStart = -1;
            }
        }
    }

    return maxPowerful;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    int k;
    cin >> k;

    int result = findMaxPowerfulInteger(intervals, k);
    cout << result << endl;

    return 0;
}
