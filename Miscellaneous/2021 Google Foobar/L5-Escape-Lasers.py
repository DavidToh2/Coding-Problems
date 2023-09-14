    
    # I had a lot of issues with Python's calculation precision.
    # I'll admit, the sqrt_2 and ten_power longs were inspired
    # by the solution at this website: https://surajshetiya.github.io/Google-foobar/
    
    # The main body of the problem is essentially a math exercise.
    # We look at a[n] = floor(n*(sqrt(2)-1)), and show that:
    # if a[n+1]-a[n] = 1, then there must exist some m such that
    # a[m], a[m+1], a[m+2] = n.
    # In layman's terms, if the sequence a[n] "jumps" at n, then
    # there is a 3-block of n's in the sequence. All other numbers
    # feature 2-blocks.
    # This claim can be proven using some good-old fashioned
    # math olympiad-style algebra.
    
    # Once we've shown the claim, the calculation involves taking 2
    # copies of all numbers up to the highest number we're considering,
    # then adding in one copy of all the numbers which appear 3 times.
    # By our claim, these numbers are also all "jump" numbers, and are
    # less than the highest number we're considering, so we can
    # form a recursion from here.

def maximumSoFar(s):
    sqrt_2 = 41421356237309504880168872420969807856967187537694807317667973799073247846210703885038753432764157273501384623091229702492483605585073721264412149709993583141322266592750559275579995050115278206
    ten_power = 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
    return (s * sqrt_2 / ten_power)

def partialSolution(s):
    if s <= 2:
        return 0
    elif s == 3:
        return 1
    elif s == 4:
        return 2
    answer = 0
    # In the rest of the problem, we look at sqrt(2)-1.
    
    # We'll get the two values of floor(n*(sqrt(2)-1)) before s.
    # This lets us count the no. of elements equal to the maximum
    # value.
    surroundingList = []
    for i in range(0, 3, 1):
        surroundingList.append(maximumSoFar(s-2+i))
    maximum = surroundingList[2]
    
    # Measures how long the block is
    before = 0
    for i in range(0, 2, 1):
        if surroundingList[i] == maximum:
            before += 1
    
    # Adds up all the elements less than maximum
    answer += maximum * (maximum - 1)
    # Adds up all the elements equal to maximum
    answer += maximum * (before + 1)
    
    # Finally, adds one more copy of all the elements that appeared
    # thrice. If some element m appeared thrice, then m must be the
    # largest value of n for which maximumSoFar(n) = k for some 
    # constant k. Furthermore, k increments by 1: i.e. there is a unique
    # value of m for every non-negative integer k.
    # (The sequence is 2, 4, 7, 9, 12, ...)
    
    # We can invert the above property on its head by considering what
    # happens when we take t*maximumSoFar(t) - partialSolution(t).
    answer += maximum*maximumSoFar(maximum) - partialSolution(maximum)
    return answer
    
def solution(t):
    if t % 2 == 0:
        r1 = t / 2
        r = r1 * (t+1)
    else:
        r1 = (t+1)/2
        r = t * r1
    return str( r+partialSolution(t) )