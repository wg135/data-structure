#!/usr/bin/python
#
#wordcount program for interview of Nopsec company
#Author: Wei Gao
#Date:  Nov 27 2012
#Email: wg135@msstate.edu


from sys import argv
import string

#check the program argument 
def usage():
    if len(argv) != 3 or argv[1] in {"-h", "-help", "--h", "--help"}:
     print "Usage: ./wordcount.py fileread filewrite"
     exit(0)

def main(argv):
    usage()

    script, read_file, write_file = argv
    try:
      read_fd = open(read_file, 'r').read()    
      read_fd = string.lower(read_fd)           
    except:
      print "word file doesn't exist or read file error\n"
      exit(0)
  
    for character in read_fd: #take each non english character as space
       if (character.isalpha() == False):
           read_fd = string.replace(read_fd, character, ' ')
    numbers = string.split(read_fd)

    dict_count = {}   #init empty dictory for word count
    for words in numbers:  #count words  
        dict_count[words] = dict_count.get(words, 0) + 1  
    
    try:
      write_fd = open(write_file, 'w')
    except:
      print "write result error\n"
      exit(0)

    for key in sorted(dict_count.iterkeys()):  #write dictory to result file in alpha order
        write_fd.write(key)
        write_fd.write('\t')
        write_fd.write("%s\n" %dict_count[key])

    write_fd.close()

main(argv)
