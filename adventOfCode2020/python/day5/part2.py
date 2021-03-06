#!/usr/local/bin/python

import sys

def process_line(line):
    row_range = [0, 127]
    col_range = [0, 7]
    row = 0
    col = 0

    for letter in line:
        if letter == 'F':
            row_range[1] -= (row_range[1] - row_range[0]) // 2 + 1
            row = row_range[1]
        if letter == 'B':
            row_range[0] += (row_range[1] - row_range[0]) // 2 + 1
            row = row_range[0]

        if letter == 'L':
            col_range[1] -= (col_range[1] - col_range[0]) // 2 + 1
            col = col_range[1]
        
        if letter == 'R':
            col_range[0] += (col_range[1] - col_range[0]) // 2 + 1
            col = col_range[0]

    return row * 8 + col

def find_seat(lines):
    rows = [0 for x in range(128 * 8)]
    my_seat = 0
    result = 0

    for line in lines:
        temp = process_line(line)
        #print(temp)
        rows[temp] = 1
    
    res = [i for i, x in enumerate(rows) if x == 0]
    for i in range(len(res) - 2):
        if(res[i + 1] - res[i] != 1):
            result = res.pop(i + 1)

    print(result)

        
if __name__ == '__main__':
    fo = open(sys.argv[1], 'r')

    lines = fo.readlines()
  
    fo.close()
    find_seat(lines)


