---
# try also 'default' to start simple
theme: dracula

title: STL
info: |
  ## Slidev Starter Template
  Presentation slides for developers.

  Learn more at [Sli.dev](https://sli.dev)
# apply UnoCSS classes to the current slide
class: text-center
# https://sli.dev/features/drawing
drawings:
  persist: false
# slide transition: https://sli.dev/guide/animations.html#slide-transitions
transition: slide-left
# enable MDC Syntax: https://sli.dev/features/mdc
mdc: true
# duration of the presentation
duration: 35min
---

# STL

<!--
The last comment block of each slide will be treated as slide notes. It will be visible and editable in Presenter Mode along with the slide. [Read more in the docs](https://sli.dev/guide/syntax.html#notes)
-->

---
layout: capa-aula
numero_aula: 3
---

---
layout: two-cols
layoutClass: gap-16
---

# Sumário da Aula

<Toc text-sm minDepth="1" maxDepth="2" columns=2  />
---

# Ponteiros

<v-clicks>

Cada variável declarada no programa tem uma localização na memória associada a ela que chamamos de endereço.

Ponteiros são variáveis que guardam o endereço de memória de outras variáveis, eles são declarados colocando um '*' após o tipo.

Por exemplo "int*", indica que esse é um ponteiro que guarda um endereço de uma variável int.

Para acessar o endereço de uma variável usamos '&' e para acessar o valor da variável que o ponteiro está apontando usamos '*'.

Não utilizem ponteiros se não for necessário, é bem fácil criar bugs com eles.

```cpp
int x = 2;
cout << &x << endl; // vai printar um hexadecimal (endereço).

int* ptr = &x;

cout << *ptr << endl; // vai printar 2.

*ptr = 3; // tambem podemos alterar o valor da variavel com o ponteiro

```

</v-clicks>

---

# Observação

Qual a complexidade para apagar um elemento de um array?

---

# Lista ligada

<v-clicks>

Listas ligadas é uma estrutura de dados sequencial em que cada elemento tem um ponteiro apontando para o próximo elemento da lista.

Ao contrário do array os elementos não estão em posições contiguas de memória, por isso não conseguimos acessar um indice i arbitrário.

Por outro lado é extremamente fácil remover elementos, já que precisamos apenas retirar a referência aquela posição.

[Visualização](https://visualgo.net/en/list)

</v-clicks>

---

# STL

<v-clicks>

Significa "Standard Template Library" (Biblioteca de modelos padrão).

É uma biblioteca em que já estão implementados estruturas de dados, funções e algoritmos que são essenciais para a maratona.

Essas funcionalidades são implementadas da forma genérica possível para serem de propósito geral.

Para usa-la precisamos apenas incluir o header "<bits/stdc++.h>".

```cpp
#include <bits/stdc++.h>

using namespace std; // isso é necessário para não ter que escrever std:: toda vez que for usar.

```

</v-clicks>
---

# Containers

<v-clicks>

Containers são estruturas que guardam uma coleção de um tipo especifico, na STL os containers são criados de forma genérica permitindo que você define o seu tipo na criação.

Exemplo:

```cpp
vector<int> a; // ao criarmos o vector definimos o seu tipo com <TIPO>

pair<int,string> // Definimos os dois tipos do pair com <TIPO1,TIPO2>

```

Em C++, em geral temos 3 tipos de containers:

- Sequenciais.

- Associativos.

- Associativos não ordenados.

</v-clicks>
---

# Iteradores

<v-clicks>

Um iterador é um ponteiro que representa a posição de um elemento num container, é usado para iterar numa estrutura.

Existem tipos diferentes de iteradores, mais detalhes em [Iteradores](https://www.programiz.com/cpp-programming/iterators)

## Métodos padrões

- begin() , ponteiro para a primeira posição do container.

- end() , ponteiro para o final do container.

- ++, anda uma posição para frente.
````md magic-move {lines: true}
```cpp
vector<int> a;

vector<int>::iterator itr = a.begin();
vector<int>::iterator fin = a.end();

for(;itr != fin;itr++){
    // executa
    int val = *itr; // acessar o valor de itr;
}
```

```cpp
vector<int> a;
// na pratica utilizamos o auto para não ter que escreve muitas linhas de código
auto itr = a.begin();
auto fin = a.end();

for(;itr != fin;itr++){
    // executa
    int val = *itr; // acessar o valor de itr;
}
```

````

</v-clicks>

---

# Por que usar Iteradores

<v-clicks>

Alguém pode estar pensando "Ué, mas eu já itero só com um for, porque eu preciso disso?".

A grande vantagem de iteradores é que permite iterar estrutura que não são sequenciais (Arrays) como árvores sem ter que modificar a forma que escreve o código.

Outra vantagem é que algoritmos da STL como `std::sort()` recebem iteradores como parâmetro.

</v-clicks>

---

# Pair


<v-clicks>

Pair é uma estrutura que guarda dois elementos, os tipos desses elementos é definido na criação.


## Sintaxe

```cpp
pair<int,string> par;

// atribuição
par = {2,"Nome"};

cout << par.first << endl; // 2
cout << par.second << endl; // Nome

par.first = 3; // podemos modificar um elemento separadamente.
par.second = "Nome2";
```

Para comparar pair, primeiro o programa analisa o primeiro elemento, se os dois forem iguais compara o segundo.

```cpp
pair<int,int> a = {2,5};
pair<int,int> b = {3,4};
cout << (a < b) << endl; // true
a.first = 3;
cout << (a < b) << endl; // false
```


</v-clicks>

---

# Problema

Dado um array A não ordenado, imprima a posição original de cada elemento no array ordenado.

[Link Problema](https://codeforces.com/group/mzbGmMVMMp/contest/689521/problem/C)


---

# Pilha

<v-clicks>

Uma pilha é uma estrutura de dados abstrata que segue o princípio LIFO(Last In First Out), ou seja o ultimo elemento adicionado vai ser o primeiro a ser removido.

Uma forma de visualizar é pensar numa pilha de pratos uma em cima da outra, e você pode:

- Colocar um novo prato em cima.

- Retirar um prato.

Se você quiser pegar o prato que está na base, você terá que retirar todos os pratos.

## Aplicações básicas

- Inverter uma string (ou array).

- Botão de voltar do navegador.

</v-clicks>

---

# Pilha em C++
```cpp
stack<int> pilha; // voce definie o tipo com <TIPO>

pilha.push(2); // adiciona um elemento
pilha.push(3);
cout << pilha.top() << endl; // retorna o elemento no topo da pilha
cout << pilha.size() << endl;// retorna o tamanho atual da pilha
cout << pilha.empty() << endl; // retorna um booleano (se a pilha está vazia).
pilha.pop() // remove o elemento do topo.

```
---

# Questão clássica

Dada uma sequência de parênteses, determine se ela está balanceada. Ela está balanceada se cada parentêse aberto '(' tem um parêntese fechado correspondente ')'.

[Problema](https://codeforces.com/group/mzbGmMVMMp/contest/689521/problem/E)

---

# Fila

<v-clicks>

Uma fila é uma estrutura de dados abstrata que segue o princípio FIFO(First In First Out), ou seja o primeiro elemento adicionado vai ser o primeiro a ser removido.

É uma abstração muito utilizada para simular algoritmos e como base para algoritmos mais complexos.

Também é a base para algoritmos de busca em largura (falaremos sobre na aula de grafos).

</v-clicks>

---

# Fila em C++

```cpp
queue<int> fila; // voce definie o tipo com <TIPO>

fila.push(2); // adiciona um elemento
fila.push(3);
cout << pilha.front() << endl; // retorna o elemento na frente da fila
cout << pilha.size() << endl;// retorna o tamanho atual da fila
cout << pilha.empty() << endl; // retorna um booleano (se a fila está vazia).
pilha.pop() // remove o elemento do frente.

```

---

# Questão

[Questão](https://codeforces.com/group/mzbGmMVMMp/contest/689521/problem/F)


---

# Algoritmos


<v-clicks>

A STL também tem uma coleção de algoritmos úteis para resolução de problemas.

Os principais são:

- sort(), ordena um conjunto de elementos (vector ou array) em O(NlogN)

- reverse(), inverte um conjunto de elementos em O(N).

- swap(), troca o valor de duas variáveis em O(1).

- unique(), dado um array ordenado, ele deixa apenas valores únicos nele.

[Lista completa](https://cppreference.com/cpp/algorithm)

</v-clicks>

---

# Sort

Função que ordena um array de elementos, ela recebe um ponteiro pro inicio e um ponteiro pro final do array e ordena esse intervalo.

````md magic-move {lines: true}
```cpp
int n; cin >> n;
vector<int> a(n);
for(int i = 0 ; i < n;i++){
  cin >> a[i];
}
sort(a.begin(),a.end());
for(int x : a)cout << x << " ";
cout << endl; // 1 2 3 4 5

```
```cpp
int n; cin >> n;
int a[n];
for(int i = 0 ; i < n;i++){
  cin >> a[i];
}
sort(a,a + n);
for(int i = 0 ; i < n;i++) cout << a[i] << " ";
cout << endl;
```
````
---

# Reverse

Inverte o conteúdo de um vector.

```cpp
int n; cin >> n;
vector<int> a(n);
for(int i = 0 ; i < n;i++){
  cin >> a[i];
}
reverse(a.begin(),a.end()); // inverte o vector
```


---

# Swap

Troca o valor de duas variáveis em O(1).

```cpp
int a = 2, b = 3;
swap(a,b);
cout << a << " " << b << endl;

string s1 = "primeira", s2 = "segunda";
swap(s1,s2);

cout << s1 << " " << s2 << endl;

vector<int> v1 = {2,3,4} , v2 = {6,3};
swap(v1,v2); // troca os dois vetores.


```

---

# Unique

Dado um array ordenado, essa função move os elementos duplicados pro final, utilizamos o erase pra conseguir o array sem duplicatas.



```cpp
vector<int> a = {2, 3 , 1, 4 , 2 , 1};

// antes de usarmos a função temos que ordenar
sort(a.begin(),a.end()); // {1,1,2,2,3,4};

// a função retorna um ponteiro para o final dos elementos únicos
auto last = unique(a.begin(),a.end()); // {1,2,3,4,x,x}.
// agora precisamos apagar os elementos duplicados

a.erase(last,a.end());

for(int x : a){
  cout << x << " ";
}
cout << endl;
```

---

# Questão

Descobrir quantos valores únicos eu tenho num array.

[Problema](https://codeforces.com/group/mzbGmMVMMp/contest/689521/problem/B)

---

# Referências

- [Documentação C++](https://cplusplus.com/)
- [Programiz](https://www.programiz.com/cpp-programming/standard-template-library)
- [Livro CPH](https://cses.fi/book/book.pdf)
- [Aula UFMG](https://www.youtube.com/watch?v=beHruxE8D0M&list=PLU2KWF7n4KZzvYwAk7h2LAx4Td0kadh-T&index=3)

---
src: ./pages/contatos.md
---

---
layout: end
---
# Obrigado por acompanhar a aula

 Por favor preencha o [formulário](https://forms.gle/FKEfS8JL5UnaTfzM9) de feedback com sugestões e críticas para a próxima aula 🙃.

<QRCode url="https://forms.gle/FKEfS8JL5UnaTfzM9" :size="150" />
