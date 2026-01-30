#Iterative Method (Most Common)
def is_armstrong(n):
    temp = n
    digits = len(str(n))
    sum_ = 0

    while n > 0:
        d = n % 10
        sum_ += d ** digits
        n //= 10

    return temp == sum_

n = int(input("Enter a number: "))
print(is_armstrong(n))


#Using Recursion
def armstrong(n, power):
    if n == 0:
        return 0
    return (n % 10) ** power + armstrong(n // 10, power)

n = int(input("Enter a number: "))
power = len(str(n))
print(n == armstrong(n, power))


#Using String Method (Easiest)
def is_armstrong(n):
    digits = len(str(n))
    return n == sum(int(d) ** digits for d in str(n))

n = int(input("Enter a number: "))
print(is_armstrong(n))


# | Method    | Time Complexity | Space Complexity |
# | --------- | --------------- | ---------------- |
# | Iterative | `O(d)`          | `O(1)`           |
# | Recursive | `O(d)`          | `O(d)`           |
# | String    | `O(d)`          | `O(d)`           |
