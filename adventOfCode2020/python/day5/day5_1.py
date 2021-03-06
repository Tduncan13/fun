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


