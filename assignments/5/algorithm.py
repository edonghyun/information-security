from fractions import gcd

def get_num_power(a,b):
    result = 1;
    for number in range(b):
        result=result*a
    return result


def is_int(a):
    b = int(a)
    b = a-b
    if(b == 0):
        return 1
    else:
        return 0


def invert_numbers(a,b):
    a1 = 1
    a2 = 0
    a3 = a
    b1 = 0
    b2 = 1
    b3 = b
    while(1):
        q = a //b
        t1 = a1 - q*b1
        t2 = a2 - q*b2
        t3 = a3 - q*b3
        a1 = b1
        a2 = b2
        a3 = b3
        b1 = t1
        b2 = t2
        b3 = t3
        if(b3 == 0):
            return -1
        if(b3==1):
            return b2

def is_prime(num):
    if(num>1):
        for i in range(2,num):
            if(num%i) ==0:
                return 0
        else:
             return 1
    else:
        return 0
    
numlist = [233,235,237,239,241]

for a in numlist:
    print(a)
    qlist=[]
    for number in range(8):
        if(number ==0):
            continue
        powered_two = get_num_power(2,number);
        b = (a-1)/powered_two
        if(is_int(b)==1):
            if(b%2==1):
                qlist.append(int(b))

    print(qlist)
    for q in qlist:
        if(q%2==0):
            continue
        for testnum in range(a):
            if(testnum==1):
                continue
            c = get_num_power(testnum,q)
            b = c%a
            if(b==1):
                print(testnum,'^',q,'=',b,'mod',a)
                break 

for a in range(235):
    k=0
    jq=get_num_power(a,get_num_power(2,k)*117)
    if(jq%235 == 234):
        print('235 is composit')

for a in range(237):
    for k in range(2):
        jq=get_num_power(a,get_num_power(2,k)*59)
        if(jq%237 == 236):
            print('237 is composit')
            
n = 56153
e = 23
M = 2
c = get_num_power(2,23)%n
print('\nprob2',c)

p=233
q=241
ceta=(p-1)*(q-1)
print('p=233 q=241',ceta)

gcdlist=[]
privatekey=[]

for possible_gcd in range(ceta+1):
    e=gcd(possible_gcd,ceta)
    if(e==1):
        gcdlist.append(possible_gcd)

e=23

for d in range(ceta):
    result=d*e%ceta
    if(result==1):
        privatekey.append(d)

print('d=',privatekey)
print()
print('a1',get_num_power(21811,19367)%233)
print('a2',get_num_power(21811,19367)%241)
