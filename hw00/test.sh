#!/bin/bash

for LANG in CZE ENG; do
    for X in {0000..0011}; do
        if [ ! -e "./${LANG}/${X}_in.txt" ]; then
            break
        fi

        echo "Testing ./${LANG}/${X}_in.txt"

        ./a.exe < "./${LANG}/${X}_in.txt" > out.txt

        if ! diff -q "./${LANG}/${X}_out_win.txt" out.txt; then
            echo "Mismatch ./${LANG}/${X}_in.txt"
        else
            echo "OK ./${LANG}/${X}_in.txt"
        fi
    done
done

echo "All tests completed"
