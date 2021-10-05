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

  // ja estava aqui: imprime todas as pessoas da Hash
  alunosHash.print();  

  cout << "------------------------------" <<  endl;

  // alterado numero: virou 19, como pedido no exercicio
  Aluno aluno(19,"");  

  // ja estava aqui: pega o aluno da Hash
  bool     found = false;
  alunosHash.retrieveItem(aluno, found);

  // ja estava aqui: imprime o aluno que foi pego
  cout << aluno.getNome() << " -> " << found << endl;
  
  cout << "------------------------------" <<  endl;

  // ja estava aqui: remove o aluno que foi pego
  alunosHash.deleteItem(aluno);

  // ja estava aqui: imprime todas as pessoas da Hash de novo,
  // agora sem o aluno removido
  alunosHash.print();

  cout << "Fim" << endl;  
}
