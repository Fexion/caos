


def q(n, p):
    s = 0
    for i in range(n):
        s += (-1)**(i)/(i+1)**(p)
    print(s)

q(100, 1/2)
