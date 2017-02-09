#!/usr/bin/env python
# coding: utf-8

import os
import sys
import subprocess
import re

def test_0():
	print "  "
	# ERROR

def test_1_1():
	 print "3\n2 5 0\n##start\n0 1 2\n##end\n1 9 2\n3 5 4\n0-2\n0-3\n2-1\n3-1\n2-3"
	 #L1-3 L2-2
	 #L1-1 L2-1 L3-3
	 #L3-1

def test_1_2():
	 print "3\n2 5 0\n##start\n0 1 2\n##end\n1 9 2\n3 5 4\n0-1\n0-2\n0-3\n2-1\n3-1\n2-3"
# Cas a gerer : Liaison direct start_end + 2 chemin de longeur 2
	 #L1-1 L2-3 L3-2
	 #L2-1 L3-1

def test_1_2_bis():
	 print "29\n2 5 0\n##start\n0 1 2\n##end\n1 9 2\n3 5 4\n0-1\n0-2\n0-3\n2-1\n3-1\n2-3"
# Cas a gerer : Liaison direct start_end + 2 chemin de longeur 2

def test_1_3():
	 print "3\n##start\n0 111111111111111 0\n##end\nend 5 0\n2 9 0\n3 13 0\n0-2\n2-3\n3-end"

def test_1():
	 print "3\n##start\n0 1 0\n##end\nend 5 0\n2 9 0\n3 13 0\n0-2\n2-3\n3-end"
 
def test_2():
	 print "3\nlol##start\n0 1 0\n##end\n1 5 0\n2 9 0\n3 13 0\n0-2\n2-3\n3-1"

def test_3():
	 print "3\n##start\n0 1 0\n##end\n1 1 0\n2 9 0\n3 13 0\n0-2\n2-3\n3-1"
# INFO : Erreur Start ecrase par End
 
def test_4():
	 print "3\n##start\n0 1 0\n##end\n1 4 0\n2 9 0\n3 13 0\n4 9 0\n0-2\n2-3\n3-1"
# INFO : Erreur room 2 ecrase par la room 4

def test_5():
	 print "3\n##start\n0 1 0\n##end\n1 4 0\n3 9 0\n3 13 0\n4 29 0\n0-2\n2-3\n3-1"
# INFO : Erreur pas de room 2

def test_6():
	 print "3\n##start\n0 1 0\n1 5 0\n2 9 0\n3 13 0\n0-2\n2-3\n3-1"
# INFO : Erreur pas de End

def test_7():
	 print "3\n##start\n0 1 0\n##end\n1 5 0\n2 9 0\n3 13 0\n0-2\n2-3\n0-pasbon\n3-1"
# INFO : Erreur Tube invalide 
	 
def test_8():
	 print "3\n##start\n0 1 0\n##end\n1 5 0\n2 9 0\n3 13 0\n0-2\n2-3\npasbon-0\n3-1"
# INFO : Erreur Tube invalide 

def test_9():
	 print "3\n##start\n0 1 0\n##end\n1 5 0\n2 9 0\n3 13 0\n0-2\n2-3\n3-1\npasbon-0\n3-1"
# INFO : arret de lencture au niiveau du tube invalide 

def test_10():
	 print "3\n##start\n0 1 0\n1 5 0\n2 9 0\n##end\n3 13 0\n0-2\n2-3\n3-1"
# 0 2 3 1

def test_11():
	 print "12\n##start\n1 23 3\n2 16 7\n#commentaire\n3 16 3\n4 16 5\n5 9 3\n6 1 5\n7 4 8\n##end\n0 9 5\n0-4\n0-6\n1-3\n4-3\n5-2\n3-5\n#autre commentaire\n4-2\n2-1\n7-6\n7-2\n7-4\n6-5"

def test_12():
	 print "12\n##start\n1 23 3\n2 16 7\n#commentaire\n3 16 3\n4 16 5\n5 9 3\n6 1 5\n7 4 8\n##end\n0 9 5\n0-4\n0-6\n1-3\n4-3\n5-2\n3-5\n#autre commentaire\n4-2\n2-1\n7-6\n7-2\n7-4"
#Suppression d'un chemin

def test_13():
	 print "12\n##start\n1 23 3\n2 16 7\n#commentaire\n3 16 3\n4 16 5\n5 9 3\n6 1 5\n7 4 8\n##end\n0 9 5\n0-4\n0-6\n1-3\n4-3\n5-2\n3-5\n#autre commentaire\n4-2\n2-1\n7-6\n7-2\n7-4\n6-5\n1-0"
# TEST : # chemin possible avec une liaison direct entre start et end
def test_14():
	 print "12\n##start\nblabla 23 3\nii 16 7\n#commentaire\n3 16 3\n4 16 5\n5 9 3\n6 1 5\n7 4 8\n##end\n0 9 5\n0-4\n0-6\nblabla-3\n4-3\n5-ii\n3-5\n#autre commentaire\n4-ii\nii-blabla\n7-6\n7-ii\n7-4\n6-5\nblabla-0"

def test_20():
	print "50\n##start\n1 1 1\n2 2 2\n3 3 3\n4 4 4\n5 5 5\n7 7 7\n8 8 8\n9 9 9\n10 10 10\n11 11 11\n12 12 12\n13 13 13\n14 14 14\n15 15 15\n16 16 16\n##end\nend 6 6\n17 17 17\n1-2\n2-3\n3-4\n4-5\n5-7\n7-8\n8-9\n9-10\n10-11\n11-12\n12-13\n13-14\n14-15\n15-16\n16-end\nend-17\n17-1\n"

## 1_2

if (len(sys.argv) == 1):
	#test_0()
	#test_1_1()
	#test_1_2()
	#test_1_2_bis()
	#test_1_3()
	#test_1()
	#test_2()
	#test_3()
	#test_4()
    #test_5()
    #test_6()
    #test_7()
    #test_8()
    #test_9()
    #test_10()
    #test_11()
    #test_12()
    #test_13()
    #test_14()
	test_20()
