# Solved with Brandon.

r, s, m, d, n = map(int, input().split())

# 2D arrays for starters, main, dessert
ingredients = list(map(int, input().split()))
meals = [list(map(lambda x: int(x) - 1, input().split()))[1:] for _ in range(s+m+d)]
el = set()

for _ in range(n):
    x, y = map(int, input().split())
    x-=1
    y-=1
    x, y = min(x, y), max(x, y)
    el.add((x, y))

ans = 0
for starter in range(s):
    for main in range(s, m+s):
        if (starter, main) in el: continue
        for dessert in range(m+s, m+s+d):
            if (starter, dessert) in el: continue
            if (main, dessert) in el: continue

            usedIngredients = set()
            for ing in meals[starter]: usedIngredients.add(ing)
            for ing in meals[main]: usedIngredients.add(ing)
            for ing in meals[dessert]: usedIngredients.add(ing)

            cur = 1
            for ing in usedIngredients:
                cur *= ingredients[ing]
                if cur > 1e18: 
                    print("too many")
                    exit()

            ans += cur
            if ans > 1e18: 
                print("too many")
                exit()

print(ans)