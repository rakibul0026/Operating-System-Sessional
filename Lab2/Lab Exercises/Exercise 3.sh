
#!/bin/bash

for (( i=1; i<=20; i++ ))
do
    if [ $((i % 2)) -eq 0 ]; then
        output="$i is Even"
    else
        output="$i is Odd"
    fi

    if [ $((i % 3)) -eq 0 ]; then
        output="$output, Multiple of 3"
    fi

    echo "$output"
done
