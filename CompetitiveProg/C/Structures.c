#include <stdio.h>
#include <malloc.h>

typedef struct person {
  char *name;
  struct person *father;
  struct person *mother;
  struct kidlist *kidlist;
} person;

typedef struct kidlist {
  struct person *kid;
  struct kidlist *next;
} kidlist;

person * makeperson(char *name,
		    person *father,
		    person *mother)
{
  person *p;
  p = (person *) malloc(sizeof (person));
  p->name = name;
  p->father = father;
  p->mother = mother;
  p->kidlist = NULL;
  if(father) {
    kidlist *knode;
    knode = (kidlist *) malloc(sizeof (kidlist));
    knode->kid = p;
    knode->next =  father->kidlist;
    father->kidlist = knode;
  }
  if(mother) {
    kidlist *knode;
    knode = (kidlist *) malloc(sizeof (kidlist));
    knode->kid = p;
    knode->next =  mother->kidlist;
    mother->kidlist = knode;
  }
  return p;
}

void printkids( kidlist * k ) {
  while(k) {
    printf(" Kid named: %s\n", k->kid->name);
    k = k->next;
  }
}

void printperson( person * p )
{
  printf("person at address %p:\n", p);
  printf(" name: %s\n", p->name);
  printf(" father address:%p mother address:%p\n", p->father, p->mother);
  if(p->father) {
    printf(" father's name:%s\n", p->father->name);
  }
  else {
    printf(" no father.\n");
  }
  if(p->mother) {
    printf(" mother's name:%s\n", p->mother->name);
  }
  else {
    printf(" no mother.\n");
  }
  printkids( p->kidlist );
  printf("\n");
}

void removeperson( person * p)
{
  /* You write! */
}
    
int main() {
  struct person *adam;
  struct person *eve;
  struct person *cain;
  struct person *abel;

  adam = makeperson("Adam", NULL, NULL);
  eve = makeperson("Eve", NULL, NULL);
  cain = makeperson("Cain", adam, eve);
  abel = makeperson("Abel", adam, eve);

  printperson(adam);
  printperson(eve);
  printperson(cain);
  printperson(abel);

  removeperson( abel );

  printf("Data after removeperson( abel ):\n");

  printperson(adam);
  printperson(eve);
  printperson(cain);
  printperson(abel);

  
  return 0;

}
