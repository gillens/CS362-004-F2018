#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int main(){
  
  int testRuns = rand() % 100 + 10; //at least 10 runs 
  int seed = rand() % 1000 + 100; 
  int numPlayers = 2; 
  int player = 1;
  int k[10] = {adventurer, smithy, great_hall, steward, embargo, outpost, salvager, sea_hag, gardens, mine};
  int cardNum;
  int handCount = 10; 
  int postHandCount;//smithy draws 3 cards and discards smithy should be 12 after its all said and done
  int preHandCount;//just in case seperate variable
  int i;  
  int j;
  
  
  struct gameState G;
  
  srand(time(NULL));

  printf("Random Tester: Smithy\n");
  
  for (i = 0; i < testRuns; i++){
  
    initializeGame(numPlayers, k, seed, &G);
    G.whoseTurn = player;
    G.handCount[player] = handCount;
    
    G.deckCount[player] = rand() % 400 + 10;
    //build Player 1 
    //Any card is fair game here, not just cards in k
    for(j = 0; j < G.deckCount[player]; j++){
      cardNum = rand() % treasure_map;
      G.deck[player][j] = cardNum; 
    }
    //build Player 1 hand
    //Any card is fair game here, not just cards in k
    G.hand[player][0] = smithy;
    for(j = 1; j < G.handCount[player]; j++){
      cardNum = rand() % treasure_map;
      G.hand[player][j] = cardNum;
    }
    
    preHandCount = G.handCount[player];
    printf("Hand Size Pre Smithy: %d\n", preHandCount);
    printf("Pre smithy cards: ");
    for(j = 0; j < G.handCount[player]; j++){//13 is smithy
      
      printf("%d ", G.hand[player][j]);
    }
    printf("\n");
    
    playCard(0,0,0,0,&G); 
    
    postHandCount = G.handCount[player];
    if(postHandCount != 12){
      printf("Problem with hand Size\n");
      printf("Hand Size Post Smithy: %d\n", postHandCount);
    }
    else{
      printf("Hand Size is Appropriate");
    }
    printf("Post smithy cards in hand: ");
    for(j = 0; j < G.handCount[player]; j++){//13 is smithy
      
      printf("%d ", G.hand[player][j]);
    }
    printf("\n");
    
    printf("Run Number: %d\n" ,i);
    printf("\n");
    printf("\n");
  }
  return 0;
}