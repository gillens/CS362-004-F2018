#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int main(){

  srand(time(NULL));
  int testRuns = rand() % 100 + 10; //at least 10 runs 
  int seed = rand() % 1000 + 100; 
  int numPlayers = 2; 
  int player = 1;
  int k[10] = {adventurer, smithy, great_hall, steward, embargo, outpost, salvager, sea_hag, gardens, mine};
  int cardNum;
  int preHandCount = 10; 
  int postHandCount = 12;
  int deckCopperCount = 0, deckSilverCount = 0, deckGoldCount = 0;
  int handCopperCount = 0, handSilverCount = 0, handGoldCount = 0;
  int postCopperCount = 0, postSilverCount = 0, postGoldCount = 0;
  int i;  
  int j;
  
  
  struct gameState G;
  
  

  printf("Random Tester: Adventurer\n");
  
  for (i = 0; i < testRuns; i++){
  printf("---------------------BEGIN NEW RUN------------------------\n");
    initializeGame(numPlayers, k, seed, &G);
    G.whoseTurn = player;
    G.handCount[player] = preHandCount;
    
    G.deckCount[player] = rand() % 400 + 10;
    
    printf("Start Hand Amount: %d\n", preHandCount);
    //build Player 1 deck Keep track of Coins
    //Any card is fair game here, not just cards in k
    for(j = 0; j < G.deckCount[player]; j++){
      cardNum = rand() % treasure_map;
      G.deck[player][j] = cardNum;
      
      if(cardNum == copper){
        deckCopperCount++;
      }
      else if(cardNum == silver){
        deckSilverCount++;
      }
      else if(cardNum == gold){
        deckGoldCount++;
      }
    }
    //build Player 1 hand, keep track of coins
    //Any card is fair game here, not just cards in k
    for(j = 0; j < G.handCount[player]; j++){
      cardNum = rand() % treasure_map;
      G.hand[player][j] = cardNum;
      if(cardNum == copper){
        handCopperCount++;
      }
      else if(cardNum == silver){
        handSilverCount++;
      }
      else if(cardNum == gold){
        handGoldCount++;
      }
    }
    
    adventurerCard(&G, player);
    //Check that two cards were drawn
    if(G.handCount[player] != postHandCount){
      if(G.handCount[player] > postHandCount){
        printf("Too many cards were added to hand!\n");
        printf("Hand Count after Card effect: %d\n", G.handCount[player]);
      }
      else if(G.handCount[player] < postHandCount){
        printf("Too few cards were added to hand!\n");
        printf("Hand Count after Card effect: %d\n", G.handCount[player]);
      }
    }
    //Loop to find new treasure card counts
    for(j = 0; j < G.handCount[player]; j++){
      if(G.hand[player][j] == copper){
        postCopperCount++;
      }
      else if(G.hand[player][j] == silver){
        postSilverCount++;
      }
      else if(G.hand[player][j] == gold){
        postGoldCount++;
      }
      
    }
    //Checks status of treasure cards in hand
    //copper
//    if(handCopperCount != postCopperCount){
//      if(handCopperCount < postCopperCount){
//        printf("Copper was added to hand\n");
//        printf("Pre copper amount: %d\n", handCopperCount);
//        printf("Post copper amount: %d\n", postCopperCount);
//      }
//      else if(handCopperCount > postCopperCount){
//        printf("Copper was lost in hand???\n");
//        printf("Pre copper amount: %d\n", handCopperCount);
//        printf("Post copper amount: %d\n", postCopperCount);
//      }
//    }
//    //silver
//    if(handSilverCount != postSilverCount){
//      if(handSilverCount < postSilverCount){
//        printf("Silver was added to hand\n");
//        printf("Pre Silver amount: %d\n", handSilverCount);
//        printf("Post Silver amount: %d\n", postSilverCount);
//      }
//      else if(handSilverCount > postSilverCount){
//        printf("Silver was lost in hand???\n");
//        printf("Pre Silver amount:  %d\n", handSilverCount);
//        printf("Post Silver amount: %d\n", postSilverCount);
//      }
//    }
//    //Gold
//    if(handGoldCount != postGoldCount){
//      if(handGoldCount < postGoldCount){
//        printf("Gold was added to hand\n");
//        printf("Pre Gold amount: %d\n", handGoldCount);
//        printf("Post Gold amount: %d\n", postGoldCount);
//      }
//      else if(handGoldCount > postGoldCount){
//        printf("Gold was lost in hand\n");
//        printf("Pre Gold amount: %d\n", handGoldCount);
//        printf("Post Gold amount: %d\n", postGoldCount);
//      }
//    }
    
    printf("Initial Values of Treasure found in Hand\n");
    printf("Copper: %d\n", handSilverCount);
    printf("Silver: %d\n", handSilverCount);
    printf("Gold: %d\n", handGoldCount);
    printf("Post Values of Treasure found in Hand\n");
    printf("Copper: %d\n", postCopperCount);
    printf("Silver: %d\n", postSilverCount);
    printf("Gold: %d\n", postGoldCount); 
    
    
    printf("Run Number: %d\n" ,i);
    printf("\n");
    printf("\n");
  }
  
  return 0; 
}   
   