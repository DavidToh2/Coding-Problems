## Problem 801

Define $f(n)$ as the number of pairs of positive integers $(x, y)$, where $0 < x, y \leq n^2-n$, satisfying
$$x^y \equiv y^x \pmod{n}.$$

Define $\displaystyle S(M, N) = \sum_{M \leq p \leq n, p \text{ prime}} f(p)$. Determine the value of $S(10^{16}, 10^{16} + 10^6) \pmod{993353399}$.

Answer: $638129754$

## Solution 1

Let $0 < x < p$ and let $ord_p(x) = d$. Define $R(x)$ as the set of remainders attainable by powers of $x \pmod{p}$, i.e. the set $\{1, x, x^2, \ldots x^{d-1} \}$. Define $c(x) = \frac{p-1}{d}$.

We start with the following observation. Fix $0 < x, y < p$, and let $ord_p(y) = d$. Notice that the set
$$\{y^{x}, y^{x+p}, y^{x+2p}, \ldots, y^{x+(p-2)p} \} \equiv \{ y^{x}, y^{x+1}, y^{x+2}, \ldots, y^{x+p-2} \} \pmod{p}$$
is composed of $c(x)$ copies of the set $R(y)$. Hence, as long as $x^y \in R(y)$, then there will definitely be $c(x)$ solutions $(x', y)$ satisfying $x' \equiv x \pmod{p}$.

All numbers $y' \equiv y \pmod{p}$ can be checked using the exact same procedure, yielding either 0 or $c(x)$ solutions $(x', y')$ for each fixed value of $y'$, depending on whether $x^{y'} \in R(y') = R(y)$. Again, notice that the set
$$\{ x^y, x^{y+p}, x^{y+2p}, \ldots, x^{y+(p-2)p} \}$$
is comprised of $c(y)$ copies of the set $R(x)$. Hence, as long as $x^{y'} \equiv C \in R(y)$, then we can find $c(x)$ values $y'$ that give the same residue $C$.

In other words, we can look at the number of common elements of $R(x)$ and $R(y)$, and multiply this by $c(x)c(y)$, to get the number of solutions $(x', y') \equiv (x, y) \pmod{p}$. 

We may interpret this algorithm bijectively as such. For each residue $0 < r < p$, consider all the residue classes $0 < x < p$ for which $r \in R(x)$. Compute the sum
$$\sum_{\text{unordered } (x_1, x_2)} c(x_1)c(x_2) = \left(\sum_{x} c(x)\right)^2$$
This gives us the number of solutions $(x, y)$ where $p \nmid x, y$. Finally, we add $(p-1)^2$ pairs $(x, y)$ wit $p \mid x, y$ to get the value of $f(p)$.

## Solution 2

Unfortunately, solution 1 is too computationally inefficient. So we need a better way!

Let $0 < x, y \leq p^2-p$, let $g$ be a primitive root of $p$, and let $x \equiv g^a, y \equiv g^b \pmod{p}, 0  \leq a, b < p-1$. Then
$$x^y \equiv y^x \Leftrightarrow g^{ay} \equiv g^{bx} \pmod{p} \Leftrightarrow ay \equiv bx \pmod{p-1}$$
Notice that, in the above equation, we may not treat $a, b, x, y$ as completely independent variables. However, if we only look at their values $\pmod{p-1}$, then we may do so! 

In other words, let $0 \leq a, b, x', y' < p-1$ be independent variables and let $x, y \equiv x', y' \pmod{p-1}$. There is exactly one value 
$$x \in \{x', x'+(p-1), x'+2(p-1), \ldots, x'+(p-1)^2\}, \quad x \equiv g^a \pmod{p}$$
and the same thing can be said for $y$. Hence, every quadruplet of such four independent variables satisfying $ay' \equiv bx' \pmod{p-1}$ will biject to a unique pair $0 < x , y \leq p(p-1)$ satisfying the problem statement.

It thus suffices to compute the number of such quadruplets. This is apparently "well-known enough" that I had to spoil the solution for myself and realise that it's just an OEIS sequence.

**Lemma**. For every $N = p_1^{a_1}p_2^{a_2}\cdots p_k^{a_k}$, the number of quadruplets $(a, b, x, y)$ with $ay \equiv bx \pmod{N}$ is given by $g(N)$ where
$$g(N) = \prod g(p_i^{a_i}), \quad \text{ where } g(p^a) = p^{2a-1}(p^{a+1} + p^{a} - 1)$$

Factorising $N = p-1$, then directly plugging in this formula, gives us a much faster solve for $f(p)$!