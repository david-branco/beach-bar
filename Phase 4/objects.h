#include "header.h"

#include "vbo.h"

// //////////
// Structs
// //////////
typedef struct sObject {
    Primitiva *primitivas;
    int size;
    float *vars;
} Object;



// /////////////////////
// VBO
// /////////////////////

Object vboBar(Texture flooring, Texture wall, Texture sand, Texture columns, Texture metal,Texture ceiling, Texture glass);
Object vboBarreira(float comp, Texture texture);
Object vboCorrimao(float comp, Texture texture);
Object vboEscada(Texture texture);
Object vboBar(Texture flooring, Texture wall, Texture sand, Texture columns, Texture metal);
Object vboElements(float comp, float larg, Texture power);
Object vboBalcao(Texture texture);

Object vboMartini(int fatias, float alturaBase, float alturaPe, float alturaCone, float raioBase, float raioPe, float raioCone, Texture texture);
Object vboMartiniStick(float fatias, float alturaStick, float raioStick, float raioAzeitona, Texture olive, Texture stick);
Object vboTallGlass(int fatias, int gomos, float altura, float raio, Texture texture);
Object vboCaneca(float fatias, float raioI, float raioO, float raioCaneca, float alturaCaneca, Texture texture);
Object vboCerveja(float fatias, float gomos, float alturaBase, float raioBase, float raioBaseTopo, float alturaCopo, float raioCopo, Texture glass, Texture beer);
Object vboGlassWater(int fatias, float raio, float alturaPe, float alturaBase, float larguraBase, Texture texture);

Object vboCandeeiroTeto(int fatias, int gomos, float alturaFio, float alturaBase, float raioBase, float raioEsfera, Texture base, Texture luz);
Object vboCandeeiroChao(int fatias, float alturaBase, float raioBase, float alturaFio, float larguraTopo, float alturaTopo, Texture base, Texture luz, Texture lampada);
Object vboCandeeiroTetoCilindro(int fatias, int gomos, float alturaFio, float alturaBase, float raioBase, float altura, float raio, Texture base, Texture luz, Texture lamp);
Object vboFoco(int cubo, Texture texture);
Object vboLamp(int size, Texture texture);

Object vboMesaCafe (float raioTampo, float alturaTampo, int numPernas, float raioPerna, float alturaPerna, Texture texture);
Object vboMesaVidro (float compTampo, float largTampo, float altTampo, float altPerna, float largPerna, float compBase, float altBase, Texture perna, Texture tampo);
Object vboMesaVidroR (float raioTampo, float altTampo, float altPerna, float largPerna, float compBase, float altBase, Texture perna, Texture tampo);
Object vboEsplanadaPequena (float c, float p, Texture perna, Texture tampo);
Object vboMesaEsplanada(float compBase, float largBase, float altBase, int numTamposBase, float altTampos, float compTampos, float altPerna, float compPerna, float largPerna, Texture pernas, Texture tampo);

Object vboCadeiraSimples (float compTampo, float altTampo, float profTampo, float compPerna, float altPerna, float profPerna, float raioFerrinho, float altFerrinho, float compEncosto, float profEncosto, Texture texture);
Object vboCadeiraSimplesTabuas(float compTampo, float altTampo, float profTampo, float compPerna, float altPerna, float altEncosto, float compEncosto, int numEncosto, Texture texture);
Object vboBanco(float raioTampo, float altTampo, float altPerna, float largPerna, float tamBeira, float largBeira, float largBarra, Texture texture);
Object vboBancoI(float raioTampo, float altTampo, float altPerna, float largPerna, float inclinacao, float tamBeira, float largBeira, float largBarra, Texture perna, Texture almofada);
Object vboBancoQ(float compTampo, float largTampo, float altTampo, float altPerna, float largPerna, float tamBeira, float largBeira, float largBarra, Texture texture);
Object vboBancoQI(float compTampo, float largTampo, float altTampo, float altPerna, float largPerna, float inclinacao, float tamBeira, float largBeira, float largBarra, Texture texture);
Object vboBancoRedondo(float raioTampo, float altTampo, float raioPerna, float altPerna, Texture texture);
Object vboCadeiraDecor(float compBase, float largBase, float altBase, int numTamposBase, float altTampos, float compTampos, float altPerna, float compPerna, float largPerna, float altBracos, float difTampoeCostas, float altCostas, float compCostas, float largCostas, int numTamposCostas, Texture esqueleto, Texture tampo);
Object vboCadeiraDecorX(float compBase, float largBase, float altBase, int numTamposBase, float altTampos, float compTampos, float altPerna, float compPerna, float largPerna, float altBracos, float difTampoeCostas, float altCostas, float compCostas, float largCostas, int numTamposCostas, Texture esqueleto, Texture tampo);
Object vboCadeiraDecorInc(float compBase, float largBase, float altBase, int numTamposBase, float altTampos, float compTampos, float altPerna, float compPerna, float largPerna, float altBracos, float difTampoeCostas, float altCostas, float compCostas, float largCostas, int numTamposCostas, float inclinacao, Texture texture);
Object vboCadeiraFashion(float compTampo, float largTampo, float altTampo, float altCostas, float largCostas, float altPerna, float largPerna, float altBraco, Texture esqueleto, Texture almofada);
Object vboSofa(float compBase, float largBase, float altBase, float altLateral, float largLateral, float altCostas, float largCostas, int numAlmofadas, float compAlmofada, float grossAlmofada, float altApoio, float grossApoio, Texture almofada, Texture corpo);

Object vboGuardaSol(float fatias, float gomos, float alturaCone, float raioCone, float raioVarao, float alturaVarao, Texture varao, Texture topo);
Object vboPassadeira(int total, int rotacao, float altura, float largura, float comprimento, Texture texture);
Object vboBolaPraia(float fatias, float gomos, float raio, Texture texture);
Object vboToalhaPraia (float angulo, float altura, float largura, float comprimento, Texture texture);
Object vboQuadro(float altura, float largura, float comprimento, Texture texture);
Object vboEstante(float altura, float largCostas, float grossEstante, float compLateral, float grossPrateleira, Texture texture);
Object vboGarrafa(float fatias, float altBase, float raioBase, float alt, float raioGarg, float altGargalo, Texture texture);
Object vboCaipiraBar(float alturaBalcao, float lado, Texture base,Texture apoio, Texture balcao, Texture tecto);
// /////////////////////
// Draw
// /////////////////////

void drawBar(Object bar, Object barr1, Object barr2,Object barr3, Object barr4,Object escada,Object corrimao, Object balcao, Object power, Object air, Object sewer);

void drawMartini(Object copo);
void drawTallGlass(Object copo);
void drawMartiniStick(Object object);
void drawMartiniWithStick(Object copo, Object stick);
void drawCaneca(Object object);
void drawCerveja(Object object);
void drawGlassWater(Object object);

void drawCandeeiroTeto(Object candeeiro);
void drawCandeeiroChao(Object object);
void drawCandeeiroTetoCilindro(Object object);
void drawFoco(Object object);
void drawLamp(Object object);

void drawMesaCafe (Object mesa);
void drawMesaVidro (Object mesa);
void drawMesaVidroR (Object mesa);
void drawEsplanadaPequena (Object mesa);
void drawMesaEsplanada(Object mesa);

void drawCadeiraSimples (Object cadeira);
void drawCadeiraSimplesTabuas(Object cadeira);
void drawBanco(Object cadeira);
void drawBancoI(Object cadeira);
void drawBancoQ(Object cadeira);
void drawBancoQI(Object cadeira);
void drawBancoRedondo(Object cadeira);
void drawCadeiraDecor(Object cadeira);
void drawCadeiraDecorX(Object cadeira);
void drawCadeiraDecorInc(Object cadeira);
void drawCadeiraFashion(Object cadeira);
void drawSofa(Object cadeira);
void drawGuardaSol(Object guardaSol);
void drawPassadeira(Object passadeira);

void drawBolaPraia (Object bolaPraia);
void drawToalhaPraia (Object toalha);
void drawQuadro(Object quadro);
void drawEstante(Object estante);
void drawGarrafa(Object garrafa);
void drawCaipiraBar(Object caipira);
