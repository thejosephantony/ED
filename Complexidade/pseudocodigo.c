algoritmo Atividade;
constante
  Max = 50;
variáveis
  Notas: vetor de reais[Max];
  Media: real;
  I, Quant: inteiros;
inicio
  Media = 0;            // 1

  para I = 0 até Max-1 faça               // 50
      leia(Notas[I]);                     // 1
      Media = Media + Notas[I];           // 1

  Media = Media / Max;                    // 1

  Quant = 0;                              // 1

  para I = 0 até Max-1 faça               // 50
      se (Notas[I] > Media) então         // 1
          Quant = Quant + 1;              // 1

  escreva(Quant);                         // 1
fim.

// 1 + 50*2 + 1 + 1 + 50*2 + 1= 200 + 4 = 204
// O(1) - constante
