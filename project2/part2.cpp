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

void printCard(int face, int suit) {
  string cd;
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

  cout << char(face) << cd << "\n";
}

void printDeck(int** deck) {
  for(int i=0; i<52; i++) {
    //first index is the face value
    int temp = deck[i][1];
    int suit = deck[i][0];
    printCard(temp, suit);
  }

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


int main() {
  //generate card deck that is a list of lists containing card attributes
  int** deck = genDeck();

  //take in user input
  takeInput(deck);
  printDeck(deck);

  for(int c=0; c<52; c++) {
    delete[] deck[c];
  }
  delete[] deck;

  return 0;
}
