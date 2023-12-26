class set:
    def __init__(self, elementCount):
        self.s = []

        for i in range(elementCount):
            e = int(input("Enter Element "+str(i+1)+" : "))
            self.add(e)


    def add(self, ele):
        if ele not in self.s:
            self.s.append(ele)

    def __iter__(self):
        return iter(self.s)

    def __len__(self):
        return len(self.s)

    def union (self, setB):
        result = set(0)
        for i in self:
            result.add(i)
        for i in setB:
            if i not in self.s:
                result.add(i)
        return result

    def intersection (self,setB):
        result = set(0)
        for i in setB:
            for j in self:
                if i == j:
                    result.add(i)
        return result

    def difference(self, setB):
        result = set(0)
        for i in self:
            if i not in setB:
                result.add(i)
        return result

    def symmetric_diff (self, setB):
        u = self.union(setB)
        i = self.intersection(setB)
        return u.difference(i)


def create():
    count = int(input("Enter How Many Elements to enter: "))
    s = set(count)
    return s

print("\t\t\tWelcome To Set Operations Program ")

count = int(input("Enter the Number of elements to be inserted: "))
set1 = set(count)
ch = 0
while(ch!=5):
    c = int(input("Operations to Perform: \n1) Union\n2) Intersection \n3) Difference \n4) Symmetric Difference \n5) Exit\n"))

    if c == 1:
        set2 = create()
        res = set1.union(set2)
        print("Union of A and B is: ")
        print(res.s)

    elif c == 2:
        set2 = create()
        res = set1.intersection(set2)
        print("Intersection of A and B is: ")
        print(res.s)

    elif c == 3:
        set2 = create()
        r = set1.difference(set2)
        print("Difference of A and B is: ")
        print(r.s)

    elif c == 4:
        set2 = create()
        r = set1.symmetric_diff(set2)
        print("Symmetric Difference of A and B is: ")
        print(r.s)

    elif c == 5:
        break
    
    else:
        print("Enter a valid choice")

    
