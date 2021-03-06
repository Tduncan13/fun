#!/usr/local/bin/python

import sys

def process_line(line):
    rows = [x for x in range(128)]
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

    print(f'Row pointers: {row_ptr1} {row_ptr2}')
    print(f'Col pointers: {col_ptr1} {col_ptr2}')
            
    return row * 8 + col

def find_seat(lines):
    highest_seat_id = 0

    for line in lines:
        temp = process_line(line)
        if temp > highest_seat_id:  
            highest_seat_id = temp  

    print(highest_seat_id)
        
if __name__ == '__main__':
    fo = open(sys.argv[1], 'r')

    lines = fo.readlines()
  
    fo.close()
    find_seat(lines)


