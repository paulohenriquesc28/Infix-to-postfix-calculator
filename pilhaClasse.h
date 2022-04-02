/*
   Pilha estatica e sequencial
   Desenvolvimento com classe
   criado: 15/02/2022.
   prof. Dr. Ivan Carlos Alcantara de Oliveira
*/

/*
Paulo Henrique Sousa Camargo 32138121
Thales Torres Lopes 32135513
Vincenzo Sivero Ferreira Alberice 32135661
Victor Silva Fernandes 32163967

LINK PARA O VIDEO: https://www.youtube.com/watch?v=V7Aq3Rzmhl4&ab_channel=PauloHenrique
*/

#include <iostream>

using namespace std;

// definicao de um novo tipo de dado
typedef int Elem; 

// constante que indica o 
// Tamanho alocado para a pilha
const int TAM_PILHA = 10;

// Classe pilha estatica e sequencial
class Pilha {
	private:
   		int topoPilha;
   		Elem e[TAM_PILHA];
   	public:
   		Pilha();
   		~Pilha();
   		bool isEmpty();
   		bool isFull();
   		void push(Elem e);
   		Elem pop();
   		Elem topo(); 
		int size();		
};

// Construtor da Pilha
Pilha::Pilha(){
  this->topoPilha = -1;
}

// Destrutor da pilha
// Não faz nada, pois 
// a alocação é estática e senquencial
Pilha::~Pilha(){};

// Verifica se a pilha
// está vazia
bool Pilha::isEmpty( ) {
  if (this->topoPilha == -1)
   	return true;
  else
   	return false;
}

// Verifica se a pilha está
// cheia
bool Pilha::isFull( ){
  if (this->topoPilha == TAM_PILHA-1)
   	return true;
  else
   	return false;
}

// insere um elemento e 
// no topo da pilha
void Pilha::push( Elem e ){
  if (! this->isFull( ))
    this->e[++this->topoPilha] = e;
  else 
    cout << "overflow - Estouro de Pilha";
}

// remove um elemento 
// do topo da pilha
Elem Pilha::pop( ){
  if (! this->isEmpty( ))
   return this->e[this->topoPilha--];
  else{
    cout << "underflow - Esvaziamento de Pilha";
    return -1;
  }
}

// Retorna o elemento que está
// no topo da pilha
Elem Pilha::topo( ){
  if ( ! this->isEmpty( ))
   	return this->e[this->topoPilha];
  else{
    cout << "underflow - Esvaziamento de Pilha";
    return -1;
  }
}

/// obtém o total de elementos 
// armazenados na Pilha
int Pilha::size( ){
  return topoPilha+1;
}

/*
Fontes para tudo que foi usado para fazer o codigo:
https://www.cplusplus.com/reference/algorithm/count/
https://www.cmmprogressivo.net/2019/11/Exponenciacao-usando-lacos-Cmm.html
https://docs.microsoft.com/pt-br/cpp/cpp/?view=msvc-170
https://www.youtube.com/watch?v=dLNBitfwqzo&ab_channel=Programeseufuturo
*/