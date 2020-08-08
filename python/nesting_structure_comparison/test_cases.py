#!/usr/bin/env/python
import nesting_struct_comp

def assert_equals(a, b, msg=None):
    if a == b:
        if msg == None:
            print("Pass! They match.")
        else:
            print(f'Pass! {msg}')
    else:
        print("Fail! They do not match.")

assert_equals(nesting_struct_comp.same_structure_as([1,[1,1]],[2,[2,2]]), True, "[1,[1,1]] same as [2,[2,2]]")
assert_equals(nesting_struct_comp.same_structure_as([1,[1,1]],[[2,2],2]), False, "[1,[1,1]] not same as [2,[2,2]]")


