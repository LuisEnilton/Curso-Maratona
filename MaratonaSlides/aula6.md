---
# try also 'default' to start simple
theme: dracula

title: Algoritmos Gulosos e Two pointers
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

# Algoritmos Gulosos e Two pointers

<!--
The last comment block of each slide will be treated as slide notes. It will be visible and editable in Presenter Mode along with the slide. [Read more in the docs](https://sli.dev/guide/syntax.html#notes)
-->

---
layout: capa-aula
numero_aula: 6
---

---
layout: two-cols
layoutClass: gap-16
---

# Sumário da Aula

<Toc text-sm minDepth="1" maxDepth="2" columns=2  />
---

# Definição de Algoritmo Guloso

<v-clicks>

- Um algoritmo guloso constrói uma solução para **problemas de escolha** sempre fazendo a
escolha que parece ser a melhor no momento.

- Problemas de escolha são aqueles em que nosso objetivo é selecionar a melhor opção dentro de um conjunto de alternativas.

- Um algoritmo guloso nunca volta atrás em suas escolhas, mas constrói diretamente a solução final. Por esta razão, os algoritmos gulosos são geralmente muito eficientes.

- A ideia geral é que definimos um critério para a escolha de um item em detritemento de outro, após isso vamos selecionando os itens mais adequados até onde der. Por exemplo, se definirmos que o critério é o menor valor, pegaremos os itens de menor valor até o limite definido pelo problema.


</v-clicks>

---

# Problema Motivador

<v-clicks>


Steph quer melhorar seu conhecimento em algoritmos durante as férias de inverno. Ela tem um total de X ($1≤X≤10^4$) minutos para dedicar ao aprendizado de algoritmos. Existem N ($1≤N≤100$) algoritmos, e cada um deles requer ai ($1≤ai≤100$) minutos para ser aprendido. Encontre o número máximo de algoritmos que ela pode aprender.


[Link](https://codeforces.com/group/mzbGmMVMMp/contest/694969/problem/A)

Ao resolver um problema de forma gulosa geralmente recorremos a intuição, por exemplo, se queremos o numero máximo de algoritmos faz sentido estudar os algoritmos que gastam menos tempo, sobrando mais tempo para estudar outras coisas.

Para resolver esse problema, ordenamos os algoritmos em ordem crescente de tempo e vamos pegar sempre o menor possível.

</v-clicks>

---

# Selecionando Intervalos

<v-clicks>

Dado um N intervalos numéricos na forma $[l_i,r_i]$ , qual a quantidade máxima de intervalos que conseguimos pegar sem que haja intersecção?

Esse é um classico problema de algoritmos gulosos, em que a solução é um pouco menos intuitiva.

[Link](https://codeforces.com/group/mzbGmMVMMp/contest/694969/problem/D)

## Abordagem 1

De cara, podemos pensar em pegar sempre os menores intervalos pra sobrar mais espaços para outros intervalos, porém podemos pensar no seguinte contra-exemplo.

N = 3

$[1 , 5]$

$[4 , 6]$

$[5 , 10]$

Se pegassemos os dois maiores intervalos não haveria intersecção e teriamos a melhor resposta (2).

</v-clicks>

---

# Selecionando Intervalos

<v-clicks>

## Abordagem 2

A segunda abordagem que podemos pensar é pegar sempre o intervalo que começa primeiro, porém podemos pensar no seguinte contraexemplo.

N = 3

$[1 , 7]$

$[2 , 3]$

$[4 , 5]$

## Abordagem 3

A terceira abordagem consiste em pegar o intervalo que termina primeiro e ela sempre produz a solução ótima. Uma forma de intuir porque funciona é pensar que ao pegar a que termina primeiro, nós maximizamos a quantidade de intervalos restantes, por terminar primeiro ela cria conflitos com poucos intervalos.

</v-clicks>

---

# Solução

<v-clicks>

Podemos definir de forma customizada como vamos ordenar nosso array.

```cpp
  int n;
  cin >> n;
  vector<pair<int, int>> filmes(n); // ler o [inicio,fim] de cada fim
  for (auto &[l, r] : filmes)
      cin >> l >> r;
  // função que define como comparamos dois pares de forma customizada
  // essa função retorna a condição para que a venha primeiro que b
  auto cmp = [&](pair<int, int> &a, pair<int, int> &b)
  {
      return a.second < b.second;
  };
  sort(filmes.begin(), filmes.end(), cmp); // ordena pelo tempo de fim
  int anterior = 0, resposta = 0; // onde o filme anterior terminou
  for (auto [l, r] : filmes)
  {
      if (l < anterior)
          continue; // n da de pegar esse cara pq intersecta
      resposta++;
      anterior = r;
  }
  cout << resposta << endl;
```

</v-clicks>
---

# Tarefas e Prazos

<v-clicks>

Você tem que processar $n$ tarefas. Cada tarefa tem uma duração e um prazo, e você processará as tarefas em alguma ordem, uma após a outra. Sua recompensa por uma tarefa é $p-d$, onde $p$ é o seu prazo e $t$ é o seu tempo de término. (O tempo de início é $0$, e você tem que processar todas as tarefas mesmo que uma tarefa renda uma recompensa negativa.)

Qual é a sua recompensa máxima se você agir de forma ótima?

[Problema](https://codeforces.com/group/mzbGmMVMMp/contest/694969/problem/E)

Ao procurar uma solução gulosa em um problema, geralmente chutamos algo e analisamos se funciona, nesse caso poderiamos chutar "Pegar a tarefa que tem o prazo mais apertado funciona? E pegar a tarefa com o menor tempo de termino? E com o maior tempo de término?".

O problema é que ficar chutando soluções não é tão prático, vamos tentar achar a solução gulosa com um método mais analítico

OBS: As vezes não sai nada e a gente tem que sair chutando e vendo se passa ;)

</v-clicks>

---

# Modelando o problema

<v-clicks>

Então queremos definir uma ordem para processar as tarefas e a expressão da resposta final é expressa por:

$\sum_{1}^{n} {p_i - t_i}$

- $p_i$ é o prazo da tarefa $i$ e $t_i$ é o tempo de término.

Podemos separar esse somatório em dois:

$\sum_{1}^{n} {p_i}$ - $\sum_{1}^{n} {t_i}$

Perceba que independente da ordem que escolhermos o prazo da tarefa será somado na resposta final, o que muda é o valor do segundo somatório, queremos minimiza-lo.

Para um item escolhido $i$ o valor de $t_i$ é a soma de acumulada da duração de todas as tarefas até agora.

Então, a duração primeiro item será somada N - 1 vezes, a duração do segundo item será somada N-2 vezes, logo, queremos que os itens com menor duração sejam resolvidos primeiro.


</v-clicks>

---

# Subarray de Soma Máxima

<v-clicks>

Dado um array A formado por N elementos, queremos encontrar o subarray que tem soma máxima entre todos os subarrays.

[Problema](https://codeforces.com/group/mzbGmMVMMp/contest/694969/problem/C)

**Definição de subarray:**  Qualquer porção contínua de um array, ele é formado por elementos vizinhos extraidos do array original, podemos também pensar que é um corte do array.

## Força Bruta

A primeira abordagem que podemos pensar é testar todos os subarray com dois loops aninhados e verificar qual tem a maior soma, a complexidade disso é $O(N^2)$

```cpp
  // testa os subarrays começando na posição i
  for(int i = 0; i < n;i++){
    int soma = 0;
    for(int j = i;j < n;i++){
      soma += a[j];
      resposta = max(resposta,soma);
    }
  }
```

</v-clicks>

---


# Algoritmo de Kadane

<v-clicks>

Existe uma solução com complexidade O(N) proposta por Joseph Kadane, é ideia consiste em calcular para cada posição o maior subarray terminando nela, a resposta final será a maior resposta de cada posição.

O maior subarray terminando numa posição $i$, é o máximo entre duas opções:

1 - Extender o maximo do subarray terminando na posição $i$ - 1 , somando $a[i]$.

2 - Começar um novo subarray com valor $a[i]$.

```cpp
  // testa os subarrays começando na posição i
  vector<int> maior_sub(n); // maior subarray terminando em i
  maior_sub[0] = a[0];
  int resposta = maior_sub[0];
  for(int i = 1; i < n;i++){
    int extender = maior_sub[i - 1] + a[i];
    int comecar_dnv = a[i];
    maior_sub[i] = max(extender,comecar_dnv);
    resposta = max(resposta,maior_sub[i]);
  }
```

Bônus: Como resolver apenas com soma de prefixo em O(N)? como resolver se o tamanho do subarray tem ser >= K?

</v-clicks>

---

# Problemas em que o Guloso falha

<v-clicks>

Dado o conjunto de moedas $[1,3,4]$ , qual é o numero minimo de moedas que temos que usar para construir um valor S , dado que cada moeda pode ser usada quantas vezes quisermos.

Esse é um problema conhecido e em muitos casos existe uma solução gulosa que consiste em pegar a maior moeda que não passa do valor S atual.

Porém, o que acontece se tentarmos construir o valor $6$ com esse algoritmo guloso, pegariamos $[4,1,1]$. Entretanto a resposta ótima é $[3,3]$. Esse problema não tem soluçao gulosa conhecida e é resolvido com programaçao dinâmica.

</v-clicks>

---

# Two Pointers

<v-clicks>

Two pointers é uma técnica para resolução de problemas em que usamos duas variáveis índices para percorrer um array, a restrição é que cada ponteiro só pode ser mover para uma direção, em alguns materiais eles são chamados de monotônicos.

Pelo fato dos ponteiros só se moverem em uma direção é complexidade do algoritmo é $O(N)$

## Exemplo

Dado dois arrays ordenados $a$ e $b$ , combine os em um array grande $c$ também ordenado. A abordagem ingênua é juntar os dois arrays e chamar a função sort() , a complexidade disso é $O(NlogN)$ queremos uma solução $O(N)$ . 


Essa é a ideia é usada para combinar no merge sort.

</v-clicks>

---

# Solução

<v-clicks>

Para resolver o problema a ideia é criar dois ponteiros, um para marcar o menor elemento no array $a$ e outro para marcar o menor elemento em $b$, em cada passo nós pegamos o menor entre as duas posições e andamos com o ponteiro correspondente.

```cpp
  vector<int> combinar(vector<int> & a , vector<int & b){
    int i = 0 , j = 0 , n = a.size() , m = b.size();
    vector<int> c;
    while(i < n && j < m){
      if(a[i] < b[j]){
        c.push_back(a[i++]);
      }else{
        c.push_back(b[j++]);
      }
    }
    while(i < n) c.push_back(a[i++]); // se faltou colocar algum elemento de a
    while(j < m) c.push_back(b[j++]); // se faltou colocar algum elemento de b
  }
```

</v-clicks>

---

# Problema clássico

<v-clicks>

Dado um array de $n$ números inteiros, sua tarefa é calcular o número de subarrays que têm no máximo $k$ valores distintos.

[Problema](https://codeforces.com/group/mzbGmMVMMp/contest/694969/problem/F)

A ideia aqui é que podemos calcular a resposta para cada $r$, mais especificamente, terminando na posição $r$ qual o indice mais a esquerda $l$ em que o subarray tem <= K valores distintos.

Mas como isso ajuda a calcular a quantidade de subarrays? Perceba, que qualquer subarray terminando em $r$ que comece depois de $l$ vai satisfazer a condição. Então a quantidade subarrays que tem no máximo $k$ valores distintos e termina em $r$ é igual a $(r - l + 1)$.

Podemos usar essa técnica para calcular o maior subarray com no máximo k valores distintos.

</v-clicks>

---

# Solução

<v-clicks>

## Algoritmo

 - Vamos ter um mapa guardando a frequencia de cada cara no subarray e um contador de valores distintos
 - Quando a frequencia de alguem sai de 0 para 1 temos um novo valor distinto
 - Quando a frequencia sai de 1 para 0 temos um valor distinto a menos.
 - Para cada r, adicionamos o valor de a[r] no mapa, e for um novo valor distinto somamos 1 no contado
 - Enquanto tiver mais que k valores distintos, anda com o ponteiro $l$ para frente (perceba que estamos removendo valores), ao final teremos a posição $l$ para cada $r$


```cpp
  unordered_map<int,int> freq; // contar a frequencia de cada numero
  int cnt = 0; // quantos elementos distintos eu tenho
  int l = 0; // ponteiro que vai marcar o l de cada r
  for(int r = 0; r < n;r++){
    freq[a[r]]++; // aumenta a frequencia do cara que chegou agora
    if(freq[a[r]] == 1) cnt++;// se a frequencia virou 1, quer dizer que é a primeira aparição, temos um novo valor distinto
    // aumentamos o l enquanto a condição não estiver satisfeita
    while(l < r && cnt > k ){
      freq[a[l]]--;
      if(freq[a[l]] == 0) cnt--;
      l++;
    }
  }
```

</v-clicks>

---

# Generalizando o algoritmo

<v-clicks>

Podemos generalizar esse problema para outras condições, a restrição é que se pra um dado $r$ a posição $l$ é a mais esquerda em que a condição é verdade, qualquer indice $i$ (l <= i <= r) também atende a condição. Outra forma de dizer é que a função que determina o valor de uma posição $r$ é monotônica em relação a $l$.

Exemplos de condição: Subarray com soma <= K, subarray com o minimo >= K, subarray em que a diferença entre o maior e o menor elemento é no máximo K.

[Lista](https://codeforces.com/edu/course/2/lesson/9/2/practice)

## Perguntas

1 - Qual a quantidade de subarrays que um array tem?

2 - Como calcular a quantidade de subarrays em que a quantidade de elementos distintos é > K?

3 - Repetindo, como calcular o subarray com maior soma que tem tamanho >= K?

</v-clicks>

---


# Referências

- [Documentação C++](https://cplusplus.com/)
- [Curso Two pointers](https://codeforces.com/edu/course/2/lesson/9)
- [Algoritmo de Kadane NOIC](https://noic.com.br/materiais-informatica/curso/soma-max-em-intervalo/)
- [Competitive programming HandBook](https://github.com/natanlimaz/cphb_ptbr)
---
src: ./pages/contatos.md
---

---
layout: end
---
# Obrigado por acompanhar a aula

 Por favor preencha o [formulário](https://forms.gle/Y7rXjvKZybMibntR6) de feedback com sugestões e críticas para a próxima aula 🙃.

<QRCode url="https://forms.gle/Y7rXjvKZybMibntR6" :size="150" />
