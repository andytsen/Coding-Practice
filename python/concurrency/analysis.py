# How does these data structures share across processes in these libraries

from multiprocessing import Process

class foo:
    cache = []

    def f1(self,x):
        self.cache.append(x)
        print(x)

    def kickoff(self):
        p1 = Process(target=self.f1, args=("hi",))
        p2 = Process(target=self.f1, args=("world!",))
        self.cache.append("main")
        
        p1.start()
        p2.start()
        
        p1.join()
        p2.join()

        for x in self.cache:
            print(x)
        

f_x = foo()
f_x.kickoff()

