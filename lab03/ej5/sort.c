/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    return (*x).rank <= (*y).rank;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void swap(unsigned int i,unsigned int j,player_t a[]){ //ANDA MAS RAPIDO PORQUE NO CAMBIO VALORES REFERIDOS SINO QUE
	player_t aux = a[i];							  // SIMPLEMENTE HAGO QUE APUNTEN A OTRO LADO
	a[i] = a[j];
	a[j] = aux;
}

void sort(player_t a[], unsigned int length) {
    for(unsigned int i = 0u; i < length; i++){
		unsigned int act = i;
		for(unsigned int j = i+1; j < length; j++){
			if(goes_before(a[j],a[act])){
				act = j;
			}
		}
		swap(i,act,a);
	}
}
