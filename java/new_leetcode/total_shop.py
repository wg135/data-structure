#!/usr/bin/env python

############################################################################                                                                              
# QA Engineering Programming Quiz
# By Wei Gao                                                                  
#                                                                             
# Release date: Feb 2 2013      
# take a log file name as input                                       
###########################################################################

from sys import argv
import string
import collections

def usage():
  if(len(argv) != 2):
    print "Usage: ./total_shop.py grocery.txt"
    exit(0)

def read_log():
  Dict = {} #initial empty dict
  script, read_file = argv   
  try:
    file = open(read_file)
  except:
      print "shop log file doesn't exist or read file error\n"
      exit(0)
  while 1:
    line = file.readline().rstrip()
    if not line:
      break
    info = line.split('|')
    if not Dict.has_key(info[0]):
      Dict[info[0]] = {}
    if not Dict[info[0]].has_key(info[1]):
      Dict[info[0]][info[1]] = 0.0
    Dict[info[0]][info[1]] += float(info[3])
  return Dict    

def write_file(Dict):
  f1 = open('report1', 'w')
  f2 = open('report2', 'w')
 
  f1.write("Total revenue by customer:\n")
  total_tax = 0.0
  for name in Dict:
    cnt = 0.0
    for item in Dict[name]:
      cnt += Dict[name][item]
      total_tax += Dict[name][item]
    f1.write(name + " - $" + str(cnt) + "\n")
    tax = total_tax * 0.0925
  f1.write("Total tax: $" + str(tax) + "\n")
 
  for name in Dict:
    total_tax = 0.0
    f2.write("Purchases by " + name + "\n")
    for item in Dict[name]:
      total_tax += Dict[name][item]
      f2.write(item + " - $" + str(Dict[name][item]) + "\n")
    total_tax *= 0.0925  
    f2.write("The tax for "+ name + ": $" + str(total_tax) + "\n")     
    f2.write("\n")
  
def main(argv): #creat test case 
  usage()
  Dict = read_log()
  write_file(Dict)

main(argv)
