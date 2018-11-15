#include "dominion.h"
#include <stdlib.h>
#include "rngs.h"
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>


int check_smithy_run(int p, struct gameState *post) {
  // Need to check 2 main things: 
  //  3 cards added
  //  current card discarded
  int fail = 0;

  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));

  cardEffect(smithy, 0, 0, 0, post, 1, 0);
  //  printf ("drawCard PRE: p %d HC %d DeC %d DiC %d\n",
  //	  p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p]);

  //printf ("drawCard POST: p %d HC %d DeC %d DiC %d\n",
  //      p, post->handCount[p], post->deckCount[p], post->discardCount[p]);
  

  // check for fail
  if ((*post).deckCount[p] != (pre.deckCount[p] - 3)){
    printf("deckCount post: %d, deckCount pre: %d\n", (*post).deckCount[p], pre.deckCount[p] );
    fail = 1;
  }
  if ((*post).handCount[p] != (pre.handCount[p] + 2)){
    printf("handCount post: %d, handCount pre: %d\n", (*post).handCount[p], pre.handCount[p] );
    fail = 1;
  }

  return fail;
}

int main(){
  int i, n, r, p, deckCount, discardCount, handCount, num_tests;
  int players = 2;
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy};
  int turns = 30;
  struct gameState G;



  printf ("Testing smithy_run.\n");

  printf ("RANDOM TESTS.\n");

  srand(time(NULL));

  int error_count = 0;
  
  for (num_tests = 0; num_tests < 10; num_tests++) {
    // seed for initializeGame
    int randomSeed = rand();
    initializeGame(players, kingdomCards, randomSeed, &G);

    p = rand() % 2;
    G.whoseTurn = p;

    G.deckCount[p] = rand() % MAX_DECK;
    G.discardCount[p] = rand() % MAX_DECK;
    G.handCount[p] = rand() % MAX_HAND;
    G.numActions = 1;

    G.hand[p][0] = adventurer;
    G.hand[p][1] = smithy;
    
    error_count += check_smithy_run(p, &G);
  }

  if(error_count == 0){
    printf ("ALL TESTS OK\n");
  }
  else {
    printf("ERRORS FOUND\n");
    printf("smithy_run failed %d times\n", error_count);
  }

}
