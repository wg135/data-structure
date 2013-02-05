#!/usr/bin/env python

############################################################################                                                                              
# code test question monkey on pyramid 
# By Wei Gao                                                                  
#                                                                             
# Release date: Feb 1 2013      
# Use DP algorithm to make sure algorithm is fast when lines is large                                               
###########################################################################

def pyramid():
  file = open("pyramid.txt")
  line_cnt = 1
  newlists = []
  while 1: #read number in each line to list of list
    line = file.readline().rstrip()
    if not line:
      break
    line_cnt += 1
    lists = line.split(' ')
    new_list = []
    for character in lists:
      if (character != ' ' and character != ''):
        new_list.append(int(character)) 
    newlists.append(new_list) 
 
    tmp = newlists[0]
  if (len(newlists) == 1): #the file only have one level
     return tmp[0]
  result = tmp[0]

  mylist = [] #initial a 2-D matrix
  for i in range(line_cnt):
    mylist.append([])
    for j in range(line_cnt):
      mylist[i].append(0)
  mylist[0][0] = tmp[0]

  for i in range(1, line_cnt-1): #add left edge of the pyramid
    mylist[i][0] = newlists[i][0] + mylist[i-1][0]
  for i in range(1, line_cnt-1): #add right edge of the pyramid
    mylist[i][i] = newlists[i][i] + mylist[i-1][i-1]
  for i in range(2, line_cnt-1): #add middle elements
    for j in range(1, i):
      mylist[i][j] = max(mylist[i-1][j-1], mylist[i-1][j]) + newlists[i][j]       

  result = 0 #scan the last level and find the maxium element
  for i in range(0, line_cnt-1):
    if(result < mylist[line_cnt-2][i]):
      result = mylist[line_cnt-2][i]
  return result

def main(): #creat test case 
  result =  pyramid()
  print result

main()
