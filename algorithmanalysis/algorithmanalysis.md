# 算法分析

算法(algorithm):为求解一个问题需要遵守的、被清楚指定的简单指令的集合。

## 数学基础 
定义：
1. 如果存在正常数 $c$和 $n_0$,使得 $N \ge n_{0}$ 时，$T(N) \le cf(N)$,则记为 $T(N)=O(f(N))$。
2. 如果存在正常数 $c$和 $n_0$,使得 $N\ge n_{0}$时, $T(N) \ge cg(N)$,则记为 $T(N)=\Omega (g(N))$。
3. $T(N)=\Theta (h(N))$当且仅当$T(N)=O(h(N))且T(N)=\Omega (h(N))$
4. 如果$T(N)=O(h(n))且T(N)\ne \Omega (h(n)),则T(N)=o(h(n))$  

推导规则:
1. 如果$T_1(N)=O(f(N))且T_2=O(g(n))$，那么有:  
   a.  $T_1(N)+T_2(N)=max(O(f(n)), O(g(n)))$  
   b.  $T_1(N)*T_2(N)=O(f(n)*g(n))$
2. 如果$T(N)$是一个$k$多项式，则$T(N)=\Theta(N^k)$
3. 对任意常数$k, log^{kN}=O(N)$。对数增长缓慢。


