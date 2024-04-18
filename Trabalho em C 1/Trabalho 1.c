#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAMANHO 5000

void adicionarEspacoNoFinal(char *str){
	int tam = strlen(str);
	str[tam] = ' ';
	str[tam+1] = '\0';
}

void abrirEspaco(char *str, int pos_inicial, int espaco, int ao){ ////a função recebe a string, a posição inicial, o tamanho do espaço a ser aberto, e as strings a serem substituidas.
	char* novaString = (char *)calloc(TAMANHO, sizeof(char));//Calloc coloca \0 em todos os espaços em branco.
	int i; 
	for(i=0; i<pos_inicial; i++){//Preencho a novaString com os caracteres da string original antes do espaço
		novaString[i] = str[i];
	}
	for(i=pos_inicial; i<pos_inicial+espaco; i++){//Abro o espaço.
		novaString[i] = ' ';
	}
	i = pos_inicial;
	while(str[i] != '\0'){//Prencho a novaString, apos o espaco, com os caracteres da string original. 
		novaString[i+espaco] = str[i+ao]; //Observe que o +2 é o "ao", logo só estarei adicionando os caracteres apos ele.
		i++;
	}
	strcpy(str, novaString);
}

char espelho(char caractere){
	int distanciaA = caractere - 'a';//calculo a distancia do caractere em relação ao a.
	int espelho = 'a'+('z' - 'a' - distanciaA);
	return espelho;//Sendo a = 97, z = 122 e considerando distanciaA = 0.
}										// 97+(122-97-0) = 122, justamente a posição de z, que varia de acordo com a distanciaA.

void vaiDeMao(char *str){
	int i;
	int tam = strlen(str);
	for(i=0; i<tam; i++){
		if(str[i] == 'a' && str[i+1] == 'o'){
			abrirEspaco(str, i, 3, 2);//i está como a posição do espaço a ser aberto(pos_inicial).
			str[i] = 'T';
			str[i+1] = 's';
			str[i+2] = 'é';
		}
		else if(str[i] == 'o' && str[i+1] == 'a'){
			abrirEspaco(str, i, 4, 2);
			str[i] = 'T';
			str[i+1] = 'u';
			str[i+2] = 'n';
			str[i+3] = 'g';
		}
	}
}

void chinaDividida(char *str){
	int i;
	int contC = 0;
	int contT = 0;
	int tam = strlen(str);
	char china[10] = "China";
	char taiwan[10] = "Taiwan";
	for(i=0; i<tam; i++){ //Percorre a string, se achar os caracters c/t sera incrementado 1 no contC ou no counT.
		if(str[i] == 'c' || str[i] == 'C'){
			contC++;
		}
		else if(str[i] == 't' || str[i] == 'T'){
			contT++;
		}
	}
	//Se tiver mais (ou igual quantidade) letras ‘c’ do que ‘t’, coloca “China” no início e no final da substring e “Taiwan” no meio
	if(contC >= contT){
		abrirEspaco(str, (tam/2), 6, 0); //observe que tam/2 representa a metade da string.
		str[(tam/2)] = 'T';
		str[(tam/2)+1] = 'a';
		str[(tam/2)+2] = 'i';
		str[(tam/2)+3] = 'w';
		str[(tam/2)+4] = 'a';
		str[(tam/2)+5] = 'n'; //Coloca "Taiwan" no meio da string apos abrir o espaço.
		
		abrirEspaco(str, 0, 5, 0); //a função recebe a string, a posição inicial, o tamanho do espaço a ser aberto, e as strings a serem substituidas.
		str[0] = 'C'; //Coloca china no inicio da string apos abrir o espaço.
		str[1] = 'h';
		str[2] = 'i';
		str[3] = 'n';
		str[4] = 'a';
		
		strcat(str, china);//Coloca china no final da string.
	}
	else if(contC < contT){//Se tiver mais letras ‘t’ do que ‘c’, coloca “Taiwan” no início e no final da substring e “China” no meio.
		abrirEspaco(str, (tam/2), 5, 0); 
		str[(tam/2)] = 'C'; //Coloca china no meio apos abrir o espaço.
		str[(tam/2)+1] = 'h';
		str[(tam/2)+2] = 'i';
		str[(tam/2)+3] = 'n';
		str[(tam/2)+4] = 'a';
		
		abrirEspaco(str, 0, 6, 0);
		str[0] = 'T'; //Coloca Taiwan no meio da string apos abrir o espaço.
		str[1] = 'a';
		str[2] = 'i';
		str[3] = 'w';
		str[4] = 'a';
		str[5] = 'n';
		
		strcat(str, taiwan);//Coloca taiwan no final da string.
	}
}
 
void espelhoTai(char *str){
	int tam = strlen(str);
	int i;
	for(i=0; i<tam; i++){
		str[i] = espelho(str[i]);
	}
	str[tam+1] = '\0';
}

void inversao2a2(char *str){
	char guardarCaractere;
	int i;
	int tam = strlen(str);
	for(i=0; i<tam; i+=2){//O i ira pular de 2 em 2 por conta do par de caracteres.
		guardarCaractere = str[i];
		str[i] = str[i+1];
		str[i+1] = guardarCaractere;
	}
	if(tam %2 != 0){ //Se o tamanho da substring for impar ele ira fazer a inversão do ultimo caractere novamente.
		guardarCaractere = str[tam-1];
		str[tam-1] = str[tam];
		str[tam] = guardarCaractere;
	}
	str[tam+1] = '\0';
}

void quaseJuncao(char *str){
	vaiDeMao(str);
	chinaDividida(str);	
	inversao2a2(str);
}

void descriptografaVaiDeMao(char *str){
	int i;
	int tam = strlen(str);
	for(i=0; i<tam; i++){
		if(str[i] == 'T' && str[i+1] == 's' && str[i+2] == 'é'){
			abrirEspaco(str, i, 2, 3);//i está como a posição do espaço a ser aberto(pos_inicial).
			str[i] = 'a';
			str[i+1] = 'o';
		}
		else if(str[i] == 'T' && str[i+1] == 'u' && str[i+2] == 'n' && str[i+3] == 'g'){
			abrirEspaco(str, i, 2, 4);
			str[i] = 'o';
			str[i+1] = 'a';
		}
	}
}	

void descriptografaChinaDividida(char *str){
	int i;
	int contC = 0;
	int contT = 0;
	int tam = strlen(str);
	for(i=0; i<tam; i++){ //Percorre a string, se achar os caracters c/t sera incrementado 1 no contC ou no counT.
		if(str[i] == 'c' || str[i] == 'C'){
			contC++;
		}
		else if(str[i] == 't' || str[i] == 'T'){
			contT++;
		}
	}
	//Se tiver mais (ou igual quantidade) letras ‘c’ do que ‘t’, coloca “China” no início e no final da substring e “Taiwan” no meio
	if(contC >= contT){
		abrirEspaco(str, (tam-5), 0, 5);
		abrirEspaco(str, 0, 0, 5);
		tam = strlen(str);
		abrirEspaco(str, ((tam/2)-3), 0, 6);//Observe que (tam/2)-3 é a metade da string menos metade de taiwan.
	}
	else if(contC < contT){//Se tiver mais letras ‘t’ do que ‘c’, coloca “Taiwan” no início e no final da substring e “China” no meio.
		abrirEspaco(str, (tam-6), 0, 6);
		abrirEspaco(str, 0, 0, 6);
		tam = strlen(str);
		abrirEspaco(str, ((tam/2)-2), 0, 5);//Observe que (tam/2)-2 é a metade da string menos metade de china.
	}
}

void descriptografaQuasejuncao(char *str){
	inversao2a2(str);
	descriptografaChinaDividida(str);
	descriptografaVaiDeMao(str);
}

int* posicaoDosEspacos(char *str, int *quantSubstrings){
	int* espacos = (int *)malloc(TAMANHO *sizeof(int));
	int i;
	int j = 0;
	int tamStr = strlen(str);
	for(i=0; i<tamStr; i++){
		if(str[i] == ' '){
			espacos[j] = i;//Adiciono mais a posição do espaço
			j++;
			*quantSubstrings+=1;//para cada espaço eu incremento 1.
		}
	}
	espacos[j] = tamStr;//Adiciono no vetor a posição do \0 tambem.
	*quantSubstrings+=1;
	return espacos;
}

char* dividirString(char *str, int espacos, int *percorrerString){
	char* substring = (char *)malloc(TAMANHO *sizeof(char));
	int i;
	int j = 0;
	for(i=*percorrerString; i<espacos; i++){ //O for i ira iniciar a partir da posição que parou na string.
		substring[j] = str[i];
		substring[j+1] = '\0';//Coloco o \0 no final
		j++;
	}
	*percorrerString = i+1; //o i é onde parou na string original. Adiciona mais um para pular para a string posterior.
	return substring; 
}

char* lerdados(){
	char* string = (char *)malloc(TAMANHO *sizeof(char));
	printf("Insira a mensagem:\n");
	gets(string);
	return string;
}

char* criptografaDados(char* mensagem){
	char* novaString = (char *)malloc(TAMANHO *sizeof(char));
	novaString[0] = '\0';
	char* substring = (char *)malloc(TAMANHO *sizeof(char));
	int* espacos = (int *)malloc(TAMANHO *sizeof(int));//Aloco um vetor para guardar a posição de cada espaço.
	int quantSubstrings=0; //A quantidade de substrings sera passada pela função posicaoDosEspacos
	espacos = posicaoDosEspacos(mensagem, &quantSubstrings);//Com essa função eu guardo em um vetor as posições de cada espaço na string + \0.
	int percorrerString = 0;
	int i = 0;
	int contCriptografia = 0;
	
	while(i < quantSubstrings){//esse while vai se repetir pela quantidade de substrings. Enquando que o i ira percorrer o vetor de espaços.
		substring = dividirString(mensagem, espacos[i], &percorrerString);//Mando a mensagem, o vetor de espaços e a variavel que percorre a string.
		if(contCriptografia==0){ //Se o i for igual a 0 significa que é a primeira substring, e assim por diante...
			vaiDeMao(substring);
			adicionarEspacoNoFinal(substring);//Adiciono um espaço no final da substring tendo em vista que estou ignorando o espaço durante a criptografia.
		}
		else if(contCriptografia==1){
			chinaDividida(substring);
			adicionarEspacoNoFinal(substring);
		}
		else if(contCriptografia==2){
			espelhoTai(substring);
			adicionarEspacoNoFinal(substring);
		}
		else if(contCriptografia==3){
			inversao2a2(substring);
			adicionarEspacoNoFinal(substring);
		}
		else if(contCriptografia==4){
			quaseJuncao(substring);
			adicionarEspacoNoFinal(substring);
		}
		i++;
		strcat(novaString, substring);//Adiciono a substring a novaString.
		contCriptografia++;
		if(contCriptografia >= 5){ //Se o contador for igual a 5 eu reseto para reiniciar a criptografia.
			contCriptografia = 0;
		}
	}
	novaString[strlen(novaString)-1] = '\0'; //Tiro o espaço no final da novastring.
	return novaString;
}

char* descriptografaDados(char* mensagemCriptografada){
	char* novaString = (char *)malloc(TAMANHO *sizeof(char));
	novaString[0] = '\0';
	char* substring = (char *)malloc(TAMANHO *sizeof(char));
	int* espacos = (int *)malloc(TAMANHO *sizeof(int));//Aloco um vetor para guardar a posição de cada espaço.
	int quantSubstrings=0; //A quantidade de substrings sera passada pela função posicaoDosEspacos
	espacos = posicaoDosEspacos(mensagemCriptografada, &quantSubstrings);//Com essa função eu guardo em um vetor as posições de cada espaço na string + o \0.
	int percorrerString = 0;
	int i = 0;
	int contCriptografia = 0;
	
	while(i < quantSubstrings){//esse while vai se repetir pela quantidade de substrings. Enquando que o i ira percorrer o vetor de espaços.
		substring = dividirString(mensagemCriptografada, espacos[i], &percorrerString);//Mando a mensagem, o vetor de espaços e a variavel que percorre a string.
		if(contCriptografia==0){ //Se o i for igual a 0 significa que é a primeira substring, e assim por diante...
			descriptografaVaiDeMao(substring);
			adicionarEspacoNoFinal(substring);
		}
		else if(contCriptografia==1){
			descriptografaChinaDividida(substring);
			adicionarEspacoNoFinal(substring);
		}
		else if(contCriptografia==2){
			espelhoTai(substring); //Mantenho a função espelho tai
			adicionarEspacoNoFinal(substring);
		}
		else if(contCriptografia==3){
			inversao2a2(substring); //Mantenho a função inversao2a2
			adicionarEspacoNoFinal(substring);
		}
		else if(contCriptografia==4){
			descriptografaQuasejuncao(substring);
			adicionarEspacoNoFinal(substring);
		}
		i++;
		strcat(novaString, substring);//Adiciono a substring a novaString.
		contCriptografia++;
		if(contCriptografia >= 5){ //Se o contador for igual a 5 eu reseto para reiniciar a criptografia.
			contCriptografia = 0;
		}
	}
	novaString[strlen(novaString)-1] = '\0'; //Tiro o espaço no final da novastring.
	return novaString;
}

int main(int argc, char *argv[]){
	setlocale(LC_ALL, "Portuguese");
	char* mensagem = lerdados();
	char* mensagemCriptografada = criptografaDados(mensagem);
	char* mensagemDescriptografada = descriptografaDados(mensagemCriptografada);
	printf("\nA string criptografada é:\n%s", mensagemCriptografada);
	printf("\n\nA string descriptografada é:\n%s", mensagemDescriptografada);
	return 0;
}
