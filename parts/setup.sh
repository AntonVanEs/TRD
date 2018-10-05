#!/bin/bash
for d in {A..J}; do
  mkdir -p $d;
  sed -r s/name/$d/g < Makefile > $d/Makefile
  sed -r s/NAME/$d/g < name.cpp > $d/$d.cpp
done

