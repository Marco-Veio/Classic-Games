#ifndef GAMES_H_INCLUDED
#define GAMES_H_INCLUDED

#define QUANT_JOGOS 4

int menu(int tam,char frase[],char opcoes[],int frasenum,char simbolo1,char simbolo2,int cor_padrao,int cor_selecionada,int cor_simbolos);
void player2(char ptemp[],char p2[],int pvp);
void help(int jogo);
void lingua_padrao(int lingua);
void language(int frase,char str[]);
void jogodavelha(char p1[],char p2[],int pvp,int diff);
void senha(char p1[],char p2[],int diff,const int MAX);
void forca(char p1[],char p2[],const int TENT);

#endif // GAMES_H_INCLUDED
