# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main:
	$(CC) $(CFLAGS) -c main.cpp -o main


# g++ main.cpp -o main