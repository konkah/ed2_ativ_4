#include <iostream>
#include "hash.h" 

using namespace std;

int main(){
  Hash alunosHash(11);

  // alterados RA para os numeros pedidos na atividade
  int ras[5] = { 41, 48, 19, 12, 30 };
  string nomes[5] = {
    "Pedro", "Raul", "Paulo",
    "Carlos", "Lucas" }; // removidos dois alunos que sobraram

  // diminuido tamanho do for
  for (int i = 0; i < 5; i++) {
    Aluno aluno = Aluno(ras[i], nomes[i]);
    alunosHash.insertItem(aluno);
  }
  alunosHash.print();  
  cout << "------------------------------" <<  endl;

  // alterado numero a ser removido
  Aluno aluno(19,"");  
  bool     found = false;
  alunosHash.retrieveItem(aluno, found);
  cout << aluno.getNome() << " -> " << found << endl;
  
  cout << "------------------------------" <<  endl;

  alunosHash.deleteItem(aluno);
  alunosHash.print();
  cout << "Fim" << endl;  
}
