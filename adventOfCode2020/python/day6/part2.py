#!/usr/bin/python
import sys

if __name__ == '__main__':
    fo = open(sys.argv[1], 'r')
    lines = fo.readlines()
    q = [0] * 26 
    s = 0
    c = 0
    for line in lines:
        line = ''.join(line.split())
        if len(line) == 0:
            t = [x for x in q if x == c]
            s += len(t)
            print(len(t))
            q = [0] * 26
            c = 0
            continue

        c += 1

        for letter in line:
            q[ord(letter) - 97] += 1


    t = [x for x in q if x == c]
    s += len(t)

    print(s)
