from math import gcd
from collections import defaultdict
def solve(fractions):
  visited= defaultdict(0)
  ans = 0
  for n, d in fractions:
      g = gcd(n,d)
      n=n//g # reducing the numerator
      d=d//g # reducing the denominator
      # checking if there is a complementary value of that number i.e 1-(n/d)
      ans += seen[(d - n, d)]
      # if there is a value in the fractions then we add 1 to the ans
      seen[(n, d)] += 1
      # updating the current value as seen in the dictionar
  return ans
 
