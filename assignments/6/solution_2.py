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
    c = pow(plaintext, key, mod)
    return c


def decrypt(cipherd, privkey, n):
    d = pow(cipherd, privkey, n)
    #d = modeexp(cipherd,privkey,n)
    return d


def extended_ec(m, b):
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


def get_private_key(totient_n, publick):
    return extended_ec(totient_n, publick)


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


def encrypt(m, ya, a, q, k):
    c1c2 = []
    # because of efficiency problem, multiply_square is replaced
    # K=multiply_square(ya,k,q)
    K = pow(ya, k, q)
    # c1=multiply_square(a,k,q)
    c1 = pow(a, k, q)
    c2 = (K*m) % q

    c1c2.append(c1)
    c1c2.append(c2)

    return c1c2


def decrypt(c1c2, xa, q):
    # because of efficiency problem, multiply_square is replaced
    # K=multiply_square(c1c2[0],xa,q)

    K = pow(c1c2[0], xa, q)
    K_ = extended_ec(q, K)
    M = (c1c2[1]*K_) % q
    return M


def find_k(givenc1, ya, q):
    print('lets find k')
    # print('startpoint?\n')
    #startpoint = input()
    #print('start from ...  ',int(startpoint))

    # pre-calculated before value is 1216856793
    # for k in range(int(startpoint),q):
    for k in range(1200000000, q):
        # because of efficiency problem, multiply_square operation is replaced
        #c1 = multiply_square(a,k,q)
        if(k % 100000 == 0):
            print(k)
        c1 = pow(a, k, q)
        if(givenc1 == c1):
            break
    return k


def find_m(ya, a, k, q, c2):
    # because of efficiency problem, multiply_sqaure opreation is replaced
    #K = multiply_square(ya,k,q)
    K = pow(ya, k, q)

    ec_K = extended_ec(q, K)

    M = (c2*ec_K) % q

    return M


if (__name__ == '__main__'):
    c1 = 187341129
    c2 = 881954783

    c1c2 = [c1, c2]

    q = 1605333871

    a = 43
    ya = 22

    '''
    q=19
    a=10
    c1=11
    c2=5
    ya=3
    '''

    k = find_k(c1, ya, q)
    print('key is... ', k)
    m = find_m(ya, a, k, q, c2)
    print('plaintext is ...', m)
    print(encrypt(m, ya, a, q, k))
