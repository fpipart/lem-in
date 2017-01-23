#!/usr/bin/env python
# coding: utf-8

import os
import sys
import subprocess
import re

def test_1():
	 print "3\n##start\n0 1 0\n##end\n1 5 0\n2 9 0\n3 13 0\n0-2\n2-3\n3-1"
	 
def test_2():
	 print "3\nlol##start\n0 1 0\n##end\n1 5 0\n2 9 0\n3 13 0\n0-2\n2-3\n3-1"

def test_3():
	 print "3\n##start\n0 1 0\n##end\n1 1 0\n2 9 0\n3 13 0\n0-2\n2-3\n3-1"
	 
def test_4():
	 print "3\n##start\n0 1 0\n##end\n1 4 0\n2 9 0\n3 13 0\n4 9 0\n0-2\n2-3\n3-1"

if (len(sys.argv) == 1):
	#test_1()
	#test_2()
	test_4()
