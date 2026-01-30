#Basic Method (Brute Force)
def print_factors(n):
    for i in range(1, n + 1):
        if n % i == 0:
            print(i, end=" ")

n = int(input("Enter a number: "))
print_factors(n)


#Optimized Method (Up to √n) ✅ Best
import math

def print_factors(n):
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            print(i, end=" ")
            if i != n // i:
                print(n // i, end=" ")

n = int(input("Enter a number: "))
print_factors(n)


#Sorted Factors (Interview Friendly)
import math

def print_factors(n):
    small = []
    large = []

    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            small.append(i)
            if i != n // i:
                large.append(n // i)

    for f in small:
        print(f, end=" ")
    for f in reversed(large):
        print(f, end=" ")

n = int(input("Enter a number: "))
print_factors(n)


# | Method         | Time Complexity | Space Complexity |
# | -------------- | --------------- | ---------------- |
# | Brute Force    | `O(n)`          | `O(1)`           |
# | Optimized (√n) | `O(√n)`         | `O(1)`           |
# | Sorted Output  | `O(√n)`         | `O(√n)`          |
