#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int retornaDate(int *arrayDate, int posicao);
int buscarPorIndex(int index, int *arrayIndex);
int buscarPorTag(int tag, int *arrayTag, int index);
void imprimirSet(int *setV, int *setIndex, int *setTag, int *setDate);
void inicializarSet(int *setV, int *setTag, int *setDate);
void iniciarIndex(int *index);
void menu();

int tamanhoCache = 256;

int main()
{
    int Tag ;
    int Index ;
    int opcao = 0 ;

    int set0_V[tamanhoCache];
    int set0_tag[tamanhoCache];
    int set0_index[tamanhoCache];
    int set0_date[tamanhoCache];

    int set1_V[tamanhoCache];
    int set1_tag[tamanhoCache];
    int set1_date[tamanhoCache];

    int set2_V[tamanhoCache];
    int set2_tag[tamanhoCache];
    int set2_date[tamanhoCache];

    int set3_V[tamanhoCache];
    int set3_tag[tamanhoCache];
    int set3_date[tamanhoCache];

    int contadorHit = 0 ;
    int contadorMiss = 0 ;

    iniciarIndex(set0_index);

    // inicializando o set 0
    inicializarSet(set0_V,set0_tag,set0_date);

    // inicializando o set 1
    inicializarSet(set1_V,set1_tag,set1_date);

    // inicializando o set 2
    inicializarSet(set2_V,set2_tag,set2_date);

    // inicializando o set 3
    inicializarSet(set3_V,set3_tag,set3_date);

    printf("Memoria cache associativa por conjuntos criada com sucesso \n\n");


    do
    {
        menu();
        scanf("%d",&opcao);

        if(opcao == 1)
        {
            printf("\n");
            printf("Digite o index para procurar na cache: ");
            scanf("%d",&Index);
            int encontrou = buscarPorIndex(Index,set0_index);
            if(encontrou == 1)
            {
                printf("Digite o tag para procurar na cache: ");
                scanf("%d",&Tag);
                int encontrouTag = buscarPorTag(Tag, set0_tag,Index);
                if(encontrouTag == 1)
                {
                    int date = retornaDate(set0_date,Index);

                    printf("\n HIT (set 0)\n");
                    printf("Date encontrado: %d \n\n",date);
                    contadorHit++;
                }
                else
                {
                    int encontrouTag = buscarPorTag(Tag, set1_tag,Index);
                    if(encontrouTag == 1)
                    {
                        int date = retornaDate(set1_date,Index);

                        printf("\n HIT (set 1) \n");
                        printf("Date encontrado: %d \n\n",date);
                        contadorHit++;
                    }
                    else
                    {

                        int encontrouTag = buscarPorTag(Tag, set2_tag,Index);
                        if(encontrouTag == 1)
                        {
                            int date = retornaDate(set2_date,Index);

                            printf("\n HIT (set 2) \n");
                            printf("Date encontrado: %d \n\n",date);
                            contadorHit++;
                        }

                        else
                        {

                            int encontrouTag = buscarPorTag(Tag, set3_tag,Index);
                            if(encontrouTag == 1)
                            {
                                int date = retornaDate(set3_date,Index);

                                printf("\n HIT (set 3)\n");
                                printf("Date encontrado: %d \n\n",date);
                                contadorHit++;
                            }
                            else
                            {
                                printf(" \n MISS \n\n");
                                contadorMiss++;
                            }

                        }
                    }
                }
                printf("Quantidade Hit: %d \n",contadorHit);
                printf("Quantidade Miss: %d \n\n",contadorMiss);
            }
            else
            {
                printf("Index invalido \n");
            }

        }

        else if(opcao == 2)
        {
            printf("--------------- Imprimindo Set 0 ----------------- \n");
            imprimirSet(set0_V,set0_index,set0_tag,set0_date);
        }
        else if(opcao == 3)
        {
            printf("--------------- Imprimindo Set 1 -----------------\n");
            imprimirSet(set1_V,set0_index,set1_tag,set1_date);

        }
        else if(opcao == 4)
        {
            printf("--------------- Imprimindo Set 2 -----------------\n");
            imprimirSet(set2_V,set0_index,set2_tag,set2_date);

        }
        else if(opcao ==5)
        {
            printf("--------------- Imprimindo Set 3----------------- \n");
            imprimirSet(set3_V,set0_index,set3_tag,set3_date);
        }
        else
        {
            printf("\n opcao invalida \n");
        }

    }
    while(opcao != 0);
    {
        printf("\nPrograma finalizado :)\n");
        printf("Aluno: Bruno Dias Pinto \n");
        printf("Matricula: 18.2.8144 \n");

    }

    return 0;
}

void iniciarIndex(int *index)
{
    for(int i =0 ; i < 256; i++)
    {
        index[i] = i;
    }
}


void menu()
{
    printf("1 - Procurar na memoria cache associativa por conjuntos \n");
    printf("2 - Imprimir set 0 \n");
    printf("3 - Imprimir set 1 \n");
    printf("4 - Imprimir set 2 \n");
    printf("5 - Imprimir set 3 \n");
    printf("0 - Sair do loop \n");
    printf("Qual a sua escolha: ");

}

void inicializarSet(int *V,  int *Tag, int *Date)
{

    for(int i = 0 ; i <tamanhoCache; i++)
    {
        Tag[i] = rand() % 750;
        V[i] = 1 ;
        Date[i] = rand() % 1000;

    }

}

void imprimirSet(int *setV, int *setIndex, int *setTag, int *setDate)
{
    for(int i = 0 ; i < tamanhoCache ; i++)
    {
        printf("index: %d\n", setIndex[i]);
        printf("validade: %d\n",setV[i]);
        printf("tag: %d\n", setTag[i]);
        printf("date: %d\n\n", setDate[i]);
    }
}


int  buscarPorTag(int tag, int *arrayTag, int index)
{
    if(tag == arrayTag[index])
    {
        return 1 ; // encontrou a tag
    }

    return 0; // nao encontrou
}

int buscarPorIndex(int index, int *arrayIndex)
{

    if(index == arrayIndex[index])
    {
        return 1 ; // encontrou o index
    }


    return 0 ; // nao encontrou
}

int retornaDate(int *arrayDate, int posicao)
{
    return arrayDate[posicao] ;

}
