#Iterative Method (While Loop)

def count_digit(n)->int:
  count = 0
  while n != 0:
    count = count+1
    n = n//10
  return count  

n = int(input("Enter a number: "))
print(count_digit(n))    

#recursive digit count program using user input 👇
def count_digit(n):
    if n == 0:
        return 1
    return 1 + count_digit(n // 10)

n = int(input("Enter a number: "))
print("Number of digits:", count_digit(n))

#digit count using logarithm (log₁₀) method 👇
import math
def count_digit(n):
    if n == 0:
        return 1
    n = abs(n)
    return int(math.log10(n)) + 1

n = int(input("Enter a number: "))
# print("Number of digits:", count_digit(n))

# Method	Time Complexity	Space Complexity
# Iterative (Loop)	O(d)	   O(1)
# Recursive	        O(d)	   O(d)
# Logarithmic	      O(1)	   O(1)