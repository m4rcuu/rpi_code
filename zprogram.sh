#!/bin/bash
sudo motion start

mkdir build
cd build/
cmake ..
make
echo ""
./samochodzik

sudo systemctl stop motion.service