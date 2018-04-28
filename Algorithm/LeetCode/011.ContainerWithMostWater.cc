/*
Given n non-negative integers a1, a2, ..., an, where each represents a point
 at coordinate (i, ai). n vertical lines are drawn such that the two endpoints 
 of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis 
 forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int area;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            // The area is determined by the shorter edge
            // area = (right - left) * min(height[left], height[right]);
            area = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
            // maxArea = max(area, maxArea);
            maxArea = area > maxArea ? area : maxArea;
            if (height[left] < height[right]) {
                do {
                    ++left;
                } while (left < right && height[left - 1] >= height[left]);
            } else {
                do {
                    --right;
                } while (left < right && height[right + 1] >= height[right]);
            }
        }
        
        return maxArea;
    }
};

int main() {
    
}