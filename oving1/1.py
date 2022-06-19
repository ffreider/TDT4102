n = int(input("Tall: "))

def isFibonacciNumber(n):
    a = 0
    b = 1
    while b < n:
        temp = b
        b += a
        a = temp
    if b == n:
        return True
    else:
        return False

print(isFibonacciNumber(n))