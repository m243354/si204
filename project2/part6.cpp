#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

int** genDeck() {
  int** deck = new int*[52];
  //v is face value and s is suit pv is point value
  int v=2, s=0, pv = 2;
  for(int c=0; c<52; c++) {

    if(c%13==0) {
      s++;
    }

    //create each card pointer
    deck[c] = new int[3];
    deck[c][2] = pv++;
    deck[c][0] = s;
    deck[c][1] = v++;
    if(pv > 10) {
      pv = 10;
      //makes point value 10 for all face cards
    }
    //aces are scored as 1
    if(v == 14) {
      pv = 1;
    }

    if(v>14){
      v=2;
      pv = 2;
      //resets v and pv after counting all the face cards
    }
  }
  return deck;
}

void swap(int** d, int p1, int p2) {
  //swaps the item at position 1 with position 2
  int* temp = d[p1];
  d[p1] = d[p2];
  d[p2] = temp;
}

void shuffle(int** deck) {
  //shuffle psuedocode is given in instructions
  for(int c=0; c<52; c++) {
    int j = rand() % 52;
    swap(deck, j, c);
  }
}

void printCard(int* card, bool newLine) {
  string cd;
  int face = card[1];
  int suit = card[0];
  switch(face) {
    case 11:
    //jack
      face = 74;
      break;

    case 12:
    //queen
      face = 81;
      break;

    case 13:
    //king
      face = 75;
      break;

    case 14:
    //ace
      face = 65;
      break;

    case 10:
    //cout a 1 for the other stuff later
      cout << 1;
      face = 48;
      break;

    default:
    //face card
      face += 48;
      break;
  }
  if(face != 48) {
    cout << " ";
  }
  //cout <<"  suit:" <<suit << " ";
  //unix suit codes for output
  switch(suit) {
    case 1:
      cd = "\u2663";
      break;
    case 2:
      cd = "\u2666";
      break;
    case 3:
      cd = "\u2665";
      break;
    case 4:
      cd = "\u2660";
      break;
  }

  cout << char(face) << cd;
  if(newLine) {
    cout << "\n";
  }
}

void printDeck(int** deck,int n) {
  for(int i=0; i<n; i++) {
    //first index is the face value
    printCard(deck[i], true);
  }
}

int scoreMe(int*** players, int turns, int count, int index) {
  int pScore = 0;
  bool pAce = false;
  for(int i=0; i<turns+1; i++) {
    if(i < count) {
      pScore += players[index][i][2];
    }
    if(players[index][i][1] == 14) {
      //ace
      pAce = true;
    }
  }

  if((pScore+10)<21 && pAce) {
    pScore += 10;
  }

  return pScore;
}


//reads a deck and returns dealer score and couts both scores
int scoreDeck(int*** players, int turns, int pCount, int dCount, bool printScore) {
  int p1Score = 0, p2Score = 0;
  bool p1Ace = false, p2Ace = false;
  for(int i=0; i<turns+1; i++) {
    if(i < pCount) {
      p1Score += players[1][i][2];
    }
    if(players[1][i][1] == 14) {
      //ace
      p1Ace = true;
    }

    if(i < dCount) {
      p2Score += players[0][i][2];
    }
    if(players[0][i][1] == 14) {
      //ace
      p2Ace = true;
    }
  }

  if((p1Score+10)<21 && p1Ace) {
    p1Score += 10;
  }
  if((p2Score+10)<21 && p2Ace) {
    p2Score += 10;
  }
  if(printScore) {
    cout << "Player " << p1Score << ", Dealer " << p2Score << '\n';
  }
  return p2Score;
}

void displayHands(int*** players, int turns, int pCount, int dCount, bool printScore) {
  cout << " Player Dealer\n";
  //turns starts at 1 when card count is 2, so max card count is 1+turns. Run this loop for maximum possible cards and only print if there is a card at that index.
  for(int i=0; i<turns+1; i++) {
    //uses print card function. Player[1] is player hand. Take ith card in that hand and then get the suit and value to print. Same for dealer
    if(i < pCount || i < dCount) {
      cout << "| ";

      if(i < pCount) {
        //cout << "i=" << i << " players=" << players[1][i][0] << '\n';
        printCard(players[1][i], false);
      } else {
        cout << "   ";
      }
      cout << "  | ";

      if(i < dCount) {
        printCard(players[0][i], false);
      } else {
        cout << "   ";
      }
      cout << "  |\n";
    }
  }
  int temp = scoreDeck(players, turns, pCount, dCount, printScore);
}

void takeInput(int** deck) {
  cout << "Shuffle: [n | s | u <seed>]: ";
  char in;
  cin >> in;

  switch(in) {
    case 110:
    //lowercase n
    //no shuffling
      break;

    case 115:
      //lowercase s so shuffle
      srand(time(0));
      shuffle(deck);
      break;

    case 117:
      //u is given so read a seed s
      int s;
      cin >> s;
      srand(s);
      shuffle(deck);
      break;

    default:
      break;
  }
}

void dealCards(int** deck, int*** players, int pCount, int dCount, bool dealP, bool dealD) {
  //index 0 will be dealer and index 1 will be player
  //pick for player first then dealer
  //if turn is 0, choose 0 and 1. If turn is 1, choose 2 and 3, turn is 2 choose 4 and 5, turn is 3 choose 6 and 7
  //pcount is the index of the next card to give to the player
  //cout << "pcount: " << pCount << " dcount: " << dCount << '\n';
  int totalCards = (pCount)+(dCount)+2;
  int next = totalCards-2;
  for(int i=0; i<3; i++) {
    if(dealP && dealD) {
      players[1][pCount][i] = deck[next][i];
      players[0][dCount][i] = deck[next+1][i];
    } else if(dealD) {
      players[0][dCount][i] = deck[next][i];
    } else if(dealP) {
      players[1][pCount][i] = deck[next][i];
    }
  }
}

bool hitOrStd(int round, int choice) {
  string s = "Dealer";
  if(choice == 0) {
    s = "Player";
  }
  cout << "Round " << round << " " << s <<"'s turn\nhit or stand? [h/s] ";
  char c;
  cin >> c;

  if(c == 'h') {
    return true;
  }
  return false;
}


int main() {
  //generate card deck that is a list of lists containing card attributes
  int** deck = genDeck();
  int cardHoldMax = 20;
  //create three nested arrays for each players hands. Index 0 is dealer hand and index 1 is player hand
  int*** players = new int**[2];
  //each player can hold up to cardholdmax of a card
  for(int p=0; p<2; p++) {
    players[p] = new int*[cardHoldMax];
    for(int c=0; c<cardHoldMax; c++) {
      players[p][c] = new int[3];
    }
  }
  //deck[card, card, ...]
  //card[suit, face, stuff]

  //Players [dealer, player]
  //dealer[card, card, card,...]
  //card[suit, face, stuff]

  int turn = 1;
  bool play = true;
  bool playerIn = true;
  bool dealerIn = true;

  //take in user input
  takeInput(deck);
  system("clear");
  //printDeck(deck);
  //deal twice to start
  //pccard count is the index of the card to deal and should be incremented after each call to deal cards
  int pccount = 0, dccount = 0;
  dealCards(deck, players, pccount++, dccount++, true, true);
  dealCards(deck, players, pccount++, dccount++, true, true);
  displayHands(players, turn, pccount, dccount, true);

  while(play) {
    //ask player to hit or stand
    if(playerIn) {
      if(hitOrStd(turn, 0)) {
        //cout << "player card count=" << pccount << endl;
        dealCards(deck, players, pccount++, dccount, true, false);
        //printDeck(players[0]);
      } else {
        playerIn = false;
        //do else?
        //play = false;
      }
      //count to turn+1 because it hasnt accounted for the turn being incremented afer both players move.
      system("clear");
      displayHands(players, turn+1, pccount, dccount, true);
    }
    if(dealerIn) {
      cout << flush;
      sleep(2);
      bool decide = scoreDeck(players, turn, pccount, dccount, false) < 17;
      cout << "Round " << turn << " Dealer's turn\nhit or stand? [h/s] ";
      if(decide) {
        cout << "h\n";
        dealCards(deck, players, pccount, dccount++, false, true);
      } else {
        cout << "s\n";
        //do else?
        //play = false;
        dealerIn = false;
      }
      system("clear");
      if(turn < 3) {
        displayHands(players, turn+1, pccount, dccount, true);
      } else {
        displayHands(players, turn+1, pccount, dccount, false);
      }
    }


      //ask dealer to hit or stand
      // if(!playerIn) {
      //   turn++;
      // }

    turn++;
    //if(dealerIn && playerIn) {
    //  play = false;

    if(turn > 3) {
      play = false;
    }

    //bust people
    int playerScore, dealerScore;
    playerScore = scoreMe(players, turn, pccount, 1);
    dealerScore = scoreMe(players, turn, pccount, 0);
    if(playerScore > 21) {
      playerIn = false;
    }
    if(dealerScore > 21) {
      dealerIn = false;
    }
    if(!dealerIn && !playerIn) {
      play = false;
    }
    // if(playerScore == 21) {
    //   play = false;
    // }
    // if(dealerScore == 21) {
    //   play = false;
    // }
    if(playerScore == 21 && dealerScore == 21) {
      play = false;
    }
  }

  //delete all
  for(int i=0; i<2; i++) {
    for(int c=0; c<cardHoldMax; c++) {
      delete[] players[i][c];
    }
    delete[] players[i];
  }
  for(int c=0; c<52; c++) {
    delete[] deck[c];
  }
  delete[] deck;
  delete[] players;

  //printDeck(deck);

  return 0;
}
