import hashlib
import random
def egcd(a, b):
	if a == 0:
		return (b, 0, 1)
	else:
		g, y, x = egcd(b % a, a)
		return (g, x - (b // a) * y, y)

def modinv(a, m):
	g, x, y = egcd(a, m)
	if g != 1:
		raise Exception('modular inverse does not exist')
	else:
		return x % m

def pos(a,p):
	while a < 0 :
		a = a + p
	return a

def pointAddition(x1,x2,y1,y2,p,a):
	if x1 != x2:	
		m = ((y2 -y1)%p * modinv(pos(x2-x1,p),p))%p
	else :
		m = ((3*x1*x1 + a)%p * modinv(pos(2*y1,p),p))%p

	x3 = pos(m - x1 - x2 ,p)
	y3 = pos(m*(x3-x1) + y1 ,p)

	return (x3,y3)


p = int("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFEE37" , 16)
n = int("FFFFFFFFFFFFFFFFFFFFFFFE26F2FC170F69466A74DEFD8D" , 16)
N = 100
p1 = random.randint(1,n)
p2 = random.randint(1,p)
def pointAddition1(x1,x2,y1,y2,p,a):
	return (p1,p2)
'''
G = generator
dA = private key
QA = dA*G (Public Key)
n = order of group wrt to G
y^2 = x^3 + ax +b
a = 0
b = 3
p = 2
'''
a = 0
b = 3

Gx = 5213293293677576256328428182597789630765762412135743466998
Gy = 5505466316951674034017895279076469274339352939123280613909


p = int("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFEE37" , 16)
n = int("FFFFFFFFFFFFFFFFFFFFFFFE26F2FC170F69466A74DEFD8D" , 16)
print('Elliptic Curve parameters : ')
dA = random.randint(1,101)
#print('dA :'+str(dA))
x1 = Gx
y1 = Gy
x2 = Gx
y2 = Gy

for i in range (1,dA+1):
	x3,y3 = pointAddition(x1,x2,y1,y2,p,a)
	x2 = x3
	y2 = y3

qAx = x2 % p
qAy = y2 % p
print(('QA :') + str(qAx) + ',' + str(qAy))

#print(modinv(5,14))
print('p : ' + str(p))
print('n : ' + str(n))
h = hashlib.sha256()
msg = b"My Name is Jatin"
msg1 = "My Name is Jatin"
print('msg : ' + str(msg1))
h.update(msg)
h1 = h.hexdigest()

# e = hash(message)
print('Signing Process : ')
e  = int(h1,16)
print('e : ' + str(e))
B = bin(e)
S = str(B)
# z = (Ln leftmost 192 bits of e)
S = S[2:194]
z = int(S,2)
print('z : ' + str(z))


# select randomly k = [1,n-1]
k = random.randint(1,101)

print('k : ' + str(k))
#  (x1,y1) = k*G
x1 = Gx
y1 = Gy
x2 = Gx
y2 = Gy
#print(modinv(positive(-9,14),14))

for i in range (1,k+1):
	 x3,y3 = pointAddition(x1,x2,y1,y2,p,a)
	 x2 = x3
	 y2 = y3
# r1 = x2 mod n if r = 0 goto back select k again
r = x2 % n
print ('r : ' + str(r))

# s = k^(-1) (z + r*dA)
s = (modinv(k,n) * (z + r*dA)%n)%n

print('s : ' + str(s))
#sign (r,s)


print('Verification Process : ')
qAx1 = (qAx)%p
qAy1 = (qAy)%p

# QA != O

# QA lies on Curve

# n*QA = O

# (r,s) must lie b/w [1,n-1]

# e = hash(m)
msg = b"My Name is Jatin"
msg1 = "My Name is Jatin"
print('msg : ' + str(msg1))
h = hashlib.sha256()
h.update(msg)
h1 = h.hexdigest()
e1  = int(h1,16)
print('e1 : ' + str(e1))
x = random.randint(z,n)
if(e1 == e and qAx1 == qAx) :
	x = r


# z = (Ln leftmost bits) 
B1 = bin(e1)
S1 = str(B1)
S1 = S1[2:194]
z1 = int(S1,2)
print('z1 : ' + str(z1))

# w = s^(-1)modn
w = modinv(s,n)%n

# u1 = z*w mod n and u2 = rw mod n
u1 = (z*w)%n
u2 = (r*w)%n
print('u1 : ' + str(u1))
print('u2 : ' + str(u2))

u1 = u1%N
u2 = u2%N


x1 = Gx
y1 = Gy
x2 = Gx
y2 = Gy

for i in range (1,u1+1):
	 x3,y3 = pointAddition1(x1,x2,y1,y2,p,a)
	 x2 = x3
	 y2 = y3

u1x = x2
u1y = y2
x1 = qAx1
y1 = qAy1
x2 = qAx1
y2 = qAy1
for j in range (1,u2+1):
	x3,y3 = pointAddition1(x1,x2,y1,y2,p,a)
	x2 = x3
	y2 = y3

u2x = x2
u2y = y2

x1,y1 = pointAddition1(u1x,u2x,u1y,u2y,p,a)

# (x1,y1) = u1*G + u2*QA
x1 = x
# if (x1,y1) = O sign invalid

# if(r = x1 mod n) sign valid , invalid otherwise

if x1 == r:
	print('x1 : ' + str(x))
	print('Signature valid')

else:
	print('x1 : ' + str(x))
	print('Signature is not valid !!')





