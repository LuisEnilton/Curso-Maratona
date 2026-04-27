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

Ponteiros são variáveis que guardam o endereço de memória de outras variáveis .

Cada variável declarada no programa tem uma localização na memória associada a ela que chamamos de endereço.

Para acessar o endereço de uma variável usamos '&'.

```cpp
int x = 2;

cout << &x << endl;

```


---

# Lista ligada

<v-clicks>

Listas ligadas são estruturas de dados em que cada elemento tem um ponteiro apontando para o próximo elemento da lista

Ao contrário do array os elementos não estão em posições contiguas de memória, por isso não conseguimos acessar um indice i arbitrário.

Por outro lado é extremamente fácil remover elementos, já que precisamos apenas retirar a referência aquela posição

[Visualização](https://visualgo.net/en/list)

</v-clicks>

---

# STL

<v-clicks>

Significa "Standard Template Library" (Biblioteca de modelos padrão).

É uma biblioteca em que já estão implementados estruturas de dados, funções e algoritmos que são essenciais para a maratona.

Essas funcionalidades são implementadas da forma genérica possível para serem de propósito geral.

Para usa-la precisamos apenas incluir o header " <bits/stdc++.h>".

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

Em C++, no geral temos 3 tipos de containers:

- Sequenciais.

- Associativos.

- Associativos não ordenados.

</v-clicks>
---

# Iteradores

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
---

# Por que usar Iteradores

<v-clicks>

Alguém pode estar pensando "Ué, mas eu já itero só com um for, porque eu preciso disso?".

A grande vantagem de iteradores é que permite iterar estrutura que não são sequenciais (Arrays) como árvores sem ter que modificar a forma que escreve o código.

Outra vantagem é que algoritmos da STL como `std::sort()` recebem iteradores como parâmetro.

</v-clicks>

---

# Pair

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
---

# Problema

Dado um array A não ordenado, imprima a posição original de cada elemento no array ordenado.

[Link Problema](https://codeforces.com/group/mzbGmMVMMp/contest/689521/problem/A)


---

# Por que estudar complexidade?

Nos problemas de maratona não nos importamos apenas se o algoritmo está correto, mas também com a velocidade que ele executa.

Essa motivação nos leva a estudar complexidade, que nos dá uma estimativa, com base na entrada do tempo que o algoritmo demora para rodar .

Motivos:
<v-clicks>

- Estimar o tempo de execução sem ter o código.

- Avaliar o pior caso para a solução proposta, em competições, os testes dos juizes são feitos para quebrar soluções ineficientes.

- Saber que estrutura de dados eu posso utilizar, sem estourar o limite de tempo.

</v-clicks>

---

# Notação Big O

O Big O ($O$) descreve como o número de operações do seu algoritmo cresce à medida que a entrada ($N$) aumenta.

## Definições

<v-clicks>

- **Não mede o tempo em segundos:** Segundos dependem do hardware, da linguagem e do compilador.
- **Mede a ordem de grandeza:** Se a entrada dobrar, o tempo dobra? Quadruplica?
- **Foca no Pior Caso:** Assumimos que o universo conspira contra nós. Se a busca pode ir até o final da lista, assumimos que ela vai até o final.
- **Ignora Constantes:** Para o Big O, $O(2N)$ e $O(50N)$ são apenas $O(N)$. O que importa é a curva de crescimento.

</v-clicks>
---

# Aplicação na Maratona

Via de regra, em competições usando C++, em 1 segundo o computador processa **$10^8$ operações.

Em cada problema é definido o tempo limite máximo e as restrições para o tamanho da entrada.

<img src="/TabelaComplexidade.png" class="w-2/5 mx-auto rounded-lg shadow-lg border border-gray-300" />
---

# Analisando código
 
## Loops aninhados

<v-clicks>

```cpp
int cnt = 0;
for(int i = 1; i <=n;i++){
  for(int j = 1;j <=m;j++){
    cnt++;
  }
}

```

- Em loops aninhados em cada voltar do loop exterior, você roda o loop interior completo, então você multiplica a complexidade dos dois.
- O(N * M)

</v-clicks>

---

# Analisando código

## Loops separados

<v-clicks>

```cpp
int cnt = 0;
for(int i = 1; i <=n;i++){
  
}

for(int j = 1;j <=m;j++){
    cnt++;
  }

```

- Em loops Separados, calculamos a complexidade separadamente e depois somamos.
- O(N + M)

</v-clicks>

---

# Exercicio Motivador

## Divisores de um número

<v-clicks>

Dado um numero N, encontre todos os divisores dele.

Restrições: N <= $10^9$.

Tempo limite: 1 segundo.
</v-clicks>

---

# Primeira Abordagem
Podemos iterar por todos os numeros <= a N e testar se ele divide N.

```cpp
vector<int> divisores;
for(int i = 1; i <=n;i++){
  if((n % i) == 0) divisores.push_back(i);
}

```

<v-clicks>

Qual a complexidade desse código?

$O(N)$

Efetuariamos $10^9$ operações o que é muito lento.

</v-clicks>

---

# Segunda abordagem

É impossivel que um numero maior do que a metade divida N, logo só precisamos testar até N/2

```cpp
for(int i = 1; i <=n/2;i++){
  if((n % i) == 0) divisores.push_back(i);
}
```
<v-clicks>

Qual a complexidade desse código?

$O(N/2)$ = $O(N)$ 

Efetuariamos $5 * 10^8$ operações o que ainda é muito lento.

</v-clicks>

---

# Observação

Todo número N tem uma quantidade finita de divisores, mas eles não estão distribuidos de forma aleatória.

Eles se organizam em pares ao redor do ponto central: $\sqrt{N}$.


<v-clicks>

$$d \times \left(\frac{N}{d}\right) = N$$

Se $d$ é um divisor, $\frac{N}{d}$ também é. Um "espelha" o outro.

Prova por contradição: Existir dois divisores a e b de N (a/N = b) tal que a > $\sqrt{N}$ e b > $\sqrt{N}$ $\Rightarrow$ $a * b > N$ , o que é uma contradição.

</v-clicks>

---
layout: two-cols
class: text-center
transition: slide-up
---

# Divisores de $N=36$
## Espelho em $\sqrt{36} = 6$

<div class="text-lg space-y-2 font-mono w-full px-4 mt-2">
  
  <span v-click class="block border border-opacity-20 py-0.5 rounded bg-opacity-10 bg-gray-500">Iteração $i=1$</span>
  
  <span v-click class="block border border-opacity-20 py-0.5 rounded bg-opacity-10 bg-gray-500">Iteração $i=2$</span>
  
  <span v-click class="block border border-opacity-20 py-0.5 rounded bg-opacity-10 bg-gray-500">Iteração $i=3$</span>
  
  <span v-click class="block border border-opacity-20 py-0.5 rounded bg-opacity-10 bg-gray-500">Iteração $i=4$</span>
  
  <span v-click class="block border border-opacity-20 py-0.5 rounded bg-opacity-10 bg-gray-500 leading-tight">Iteração $i=5$ <span class="text-red-400 text-xs block">Não divide (pula)</span></span>
  
  <span v-click class="block border border-primary py-0.5 rounded bg-opacity-20 bg-primary font-bold">Iteração $i=6 = \sqrt{36}$</span>

</div>

::right::

<div class="flex flex-col items-center h-full mt-2">

<h3 class="mb-4 text-sm opacity-80 uppercase tracking-widest">Pares Encontrados</h3>

<div class="grid grid-cols-2 gap-x-10 gap-y-2 font-bold text-3xl w-fit mx-auto">
  
  <div v-click="1" class="text-right text-green-300">1</div>
  <div v-click="1" class="text-left text-green-300">36</div>

  <div v-click="2" class="text-right text-cyan-300">2</div>
  <div v-click="2" class="text-left text-cyan-300">18</div>

  <div v-click="3" class="text-right text-purple-300">3</div>
  <div v-click="3" class="text-left text-purple-300">12</div>

  <div v-click="4" class="text-right text-amber-300">4</div>
  <div v-click="4" class="text-left text-amber-300">9</div>

  <div v-click="6" class="text-right text-blue-300">6</div>
  <div v-click="6" class="text-left text-blue-300">6</div>

</div>

<div v-click="7" class="mt-4 w-full pt-3 border-t border-dashed border-opacity-30 border-gray-400 text-center text-sm">
  <p class="font-bold text-green-400">Iterações: 6 (vs 36)</p>
  <p class="text-xs opacity-60 mt-1">Após a raiz, os pares apenas se repetem de trás pra frente.</p>
</div>

</div>

---

# Terceira abordagem

Com base na observação anterior, só precisamos testar os numeros até $\sqrt{N}$

```cpp
for(int i = 1; i * i <=n;i++){
  if((n % i) == 0) {
    divisores.push_back(i);
    if(i != n/i) divisores.push_back(n/i);
    // precisamos tratar o caso da raiz quadrada pra não ficar duplicado
  }
}
```
<v-clicks>

Qual a complexidade desse código?

$O(\sqrt{N})$

Efetuariamos $31 * 10^4$ operações o que passa com bastante folga no tempo limite.

</v-clicks>

---

# Problema

Responda Q consultas no formato "O numero N é Primo?", se o numero N for primo imprima "YES", caso contrário imprima "NO".

Q <= ${10^2}$

N <= $10^{10}$

[Link do Problema](https://codeforces.com/group/mzbGmMVMMp/contest/683347/problem/L)

---

# Solução

```cpp
bool eh_primo = true;
for(int i = 1; i * i <=n;i++){
  if((n % i) == 0) {
    eh_primo = false;
  }
}
```
---

# Hora do Quiz

Peguem o link do quiz no chat.

---

# Referências

- [Documentação C++](https://cplusplus.com/)
- [Livro Entendendo algoritmos](https://www.amazon.com.br/Entendendo-Algoritmos-Ilustrado-Programadores-Curiosos/dp/8575225634)
- [Aula UFMG](https://www.youtube.com/watch?v=cu3kKbkEZSw&list=PLU2KWF7n4KZzvYwAk7h2LAx4Td0kadh-T)
- [Série Harmônica](https://pt.wikipedia.org/wiki/S%C3%A9rie_harm%C3%B3nica_(matem%C3%A1tica))

---
src: ./pages/contatos.md
---

---
layout: end
---
# Obrigado por acompanhar a aula

 Por favor preencha o [formulário](https://forms.gle/fCRnxoAuGDCpTsBy5) de feedback com sugestões e críticas para a próxima aula 🙃.

<QRCode url="https://forms.gle/fCRnxoAuGDCpTsBy5" :size="150" />
