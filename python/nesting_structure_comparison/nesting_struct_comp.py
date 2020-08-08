#!/usr/bin/env/python

def same_structure_as(original, other):
    res = True

    if not isinstance(original, list) and isinstance(other, list):
        return False
        

    if isinstance(original, list) and not isinstance(other, list):
        return False
    
    if not isinstance(original, list) and not isinstance(other, list):
        return True

    if len(original) != len(other):
        return False

    for i in range(0, len(original)):
        res = same_structure_as(original[i], other[i])

    return res
    

