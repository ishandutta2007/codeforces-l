import sys
import math

f = sys.stdin

n = int(f.readline())


print n * (n-1) * (n-2) * (n-3) * (n-4) / 1 / 2 / 3 / 4 / 5 +n * (n-1) * (n-2) * (n-3) * (n-4) * (n-5) / 1 / 2 / 3 / 4 / 5 / 6 + n * (n-1) * (n-2) * (n-3) * (n-4) * (n-5) * (n-6) / 1 / 2 / 3 / 4 / 5 / 6 / 7