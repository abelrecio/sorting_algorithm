#!/bin/bash

quinientos=$(shuf -i 1-5000 -n 500 | tr '\n' ' ')

contador=0
while [ $contador -lt 100 ]; do
    cien=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); 
    ./push_swap $cien | ./checker $cien
    let contador+=1
done


