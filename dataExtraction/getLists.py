def main():
  fp = open('pythonLists.txt')

  minsT = []
  onesT = []
  twosT = []
  threesT = []
  maxsT = []

  minsB = []
  onesB = []
  twosB = []
  threesB = []
  maxsB = []
  
  for i, line in enumerate(fp.readlines() ):
    # do something here

    #print( i )
    #print( line )

    split = line.split( ',', -1)
    split = split[:-1]
    if( i != 0 ):
      for str in range(0, len(split) ):
        split[i] = float(split[i])

    if( i == 1 ):
      minsT = split
    elif( i == 2 ):
      onesT = split
    elif( i == 3 ):
      twosT = split
    elif( i == 4 ):
      threesT = split
    elif( i == 5 ):
      maxsT = split
    elif( i == 6 ):
      minsB = split
    elif( i == 7 ):
      onesB = split
    elif( i == 8 ):
      twosB = split
    elif( i == 9 ):
      threesB = split
    elif( i == 10 ):
      maxsB = split

  print(minsT)
  print(onesT)
  print(twosT)
  print(threesT)
  print(maxsT)

  print(minsB)
  print(onesB)
  print(twosB)
  print(threesB)
  print(maxsB)

if __name__ == '__main__':
  main()
