# 导论

## 数学知识复习

### 指数
1. $$x^ax^b=x^{a+b}$$
2. $$\frac{x^a}{x^b}\quad = x^{a-b}$$
3. $$(x^a)^b=x^{ab}$$
4. $$x^n+x^n=2x^n\not = x^{2n}$$
5. $$2^n+2^n=2^{n+1}$$
### 对数
**计算机科学中所有的对数，除非特殊声明，均以2为底。**  
定义：$x^A=B$,当且仅当$log_x^B = A$。  
有以下定理成立：
1. $$log_b^a = \frac {log_c^a}{log_c^b}\quad$$
2. $$log^{AB}=log^A+log^B$$
3. $$log^\frac{A}{B}\quad=log^A-log^B$$
4. $$log^{(A^B)}=Blog^A$$
5. $$log^x < x, \exists x>0$$
6. $$log^2=1;log^1=0;log^{1024}=10;log^{1048576}=20$$
### 级数
1. $$\sum_{t=0}^{N}2^t=2^{N+1}-1$$
2. $$\sum_{t=0}^{N}A^t=\frac{A^{N+1}-1}{A-1}\quad$$
3. $$\sum_{t=0}^{N}A^t\le\frac{1}{1-A}\quad, \forall A \in(0,1)$$
4. $$\sum_{t=0}^{n}i^2=\frac{N(N+1)(2N+1)}{6}\quad$$

### 模运算
$$若A\equiv B(mod N),则 A+C \equiv B+C(mod N) 且AD\equiv BD(mod N)。$$
