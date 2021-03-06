#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void bubblesort(int arquivo[],int size){
    int troca = 1;
    int cont =0;
    int temp;
    while(troca){
        troca = 0;
        for(int i=0;i<size-1-cont;i++){
            if(arquivo[i]>arquivo[i+1]){
                temp = arquivo[i];
                arquivo[i] = arquivo[i+1];
                arquivo[i+1] = temp;
                troca = 1;
            }
        }
        cont++;
    }
}

void rQuickSort(int arquivo[],int inicio,int fim){
    if(inicio<fim){
        int i= inicio;
        int j = fim;
        int p = arquivo[inicio];
        int temp;
        while(i<j){
            while (arquivo[i]<= p){
                i++;
            }
            while (arquivo[j] > p){
                j--;
            }
            if(i<j){
                temp = arquivo[i];
                arquivo[i] = arquivo[j];
                arquivo[j] = temp;
            }
        }
        arquivo[inicio] = arquivo[j];
        arquivo[j] = p;
        rQuickSort(arquivo,inicio,j-1);
        rQuickSort(arquivo,j+1,fim);
    }
}

void quicksort(int arquivo[],int size){
    rQuickSort(arquivo,0,size-1);
}

void selectionSort(int arquivo[],int size){
    int max = arquivo[0];
    int pos =0;
    int temp;
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i;j++){
            if(arquivo[j]>=max){
                max = arquivo[j];
                pos = j;
            }
        }
        temp = arquivo[size-i-1];
        arquivo[size-i-1] = max;
        arquivo[pos] = temp;
        max = arquivo[0];
    }
}

void insertionSort(int arquivo[],int size){
    int temp;
    for(int i=1;i<size;i++){
        temp = arquivo[i];
        for(int j=i;j>0;j--){
            if(temp < arquivo[j-1]){
                arquivo[j]=arquivo[j-1];
                arquivo[j-1] = temp;
            }else{
                break;
            }
        }
    }
}

void shellSort(int arquivo[],int size,int seq[],int sizeSeq){
    int temp;
    for(int i=sizeSeq-1;i>=0;i--){
        for(int j=i;j<size;j++){
            int k=j;
            while(arquivo[k]<arquivo[k-seq[i]] && k>=seq[i]){
                temp = arquivo[k-seq[i]];
                arquivo[k-seq[i]] = arquivo[k];
                arquivo[k] = temp;
                k-=seq[i];
            }
        }
    }
}

void rMergeSort(int arquivo[],int inicio,int fim){
    if(inicio<fim){
        int meio = ((inicio+fim)/2);

        rMergeSort(arquivo,inicio,meio);
        rMergeSort(arquivo,meio + 1,fim);

        int tamanho = fim-inicio + 1;
        int* tempArray = (int*)malloc(tamanho*sizeof(int));
        int p1 = inicio;
        int p2 = meio+1;
        int k=0;
        while(p1<=meio && p2<=fim){
            if(arquivo[p1]<arquivo[p2]){
                tempArray[k++] =arquivo[p1++];
            }else{
                tempArray[k++] =arquivo[p2++];
            }
        }
        while(p1<=meio){
            tempArray[k++] =arquivo[p1++];
        }
        while(p2<=fim){
            tempArray[k++] =arquivo[p2++];
        }
        for(int k=0;k<tamanho;k++){
            arquivo[inicio+k]=tempArray[k];
        }
        free(tempArray);
    }

}

void mergeSort(int arquivo[],int size){
    rMergeSort(arquivo,0,size-1);
}

void countingSort(int arquivo[],int size){
    int max, min;
    max = min = arquivo[0];
    for(int i=1;i<size;i++){
        if(arquivo[i]>max){
            max = arquivo[i];
        }
        if(arquivo[i]<min){
            min = arquivo[i];
        }
    }
    int* tempArray = (int*)malloc((max-min+1)*sizeof(int));
    for(int i=0;i<size;i++){
        tempArray[arquivo[i]-min]++;
    }
    int j=0;
    for(int i=0;i<max-min+1;i++){
        if(tempArray[i]!=0){
            while(tempArray[i]!=0){
                arquivo[j++] = i + min;
                tempArray[i]--;
            }
        }
    }
}

void heap(int arquivo[],int inicio,int size){
    int pai = arquivo[inicio];
    int j= 2*inicio+1;
    while(j<=size){
        if(j<size){
            if(arquivo[j]<arquivo[j+1]){
                j++;
            }
        }
        if(arquivo[j]>pai){
            arquivo[inicio] = arquivo[j];
            inicio = j;
            j = 2*inicio+1;
        }else{
            break;
        }
    }
    arquivo[inicio] = pai;
}

void heapSort(int arquivo[],int size){
    int temp;
    for(int i=(size-1)/2;i>=0;i--){
        heap(arquivo,i,size-1);
    }
    for(int i=size-1;i>=0;i--){
        temp = arquivo[i];
        arquivo[i] = arquivo[0];
        arquivo[0] = temp;
        heap(arquivo,0,i-1);
    }
}