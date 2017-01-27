#!/usr/bin/env python
# coding: utf-8

import os
import sys
import subprocess
import re

def test_0():
	print "  "

def test_1():
	 print "3\n##start\n0 1 0\n##end\n1 5 0\n2 9 0\n3 13 0\n0-2\n2-3\n3-1"
	 
def test_2():
	 print "3\nlol##start\n0 1 0\n##end\n1 5 0\n2 9 0\n3 13 0\n0-2\n2-3\n3-1"

def test_3():
	 print "3\n##start\n0 1 0\n##end\n1 1 0\n2 9 0\n3 13 0\n0-2\n2-3\n3-1"
	 
def test_4():
	 print "3\n##start\n0 1 0\n##end\n1 4 0\n2 9 0\n3 13 0\n4 9 0\n0-2\n2-3\n3-1"

def test_5():
	 print "3\n##start\n0 1 0\n##end\n1 4 0\n3 9 0\n3 13 0\n4 29 0\n0-2\n2-3\n3-1"

def test_6():
	 print "3\n##start\n0 1 0\n1 5 0\n2 9 0\n3 13 0\n0-2\n2-3\n3-1"

def test_7():
	 print "3\n##start\n0 1 0\n##end\n1 5 0\n2 9 0\n3 13 0\n0-2\n2-3\n0-pasbon\n3-1"
	 
def test_8():
	 print "3\n##start\n0 1 0\n##end\n1 5 0\n2 9 0\n3 13 0\n0-2\n2-3\npasbon-0\n3-1"

def test_10():
	 print "3\n##start\n0 1 0\n1 5 0\n2 9 0\n##end\n3 13 0\n0-2\n2-3\n1-0\n3-1"

def test_11():
	 print "12\n##start\n1 23 3\n2 16 7\n#commentaire\n3 16 3\n4 16 5\n5 9 3\n6 1 5\n7 4 8\n##end\n0 9 5\n0-4\n0-6\n1-3\n4-3\n5-2\n3-5\n#autre commentaire\n4-2\n2-1\n7-6\n7-2\n7-4\n6-5"

if (len(sys.argv) == 1):
	#test_0()
	#test_1()
	#test_2()
	#test_3()
	#test_4()
    #test_5()
    #test_6()
    #test_7()
    #test_8()
    #test_10()
    test_11()
