#include "hash.h" 
#include <iostream>
using namespace std;

Hash::Hash(int max) {  
  length = 0;
  max_items = max;
  structure = new Aluno[max_items];
}

Hash::~Hash(){
  delete [] structure;
}

bool Hash::isFull() const {
  return (length == max_items);
}

int Hash::getLength() const {
  return length;
}

void Hash::retrieveItem(Aluno& aluno, bool& found) {
  int startLoc = getHash(aluno);
  bool moreToSearch = true; 
  int location = startLoc;

  // calcular quanto adiciona em caso de colisao
  int collision;
  collision = getHashCollision(aluno);

  do {
    if (structure[location].getRa() == aluno.getRa() ||
	structure[location].getRa() == -1)
      moreToSearch = false;
    else
      // adiciona o que foi calculado ao inves de "1"
      location = (location + collision) % max_items;
  } while (location != startLoc && moreToSearch);
  
  found = (structure[location].getRa() == aluno.getRa() );   
  if (found) { 
    aluno = structure[location];
  }
}

void Hash::insertItem(Aluno aluno) {
  int location;
  location = getHash(aluno);

  // calcular quanto adiciona em caso de colisao
  int collision;
  collision = getHashCollision(aluno);

  while (structure[location].getRa() > 0)
    // adiciona o que foi calculado ao inves de "1"
    location = (location + collision) % max_items;
  structure[location] = aluno;
  length++;
}

void Hash::deleteItem(Aluno aluno) {
  int startLoc = getHash(aluno);
  bool moreToSearch = true; 
  int location = startLoc;

  // calcular quanto adiciona em caso de colisao
  int collision;
  collision = getHashCollision(aluno);

  do {
    if (structure[location].getRa() == aluno.getRa() ||
	structure[location].getRa() == -1)
      moreToSearch = false;
    else
      // adiciona o que foi calculado ao inves de "1"
      location = (location + collision) % max_items;
  } while (location != startLoc && moreToSearch);

  if (structure[location].getRa() == aluno.getRa()) {       
    structure[location] = Aluno(-2,"");
    length--;
  }
}

void Hash::print() {
  for (int i = 0; i < max_items; i++) {
    cout << i <<":"<< structure[i].getRa()<<", "<<structure[i].getNome()<<endl;
  }
}

int Hash::getHash(Aluno aluno){
  return aluno.getRa() % max_items;
}

int Hash::getHashCollision(Aluno aluno) {
    return 7 - aluno.getRa() % 7;
}
