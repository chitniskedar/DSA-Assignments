#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "poly.h"

void init_poly(poly_t *ptr_poly)
{
	ptr_poly->head_ = NULL;
}

void disp(poly_t *ptr_poly)
{
	node_t* pres = ptr_poly->head_;
	while(pres != NULL)
	{
		//printf("%d ", pres->key_);
		disp_term(&pres->term_);
		pres = pres->next_;
	}
	printf("\n");
}

int eval(poly_t* ptr_poly, int x)
{
	node_t* pres = ptr_poly->head_;
	int res = 0;
	while(pres != NULL)
	{
		res += val(&pres->term_, x);
		pres = pres->next_;
	}
	return res;
}

void insert(poly_t* ptr_poly, int coeff, int expo) 
{
	node_t* temp;
	temp = (node_t*)malloc(sizeof(node_t));
	set_term(&temp->term_, coeff, expo);
	temp->next_ = NULL;
	
	// 1. empty poly 
	if(ptr_poly->head_ == NULL)
	{
		ptr_poly->head_ = temp;
		temp->next_ = NULL;
	}
	else // find the position
	{
		node_t* prev = NULL; 
		node_t* pres = ptr_poly->head_;
		//while(pres != NULL && pres->key_ < temp->key_)
		while(pres != NULL && 
			compare_exponents(&pres->term_, &temp->term_) > 0)
		{
			prev = pres;
			pres = pres->next_;
		}
		// beginning 
		if(prev == NULL)
		{
			ptr_poly->head_ = temp;
			temp->next_ = pres;
		}
		else // middle or end 
		{
			prev->next_ = temp;
			temp->next_ = pres;
		}
	}
	
}

void copy_poly(poly_t* mypoly_new, poly_t* mypoly){
	node_t* pres = mypoly->head_;
    init_poly(mypoly_new);
    while(pres != NULL)
    {
        insert(mypoly_new, pres->term_.coeff_, pres->term_.expo_);
        pres = pres->next_;
    }
}

void differentiate(poly_t* ptr_poly, poly_t* ptr_diff_poly)
{
	node_t* pres = ptr_poly->head_;
	init_poly(ptr_diff_poly);

	while (pres!=NULL)
	{
		if (pres->term_.expo_!=0)							// will ignore the constant term
		{
			insert (ptr_diff_poly, 
					pres->term_.coeff_*pres->term_.expo_,	// coeff multiplied by n
                	pres->term_.expo_-1);					// expo decrease by 1
		}
		pres = pres->next_;
	}
}

int power(int x, int n)
{
    int result = 1;
    for(int i = 0; i < n; i++)
    {
        result *= x;
    }
    return result;
}

int definite_integral(poly_t* ptr_poly, int upper_limit, int lower_limit)	
{
	node_t* pres = ptr_poly->head_;
    int result = 0;

	while (pres!=NULL)
	{
		int coeff = pres->term_.coeff_;
        int expo = pres->term_.expo_;

		result += (coeff*(power(upper_limit, expo+1) - power(lower_limit, expo+1)))/(expo+1);
		pres = pres->next_;
	}	// for P*x^n : P * ((upperlimit^n+1) - (lowerlimit^n+1)) / n+1

	return result;
}