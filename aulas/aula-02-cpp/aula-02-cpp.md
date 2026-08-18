# Aula 02 - Introdução em C++
Os namespaces serve para organizar variáveis e funções em 'caixas', rotulando um conjunto de dados para o direcionamento correto do fluxo de lógica no compilador.

### Básico de como o C++ compila os arquivos
O C++ faz sempre a compilação dos arquivos necesssários para a extensão .o, transformando todo o código em objetos os quais vão ser linkados pelo *Linker*. É o Linker que vai verificar se todas as funções e variáveis realmente existem em todo código que vai ser compilado.

### Utilidade do namespace
Namespaces servem para organizar funções e variáveis dentro de um escopo, possibilitando uma melhor organização de código e repetição de assinaturas.

Exemplo:
- Utilizando o *namespace std* para abreviar o 'cout' e 'endl' pertecentes ao stdlib:
```cpp
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0
}
```

### Como o include funciona
Ele importa todo o código incluído para dentro do main.o, permitindo o linker verificar o que vai ser usado e se vai ser usado.
Importante lembrar que os arquivos *.cpp incluído no código principal também deve ser declarado na hora da compilação.

### Estruturas de seleção
- if-else;
- switch;
- operador ternário;

### Estrutura de repetição
- while
- do-while
- for

### Como strings funcionam
É sempre um vetor que guarda bytes que termina sempre com a última casa indexada com o valor '/0';