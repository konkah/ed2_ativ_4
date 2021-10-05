#include <iostream>
using namespace std;

// Estrutura da classe para armazenar cada Aluno
class Aluno{
private :
  int         ra;
  std::string nome;  
public:  
  Aluno();
  Aluno(int ra, std::string nome);
  string getNome() const;
  int getRa() const;
};
