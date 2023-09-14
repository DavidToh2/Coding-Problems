# Problem redefinition:
    
    # The problem was worded very confusingly. It's basically asking us to
    # construct the smallest set S, size n, and a collection of s (equally
    # sized?) subsets of S, such that:
    
    # the union of any t subsets amongst the collection equals to S, but
    # the union of any t-1 subsets is missing elements of S.
    # (We know that n should be minimised, since the question says that
    # the no. of keys issued isn't more than what is necessary.)
    
    # soln(r,1): S = {1}, s = {[1],[1],[1],...}
    # soln(r,2): S = {1,2,...,r}, s = {[everything except 1], [except 2],...}
    # soln(3,3): S = {1,2,3}, s = {[1],[2],[3]}
    # soln(4,3): We can't do {[1],[1],[2],[3]} since the first three
    # subsets do not satisfy the problem condition. The answer is actually
    # S = {1 to 6}, s = {[1,2,3],[1,4,5],[2,4,6],[3,5,6]}

# Motivation:

    # One way of seeing this is: ideally, for any element e, there are exactly
    # t-1 subsets without e in it, and so s-t+1 subsets with e in it.
    # (This is so we can pick the t-1 subsets, and still be short of S.;
    # but pick any t subsets, and be sure e is in its union.)
    
    # This means there are n(s-t+1) elements, allowing multiplicity. Each
    # set must then have n(s-t+1)/s = n - n(t-1)/s elements.
    
# Let's try to prove that this ideal situation indeed gives us the solution.
    
    # Claim 1: every (t-1)-tuple of subsets has a single, unique
    # missing element.
    
    # Proof: suppose e is missing from two different (t-1)-tuples. Their
    # union contains at least t subsets, contradiction!
    # Suppose both e and f are missing from our (t-1)-tuple. Then every
    # other subset must contain both e and f. This means we can merge
    # e and f to be one element. 
    
    # Claim 2: every element e is missing from exactly t-1 subsets.
    
    # Proof: Clearly, it can't be missing from more than t-1 subsets. On the
    # other hand, if it were missing from less than t-1 subsets...then it is
    # superfluous, and can be removed, since it will never contribute
    # as a "missing element".
    
    # Combining claims 1 and 2, we get that n = (s choose t-1). The size
    # of each subset is (s-1 choose t-1).
    
    # Since each element is missing in exactly t-1 subsets, there are s
    # subsets, and there are n elements, we have a bijection here! Thus,
    # it suffices to generate all unique binary s-tuples with exactly
    # t-1 zeroes. To ensure the solution is lexographically minimised,
    # element 0 will start from the back.
    

def solution(s, t):
    n = comb(s, t-1)
    m = comb(s-1, t-1)
    binaryList = generate_binary(s, t-1)
    solutionList = []
    for j in range(0, s, 1):
        solutionList.append([])
    for i in range(0, n, 1):
        targetList = binaryList[-i-1]
        for k in range(0, s, 1):
            if targetList[k] == 1:
                solutionList[k].append(i)
                
    return solutionList
    
def comb(n,r):
    if n == 0:
        return 1
    elif r == 0 or r == n:
        return 1
    else:
        answer = comb(n-1,r-1)+comb(n-1,r)
        return answer

def generate_binary(size, no_of_zeroes):
    if size == 1:
        if no_of_zeroes == 1:
            return [[0]]
        else:
            return [[1]]
    elif size == no_of_zeroes:
        add_zeroo = generate_binary(size - 1, no_of_zeroes - 1)
        for k in add_zeroo:
            k.insert(0,0)
        return add_zeroo
    else:
        add_one = generate_binary(size - 1, no_of_zeroes)
        for j in add_one:
            j.insert(0,1)
        if no_of_zeroes == 0:
            return add_one
        else:
            add_zero = generate_binary(size - 1, no_of_zeroes - 1)
            for k in add_zero:
                k.insert(0,0)
            return add_zero + add_one