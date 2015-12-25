lcc -Wa-l -Wf-bo2 -c -o  tiles00.o tiles/tiles.c
lcc -Wa-l -Wf-bo2 -c -o  map00.o map/map.c
lcc -Wa-l -c -o  main.o main.c 
lcc -Wl-yt3 -Wl-yo8 -o background.gb main.o map00.o tiles00.o
pause

del *.o
del *.lst