#!/bin/bash
gcc server.c -o server.o
gcc client.c -o client.o `mysql_config --cflags --libs` 
./server.o

