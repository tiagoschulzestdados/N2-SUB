#include <stdio.h>
#include <stdlib.h>

struct noArv {
	int info;
	struct noArv* esq;
	struct noArv* dir;
};

typedef struct noArv NoArv;


NoArv* cria(void)
{
	return NULL;
}

void imprime(NoArv* a)
{
	if (a != NULL) {
		printf("%d \n", a->info); /* mostra raiz */
		imprime(a->esq); /* mostra sae */
		imprime(a->dir); /* mostra sad */
	}
}



NoArv* busca(NoArv* r, int v)
{
	if (r == NULL)
		return NULL;
	else if (r->info > v)
		return busca(r->esq, v);
	else if (r->info < v)
		return busca(r->dir, v);
	else return r;
}



NoArv* insere(NoArv* a, int v)
{
	if (a == NULL) {
		a = (NoArv*)malloc(sizeof(NoArv));
		a->info = v;
		a->esq = a->dir = NULL;
		printf(" %d \n", a->info);
	}

	if (v < a->info) {
		a->esq = insere(a->esq, v);
	}
	else if (v > a->info) {
		a->dir = insere(a->dir, v);
	}
	return a;
}

// No Folha nao tem ninguem pendurado

NoArv* libera(NoArv* a, int v) {
	if (a != NULL) {

		if (a->info == v) {
			// remove nós folhas, nós sem filhos
			if (a->esq == NULL && a->dir == NULL) {
				free(a);
				return NULL;
			}
			else {
				// remove nós que possuem apenas 1 filho
				if (a->esq != NULL || a->dir != NULL) {
					NoArv* aux;
					if (a->esq != NULL) {
						if (a->esq->info > v)
							aux = a->esq;
						else {
							aux = a->dir;
							aux->esq = a->esq;
						}
					}
					else {
						if (a->dir->info > v)
							aux = a->dir;
						else
							aux = a->esq;
					}

					free(a);
					return aux;
				}
				else {
					NoArv* aux = a->esq;
					while (a->dir != NULL)
						aux = aux->dir;

					a->info = aux->info;
					aux->info = v;
					a->esq = libera(a->esq, v);
					return a;
				}
			}
		}
		else {

			if (v < a->info)
				a->esq = libera(a->esq, v);
			else
				a->dir = libera(a->dir, v);

			return a;
		}

	}
	return NULL;
}


int main() {
	NoArv* noArv;

	noArv = cria();

	noArv = insere(noArv, 6);
	noArv = insere(noArv, 4);
	noArv = insere(noArv, 8);
	noArv = insere(noArv, 2);
	noArv = insere(noArv, 5);
	noArv = insere(noArv, 1);
	noArv = insere(noArv, 3);
	noArv = insere(noArv, 7);
	noArv = insere(noArv, 9);

	printf("Imprime.... \n");
	imprime(noArv);


	NoArv* noArv5;
	noArv5 = busca(noArv, 5);
	printf(" BUSCA %d  %p \n", noArv5->info, noArv5);

	NoArv* noArv2;
	noArv2 = busca(noArv, 2);
	printf(" BUSCA %d  %p \n", noArv2->info, noArv2);

	NoArv* noArv7;
	noArv7 = busca(noArv, 7);
	printf(" BUSCA %d  %p \n", noArv7->info, noArv7);



	printf("Libera 4... \n");
	noArv = libera(noArv, 4);


	printf("Libera 9... \n");
	noArv = libera(noArv, 9);

	printf("Imprime.... \n");
	imprime(noArv);


	//imprime(noArv);
}