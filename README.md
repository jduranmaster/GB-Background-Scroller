# GB-Background-Scroller
A repository to storage the source code of the hombrew "Background Scroller"  

"Background Scroller" is a homebrew software for the Nintendo Game Boy developed in C by Ryoga (a.k.a. jduranmaster) using the GBDK (GameBoy Development Kit).  

The controls are the following:  LEFT &amp; RIGTH - to move in the X axis of the background.  

This game/software was in development between the 2015/12/10 - 2015/12/11 in my free-time. The code has not been improved since then.  

Compilation Script:  

lcc -Wa-l -Wf-bo2 -c -o  tiles00.o tiles/tiles.c 
lcc -Wa-l -Wf-bo2 -c -o  map00.o map/map.c lcc -Wa-l -c -o  main.o main.c  
lcc -Wl-yt3 -Wl-yo8 -o background.gb main.o map00.o tiles00.o
