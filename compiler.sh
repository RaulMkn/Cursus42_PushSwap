#!/bin/bash
make fclean
make all
make clean
sleep 1
./push_swap 1 2 3 4 5 6 7 8 9
