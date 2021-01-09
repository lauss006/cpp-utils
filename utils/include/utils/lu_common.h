#ifndef _LU_COMMON_H
#define _LU_COMMON_H
#include <vector>
#include <algorithm>

namespace lu
{

class LU_Common
{
public:
	// 使用字典序，生成所有排列
	template<typename T>
	static void genAllPermutation(std::vector<T> vIn, std::vector<std::vector<T> > &vOut);
};

template<typename T>
void LU_Common::genAllPermutation(std::vector<T> vIn, std::vector<std::vector<T> > &vOut)
{
	// i = max{ j : p[j-1] < p[j] }
	// j = max{ k : p[i-1] < p[k] }
	// 交换 p[i - 1], p[j]
	// 反转 p[j] 之后的元素( 下边 i-1 之后)

	do
	{
		vOut.push_back(vIn);
		int i = -1;

		for (int j = vIn.size() - 1; j >= 1; --j) {
			if (vIn[j] > vIn[j-1]) {
				i = j;
				break;
			}
		}

		if (-1 == i) { return; }

		int j = -1;
		for (int k = vIn.size() - 1; k > i-1; --k) {
			if (vIn[k] > vIn[i-1]) {
				j = k;
				break;
			}
		}

		if (-1 == j) { return; }

		std::swap(vIn[i-1], vIn[j]);
		std::reverse(vIn.begin() + i, vIn.end());

	} while (true);

}

}

#endif
