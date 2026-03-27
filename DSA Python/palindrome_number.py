#Iterative Method
def is_palindrome(n):
    temp = n
    rev = 0

    while n > 0:
        rev = rev * 10 + n % 10
        n //= 10

    return temp == rev

n = int(input("Enter a number: "))
print(is_palindrome(n))


#Recursive Method
def is_palindrome(n, rev=0):
    if n == 0:
        return rev
    return is_palindrome(n // 10, rev * 10 + n % 10)

n = int(input("Enter a number: "))
print(n == is_palindrome(n))


#String Method (Simplest)
def is_palindrome(n):
    s = str(n)
    return s == s[::-1]

n = input("Enter a number: ")
print(is_palindrome(n))


# | Method         | Time Complexity | Space Complexity |
# | -------------- | --------------- | ---------------- |
# | Reverse Number | `O(d)`          | `O(1)`           |
# | Recursive      | `O(d)`          | `O(d)`           |
# | String         | `O(d)`          | `O(d)`           |
