## Problem 803

The objective of this problem is to reverse-engineer the starting term of the pseudo-random number generator
$$a_{n+1} = Ca_{n} + 11 \pmod{2^{48}}, \quad b_n = \left\lfloor\frac{a_n}{2^{16}}\right\rfloor \pmod{52}$$
where $C = 25214903917$, given a sequence of 9 terms $b_i$; and also to determine the smallest distance between two members of the sequence.

Answer: $9300900470636$

## Attempt at Reverse Engineering

Define $f(x) = Cx + 11 \pmod{2^{48}}$. We may split each term of the sequence into its first 32 and last 16 bits, like so:
$$a_n = x_n \cdot 2^{16} + y_n$$

Each term of the sequence can be calculated from its previous term like so:

1. Calculate $f(y_n)$. This is in turn split into two parts:
   - The last 16 bits give $y_{n+1}$;
   - The "overflow bits" $overflow(y_n)$ will spill over into the first 32 bits of the next term.
2. Calculate $Cx_n + overflow(y_n) \pmod{32}$, which gives $x_{n+1}$.

For each $0 \leq y_n < 65535 = 2^{16} - 1$, the corresponding $y_{n+1}$ and $overflow(y_n)$ values in step 1 can be precomputed, allowing us to focus on step 2.

A slight optimisation can be made by only testing those values of $x_0$ in step 2 for which the first alphabet is correct.

Nevertheless, this algorithm is essentially brute force as, for each value of $x$, all 65536 values of $y$ need to be tested in the worst case scenario. Hence, the number of computations required is approximately $\lfloor\frac{2^{32}}{52}\rfloor \cdot 2^{16}$, which is not great.

Runtime:
- "EULERcats": 3681.165s = 1.02h (for 1.2e9 cases of $x$)
- "PuzzleOne": 8714.695s = 2.42h (for 2.2e9 cases of $x$)

## Part 1: Reverse Engineering

Sadly I had to spoil myself because I was fed up with the slow, brute force method.

The crucial observation is that 52 is divisible by 4. Hence, by taking $b_n \pmod{4}$, we can obtain the values of the 17th and 18th bits (from the back) of each of the terms $a_0, a_1, \ldots, a_8$.

We then brute force all 18-bit numbers to determine a valid "seed" starting term that ensures that the 17th and 18th bits are correct for these first 9 terms.

We can throw away the 17th and 18th bits now to avoid confusion, and extract the first 16 bits of this seed. (This is the $y_0$ in our attempt.)

Finally, we brute force all $\lfloor\frac{2^{32}}{52}\rfloor$ possible values of $x_0$, similar to our attempt. However, this is significantly faster as our value of $y_0$ is already known, so we do not have to iterate on $y_0$.

Runtime:
- "EULERcats": 81.2ms
- "PuzzleOne": 147.6ms
- "LuckyText": 172.6ms

## Part 2: Discrete Logarithm

From Part 1, we obtain the constants
- "PuzzleOne": $a_0 = 144933752257087$
- "LuckyText": $a_n = 160163661474491$

Our objective is to determine the value of $n$. We perform a small algebraic trick:
$$a_{k+1} - a_k \equiv (Ca_k + 11) - (Ca_{k-1} + 11) \equiv C(a_k - a_{k-1}) \pmod{2^{48}}$$

Hence, we compute $A = a_1 - a_0 = 99607973670047, B = a_{n+1} - a_{n} = 151992572250351$. We require the smallest positive integer $n$ such that
$$A \cdot C^{n} \equiv B \pmod{2^{48}}$$

We will recursively find positive integers $n_i$ such that
$$A \cdot C^{n_i} \equiv B \pmod{2^{i}}, \quad 1 \leq i \leq 48$$

For this, we first note that for any odd $x$, we have $x^{\phi(2^{i})} = x^{2^{i-1}} \equiv 1 \pmod{2^i}$. This means that $ord_{2^i}(x)$ is a power of 2 that is at most $2^{i-1}$. Additionally, note that $ord_{2^i}(x) \mid ord_{2^{i+1}}(x)$.

Hence, we define the following recursive algorithm: 
- for each $1 \leq i \leq 48$, determine $ord_{2^i}(C)$ recursively;
- define $n_1 = 0$;
- having found $n_i$, we will now find $n_{i+1} = n_i + k\cdot ord_{2^{i}}(C)$. (This is because the value of the LHS $\pmod{2^i}$ cannot change.)

For the first part of this algorithm, raw computation tells us that
$$ord_{2^i}(C) = 2^{i-2} \quad  \forall 2 \leq i \leq 48.$$

This can be used in the second part: if $A\cdot C^{n_i} \equiv B \pmod{2^i}$ but not $\pmod{2^{i+1}}$, then we simply need to add one copy of $ord_{2^i}(C)$, which is $2^{i-2}$, to the exponent $n_i$, to get to $n_{i+1}$.

This allows us to get our final answer!