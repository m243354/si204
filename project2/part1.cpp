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

void printDeck(int** deck) {
  for(int i=0; i<52; i++) {
    //second index is the card stuff
    cout << deck[i][2] << "\n";
  }

}

int main() {
  //generate card deck that is a list of lists containing card attributes
  int** deck = genDeck();

  cout << "Shuffle: [n | s | u <seed>]: ";
  //take in user input
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

  printDeck(deck);

  for(int c=0; c<52; c++) {
    delete[] deck[c];
  }
  delete[] deck;
  
  return 0;
}
