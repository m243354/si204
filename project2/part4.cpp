#include <iostream>
#include <ctime>

using namespace std;

int** genDeck() {
  int** deck = new int*[52];
  //v is face value and s is suit
  int v=2, s=0;
  for(int c=0; c<52; c++) {

    if(c%13==0) {
      s++;
    }

    //create each card pointer
    deck[c] = new int[3];
    deck[c][2] = 100*s+v;
    deck[c][0] = s;
    deck[c][1] = v++;

    if(v>14){
      v=2;
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

void printDeck(int** deck) {
  for(int i=0; i<52; i++) {
    //first index is the face value
    printCard(deck[i], true);
  }

}

void displayHands(int*** players, int turns) {
  cout << '\n' << " Player Dealer \n";
  for(int i=0; i<turns; i++) {
    //uses print card function. Player[1] is player hand. Take ith card in that hand and then get the suit and value to print. Same for dealer
    cout << "| ";
    printCard(players[1][i], false);
    cout << "  | ";
    printCard(players[0][i], false);
    cout << "  |\n";
  }
  cout << '\n';
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

void dealCards(int** deck, int*** players, int turn) {
  //index 0 will be dealer and index 1 will be player
  //pick for player first then dealer
  //if turn is 0, choose 0 and 1. If turn is 1, choose 2 and 3, turn is 2 choose 4 and 5, turn is 3 choose 6 and 7
  for(int i=0; i<3; i++) {
    players[1][turn][i] = deck[turn*2][i];
    players[0][turn][i] = deck[turn*2+1][i];
  }
}

bool hitOrStd(int round) {
  cout << "Round " << round << " Player's turn \nhit or stand? [h/s] ";
  char c;
  cin >> c;
  if(c=='h') {
    return true;
  } else {
    return false;
  }
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

  //take in user input
  takeInput(deck);
  //printDeck(deck);
  //deal twice to start
  int ccount = 0;
  dealCards(deck, players, ccount++);
  dealCards(deck, players, ccount++);

  while(play) {
    displayHands(players, ccount);
    if(hitOrStd(turn)) {
      dealCards(deck, players, ccount++);
    } else {
      //do else?
      play = false;
    }
    turn++;
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
