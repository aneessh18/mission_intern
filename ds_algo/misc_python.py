def modify(a):
    b = [1]
    a.append(b) #can get around this problem using list(b)
    print(a) #its printing as expected 
    b.pop() #this is where things get different

class Buf:
    def __init__(self):
        a = [] 
        print(a)
        modify(a)
        print(a)
b = Buf()
a = [1,2,3]
print([*a])