#!/usr/bin/python
import sys
import re

def count_bags(bag, rules, num_bags):
    s = 0
    if rules[bag] == []:
        return 0

    for i, b in enumerate(rules[bag]):
        count = int(num_bags[bag][i])
        s += count
        count *= count_bags(b, rules, num_bags)
        s += count

    return s

if __name__ == '__main__':
    fo = open(sys.argv[1], 'r')
    bags = []
    num_bags = {}
    rules = {}
    lines = fo.readlines()
    count = 0

    for line in lines:
        t = re.sub('[a-zA-Z]*,*', '', line).replace('.', '').split()
        line = re.sub(r' contain no other bags.', "", line)
        line = re.sub(r' contain [0-9]+', "", line)
        line = re.sub(r', [0-9]+', "", line)
        line = line.replace('.', '').replace(' bags', '').replace('bag', '')
        words = line.split()
        bags.append(' '.join(words[0:2])) 
        num_bags[' '.join(words[0:2])] = t
        rules[' '.join(words[0:2])] = [' '.join(words[i:i+2]) for i in range(2, len(words), 2)]
    count += count_bags('shiny gold', rules, num_bags)

    print(count)

    








