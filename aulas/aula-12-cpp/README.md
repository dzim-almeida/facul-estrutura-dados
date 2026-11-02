# Listas encadeadas

Uma lista encadeada é uma estrutura de dados linear formada por nós. Cada nó armazena:

- um valor ou dado;
- um ponteiro para o próximo nó da lista.

Ao contrário de um vetor ou de um `std::vector`, os elementos de uma lista encadeada não precisam estar em posições consecutivas da memória. Os nós são alocados dinamicamente e ficam conectados por ponteiros. O primeiro nó é acessado por um ponteiro chamado normalmente de `head`, enquanto o último aponta para `nullptr`, indicando o fim da lista.

## Representação da estrutura

Uma lista simplesmente encadeada pode ser visualizada da seguinte forma:

```text
head
 ↓
[10 | •] -> [20 | •] -> [30 | nullptr]
```

O primeiro campo de cada nó representa o dado e o segundo representa o endereço do próximo nó. Para alcançar um elemento, é necessário começar em `head` e seguir os ponteiros um a um. Por isso, uma lista não oferece acesso direto por índice como um vetor.

## Estrutura de um nó em C++

Em C++, um nó pode ser representado por uma `struct`:

```cpp
struct Node {
    int value;
    Node* next;

    Node(int value) : value(value), next(nullptr) {}
};
```

O campo `next` armazena o endereço do próximo nó. Quando ele vale `nullptr`, significa que o nó atual é o último da lista.

Uma implementação mínima de lista pode manter apenas o ponteiro para o primeiro nó e a quantidade de elementos:

```cpp
class LinkedList {
private:
    Node* head = nullptr;
    int size = 0;

public:
    bool empty() const {
        return head == nullptr;
    }

    int getSize() const {
        return size;
    }
};
```

Manter o tamanho em uma variável evita percorrer toda a lista sempre que for necessário saber quantos elementos ela possui.

## Operações principais

As operações mais comuns são:

- **Percorrer:** começa em `head` e segue `next` até encontrar `nullptr`.
- **Buscar:** compara o valor de cada nó durante a percorrida.
- **Inserir no início:** cria um nó, faz seu `next` apontar para o antigo `head` e atualiza `head`.
- **Inserir no fim:** percorre a lista até o último nó e conecta o novo nó. Se a lista também mantiver um ponteiro `tail`, essa operação pode ser feita sem percorrer todos os elementos.
- **Remover do início:** guarda o antigo primeiro nó, move `head` para o próximo e libera a memória do nó removido.
- **Remover um elemento:** localiza o nó anterior, ajusta o ponteiro `next` e libera o nó retirado.

Por exemplo, a inserção no início pode ser implementada assim:

```cpp
void pushFront(int value) {
    Node* node = new Node(value);
    node->next = head;
    head = node;
    size++;
}
```

Como o nó é criado com `new`, ele precisa ser destruído com `delete` quando não for mais utilizado. Uma lista que não libera seus nós pode causar vazamento de memória.

```cpp
void popFront() {
    if (head == nullptr) {
        return;
    }

    Node* removed = head;
    head = head->next;
    delete removed;
    size--;
}
```

## Percorrendo e exibindo os elementos

```cpp
void print() const {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }

    std::cout << "\n";
}
```

O ponteiro `current` funciona como um cursor. Ele começa no primeiro nó e avança para o próximo até chegar ao fim. É importante não perder o endereço de `head`, pois ele é a referência de entrada para toda a lista.

## Complexidade das operações

Considerando uma lista simplesmente encadeada sem um ponteiro para o último nó:

| Operação | Complexidade |
| --- | --- |
| Acessar o elemento na posição `i` | `O(n)` |
| Buscar um valor | `O(n)` |
| Percorrer a lista | `O(n)` |
| Inserir no início | `O(1)` |
| Remover do início | `O(1)` |
| Inserir no fim | `O(n)` |
| Remover no fim | `O(n)` |

O acesso por posição é `O(n)` porque a lista precisa avançar nó por nó. Em um vetor, o acesso costuma ser `O(1)`, pois os elementos estão em posições contíguas e podem ser calculados diretamente pelo índice.

## Vantagens e limitações

As listas encadeadas são úteis quando há muitas inserções e remoções, principalmente no início ou em posições já localizadas. Elas não precisam reservar um bloco contínuo de memória e podem crescer conforme novos nós são criados.

Por outro lado, cada nó ocupa espaço adicional para armazenar ponteiros, o acesso é sequencial e a alocação dinâmica pode ser mais custosa. Se a aplicação precisa acessar frequentemente elementos por índice, um `std::vector` costuma ser uma escolha melhor.

| Estrutura | Acesso por índice | Inserção no início | Memória |
| --- | --- | --- | --- |
| `std::vector` | `O(1)` | `O(n)` | Bloco contíguo |
| Lista encadeada | `O(n)` | `O(1)` | Nós ligados por ponteiros |

## Tipos de listas encadeadas

- **Simplesmente encadeada:** cada nó aponta apenas para o próximo.
- **Duplamente encadeada:** cada nó possui ponteiros para o próximo e para o anterior, facilitando a navegação nos dois sentidos.
- **Circular:** o último nó aponta novamente para o primeiro, em vez de apontar para `nullptr`.

Em uma lista duplamente encadeada, é necessário atualizar mais ponteiros durante inserções e remoções. Em uma lista circular, a condição de parada não é encontrar `nullptr`; é necessário reconhecer quando o percurso voltou ao nó inicial.

## Cuidados na implementação

- Inicialize `head` com `nullptr`.
- Verifique a lista vazia antes de acessar um nó.
- Atualize os ponteiros na ordem correta para não perder o restante da lista.
- Use `delete` para cada nó criado com `new`.
- Ao remover o último nó, atualize `head` e, caso exista, `tail`.
- Evite acessar um ponteiro depois que o nó apontado foi liberado.
- Encapsule os nós dentro da classe e exponha operações seguras para quem utiliza a lista.

Uma implementação completa também deve possuir um destrutor que percorra os nós e libere toda a memória, além de considerar construtor de cópia e operador de atribuição caso a lista seja copiada. Essas regras são especialmente importantes em C++, pois a linguagem permite controlar diretamente a memória.
