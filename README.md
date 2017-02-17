# PAT-a-practice
PAT (Advanced Level) Practise solutions
https://www.patest.cn/contests/pat-a-practise

# note #
### 1021. Deepest Root  ###
一种方法是每一个vertice都DFS或BFS。然后选择deepest root的vertice。但是可能会超时。
另一种方法是使用两次DFS。第一次任选一个vertice进行DFS，得到deepest root的点集s1, 然后从s1中任选一点，再进行一次DFS，得到deepest root的点集s2，s1 U s2就是所求的点集。这种方法是从树的性质得到：
对于每一条最长的路径S->D，那么 S或D 也是其它顶点的deepest root。可用反证法证明。

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

