#include "objects.h"


GLfloat white[] = {1.0, 1.0, 1.0};
GLfloat black[] = {0.2, 0.2, 0.2};
GLfloat yellow[] = {1.0, 1.0, 0.0};

// ////////////////////////////////
// VBO
// ////////////////////////////////


Object vboBar(Texture flooring, Texture wall, Texture sand, Texture columns, Texture metal,Texture ceiling, Texture glass) {

	int nObjects = 18;
	Object bar;
	bar.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);

	// Base
	int lBase = 128;
	int cBase = 256;
	int aBase = 2;

	// Parede
	int aParede = 32;


	//Base
	bar.primitivas[0] = vboFloor(lBase*8, cBase*4, sand, lBase/8);
	// Chao
	// Tecto lado direito
	bar.primitivas[1] = vboParalelo(lBase, cBase/4, aBase, flooring);
	bar.primitivas[2] = vboParalelo(lBase/2, 3 * (cBase/4), aBase, flooring);

	//Tecto lado esquerdo frente
	bar.primitivas[3] = vboParalelo(lBase/2, cBase/4, aBase, flooring);

	//Tecto lado esquerdo trás
	bar.primitivas[4] = vboParalelo(lBase/4, cBase/4, aBase, flooring);
	bar.primitivas[5] = vboParalelo(lBase/4, 3*lBase/8, aBase, flooring);


	// Parede Traseira
	bar.primitivas[6] = vboParalelo(aParede, cBase,aBase, wall);

	// Parede Esquerda     
	bar.primitivas[7] = vboParalelo(aParede, 62*aBase,aBase, wall);

	//Parede Esq Frente
	// bar.primitivas[5]= vboParalelo(aParede, cBase/4,aBase, wall);
	bar.primitivas[8]= vboParalelo(aParede, (lBase/8),aBase, wall);
	bar.primitivas[9] = vboParalelo(aParede, lBase/8,aBase/2,glass);

	//Parede Direita Adjacente à Parede Esq Frente
	//Tamanho da parede menos a grossura
	//bar.primitivas[15]= vboParalelo(aParede, (cBase/4)-2*aBase,aBase, flooring);
	bar.primitivas[10]= vboParalelo(aParede, (124*aBase)/4,aBase, wall);

	//Parede Direita
	bar.primitivas[11]= vboParalelo(aParede, (120*aBase)/4,aBase, wall);

	//Parede frente esplanada
	// bar.primitivas[6]= vboParalelo(aParede, (6*cBase)/8, aBase,flooring);
	bar.primitivas[12]= vboParalelo(aParede, lBase/4, aBase,wall);
	bar.primitivas[13]= vboParalelo(aParede, lBase/2, aBase/2,glass);
	bar.primitivas[14]= vboParalelo(aParede, lBase/4 + aBase, aBase/2,glass);

	//2º Andar
	bar.primitivas[15]= vboParalelo(lBase/4, cBase, aBase, ceiling);
	bar.primitivas[16]= vboParalelo(lBase/4, lBase/2, aBase, ceiling);

	//Colunas
	bar.primitivas[17] = vboCilindro(3, 2 ,3*aParede/4, 1, columns);

	return bar;
}

Object vboBarreira(float comp, Texture texture){
	int nObjects = 2;
	// Base
	int aBase = 2;

	// Parede
	int aParede = 32;
	Object barreira;

	barreira.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);

	barreira.primitivas[0] = vboParalelo(aParede/6,aBase,aBase,texture);

	barreira.primitivas[1] = vboCilindro(20,2,comp,1,texture);

	barreira.size = nObjects;

	return barreira;   
}

Object vboCorrimao(float comp, Texture texture){
	int nObjects = 3;
	// Base

	// Parede
	int aParede = 32;
	Object corrimao;

	corrimao.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);

	corrimao.primitivas[0] = vboParalelo(aParede/4 +8,1,1,texture);

	corrimao.primitivas[1] = vboCilindro(20,1,comp,0.5,texture);
	corrimao.primitivas[2] = vboParalelo(aParede/4 +3,1,1,texture);

	corrimao.size = nObjects;

	return corrimao;
}

Object vboEscada(Texture texture){
	int nObjects = 1;

	// Parede
	int aParede = 32;
	Object escada;

	escada.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);

	escada.primitivas[0] = vboParalelo(aParede/2 + 3,4,1,texture);

	escada.size = nObjects;

	return escada;   
}

Object vboElements(float comp, float larg, Texture power) {
	int nObjects = 1;

	// Parede
	Object elem;

	elem.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);

	elem.primitivas[0] = vboPlano(comp,larg,power);

	elem.size = nObjects;

	return elem;
}

Object vboBalcao(Texture texture) {
	int nObjects = 2;

	// Parede
	int aParede = 32;
	Object balcao;

	balcao.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);

	balcao.primitivas[0] = vboParalelo(aParede/4,60,4,texture);
	balcao.primitivas[1] = vboParalelo(aParede/2 -4,50,4,texture);

	balcao.size = nObjects;

	return balcao;
}

// /////////////////////
// Glasses
// /////////////////////

Object vboMartini(int fatias, float alturaBase, float alturaPe, float alturaCone, float raioBase, float raioPe, float raioCone, Texture texture){
	int nObjects = 5;
	float border = (raioCone*0.2)/5;
	Object copo;

	copo.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	copo.vars = (float *)malloc(sizeof(float)*2);

	copo.primitivas[0] = vboConeOpenInv(fatias, 2, alturaCone, raioCone - border, raioPe - border, texture);

	copo.primitivas[1] = vboConeOpen(fatias, 2, alturaCone, raioCone, raioPe, texture);

	copo.primitivas[2] = vboBorder(fatias, alturaCone/2, raioCone, border, texture);

	copo.primitivas[3] = vboCilindro(fatias, 2, alturaPe, raioPe, texture);

	copo.primitivas[4] = vboCilindro(fatias, 1, alturaBase, raioBase, texture);

	copo.size = nObjects;

	copo.vars[0] = alturaCone;
	copo.vars[1] = alturaPe;

	return copo;
}

Object vboTallGlass(int fatias, int gomos, float altura, float raio, Texture texture){
	float border = (raio*0.2)/5;
	int nObjects = 3;
	Object copo;

	copo.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);

	// Inside
	copo.primitivas[0] = vboCilindroOpenInv(fatias, gomos, altura, raio - border, texture);

	copo.primitivas[1] = vboCilindroOpen(fatias, gomos, altura, raio, texture);

	copo.primitivas[2] = vboBorder(fatias, altura/2, raio, border, texture);

	copo.size = nObjects;

	return copo;
}

Object vboMartiniStick(float fatias, float alturaStick, float raioStick, float raioAzeitona, Texture olive, Texture stick){
	int nObjects = 2;
	Object copo;

	copo.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	copo.vars = (float *)malloc(sizeof(float)*1);

	// Inside
	copo.primitivas[0] = vboCilindro(fatias, 2, alturaStick, raioStick, stick);

	copo.primitivas[1] = vboEsfera(fatias, 10, raioAzeitona, olive);

	copo.size = nObjects;

	copo.vars[0] = alturaStick;

	return copo;
}

Object vboCaneca(float fatias, float raioI, float raioO, float raioCaneca, float alturaCaneca, Texture texture){
	int nObjects = 4;
	float border = (raioCaneca*0.8)/5;
	Object copo;

	copo.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	copo.vars = (float *)malloc(sizeof(float)*4);

	copo.primitivas[0] = vboTorusHalf(fatias, raioI, raioO, texture);

	copo.primitivas[1] = vboCilindroOpen(fatias, 1, alturaCaneca, raioCaneca, texture);

	copo.primitivas[2] = vboCilindroOpenInv(fatias, 1, alturaCaneca, raioCaneca-border, texture);

	copo.primitivas[3] = vboBorder2(fatias, alturaCaneca/2, raioCaneca, border, texture);

	copo.size = nObjects;

	copo.vars[0] = raioCaneca;
	copo.vars[1] = raioI;
	copo.vars[2] = raioO;
	copo.vars[3] = border;

	return copo;
}

Object vboCerveja(float fatias, float gomos, float alturaBase, float raioBase, float raioBaseTopo, float alturaCopo, float raioCopo, Texture glass, Texture beer){
	int nObjects = 4;
	float border = (raioCopo*0.2)/5;
	Object copo;

	copo.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	copo.vars = (float *)malloc(sizeof(float)*2);

	copo.primitivas[0] = vboCone(fatias, 1, alturaBase, raioBaseTopo, raioBase, glass);

	copo.primitivas[1] = vboConeOpen(fatias, gomos, alturaCopo, raioCopo, raioBaseTopo, beer);

	copo.primitivas[2] = vboConeOpenInv(fatias, gomos, alturaCopo, raioCopo-border, raioBaseTopo-border, beer);

	copo.primitivas[3] = vboBorder(fatias, alturaCopo/2, raioCopo, border, glass);

	copo.size = nObjects;

	copo.vars[0] = alturaCopo;
	copo.vars[1] = alturaBase;

	return copo;
}

Object vboGlassWater(int fatias, float raio, float alturaPe, float alturaBase, float larguraBase, Texture texture){
	int nObjects = 4;
	Object copo;

	copo.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	copo.vars = (float *)malloc(sizeof(float)*3);

	copo.primitivas[0] = vboEsferaCopoInv(fatias, fatias, raio-0.01, texture);

	copo.primitivas[1] = vboEsferaCopo(fatias, fatias, raio, texture);

	copo.primitivas[2] = vboCilindro(fatias, 4, alturaPe, 0.03, texture);

	copo.primitivas[3] = vboCilindro(fatias, 4, alturaBase, larguraBase, texture);

	copo.size = nObjects;

	
	copo.vars[0] = raio;
	copo.vars[1] = alturaPe;
	copo.vars[2] = alturaBase;

	return copo;
}

// /////////////////////
// Candeeiros
// /////////////////////

Object vboCandeeiroTeto(int fatias, int gomos, float alturaFio, float alturaBase, float raioBase, float raioEsfera, Texture base, Texture luz){
	int nObjects = 3;
	Object candeeiro;

	candeeiro.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	candeeiro.vars = (float *)malloc(sizeof(float)*3);

	// Base
	candeeiro.primitivas[0] = vboCilindro(fatias, 1, alturaBase, raioBase, base);

	// Fio
	candeeiro.primitivas[1] = vboCilindro(fatias/2, 1, alturaFio, 0.05, base);

	// Esfera
	candeeiro.primitivas[2] = vboEsfera(fatias, gomos,raioEsfera, luz);

	candeeiro.vars[0] = alturaFio;
	candeeiro.vars[1] = alturaBase;
	candeeiro.vars[2] = raioEsfera;

	return candeeiro;
}

Object vboCandeeiroChao(int fatias, float alturaBase, float raioBase, float alturaFio, float larguraTopo, float alturaTopo, Texture base, Texture luz, Texture lampada){
	int nObjects = 6;
	Object candeeiro;
	float border = (larguraTopo*0.2)/5;

	candeeiro.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	candeeiro.vars = (float *)malloc(sizeof(float)*3);

	candeeiro.primitivas[0] = vboCilindro(fatias, 4, alturaBase, raioBase, base);

	candeeiro.primitivas[1] = vboCilindroOpen(fatias, 4, alturaFio, 0.2, base);

	candeeiro.primitivas[2] = vboCilindroOpen(fatias, 4, alturaTopo, larguraTopo, luz);

	candeeiro.primitivas[3] = vboCilindroOpenInv(fatias, 4, alturaTopo, larguraTopo-border, luz);

	candeeiro.primitivas[4] = vboBorder2(fatias, alturaTopo/2, larguraTopo, border, luz);

	candeeiro.primitivas[5] = vboEsfera(10, 10, 1.5, lampada);

	candeeiro.vars[0] = alturaFio;
	candeeiro.vars[1] = alturaBase;
	candeeiro.vars[2] = alturaTopo;

	return candeeiro;
}

Object vboCandeeiroTetoCilindro(int fatias, int gomos, float alturaFio, float alturaBase, float raioBase, float altura, float raio, Texture base, Texture luz, Texture lampp){
	int nObjects = 6;
	Object candeeiro;
	float border = (raio*0.2)/5;

	candeeiro.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	candeeiro.vars = (float *)malloc(sizeof(float)*3);

	// Base
	candeeiro.primitivas[0] = vboCilindro(fatias, 1, alturaBase, raioBase, base);

	// Fio
	candeeiro.primitivas[1] = vboCilindroOpen(fatias/2, gomos, alturaFio, 0.2, base);

	candeeiro.primitivas[2] = vboCilindroOpen(fatias, gomos, altura, raio, luz);

	candeeiro.primitivas[3] = vboCilindroOpenInv(fatias, 5, altura, raio-border, luz);

	candeeiro.primitivas[4] = vboBorder2(fatias, altura/2, raio, border, luz);

	candeeiro.primitivas[5] = vboEsfera(10, 10, 2.5, lampp);

	candeeiro.vars[0] = alturaFio;
	candeeiro.vars[1] = alturaBase;
	candeeiro.vars[2] = altura;

	return candeeiro;
}

Object vboFoco(int cubo, Texture texture) {
	int nObjects = 1;
	Object candeeiro;

	candeeiro.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);

	candeeiro.primitivas[0] = vboParalelo(cubo, cubo, cubo, texture);

	return candeeiro;
}

Object vboLamp(int size, Texture texture) {
	int nObjects = 1;
	Object candeeiro;

	candeeiro.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);

	candeeiro.primitivas[0] = vboEsfera(10, 10, size, texture);

	return candeeiro;
}

// /////////////////////
// Mesas
// /////////////////////

Object vboMesaCafe (float raioTampo, float alturaTampo, int numPernas, float raioPerna, float alturaPerna, Texture texture) {

	int nObjects = 2;
	float nVars = 5;

	Object mesa;
	mesa.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	mesa.vars = (float *)malloc(sizeof(float)*nVars);

	//Tampo
	mesa.primitivas[0] = vboCilindro(20, 5, alturaTampo, raioTampo, texture);

	//Pernas
	mesa.primitivas[1] = vboCilindro(20, 5, alturaPerna, raioPerna, texture);

	//Variaveis
	mesa.vars[0] = numPernas;
	mesa.vars[1] = alturaTampo;
	mesa.vars[2] = alturaPerna;
	mesa.vars[3] = raioTampo;
	mesa.vars[4] = raioPerna;

	return mesa;
}

Object vboMesaVidro (float compTampo, float largTampo, float altTampo, float altPerna, float largPerna, float compBase, float altBase, Texture perna, Texture tampo){

	int nObjects = 8;
	float nVars = 6;
	Object mesa;
	mesa.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	mesa.vars = (float *)malloc(sizeof(float)*nVars);

	//Tampo
	mesa.primitivas[0] = vboParalelo(altTampo, compTampo, largTampo, tampo);

	//Perna
	mesa.primitivas[1] = vboParalelo(altPerna, largPerna, largPerna, perna);

	//Bases
	mesa.primitivas[2] = vboParalelo(altBase, 1.5*largPerna, 1.5*largPerna, perna);
	mesa.primitivas[3] = vboParalelo(altBase, compBase, compBase, perna);

	//Apoios do Tampo
	mesa.primitivas[4] = vboParalelo(altTampo/3, compTampo/2 - largPerna/2 - altTampo/2, altTampo/2, perna);
	mesa.primitivas[5] = vboParalelo(altTampo/3, altTampo/2, largTampo/2 - largPerna/2 - altTampo/2, perna);
	mesa.primitivas[6] = vboParalelo(altTampo/3, altTampo/2, largTampo/3, perna);
	mesa.primitivas[7] = vboParalelo(altTampo/3, compTampo/3, altTampo/2, perna);
	
	//Variaveis
	mesa.vars[0] = compTampo;
	mesa.vars[1] = largTampo;
	mesa.vars[2] = altTampo;
	mesa.vars[3] = altPerna;
	mesa.vars[4] = largPerna;
	mesa.vars[5] = altBase;

	return mesa;
}

Object vboMesaVidroR (float raioTampo, float altTampo, float altPerna, float largPerna, float compBase, float altBase, Texture perna, Texture tampo) {

	int nObjects = 8;
	float nVars = 5;
	Object mesa;
	mesa.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	mesa.vars = (float *)malloc(sizeof(float)*nVars);

	//Tampo
	mesa.primitivas[0] = vboCilindro(20, 5, altTampo, raioTampo, tampo);

	//Perna
	mesa.primitivas[1] = vboParalelo(altPerna, largPerna, largPerna, perna);

	//Bases
	mesa.primitivas[2] = vboParalelo(altBase, 1.5*largPerna, 1.5*largPerna, tampo);
	mesa.primitivas[3] = vboParalelo(altBase, compBase, compBase, tampo);

	//Apoios do Tampo
	mesa.primitivas[4] = vboParalelo(altTampo/3, raioTampo - largPerna/2 - altTampo/2 - altTampo/3, altTampo/2, tampo);
	mesa.primitivas[5] = vboParalelo(altTampo/3, altTampo/2, raioTampo - largPerna/2 - altTampo/2 - altTampo/3, tampo);
	mesa.primitivas[6] = vboParalelo(altTampo/3, altTampo/2, raioTampo/3, tampo);
	mesa.primitivas[7] = vboParalelo(altTampo/3, raioTampo/3, altTampo/2, tampo);
	
	//Variaveis
	mesa.vars[0] = raioTampo;
	mesa.vars[1] = altTampo;
	mesa.vars[2] = altPerna;
	mesa.vars[3] = largPerna;
	mesa.vars[4] = altBase;

	return mesa;
}

Object vboEsplanadaPequena(float c, float p, Texture perna, Texture tampo) {

	int nObjects = 4;
	float nVars = 2;
	Object mesa;

	float eachBar = p /6;

	mesa.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	mesa.vars = (float *)malloc(sizeof(float)*nVars);

	//tampo
	mesa.primitivas[0] = vboParalelo(0.15, c, eachBar ,tampo);

	//barras baixo do tampo
	mesa.primitivas[1] = vboParalelo(0.25, eachBar /2, c, tampo);
	
	//pernas
	mesa.primitivas[2] = vboParalelo(c, eachBar/5, eachBar /2, perna);

	//barras baixo
	mesa.primitivas[3] = vboParalelo(0.2, c - eachBar, 0.03, tampo);

	//Variaveis
	mesa.vars[0] = c;
	mesa.vars[1] = p;

	return mesa;
}

Object vboMesaEsplanada(float compBase, float largBase, float altBase, int numTamposBase, float altTampos, float compTampos, float altPerna, float compPerna, float largPerna, Texture pernas, Texture tampo) {

	int nObjects = 6;
	float nVars = 9;
	Object mesa;
	mesa.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	mesa.vars = (float *)malloc(sizeof(float)*nVars);

	//Base
	mesa.primitivas[0] = vboParalelo(altBase, largBase, altBase, pernas);
	mesa.primitivas[1] = vboParalelo(altBase, compBase -altBase*2, altBase, pernas);

	//Tampos da Base
	mesa.primitivas[2] = vboParalelo(altTampos, largBase, compTampos, tampo);

	//Pernas
	mesa.primitivas[3] = vboParalelo(altPerna, largPerna, compPerna, pernas);

	//Apoio Base
	mesa.primitivas[4] = vboParalelo(altBase/2, largBase -largPerna*2 , compPerna , pernas);
	mesa.primitivas[5] = vboParalelo(altBase/2, compBase - 2*largPerna, compPerna, pernas);

	//Variaveis
	mesa.vars[0] = compBase;
	mesa.vars[1] = largBase;
	mesa.vars[2] = altBase;
	mesa.vars[3] = numTamposBase;
	mesa.vars[4] = altTampos;
	mesa.vars[5] = compTampos;
	mesa.vars[6] = altPerna;
	mesa.vars[7] = compPerna;
	mesa.vars[8] = largPerna;

	return mesa;
}

// /////////////////////
// Cadeiras
// /////////////////////

Object vboCadeiraSimples (float compTampo, float altTampo, float profTampo, float compPerna, float altPerna, float profPerna, float raioFerrinho, float altFerrinho, float compEncosto, float profEncosto, Texture texture) {

	int nObjects = 4;
	float nVars = 9;
	Object cadeira;
	cadeira.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	cadeira.vars = (float *)malloc(sizeof(float)*nVars);

	//Tampo
	cadeira.primitivas[0] = vboParalelo(altTampo ,compTampo ,profTampo, texture);
	
	//Pernas
	cadeira.primitivas[1] = vboParalelo(altPerna,compPerna,profPerna, texture);

	//Ferrinhos
	cadeira.primitivas[2] = vboCilindro(20, 5, altFerrinho, raioFerrinho, texture);

	//Encosto
	cadeira.primitivas[3] = vboParalelo(altFerrinho/2, compEncosto, profEncosto, texture);

	//Variaveis
	cadeira.vars[0] = compTampo;
	cadeira.vars[1] = altTampo;
	cadeira.vars[2] = profTampo;
	cadeira.vars[3] = compPerna;
	cadeira.vars[4] = altPerna;
	cadeira.vars[5] = profPerna;
	cadeira.vars[6] = raioFerrinho;
	cadeira.vars[7] = altFerrinho;
	cadeira.vars[8] = profEncosto;

	return cadeira;
}

Object vboCadeiraSimplesTabuas(float compTampo, float altTampo, float profTampo, float compPerna, float altPerna, float altEncosto, float compEncosto, int numEncosto, Texture texture) {

	int nObjects = 7;
	float nVars = 8;
	Object cadeira;
	cadeira.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	cadeira.vars = (float *)malloc(sizeof(float)*nVars);

	//Tampo
	cadeira.primitivas[0] = vboParalelo(altTampo, compTampo, profTampo, texture);
	
	//Pernas
	cadeira.primitivas[1] = vboParalelo(altPerna, compPerna, compPerna, texture);

	//Barras Encostadas ao Tampo 
	//Barras Laterais e do Meio
	cadeira.primitivas[2] = vboParalelo(compPerna*0.75, compPerna, compTampo -3*compPerna, texture);
	cadeira.primitivas[3] = vboParalelo(compPerna*0.75, compPerna, profTampo -3*compPerna, texture);

	//Barras Verticas das Costas
	cadeira.primitivas[4] = vboParalelo(altEncosto , compPerna, compPerna, texture);

	//Barras Lateral das Costas
	cadeira.primitivas[5] = vboParalelo(compPerna*0.75, compTampo -compPerna, compPerna, texture);

	//Encostos
	cadeira.primitivas[6] = vboParalelo(compEncosto, compTampo -3*compPerna, compPerna/2, texture);

	//Variaveis
	cadeira.vars[0] = compTampo;
	cadeira.vars[1] = altTampo;
	cadeira.vars[2] = profTampo;
	cadeira.vars[3] = compPerna;
	cadeira.vars[4] = altPerna;
	cadeira.vars[5] = altEncosto;
	cadeira.vars[6] = compEncosto;
	cadeira.vars[7] = numEncosto;

	return cadeira;
}

Object vboBanco(float raioTampo, float altTampo, float altPerna, float largPerna, float tamBeira, float largBeira, float largBarra, Texture texture) {

	int nObjects = 6;
	float nVars = 5;
	Object cadeira;
	cadeira.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	cadeira.vars = (float *)malloc(sizeof(float)*nVars);

	//Tampo
	cadeira.primitivas[0] = vboCilindro(20, 5, altTampo, raioTampo, texture);
	
	//Pernas
	cadeira.primitivas[1] = vboParalelo(altPerna, largPerna, largPerna, texture);

	//Beiras encostadas ao Tampo e Barra das Pernas
	cadeira.primitivas[2] = vboParalelo(tamBeira, 2*raioTampo*sin(M_PI/4) -1.7*largPerna, largBeira, texture);
	cadeira.primitivas[3] = vboParalelo(largBarra, 2*raioTampo*sin(M_PI/4) -1.7*largPerna, largBarra, texture);
	cadeira.primitivas[4] = vboParalelo(tamBeira, 2*raioTampo*sin(M_PI/4) -2*largPerna, largBeira, texture);
	cadeira.primitivas[5] = vboParalelo(largBarra, 2*raioTampo*sin(M_PI/4) -2*largPerna, largBarra, texture);

	//Variaveis
	cadeira.vars[0] = raioTampo;
	cadeira.vars[1] = altTampo;
	cadeira.vars[2] = altPerna;
	cadeira.vars[3] = largPerna;
	cadeira.vars[4] = tamBeira;

	return cadeira;
}

Object vboBancoI(float raioTampo, float altTampo, float altPerna, float largPerna, float inclinacao, float tamBeira, float largBeira, float largBarra, Texture perna, Texture almofada) {

	int nObjects = 4;
	float nVars = 7;
	Object cadeira;
	cadeira.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	cadeira.vars = (float *)malloc(sizeof(float)*nVars);

	//Tampo
	cadeira.primitivas[0] = vboCilindro(20, 5, altTampo, raioTampo, perna);
	
	//Pernas
	cadeira.primitivas[1] = vboParalelo(altPerna, largPerna, largPerna, almofada);

	//Beiras encostadas ao Tampo e Barra das Pernas
	cadeira.primitivas[2] = vboParalelo(tamBeira, 2*raioTampo*sin(M_PI/4) -2*largPerna, largBeira, almofada);
	cadeira.primitivas[3] = vboParalelo(largBarra, 2*raioTampo*sin(M_PI/4) -1.3*largPerna, largBarra, almofada);

	//Variaveis
	cadeira.vars[0] = raioTampo;
	cadeira.vars[1] = altTampo;
	cadeira.vars[2] = altPerna;
	cadeira.vars[3] = largPerna;
	cadeira.vars[4] = inclinacao;
	cadeira.vars[5] = tamBeira;
	cadeira.vars[6] = largBarra;

	return cadeira;
}

Object vboBancoQ(float compTampo, float largTampo, float altTampo, float altPerna, float largPerna, float tamBeira, float largBeira, float largBarra, Texture texture) {

	int nObjects = 4;
	float nVars = 7;
	Object cadeira;
	cadeira.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	cadeira.vars = (float *)malloc(sizeof(float)*nVars);

	//Tampo
	cadeira.primitivas[0] = vboParalelo(altTampo, compTampo, largTampo, texture);
	
	//Pernas
	cadeira.primitivas[1] = vboParalelo(altPerna, largPerna, largPerna, texture);

	//Beiras encostadas ao Tampo e Barra das Pernas
	cadeira.primitivas[2] = vboParalelo(tamBeira, largBeira, largTampo - 2*largPerna, texture);
	cadeira.primitivas[3] = vboParalelo(tamBeira, compTampo - 2*largPerna, largBeira, texture);

	//Variaveis
	cadeira.vars[0] = compTampo;
	cadeira.vars[1] = largTampo;
	cadeira.vars[2] = altTampo;
	cadeira.vars[3] = altPerna;
	cadeira.vars[4] = largPerna;
	cadeira.vars[5] = tamBeira;
	cadeira.vars[6] = largBeira;

	return cadeira;
}

Object vboBancoQI(float compTampo, float largTampo, float altTampo, float altPerna, float largPerna, float inclinacao, float tamBeira, float largBeira, float largBarra, Texture texture) {

	int nObjects = 6;
	float nVars = 8;
	Object cadeira;
	cadeira.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	cadeira.vars = (float *)malloc(sizeof(float)*nVars);

	//Tampo
	cadeira.primitivas[0] = vboParalelo(altTampo, compTampo, largTampo, texture);
	
	//Pernas
	cadeira.primitivas[1] = vboParalelo(altPerna, largPerna, largPerna, texture);

	//Beiras encostadas ao Tampo e Barra das Pernas
	cadeira.primitivas[2] = vboParalelo(tamBeira, largBeira, largTampo - 2.5*largPerna, texture);
	cadeira.primitivas[3] = vboParalelo(tamBeira, largBeira, largTampo - 1.5*largPerna, texture);
	cadeira.primitivas[4] = vboParalelo(tamBeira, compTampo - 2*largPerna, largBeira, texture);
	cadeira.primitivas[5] = vboParalelo(tamBeira, compTampo - 1.5*largPerna, largBeira, texture);

	//Variaveis
	cadeira.vars[0] = compTampo;
	cadeira.vars[1] = largTampo;
	cadeira.vars[2] = altTampo;
	cadeira.vars[3] = altPerna;
	cadeira.vars[4] = largPerna;
	cadeira.vars[5] = inclinacao;
	cadeira.vars[6] = tamBeira;
	cadeira.vars[7] = largBeira;

	return cadeira;
}

Object vboBancoRedondo(float raioTampo, float altTampo, float raioPerna, float altPerna, Texture texture) {

	int nObjects = 2;
	float nVars = 2;
	Object cadeira;
	cadeira.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	cadeira.vars = (float *)malloc(sizeof(float)*nVars);

	//Tampo
	cadeira.primitivas[0] = vboCilindro(20, 5, altTampo, raioTampo, texture);
	
	//Base
	cadeira.primitivas[1] = vboCilindro(20, 5, altPerna, raioPerna, texture);

	//Variaveis
	cadeira.vars[0] = altTampo;
	cadeira.vars[1] = altPerna;

	return cadeira;
}

Object vboCadeiraDecor(float compBase, float largBase, float altBase, int numTamposBase, float altTampos, float compTampos, float altPerna, float compPerna, float largPerna, float altBracos, float difTampoeCostas, float altCostas, float compCostas, float largCostas, int numTamposCostas, Texture esqueleto, Texture tampo) {

	int nObjects = 12;
	float nVars = 15;
	Object cadeira;
	cadeira.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	cadeira.vars = (float *)malloc(sizeof(float)*nVars);

	//Base
	cadeira.primitivas[0] = vboParalelo(altBase, largBase, altBase, esqueleto);
	cadeira.primitivas[1] = vboParalelo(altBase, compBase, altBase, esqueleto);

	//Tampos da Base
	cadeira.primitivas[2] = vboParalelo(altTampos, largBase, compTampos, tampo);

	//Pernas
	cadeira.primitivas[3] = vboParalelo(altPerna, largPerna, compPerna, esqueleto);

	//Bracos
	cadeira.primitivas[4] = vboParalelo(altBracos, largPerna, compPerna, esqueleto);
	cadeira.primitivas[5] = vboParalelo(largPerna ,largPerna , compBase -compPerna, esqueleto);

	//Apoio Base
	cadeira.primitivas[6] = vboParalelo(altBase/2, largBase, altBase, esqueleto);
	cadeira.primitivas[7] = vboParalelo(altBase/2, altBase, compBase -3*compPerna, esqueleto);
	cadeira.primitivas[8] = vboParalelo(largCostas, largCostas, compPerna/2 + altBase + largCostas + difTampoeCostas, esqueleto);

	//Base Costas
	cadeira.primitivas[9] = vboParalelo(altCostas, largCostas, largCostas, esqueleto);
	cadeira.primitivas[10] = vboParalelo(largCostas, compCostas, largCostas, esqueleto);

	//Tampos das costas
	cadeira.primitivas[11] = vboParalelo(altTampos, compCostas, compTampos, tampo);

	//Variaveis
	cadeira.vars[0] = compBase;
	cadeira.vars[1] = largBase;
	cadeira.vars[2] = altBase;
	cadeira.vars[3] = numTamposBase;
	cadeira.vars[4] = altTampos;
	cadeira.vars[5] = compTampos;
	cadeira.vars[6] = altPerna;
	cadeira.vars[7] = compPerna;
	cadeira.vars[8] = largPerna;
	cadeira.vars[9] = altBracos;
	cadeira.vars[10] = difTampoeCostas;
	cadeira.vars[11] = altCostas;
	cadeira.vars[12] = compCostas;
	cadeira.vars[13] = largCostas;
	cadeira.vars[14] = numTamposCostas;

	return cadeira;
}

Object vboCadeiraDecorX(float compBase, float largBase, float altBase, int numTamposBase, float altTampos, float compTampos, float altPerna, float compPerna, float largPerna, float altBracos, float difTampoeCostas, float altCostas, float compCostas, float largCostas, int numTamposCostas, Texture esqueleto, Texture tampo) {

	int nObjects = 12;
	float nVars = 15;
	Object cadeira;
	cadeira.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	cadeira.vars = (float *)malloc(sizeof(float)*nVars);

	//Base
	cadeira.primitivas[0] = vboParalelo(altBase, largBase, altBase, esqueleto);
	cadeira.primitivas[1] = vboParalelo(altBase, compBase, altBase, esqueleto);

	//Tampos da Base
	cadeira.primitivas[2] = vboParalelo(altTampos, largBase, compTampos, tampo);

	//Pernas
	cadeira.primitivas[3] = vboParalelo(altPerna, largPerna, compPerna, esqueleto);

	//Bracos
	cadeira.primitivas[4] = vboParalelo(altBracos, largPerna, compPerna, esqueleto);
	cadeira.primitivas[5] = vboParalelo(largPerna ,largPerna , compBase -compPerna, esqueleto);

	//Apoio Base
	cadeira.primitivas[6] = vboParalelo(altBase/2, largBase, altBase, esqueleto);
	cadeira.primitivas[7] = vboParalelo(altBase/2, altBase, compBase -3*compPerna, esqueleto);
	cadeira.primitivas[8] = vboParalelo(largCostas, largCostas, compPerna/2 + altBase + largCostas + difTampoeCostas, esqueleto);

	//Base Costas
	cadeira.primitivas[9] = vboParalelo(altCostas, largCostas, largCostas, esqueleto);
	cadeira.primitivas[10] = vboParalelo(largCostas, compCostas, largCostas, esqueleto);

	//Tampos das costas
	cadeira.primitivas[11] = vboParalelo(altTampos, compCostas, compTampos, tampo);

	//Variaveis
	cadeira.vars[0] = compBase;
	cadeira.vars[1] = largBase;
	cadeira.vars[2] = altBase;
	cadeira.vars[3] = numTamposBase;
	cadeira.vars[4] = altTampos;
	cadeira.vars[5] = compTampos;
	cadeira.vars[6] = altPerna;
	cadeira.vars[7] = compPerna;
	cadeira.vars[8] = largPerna;
	cadeira.vars[9] = altBracos;
	cadeira.vars[10] = difTampoeCostas;
	cadeira.vars[11] = altCostas;
	cadeira.vars[12] = compCostas;
	cadeira.vars[13] = largCostas;
	cadeira.vars[14] = numTamposCostas;

	return cadeira;
}

Object vboCadeiraDecorInc(float compBase, float largBase, float altBase, int numTamposBase, float altTampos, float compTampos, float altPerna, float compPerna, float largPerna, float altBracos, float difTampoeCostas, float altCostas, float compCostas, float largCostas, int numTamposCostas, float inclinacao, Texture texture) {

	int nObjects = 12;
	float nVars = 16;
	Object cadeira;
	cadeira.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	cadeira.vars = (float *)malloc(sizeof(float)*nVars);

	//Base
	cadeira.primitivas[0] = vboParalelo(altBase, largBase, altBase, texture);
	cadeira.primitivas[1] = vboParalelo(altBase, compBase, altBase, texture);

	//Tampos da Base
	cadeira.primitivas[2] = vboParalelo(altTampos, largBase, compTampos, texture);

	//Pernas
	cadeira.primitivas[3] = vboParalelo(altPerna, largPerna, compPerna, texture);

	//Bracos
	cadeira.primitivas[4] = vboParalelo(altBracos, largPerna, compPerna, texture);
	cadeira.primitivas[5] = vboParalelo(largPerna ,largPerna , compBase -compPerna, texture);

	//Apoio Base
	cadeira.primitivas[6] = vboParalelo(altBase/2, largBase, altBase, texture);
	cadeira.primitivas[7] = vboParalelo(altBase/2, altBase, compBase -3*compPerna, texture);
	cadeira.primitivas[8] = vboParalelo(largCostas, largCostas, compPerna/2 + altBase + largCostas + difTampoeCostas, texture);

	//Base Costas
	cadeira.primitivas[9] = vboParalelo(altCostas, largCostas, largCostas, texture);
	cadeira.primitivas[10] = vboParalelo(largCostas, compCostas, largCostas, texture);

	//Tampos das costas
	cadeira.primitivas[11] = vboParalelo(altTampos, compCostas, compTampos-0.2, texture);

	//Variaveis
	cadeira.vars[0] = compBase;
	cadeira.vars[1] = largBase;
	cadeira.vars[2] = altBase;
	cadeira.vars[3] = numTamposBase;
	cadeira.vars[4] = altTampos;
	cadeira.vars[5] = compTampos;
	cadeira.vars[6] = altPerna;
	cadeira.vars[7] = compPerna;
	cadeira.vars[8] = largPerna;
	cadeira.vars[9] = altBracos;
	cadeira.vars[10] = difTampoeCostas;
	cadeira.vars[11] = altCostas;
	cadeira.vars[12] = compCostas;
	cadeira.vars[13] = largCostas;
	cadeira.vars[14] = numTamposCostas;
	cadeira.vars[15] = inclinacao;

	return cadeira;
}

Object vboCadeiraFashion(float compTampo, float largTampo, float altTampo, float altCostas, float largCostas, float altPerna, float largPerna, float altBraco, Texture esqueleto, Texture almofada) {

	int nObjects = 7;
	float nVars = 8;

	Object cadeira;
	cadeira.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	cadeira.vars = (float *)malloc(sizeof(float)*nVars);

	//Tampo
	cadeira.primitivas[0] = vboParalelo(largTampo, compTampo, altTampo, almofada);
	
	//Costas    
	cadeira.primitivas[1] = vboParalelo(altCostas, compTampo, largCostas, almofada);

	//Pernas
	cadeira.primitivas[2] = vboParalelo(largPerna, altPerna, largPerna, esqueleto);
	cadeira.primitivas[3] = vboParalelo(largPerna, compTampo, largPerna, esqueleto);
	cadeira.primitivas[4] = vboParalelo(largPerna, largTampo - largPerna*2, largPerna , esqueleto);
	
	//Bracos
	cadeira.primitivas[5] = vboParalelo(altBraco, largPerna, largPerna, esqueleto);
	cadeira.primitivas[6] = vboParalelo(largPerna, largPerna, largTampo - largPerna, esqueleto);
	
	//Variaveis
	cadeira.vars[0] = compTampo;
	cadeira.vars[1] = largTampo;
	cadeira.vars[2] = altTampo;
	cadeira.vars[3] = altCostas;
	cadeira.vars[4] = largCostas;
	cadeira.vars[5] = altPerna;
	cadeira.vars[6] = largPerna;
	cadeira.vars[7] = altBraco;

	return cadeira;
}

Object vboSofa(float compBase, float largBase, float altBase, float altLateral, float largLateral, float altCostas, float largCostas, int numAlmofadas, float compAlmofada, float grossAlmofada, float altApoio, float grossApoio, Texture almofada, Texture corpo) {

	int nObjects = 9;
	float nVars = 12;
	Object cadeira;
	cadeira.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	cadeira.vars = (float *)malloc(sizeof(float)*nVars);

	///Base
	cadeira.primitivas[0] = vboParalelo(altBase, largBase, altBase, corpo);
	cadeira.primitivas[1] = vboParalelo(altBase, compBase, altBase, corpo);
	
	//Laterais
	cadeira.primitivas[2] = vboParalelo(altLateral, largLateral, compBase  + 2*altBase, corpo);
	
	//Costas
	cadeira.primitivas[3] = vboParalelo(altCostas, largBase, largCostas, corpo);
	
	//Almofada Base
	cadeira.primitivas[4] = vboParalelo(grossAlmofada, largBase/numAlmofadas, compAlmofada, almofada);
	
	//Almofada Costas
	cadeira.primitivas[5] = vboParalelo(compAlmofada -grossAlmofada, largBase/numAlmofadas, grossAlmofada, almofada);
	
	//Apoios Frente e Tras
	cadeira.primitivas[6] = vboParalelo(altApoio, largBase + 0.5*largLateral, grossApoio, corpo);
	cadeira.primitivas[7] = vboParalelo(altApoio, 0.5*largLateral, grossApoio*2, corpo);
	
	//Apoios Laterais
	cadeira.primitivas[8] = vboParalelo(altApoio, grossApoio, compBase  + 2*altBase - 6*grossApoio, corpo);


	//Variaveis
	cadeira.vars[0] = compBase;
	cadeira.vars[1] = largBase;
	cadeira.vars[2] = altBase;
	cadeira.vars[3] = altLateral;
	cadeira.vars[4] = largLateral;
	cadeira.vars[5] = altCostas;
	cadeira.vars[6] = largCostas;
	cadeira.vars[7] = numAlmofadas;
	cadeira.vars[8] = compAlmofada;
	cadeira.vars[9] = grossAlmofada;
	cadeira.vars[10] = altApoio;
	cadeira.vars[11] = grossApoio;

	return cadeira;
}

Object vboGuardaSol(float fatias, float gomos, float alturaCone, float raioCone, float raioVarao, float alturaVarao, Texture varao, Texture topo){

	float nObjects = 4;
	float border = (raioCone*0.2)/5;
	Object guardaSol;

	guardaSol.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	guardaSol.vars = (float *)malloc(sizeof(float)*2);

	guardaSol.primitivas[0] = vboConeOpenInv(fatias, gomos, alturaCone, raioCone - border, 0.0, topo);

	guardaSol.primitivas[1] = vboConeOpen(fatias, gomos, alturaCone, raioCone, 0.0, topo);

	guardaSol.primitivas[2] = vboBorder(fatias, alturaCone/2, raioCone, border, topo);

	guardaSol.primitivas[3] = vboCilindro(20, 10, alturaVarao, raioVarao, varao);

	guardaSol.vars[0] = alturaCone;
	guardaSol.vars[1] = alturaVarao;

	return guardaSol;
}

Object vboPassadeira(int total, int rotacao, float altura, float largura, float comprimento, Texture texture) {

	float nObjects = 1;
	float nVars = 3;
	Object passadeira;

	passadeira.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	passadeira.vars = (float *)malloc(sizeof(float)*nVars);

	passadeira.primitivas[0] = vboParalelo(altura, largura, comprimento, texture);

	passadeira.vars[0] = total;
	passadeira.vars[1] = rotacao;
	passadeira.vars[2] = comprimento;

	return passadeira;
}

Object vboBolaPraia(float fatias, float gomos, float raio, Texture texture) {

	int nObjects = 1;
	float nVars = 1;

	Object bolaPraia;
	bolaPraia.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	bolaPraia.vars = (float *)malloc(sizeof(float)*nVars);

	//Bola
	bolaPraia.primitivas[0] = vboEsfera(fatias, gomos, raio, texture);

	//Variaveis
	bolaPraia.vars[0] = raio;

	return bolaPraia;
}

Object vboToalhaPraia (float angulo, float altura, float largura, float comprimento, Texture texture) {

	int nObjects = 1;
	float nVars = 2;

	Object toalha;
	toalha.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	toalha.vars = (float *)malloc(sizeof(float)*nVars);

	//Bola
	toalha.primitivas[0] = vboParalelo(altura, largura, comprimento, texture);

	//Variaveis
	toalha.vars[0] = angulo;
	toalha.vars[1] = altura;

	return toalha;
}

Object vboQuadro(float altura, float largura, float comprimento, Texture texture) {

	int nObjects = 1;
	float nVars = 1;

	Object quadro;
	quadro.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	quadro.vars = (float *)malloc(sizeof(float)*nVars);

	quadro.primitivas[0] = vboParalelo(altura, largura, comprimento, texture);

	//Variaveis
	quadro.vars[0] = altura;

	return quadro;
}

Object vboEstante(float altura, float largCostas, float grossEstante, float compLateral, float grossPrateleira, Texture texture) {

	int nObjects = 5;
	float nVars = 5;
	Object estante;
	estante.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
	estante.vars = (float *)malloc(sizeof(float)*nVars);

	//Costas
	estante.primitivas[0] = vboParalelo(altura, largCostas, grossEstante, texture);

	//Laterais
	estante.primitivas[1] = vboParalelo(altura, grossEstante, compLateral, texture);

	//Extremos
	estante.primitivas[2] = vboParalelo(grossEstante, largCostas, compLateral + 2*grossEstante, texture);

	//Baixo
	estante.primitivas[3] = vboParalelo(altura/2, largCostas/2 - grossEstante*2, compLateral -grossEstante, texture);

	//Prateleiras
	estante.primitivas[4] = vboParalelo(grossPrateleira, largCostas -4*grossEstante, compLateral + compLateral*0.1, texture);

	//Variaveis
	estante.vars[0] = altura;
	estante.vars[1] = largCostas;
	estante.vars[2] = grossEstante;
	estante.vars[3] = compLateral;
	estante.vars[4] = grossPrateleira;

	return estante;
}

Object vboGarrafa(float fatias, float altBase, float raioBase, float alt, float raioGarg, float altGargalo, Texture texture) {

    int nObjects = 6;
    float nVars = 3;
    float border = (raioGarg*0.2)/5;

    Object garrafa;
    garrafa.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
    garrafa.vars = (float *)malloc(sizeof(float)*nVars);

    //Base
    garrafa.primitivas[0] = vboCilindroOpen(fatias, 1, altBase, raioBase, texture);
    garrafa.primitivas[1] = vboCilindroOpenInv(fatias, 1, altBase, raioBase, texture);

    //Cima
    garrafa.primitivas[2] = vboConeOpen(fatias, 1, alt, raioGarg, raioBase, texture);

    //Gargalo
    garrafa.primitivas[3] = vboCilindroOpen(fatias, 1, altGargalo, raioGarg -border, texture);
    garrafa.primitivas[4] = vboCilindroOpenInv(fatias, 1, altGargalo, raioGarg -border, texture);

    //Borda
    garrafa.primitivas[5] = vboBorder2(fatias, 0, raioGarg, border, texture);

    //Variaveis
    garrafa.vars[0] = altBase;
    garrafa.vars[1] = alt;
    garrafa.vars[2] = altGargalo;

    return garrafa;
}

Object vboCaipiraBar(float alturaBalcao, float lado, Texture base,Texture apoio, Texture balcao, Texture tecto) {

    int nObjects = 6;
    float nVars = 2;
    Object caipira;

    caipira.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);
    caipira.vars = (float *)malloc(sizeof(float)*nVars);

    float cuboLado = 5;
    float profBalcao =3;

    //balcao frente
    caipira.primitivas[0] = vboParalelo(alturaBalcao, lado, profBalcao, base);

    //balcao direita
    caipira.primitivas[1] = vboParalelo(alturaBalcao, profBalcao, lado - profBalcao*2, base);

    //Barra esquerda
    caipira.primitivas[2] = vboParalelo(alturaBalcao/15, profBalcao, lado - profBalcao*2, base);

    //Cilindros
    caipira.primitivas[3] = vboCilindro(40, 20, 8, 0.5, apoio);

    //tecto
    caipira.primitivas[4] = vboParalelo(alturaBalcao/14, lado, lado, tecto);

    //movel centro
    caipira.primitivas[5] = vboParalelo(alturaBalcao +cuboLado/3, cuboLado *1.5, cuboLado, balcao);

    //Variaveis
    caipira.vars[0] = alturaBalcao;
    caipira.vars[1] = lado;

    return caipira;
}

// ////////////////////////////////
// Draw
// ////////////////////////////////

void drawBar(Object bar, Object barr1, Object barr2,Object barr3, Object barr4,Object escada,Object corrimao, Object balcao, Object power, Object air, Object sewer) {

	// Base
	int lBase = 128;
	int cBase = 256;
	int aBase = 2;

	// Parede
	int aParede = 32;

	//Base
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,white);
	glPushMatrix();
	drawVBO(bar.primitivas[0]);
	glPopMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,black);

	// Chao
	glPushMatrix();
	glTranslatef(-3*(cBase/8), 0, aBase/2);
	drawVBO(bar.primitivas[1]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cBase/8, lBase/4, aBase/2);
	drawVBO(bar.primitivas[2]);
	glPopMatrix();

	// Parede Traseira
	glPushMatrix();
	glTranslatef(0, lBase/2 - aBase/2, aParede/2 + aBase);
	glRotatef(90, 1, 0, 0);
	drawVBO(bar.primitivas[6]);
	glPopMatrix();

	// Parede Esquerda
	glPushMatrix();
	glTranslatef((-127*aBase)/2, 0, aParede/2 + aBase);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	drawVBO(bar.primitivas[7]);
	glPopMatrix();

	//Balcão
	glPushMatrix();
	glTranslatef(-96*aBase/2,-lBase/4,aParede/2);
	drawVBO(balcao.primitivas[0]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-91*aBase/2,-lBase/4,aParede/2 -8);
	glRotatef(90,1,0,0);
	// glTranslatef(0,-6,aParede/2 - aBase);
	drawVBO(balcao.primitivas[1]);
	glPopMatrix();

	//Parede Esq Frente
	glPushMatrix();
	glTranslatef(-9*lBase/16,-lBase/2 + aBase/2,aParede/2 + aBase);
	glRotatef(90,1,0,0);
	drawVBO(bar.primitivas[8]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15*lBase/16,-lBase/2 + aBase/2,aParede/2 + aBase);
	glRotatef(90,1,0,0);
	drawVBO(bar.primitivas[8]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-13*lBase/16,-lBase/2 + aBase/2,aParede/2 + aBase);
	glRotatef(90,1,0,0);
	drawVBO(bar.primitivas[9]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-11*lBase/16,-lBase/2 +aBase,aParede/2 + aBase);
	glRotatef(90,1,0,0);
	drawVBO(bar.primitivas[9]);
	glPopMatrix();

	
	//Parede Direita Adjacente à Parede Esq Frente
	glPushMatrix();
	// glTranslatef(-lBase/2,-cBase/8,aParede/2 + aBase);
	glTranslatef((-65*aBase)/2,(-124*aBase)/8,aParede/2 + aBase);
	glRotatef(90, 1, 0, 0);
	glRotatef(90,0,1,0);
	drawVBO(bar.primitivas[10]);
	glPopMatrix();


	//Parede frente esplanada
	glPushMatrix();
	glTranslatef(-3*lBase/8 - aBase,aBase/2,aParede/2 + aBase);
	glRotatef(90, 1, 0, 0);
	drawVBO(bar.primitivas[12]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(14*lBase/16,aBase/2,aParede/2 + aBase);
	glRotatef(90, 1, 0, 0);
	drawVBO(bar.primitivas[12]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-aBase,0.5,aParede/2 + aBase);
	glRotatef(90, 1, 0, 0);
	drawVBO(bar.primitivas[13]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5*lBase/8 -1,aBase/2,aParede/2 + aBase);
	glRotatef(90, 1, 0, 0);
	drawVBO(bar.primitivas[14]);
	glPopMatrix();

	//Parede direita
	glPushMatrix();
	glTranslatef((127*aBase)/2,lBase/4,aParede/2 + aBase);
	glRotatef(90,1,0,0);
	glRotatef(90,0,1,0);
	drawVBO(bar.primitivas[11]);
	glPopMatrix();

	// Tecto lado esquerdo frente
	glPushMatrix();
	// glTranslatef(-3*(cBase/8), 0, aParede + aBase);
	glTranslatef(-3*(cBase/8), -lBase/4, aParede + 3);
	drawVBO(bar.primitivas[3]);
	glPopMatrix();

	// Tecto lado esquerdo trás
	glPushMatrix();
	// glTranslatef(-3*(cBase/8), 0, aParede + aBase);
	glTranslatef((-3*cBase)/8, 6*lBase/16, aParede + 3);
	drawVBO(bar.primitivas[4]);
	glPopMatrix();

	//Escadas do topo para baixo

	//Escada 1
	glPushMatrix();
	glTranslatef(-lBase+6, 8*lBase/32 -2, aParede + 1);
	glRotatef(90,0,0,1);
	drawVBO(escada.primitivas[0]);
	glPopMatrix();

	// Escada 2
	glPushMatrix();
	glTranslatef(-lBase+6, 8*lBase/32 -5, aParede - 3);
	glRotatef(90,0,0,1);
	drawVBO(escada.primitivas[0]);
	glPopMatrix();

	//Escada 3
	glPushMatrix();
	glTranslatef(-lBase+6, 8*lBase/32 -8, aParede - 7);
	glRotatef(90,0,0,1);
	drawVBO(escada.primitivas[0]);
	glPopMatrix();

	//Escada 4
	glPushMatrix();
	glTranslatef(-lBase+6, 8*lBase/32 -11, aParede - 11);
	glRotatef(90,0,0,1);
	drawVBO(escada.primitivas[0]);
	glPopMatrix();

	//Escada 5
	glPushMatrix();
	glTranslatef(-lBase+6, 8*lBase/32 -14, aParede - 15);
	glRotatef(90,0,0,1);
	drawVBO(escada.primitivas[0]);
	glPopMatrix();

	//Escada 6
	glPushMatrix();
	glTranslatef(-lBase+6, 8*lBase/32 -17, aParede - 19);
	glRotatef(90,0,0,1);
	drawVBO(escada.primitivas[0]);
	glPopMatrix();

	//Escada 7
	glPushMatrix();
	glTranslatef(-lBase+6, 8*lBase/32 -20, aParede - 23);
	glRotatef(90,0,0,1);
	drawVBO(escada.primitivas[0]);
	glPopMatrix();

	//Escada 8
	glPushMatrix();
	glTranslatef(-lBase+6, 8*lBase/32 -23, aParede - 27);
	glRotatef(90,0,0,1);
	drawVBO(escada.primitivas[0]);
	glPopMatrix();

	//Corrimão
	glPushMatrix();
	// glTranslatef((-3*cBase)/8 -26,-lBase/2 + aBase/2,(9*aParede)/8 + 3);
	glTranslatef(-lBase+15.5, 8*lBase/32-28, aParede -22);
	glRotatef(90,1,0,0);
	drawVBO(corrimao.primitivas[0]);
	glPopMatrix();

	glPushMatrix();
	// glTranslatef((-3*cBase)/8,-lBase/2,(9*aParede)/8 + 10);
	glTranslatef(-lBase+15.5, 8*lBase/32 -15, aParede - 1);
	glRotatef(90,0,0,1);
	glRotatef(90,0,0,1);
	glRotatef(-45,1,0,0);
	glRotatef(-65,0,1,0);
	drawVBO(corrimao.primitivas[1]);
	glPopMatrix();

	glPushMatrix();
	// glTranslatef((-3*cBase)/8 +26,-lBase/2 + aBase/2,(9*aParede)/8 + 3);
	glTranslatef(-lBase+15.5, 8*lBase/32 +1, aParede + aBase+7);
	glRotatef(90,1,0,0);
	drawVBO(corrimao.primitivas[2]);
	glPopMatrix();

	glPushMatrix();
	// glTranslatef((-3*cBase)/8 -26,-lBase/2 + aBase/2,(9*aParede)/8 + 3);
	glTranslatef(-lBase+3, 8*lBase/32-28, aParede -22);
	glRotatef(90,1,0,0);
	drawVBO(corrimao.primitivas[0]);
	glPopMatrix();

	glPushMatrix();
	// glTranslatef((-3*cBase)/8,-lBase/2,(9*aParede)/8 + 10);
	glTranslatef(-lBase+3, 8*lBase/32 -15, aParede - 1);
	glRotatef(90,0,0,1);
	glRotatef(90,0,0,1);
	glRotatef(-45,1,0,0);
	glRotatef(-65,0,1,0);
	drawVBO(corrimao.primitivas[1]);
	glPopMatrix();

	glPushMatrix();
	// glTranslatef((-3*cBase)/8 +26,-lBase/2 + aBase/2,(9*aParede)/8 + 3);
	glTranslatef(-lBase+3, 8*lBase/32 +1, aParede + aBase+7);
	glRotatef(90,1,0,0);
	drawVBO(corrimao.primitivas[2]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((-11*lBase)/16, 2*lBase/16, aParede + 3);
	drawVBO(bar.primitivas[5]);
	glPopMatrix();

	//Tecto lado direito
	glPushMatrix();
	glTranslatef(cBase/8, lBase/4, aParede + 3);
	drawVBO(bar.primitivas[2]);
	glPopMatrix();

	//2º Andar
	glPushMatrix();
	glTranslatef(0, (3*lBase)/8, 4*aParede/2 - 3);
	drawVBO(bar.primitivas[15]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7*lBase/8, 0, 4*aParede/2 - 3);
	glRotatef(90,0,0,1);
	drawVBO(bar.primitivas[16]);
	glPopMatrix();

	//Colunas de suporte -> Da direita para a esquerda

	//Coluna fundo 1
	glPushMatrix();
	glTranslatef(cBase/2, (2*lBase)/4 -1, 6*aParede/4);
	glRotatef(90,1,0,0);
	drawVBO(bar.primitivas[17]);
	glPopMatrix();

	//Coluna frente 1
	glPushMatrix();
	glTranslatef(cBase/2, (2*lBase)/8 +1, 6*aParede/4);
	glRotatef(90,1,0,0);
	drawVBO(bar.primitivas[17]);
	glPopMatrix();

	//Protecção 1
	glPushMatrix();
	glTranslatef((3*cBase)/8 - 25,lBase/2 -1,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	// drawVBO(bar.primitivas[9]);
	drawVBO(barr1.primitivas[0]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((3*cBase)/8,lBase/2-1,(9*aParede)/8 + 6);
	glRotatef(90,0,0,1);
	// drawVBO(bar.primitivas[9]);
	drawVBO(barr1.primitivas[1]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((3*cBase)/8 + 25,lBase/2-1,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	drawVBO(barr1.primitivas[0]);
	glPopMatrix();

	//Coluna fundo 2
	glPushMatrix();
	glTranslatef(cBase/4, lBase/2 -1, 6*aParede/4);
	glRotatef(90,1,0,0);
	drawVBO(bar.primitivas[17]);
	glPopMatrix();

	//Coluna frente 2
	glPushMatrix();
	glTranslatef(cBase/4, (2*lBase)/8 +1, 6*aParede/4);
	glRotatef(90,1,0,0);
	drawVBO(bar.primitivas[17]);
	glPopMatrix();

	//Protecção 2
	glPushMatrix();
	glTranslatef(cBase/8 -25,lBase/2 -1,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	// drawVBO(bar.primitivas[9]);
	drawVBO(barr1.primitivas[0]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cBase/8,lBase/2 -1,(9*aParede)/8 + 6);
	glRotatef(90,0,0,1);
	// drawVBO(bar.primitivas[9]);
	drawVBO(barr1.primitivas[1]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cBase/8 +25,lBase/2 -1,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	// drawVBO(bar.primitivas[9]);
	drawVBO(barr1.primitivas[0]);
	glPopMatrix();

	//Coluna fundo 3
	glPushMatrix();
	glTranslatef(0, lBase/2 -1, 6*aParede/4);
	glRotatef(90,1,0,0);
	drawVBO(bar.primitivas[17]);
	glPopMatrix();

	//Coluna frente 3
	glPushMatrix();
	glTranslatef(0, (2*lBase)/8 +1, 6*aParede/4);
	glRotatef(90,1,0,0);
	drawVBO(bar.primitivas[17]);
	glPopMatrix();

	//Protecção 3
	glPushMatrix();
	glTranslatef(-cBase/8 -25,lBase/2 -1,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	// drawVBO(bar.primitivas[9]);
	drawVBO(barr1.primitivas[0]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-cBase/8,lBase/2 -1,(9*aParede)/8 + 6);
	glRotatef(90,0,0,1);
	// drawVBO(bar.primitivas[9]);
	drawVBO(barr1.primitivas[1]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-cBase/8 +25,lBase/2 -1,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	// drawVBO(bar.primitivas[9]);
	drawVBO(barr1.primitivas[0]);
	glPopMatrix();

	//Coluna fundo 4
	glPushMatrix();
	glTranslatef(-cBase/4, lBase/2 -1, 6*aParede/4);
	glRotatef(90,1,0,0);
	drawVBO(bar.primitivas[17]);
	glPopMatrix();

	//Coluna frente 4
	glPushMatrix();
	glTranslatef(-cBase/4, (2*lBase)/8 +1, 6*aParede/4);
	glRotatef(90,1,0,0);
	drawVBO(bar.primitivas[17]);
	glPopMatrix();

	//Protecção 4
	glPushMatrix();
	glTranslatef((-3*cBase)/8 - 25,lBase/2 -1,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	// drawVBO(bar.primitivas[9]);
	drawVBO(barr1.primitivas[0]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((-3*cBase)/8 - 1,lBase/2 -1,(9*aParede)/8 + 6);
	glRotatef(90,0,0,1);
	// drawVBO(bar.primitivas[9]);
	drawVBO(barr1.primitivas[1]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((-3*cBase)/8 + 25,lBase/2 -1,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	drawVBO(barr1.primitivas[0]);
	glPopMatrix();

	//Coluna fundo 5
	glPushMatrix();
	glTranslatef(-cBase/2, lBase/2 -1, 6*aParede/4);
	glRotatef(90,1,0,0);
	drawVBO(bar.primitivas[17]);
	glPopMatrix();

	//Coluna frente 5
	glPushMatrix();
	glTranslatef(-6*lBase/8 -1, (2*lBase)/8, 6*aParede/4);
	glRotatef(90,1,0,0);
	drawVBO(bar.primitivas[17]);
	glPopMatrix();

	//Coluna 6
	glPushMatrix();
	glTranslatef(-7*lBase/8 -12, -lBase/4 +1, 6*aParede/4);
	glRotatef(90,1,0,0);
	drawVBO(bar.primitivas[17]);
	glPopMatrix();

	//Coluna 7
	glPushMatrix();
	glTranslatef(-6*lBase/8 -1, -lBase/4 +1, 6*aParede/4);
	glRotatef(90,1,0,0);
	drawVBO(bar.primitivas[17]);
	glPopMatrix();

	//Protecção lado direito fundo
	glPushMatrix();
	glTranslatef(cBase/2 -1,(3*lBase)/8 +6,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	drawVBO(barr2.primitivas[0]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cBase/2 -1,(3*lBase)/8,(9*aParede)/8 + 6);
	// glTranslatef(-6,5,0);
	// glRotatef(90,0,0,1);
	drawVBO(barr2.primitivas[1]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cBase/2 -1,(3*lBase)/8 -6,(9*aParede)/8 + 2.5);
	// glTranslatef(-6,5,0);
	glRotatef(90,1,0,0);
	drawVBO(barr2.primitivas[0]);
	glPopMatrix();


	//Protecção lado esquerdo fundo
	glPushMatrix();
	glTranslatef(-cBase/2  +aBase/2,(3*lBase)/8 -25,(9*aParede)/8 + 6);
	drawVBO(barr4.primitivas[1]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-cBase/2 +aBase/2,(3*lBase)/8 -6,(9*aParede)/8 + 2.5);
	// glTranslatef(-6,5,0);
	glRotatef(90,1,0,0);
	drawVBO(barr4.primitivas[0]);
	glPopMatrix();

	//Protecção lado direito frente
	glPushMatrix();
	glTranslatef(cBase/2 -1,lBase/8 +6,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	drawVBO(barr2.primitivas[0]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cBase/2 -1,lBase/8,(9*aParede)/8 + 6);
	drawVBO(barr2.primitivas[1]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cBase/2 -1,lBase/8 -6,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	drawVBO(barr2.primitivas[0]);
	glPopMatrix();

	//Protecção frente esplanada
	glPushMatrix();
	glTranslatef(cBase/8 +80,lBase/32 - aBase,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	drawVBO(barr3.primitivas[0]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cBase/8,lBase/32 - aBase,(9*aParede)/8 + 6);
	glRotatef(90,0,0,1);
	drawVBO(barr3.primitivas[1]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cBase/8 -80,lBase/32 - aBase,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	drawVBO(barr3.primitivas[0]);
	glPopMatrix();


	//Protecção frente esquerda
	glPushMatrix();
	glTranslatef((-3*cBase)/8 -26,-lBase/2 + aBase/2,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	drawVBO(barr4.primitivas[0]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((-3*cBase)/8,-lBase/2 +1,(9*aParede)/8 + 6);
	glRotatef(90,0,0,1);
	drawVBO(barr4.primitivas[1]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((-3*cBase)/8 +26,-lBase/2 + aBase/2,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	drawVBO(barr4.primitivas[0]);
	glPopMatrix();

	//Protecção esquerda (lateral direita)
	glPushMatrix();
	glTranslatef(-cBase/4 -1,(-lBase)/4 +25,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	drawVBO(barr1.primitivas[0]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-cBase/4 -1,(-lBase)/4,(9*aParede)/8 + 6);
	glRotatef(90,0,1,0);
	drawVBO(barr1.primitivas[1]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-cBase/4 -1,(-lBase)/4 -25,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	drawVBO(barr1.primitivas[0]);
	glPopMatrix();

	//Protecção esquerda
	glPushMatrix();
	glTranslatef(-cBase/2 +aBase/2,(-lBase)/4 +27,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	drawVBO(barr1.primitivas[0]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-cBase/2 +aBase/2,(-lBase)/4,(9*aParede)/8 + 6);
	glRotatef(90,0,1,0);
	drawVBO(barr1.primitivas[1]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-cBase/2 +aBase/2,(-lBase)/4 -23,(9*aParede)/8 + 2.5);
	glRotatef(90,1,0,0);
	drawVBO(barr1.primitivas[0]);
	glPopMatrix();

	//Extras
	glPushMatrix();
	glTranslatef(-cBase/2 +10, lBase/2 +0.1,3*aBase);
	glRotatef(90, 1, 0, 0);
	glRotatef(180,0,1,0);
	drawVBO(power.primitivas[0]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-cBase/2 +10, lBase/2 +0.1,aParede - aBase);
	glRotatef(90, 1, 0, 0);
	glRotatef(180,0,1,0);
	drawVBO(air.primitivas[0]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-cBase/2 +aBase, lBase/2 +aBase,0.1);
	drawVBO(sewer.primitivas[0]);
	glPopMatrix();
}

// /////////////////////
// Mesa
// /////////////////////

void drawMesaCafe (Object mesa) {

	float i = 0.0f;
	float x, y, z;
	float angulo = (2*M_PI) / mesa.vars[0];

	glPushMatrix();
	glTranslatef(0, (mesa.vars[1] + mesa.vars[2])/2, 0);
	drawVBO(mesa.primitivas[0]);
	glPopMatrix();

	x = mesa.vars[3] - mesa.vars[4];
	y = 0.0f;
	z = mesa.vars[3] - mesa.vars[4];

	for (i = 0.0f; i < 2*M_PI; i+= angulo) {
		glPushMatrix();
		glTranslatef(x *sin(i), y, z *cos(i));
		drawVBO(mesa.primitivas[1]);
		glPopMatrix();
	}  
}

void drawMesaVidro (Object mesa){

	int i;
	float yP;
	float yBP, yBG;
	float xA1, yA, zA1;
	float xA2, zA2;

	//Tampo
	drawVBO(mesa.primitivas[0]);

	//Perna
	yP = mesa.vars[3]/2 + mesa.vars[2]/2;

	glPushMatrix();
	glTranslatef(0.0, -yP, 0.0);
	drawVBO(mesa.primitivas[1]);
	glPopMatrix();

	//Bases
	yBP = mesa.vars[3] + mesa.vars[2]/2 + mesa.vars[5]/2;

	glPushMatrix();
	glTranslatef(0.0, -yBP, 0.0);   
	drawVBO(mesa.primitivas[2]);
	glPopMatrix();

	yBG = mesa.vars[3] + mesa.vars[2]/2 + 1.5*mesa.vars[5];

	glPushMatrix();
	glTranslatef(0.0, -yBG, 0.0);   
	drawVBO(mesa.primitivas[3]);
	glPopMatrix();

	//Apoios do Tampo
	xA1 = mesa.vars[4]/2 + (mesa.vars[0]/2 - mesa.vars[4]/2 - mesa.vars[2]/2)/2;
	yA = mesa.vars[2]/2 + mesa.vars[2]/6;
	zA1 = mesa.vars[4]/2 + (mesa.vars[1]/2 - mesa.vars[4]/2 - mesa.vars[2]/2)/2;

	for (i = -1; i < 2; i+=2) {
		glPushMatrix();
		glTranslatef(i*xA1, -yA, 0.0);
		drawVBO(mesa.primitivas[4]);
		glPopMatrix();
	}

	for (i = -1; i < 2; i+=2) {
		glPushMatrix();
		glTranslatef(0.0, -yA, i*zA1);
		drawVBO(mesa.primitivas[5]);
		glPopMatrix();
	}

	xA2 = mesa.vars[4]/2 + (mesa.vars[0]/2 - mesa.vars[4]/2 - mesa.vars[2]/2) + mesa.vars[2]/4;
	zA2 = mesa.vars[4]/2 + (mesa.vars[1]/2 - mesa.vars[4]/2 - mesa.vars[2]/2) + mesa.vars[2]/4;

	for (i = -1; i < 2; i+=2) {
		glPushMatrix();
		glTranslatef(i*xA2, -yA, 0.0);
		drawVBO(mesa.primitivas[6]);
		glPopMatrix();
	}

	for (i = -1; i < 2; i+=2) {
		glPushMatrix();
		glTranslatef(0.0, -yA, i*zA2);
		drawVBO(mesa.primitivas[7]);
		glPopMatrix();
	}
}

void drawMesaVidroR (Object mesa) {

	int i;
	float yP;
	float yBP, yBG;
	float xA1, yA, zA1;
	float xA2, zA2;

	//Tampo
	drawVBO(mesa.primitivas[0]);

	//Perna
	yP = mesa.vars[2]/2 + mesa.vars[1]/2;

	glPushMatrix();
	glTranslatef(0.0, -yP, 0.0);
	drawVBO(mesa.primitivas[1]);
	glPopMatrix();

	//Bases
	yBP = mesa.vars[2] + mesa.vars[1]/2 + mesa.vars[4]/2;

	glPushMatrix();
	glTranslatef(0.0, -yBP, 0.0);   
	drawVBO(mesa.primitivas[2]);
	glPopMatrix();

	yBG = mesa.vars[2] + mesa.vars[1]/2 + 1.5*mesa.vars[4];

	glPushMatrix();
	glTranslatef(0.0, -yBG, 0.0);   
	drawVBO(mesa.primitivas[3]);
	glPopMatrix();

	//Apoios do Tampo
	xA1 = mesa.vars[3]/2 + (mesa.vars[0] - mesa.vars[3]/2 - mesa.vars[1]/2 - mesa.vars[1]/3)/2;
	yA = mesa.vars[1]/2 + mesa.vars[1]/6;
	zA1 = mesa.vars[3]/2 + (mesa.vars[0] - mesa.vars[3]/2 - mesa.vars[1]/2 - mesa.vars[1]/3)/2;

	for (i = -1; i < 2; i+=2) {
		glPushMatrix();
		glTranslatef(i*xA1, -yA, 0.0);
		drawVBO(mesa.primitivas[4]);
		glPopMatrix();
	}

	for (i = -1; i < 2; i+=2) {
		glPushMatrix();
		glTranslatef(0.0, -yA, i*zA1);
		drawVBO(mesa.primitivas[5]);
		glPopMatrix();
	}

	xA2 = mesa.vars[3]/2 + (mesa.vars[0] - mesa.vars[3]/2 - mesa.vars[1]/2 - mesa.vars[1]/3) + mesa.vars[1]/4;
	zA2 = mesa.vars[3]/2 + (mesa.vars[0] - mesa.vars[3]/2 - mesa.vars[1]/2 - mesa.vars[1]/3) + mesa.vars[1]/4;

	for (i = -1; i < 2; i+=2) {
		glPushMatrix();
		glTranslatef(i*xA2, -yA, 0.0);
		drawVBO(mesa.primitivas[6]);
		glPopMatrix();
	}

	for (i = -1; i < 2; i+=2) {
		glPushMatrix();
		glTranslatef(0.0, -yA, i*zA2);
		drawVBO(mesa.primitivas[7]);
		glPopMatrix();
	}
}

void drawEsplanadaPequena (Object mesa) {

	float eachBar = mesa.vars[1] /6;
	float spaceBetween = .05;
	float posZ = -((6* eachBar + 5 *spaceBetween) /2 ) + eachBar/2;

	//tampo
	for ( int i=0; i<6; i++) {
		glPushMatrix();
		glTranslatef(0, 0, posZ);
		drawVBO(mesa.primitivas[0]);
		glPopMatrix();
		posZ += eachBar + spaceBetween;
	}

	//barras baixo do tampo
	glPushMatrix();
	glTranslatef(mesa.vars[0] /2 - eachBar /2, -.2, 0); 
	drawVBO(mesa.primitivas[1]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef( -( mesa.vars[0] /2 - eachBar /2), -.2, 0);
	drawVBO(mesa.primitivas[1]);
	glPopMatrix();

	// pernas
	for ( int j =-1; j <2; j+=2) {
		glPushMatrix();
		glTranslatef(j * (mesa.vars[0] /2 - eachBar/2 + eachBar /8), -(mesa.vars[0]/2) * sin(M_PI/4) -.2, 0); 
		glRotatef(-45, 1.0f, 0.0f, 0.0f);
		drawVBO(mesa.primitivas[2]);
		glPopMatrix();

		glPushMatrix();
		glTranslatef( j* (mesa.vars[0] /2 - eachBar/2- eachBar /8), -(mesa.vars[0]/2) * sin(M_PI/4) -.2, 0); 
		glRotatef(45, 1.0f, 0.0f, 0.0f);
		drawVBO(mesa.primitivas[2]);
		glPopMatrix();

	}

	//barras
	glPushMatrix();
	glTranslatef( 0, -mesa.vars[0] *0.7 + eachBar, -mesa.vars[1]/5 + spaceBetween *2);
	glRotatef(45, 1.0f, 0.0f, 0.0f);
	drawVBO(mesa.primitivas[3]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef( 0, -mesa.vars[0] *0.7 + eachBar, mesa.vars[1]/5 - spaceBetween *2);
	glRotatef(-45, 1.0f, 0.0f, 0.0f);
	drawVBO(mesa.primitivas[3]);
	glPopMatrix();
}

void drawMesaEsplanada(Object mesa) {

	int i, j;
	float distEntreTamposBase;
	float xB, yB, zB;
	float xT, yT, zT;
	float xP, yP, zP;
	float xA1, yA1, zA1;

	//Base
	xB = mesa.vars[1]/2 -mesa.vars[2]/2;
	yB = 0.0;
	zB = mesa.vars[0]/2 -mesa.vars[2]/2;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, j*zB);
		drawVBO(mesa.primitivas[0]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xB, 0.0, 0.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		drawVBO(mesa.primitivas[1]);      
		glPopMatrix();
	}

	//Tampos da Base
	distEntreTamposBase = (mesa.vars[0] -(mesa.vars[3]*mesa.vars[5]))/(mesa.vars[3]+1);
	xT = 0.0;
	yT = mesa.vars[2]/2 +mesa.vars[4]/2;
	zT = mesa.vars[0]/2 - mesa.vars[5]/2;

	for (i = 0; i < mesa.vars[3]; i++) {
		glPushMatrix();
		glTranslatef(0.0, yT, -zT + (i+1)*distEntreTamposBase + (i)*mesa.vars[5]);
		drawVBO(mesa.primitivas[2]);
		glPopMatrix();
	}

	//Pernas
	xP = mesa.vars[1]/2 - mesa.vars[8]/2;
	yP = mesa.vars[6]/2 + mesa.vars[2]/2;
	zP = mesa.vars[0]/2 - mesa.vars[7];

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xP, -yP, zP);
		drawVBO(mesa.primitivas[3]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xP, -yP, -zP);
		drawVBO(mesa.primitivas[3]);
		glPopMatrix();
	}

	//Apoio Base
	xA1= mesa.vars[1]/2 - mesa.vars[7]/2;
	yA1 = -mesa.vars[2] +mesa.vars[2]/4; 
	zA1 = mesa.vars[0]/2 - mesa.vars[7];

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(0.0, yA1, j*zA1);
		drawVBO(mesa.primitivas[4]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xA1, yA1, 0.0);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		drawVBO(mesa.primitivas[5]);
		glPopMatrix();
	}
}

// /////////////////////
//Cadeiras
// /////////////////////

void drawCadeiraSimples (Object cadeira) {

	float xP, yP, zP;
	float xF, yF, zF;
	float xE, yE, zE;

	//Tampo
	drawVBO(cadeira.primitivas[0]);
	
	//Pernas
	xP = cadeira.vars[0]/2 - cadeira.vars[3];
	yP = -(cadeira.vars[4]/2) -(cadeira.vars[1]/2);
	zP = cadeira.vars[2]/2 - cadeira.vars[5];

	glPushMatrix();
	glTranslatef(xP, yP, -zP);
	drawVBO(cadeira.primitivas[1]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-xP, yP, -zP);
	drawVBO(cadeira.primitivas[1]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-xP, yP, zP);
	drawVBO(cadeira.primitivas[1]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xP, yP, zP);
	drawVBO(cadeira.primitivas[1]);
	glPopMatrix();

	//Ferrinhos
	xF = cadeira.vars[0]/4;
	yF = cadeira.vars[7]/2 - cadeira.vars[1]/2;
	zF = -(cadeira.vars[2]/2 + cadeira.vars[6]);

	glPushMatrix();
	glTranslatef(xF, yF, zF);
	drawVBO(cadeira.primitivas[2]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-xF, yF, zF);
	drawVBO(cadeira.primitivas[2]);
	glPopMatrix();

	//Encosto
	xE = 0.0;
	yE = cadeira.vars[7] - cadeira.vars[1];
	zE = -cadeira.vars[2]/2 + cadeira.vars[8]/2;

	glPushMatrix();
	glTranslatef(xE, yE, zE);
	drawVBO(cadeira.primitivas[3]);
	glPopMatrix();
}

void drawCadeiraSimplesTabuas(Object cadeira) {

	int i, j;
	float distEntreTamposCostas;
	float xP, yP, zP;
	float xB, yB, zB;
	float xL, yL, zL;
	float xV, yV, zV;
	float xE, yE, zE;

	//Tampo
	drawVBO(cadeira.primitivas[0]);
	
	//Pernas
	xP = cadeira.vars[0]/2 - cadeira.vars[3];
	yP = cadeira.vars[4]/2 + cadeira.vars[1]/2;
	zP = cadeira.vars[2]/2 - cadeira.vars[3];

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xP, -yP, zP);
		drawVBO(cadeira.primitivas[1]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xP, -yP, -zP);
		drawVBO(cadeira.primitivas[1]);
		glPopMatrix();
	}

	//Barras Encostadas ao Tampo 
	xB = cadeira.vars[3] - cadeira.vars[0]/2;
	yB = (cadeira.vars[3]*0.75)/2 + cadeira.vars[1]/2;
	zB = cadeira.vars[2]/2 - cadeira.vars[3];

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(0.0f, -yB, j*zB);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		drawVBO(cadeira.primitivas[2]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xB, -yB, 0.0f);
		drawVBO(cadeira.primitivas[3]);
		glPopMatrix();
	}

	//Barras Laterais e do Meio
	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xB, -yB -cadeira.vars[4]*0.5, 0.0f);
		drawVBO(cadeira.primitivas[3]);
		glPopMatrix();
	}

	glPushMatrix();
	glTranslatef(0.0f, -yB -cadeira.vars[4]*0.6, -zB);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	drawVBO(cadeira.primitivas[2]);
	glPopMatrix();

	//Barras Verticas das Costas
	xV = cadeira.vars[0]/2 - cadeira.vars[3];
	yV = cadeira.vars[5]/2 + cadeira.vars[1]/2;
	zV = cadeira.vars[2]/2 - cadeira.vars[3];

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xV, yV, zV);
		drawVBO(cadeira.primitivas[4]);
		glPopMatrix();
	}

	//Barras Lateral das Costas
	xL = 0.0;
	yL = cadeira.vars[5] + cadeira.vars[1]/2 + (cadeira.vars[3]*0.75)/2;
	zL = cadeira.vars[2]/2 - cadeira.vars[3];

	glPushMatrix();
	glTranslatef(0.0, yL, zL);
	drawVBO(cadeira.primitivas[5]);
	glPopMatrix();

	//Encostos
	distEntreTamposCostas = (cadeira.vars[5] - (cadeira.vars[7]*cadeira.vars[6]))/(cadeira.vars[7]+1);
	xE = 0.0;
	yE = cadeira.vars[5] + cadeira.vars[1]/2;
	zE = cadeira.vars[2]/2 - cadeira.vars[3] +cadeira.vars[3]/4;

	for (i = 0; i < cadeira.vars[7]; i++) {
		glPushMatrix();
		glTranslatef(xE, yE - distEntreTamposCostas - cadeira.vars[6]/2, zE);
		drawVBO(cadeira.primitivas[6]);
		glPopMatrix();
		yE = yE - distEntreTamposCostas - cadeira.vars[6];
	}
}

void drawBanco(Object cadeira) {

	float angulo;
	float xP, yP, zP;
	float xBe, yBe, zBe;
	float yBa;

	//Desenhar Tampo
	drawVBO(cadeira.primitivas[0]);

	//Pernas
	xP = cadeira.vars[0] - cadeira.vars[3]/2;        
	yP = cadeira.vars[2]/2 + cadeira.vars[1]/2;
	zP = cadeira.vars[0] - cadeira.vars[3];   

	for (angulo = M_PI/4; angulo < 2*M_PI; angulo += M_PI/2) {  
		glPushMatrix();
		glTranslatef(xP * sin(angulo), -yP, zP * cos(angulo));
		drawVBO(cadeira.primitivas[1]);
		glPopMatrix();
	}

	//Beiras encostadas ao Tampo e Barra das Pernas
	xBe = cadeira.vars[0] - cadeira.vars[3];
	yBe = cadeira.vars[1]/2 + cadeira.vars[4]/2;
	zBe = cadeira.vars[0] - cadeira.vars[3];
	yBa = (cadeira.vars[2])* 0.70 -  cadeira.vars[1]/2;

	for (angulo = M_PI/4; angulo < M_PI; angulo += M_PI/2) {  
		glPushMatrix();
		glTranslatef(0.0f, -yBe, zBe * cos(angulo));
		drawVBO(cadeira.primitivas[2]);
		glTranslatef(0.0f, -yBa, 0.0f);
		drawVBO(cadeira.primitivas[3]);
		glPopMatrix();
	}

	for (angulo = (3*M_PI)/4; angulo < 2*M_PI; angulo += M_PI/2) {  
		glPushMatrix();
		glTranslatef(xBe * sin(angulo), -yBe, 0.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		drawVBO(cadeira.primitivas[4]);
		glTranslatef(0.0f, -yBa, 0.0f);
		drawVBO(cadeira.primitivas[5]);  
		glPopMatrix();
	}
}

void drawBancoI(Object cadeira) {

	int j;
	float angulo;
	float xP, yP, zP;
	float xBe, yBe, zBe;
	float yBa;
	float incConv = cadeira.vars[4]*M_PI /180;

	//Desenhar Tampo
	drawVBO(cadeira.primitivas[0]);

	//Pernas
	xP = cadeira.vars[0] -cadeira.vars[3]/2;        
	yP = cadeira.vars[2]/2 + cadeira.vars[1]/2;
	zP = cadeira.vars[0] -cadeira.vars[3]/2;   

	for (angulo = M_PI/4, j = -1; angulo < M_PI; angulo += M_PI/2, j += 2) {  
		glPushMatrix();
		glTranslatef(xP * sin(angulo), -yP, zP * cos(angulo));
		glRotatef(j*cadeira.vars[4], 1.0f, 0.0f, 0.0f);
		glRotatef(cadeira.vars[4], 0.0f, 0.0f, 1.0f);
		drawVBO(cadeira.primitivas[1]);
		glPopMatrix();
	}

	for (angulo = (5*M_PI/4), j = 1; angulo < 2*M_PI; angulo += M_PI/2, j -= 2) {  
		glPushMatrix();
		glTranslatef(xP * sin(angulo), -yP, zP * cos(angulo));
		glRotatef(j*cadeira.vars[4], 1.0f, 0.0f, 0.0f);
		glRotatef(-cadeira.vars[4], 0.0f, 0.0f, 1.0f);
		drawVBO(cadeira.primitivas[1]);
		glPopMatrix();
	}

	//Beiras encostadas ao Tampo e Barra das Pernas
	xBe = cadeira.vars[0] -cadeira.vars[3]/2 - cadeira.vars[6];  
	yBe = cadeira.vars[1]/2 + cadeira.vars[5]/2;
	zBe = cadeira.vars[0] -cadeira.vars[3]/2 - cadeira.vars[6]; 
	yBa = (cadeira.vars[2])* 0.70 - cadeira.vars[1]/2;

	for (angulo = M_PI/4, j = -1; angulo < M_PI; angulo += M_PI/2, j += 2) {  
		glPushMatrix();
		glTranslatef(0.0, -yBe, zBe * cos(angulo-j*incConv));
		glRotatef(j*cadeira.vars[4], 1.0f, 0.0f, 0.0f);
		drawVBO(cadeira.primitivas[2]);
		glTranslatef(0.0f, -yBa, 0.0f);
		drawVBO(cadeira.primitivas[3]);
		glPopMatrix();
	}

	for (angulo = (3*M_PI)/4, j = -1; angulo < 3*M_PI/2; angulo += M_PI/2, j+=2) {  
		glPushMatrix();
		glTranslatef(xBe * sin(angulo-j*incConv), -yBe, 0.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(j*cadeira.vars[4], 1.0f, 0.0f, 0.0f);
		drawVBO(cadeira.primitivas[2]);
		glTranslatef(0.0f, -yBa, 0.0f);
		drawVBO(cadeira.primitivas[3]);
		glPopMatrix();
	}
}

void drawBancoQ(Object cadeira) {

	int i;
	float xP, yP, zP;
	float xBe, yBe, zBe;
	float yBa;

	//Desenhar Tampo
	drawVBO(cadeira.primitivas[0]);

	//Pernas
	xP = cadeira.vars[0]/2 - cadeira.vars[4]/2;        
	yP = cadeira.vars[3]/2 + cadeira.vars[2]/2;
	zP = cadeira.vars[1]/2 -cadeira.vars[4]/2;   

	for (i = -1; i < 2; i+=2) {
		glPushMatrix();
		glTranslatef(i*xP, -yP, zP);
		drawVBO(cadeira.primitivas[1]);
		glPopMatrix();
	}

	for (i = -1; i < 2; i+=2) { 
		glPushMatrix();
		glTranslatef(i*xP, -yP, -zP);
		drawVBO(cadeira.primitivas[1]);
		glPopMatrix();
	}


	//Beiras encostadas ao Tampo e Barra das Pernas
	xBe = cadeira.vars[0]/2 -cadeira.vars[6]/2 -cadeira.vars[4]/2;  
	yBe = cadeira.vars[2]/2 + cadeira.vars[5]/2;
	zBe = cadeira.vars[1]/2 -cadeira.vars[6]/2 -cadeira.vars[4]/2;
	yBa = (cadeira.vars[3])* 0.70 - cadeira.vars[2]/2;

	for (i = -1; i < 2; i+=2) { 
		glPushMatrix();
		glTranslatef(i*xBe, -yBe, 0.0);
		drawVBO(cadeira.primitivas[2]);
		glTranslatef(0.0, -yBa, 0.0);
		drawVBO(cadeira.primitivas[2]);
		glPopMatrix();
	}

	for (i = -1; i < 2; i+=2) { 
		glPushMatrix();
		glTranslatef(0.0, -yBe, i*zBe);
		drawVBO(cadeira.primitivas[3]);
		glTranslatef(0.0, -yBa, 0.0);
		drawVBO(cadeira.primitivas[3]);
		glPopMatrix();
	}
}

void drawBancoQI(Object cadeira) {

	int i, j;
	float xP, yP, zP;
	float xBe, yBe, zBe;
	float yBa;
	float incConv = cadeira.vars[5]*M_PI /180;

	//Desenhar Tampo
	drawVBO(cadeira.primitivas[0]);

	// //Pernas
	xP = cadeira.vars[0]/2 - cadeira.vars[4]/2;        
	yP = cadeira.vars[3]/2 + cadeira.vars[2]/2;
	zP = cadeira.vars[1]/2 -cadeira.vars[4]/2;


	for (i = -1; i < 2; i+=2) {
		glPushMatrix();
		glTranslatef(i*xP, -yP, zP);
		glRotatef(-cadeira.vars[5], 1.0f, 0.0f, 0.0f);
		glRotatef(i*cadeira.vars[5], 0.0f, 0.0f, 1.0f);
		drawVBO(cadeira.primitivas[1]);
		glPopMatrix();
	}

	for (i = 1; i > -2; i-=2) {
		glPushMatrix();
		glTranslatef(i*xP, -yP, -zP);
		glRotatef(cadeira.vars[5], 1.0f, 0.0f, 0.0f);
		glRotatef(i*cadeira.vars[5], 0.0f, 0.0f, 1.0f);
		drawVBO(cadeira.primitivas[1]);
		glPopMatrix();
	}

	// //Beiras encostadas ao Tampo e Barra das Pernas
	xBe = cadeira.vars[0]/2 -cadeira.vars[7]/2 -cadeira.vars[3]*sin(incConv);  
	yBe = cadeira.vars[2]/2 + cadeira.vars[6]/2;
	zBe = cadeira.vars[1]/2 -cadeira.vars[7]/2 -cadeira.vars[3]*sin(incConv);
	yBa = (cadeira.vars[3])* 0.70 - cadeira.vars[2]/2;

	for (i = -1; i < 2; i+=2) { 
		glPushMatrix();
		glTranslatef(i*xBe, -yBe, 0.0);
		glRotatef(i*cadeira.vars[5], 0.0f, 0.0f, 1.0f);
		drawVBO(cadeira.primitivas[2]);
		glTranslatef(0.0, -yBa, 0.0);
		drawVBO(cadeira.primitivas[3]);
		glPopMatrix();
	}

	for (i = -1, j = 1; i < 2; i+=2, j -=2) { 
		glPushMatrix();
		glTranslatef(0.0, -yBe, i*zBe);
		glRotatef(j*cadeira.vars[5], 1.0f, 0.0f, 0.0f);
		drawVBO(cadeira.primitivas[4]);
		glTranslatef(0.0, -yBa, 0.0);
		drawVBO(cadeira.primitivas[5]);
		glPopMatrix();
	}
}

void drawBancoRedondo(Object cadeira) {

	//Tampo
	drawVBO(cadeira.primitivas[0]);

	//Base
	glPushMatrix();
	glTranslatef(0.0, -(cadeira.vars[0]/2 + cadeira.vars[1]/2), 0.0);
	drawVBO(cadeira.primitivas[1]);
	glPopMatrix();
}

void drawCadeiraDecor(Object cadeira) {

	int i, j;
	float distEntreTamposBase, distEntreTamposCostas;
	float xB, yB, zB;
	float xT, yT, zT;
	float xP, yP, zP;
	float xBr, yBr, zBr;
	float xA1, yA1, zA1;
	float xA2, yA2, zA2;
	float xC, yC, zC;
	float xTC, yTC, zTC;

	//Base
	xB = cadeira.vars[1]/2 -cadeira.vars[2]/2;
	yB = 0.0;
	zB = cadeira.vars[0]/2 + cadeira.vars[2]/2;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, j*zB);
		drawVBO(cadeira.primitivas[0]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xB, 0.0, 0.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		drawVBO(cadeira.primitivas[1]);
		glPopMatrix();
	}

	//Tampos da Base
	distEntreTamposBase = (cadeira.vars[0] -(cadeira.vars[3]*cadeira.vars[5]))/(cadeira.vars[3]+1);
	xT = 0.0;
	yT = cadeira.vars[2]/2 +cadeira.vars[4]/2;
	zT = cadeira.vars[0]/2 - cadeira.vars[5]/2;

	for (i = 0; i < cadeira.vars[3]; i++) {
		glPushMatrix();
		glTranslatef(0.0, yT, -zT + (i+1)*distEntreTamposBase + (i)*cadeira.vars[5]);
		drawVBO(cadeira.primitivas[2]);
		glPopMatrix();
	}

	//Pernas
	xP = cadeira.vars[1]/2 + cadeira.vars[8]/2;
	yP = cadeira.vars[6]/2 + cadeira.vars[2]/2;
	zP = cadeira.vars[0]/2 - cadeira.vars[7];

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xP, -yP, zP);
		drawVBO(cadeira.primitivas[3]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xP, -yP, -zP);
		drawVBO(cadeira.primitivas[3]);
		glPopMatrix();
	}

	//Bracos
	xBr = xP;
	yBr = cadeira.vars[9]/2 -cadeira.vars[2]/2;
	zBr = zP;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(xBr, yBr, j*zBr);
		drawVBO(cadeira.primitivas[4]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(-xBr, yBr, j*zBr);
		drawVBO(cadeira.primitivas[4]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xBr, yBr + cadeira.vars[9]/2 + cadeira.vars[8]/2, 0.0);
		drawVBO(cadeira.primitivas[5]);
		glPopMatrix();
	}

	//Apoio Base
	xA1 = cadeira.vars[1]/2 + cadeira.vars[8]/2;
	yA1 = -(cadeira.vars[2]/2 +cadeira.vars[2]/4); 
	zA1 = cadeira.vars[0]/2 - cadeira.vars[7];

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(0.0, yA1, j*zA1);
		drawVBO(cadeira.primitivas[6]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xA1, yA1, 0.0);
		drawVBO(cadeira.primitivas[7]);
		glPopMatrix();
	}

	xA2 = cadeira.vars[12]/2 + cadeira.vars[13]/2;
	yA2 = cadeira.vars[2]/2 + cadeira.vars[13]/2; 
	zA2 = cadeira.vars[0]/2 - cadeira.vars[7]/2 + (cadeira.vars[7]/2 + cadeira.vars[2] + cadeira.vars[13] + cadeira.vars[10])/2;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xA2, -yA2, -zA2);
		drawVBO(cadeira.primitivas[8]);
		glPopMatrix();   
	}

	//Base Costas
	xC = cadeira.vars[12]/2 + cadeira.vars[13]/2;
	yC = cadeira.vars[11]/2 -cadeira.vars[2]/2; 
	zC = cadeira.vars[0]/2 + cadeira.vars[2] + cadeira.vars[10] + cadeira.vars[13]/2;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xC, yC, -zC);
		drawVBO(cadeira.primitivas[9]);
		glPopMatrix();
	}

	yC = cadeira.vars[13]/2 + cadeira.vars[2]/2; ;

	for (i = 0, j = 0; i < 2; i++, j+= cadeira.vars[11]) {
		glPushMatrix();
		glTranslatef(0.0, j -yC, -zC);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		drawVBO(cadeira.primitivas[10]);
		glPopMatrix();
	}

	//Tampos das costas
	distEntreTamposCostas = (cadeira.vars[11] -(cadeira.vars[14]*cadeira.vars[4]))/(cadeira.vars[14]+1);
	xTC = 0.0;
	yTC = cadeira.vars[11] - cadeira.vars[2]/2 - cadeira.vars[13]/2 - distEntreTamposCostas ;
	zTC = cadeira.vars[0]/2 + cadeira.vars[2] + cadeira.vars[10] +cadeira.vars[4]/2;

	for (i = 0; i < cadeira.vars[14]; i++) {
		glPushMatrix();
		glTranslatef(xTC, yTC, -zTC);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		drawVBO(cadeira.primitivas[11]);
		glPopMatrix();
		yTC = yTC - distEntreTamposCostas;
	}
}

void drawCadeiraDecorX(Object cadeira) {

	int i, j;
	float distEntreTamposBase, distEntreTamposCostas;
	float xB, yB, zB;
	float xT, yT, zT;
	float xP, yP, zP;
	float xBr, yBr, zBr;
	float xA1, yA1, zA1;
	float xA2, yA2, zA2;
	float xC, yC, zC;
	float xTC, yTC, zTC;

	//Base
	xB = cadeira.vars[1]/2 -cadeira.vars[2]/2;
	yB = 0.0;
	zB = cadeira.vars[0]/2 + cadeira.vars[2]/2;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, j*zB);
		drawVBO(cadeira.primitivas[0]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xB, 0.0, 0.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		drawVBO(cadeira.primitivas[1]);
		glPopMatrix();
	}

	//Tampos da Base
	distEntreTamposBase = (cadeira.vars[0] -(cadeira.vars[3]*cadeira.vars[5]))/(cadeira.vars[3]+1);
	xT = 0.0;
	yT = cadeira.vars[2]/2 +cadeira.vars[4]/2;
	zT = cadeira.vars[0]/2 - cadeira.vars[5]/2;

	for (i = 0; i < cadeira.vars[3]; i++) {
		glPushMatrix();
		glTranslatef(0.0, yT, -zT + (i+1)*distEntreTamposBase + (i)*cadeira.vars[5]);
		drawVBO(cadeira.primitivas[2]);
		glPopMatrix();
	}

	// Pernas
	xP = cadeira.vars[1]/2 + cadeira.vars[8]/2;
	yP = (cadeira.vars[6]/2)* sin(M_PI/4) + cadeira.vars[2]/2 -cadeira.vars[7]/2;
	zP = cadeira.vars[0]/2 -(cadeira.vars[6]/2)* sin(M_PI/4);

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xP, -yP, -zP);
		glRotatef(-45.0, 1.0, 0.0, 0.0);
		drawVBO(cadeira.primitivas[3]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xP, -yP, zP);
		glRotatef(45.0, 1.0, 0.0, 0.0);
		drawVBO(cadeira.primitivas[3]);
		glPopMatrix();
	}

	//Bracos
	xBr = xP;
	yBr = cadeira.vars[9]/2 -cadeira.vars[2]/2;
	zBr = cadeira.vars[0]/2 - cadeira.vars[7];

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(xBr, yBr, j*zBr);
		drawVBO(cadeira.primitivas[4]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(-xBr, yBr, j*zBr);
		drawVBO(cadeira.primitivas[4]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xBr, yBr + cadeira.vars[9]/2 + cadeira.vars[8]/2, 0.0);
		drawVBO(cadeira.primitivas[5]);
		glPopMatrix();
	}

	//Apoio Base
	xA1 = cadeira.vars[1]/2 + cadeira.vars[8]/2;
	yA1 = -(cadeira.vars[2]/2 +cadeira.vars[2]/4); 
	zA1 = cadeira.vars[0]/2 - cadeira.vars[7];

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(0.0, yA1, j*zA1);
		drawVBO(cadeira.primitivas[6]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xA1, yA1, 0.0);
		drawVBO(cadeira.primitivas[7]);
		glPopMatrix();
	}

	xA2 = cadeira.vars[12]/2 + cadeira.vars[13]/2;
	yA2 = cadeira.vars[2]/2 + cadeira.vars[13]/2; 
	zA2 = cadeira.vars[0]/2 - cadeira.vars[7]/2 + (cadeira.vars[7]/2 + cadeira.vars[2] + cadeira.vars[13] + cadeira.vars[10])/2;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xA2, -yA2, -zA2);
		drawVBO(cadeira.primitivas[8]);
		glPopMatrix();   
	}

	//Base Costas
	xC = cadeira.vars[12]/2 + cadeira.vars[13]/2;
	yC = cadeira.vars[11]/2 -cadeira.vars[2]/2; 
	zC = cadeira.vars[0]/2 + cadeira.vars[2] + cadeira.vars[10] + cadeira.vars[13]/2;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xC, yC, -zC);
		drawVBO(cadeira.primitivas[9]);
		glPopMatrix();
	}

	yC = cadeira.vars[13]/2 + cadeira.vars[2]/2; ;

	for (i = 0, j = 0; i < 2; i++, j+= cadeira.vars[11]) {
		glPushMatrix();
		glTranslatef(0.0, j -yC, -zC);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		drawVBO(cadeira.primitivas[10]);
		glPopMatrix();
	}

	//Tampos das costas
	distEntreTamposCostas = (cadeira.vars[11] -(cadeira.vars[14]*cadeira.vars[4]))/(cadeira.vars[14]+1);
	xTC = 0.0;
	yTC = cadeira.vars[11] - cadeira.vars[2]/2 - cadeira.vars[13]/2 - distEntreTamposCostas ;
	zTC = cadeira.vars[0]/2 + cadeira.vars[2] + cadeira.vars[10] +cadeira.vars[4]/2;

	for (i = 0; i < cadeira.vars[14]; i++) {
		glPushMatrix();
		glTranslatef(xTC, yTC, -zTC);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		drawVBO(cadeira.primitivas[11]);
		glPopMatrix();
		yTC = yTC - distEntreTamposCostas;
	}
}

void drawCadeiraDecorInc(Object cadeira) {

	int i, j;
	float distEntreTamposBase, distEntreTamposCostas;
	float xB, yB, zB;
	float xT, yT, zT;
	float xP, yP, zP;
	float xBr, yBr, zBr;
	float xA1, yA1, zA1;
	float xA2, yA2, zA2;
	float xC1, yC1, zC1;
	float xC2, yC2, zC2;
	float xC3, yC3, zC3;
	float xTC, yTC, zTC;
	float incConv = (cadeira.vars[15] * M_PI)/180;

	//Base
	xB = cadeira.vars[1]/2 -cadeira.vars[2]/2;
	yB = 0.0;
	zB = cadeira.vars[0]/2 + cadeira.vars[2]/2;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, j*zB);
		drawVBO(cadeira.primitivas[0]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xB, 0.0, 0.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		drawVBO(cadeira.primitivas[1]);
		glPopMatrix();
	}

	//Tampos da Base
	distEntreTamposBase = (cadeira.vars[0] -(cadeira.vars[3]*cadeira.vars[5]))/(cadeira.vars[3]+1);
	xT = 0.0;
	yT = cadeira.vars[2]/2 + cadeira.vars[4]/2;
	zT = cadeira.vars[0]/2 - cadeira.vars[5]/2;

	for (i = 0; i < cadeira.vars[3]; i++) {
		glPushMatrix();
		glTranslatef(0.0, yT, -zT + (i+1)*distEntreTamposBase + (i)*cadeira.vars[5]);
		drawVBO(cadeira.primitivas[2]);
		glPopMatrix();
	}

	//Pernas
	xP = cadeira.vars[1]/2 + cadeira.vars[8]/2;
	yP = cadeira.vars[6]/2 + cadeira.vars[2]/2;
	zP = cadeira.vars[0]/2 - cadeira.vars[7];

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xP, -yP, zP);
		drawVBO(cadeira.primitivas[3]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xP, -yP, -zP);
		drawVBO(cadeira.primitivas[3]);
		glPopMatrix();
	}

	//Bracos
	xBr = xP;
	yBr = cadeira.vars[9]/2 -cadeira.vars[2]/2;
	zBr = zP;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(xBr, yBr, j*zBr);
		drawVBO(cadeira.primitivas[4]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(-xBr, yBr, j*zBr);
		drawVBO(cadeira.primitivas[4]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xBr, yBr + cadeira.vars[9]/2 + cadeira.vars[8]/2, 0.0);
		drawVBO(cadeira.primitivas[5]);
		glPopMatrix();
	}

	//Apoio Base
	xA1 = cadeira.vars[1]/2 + cadeira.vars[8]/2;
	yA1 = -(cadeira.vars[2]/2 +cadeira.vars[2]/4); 
	zA1 = cadeira.vars[0]/2 - cadeira.vars[7];

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(0.0, yA1, j*zA1);
		drawVBO(cadeira.primitivas[6]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xA1, yA1, 0.0);
		drawVBO(cadeira.primitivas[7]);
		glPopMatrix();
	}

	xA2 = cadeira.vars[12]/2 + cadeira.vars[13]/2;
	yA2 = cadeira.vars[2]/2 + cadeira.vars[13]/2; 
	zA2 = cadeira.vars[0]/2 - cadeira.vars[7]/2 + (cadeira.vars[7]/2 + cadeira.vars[2] + cadeira.vars[13] + cadeira.vars[10])/2;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xA2, -yA2, -zA2);
		drawVBO(cadeira.primitivas[8]);
		glPopMatrix();   
	}

	//Base Costas
	xC1 = cadeira.vars[12]/2 + cadeira.vars[13]/2;
	yC1 = cadeira.vars[11]/2 -cadeira.vars[2] - ((cadeira.vars[11]/2)-(sin(incConv)*cadeira.vars[11])); 
	zC1 = cadeira.vars[0]/2 + 2*cadeira.vars[2] + cadeira.vars[10] -cadeira.vars[13]/2 +(sin(incConv)*cadeira.vars[11])/2;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xC1, yC1, -zC1);
		glRotatef(-cadeira.vars[15], 1.0f, 0.0f, 0.0f);
		drawVBO(cadeira.primitivas[9]);
		glPopMatrix();
	}

	xC2 = cadeira.vars[12]/2 + cadeira.vars[13]/2;
	yC2 = cadeira.vars[13]/2 + cadeira.vars[2]/2; 
	zC2 = cadeira.vars[0]/2 + cadeira.vars[2] + cadeira.vars[10] + cadeira.vars[13]/2;

	glPushMatrix();
	glTranslatef(0.0,-yC2, -zC2);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	drawVBO(cadeira.primitivas[10]);
	glPopMatrix();

	xC3 = 0.0;
	yC3 = cadeira.vars[11] -cadeira.vars[2] - ((cadeira.vars[11]/2)-(sin(incConv)*cadeira.vars[11])) -cadeira.vars[13]; 
	zC3 = zC2 + sin(incConv)*cadeira.vars[11] -cadeira.vars[13]/2;

	glPushMatrix();
	glTranslatef(xC3, yC3, -zC3);
	glRotatef(-cadeira.vars[15], 1.0f, 0.0f, 0.0f);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	drawVBO(cadeira.primitivas[10]);
	glPopMatrix();

	//Tampos das costas
	distEntreTamposCostas = (cadeira.vars[11] -(cadeira.vars[14]*cadeira.vars[4]))/(cadeira.vars[14]+1);
	xTC = 0.0;
	yTC = cadeira.vars[11] - cadeira.vars[2] - cadeira.vars[13] - distEntreTamposCostas;
	zTC = zC3 -cadeira.vars[13]/2 -cadeira.vars[4]/2;

	for (i = 0; i < cadeira.vars[14]; i++) {
		glPushMatrix();
		glTranslatef(xTC, yTC, -zTC);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glRotatef(-cadeira.vars[15], 1.0, 0.0, 0.0);
		drawVBO(cadeira.primitivas[11]);
		glPopMatrix();
		yTC = yTC - distEntreTamposCostas;
		zTC -= 2*cadeira.vars[13]*sin(incConv) -cadeira.vars[4];
	}
}

void drawCadeiraFashion(Object cadeira) {

	int j;
	float xC, yC, zC;
	float xP, yP, zP;
	float xB, yB, zB;
	float xBr1, yBr1, zBr1;
	float xBr2, yBr2, zBr2;


	//Tampo
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	drawVBO(cadeira.primitivas[0]);
	glPopMatrix();

	xC = 0.0;
	yC = cadeira.vars[3]/2 + cadeira.vars[2]/2;
	zC = cadeira.vars[1]/2 -cadeira.vars[4]/2;

	//Costas
	glPushMatrix();
	glTranslatef(xC, yC, -zC);
	drawVBO(cadeira.primitivas[1]);
	glPopMatrix();

	//Pernas
	xP = cadeira.vars[0]/2 + cadeira.vars[6]/2;
	yP = cadeira.vars[5]/2 -cadeira.vars[2]/2;
	zP = cadeira.vars[1]/2 - cadeira.vars[6]*1.5;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xP, -yP, zP);
		glRotatef(90.0, 0.0, 0.0, 1.0);
		drawVBO(cadeira.primitivas[2]);
		glPopMatrix();
	}

	//Base
	xB = cadeira.vars[0]/2 + cadeira.vars[6]/2;
	yB = cadeira.vars[5] -cadeira.vars[2]/2 -cadeira.vars[6]/2;
	zB = cadeira.vars[1]/2 -cadeira.vars[6]/2 ;

	glPushMatrix();
	glTranslatef(0.0, -yB, -zB);
	drawVBO(cadeira.primitivas[3]);
	glPopMatrix();

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xB, -yB, -cadeira.vars[6]);
		glRotatef(90, 0.0, 1.0, 0.0);
		drawVBO(cadeira.primitivas[4]);
		glPopMatrix();
	}

	//Bracos
	xBr1 = cadeira.vars[0]/2 + cadeira.vars[6]/2;
	yBr1 = cadeira.vars[7]/2 + cadeira.vars[2]/2;
	zBr1 = cadeira.vars[1]/2 - cadeira.vars[6]*1.5;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xBr1, yBr1, zBr1);
		drawVBO(cadeira.primitivas[5]);
		glPopMatrix();
	}

	xBr2 = cadeira.vars[0]/2 + cadeira.vars[6]/2;
	yBr2 = cadeira.vars[7] + cadeira.vars[6]/2 +cadeira.vars[2]/2;
	zBr2 = cadeira.vars[6]/2;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xBr2, yBr2, -zBr2);
		drawVBO(cadeira.primitivas[6]);
		glPopMatrix();    
	}
}

void drawSofa(Object cadeira) {


	float j;
	float xB, yB, zB;
	float xL, yL, zL;
	float xC, yC, zC;
	float xAB, yAB, zAB;
	float xAC, yAC, zAC;
	float xA, yA, zA;
	float xAL, yAL, zAL;

	//Base
	xB = cadeira.vars[1]/2 -cadeira.vars[2]/2;
	yB = cadeira.vars[2]/2;
	zB = cadeira.vars[0]/2 + cadeira.vars[2]/2;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(0.0f, yB, j*zB);
		drawVBO(cadeira.primitivas[0]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xB,yB, 0.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		drawVBO(cadeira.primitivas[1]);
		glPopMatrix();
	}

	//Laterais
	xL = cadeira.vars[1]/2 + cadeira.vars[4]/2;
	yL = cadeira.vars[3]/2;
	zL = 0.0;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xL, yL, 0.0);
		drawVBO(cadeira.primitivas[2]);
		glPopMatrix();
	}

	//Costas
	xC = 0.0;
	yC = cadeira.vars[2] + cadeira.vars[5]/2;
	zC = cadeira.vars[0]/2  + cadeira.vars[2] -cadeira.vars[6]/2;

	glPushMatrix();
	glTranslatef(xC, yC, -zC);
	drawVBO(cadeira.primitivas[3]);
	glPopMatrix();
	
	//Almofada Base
	xAB = cadeira.vars[1]/2 - (cadeira.vars[1]/cadeira.vars[7])/2;
	yAB = cadeira.vars[2] + cadeira.vars[9]/2;
	zAB = (cadeira.vars[8]/2)-(cadeira.vars[0]/2  + cadeira.vars[2]) + cadeira.vars[6];

	for (j = 0; j < cadeira.vars[7]; j++) {
		glPushMatrix();
		glTranslatef(xAB, yAB, zAB);
		drawVBO(cadeira.primitivas[4]);
		glPopMatrix();
		xAB -= cadeira.vars[1]/cadeira.vars[7];
	}

	//Almofada Costas
	xAC = cadeira.vars[1]/2 - (cadeira.vars[1]/cadeira.vars[7])/2;
	yAC = cadeira.vars[2] + (cadeira.vars[8]-cadeira.vars[9])/2 + cadeira.vars[9];
	zAC = cadeira.vars[0]/2  + cadeira.vars[2] -cadeira.vars[6] - cadeira.vars[9]/2;

	for (j = 0; j < cadeira.vars[7]; j++) {
		glPushMatrix();
		glTranslatef(xAC, yAC, -zAC);
		drawVBO(cadeira.primitivas[5]);
		glPopMatrix();
		xAC -= cadeira.vars[1]/cadeira.vars[7];
	}

	//Apoios Frente e Tras
	xA = (cadeira.vars[1] + 0.5*cadeira.vars[4])/2 + (0.5*cadeira.vars[4])/2;
	yA = cadeira.vars[10]/2;
	zA = cadeira.vars[0]/2  + cadeira.vars[2] -cadeira.vars[11]*2;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(0.0f, -yA, j*zA);
		drawVBO(cadeira.primitivas[6]);
		glPopMatrix();
	}

	//Apoios Cantos
	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(xA, -yA, j*zA);
		drawVBO(cadeira.primitivas[7]);
		glPopMatrix();
	}

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(-xA, -yA, j*zA);
		drawVBO(cadeira.primitivas[7]);
		glPopMatrix();
	}

	//Apoios Laterais
	xAL = (cadeira.vars[1] + cadeira.vars[4])/2;
	yAL = cadeira.vars[10]/2;
	zAL = 0.0;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xAL, -yAL, zAL);
		drawVBO(cadeira.primitivas[8]);
		glPopMatrix();
	}
}

// /////////////////////
// Copos
// /////////////////////
void drawMartini(Object copo){
	drawVBO(copo.primitivas[0]);

	drawVBO(copo.primitivas[1]);

	drawVBO(copo.primitivas[2]);

	glPushMatrix();
	glTranslatef(0, -copo.vars[0]/2 - copo.vars[1]/2, 0);
	drawVBO(copo.primitivas[3]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -copo.vars[0]/2 - copo.vars[1] , 0);
	drawVBO(copo.primitivas[4]);
	glPopMatrix();
}

void drawTallGlass(Object copo) {
	drawVBO(copo.primitivas[0]);

	drawVBO(copo.primitivas[1]);

	drawVBO(copo.primitivas[2]);
}

void drawMartiniWithStick(Object copo, Object stick){
	drawMartini(copo);
	glPushMatrix();
	glTranslatef(0.2, 0.2, 0);
	drawMartiniStick(stick);
	glPopMatrix();
}

void drawMartiniStick(Object object) {
	glPushMatrix();
	glRotatef(-35, 0, 1, 1);
	drawVBO(object.primitivas[0]);
	glPopMatrix();

	// Azeitona
	float raio = object.vars[0]/4;
	glPushMatrix(),
	glTranslatef(raio*sin(-35), raio , 0);
	drawVBO(object.primitivas[1]);
	glPopMatrix();
}

void drawCaneca(Object object){

	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	drawVBO(object.primitivas[0]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(object.vars[0]/2 + object.vars[1]/2 + object.vars[2]/2 - object.vars[3]/2-0.02, 0, 0);
	drawVBO(object.primitivas[1]);
	drawVBO(object.primitivas[2]);
	drawVBO(object.primitivas[3]);
	glPopMatrix();
}

void drawCerveja(Object object){
	glPushMatrix();
	glTranslatef(0, -object.vars[0]/2 - object.vars[1]/2, 0);
	drawVBO(object.primitivas[0]);
	glPopMatrix();

	glPushMatrix();
	drawVBO(object.primitivas[1]);
	drawVBO(object.primitivas[2]);
	drawVBO(object.primitivas[3]);
	glPopMatrix();
}

void drawGlassWater(Object object){
	drawVBO(object.primitivas[0]);
	drawVBO(object.primitivas[1]);

	glPushMatrix();
	glTranslatef(0.0, -object.vars[0]/2 - object.vars[1]/2, 0.0);
	drawVBO(object.primitivas[2]);
	glPopMatrix();

    // Base
	glPushMatrix();
	glTranslatef(0.0, -object.vars[0]/2 - object.vars[1] - object.vars[2]/2, 0.0);
	drawVBO(object.primitivas[3]);
	glPopMatrix();

	// glPushMatrix();
	// drawVBO(object.primitivas[1]);
	// drawVBO(object.primitivas[2]);
	// drawVBO(object.primitivas[3]);
	// glPopMatrix();
}

// /////////////////////
// Candeeiros
// /////////////////////

void drawCandeeiroTeto(Object candeeiro) {

	// Base
	drawVBO(candeeiro.primitivas[0]);

	// Fio
	glPushMatrix();
	glTranslatef(0.0, -(candeeiro.vars[0]/2 + candeeiro.vars[1]/2), 0.0);
	drawVBO(candeeiro.primitivas[1]);
	glPopMatrix();

	// Esfera
	glPushMatrix();
	glTranslatef(0.0,-candeeiro.vars[0] - candeeiro.vars[2]/2 - candeeiro.vars[1]/2, 0.0);
	drawVBO(candeeiro.primitivas[2]);
	glPopMatrix();
}

void drawCandeeiroChao(Object object){
	// Base
	glPushMatrix();
	drawVBO(object.primitivas[0]);
	glPopMatrix();

	// Fio
	glPushMatrix();
	glTranslatef(0.0, (object.vars[0]/2 + object.vars[1]/2), 0.0);
	drawVBO(object.primitivas[1]);
	glPopMatrix();

	// Topop
	glPushMatrix();
	glTranslatef(0.0, (object.vars[0] + object.vars[1]/2) + object.vars[2]/2, 0.0);
	drawVBO(object.primitivas[2]);
	drawVBO(object.primitivas[3]);
	drawVBO(object.primitivas[4]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,yellow);
	drawVBO(object.primitivas[5]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,black);
	glPopMatrix();
}

void drawCandeeiroTetoCilindro(Object object){
	// Base
	glPushMatrix();
	drawVBO(object.primitivas[0]);
	glPopMatrix();

	// Fio
	glPushMatrix();
	glTranslatef(0.0, -(object.vars[0]/2 + object.vars[1]/2), 0.0);
	glRotatef(180, 1, 0, 0);
	drawVBO(object.primitivas[1]);
	glPopMatrix();

	// Cilindro
	glPushMatrix();
	glTranslatef(0.0, -object.vars[0] - object.vars[2]/2 - object.vars[1]/2, 0.0);
	glRotatef(180, 1, 0, 0);
	drawVBO(object.primitivas[2]);
	drawVBO(object.primitivas[3]);
	drawVBO(object.primitivas[4]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,yellow);
	drawVBO(object.primitivas[5]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,black);
	glPopMatrix();
}

void drawFoco(Object object){

	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,yellow);
	drawVBO(object.primitivas[0]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,black);
}

void drawLamp(Object object){
	drawVBO(object.primitivas[0]);
}

void drawGuardaSol(Object guardaSol) {

	// Pano
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,white);
	glPushMatrix();
	glTranslatef(0.0f, guardaSol.vars[1]/2, 0.0f);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	drawVBO(guardaSol.primitivas[0]);
	drawVBO(guardaSol.primitivas[1]);
	drawVBO(guardaSol.primitivas[2]);
	glPopMatrix();

	//Varao
	glPushMatrix();
	glTranslatef(0.0f, guardaSol.vars[0]*0.3, 0.0f);
	drawVBO(guardaSol.primitivas[3]);
	glPopMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,black);
}

void drawPassadeira(Object passadeira) {

	int i;
	float variacao = passadeira.vars[2]/2;

	if(passadeira.vars[1] == 0) {

		for(i = 0; i < passadeira.vars[0]; i++) {
			glPushMatrix();
			glTranslatef(0.0f, 0.0f, variacao);
			glRotatef(passadeira.vars[1], 0.0, 1.0, 0.0);
			drawVBO(passadeira.primitivas[0]);
			glPopMatrix();
			variacao += passadeira.vars[2] + passadeira.vars[2]*0.2;
		}
	}

	else {

		for(i = 0; i < passadeira.vars[0]; i++) {
			glPushMatrix();
			glTranslatef(variacao, 0.0f, 0.0f);
			glRotatef(passadeira.vars[1], 0.0, 1.0, 0.0);
			drawVBO(passadeira.primitivas[0]);
			glPopMatrix();
			variacao += passadeira.vars[2] + passadeira.vars[2]*0.2;
		}
	}
}

void drawBolaPraia(Object bolaPraia) {

	glPushMatrix();
	glTranslatef(0.0, bolaPraia.vars[0], 0.0);
	drawVBO(bolaPraia.primitivas[0]);
	glPopMatrix();
}

void drawToalhaPraia(Object toalha) {

	glPushMatrix();
	glRotatef(toalha.vars[0], 0.0, 1.0, 0.0);
	glTranslatef(0.0, toalha.vars[1]/2, 0.0);
	drawVBO(toalha.primitivas[0]);
	glPopMatrix();
}

void drawQuadro(Object quadro) {

	glPushMatrix();
	glTranslatef(0.0, quadro.vars[0]/2, 0.0);
	drawVBO(quadro.primitivas[0]);
	glPopMatrix();
}

void drawEstante(Object estante) {

	int j;
	float xC, yC, zC;
	float xL, yL, zL;
	float xE, yE, zE;
	float xA, yA, zA;
	float xP, yP, zP;

	//Costas
	xC = 0.0;
	yC = estante.vars[0]/2;
	zC = 0.0;

	glPushMatrix();
	glTranslatef(xC, yC, zC);
	drawVBO(estante.primitivas[0]);
	glPopMatrix();

	//Laterais
	xL = estante.vars[1]/2 - estante.vars[2]*1.5;
	yL = estante.vars[0]/2;
	zL = estante.vars[3]/2 + estante.vars[2]/2;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xL, yL, zL);
		drawVBO(estante.primitivas[1]);
		glPopMatrix();
	}

	//Extremos
	xE = 0.0;
	yE = estante.vars[0] + estante.vars[2]/2;
	zE = estante.vars[3]/2 + estante.vars[2]/2;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(xE, yE, zE);
		drawVBO(estante.primitivas[2]);
		glPopMatrix();
		yE -= yE +estante.vars[2]/2;
	}

	//Baixo
	xA = (estante.vars[1]/2 - estante.vars[2]*2)/2;
	yA = (estante.vars[0]/2)/2;
	zA = estante.vars[3]/2;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(j*xA, yA, zA);
		drawVBO(estante.primitivas[3]);
		glPopMatrix();
	}

	//Prateleiras
	xP = 0.0;
	yP = (estante.vars[0]/2) + estante.vars[4]/2;
	zP = (estante.vars[3] + estante.vars[3]*0.1)/ 2 +estante.vars[2]/2;

	for (j = -1; j < 2; j+=2) {
		glPushMatrix();
		glTranslatef(xP, yP, zP);
		drawVBO(estante.primitivas[4]);
		glPopMatrix();
		yP += yP/2;
	}
}

void drawGarrafa(Object garrafa) {

    //Base
    drawVBO(garrafa.primitivas[0]);
    drawVBO(garrafa.primitivas[1]);

    //Cima
    glPushMatrix();
    glTranslatef(0.0f ,garrafa.vars[0]/2 + garrafa.vars[1]/2, 0.0f);
    drawVBO(garrafa.primitivas[2]);
    glPopMatrix();

    //Gargalo
    glPushMatrix();
    glTranslatef(0.0f ,garrafa.vars[0]/2 + garrafa.vars[1] + garrafa.vars[2]/2, 0.0f);
    drawVBO(garrafa.primitivas[3]);
    drawVBO(garrafa.primitivas[4]);
    glPopMatrix();

    //Border
    glPushMatrix();
    glTranslatef(0.0f ,garrafa.vars[0]/2 + garrafa.vars[1] +garrafa.vars[2], 0.0f);
    drawVBO(garrafa.primitivas[5]);
    glPopMatrix();
}

void drawCaipiraBar(Object caipira) {

    float profBalcao =3;

    //balcao frente
    glPushMatrix();
    drawVBO(caipira.primitivas[0]);
    glPopMatrix();

    //balcao direita
    glPushMatrix();
    glTranslatef( caipira.vars[1]/2 - profBalcao/2, 0, - (profBalcao/2)  - (caipira.vars[1] - profBalcao*2)/2);
    drawVBO(caipira.primitivas[1]);
    glPopMatrix();

    //balcao tras
    glPushMatrix();
    glTranslatef( 0, 0, -caipira.vars[1] +profBalcao);
    drawVBO(caipira.primitivas[0]);
    glPopMatrix();

    //barra abrir
    glPushMatrix();
    glTranslatef( - (caipira.vars[1]/2 - profBalcao/2), caipira.vars[0]/2 - (caipira.vars[0]/15)/2, - (profBalcao/2)  - (caipira.vars[1] - profBalcao*2)/2);
    drawVBO(caipira.primitivas[2]);
    glPopMatrix();

    //cilindro direita frente
    glPushMatrix();
    glTranslatef( caipira.vars[1] /2 - 0.5 *2, caipira.vars[0]/2 + 8 /2, 0);
    drawVBO(caipira.primitivas[3]);
    glPopMatrix();

    //cilindro direita tras
    glPushMatrix();
    glTranslatef( caipira.vars[1] /2 - 0.5 *2, caipira.vars[0]/2 + 8 /2, -caipira.vars[1] +profBalcao);
    drawVBO(caipira.primitivas[3]);
    glPopMatrix();

    //cilindro esquerda frente
    glPushMatrix();
    glTranslatef( - caipira.vars[1] /2 + 0.5 *2, caipira.vars[0]/2 + 8 /2, 0);
    drawVBO(caipira.primitivas[3]);
    glPopMatrix();

    //cilindro esquerda tras
    glPushMatrix();
    glTranslatef( - caipira.vars[1] /2 + 0.5*2, caipira.vars[0]/2 + 8 /2, -caipira.vars[1] +profBalcao);
    drawVBO(caipira.primitivas[3]);
    glPopMatrix();

    //tecto
    glPushMatrix();
    glTranslatef( 0, caipira.vars[0]/2 + 8, - (profBalcao/2)  - (caipira.vars[1] - profBalcao*2)/2);
    drawVBO(caipira.primitivas[4]);
    glPopMatrix();

    //movel centro

    float cuboLado = 5;

    glPushMatrix();
    glTranslatef( 0, (cuboLado/3) /2, - (profBalcao/2)  - (caipira.vars[1] - profBalcao*2)/2);
    drawVBO(caipira.primitivas[5]);
    glPopMatrix();
}
