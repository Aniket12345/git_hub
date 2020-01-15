#####
# Makefile for STM8
#
# Developer: Aniket Fondekar
#
# Date: 7 July 2019 
######


This Makfile is to compile two diffrent file together. ex C and CPP





Details of Function is Makfile

1)The Function wildcard
This string, used anywhere in a makefile, is replaced by a space-separated list of names of existing files that match one of the given file name patterns


ex: $(wildcard pattern...)

2)Functions for String Substitution   $(patsubst pattern,replacement,text)
 Finds whitespace-separated words in text that match pattern and replaces them with replacement.
 
 ex:$(patsubst %.c,%.o,x.c.c bar.c)
	produces the value ‘x.c.o bar.o’.

3)The Function Filter $(filter pattern…,text)
 Returns all whitespace-separated words in text that do match any of the pattern words, removing any words that do not match

ex: sources := foo.c bar.c baz.s ugh.h
    foo: $(sources)
        cc $(filter %.c %.s,$(sources)) -o foo
 says that foo depends of foo.c, bar.c, baz.s and ugh.h but only foo.c, bar.c and baz.s should be specified in the command to the compiler
