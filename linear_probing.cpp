#include "hash.h" 
#include <iostream>
using namespace std;

// construtor
Hash::Hash(int max) {  
  length = 0;
  max_items = max;
  structure = new Aluno[max_items];
}

// destrutor
Hash::~Hash(){
  delete [] structure;
}

// se o maximo de alunos for igual a quantidade ja armazenada, esta cheia
bool Hash::isFull() const {
  return (length == max_items);
}

int Hash::getLength() const {
  return length;
}

// pega um aluno, usando o ra
// se não encontrar, coloca false em "found"
// se encontrar, coloca true em "found"
void Hash::retrieveItem(Aluno& aluno, bool& found) {

  // calcula o que seria a localizacao inicial do aluno, sem contar colisoes
  int startLoc = getHash(aluno);

  bool moreToSearch = true; 

  // copia a localizacao inicial para calcular
  // a localizacao final caso tenha colisao
  int location = startLoc;

  // calcular quanto adicionar em caso de colisao
  int collision;
  collision = getHashCollision(aluno);

  do {
    // se encontrar o aluno com o RA pedido
    //     - significa que encontrou o aluno buscado
    // se encontrar um espaço com -1
    //     - significa que chegou a um espaço que nunca teve um aluno
    if (structure[location].getRa() == aluno.getRa() ||
	structure[location].getRa() == -1)
      // vai parar a busca, pois não tem mais porque procurar
      moreToSearch = false;
    else
      // se não for nenhum dos casos, o aluno pode estar no proximo espaco
      // adiciona o que foi calculado ao inves de "1"
      location = (location + collision) % max_items;

    // vai sair da repeticao quando moreToSearch = false
    //     - porque caiu no if acima
    // ou quando a localizacao voltar a ser a inicial
    //     - porque se chegou ao inicio, vai comecar tudo de novo e ficar procurando para sempre
  } while (location != startLoc && moreToSearch);
  
  // se o RA for o mesmo procurado, significa que encontrou o aluno
  found = (structure[location].getRa() == aluno.getRa() );   
  if (found) { 
    // se encontrou, pode colocar ele em "aluno"
    aluno = structure[location];
  }
}

void Hash::insertItem(Aluno aluno) {
  // calcula o que seria a localizacao inicial do aluno, sem contar colisoes
  int location;
  location = getHash(aluno);

  // calcular quanto adiciona em caso de colisao
  int collision;
  collision = getHashCollision(aluno);

  // enquanto estiver encontrando espacos que ja tenham alunos
  while (structure[location].getRa() > 0)
    // adiciona o que foi calculado ao inves de "1"
    location = (location + collision) % max_items;

  // guarda o aluno no espaco vazio
  structure[location] = aluno;

  // aumenta a variavel que guarda quantos espacos ja estao ocupados
  length++;
}

void Hash::deleteItem(Aluno aluno) {

  // calcula o que seria a localizacao inicial do aluno, sem contar colisoes
  int startLoc = getHash(aluno);

  bool moreToSearch = true; 

  // copia a localizacao inicial para calcular
  // a localizacao final caso tenha colisao
  int location = startLoc;

  // calcular quanto adiciona em caso de colisao
  int collision;
  collision = getHashCollision(aluno);

  do {
    // se encontrar o aluno com o RA pedido
    //     - significa que encontrou o aluno buscado
    // se encontrar um espaço com -1
    //     - significa que chegou a um espaço que nunca teve um aluno
    if (structure[location].getRa() == aluno.getRa() ||
	structure[location].getRa() == -1)
      // vai parar a busca, pois não tem mais porque procurar
      moreToSearch = false;
    else
      // se não for nenhum dos casos, o aluno pode estar no proximo espaco
      // adiciona o que foi calculado ao inves de "1"
      location = (location + collision) % max_items;

    // vai sair da repeticao quando moreToSearch = false
    //     - porque caiu no if acima
    // ou quando a localizacao voltar a ser a inicial
    //     - porque se chegou ao inicio, vai comecar tudo de novo e ficar procurando para sempre
  } while (location != startLoc && moreToSearch);

  // se o RA for o mesmo procurado, significa que encontrou o aluno
  if (structure[location].getRa() == aluno.getRa()) {       
    // se encontrou, coloca o RA como -2 e o nome como vazio
    // assim dá para saber que esse espaço está vazio,
    // mas o próximo espaço pode não estar
    structure[location] = Aluno(-2,"");
    length--;
  }
}

// imprime cada um dos espaços da Hash
// contendo ou não um aluno no espaco
void Hash::print() {
  for (int i = 0; i < max_items; i++) {
    cout << i <<":"<< structure[i].getRa()<<", "<<structure[i].getNome()<<endl;
  }
}

// calcula a posicao inicial para o aluno
int Hash::getHash(Aluno aluno){
  return aluno.getRa() % max_items;
}

// calcula quantos espaços "anda" em caso de colisao
int Hash::getHashCollision(Aluno aluno) {
    return 7 - aluno.getRa() % 7;
}
