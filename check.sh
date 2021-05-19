#!/bin/bash
if [ $(./randall 100 | wc -c) -eq 100 ]
then
    echo "Pass 1" # Success!
else
    echo "Failure"
fi
