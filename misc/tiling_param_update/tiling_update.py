import sys

updTiles = [5, 8, 11, 14, 15, 17, 18, 20, 21, 23, 24, 27, 28, 31, 34, 37, 40, 43, 46, 47, 50, 53]

i = 0
cnt = 0
done = 0

orgTilingFile = open(sys.argv[1], "r")
orgLines = orgTilingFile.readlines()
orgLinesCnt = len(orgLines)
line = orgLines[i]
lstring = "Layer" + str(updTiles[cnt])

with open(sys.argv[2],"w") as updTilingFile:
    while done == 0:
        if lstring in line :
            lstring1 = "layer" + str(updTiles[cnt])
            print ("Updating tiling params for " + lstring)
            filepath = sys.argv[3] + lstring1
            tileFile = open(filepath, "r")
            tileLines = tileFile.readlines()
            updTilingFile.writelines(tileLines)

            val = updTiles[cnt] + 1
            cstring = "Layer" + str(val)
            skip = 1
            while skip == 1:
                if cstring in line:
                    skip = 0
                else:
                    i += 1
                    if (i == orgLinesCnt):
                        skip = 0
                    else:
                        line = orgLines[i]

            cnt += 1
            if (cnt < len(updTiles)):
                lstring = "Layer" + str(updTiles[cnt])
        else:            
            updTilingFile.write(line)
            i += 1
            if (i < orgLinesCnt):
                line = orgLines[i]

        if i == orgLinesCnt:
            done = 1
