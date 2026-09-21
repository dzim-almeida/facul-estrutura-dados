# Aula 02 — Introdução ao C++

## Objetivos

- Entender como um programa C++ é pré-processado, compilado e ligado.
- Organizar identificadores com namespaces e utilizar bibliotecas com `#include`.
- Aplicar estruturas de seleção e repetição.
- Compreender a representação básica de strings em C++.

## Compilação e ligação

Um programa C++ passa por etapas distintas:

1. O pré-processador expande diretivas como `#include`.
2. O compilador transforma cada arquivo-fonte em código objeto (`.o`).
3. O linker combina os arquivos objeto e as bibliotecas necessárias para gerar o executável.

Por isso, uma declaração disponibilizada por um cabeçalho não substitui a implementação. Quando uma função é definida em outro arquivo `.cpp`, esse arquivo também precisa participar do comando de compilação e ligação.

## Bibliotecas e `#include`

`#include` inclui as declarações de um cabeçalho no ponto em que a diretiva aparece. Por exemplo, `<iostream>` disponibiliza os recursos de entrada e saída usados por `std::cin` e `std::cout`.

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

O uso explícito de `std::` deixa claro de qual namespace cada identificador vem. `using namespace std;` pode ser usado em exemplos pequenos, mas deve ser evitado em cabeçalhos e em código com muitos namespaces para reduzir conflitos de nomes.

## Namespaces

Um namespace cria um escopo para funções, variáveis e tipos. Ele permite que dois módulos tenham identificadores iguais sem conflito, desde que estejam em namespaces diferentes.

```cpp
namespace conversao {
    int metrosParaCentimetros(int metros) {
        return metros * 100;
    }
}

int resultado = conversao::metrosParaCentimetros(2);
```

O operador `::` acessa um nome dentro de um namespace. A biblioteca padrão utiliza o namespace `std`.

## Estruturas de seleção

- `if` e `else`: escolhem caminhos com base em uma condição.
- `switch`: seleciona um bloco a partir de valores inteiros, caracteres ou enumerações.
- Operador ternário `condicao ? valorSeVerdadeiro : valorSeFalso`: representa uma escolha curta que produz um valor.

```cpp
int sinal = (valor >= 0) ? 1 : -1;
```

## Estruturas de repetição

- `while`: testa a condição antes de cada iteração.
- `do ... while`: executa o bloco pelo menos uma vez e testa depois.
- `for`: reúne inicialização, condição e atualização em uma única estrutura.

Em todos os casos, é necessário garantir que a condição de parada seja alcançada para evitar um laço infinito.

## Strings

Uma string no estilo C é uma sequência de caracteres armazenada em um vetor e terminada pelo caractere nulo `\0`. Em C++ moderno, `std::string` é normalmente preferível porque administra tamanho e operações comuns de forma mais segura.

```cpp
#include <string>

std::string nome = "Ana";
```

Ao trabalhar com vetores de `char`, é necessário reservar espaço para o terminador `\0` e não acessar posições fora dos limites.

## Atividades

- [Atividade 01](att-01/att-01.cpp)
- [Atividade 02](att-02/att-02.cpp)
- [Atividade 03](att-03/att-03.cpp)
- [Atividade 04](att-04/att-04.cpp)
- [Atividade 05](att-05/att-05.cpp)
- [Atividade 06](att-06/att-06.cpp)
- [Atividade 07](att-07/cobrinha.cpp)

Cada atividade será documentada com o problema, a estratégia de resolução, o funcionamento das funções e um exemplo de execução.

## Compilação

A partir da pasta da atividade, use:

```bash
g++ -std=c++17 -Wall -Wextra arquivo.cpp -o app
./app
```