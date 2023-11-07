#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> s;
    int maxArea = 0;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && heights[i] < heights[s.top()]) {
            int height = heights[s.top()];
            s.pop();

            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }

    while (!s.empty()) {
        int height = heights[s.top()];
        s.pop();

        int width = s.empty() ? n : n - s.top() - 1;
        maxArea = max(maxArea, height * width);
    }

    return maxArea;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> heights(N);
        for (int i = 0; i < N; ++i) {
            cin >> heights[i];
        }

        int result = largestRectangleArea(heights);
        cout << result << endl;
    }

    return 0;
}
