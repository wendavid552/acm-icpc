/*
bzoj#1100
给一个多边形，求对称轴的数量
1.能先找到一条吗？
2.对称轴对称之后，对例如说中心有什么特征吗？
test cases = 10
n <= 1e6
考虑枚举对称轴，然后两边“回文” -> 旋转角+边长一致就是特征！
*/
#include<cstdio>
using namespace std;

