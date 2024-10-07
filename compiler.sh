#!/bin/bash
make fclean
make all
make clean
sleep 1
./push_swap 1 --    45 32
