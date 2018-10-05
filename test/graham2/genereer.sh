#!/bin/bash

AANTAL_CASES=100
echo $AANTAL_CASES > convexhull.in
echo $AANTAL_CASES > convexhull.out
for i in {1..100}; do
	NEW_SEED=$RANDOM
	NUMBER_OF_POINTS=10000
	if [ $i -le 3 ]
	then
		NUMBER_OF_POINTS=4
	fi
	rbox $NUMBER_OF_POINTS z D2 t$NEW_SEED | grep -v rbox >> convexhull.in
	rbox $NUMBER_OF_POINTS z D2 t$NEW_SEED | qhull Fx >> convexhull.out
	if [ $i -lt 100 ]
	then
		echo >> convexhull.out
	fi
done

