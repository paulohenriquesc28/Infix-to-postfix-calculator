/*
Paulo Henrique Sousa Camargo 32138121
Thales Torres Lopes 32135513
Vincenzo Sivero Ferreira Alberice 32135661
Victor Silva Fernandes 32163967

LINK PARA O VIDEO: https://www.youtube.com/watch?v=V7Aq3Rzmhl4&ab_channel=PauloHenrique
*/

#include <cstdlib> // Biblioteca para fazer o programa parar.
#include <iostream> // Biblioteca de input e output.
#include <algorithm>// Biblioteca foi utilizada para fazer a expressao que tem parenteses funcionar. Tentamos implementar com um contador comum usando o ++ porem o codigo estava dando erro. Atraves de uma dica de um amigo ele recomendou essa biblioteca do propio c++ onde o codigo funciona.
#include "pilhaClasse.h" // Codigo de pilha usando classe fornecido pelo professor.
using namespace std;

string infix;
string posfixa;
char variables[26] = {};
int values[26] = {};

int exponeciacao(int base, int expo) // Codigo para fazer a conta de exponeciacao. Foi usado a biblioteca math.h pra usar a funcao pow porem achamos que nao ia ser aceito. Porem a funcao pow da biblioteca math tem uma funcionalidade melhor que o algoritmo criado.
{
    int res=1, aux;
    for(aux=1 ; aux<=expo ; aux++)
        res *= base;
    return 0;
}

// Funcao para retornar a procedencia dos operadores
int prec(char c)
{
	if(c == '^')
		return 3;
	else if(c == '/' || c == '*')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else
		return -1;
}

// Função principal para converter a expressão infixa para posfixa
void infixaToPosfixa(string s)
{

	Pilha st; //Iniciando a pilha
	string result;

	if (count(s.begin(), s.end(), '(') != count(s.begin(), s.end(), ')')) // O unico jeito que achamos para fazer a expressao funcionar quando se usa parenteses.
	{
		cout << "Expressao invalida!" << endl;
		return;
	}

	for(int i = 0; i < s.length(); i++)
	{
		char c = s[i];

		// Se o caractere escaneado for um
		// operando, coloque-o na string de output.
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;


		// Se o caractere escaneado for um
		// ‘(‘, coloque-o na Pilha.
		else if(c == '(')
			st.push('(');



		// Se o caractere scaneado for um ‘)’, use um pop e dê o output da string da Pilha até que um ‘(‘ seja encontrado.
		else if(c == ')')
		{
			while(st.topo() != '(')
			{
				result += st.topo();
				st.pop();
			}
			st.pop();
		}

		//Se um operador for inválido, então erro
		else if(prec(c) == -1)
		{
			cout << "Operador Invalido!" << endl;
			return;
		}

		//Se um operador for escaneado
		else
		{
			while(!st.isEmpty() && prec(s[i]) <= prec(st.topo()))
			{
				result += st.topo();
				st.pop();
			}
			st.push(c);
		}
	}

	// Usa pop em todos os elementos restantes da Pilha
	while(!st.isEmpty())
	{
		result += st.topo();
		st.pop();
	}
	posfixa = result;
	cout << result << endl;
}

float calc(float o1, float o2, char c)
{
	if(c == '+') return o1 + o2;
	if(c == '-') return o1 - o2;
	if(c == '*') return o1 * o2;
	if(c == '/') return o1 / o2;
	if(c == '^') return	exponeciacao(o1, o2);
	else return 0;
}

float calculaPosfixo(string exp)
{
	float result = 0;
	Pilha s ;
	int dig = 0;
	int i = 0;
	while(i < exp.length())
	{
		char e = exp[i];
		if(isdigit(exp[i]))
		{
			dig = dig * 10 + (exp[i] - '0');
		}
		else if (exp[i] == ' ')
		{
			s.push(dig);
			dig = 0;
		}
		else
		{
			float o2 = s.topo();
			s.pop();
			float o1 = s.topo();
			s.pop();
			result = calc(o1, o2, e);
			s.push(result);
			i++;

		}
		i++;
	}
	return s.topo();
}

void menu()
{
	while (true)
	{
		cout << "Escolha as opcoes abaixo:" << endl;
		cout << "1- Entrada da expressão aritmética na notação infixa" << endl;
		cout << "2- Entrada dos valores numéricos associados às variáveis." << endl;
		cout << "3- Conversão da expressão, da notação infixa para a notação posfixa, e exibição da expressão convertida para posfixa" << endl;
		cout << "4- Avaliação da expressão (apresentação do resultado do cálculo, mostrando a expressão e os valores das variáveis)." << endl;
		cout << "5- Encerramento do programa." << endl;
		int option;
		cin >> option;
		switch (option)
		{
		case 1:
		{
			fill(variables, variables + 26, '0');
			cout << "Entre com a expressao infixa" << endl;
			cin >> infix;
			for (int i = 0; i < infix.length(); i++)
			{
				if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
				{
					int counter = 0;
					for(int j = 0; j < 26; j++)
					{
						if (infix[i] == variables[j])
						{
							counter++;
						}
					}
					if (counter == 0)
					{
						variables[i] = infix[i];
					}
				}
			}
			break;
		}
		case 2:
		{
			if(infix == "" || infix[0] == '0')
			{
				cout << "Entre com a expressao infixa" << endl;
				break;
			}
			cout << "Entre com o valor numerico das variaveis" << endl;
			for (int i = 0; i < 26; i++)
			{
				if ((variables[i] >= 'a' && variables[i] <= 'z') || (variables[i] >= 'A' && variables[i] <= 'Z'))
				{
					cout << variables[i] << " = ";
					cin >> values[i];
				}
			}
			break;
		}
		case 3:
		{
			if(infix == "" || infix[0] == '0')
			{
				cout << "Entre com a expressao infixa" << endl;
				break;
			}
			cout << "Convertendo de infixa para posfixa" << endl;
			infixaToPosfixa(infix);
			break;
		}
		case 4:
		{
			if(posfixa == "")
			{
				cout << "Convertendo de infixa para posfixa" << endl;
				break;
			}
			cout << "Printando o resultado" << endl;
			string temp;
			for (int i = 0; i < posfixa.length(); i++)
			{
				int check = 0;
				for (int j = 0; j < 26; j++)
				{
					if (posfixa[i] == variables[j])
					{
						if (i != 0)
						{
							temp += ' ';
						}
						temp += to_string(values[j]);
						check++;
					}
				}
				if (check == 0 && i != 0)
				{
					temp += ' ';
					temp += posfixa[i];
				}
				if (check == 0 && i == 0)
				{
					temp += posfixa[i];
				}
			}
			cout << temp << endl;
			cout << calculaPosfixo(temp) << endl;
			break;
		}
		case 5:
			cout << "Saindo..." << endl;
      system("pause");
			return;
		default:
			cout << "Opcao Invalida!" << endl;
			break;
		}
	}
}

// Programa para testar as funções acima
int main()
{
	menu();
	return 0;
}

/*
Fontes para tudo que foi usado para fazer o codigo:
https://www.cplusplus.com/reference/algorithm/count/
https://www.cmmprogressivo.net/2019/11/Exponenciacao-usando-lacos-Cmm.html
https://docs.microsoft.com/pt-br/cpp/cpp/?view=msvc-170
https://www.youtube.com/watch?v=dLNBitfwqzo&ab_channel=Programeseufuturo
*/