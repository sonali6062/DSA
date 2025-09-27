class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double max_area = 0.0;

        auto area = [&](vector<int>& a, vector<int>& b, vector<int>& c) {
            return fabs(a[0] * (b[1] - c[1]) +
                        b[0] * (c[1] - a[1]) +
                        c[0] * (a[1] - b[1])) / 2.0;
        };

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    max_area = max(max_area, area(points[i], points[j], points[k]));
                }
            }
        }
        return max_area;
        
    }
};
