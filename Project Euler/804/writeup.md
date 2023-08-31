## Problem 804

Let $g(n)$ be the number of pairs of integers $(x, y)$ such that $x^2 + xy + 41y^2 = n$. Let $T(n) = g(1) + g(2) + \cdots + g(n)$. We seek $T(10^{16})$.

Answer: $4921370551019052$

## Solution

The quadratic equation $x^2 + xy + (41y^2 - n) = 0$ has discriminant
$$ D = y^2 - 4(41y^2 - n) = 4n - 163y^2 $$
For $x$ to also be integral, $D$ must be a perfect square, so we may let $D = z^2$ where $z \geq 0$. Then
$$ x = \frac{-y \pm z}{2} $$
meaning that, for every pair $(y, z)$ of non-zero positive integers satisfying $163y^2 + z^2 = 4n$, we are able to obtain four pairs of solutions $(x, y)$ by swapping the signs of $y$ and $z$. 

For those pairs $(y, z)$ of nonnegative integers where one of the two terms is zero, we will be able to obtain two pairs of solutions by swapping the signs of the nonzero term.

Hence, to get $g(n)$, we just need to count the number of lattice points $(y, z)$ on the ellipse $163y^2 + z^2 = 4n$, of the following three types:
- $y = 0$, which contributes two solutions to $g(n)$;
- $z = 0$, which contributes two solutions;
- $y, z \neq 0$, which contributes four solutions.

Note that $y, z$ must both be of the same parity.

To get $T(n)$, we just need to count the number of lattice points $(y, z)$ **in, or on,** the very same ellipse, with the same conditions as described above.

To do so, we may traverse along the perimeter of the ellipse, starting at the interior lattice point on the line $y=1$ closest to the perimeter. (The corresponding value of $z$ is computed directly.) 

Every time we increment $y = y'$, we compute the value of $z = z_{max}$ that gives the interior lattice point on the line $y = y'$ closest to the perimeter. This will give us the number of interior lattice points $(y', z)$ satisfying $1 \leq z \leq z_{max}$ and $y' \equiv z \pmod{2}$. We do this until $z_{max}^2 = 4n - 163y'^2$ is no longer positive.

We then compute the number of interior lattice points on the lines $y = 0$ and $z = 0$ separately. Finally, we add everything up, not forgetting to multiply by $4$ or by $2$ as needed!