#!/bin/bash
while true; do
    python3 makedata.py > data.in
    ./BF.out < data.in > std.out
    ./B2.out < data.in > code.out
    if diff std.out code.out; then
        printf "AC"
    else
        printf "Wa\n"
        exit 0
    fi
done
