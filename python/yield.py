def yielder():
    for i in range(0, 10):
        for j in range(0, 10):
            yield i * j 

def main():
    for i in yielder():
        print(i)

main()
