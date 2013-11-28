/* Figure 10.2: figure10_2.c
   Using the structure member and
   structure pointer operators */
#include <stdio.h>

struct card {
	const char *face; // define pointer face
	const char *suit; // define pointer suit
}; // end structure card

int main( void )
{
	struct card aCard; // define one struct card variable
	struct card *cardPtr; // define a pointer to a struct card

	// place strings into aCard
	aCard.face = "Ace";
	aCard.suit = "Spades";

	cardPtr = &aCard; // Assign address of aCard to cardPtr

	printf( "%s%s%s\n%s%s%s\n%s%s%s\n", aCard.face, " of ", aCard.suit, cardPtr->face, " of ",
										 cardPtr->suit, (*cardPtr).face, " of ", (*cardPtr).suit);
	return 0; // indicates successful termination
} // end main 