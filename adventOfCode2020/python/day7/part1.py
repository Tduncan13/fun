#!/usr/bin/python
import sys
import re

def find_gold(bag, rules):
    count = 0
    if rules[bag] == []:
        return 0

    if 'shiny gold' in rules[bag]:
        return 1

    for b in rules[bag]:
        count += find_gold(b, rules)

    return count


if __name__ == '__main__':
    fo = open(sys.argv[1], 'r')
    count = 0
    bags = []
    rules = {}
    lines = fo.readlines()

    for line in lines:
        line = re.sub(r' contain no other bags.', "", line)
        line = re.sub(r' contain [0-9]*', "", line)
        line = re.sub(r', [0-9]+', "", line)
        line = line.replace('.', '').replace(' bags', '').replace('bag', '')
        words = line.split()
        bags.append(' '.join(words[0:2])) 
        rules[' '.join(words[0:2])] = [' '.join(words[i:i+2]) for i in range(2, len(words), 2)]

    for bag in bags:
        if find_gold(bag, rules) > 0:
            count += 1

    print(count)
    








