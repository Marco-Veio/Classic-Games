#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "games.h"

int main()
{
    system("color f0");
    char p1[100],p2[100],ptemp[100],t1[1000],t2[1000];
    int op,pvp,diff,quant;
    strcpy(p1,"Player 1");
    strcpy(p2,"Player 2");
    while(1){
        language(QUANT_JOGOS+1,NULL);
        language(QUANT_JOGOS+2,t1);
        language(QUANT_JOGOS+3,t2);
        switch(menu(QUANT_JOGOS+2,t1,t2,0,207,207,0,12,10)){
            case -1:
            case QUANT_JOGOS+1:return 0;
            case 0:
                language(QUANT_JOGOS+4,t1);
                language(QUANT_JOGOS+5,t2);
                switch(menu(5,t1,t2,0,207,207,0,12,10)){
                    case -1:
                    case 4:return 0;
                    case 0:
                        language(QUANT_JOGOS+6,t1);
                        language(QUANT_JOGOS+7,t2);
                        op=menu(QUANT_JOGOS+2,t1,t2,0,207,207,0,12,10);
                        if(op==-1 || op==QUANT_JOGOS+1)
                            return 0;
                        if(op==-2 || op==QUANT_JOGOS)
                            break;
                        help(op);
                        break;
                    case 1:
                        language(QUANT_JOGOS+8,t1);
                        language(QUANT_JOGOS+9,t2);
                        switch(menu(4,t1,t2,0,207,207,0,12,10)){
                            case 0:
                                language(QUANT_JOGOS+10,NULL);
                                gets(p1);
                                break;
                            case 1:
                                language(QUANT_JOGOS+11,NULL);
                                gets(p2);
                                break;
                            case -1:
                            case 3:return 0;
                        }
                        break;
                    case 2:
                        language(QUANT_JOGOS+12,t1);
                        language(QUANT_JOGOS+13,t2);
                        op=menu(6,t1,t2,0,207,207,0,12,10);
                        if(op==-1 || op==5)
                            return 0;
                        if(op==-2 || op==4)
                            break;
                        lingua_padrao(op);
                }
                break;
            case 1:
                language(QUANT_JOGOS+14,NULL);
                language(QUANT_JOGOS+15,t1);
                language(QUANT_JOGOS+16,t2);
                pvp=menu(4,t1,t2,0,207,207,0,12,10);
                if(pvp==-1||pvp==3)
                    return 0;
                if(!pvp||pvp==1){
                    if(!pvp)
                    {
                        language(QUANT_JOGOS+17,t1);
                        language(QUANT_JOGOS+18,t2);
                        diff=menu(5,t1,t2,0,207,207,0,12,10);
                        if(diff==-1||diff==4)
                            return 0;
                        if(diff==-2||diff==3)
                            break;
                    }
                    player2(p2,ptemp,pvp);
                    jogodavelha(p1,ptemp,pvp,diff);
                }
                break;
            case 2:
                language(QUANT_JOGOS+26,NULL);
                language(QUANT_JOGOS+17,t1);
                language(QUANT_JOGOS+27,t2);
                diff=menu(4,t1,t2,0,207,207,0,12,10);
                if(diff==-1||diff==3)
                    return 0;
                if(diff==-2||diff==2)
                    break;
                language(QUANT_JOGOS+28,t1);
                quant=menu(9,t1,"",1,207,207,0,12,10);
                if(quant==-1)
                    return 0;
                if(quant==-2)
                    break;
                quant++;
                if(quant<4)
                    diff=1;
                player2(p2,ptemp,0);
                senha(p1,ptemp,diff,quant);
                break;
            case 3:
                language(QUANT_JOGOS+34,NULL);
                language(QUANT_JOGOS+17,t1);
                language(QUANT_JOGOS+18,t2);
                diff=menu(5,t1,t2,0,207,207,0,12,10);
                if(diff==-1||diff==4)
                    return 0;
                if(diff==-2||diff==3)
                    break;
                diff=12-3*(diff+1);
                if(diff==9)
                    diff++;
                player2(p2,ptemp,1);
                forca(p1,ptemp,diff);
                break;
        }
    }
}
