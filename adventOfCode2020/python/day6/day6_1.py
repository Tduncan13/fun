#!/usr/bin/python
import sys

if __name__ == '__main__':
    fo = open(sys.argv[1], 'r')
    lines = fo.readlines()
    q = [0] * 26 
    s = 0

    for line in lines:

        line = ''.join(line.split())

        if len(line) == 0:
            t = [x for x in q if x == 1]
            s += len(t)
            q = [0] * 26
            continue

        for letter in line:
            print(letter)
            q[ord(letter) - 97] = 1

    t = [x for x in q if x == 1]
    s += len(t)

    print(s)
