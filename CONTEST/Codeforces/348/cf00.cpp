import sys

def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a%b)


def main():
	t, b, w = map(int, sys.stdin.readline().split())
	__b=(b*w)/gcd(b,w)
	x = t/__b
	#print x
	z = min(b, w)
	#print z
	y = x*z+min(b-1,min(w-1,t))
	#print y
	a = gcd(t, y)
	#print a
	y = y/a
	#print y
	t /= a
	#print t
	print("%d/%d"%(y,t))

if __name__ == '__main__':
	main()
