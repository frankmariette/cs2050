/* Figure 7.24: figure7_24.c
   Card shuffling dealing program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Protoypes */
void shuffle( int wDeck[][ 13] );
void deal( const int wDeck[][13], const char *wFace[], const char *wSuit[]);

int main()
{
	/* initialize suit array */
	const char *suit[ 4 ] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char *face[ 13 ] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
								"Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	/* initialize deck array */
	int deck[ 4 ][ 13 ] = { 0 };

	srand( time( 0 ) ); // seed random-number generator

	shuffle( deck ); // shuffles the deck
	deal( deck, face, suit ); // deal the deck
	return 0; // indicates successful termination
}

/* Shuffle cards in the deck */
void shuffle( int wDeck[][ 13 ] )
{
	int row; // row number
	int column; // column number
	int card; // counter

	/* for each of the 52 cards, choose the slot of the deck randomly */
	for (card = 1; card <= 52; card++ ){
		do {
			row = rand() % 4;
			column = rand() % 13;
		} while( wDeck[ row ][ column ] != 0 ); // end do/while loop
		/* place card number in chosen slot of deck */
		wDeck[ row ][ column ] = card;
	} // end for
} // end shuffle function

void deal( const int wDeck[][13], const char *wFace[], const char *wSuit[] )
{
	/* counters */
	int card;
	int row;
	int column;

	/* deal each of the 52 cards */
	for ( card = 1; card <= 52; card++ ) {
		
		/* loop through the rows of wDeck */
		for (row = 0; row <= 3; row++ ) {

			/* loop through columns of wDeck for current row */
			for ( column = 0; column <= 12; column++ ) {

				/* if slot contains current card, display card */
				if ( wDeck[ row ][ column ] == card ) {
					printf("%5s of %-8s%c", wFace[column], wSuit[ row ], card % 2 == 0 ? '\n' : '\t' );
				} // end if
			} // end for
		} // end for
	} // end for
} // end deal function