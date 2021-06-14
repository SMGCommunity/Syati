lines = [l.strip("\n") for l in open("maketable.txt").readlines()]


for i in range(len(lines) // 5):
    name = lines[i * 5][21:-1]
    print(name)