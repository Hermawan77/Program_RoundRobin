// Nama : 1. Dicky Hermawan       (14116005)
//        2. Aditya Ricky Pratama (14116142)
// Tugas Besar membuat Round Robin menggunakan implementasi Linked List pada bahasa C

#include <stdio.h>
#include <stdlib.h>

#define Nil NULL
#define boolean unsigned char
#define true 1
#define false 0


typedef int infotype;
typedef char infodata;
typedef struct TElmtList * address;
typedef struct TElmtList{
	address next;
	infodata infoname;
	infotype quanta;
}ElmtList;

typedef struct{
	address first;
}List;

#define InfoQ(P) (P)-> quanta
#define InfoN(P) (P)-> infoname
#define Next(P) (P)-> next
#define First(L) (L). first

boolean IsEmpty(List * L){
	return (First(*L)==Nil);
}

void CreateEmpty(List * L){
	First(*L)==Nil;
}

address Alokasi(infotype X, infodata Y){
	address P;
	P = (address) malloc (sizeof(ElmtList));
	if(P!=Nil){
		InfoQ(P) = X;
		InfoN(P) = Y;
		Next(P) = Nil;
		return P;
	}
}

void Dealokasi(address * P){
	free(*P);
}
/*
void InserAfter(List * L, address P, address Prec){
	Next(P) = Next(Prec);
	Next(Prec) = P;
}
*/
void InsertFirst(List * L, address P){
	address Q = First(*L);
	if(Q==Nil){
		First(*L) = P;
		Next(P) = P;
	}
	else{
		Next(P) = Q;
		while(Next(Q)!=First(*L)){
		Q = Next(Q);
	}
		First(*L) = P;
		Next(Q) = P;
	}
}

address Search(List L, infodata X){
	address P = First(L);
	if(!IsEmpty(&L)){
		if(InfoN(P)>=X){
			return Nil;
		}
		else{
			while(Next(P)!=First(L) && InfoN(Next(P))<X){
				P = Next(P);
			}
			return P;
		}
	}
	else{
		return Nil;
	}
}

void InsertUrut(List * L, infotype X, infodata Y){
	address P = Alokasi(X,Y),Q;
	if(P!=Nil){
		Q = Search (*L, Y);
		if(Q!=Nil){
			InsertAfter(L,P,Q);
		}
		else{
			InsertAfter(L,P);
		}
	}
}

void CetakList(List L){
	address P;
	P = First(L);
	printf("Data : \n");
	printf("+-----------+---------+\n");
	printf("|\tData\t|\tQuanta\t|\n");
	printf("+-----------+---------+\n");
	if(IsEmpty(&L)){
		
	}
	else{
		while(Next(P)!=First(L)){
			printf("|\t%c\t|%d\t|\n", InfoN(P), InfoQ(P));
			P = Next(P);
}
	printf("|\t%c\t|%d\t|\n", InfoN(P), InfoQ(P));
}
	printf("+-----------+---------+\n");
}

address SearchPrec(List L){
	address P;
	address Prec;
	P = Prec = First(L);
	while(Next(P)!=First(L)){
		Prec = Next(Prec);
	}
	while(Next(P)!=First(L)){
		if(InfoQ(P)<=0){
			return Prec;
		}
		Prec = P;
		P = Next(P);
	}
	return Prec;
}

void DelVFirst(List * L, infotype * X){
	address P;
	address Q;
	P = Q = First(*L);
	*X = InfoQ(P);
	if(Next(P) == P){
		First(*L) = Nil;
	}
	else{
		while(Next(P)!=First(*L)){
			P = Next(P);
		}
		First(*L) = Next(P) = Next(First(*L));
	}
	free(Q);
}

void Dispose(List * L, address * P){
	address Q;
	infotype X;
	Q = SearchPrec(*L);
	if(InfoQ(First(*L))<=0){
		DelVFirst(L,&X);
	}
	else{
		*P = Next(Q);
		X = InfoQ(*P);
		Next(Q) = Next(Next(Q));
		Next(*P) = Nil;
	}
}
/*
void RoundRobin(List * L, address *P, infotype Quantum){
	int TotQntm = 0;
	int Switch = 1;
	address Q;
	*P = First(*L);
	printf("Proses >> \n");
	printf("+-----------+---------+\n");
	printf("|\tData\t|\tQuanta\t|\n");
	printf("+-----------+---------+\n");
	while(!IsEmpty(L)){
		if(Next(*P) == *P){
			if(InfoQ(*P)>0){
				printf("|   %c\t\t", InfoN(*P));
				printf("|   \t%d\t| >>", Quantum);
				printf(" %c : ", InfoN(*P));
				InfoQ(*P) == Quantum;
				printf(" = %d", InfoQ(*P));
				if(InfoQ(*P)<=0){
					printf(". Dispose %c\n", InfoN(*P));
					Q = *P;
					Dispose(L,&Q);
				}
				else{
					printf("\n");
				}
			}
		
		TotQntm += Quantum;
		}
		else if(P!=Nil){
			printf("| %c\t\t", InfoN(*P));
			printf("| \t%d\t >>", Quantum);
			printf(" %c : ", InfoN(*P));
			InfoQ(*P) = Quantum;
			printf(" = %d", InfoQ(*P));
			if(InfoQ(*P)>0){
				printf("\n");
				printf("| Switch \t| \t%d \t|\n", Switch);
				Q = *P;
				*P = Next(*P);
				Dispose(L, &Q);
			}
			TotQntm += Quantum + Switch;
		}
	printf("+------------+----------__+\n");
	printf("|Total Quantum : \t%d\t|\n", TotQntm);
	printf("+------------+----------__+\n");
}

*/
int main(){
	address P;
	List L;
	infodata Data;
	infotype Quantum;
	int Quanta, N, i, a;
	char Pilih;
	CreateEmpty(&L);
	printf("Jumlah Data\t\t: ");
	scanf("%d", &N);
	printf("Quantum Per Proses\t: ");
	scanf("%d", Quantum);
	
	for(i=1;i<=N;i++){
		printf("\nSimpul #%d\n", i);
		printf("Data #%d : ", i);
		scanf("%c", &Data);
		printf("Quanta #%d : ", i);
		scanf("%d", &Quanta);
		InsertUrut(&L, Quanta, Data);
	}
	CetakList(L);
//	RoundRobin(&L, &P, Quantum);
}
