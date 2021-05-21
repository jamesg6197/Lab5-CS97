#!/bin/bash
if [ $(./randall 100 | wc -c) -eq 100 ]
then
    echo "Success 1" 
else
    echo "Failure 1"
fi

if [ $(./randall -i mrand48_r -o stdio 100 | wc -c) -eq 100 ]
then
    echo "Success 2"
else
    echo "Failure 2"
fi

if [ $(./randall -i rdrand -o stdio 190 | wc -c) -eq 190 ]
then
    echo "Success 3"
else
    echo "Failure 3"
fi

if [ $(./randall -i /dev/urandom 190 | wc -c) -eq 190 ]
then
    echo "Success 4"
else
    echo "Failure 4"
fi

if [ $(./randall -i /dev/urandom -o 5 190 | wc -c) -eq 190 ]
then
    echo "Success 5"
else
    echo "Failure 5"
fi
if [ $(./randall -o 5 500 | wc -c) -eq  500 ]
then
   echo "Success 6"
else
    echo "Failure 6"
fi

if [ $(./randall -o stdio 199 | wc -c) -eq 199 ]
then
   echo "Success 7"
else
    echo "Failure 7"
fi

if [ $(./randall -i rdrand -o stdio 500 | wc -c) -eq 500 ]
then
   echo "Success 8"
else
    echo "Failure 8"

fi

if [ $(./randall -i mrand48_r -o stdio 469 | wc -c) = 469 ]
then
   echo "Success 9"
else
    echo "Failure 9"

fi

if [ $(./randall -i mrand48_r -o 1 100 | wc -c) = 100 ]
then
   echo "Success 10"
else
    echo "Failure 10"
fi

if [ $(./randall -i rdrand -o 1 100 | wc -c) = 100 ]
then
   echo "Success 11"
else
    echo "Failure 11"
fi

if [ $(./randall -i /dev/urandom -o 2 100 | wc -c) = 100 ]
then
   echo "Success 12"
else
    echo "Failure 12"
fi
