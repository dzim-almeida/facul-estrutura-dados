# Estrutura de Dados

Este repositório será usado para organizar as atividades, exercícios e anotações da disciplina de Estrutura de Dados da UFC de Quixadá.

## Organização do repositório

A ideia é manter o conteúdo separado por aula, para facilitar a consulta e o acompanhamento da evolução da disciplina.

```text
.
├── aulas/
│   ├── aula-01-cpp/
│   │   └── main.cpp
│   └── aula-02-*/
├── .vscode/
└── README.md
```

### Como usar essa estrutura

- Cada aula deve ficar em uma pasta própria dentro de `aulas/`.
- O nome da pasta deve seguir um padrão simples, como `aula-01-cpp`, `aula-02-vetores`, `aula-03-listas`, e assim por diante.
- Dentro de cada pasta, coloque os arquivos da atividade daquela aula, como código-fonte, anotações e exemplos.
- A primeira aula já está preparada como base para C++ em `aulas/aula-01-cpp/`.

## Ambiente para C++

O repositório já está configurado para uso no VS Code com `g++`, incluindo tarefas de compilação e depuração.

Para compilar um arquivo aberto no editor, use a tarefa de build padrão.
Para depurar, use a configuração de execução já criada no VS Code.

## C++ e g++

C++ é uma linguagem de programação de propósito geral, muito usada em disciplinas de estrutura de dados, porque permite trabalhar com controle de memória, desempenho e diferentes estilos de programação ao mesmo tempo.

Na prática, C++ é uma linguagem compilada. Isso significa que o código escrito em arquivos como `main.cpp` precisa passar por um compilador antes de gerar um programa executável.

O `g++` é o compilador de C++ do projeto GNU. Ele faz parte do ecossistema GCC e é responsável por transformar o código-fonte em um programa que pode ser executado no sistema operacional.

### Como a compilação funciona

Ao compilar um arquivo C++, o processo normalmente passa por estas etapas:

1. Pré-processamento: trata diretivas como `#include` e `#define`.
2. Compilação: converte o código C++ em código intermediário ou assembly.
3. Montagem: transforma o assembly em arquivo objeto.
4. Ligação: junta os arquivos objeto e gera o executável final.

### Comandos mais usados do compilador

- `g++ arquivo.cpp -o programa`: compila e gera um executável com o nome indicado após `-o`.
- `g++ -std=c++17 arquivo.cpp -o programa`: define a versão da linguagem C++ usada na compilação.
- `g++ -Wall -Wextra arquivo.cpp -o programa`: ativa avisos úteis para encontrar problemas no código.
- `g++ -g arquivo.cpp -o programa`: adiciona informações de depuração para usar no debugger.
- `g++ -c arquivo.cpp`: compila apenas até o arquivo objeto, sem gerar o executável final.
- `g++ -S arquivo.cpp`: gera o código em assembly.
- `g++ -E arquivo.cpp`: mostra o resultado do pré-processamento.

### Comando recomendado para este repositório

O padrão usado neste repositório é:

```bash
g++ -std=c++17 -Wall -Wextra -g arquivo.cpp -o programa
```

Esse comando já deixa a compilação mais segura para estudos, facilita a identificação de erros e prepara o programa para depuração no VS Code.

## Próximos passos

Quando uma nova aula começar, basta criar uma nova pasta dentro de `aulas/` e adicionar os arquivos correspondentes.