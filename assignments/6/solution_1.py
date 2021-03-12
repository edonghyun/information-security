def get_factors(n):
    return set(
        factor for i in range(1, int(n**0.5) + 1) if n % i == 0
        for factor in (i, n//i)
    )


def is_integer(a):
    b = a-int(a)
    if(b == 0):
        return True
    else:
        return False


def get_binary_number(a):
    listnum = []
    while a != 0:
        listnum.append(a % 2)
        a = a//2
    listnum.reverse()
    return listnum


def multiply_square(a, b, c):
    if b == 1:
        return a % c
    if b == 0:
        return 1

    result = 1
    numlist = get_binary_number(b)

    cnt = len(numlist)-1

    for num in numlist:
        if(not(num == 0)):
            result = result * (get_num_power(a, get_num_power(2, cnt)) % c)
        cnt -= 1

    return result % c


def get_num_power(a, b):
    result = 1
    for num in range(b):
        result = result * a
    return result


def is_prime(number):
    if (number > 1):
        for i in range(2, number):
            if(number % i == 0):
                return False
        else:
            return True
    else:
        return False


def get_gcd(a, b):
    while(not(b == 0)):
        temp = a % b
        a = b
        b = temp
    return abs(a)


def encrypt(plaintext, key, mod):
    # c = multiply_square(plaintext,key,mod)
    c = pow(plaintext, key, mod)
    return c


def decrypt(cipherd, privkey, n):
    # d = multiply_square(cipherd,privkey,n)
    d = pow(cipherd, privkey, n)
    # d = get_mod_exp(cipherd,privkey,n)
    return d


def get_extended_ec(m, b):
    a1 = 1
    a2 = 0
    a3 = m
    b1 = 0
    b2 = 1
    b3 = b

    while 1:
        if b3 == 0:
            return get_gcd(m, b)
        if b3 == 1:
            return b2  # b2 = inverse of b mod m

        q = int(a3/b3)

        t1 = a1 - q*b1
        t2 = a2 - q*b2
        t3 = a3 - q*b3
        a1 = b1
        a2 = b2
        a3 = b3
        b1 = t1
        b2 = t2
        b3 = t3


def get_mod_exp(a, n, m):
    result = 1
    while n > 0:
        if n % 2 == 0:
            a = (a*a) % m
            n = n/2
        else:
            result = (a*result) % m
            n = n - 1
    return result


def get_private_key(totient_n, publick):
    privatekey = get_extended_ec(totient_n, publick)
    return privatekey


if (__name__ == '__main__'):

    # possiblePrime = MilerRabin(a)
    # primelist=primelist(10000000000)
    # p,q = Cal_pq(a,primelist)

    '''
    p=17
    q=11
    M=88
    totient_n=(p-1)*(q-1)

    privk = get_private_key(totient_n,7,p*q)
    encrypt= encryptM,7,p*q)
    decrypt = decrypt(encryptprivk,p*q)
    if(decrypt == M):
        print(encrypt privk, decrypt)

    print(get_mod_exp(65,5,119))
    print(get_mod_exp(46,77,119))
    '''
    # select primes
    a = 18444164967047483891

    '''
    factor_num = get_factors(a)
    p=factor_num[2]
    q=factor_num[3]
    '''
    # prime numbers of a are precalculated
    p = 4294404461
    q = 4294929631

    e = 29
    c = 21

    # calculate totient n
    totient_n = (p-1)*(q-1)

    # private key
    privk = get_private_key(totient_n, e)
    plaintext = decrypt(c, privk, a)
    encrypt = encrypt(plaintext, e, a)

    print('Private key', privk)
    print('Plaintext', plaintext)
    print('Reencrypted', encrypt)

    p1 = 6835383948117812667
    p2 = 10824463971351777081

    '''
    e1 = encryptp1,e,a)
    e2 = encryptp2,e,a)

    d1 = decrypt(e1,privk,a)
    d2 = decrypt(e2,privk,a)

    print (e1,d1)
    print (e2,d2)
    '''
