# Relatório – AC07: Lista Circular Duplamente Encadeada com Nó Cabeça

**Aluno:** Carlos André Guedes de Almeida
**Matrícula:** 604053
**Disciplina:** QXD0010 – Estruturas de Dados
**Professor:** Atílio Gomes Luiz

## O que foi feito

Nesta atividade implementei o TAD Lista Linear em C++ usando como base uma lista circular duplamente encadeada com nó cabeça. A ideia foi aproveitar o que a lista dupla tem de melhor: como cada nó conhece o anterior e o próximo, dá para andar nos dois sentidos e remover um elemento sem ter que procurar quem vem antes dele. O fato de ser circular também ajuda bastante, porque o último elemento fica sempre a um passo do primeiro (é só olhar o `prev` dele), então inserir e remover no final não exige percorrer a lista inteira.

O código ficou dividido assim:

- `Node.h`: a `struct Node`, com o valor e os ponteiros `prev` e `next`.
- `List.h`: a declaração da classe `List`, com os atributos privados (`head` e `length`) e todas as operações pedidas.
- `list.cpp`: a implementação de cada função de `List.h`.
- `main.cpp`: o programa que conversa com o usuário pelo terminal.

Sobre a estrutura em si: o nó cabeça (`head`) é um nó sentinela que nunca guarda valor útil e só serve de ponto de entrada da lista. O `head->next` aponta para o primeiro elemento, e os elementos formam um anel entre eles (o último aponta para o primeiro e o primeiro aponta de volta para o último). Também guardo o tamanho em `length`, para que `size()` e `empty()` respondam na hora, sem precisar contar nó por nó.

Além das operações pedidas no enunciado, precisei criar duas coisas a mais:

- **Construtor de cópia** (`List(const List& lst)`): como o `main` guarda as listas dentro de um `vector`, elas são copiadas toda vez que o vector cresce. Sem um construtor de cópia próprio, duas listas acabariam apontando para os mesmos nós e o programa daria erro ao liberar a memória duas vezes.
- **`removeNode(Node* node)`** (privada): uma função interna que desliga um nó da lista e libera a memória dele. Ela é usada por `pop_back`, `remove` e `removeAll`, assim a lógica de "religar os vizinhos" ficou escrita em um lugar só.

Toda memória alocada com `new` é liberada com `delete`, seja nas remoções, no `clear()` ou no destrutor. Testei o programa com o valgrind e não apareceu nenhum vazamento.

## Como compilar e executar

Dentro da pasta da atividade:

```bash
g++ -std=c++17 -Wall -Wextra -g main.cpp -o output/main
./output/main
```

Depois é só digitar os comandos, um por linha. Também dá para deixar os comandos em um arquivo e redirecionar a entrada (`./output/main < entrada.txt`).

## Comandos disponíveis

O programa segue o mesmo estilo das atividades do Moodle: existe um `vector` de listas, cada lista é identificada pelo seu índice (a primeira criada é a lista `0`, a segunda é a `1`, e assim por diante) e cada comando digitado é repetido na tela com um `$` na frente antes de mostrar o resultado.

| Comando | O que faz | Operação testada |
| --- | --- | --- |
| `create` | Cria uma nova lista vazia no final do vector. | `List()` |
| `clone l` | Cria uma nova lista que é cópia da lista `l`. | `operator=` |
| `assign l1 l2` | Faz a lista `l1` receber uma cópia da lista `l2` (os elementos antigos de `l1` são descartados). | `operator=` |
| `pushback x l` | Insere o valor `x` no final da lista `l`. | `push_back` |
| `addBack l a1 a2 ... an` | Insere vários valores de uma vez no final da lista `l`, na ordem em que foram digitados. Ajuda bastante na hora de montar listas para teste. | `push_back` |
| `popback l` | Remove o último elemento da lista `l` e mostra o valor removido. | `pop_back` |
| `insertafter x k l` | Insere o valor `x` logo depois do `k`-ésimo nó da lista `l`. Os nós são contados a partir de 1; usando `k = 0` o valor entra no início da lista (logo após o nó cabeça). | `insertAfter` |
| `remove x l` | Remove a primeira ocorrência de `x` na lista `l`. Se `x` não existir, nada acontece. | `remove` |
| `removeall x l` | Remove todas as ocorrências de `x` na lista `l`. | `removeAll` |
| `concat l1 l2` | Junta a lista `l2` no final da lista `l1`. Depois disso a lista `l2` fica vazia, sobrando só o nó cabeça. | `concat` |
| `clear l` | Apaga todos os elementos da lista `l`. | `clear` |
| `size l` | Mostra quantos elementos a lista `l` tem. | `size` |
| `empty l` | Diz se a lista `l` está vazia ou não. | `empty` |
| `print l` | Mostra os elementos da lista `l` em ordem. | `print` |
| `printreverse l` | Mostra os elementos da lista `l` de trás para frente. | `printReverse` |
| `equals l1 l2` | Diz se as listas `l1` e `l2` são iguais (mesmo tamanho e mesmos valores nas mesmas posições). | `operator==` |
| `different l1 l2` | Diz se as listas `l1` e `l2` são diferentes. | `operator!=` |
| `show` | Mostra todas as listas criadas até o momento. | `print` |
| `help` | Lista rapidamente todos os comandos. | – |
| `exit` | Encerra o programa (as listas são destruídas e a memória é liberada). | `~List()` |

Quando algo dá errado, o programa avisa e continua rodando em vez de travar:

- usar o índice de uma lista que não existe mostra `lista inexistente`;
- dar `popback` em uma lista vazia ou usar um `k` inválido no `insertafter` mostra uma mensagem de erro explicando o problema;
- digitar um comando que não existe mostra `comando inexistente`.

## Exemplo de uso

Entrada:

```text
create
addBack 0 1 2 3 2 4
insertafter 10 2 0
print 0
printreverse 0
removeall 2 0
print 0
popback 0
create
addBack 1 7 8
concat 0 1
show
clone 0
equals 0 2
exit
```

Saída:

```text
$create
$addBack 0 1 2 3 2 4
$insertafter 10 2 0
$print 0
lista 0: [ 1 2 10 3 2 4 ]
$printreverse 0
lista 0 (reversa): [ 4 2 3 10 2 1 ]
$removeall 2 0
$print 0
lista 0: [ 1 10 3 4 ]
$popback 0
popback: 4
$create
$addBack 1 7 8
$concat 0 1
$show
lista 0: [ 1 10 3 7 8 ]
lista 1: [ ]
$clone 0
$equals 0 2
listas iguais
$exit
```

## Dificuldades e observações

A parte que mais deu trabalho foi cuidar dos casos de borda. Com a lista vazia, com um elemento só ou com dois elementos os ponteiros se comportam de um jeito um pouco diferente, e foi justamente aí que apareceram os primeiros bugs (por exemplo, um `remove` que ficava preso em loop porque o ponteiro não avançava, e um `pop_back` que quebrava o anel quando a lista tinha dois elementos). Separar esses casos com comentários (`CASE 01`, `CASE 02`, `DEFAULT`) ajudou muito a enxergar o que cada trecho estava tratando.

Outro ponto que exigiu atenção foi percorrer a lista. Como ela é circular, não existe um `nullptr` no final para indicar onde parar, então em algumas funções o percurso termina quando volta ao primeiro elemento e em outras ele anda exatamente `length` vezes. No `removeAll` isso foi essencial, porque o nó atual pode ser apagado no meio do caminho e o próximo precisa ser guardado antes do `delete`.

Por fim, o `concat` foi feito religando os ponteiros das pontas das duas listas, sem copiar nenhum nó. Assim a operação não depende do tamanho das listas, e a lista passada como parâmetro fica vazia, como o enunciado pede.
