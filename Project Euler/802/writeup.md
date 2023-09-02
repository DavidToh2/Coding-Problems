## Problem 802

We define $f(x, y) = (x^2 - x - y^2, 2xy - y + C)$, where $C = \pi$. A pair $(x, y)$ is said to have period $n$ if $n$ is the smallest positive integer such that $f^n(x, y) = (x, y)$. 

Let $f(n)$ denote the sum of $x$-coordinates across all points with period exactly $n$, and let $P(n) = f(1) + f(2) + \cdots + f(n)$. Find $P(10^7) \pmod{1020340567}$.

Answer: $973873727$

## Solution

We rewrite the function as a bivariate sequence:
$$x_{n+1} = x_{n}^2 - x_{n} - y_{n}^2, \quad y_{n+1} = 2x_{n}y_{n} - y_{n} + C$$

Observe that
$$x_{n+1} - \frac{1}{2} = \left(x_{n}^2 - x_{n} + \frac{1}{4}\right) - y_{n}^2 - \frac{3}{4} = \left(x_{n} - \frac{1}{2}\right)^2 - y_{n}^2 - \frac{3}{4}$$
$$y_{n+1} = 2\left(x_{n} - \frac{1}{2}\right)y_{n} + C$$

Define $j = \frac{3}{4} - iC, w_{n} = x_{n} - \frac{1}{2} + iy_{n}$. Then observe that
$$w_{n+1} = x_{n+1} - \frac{1}{2} + iy_{n+1} = w_n^2 - j$$

If the sequence is periodic with period $n$, then
$$w_n = w_{n-1}^2 - j = (w_{n-2}^2 - j)^2 - j = \cdots = \left(\cdots\left((w_0^2 - j)^2 - j\right)^2\cdots\right)^2 - j = w_0$$

Because there are $n$ squarings, we obtain a complex-valued polynomial of degree $2^n$, which definitely has $2^n$ complex roots. Each root of this polynomial is a term of the sequence whose period is a factor of $n$.

By Vieta's formula, the roots sum to $0$. Hence, their real parts sum to $0$. Recalling that the real part is given by $x - \frac{1}{2}$, we see that 

$$\sum_{d \mid n} \sum_{(x, y) \text{ has period } d} x = \sum_{d \mid n} f(d) = 2^{n-1}$$

At this point, we may proceed to use a sieve to efficiently calculate the values of $f(n)$ all the way up to $n = 10^7$, by subtracting the pre-computed values of $f(d)$ for its proper divisors from $2^{n-1}$. This is the implemented solution.

We may also perform a Mobius transform, which tells us
$$f(n) = \sum_{d \mid n} \mu(d) 2^{\frac{n}{d} - 1}$$
where $\mu(d)$ is the Mobius function. Summing then gives us this following, direct formula for $P(n)$.

$$\begin{align*} P(n) & = \sum_{k=1}^{n} \sum_{d \mid k} \mu(d)2^{\frac{k}{d} - 1} = \sum_{d=1}^{n}\mu(d)\sum_{d \mid k, k \leq n}2^{\frac{k}{d} - 1} \\ & = \sum_{d=1}^{n}\mu(d)\left(\sum_{k=1}^{\lfloor\frac{n}{d}\rfloor}2^{k-1}\right) = \sum_{d=1}^{n}\mu(d)\left(2^{\lfloor\frac{n}{d}\rfloor}-1\right) \end{align*}$$

Unfortunately, computing the Mobius function is not very time-efficient (unless there's some hack that I'm not aware of), so this solution was not used.