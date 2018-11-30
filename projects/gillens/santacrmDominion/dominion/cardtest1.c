#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

//Unit test for Smithy 

int main(){
  int j;
  int cardNum;
  int seed = 500; 
  int numPlayers = 2; 
  int player = 1;
  int k[10] = {adventurer, smithy, great_hall, steward, embargo, outpost, salvager, sea_hag, gardens, mine};
  srand(time(NULL));
  struct gameState G;
  
  initializeGame(numPlayers, k, seed, &G);
  
  //First Test will have 3 cards in deck
  //One card being smithy in hand
  G.deckCount[player] = 3;
  G.handCount[player] = 1;
  for(j = 0; j < G.deckCount[player]; j++){
      cardNum = rand() % treasure_map;
      if(cardNum == 13){
        cardNum++;
      }
      G.deck[player][j] = cardNum;
  }
  
  G.hand[player][0] = smithy;
  printf("First Test: 3 cards in deck, 1 card in hand\n");
  printf("One copy of smithy.(The one being played)\n");
  printf("Hand state is: ");
  for(j = 0; j < G.handCount[player]; j++){
      
      printf("%d ", G.hand[player][j]);
    }
  printf("\n");
  smithyCard(&G, 0, 1);
  printf("\n");
  printf("Hand state Post Smithy: ");
  for(j = 0; j < G.handCount[player]; j++){
      
      printf("%d ", G.hand[player][j]);
  }
  printf("\n");
  printf("Deck Count: %d\n", G.deckCount[player]);
  printf("\n");
  //First Test will have 0 cards in deck
  //One card being smithy in hand
  G.deckCount[player] = 0;
  G.handCount[player] = 1;
  
  G.hand[player][0] = smithy;
  printf("Second Test: 0 cards in deck, 1 card in hand\n");
  printf("One copy of smithy.(The one being played)\n");
  printf("Hand state is: ");
  for(j = 0; j < G.handCount[player]; j++){
      
      printf("%d ", G.hand[player][j]);
    }
  printf("\n");
  smithyCard(&G, 0, 1);
  printf("\n");
  printf("Hand state Post Smithy: ");
  for(j = 0; j < G.handCount[player]; j++){
      
      printf("%d ", G.hand[player][j]);
  }
  printf("\n");
  printf("Deck Count: %d\n", G.deckCount[player]);
  return 0;
}