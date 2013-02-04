#!/usr/bin/env python

############################################################################                                                                              
# QA Engineering Programming Quiz
# By Wei Gao                                                                  
#                                                                             
# Release date: Feb 2 2013      
# take as its only parameter a sentence stored in a string, returns a string
# consisting of the number characters in each word, with spaces separating the
# numbers                                              
###########################################################################

from sys import argv
import string

def read_sentence():
  length = len(argv)
  s1 = ""
  if length == 1:
    print "0"
    return
  for i in range(1, length-1): #store in string s1
    s1 = s1 + argv[i] + " "
  s1 += argv[length-1] 
  s2 = ""
  mylist = s1.split(' ')
  for i in range(0, len(mylist)):
    if(mylist[i].isalpha()):
      s2 = s2 + str(len(mylist[i])) + " "
  print s2

def main(argv): #creat test case 
  read_sentence()

main(argv)
