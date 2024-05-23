#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matriz_atv.h"

/*
    Você poderia também declarar os structs e funções de mtz e mtzseq em um 
    mesmo cabeçalho e dividir as implementações em dois arquivos. Note que é 
    útil dividir as implementações das funções relativas a cada struct em
    arquivos distintos de forma a organizar melhor o seu código. 
*/

/*------------------------------------------------------------------------------
    Funções da matriz com ponteiro simples
------------------------------------------------------------------------------*/

mtzseq new_mtzseq(int lin, int col, float init)
/*
    Retorna nova matriz mtzseq
*/
{
    mtzseq m;

    if (lin>0 && col>0)
    {
        m.lin = lin; m.col = col;
        //Alocação única
        m.data = malloc(lin*col*sizeof(float));
        if (m.data!=NULL)
        {
            //Inicialização das entradas
            for (int i=0; i<m.lin*m.col; i++)
            {
                m.data[i] = init;
            }
        }
        else
        {
            printf("Memória insuficiente para alocação.");
        }
    }
    //Retorna matriz null
    else
    {
        m.lin = 0; m.col = 0;
        m.data = NULL;
    }

    return m;
}

bool mtzseq_is_null(mtzseq m)
{
    if (m.data==NULL)
    {
        return true;
    }
    return false;
}

void free_mtzseq(mtzseq *m)
{
    if (m->data!=NULL)
    {
        free(m->data);
        m->data = NULL;
    }
}

void mset(mtzseq m, int i, int j, float v)
/*
    Função para definir a entrada [i,j] de m com valor v
*/
{
    if (mtzseq_is_null(m))
    {
        printf("Matriz é NULL");
        return; //uma forma de encerrar uma função void a qualquer momento
    }

    if (i>=0 && i<m.lin && j>=0 && j<m.col)
    {
        m.data[i*m.col+j] = v;
    }
    else
    {
        printf("Índice inacessível para mset.");
    }
}

float mget(mtzseq m, int i, int j)
/*
    Função para retornar a entrada [i,j] de m
*/
{
    if (mtzseq_is_null(m))
    {
        printf("Matriz é NULL");
        return 0;
    }

    if (i>=0 && i<m.lin && j>=0 && j<m.col)
    {
        return m.data[i*m.col+j];
    }
    else
    {
        printf("Índice inacessível para mget.");
        return 0;
    }
}

/*------------------------------------------------------------------------------
    
------------------------------------------------------------------------------*/

void mtzseq_read(mtzseq m)
/*
    Pede para usuário inserir elementos da matriz
*/
{
    if (mtzseq_is_null(m))
    {
        printf("Matriz é NULL.");
        return;
    }

    for (int i=0; i<m.lin; i++)
        for (int j=0; j<m.col; j++)
        {
            printf("Digite a entrada [%d,%d]: ",i,j);
            float aux;
            scanf("%f",&aux);
            mset(m,i,j,aux);
        }
}

void mtzseq_print(mtzseq m)
/*
    Imprime elementos da matriz na tela
*/
{
    if (mtzseq_is_null(m))
    {
        printf("Matriz é NULL.");
        return;
    }

    for (int i=0; i<m.lin; i++)
    {
        for (int j=0; j<m.col; j++)
        {
            printf("%f ",mget(m,i,j));
        }
        printf("\n");
    }
}

mtzseq soma_mtzseq(mtzseq A, mtzseq B)
/*
    Soma de duas matrizes
*/
{
    if (!mtzseq_is_null(A) && !mtzseq_is_null(B))
    {
        //Critério para soma ser possível
        if (A.lin==B.lin && A.col==B.col)
        {
            mtzseq res = new_mtzseq(A.lin,A.col,0);
            if (mtzseq_is_null(res))
            {
                printf("Memória insuficiente para matriz de resultado.");
                return new_mtzseq(0,0,0);
            }
            /*Note que não há necessidade de saber o tipo de ordenação desde que
            todas estejam ordenadas da mesma forma.*/
            for (int i=0; i<A.lin*A.col; i++)
            {
                res.data[i] = A.data[i]+B.data[i];
            }
            return res;
        }
        printf("Matrizes incompatíveis para soma.");
        return new_mtzseq(0,0,0);
    }
    printf("Matriz de entrada é null.");
    return new_mtzseq(0,0,0);
}

/*
    ATIVIDADE EM SALA
*/

//Produto por escalar
mtzseq ppscalar_mtzseq(mtzseq A, float x)
{
    if(!mtzseq_is_null(A))
    {
        mtzseq res = new_mtzseq(A.lin,A.col,0);
        for(int i=0; i<A.lin*A.col; i++)
        {
            res.data[i] = A.data[i]*x;
        }
        return res;
    }
    printf("Matriz de entrada é null.");
    return new_mtzseq(0,0,0);
}

//Produto de matrizes
mtzseq mul_mtzseq(mtzseq A, mtzseq B)
{
      if(!mtzseq_is_null(A))
    {
       //Critério para o produto ser possível
        if(A.col==B.lin)
        {
            mtzseq res = new_mtzseq(A.lin,B.col,0);
            
            for(int k=0; k<A.lin; k++){
                for(int j=0; j<B.col; j++){
                    for(int i=0; i<A.col; i++)
                    {
                        res.data[k*B.col+j]+=A.data[k*A.col+i]*B.data[i*B.col+j];
                    }
                    
                }
            }
            return res;
        }
        printf("Matrizes incompatíveis para o produto.");
        return new_mtzseq(0,0,0);
    }
    printf("Matriz de entrada é null.");
    return new_mtzseq(0,0,0);
}
