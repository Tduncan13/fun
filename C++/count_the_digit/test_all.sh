#!/bin/bash

NUM_TEST_CASES=3

g++ -std=c++11 count_the_digit.cc 2> /dev/null
compile_val=$?
if [[ $compile_val != 0 ]]; then
	echo 'The program had a compile time error. You are a terrible programmer!'
fi

for i in `seq -f "%02g" 1 $NUM_TEST_CASES`;
do
	./a.out ./test_cases/test_case$i.txt > myoutput$i.txt 2> /dev/null
	execution_value=$?
	if [[ $execution_value != 0 ]]; then
		echo "The program had a runtime error. You are a terrible programmer!"
	fi

	diff myoutput$i.txt test_cases/expected_output$i.txt > /dev/null
	diff_val=$?

	if [[ $diff_val != 0 ]]; then
		echo "The output does not match the expected output"
		echo "and you are a terrible programmer!"
	else 
		echo "test_case$i passed. This is ok.... You could probably do better tbh."
	fi

	rm -f myoutput$i.txt
done

