/*------------------------------------------------------------------|
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 



以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

 



图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

 

示例:

输入: [2,1,5,6,2,3]
输出: 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	单调栈 + 常数优化法
*
*	执行用时：8 ms, 在所有 C++ 提交中击败了95.23%的用户
*	内存消耗：8.6 MB, 在所有 C++ 提交中击败了36.23%的用户
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
	int n = heights.size();
	int res = 0;
	vector<int> left(n);
	vector<int> right(n, n);
	stack<int> pos;

	for (int i = 0; i < n; i++) {
		while (!pos.empty() && heights[i] <= heights[pos.top()]) {
			right[pos.top()] = i;
			pos.pop();
		}
		left[i] = pos.empty() ? -1 : pos.top();
		pos.emplace(i);
	}

	for (int i = 0; i < n; i++) {
		res = max(heights[i] * (right[i] - left[i] - 1), res);
	}
	return res;
}

int main() {
	vector<int> heights = { 2,3 };
	int res = largestRectangleArea(heights);
}