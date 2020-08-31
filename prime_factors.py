import math
def prime_factors(n:int):
    #n = 50
    factors = []
    #first churn out 2
    while n%2 ==0 :
        factors.append(2)
        n /= 2
    #n = 25
    for i in range(3, int(math.sqrt(n))+1,2):
        while n%i == 0:
            factors.append(i)
            n /= i
    if n>2: #for prime number
        factors.append(n)

    return set(factors)


if __name__ == "__main__":
    print(prime_factors(100)) 
    