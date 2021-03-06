#!/usr/local/bin/python

import sys

def process_line(line):
    row_ptr1 = 0
    row_ptr2 = 127
    col_ptr1 = 0
    col_ptr2 = 7
    row = 0
    col = 0
    for letter in line:
        if letter == 'F':
            row_ptr2 -= (row_ptr2 - row_ptr1) // 2 + 1
            row = row_ptr2
        if letter == 'B':
            row_ptr1 += (row_ptr2 - row_ptr1) // 2 + 1
            row = row_ptr1

        if letter == 'L':
            col_ptr2 -= (col_ptr2 - col_ptr1) // 2 + 1
            col = col_ptr2
        
        if letter == 'R':
            col_ptr1 += (col_ptr2 - col_ptr1) // 2 + 1
            col = col_ptr1
            
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


