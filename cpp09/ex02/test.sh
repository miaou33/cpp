#!/bin/bash

function run {
    echo -e "\nRunning ./PmergeMe $1"
    ./PmergeMe $1
}

make

run `shuf -i 1-100000 -n 3000 | tr '\n' ' '`
run "43 3 1 78 99 23 12 4 56 3"
