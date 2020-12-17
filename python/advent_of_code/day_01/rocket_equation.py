#!/usr/bin/env/python3

import sys

def main(fo):
    lines = fo.readlines() 
    answer = 0
    for line in lines:
        answer += calculate_fuel_rec(int(line))
    
    print(f'Answer: {answer}')

def calculate_fuel(mass):
    return (mass // 3) - 2

def calculate_fuel_rec(mass):
    if mass <= 0:
        return 0
    temp = mass
    fuel = calculate_fuel(mass)
    fuel += calculate_fuel_rec(fuel)
    print(f'Mass: {temp}')
    print(f'Mass: {mass} Fuel: {fuel}')
    
    return fuel

if __name__ == '__main__':
    fo = open(sys.argv[1], 'r')
    main(fo)
    fo.close()
