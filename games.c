#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include "rlutil.h"
#include "games.h"

char l[1000]="";

int menu(int tam,char frase[],char opcoes[],int frasenum,char simbolo1,char simbolo2,int cor_padrao,int cor_selecionada,int cor_simbolos){
    setCursorVisibility(0);
    int i,j,e=0;
    char escolha[tam][2],mov;
    do{
        system("cls");
        for (i=0;i<tam;i++){
            escolha[i][0]=' ';
            escolha[i][1]=' ';
        }
        escolha[e][0]=simbolo1;
        escolha[e][1]=simbolo2;
        setColor(cor_padrao);
        printf("%s\n",frase);
        if(!frasenum){
            for(i=0,j=0;opcoes[i]!=0;i++,j++){
                setColor(cor_simbolos);
                printf("%c ",escolha[j][0]);
                if(escolha[j][0]!=' ')
                    setColor(cor_selecionada);
                else
                    setColor(cor_padrao);
                for(;opcoes[i]!='|';i++)
                    printf("%c",opcoes[i]);
                setColor(cor_simbolos);
                printf(" %c \n",escolha[j][1]);
            }
        }else{
            for(i=0;i<tam;i++){
                setColor(cor_simbolos);
                printf("%c ",escolha[i][0]);
                if(escolha[i][0]!=' ')
                    setColor(cor_selecionada);
                else
                    setColor(cor_padrao);
                printf("%d ",i+1);
                setColor(cor_simbolos);
                printf("%c\n",escolha[i][1]);
            }
        }
        setColor(cor_padrao);
        do{
            do{
                mov=getch();
            }while(mov!=-32 && mov!='w' && mov!='s' && mov!=13 && mov!=27 && mov!=8 &&(mov<'1' && mov>tam+48));
            if(mov==-32)
                mov=getch();
        }while(mov!='H' && mov!='P' && mov!='w' && mov!='s' && mov!=13 && mov!=27 && mov!=8 &&(mov<'1' && mov>tam+48));
        if(tam<10 && mov>='1' && mov<=tam+48)
            e=mov-49;
        switch(mov){
            case 'w':
            case 'H':if(e>0) e--;else e=tam-1;break;
            case 's':
            case 'P':if(e<tam-1) e++;else e=0;break;
            case 27:return -1;break;
            case 8:return -2;break;
        }
    }while(mov!=13);
    system("cls");
    return e;
}
void player2(char ptemp[],char p2[],int pvp){
    strcpy(p2,ptemp);
    if(!pvp)
        language(0,p2);
}
void help(int jogo){
    FILE *fp;
    char ch,op[1000];
    language(jogo+1,op);
    fp=fopen(op,"r");
    do{
        ch=fgetc(fp);
        printf("%c",ch);
    }while(ch!=EOF);
    printf("\n");
    system("pause");
}
void lingua_padrao(int lingua){
    switch(lingua){
        case 0:
            strcpy(l,"");
            break;
        case 1:
            strcpy(l,"English");
            break;
        case 2:
            strcpy(l,"Portuguese");
            break;
        case 3:
            strcpy(l,"Spanish");
            break;
    }
}
void language(int frase,char str[]){
    int lang=0;
    if(!strcmp("English_United States.1252",setlocale(LC_MONETARY,l)))
        lang=0;
    if(!strcmp("Portuguese_Brazil.1252",setlocale(LC_MONETARY,l)))
        lang=1;
    if(!strcmp("Spanish_Spain.1252",setlocale(LC_MONETARY,l)))
        lang=1;
    switch(frase){
        case 0:
            if(!lang)
                strcpy(str,"Computer");
            if(lang==1)
                strcpy(str,"Computador");
            break;
        case 1:
            if(!lang)
                strcpy(str,"tictactoe.txt");
            if(lang==1)
                strcpy(str,"jogodavelha.txt");
            break;
        case 2:
            if(!lang)
                strcpy(str,"mastermind.txt");
            if(lang==1)
                strcpy(str,"senha.txt");
            break;
        case 3:
            if(!lang)
                strcpy(str,"hangman.txt");
            if(lang==1)
                strcpy(str,"jogodaforca.txt");
        case QUANT_JOGOS+1:
            if(!lang)
                system("title Games");
            if(lang==1)
                system("title Jogos");
            break;
        case QUANT_JOGOS+2:
            if(!lang)
                strcpy(str,"Play:");
            if(lang==1)
                strcpy(str,"Jogar:");
            break;
        case QUANT_JOGOS+3:
            if(!lang)
                strcpy(str,"Configurations|Tic Tac Toe|Mastermind|Hangman|Tetris|Quit game|");
            if(lang==1){
                strcpy(str,"Configurações|Jogo da velha|Senha|Jogo da forca|Tetris|Sair|");
                str[9]=-121;
                str[10]=-28;
            }
            break;
        case QUANT_JOGOS+4:
            if(!lang)
                strcpy(str,"Configurations:");
            if(lang==1){
                strcpy(str,"Configurações");
                str[9]=-121;
                str[10]=-28;
            }
            break;
        case QUANT_JOGOS+5:
            if(!lang)
                strcpy(str,"How to play|Name Players|Main language|Return|Quit game|");
            if(lang==1){
                strcpy(str,"Como jogar|Nomear Jogadores|Língua principal|Voltar|Sair|");
                str[29]=-95;
            }
            break;
        case QUANT_JOGOS+6:
            if(!lang)
                strcpy(str,"How to play:");
            if(lang==1)
                strcpy(str,"Como jogar:");
            break;
        case QUANT_JOGOS+7:
            if(!lang)
                strcpy(str,"Tic Tac Toe|Mastermind|Hangman|Return|Quit game|");
            if(lang==1)
                strcpy(str,"Jogo da velha|Senha|Jogo da forca|Voltar|Sair|");
            break;
        case QUANT_JOGOS+8:
            if(!lang)
                strcpy(str,"Name:");
            if(lang==1)
                strcpy(str,"Nomear:");
            break;
        case QUANT_JOGOS+9:
            if(!lang)
                strcpy(str,"Player 1|Player 2|Return|Quit game|");
            if(lang==1)
                strcpy(str,"Jogador 1|Jogador 2|Voltar|Sair|");
            break;
        case QUANT_JOGOS+10:
            if(!lang)
                printf("Player 1's name: ");
            if(lang==1)
                printf("Nome do jogador 1: ");
            break;
        case QUANT_JOGOS+11:
            if(!lang)
                printf("Player 2's name: ");
            if(lang==1)
                printf("Nome do jogador 2: ");
            break;
        case QUANT_JOGOS+12:
            if(!lang)
                strcpy(str,"Languages:");
            if(lang==1)
                strcpy(str,"Idiomas:");
            break;
        case QUANT_JOGOS+13:
            if(!lang)
                strcpy(str,"Default|English|Portuguese|Spanish|Return|Quit game|");
            if(lang==1){
                strcpy(str,"Padrão|Inglês|Português|Espanhol|Voltar|Sair|");
                str[4]=-58;
                str[11]=-120;
                str[21]=-120;
            }
            break;
        case QUANT_JOGOS+14:
            if(!lang)
                system("title Tic Tac Toe");
            if(lang==1)
                system("title Jogo da Velha");
            break;
        case QUANT_JOGOS+15:
            if(!lang)
                strcpy(str,"Gamemode:");
            if(lang==1)
                strcpy(str,"Modo de jogo:");
            break;
        case QUANT_JOGOS+16:
            if(!lang)
                strcpy(str,"Player vs Computer|Player vs Player|Return|Quit game|");
            if(lang==1)
                strcpy(str,"Jogador vs Computador|Jogador vs Jogador|Voltar|Sair|");
            break;
        case QUANT_JOGOS+17:
            if(!lang)
                strcpy(str,"Difficulty:");
            if(lang==1)
                strcpy(str,"Dificuldade:");
            break;
        case QUANT_JOGOS+18:
            if(!lang)
                strcpy(str,"Easy|Medium|Hard|Return|Quit game|");
            if(lang==1){
                strcpy(str,"Fácil|Médio|Difícil|Voltar|Sair|");
                str[1]=-96;
                str[7]=-126;
                str[15]=-95;
            }
            break;
        case QUANT_JOGOS+19:
            if(!lang)
                printf("choose a position:\n");
            if(lang==1)
                printf("escolha uma posi%c%co:\n",-121,-58);
            break;
        case QUANT_JOGOS+20:
            if(!lang)
                printf("Choose a valid position!\n\n");
            if(lang==1)
                printf("Escolha uma posi%c%co v%clida!\n\n",135,198,160);
            break;
        case QUANT_JOGOS+21:
            if(!lang)
                printf("Draw!\n\n");
            if(lang==1)
                printf("Deu velha!\n\n");
            break;
        case QUANT_JOGOS+22:
            if(!lang)
                printf("Congratulations %s, you win!\n\n",str);
            if(lang==1)
                printf("Parab%cns %s, voc%c ganhou!\n\n",130,str,136);
            break;
        case QUANT_JOGOS+23:
            if(!lang)
                printf("\nWins:\n");
            if(lang==1)
                printf("\nVit%crias:\n",-94);
            break;
        case QUANT_JOGOS+24:
            if(!lang)
                printf("Draw:");
            if(lang==1)
                printf("Velha:");
            break;
        case QUANT_JOGOS+25:
            if(!lang)
                strcpy(str,"Play again|Return|");
            if(lang==1)
                strcpy(str,"Jogar novamente|Voltar|");
            break;
        case QUANT_JOGOS+26:
            if(!lang)
                system("title Mastermind");
            if(lang==1)
                system("title Senha");
            break;
        case QUANT_JOGOS+27:
            if(!lang)
                strcpy(str,"Easy|Hard|Return|Quit game|");
            if(lang==1){
                strcpy(str,"Fácil|Difícil|Voltar|Sair|");
                str[1]=-96;
                str[9]=-95;
            }
            break;
        case QUANT_JOGOS+28:
            if(!lang)
                strcpy(str,"Quantity of colors:");
            if(lang==1)
                strcpy(str,"Quantidade de cores:");
            break;
        case QUANT_JOGOS+29:
            if(!lang)
                printf("tries left.\n\n");
            if(lang==1)
                printf("tentativas restantes.\n\n");
            break;
        case QUANT_JOGOS+30:
            if(!lang)
                printf("try left.\n\n");
            if(lang==1)
                printf("tentativa restante.\n\n");
            break;
        case QUANT_JOGOS+31:
            if(!lang)
                printf("You win!\n");
            if(lang==1)
                printf("Acertou!\n");
            break;
        case QUANT_JOGOS+32:
            if(!lang)
                printf("You lose!\n");
            if(lang==1)
                printf("Perdeu!\n");
            break;
        case QUANT_JOGOS+33:
            if(!lang)
                printf("The combination is:\n");
            if(lang==1)
                printf("A senha %c:\n",-126);
            break;
        case QUANT_JOGOS+34:
            if(!lang)
                system("title Hangman");
            if(lang==1)
                system("title Jogo da forca");
            break;
        case QUANT_JOGOS+35:
            if(!lang)
                printf(", type the secret word:\n");
            if(lang==1)
                printf(", digite a palavra secreta:\n");
            break;
        case QUANT_JOGOS+36:
            if(!lang)
                printf("Errors:\n");
            if(lang==1)
                printf("Erros:\n");
            break;
        case QUANT_JOGOS+37:
            if(!lang)
                printf("The word is: ");
            if(lang==1)
                printf("A palavra %c: ",-126);
            break;
    }
}
void jogodavelha(char p1[],char p2[],int pvp,int diff){
    int w1=0,w2=0,jogos=0,sair,i,j,jogada,ir,jr,op,v;
    char ttt[3][3],pos[3][3],move,t1[1000];
    do{
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                ttt[i][j]=' ';
        jogada=0;
        while(1){
            i=0;
            j=0;
            if((!pvp && !(jogos%2) && jogada%2)||(!pvp && jogos%2 && !(jogada%2))){
                do{
                    i=rand()%3;
                    j=rand()%3;
                }while(ttt[i][j]!=' ');
                if(diff==2 &&(ttt[0][0]==' ' || ttt[0][2]==' ' || ttt[1][1]==' ' || ttt[2][0]==' ' || ttt[2][2]==' ')){
                    do{
                        op=rand()%5;
                        switch(op){
                            case 0:i=0;j=0;break;
                            case 1:i=0;j=2;break;
                            case 2:i=1;j=1;break;
                            case 3:i=2;j=0;break;
                             case 4:i=2;j=2;break;
                        }
                    }while(ttt[i][j]!=' ');
                }
                if(diff==2 && jogos%2 && jogada==2){
                    if(ttt[1][1]==' '){
                        i=1;
                        j=1;
                    }
                    if(ttt[0][0]=='O' && ttt[2][2]==' '){
                        i=2;
                        j=2;
                    }
                    if(ttt[0][2]=='O' && ttt[2][0]==' '){
                        i=2;
                        j=0;
                    }
                    if(ttt[2][0]=='O' && ttt[0][2]==' '){
                        i=0;
                        j=2;
                    }
                    if(ttt[2][2]=='O' && ttt[0][0]==' '){
                        i=0;
                        j=0;
                    }
                }
                if(diff==2 && jogos%2 && jogada==4){
                    if(ttt[0][0]=='O'){
                        if(ttt[0][1]=='X'){
                            i=2;
                            j=0;
                        }
                        if(ttt[1][0]=='X'){
                            i=0;
                            j=2;
                        }
                    }
                    if(ttt[0][2]=='O'){
                        if(ttt[0][1]=='X'){
                            i=2;
                            j=2;
                        }
                        if(ttt[1][2]=='X'){
                            i=0;
                            j=0;
                        }
                    }
                    if(ttt[2][0]=='O'){
                        if(ttt[1][0]=='X'){
                            i=2;
                            j=2;
                        }
                        if(ttt[2][1]=='X'){
                            i=0;
                            j=0;
                        }
                    }
                    if(ttt[2][2]=='O'){
                        if(ttt[1][2]=='X'){
                            i=2;
                            j=0;
                        }
                        if(ttt[2][1]=='X'){
                            i=0;
                            j=2;
                        }
                    }
                }
                if(diff==2 && !(jogos%2) && jogada==3){
                    if(ttt[0][1]==' ' && ttt[1][1]!='O'){
                        i=0;
                        j=1;
                    }
                    if(ttt[0][1]=='O'){
                        if(ttt[1][0]=='O'){
                            i=0;
                            j=0;
                        }
                        if(ttt[1][2]=='O'){
                            i=0;
                            j=2;
                        }
                    }
                    if(ttt[2][1]=='O'){
                        if(ttt[1][0]=='O'){
                            i=2;
                            j=0;
                        }
                        if(ttt[1][2]=='O'){
                            i=2;
                            j=2;
                        }
                    }
                }
                if(diff==2 && !(jogos%2) && jogada==1 && ttt[1][1]==' '){
                    i=1;
                    j=1;
                }
                if(diff>0 && ttt[0][0]==' ' &&((ttt[1][1]=='O' && ttt[2][2]=='O')||(ttt[0][1]=='O' && ttt[0][2]=='O')||(ttt[1][0]=='O' && ttt[2][0]=='O'))){
                    i=0;
                    j=0;
                }
                if(diff>0 && ttt[0][1]==' ' &&((ttt[0][0]=='O' && ttt[0][2]=='O')||(ttt[1][1]=='O' && ttt[2][1]=='O'))){
                    i=0;
                    j=1;
                }
                if(diff>0 && ttt[0][2]==' ' &&((ttt[1][1]=='O' && ttt[2][0]=='O')||(ttt[0][0]=='O' && ttt[0][1]=='O')||(ttt[1][2]=='O' && ttt[2][2]=='O'))){
                    i=0;
                    j=2;
                }
                if(diff>0 && ttt[1][0]==' ' &&((ttt[0][0]=='O' && ttt[2][0]=='O')||(ttt[1][1]=='O' && ttt[1][2]=='O'))){
                    i=1;
                    j=0;
                }
                if(diff>0 && ttt[1][1]==' ' &&((ttt[0][0]=='O' && ttt[2][2]=='O')||(ttt[0][2]=='O' && ttt[2][0]=='O')||(ttt[1][0]=='O' && ttt[1][2]=='O')||(ttt[0][1]=='O' && ttt[2][1]=='O'))){
                    i=1;
                    j=1;
                }
                if(diff>0 && ttt[1][2]==' ' &&((ttt[1][0]=='O' && ttt[1][1]=='O')||(ttt[0][2]=='O' && ttt[2][2]=='O'))){
                    i=1;
                    j=2;
                }
                if(diff>0 && ttt[2][0]==' ' &&((ttt[0][2]=='O' && ttt[1][1]=='O')||(ttt[2][1]=='O' && ttt[2][2]=='O')||(ttt[0][0]=='O' && ttt[1][0]=='O'))){
                    i=2;
                    j=0;
                }
                if(diff>0 && ttt[2][1]==' ' &&((ttt[2][0]=='O' && ttt[2][2]=='O')||(ttt[0][1]=='O' && ttt[1][1]=='O'))){
                    i=2;
                    j=1;
                }
                if(diff>0 && ttt[2][2]==' ' &&((ttt[0][0]=='O' && ttt[1][1]=='O')||(ttt[2][0]=='O' && ttt[2][1]=='O')||(ttt[0][2]=='O' && ttt[1][2]=='O'))){
                    i=2;
                    j=2;
                }
                if(diff>0 && ttt[0][0]==' ' &&((ttt[1][1]=='X' && ttt[2][2]=='X')||(ttt[0][1]=='X' && ttt[0][2]=='X')||(ttt[1][0]=='X' && ttt[2][0]=='X'))){
                    i=0;
                    j=0;
                }
                if(diff>0 && ttt[0][1]==' ' &&((ttt[0][0]=='X' && ttt[0][2]=='X')||(ttt[1][1]=='X' && ttt[2][1]=='X'))){
                    i=0;
                    j=1;
                }
                if(diff>0 && ttt[0][2]==' ' &&((ttt[1][1]=='X' && ttt[2][0]=='X')||(ttt[0][0]=='X' && ttt[0][1]=='X')||(ttt[1][2]=='X' && ttt[2][2]=='X'))){
                    i=0;
                    j=2;
                }
                if(diff>0 && ttt[1][0]==' ' &&((ttt[0][0]=='X' && ttt[2][0]=='X')||(ttt[1][1]=='X' && ttt[1][2]=='X'))){
                    i=1;
                    j=0;
                }
                if(diff>0 && ttt[1][1]==' ' &&((ttt[0][0]=='X' && ttt[2][2]=='X')||(ttt[0][2]=='X' && ttt[2][0]=='X')||(ttt[1][0]=='X' && ttt[1][2]=='X')||(ttt[0][1]=='X' && ttt[2][1]=='X'))){
                    i=1;
                    j=1;
                }
                if(diff>0 && ttt[1][2]==' ' &&((ttt[1][0]=='X' && ttt[1][1]=='X')||(ttt[0][2]=='X' && ttt[2][2]=='X'))){
                    i=1;
                    j=2;
                }
                if(diff>0 && ttt[2][0]==' ' &&((ttt[0][2]=='X' && ttt[1][1]=='X')||(ttt[2][1]=='X' && ttt[2][2]=='X')||(ttt[0][0]=='X' && ttt[1][0]=='X'))){
                    i=2;
                    j=0;
                }
                if(diff>0 && ttt[2][1]==' ' &&((ttt[2][0]=='X' && ttt[2][2]=='X')||(ttt[0][1]=='X' && ttt[1][1]=='X'))){
                    i=2;
                    j=1;
                }
                if(diff>0 && ttt[2][2]==' ' &&((ttt[0][0]=='X' && ttt[1][1]=='X')||(ttt[2][0]=='X' && ttt[2][1]=='X')||(ttt[0][2]=='X' && ttt[1][2]=='X'))){
                    i=2;
                    j=2;
                }
                if(diff>0 && jogos%2==1){
                    if(ttt[0][0]==' ' &&((ttt[1][1]=='O' && ttt[2][2]=='O')||(ttt[0][1]=='O' && ttt[0][2]=='O')||(ttt[1][0]=='O' && ttt[2][0]=='O'))){
                        i=0;
                        j=0;
                    }
                    if(ttt[0][1]==' ' &&((ttt[0][0]=='O' && ttt[0][2]=='O')||(ttt[1][1]=='O' && ttt[2][1]=='O'))){
                        i=0;
                        j=1;
                    }
                    if(ttt[0][2]==' ' &&((ttt[1][1]=='O' && ttt[2][0]=='O')||(ttt[0][0]=='O' && ttt[0][1]=='O')||(ttt[1][2]=='O' && ttt[2][2]=='O'))){
                        i=0;
                        j=2;
                    }
                    if(ttt[1][0]==' ' &&((ttt[0][0]=='O' && ttt[2][0]=='O')||(ttt[1][1]=='O' && ttt[1][2]=='O'))){
                        i=1;
                        j=0;
                    }
                    if(ttt[1][1]==' ' &&((ttt[0][0]=='O' && ttt[2][2]=='O')||(ttt[0][2]=='O' && ttt[2][0]=='O')||(ttt[1][0]=='O' && ttt[1][2]=='O')||(ttt[0][1]=='O' && ttt[2][1]=='O'))){
                        i=1;
                        j=1;
                    }
                    if(ttt[1][2]==' ' &&((ttt[1][0]=='O' && ttt[1][1]=='O')||(ttt[0][2]=='O' && ttt[2][2]=='O'))){
                        i=1;
                        j=2;
                    }
                    if(ttt[2][0]==' ' &&((ttt[0][2]=='O' && ttt[1][1]=='O')||(ttt[2][1]=='O' && ttt[2][2]=='O')||(ttt[0][0]=='O' && ttt[1][0]=='O'))){
                        i=2;
                        j=0;
                    }
                    if(ttt[2][1]==' ' &&((ttt[2][0]=='O' && ttt[2][2]=='O')||(ttt[0][1]=='O' && ttt[1][1]=='O'))){
                        i=2;
                        j=1;
                    }
                    if(ttt[2][2]==' ' &&((ttt[0][0]=='O' && ttt[1][1]=='O')||(ttt[2][0]=='O' && ttt[2][1]=='O')||(ttt[0][2]=='O' && ttt[1][2]=='O'))){
                        i=2;
                        j=2;
                    }
                    if(ttt[0][0]==' ' &&((ttt[1][1]=='O' && ttt[2][2]=='O')||(ttt[0][1]=='O' && ttt[0][2]=='O')||(ttt[1][0]=='O' && ttt[2][0]=='O'))){
                        i=0;
                        j=0;
                    }
                    if(ttt[0][1]==' ' &&((ttt[0][0]=='O' && ttt[0][2]=='O')||(ttt[1][1]=='O' && ttt[2][1]=='O'))){
                        i=0;
                        j=1;
                    }
                    if(ttt[0][2]==' ' &&((ttt[1][1]=='O' && ttt[2][0]=='O')||(ttt[0][0]=='O' && ttt[0][1]=='O')||(ttt[1][2]=='O' && ttt[2][2]=='O'))){
                        i=0;
                        j=2;
                    }
                    if(ttt[1][0]==' ' &&((ttt[0][0]=='O' && ttt[2][0]=='O')||(ttt[1][1]=='O' && ttt[1][2]=='O'))){
                        i=1;
                        j=0;
                    }
                    if(ttt[1][1]==' ' &&((ttt[0][0]=='O' && ttt[2][2]=='O')||(ttt[0][2]=='O' && ttt[2][0]=='O')||(ttt[1][0]=='O' && ttt[1][2]=='O')||(ttt[0][1]=='O' && ttt[2][1]=='O'))){
                        i=1;
                        j=1;
                    }
                    if(ttt[1][2]==' ' &&((ttt[1][0]=='O' && ttt[1][1]=='O')||(ttt[0][2]=='O' && ttt[2][2]=='O'))){
                        i=1;
                        j=2;
                    }
                    if(ttt[2][0]==' ' &&((ttt[0][2]=='O' && ttt[1][1]=='O')||(ttt[2][1]=='O' && ttt[2][2]=='O')||(ttt[0][0]=='O' && ttt[1][0]=='O'))){
                        i=2;
                        j=0;
                    }
                    if(ttt[2][1]==' ' &&((ttt[2][0]=='O' && ttt[2][2]=='O')||(ttt[0][1]=='O' && ttt[1][1]=='O'))){
                        i=2;
                        j=1;
                    }
                    if(ttt[2][2]==' ' &&((ttt[0][0]=='O' && ttt[1][1]=='O')||(ttt[2][0]=='O' && ttt[2][1]=='O')||(ttt[0][2]=='O' && ttt[1][2]=='O'))){
                        i=2;
                        j=2;
                    }
                }
            }else{
                do{
                    for(ir=0;ir<3;ir++)
                        for(jr=0;jr<3;jr++)
                            pos[ir][jr]=' ';
                    if((jogos%2==0 && jogada%2==0)||(jogos%2==1 && jogada%2==1))
                        printf("%s, ",p1);
                    else
                        printf("%s, ",p2);
                    language(QUANT_JOGOS+19,NULL);
                    pos[i][j]=254;
                    printf("\n   %c %c %c %c %c  \n  %c%c%c%c%c%c%c%c%c%c%c\n   %c %c %c %c %c  \n  %c%c%c%c%c%c%c%c%c%c%c\n   %c %c %c %c %c  \n",pos[0][0],186,pos[0][1],186,pos[0][2],205,205,205,206,205,205,205,206,205,205,205,pos[1][0],186,pos[1][1],186,pos[1][2],205,205,205,206,205,205,205,206,205,205,205,pos[2][0],186,pos[2][1],186,pos[2][2]);
                    printf("\n\n\n\n   %c %c %c %c %c  \n  %c%c%c%c%c%c%c%c%c%c%c\n   %c %c %c %c %c  \n  %c%c%c%c%c%c%c%c%c%c%c\n   %c %c %c %c %c  \n",ttt[0][0],186,ttt[0][1],186,ttt[0][2],205,205,205,206,205,205,205,206,205,205,205,ttt[1][0],186,ttt[1][1],186,ttt[1][2],205,205,205,206,205,205,205,206,205,205,205,ttt[2][0],186,ttt[2][1],186,ttt[2][2]);
                    do{
                        do{
                            move=getch();
                        }while(move!=13 && move!=-32 && move!='w' && move!='d' && move!='s' && move!='a' && (move<'1' && move>'9'));
                        if(move==-32)
                            move=getch();
                    }while(move!='H' && move!='M' && move!='P' && move!='K' && move!='w' && move!='d' && move!='s' && move!='a' && move!=13 && (move<'1' && move>'9'));
                    system("cls");
                    switch (move){
                        case '7':i=0;j=0;break;
                        case '8':i=0;j=1;break;
                        case '9':i=0;j=2;break;
                        case '4':i=1;j=0;break;
                        case '5':i=1;j=1;break;
                        case '6':i=1;j=2;break;
                        case '1':i=2;j=0;break;
                        case '2':i=2;j=1;break;
                        case '3':i=2;j=2;break;
                        case 'w':
                        case 'H':if(i>0) i--;else i=2;break;
                        case 'd':
                        case 'M':if(j<2) j++;else j=0;break;
                        case 's':
                        case 'P':if(i<2) i++;else i=0;break;
                        case 'a':
                        case 'K':if(j>0) j--;else j=2;break;
                    }
                }while(move!=13);
            }
            if(ttt[i][j]==' '){
                jogada++;
                if(jogada%2==1)
                    ttt[i][j] = 'O';
                else
                    ttt[i][j] = 'X';
            }else
                language(QUANT_JOGOS+20,NULL);
            if((ttt[0][0]=='X' && ttt[0][1]=='X' && ttt[0][2]=='X')||(ttt[1][0]=='X' && ttt[1][1]=='X' && ttt[1][2]=='X')||
            (ttt[2][0]=='X' && ttt[2][1]=='X' && ttt[2][2]=='X')||(ttt[0][0]=='X' && ttt[1][0]=='X' && ttt[2][0]=='X')||
            (ttt[0][1]=='X' && ttt[1][1]=='X' && ttt[2][1]=='X')||(ttt[0][2]=='X' && ttt[1][2]=='X' && ttt[2][2]=='X')||
            (ttt[0][0]=='X' && ttt[1][1]=='X' && ttt[2][2]=='X')||(ttt[0][2]=='X' && ttt[1][1]=='X' && ttt[2][0]=='X')){
                if(jogos%2==0){
                    v=2;
                    w2++;
                }else{
                    v=1;
                    w1++;
                }
                break;
            }else{
                if((ttt[0][0]=='O' && ttt[0][1]=='O' && ttt[0][2]=='O')||(ttt[1][0]=='O' && ttt[1][1]=='O' && ttt[1][2]=='O')||
                (ttt[2][0]=='O' && ttt[2][1]=='O' && ttt[2][2]=='O')||(ttt[0][0]=='O' && ttt[1][0]=='O' && ttt[2][0]=='O')||
                (ttt[0][1]=='O' && ttt[1][1]=='O' && ttt[2][1]=='O')||(ttt[0][2]=='O' && ttt[1][2]=='O' && ttt[2][2]=='O')||
                (ttt[0][0]=='O' && ttt[1][1]=='O' && ttt[2][2]=='O')||(ttt[0][2]=='O' && ttt[1][1]=='O' && ttt[2][0]=='O')){
                    if(jogos%2==0){
                        v=1;
                        w1++;
                    }else{
                        v=2;
                        w2++;
                    }
                    break;
                }else{
                    if(jogada==9){
                        v=0;
                        break;
                    }
                }
            }
        }
        jogos++;
        if(v==0)
            language(QUANT_JOGOS+21,NULL);
        else{
            if(v==1)
                language(QUANT_JOGOS+22,p1);
            else
                language(QUANT_JOGOS+22,p2);
        }
        printf("\n   %c %c %c %c %c  \n  %c%c%c%c%c%c%c%c%c%c%c\n   %c %c %c %c %c  \n  %c%c%c%c%c%c%c%c%c%c%c\n   %c %c %c %c %c  \n",ttt[0][0],186,ttt[0][1],186,ttt[0][2],205,205,205,206,205,205,205,206,205,205,205,ttt[1][0],186,ttt[1][1],186,ttt[1][2],205,205,205,206,205,205,205,206,205,205,205,ttt[2][0],186,ttt[2][1],186,ttt[2][2]);
        language(QUANT_JOGOS+23,NULL);
        printf("%s: %d\n%s: %d\n",p1,w1,p2,w2);
        language(QUANT_JOGOS+24,NULL);
        printf(" %d\n",jogos-(w1+w2));
        system("pause");
        language(QUANT_JOGOS+25,t1);
        sair=menu(2,"",t1,0,207,207,0,12,10);
    }while(!sair);
}
void senha(char p1[],char p2[],int diff,const int MAX){
    int w1=0,w2=0,preto,branco;
    char sair,t1[1000];
	do{
        const int SENHA=4;
        const int TENT=10;
        system("cls");
        int pin[SENHA];
        int i=0;
        srand(time(NULL));
        while(i<SENHA){
            int cor=rand()%MAX+1;
            int j,repeat=0;
            for(j=0;j<i;j++)
                if(pin[j]==cor)
                    repeat=1;
            if(!repeat || diff)
                pin[i++]=cor;
        }
        int x;
        for(x=0;x<TENT;x++){
            printf("%d ",TENT-x);
            if(x==TENT-1)
                language(QUANT_JOGOS+30,NULL);
            else
                language(QUANT_JOGOS+29,NULL);
            int op[SENHA],i;
            char temp;
            for(i=0;i<SENHA;i++){
                do{
                    temp=getch();
                    fflush(stdin);
                }while(temp<'1' || temp>MAX+48);
                op[i]=temp-48;
                setColor(op[i]);
                if(op[i]==7)
                    setColor(YELLOW);
                printf("%c ",254);
            }
            setColor(BLACK);
            printf("\n");
            branco=0;
            preto=0;
            for(i=0;i<SENHA;i++){
                if(op[i]==pin[i])
                    preto++;
                int j,temp=0;
                for(j=0;j<SENHA;j++)
                    if(i!=j && op[i]==pin[j] && !temp && op[i]!=pin[i]){
                        branco++;
                        temp++;
                    }
            }
            for(i=0;i<preto;i++)
                printf("%c ",254);
            printf("\n");
            for(i=0;i<branco;i++){
                setColor(GREY);
                printf("%c",254);
                setColor(BLACK);
                printf(" ");
            }
            printf("\n\n");
            if(preto==SENHA) {
                system("cls");
                language(QUANT_JOGOS+31,NULL);
                w1++;
                x=TENT;
            }
        }
        if(preto!=SENHA){
            system("cls");
            language(QUANT_JOGOS+32,NULL);
            w2++;
        }
        language(QUANT_JOGOS+33,NULL);
        for(i=0;i<SENHA;i++){
            setColor(pin[i]);
            if(pin[i]==7)
                    setColor(YELLOW);
            printf("%c ",254);
        }
        setColor(BLACK);
        language(QUANT_JOGOS+23,NULL);
        printf("%s: %d\n%s: %d\n\n",p1,w1,p2,w2);
        system("pause");
        language(QUANT_JOGOS+25,t1);
        sair=menu(2,"",t1,0,207,207,0,12,10);
    }while(!sair);
}
void forca(char p1[],char p2[],const int TENT){
    int w1=0,w2=0,jogos=0;
    char sair,t1[1000];
    do{
        setCursorVisibility(1);
        int i,x;
        char password[1000],guess[1000]="",erro[52]="",c,repeat;
        do{
            system("cls");
            printf(jogos%2 ? p1 : p2);
            language(QUANT_JOGOS+35,NULL);
            gets(password);
            for(i=0,repeat=0;i<strlen(password);i++)
                if((password[i]>='a' && password[i]<='z') || password[i]==' ' || password[i]=='-' || (password[i]>=-96 && password[i]<=-92) || (password[i]>=-109 && password[i]<=-105) || (password[i]>=-127 && password[i]<=-115) || password[i]==-58 || password[i]==-28)
                    repeat++;
        }while(repeat!=strlen(password));
        for(i=0;i<strlen(password);i++)
            guess[i]='_';
        for(x=0;x<TENT;x++){
            system("cls");
            printf("%d ",TENT-x);
            if(x==TENT-1)
                language(QUANT_JOGOS+30,NULL);
            else
                language(QUANT_JOGOS+29,NULL);
            language(QUANT_JOGOS+36,NULL);
            printf("%s\n\n\n%s\n",erro,guess);
            scanf("%c",&c);
            fflush(stdin);
            repeat=0;
            for(i=0;i<strlen(erro);i++)
                if(c==erro[i])
                    repeat++;
            if(!repeat && ((c>='a' && c<='z') || c==' ' || c=='-' || (c>=-96 && c<=-92) || (c>=-109 && c<=-105) || (c>=-127 && c<=-115) || c==-58 || c==-28)){
                int j=0;
                for(i=0;i<=strlen(password);i++)
                    if(c==password[i]){
                        guess[i]=password[i];
                        j++;
                    }
                if(!j)
                    erro[strlen(erro)]=c;
                else
                    x--;
                if(!strcmp(guess,password)){
                    system("cls");
                    jogos%2 ? language(QUANT_JOGOS+22,p2) : language(QUANT_JOGOS+22,p1);
                    jogos%2 ? w2++ : w1++;
                    x=TENT;
                }
            }else
                x--;
        }
        if(strcmp(guess,password)){
            system("cls");
            jogos%2 ? language(QUANT_JOGOS+22,p1) : language(QUANT_JOGOS+22,p2);
            jogos%2 ? w1++ : w2++;
        }
        language(QUANT_JOGOS+37,NULL);
        printf("%s\n",password);
        jogos++;
        language(QUANT_JOGOS+23,NULL);
        printf("%s: %d\n%s: %d\n\n",p1,w1,p2,w2);
        system("pause");
        language(QUANT_JOGOS+25,t1);
        sair=menu(2,"",t1,0,207,207,0,12,10);
    }while(!sair);
}
