def isPerfect(n):
    if n <= 1:
        return False

    total = 1  # 1 is always a divisor

    for i in range(2, n):
        if n % i == 0:
            total += i

    return total == n