// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Paulo Vitor de Oliveira Fonseca
//  email: pfonseca485@gmail.com
//  Matrícula: XXXXXXXXX
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>

/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y){
  int soma = 0;
  return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x){ //função utilizada para testes
  int fat = 1;
  return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */
int q1(char *data){
  char dd[3], mm[3], aaaa[5];
  int dia, mes, ano, tamDia = 0, tamMes = 0, tamAno = 0, aux, auxMes, auxAno, y;

  aux=0;
  while(data[aux] != '/'){
    dd[aux]=data[aux];
    aux++;
  }
  dd[aux]='\0';
  while(dd[tamDia] != '\0'){
    tamDia++;
  }

  auxMes=0;
  aux=tamDia+1;
  while(data[aux] != '/'){
    mm[auxMes] = data[aux];
    auxMes++;
    aux++;
  }
  mm[auxMes]='\0';
  while(mm[tamMes] != '\0'){ 
    tamMes++;
  }

  auxAno=0;
  y = tamMes + tamDia + 2;
  while(data[y] != '\0'){
    aaaa[auxAno] = data[y];
    auxAno++;
    y++;
  }
  aaaa[auxAno] = '\0';
  
  dia = atoi(dd);
  mes = atoi(mm);
  ano = atoi(aaaa);

  if((mes >= 1 && mes <= 12) && (dia >= 1 && dia <= 31) && (ano >= 10 && ano <= 9999)){
    if((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia >= 1 && dia <= 31)){
      return 1;
    }
    else if((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11) && (dia >= 1 && dia <= 30)){
      return 1;
    }
    else if(dia==29 && mes==2 && (ano%400==0 || (ano%4 == 0 && ano%100 != 0))){
      return 1;
    }
    else if(mes == 2 && (dia >= 1 && dia <= 28)){
      return 1;
    }
  else
    return 0;
  }
  else
    return 0;
}


/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    int nDias, nMeses, nAnos;
    char ddini[3], mmini[3], aaaaini[5], ddfim[3], mmfim[3], aaaafim[5] ;
    int diaini, mesini, anoini, diafim, mesfim, anofim, tamDia = 0, tamMes = 0, tamAno = 0, aux, auxMes, auxAno, y, correto;
    /*nDias = nDias;
    nMeses = nMeses;
    nAnos = nAnos;*/
  aux = 0;
  while(datainicial[aux] != '/'){
    ddini[aux] = datainicial[aux];
    aux++;
  }
  ddini[aux] = '\0';
  while(ddini[tamDia] != '\0'){
    tamDia++;
  }

  auxMes = 0;
  aux = tamDia + 1;
  while(datainicial[aux] != '/'){
    mmini[auxMes] = datainicial[aux];
    auxMes++;
    aux++;
  }
  mmini[auxMes] = '\0';
  while(mmini[tamMes] != '\0'){ 
    tamMes++;
  }

  auxAno = 0;
  y = tamMes + tamDia + 2;
  while(datainicial[y] != '\0'){
    aaaaini[auxAno] = datainicial[y];
    auxAno++;
    y++;
  }
  aaaaini[auxAno] = '\0';
  
  diaini = atoi(ddini);
  mesini = atoi(mmini);
  anoini = atoi(aaaaini);
  
  if(mesini <=0 || mesini >=13){
  return 2;
  }
  if(diaini <=0 || diaini >=32){
  return 3;
  }

  y = 0;
  tamDia = 0;
  tamMes = 0;
  tamAno = 0;
  
  aux = 0;
  while(datafinal[aux] != '/'){
    ddfim[aux] = datafinal[aux];
    aux++;
  }
  ddfim[aux] = '\0';
  while(ddfim[tamDia] != '\0'){
    tamDia++;
  }

  auxMes = 0;
  aux = tamDia + 1;
  while(datafinal[aux] != '/'){
    mmfim[auxMes] = datafinal[aux];
    auxMes++;
    aux++;
  }
  mmfim[auxMes] = '\0';
  while(mmfim[tamMes] != '\0'){ 
    tamMes++;
  }

  auxAno = 0;
  y = tamMes + tamDia + 2;
  while(datafinal[y] != '\0'){
    aaaafim[auxAno] = datafinal[y];
    auxAno++;
    y++;
  }
  aaaafim[auxAno] = '\0';
  
  diafim = atoi(ddfim);
  mesfim = atoi(mmfim);
  anofim = atoi(aaaafim);

  if(mesfim <=0 || mesfim >=13){
  return 2;
  }
  if(diafim <=0 || diafim >=32){
  return 3;
  }

 
  if((anoini > anofim) || (anoini == anofim && ((mesini > mesfim) ||  ((mesini == mesfim) && (diaini > diafim))))){
  return 4;
  }

    else{
    nAnos = anofim - anoini;
    if(mesfim >= mesini){
      nMeses = mesfim - mesini;
      if(diafim >= diaini){
        nDias = diafim - diaini;
      }
      else if(diafim < diaini){
        nDias = diaini - diafim;
        nMeses = nMeses -1;
        if(((anofim%400 == 0 || (anofim%4 == 0 && anofim%100 != 0)) && (anoini%400 == 0 || (anoini%4 == 0 && anoini%100 != 0))) || ((anofim%400==0 || (anofim%4 == 0 && anofim%100 != 0)) && (anoini%400!=0 || (anoini%4 != 0 && anoini%100 == 0)))){
          if((mesfim == 2) || (mesini == 2)){
            nDias = 29 - nDias;
          }
          else if(((mesfim == 4) || (mesfim== 6) || (mesfim == 9) || (mesfim == 11)) || ((mesini == 4) || (mesini == 6) || (mesini== 9) || (mesini== 11))){
            nDias = 30 - nDias;
          }
          else if((mesfim == 1 || mesfim == 3 || mesfim == 5 || mesfim == 7 || mesfim == 8 || mesfim == 10 || mesfim == 12) || (mesini == 1 || mesini == 3 || mesini == 5 || mesini == 7 || mesini == 8 || mesini == 10 || mesini== 12)){
            nDias = 31 - nDias;
          }
        }
        else{
          if((mesfim == 2) || (mesini == 2)){
            nDias = 28 - nDias;
          }
          else if(((mesfim == 4) || (mesfim == 6) || (mesfim == 9) || (mesfim == 11)) || ((mesini == 4) || (mesini == 6) || (mesini == 9) || (mesini == 11))){
            nDias = 30 - nDias;
          }
          else if((mesfim == 1 || mesfim == 3 || mesfim == 5 || mesfim == 7 || mesfim == 8 || mesfim == 10 || mesfim == 12) || (mesini == 1 || mesini == 3 || mesini == 5 || mesini == 7 || mesini == 8 || mesini == 10 || mesini == 12)){
            nDias = 31 - nDias;
          }
      }
    }
    else if(mesfim < mesini){
      nMeses = mesini - mesfim;
      nAnos = nAnos - 1;
      nMeses = 12 - nMeses;
      if(diafim >= diaini){
        nDias = diafim - diaini;
      }
      else if(diafim < diaini){
        nDias = diaini - diafim;
        nMeses = nMeses -1;
        if(((anofim%400==0 || (anofim%4 == 0 && anofim%100 != 0)) && (anoini%400==0 || (anoini%4 == 0 && anoini%100 != 0))) || ((anofim%400==0 || (anofim%4 == 0 && anofim%100 != 0)) && (anoini%400!=0 || (anoini%4 != 0 && anoini%100 == 0)))){
          if((mesfim==2) || (mesini==2)){
            nDias = 29 - nDias;
          }
          else if((((mesfim == 4) || (mesfim == 6) || (mesfim == 9) || mesfim == 11)) || ((mesini== 4) || (mesini == 6) || (mesini == 9) || (mesini == 11))){
            nDias = 30 - nDias;
          }
          else if((mesfim == 1 || mesfim == 3 || mesfim == 5 || mesfim == 7 || mesfim == 8 || mesfim == 10 || mesfim == 12) || (mesini == 1 || mesini == 3 || mesini == 5 || mesini == 7 || mesini == 8 || mesini == 10 || mesini == 12)){
            nDias = 31 - nDias;
          }
        }
        else{
          if((mesfim == 2) || (mesini == 2)){
            nDias = 28 - nDias;
          }
          else if(((mesfim == 4) || (mesfim == 6) || (mesfim == 9) || (mesfim == 11)) || ((mesini == 4) || (mesini == 6) || (mesini == 9) || (mesini == 11))){
            nDias = 30 - nDias;
          }
          else if((mesfim == 1 || mesfim == 3 || mesfim == 5 || mesfim== 7 || mesfim == 8 || mesfim == 10 || mesfim == 12) || (mesini == 1 || mesini == 3 || mesini == 5 || mesini == 7 || mesini == 8 || mesini == 10 || mesini == 12)){
            nDias = 31 - nDias;
          }
        }
    }
    }
  } 
    correto = 1;
  } 

  if(correto == 1){
    *qtdDias = nDias;
    *qtdMeses = nMeses;
    *qtdAnos = nAnos;
    return 1;
  } 
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferências entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferências entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
  int tamTexto = 0, qntOcorrencias = 0;
  	
  if(isCaseSensitive == 1){
  while(texto[tamTexto]!='\0'){
    if(texto[tamTexto] == c){
    qntOcorrencias++;
    }
  tamTexto++;
  }
  return qntOcorrencias;
  }
  else
  while(texto[tamTexto]!='\0'){ 
     if((texto[tamTexto] == c) || (texto[tamTexto] == c + 32) || (texto[tamTexto] == c - 32)){
     qntOcorrencias++;
    }
  tamTexto++;
  }
  return qntOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
   int qtdOcorrencias = 0;
  int x, y, tamPalavra = 0, verifRepete, posicao = -2, contRepete = 0, acento=0;
  while(strBusca[tamPalavra] != '\0'){
    tamPalavra++;
  }
  for(x = 0; strTexto[x]!='\0'; x++){
    if(strTexto[x]==-95 || strTexto[x]==-87 || strTexto[x]==-83 || strTexto[x]==-77 || strTexto[x]==-70 || strTexto[x]==-93 || strTexto[x]==-89 || strTexto[x]==-76)
       acento++;
    if(strBusca[0] == strTexto[x]){
      verifRepete = 1;
      for(y = 0; y < tamPalavra; y++){
        if(strBusca[y] != strTexto[x + y]){
          verifRepete= 0;
          break;
        }
      }
      if(verifRepete == 1){
        contRepete++;
        posicao = posicao + 2;
        qtdOcorrencias = contRepete;
        posicoes[posicao] = x + 1 - acento;
        posicoes[posicao+1] = x + tamPalavra - acento;
      }
    }   
  } 
    return qtdOcorrencias;
}


/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){
    int invert = 0, aux;
    while(num > 0) {
        aux = num % 10;
        invert = invert * 10 + aux;
        num /= 10;
    }
    return invert; 
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
  int aux, qtdOcorrencias = 0;
  int tamanho = 1;
  aux = numerobusca;
  while(aux != 0){
  tamanho = tamanho * 10;
  aux = aux/ 10;
}
  aux = numerobase;
  while(aux != 0){
    if(aux % tamanho == numerobusca){
      qtdOcorrencias++;
      aux = aux / tamanho;
    }
    else
      aux = aux / 10;
  }
  return qtdOcorrencias;
}
