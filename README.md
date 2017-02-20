# PAT-a-practice
PAT (Advanced Level) Practise solutions
https://www.patest.cn/contests/pat-a-practise

# note #
### 1018. Public Bike Management ###

首先Dijsktra算法遍历图得到起点到终点的最小距离。
然后DFS 计算sent 和 take back自行车数量，在距离等于最小距离的情况下，选择sent最小的一个，如果sent相同，选择take back最小的一个。



### 1021. Deepest Root  ###
一种方法是每一个vertice都DFS或BFS。然后选择deepest root的vertice。但是可能会超时。
另一种方法是使用两次DFS。第一次任选一个vertice进行DFS，得到deepest root的点集s1, 然后从s1中任选一点，再进行一次DFS，得到deepest root的点集s2，s1 U s2就是所求的点集。这种方法是从树的性质得到：
对于每一条最长的路径S->D，那么 S或D 也是其它顶点的deepest root。可用反证法证明。

### 1022. Digital Library ###
倒查表。 注意ID可能以0开头，所以用string类型比较好。

###  1026. Table Tennis ###
排队模拟。
对于队首的player，对其到达的时间而论：
如果有空桌子，那么第一个排队的人如果是vip，则挑选vip编号最小的桌子(如果有vip桌子),否则挑选编号最小的桌子；如果没有空桌子，那么等待最先结束的桌子，如果是vip桌子，那么队伍里选择第一个vip player；否则选择队首的player。

### 1033.  To Fill or Not to Fill ###
贪心算法。分为如下几个情况：

1. 在当前站的已有的gas可及距离内，找到比当前站最便宜的那一站作为下一站；
2. 如果找不到符合条件1）的站点，那么

     2.1 在当前站的最大gas可及距离内，找到比当前站便宜的第一站作为下一站，然后在本站加油至正好到下一站；

     2.2 如果找不到符合条件2.1的站点，那么加满油，找到之后可及站点中最便宜的那一站作为下一站。


### 1034. Head of a Gang  ###
求 图中满足Weight > Threshold 的独立集数目以及独立集中Weight最大的顶点。
用set模拟独立集。每读取一条边，对两个顶点按在已知独立集中的位置分类讨论即可。

**注意事项：**

1.  满足题意的一个独立集包含顶点最小数目是3

2.  由于题中的人名是 "a string of three capital letters chosen from A-Z"， 直接用一个26 * 26 * 26的数组计数即可。

### 1039. Course List for Student ###
注意用scanf输入和printf输出，否则由于数据量太大，用cin和cout导致最后一个case超时。

### 1044. Shopping in Mars ###
一次遍历即可。类似于求MaxSequenceSum的解法。注意，同1039类似，此题也要用scanf和printf处理io。

### 1045. Favorite Color Stripe ###
动态规划问题。等价于可重复的LCS问题。递归公式如下：
**d[i][j] = d[i][j-1] + 1, if s1[i]==s2[j];
     = max(d[i][j-1], d[i-1][j]}, else;**

### 1055. The World's Richest ###
暴力法会导致一个测试点超时。本题的关键是在于  M (<= 100) - the maximum number of outputs 。因此对于Age = i 的人， 可以只考虑排序后的前100个。这样一个剪枝过程后，可以通过所有测试点。

### 1057. Stack ###
采用两个multiset存储以median值分割的两部分，每一次push就调整这两个multset和median值。由于multiset内部采用Balanced Tree的结构实现，因此push和pop的时间均只需要log(N).
注意multiset的erase函数对于iterator和value操作的不同。

### 1060. Are They Equal  ###
去有效数字和指数即可。但是需要考虑的测试点较多，如果考虑不完全，可能会有1~2个case not pass。
对于最后一个测试点，考虑  
	**2 0.00 0** 
的的情况。