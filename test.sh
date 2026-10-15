#!/bin/bash

HW="./hw0${1}"
VER="${2}"
DIR="${HW}/${VER}"
EXE="${DIR}/a.exe"
OUT="${DIR}/out.txt"

if [ ! -x "$EXE" ]; then
    echo "Nenalezen spustitelny soubor: $EXE"
    exit 1
fi

for LNG in CZE; do
    for X in {0000..0011}; do
        IN="${DIR}/${LNG}/${X}_in.txt"
        EXPECTED="${DIR}/${LNG}/${X}_out_win.txt"

        if [ ! -e "$IN" ]; then
            break
        fi

        echo "Testing $IN"

        "$EXE" < "$IN" > "$OUT"

        if ! diff -q --strip-trailing-cr "$EXPECTED" "$OUT" > /dev/null; then
            echo "Mismatch $IN"
        else
            echo "OK $IN"
        fi
    done
done

echo "All tests completed"