#include <gb/gb.h>

// tamaño del mapa
#define MapSizeX 64

// Mapa y Tiles generados con 
// las herramientas GBMB y GBTD.
extern unsigned char tile_data[];
extern unsigned char map_data[];

// funcion principal
void main(){

    UBYTE scrollX = 0;
    BYTE tileCounter = 0;

    UBYTE temporala = 0, temporalb = 0;
    UWORD counter = 0;

    UBYTE i = 0;

    wait_vbl_done();
	disable_interrupts();
	DISPLAY_OFF;
	HIDE_SPRITES;
	HIDE_WIN;
	HIDE_BKG;

	SWITCH_ROM_MBC1(2);

    set_bkg_data( 0, 4, &tile_data);

    counter = 0;
	for( temporala = 0; temporala != 18; temporala++ ){ // only shows the visible part of the screen.

		set_bkg_tiles( 0, temporala, 22, 1, &(map_data+counter));
		counter = counter + MapSizeX;
	}

	// show the map
	SHOW_BKG;
    DISPLAY_ON;
	enable_interrupts();
	
	while(1){

		wait_vbl_done();

		// read the gb-pad.
        i = joypad();
        
        if(( i & J_LEFT ) && ( scrollX != 0)){
            scroll_bkg( -1, 0 );
            tileCounter--;
        }

        if(( i & J_RIGHT ) && ( scrollX < MapSizeX - 20 )){
            scroll_bkg( 1, 0 );
            tileCounter++;
        }

        if( tileCounter == 8 ){

            scrollX++;
            tileCounter = 0;

            counter = scrollX + 21;
            temporalb = counter % 32;

            for( temporala = 0; temporala != 18; temporala++ ){

                set_bkg_tiles( temporalb , temporala, 1, 1, &(map_data+counter));
                counter = counter + MapSizeX;
            }
        }
	}
}