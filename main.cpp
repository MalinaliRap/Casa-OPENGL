#include "casa.h"


GLfloat angle, fAspect, yai = 0.0f, ybi = 0.0f, ystep = 1.0f, color = 1.0f;

GLint  rotX, rotY, obsZ;

// Função callback chamada pela GLUT a cada intervalo de tempo
// (a window não está sendo redimensionada ou movida)
void Abre(int value)
{
	if(yai <= 90.0f && yai >= 0.0f){
		yai += ystep;
	}else{
		yai -= ystep;
	}
	
	if(ybi >= -90.0f && ybi <= 0.0f){
		ybi -= ystep;
	}else{
		ybi += ystep;
	}	

    // Redesenha com as novas coordenadas 
    glutPostRedisplay();
    //glutTimerFunc(30,Abre, 1);
   
}

void MudaCorMarron(int value)
{
		color = 0.0f;	

    // Redesenha com as novas coordenadas 
    glutPostRedisplay();
   
}

void MudaCorAzul(int value)
{
		color = 1.0f;	

    // Redesenha com as novas coordenadas 
    glutPostRedisplay();
   
}

void Fecha(int value)
{
	if(yai <= 90.0f && yai >= 0.0f){
		yai -= ystep;
	}else{
		yai += ystep;
	}

	
	if(ybi >= -90.0f && ybi <= 0.0f){
		ybi += ystep;
	}else{
		ybi -= ystep;
	}	

    // Redesenha com as novas coordenadas 
    glutPostRedisplay();
   	//glutTimerFunc(30,Fecha, 1);
}



void desenharObjeto(void (*funcPointer)(void), float x, float y, float z, float angl){
   glPushMatrix();
      glTranslatef(x, y, z); //move a parte para x,y,z
      glRotatef(angl, 0.0, 1.0, 0.0); //rotaciona a angl graus com normal y
      (*funcPointer)(); //finalmente, desenha com base na funcao passada
   glPopMatrix();
}


void ConfigurarIluminacao(void){
GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0}; 
        GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};          // "cor" 
        GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
        GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};
 
        // Capacidade de brilho do material
        GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
        GLint especMaterial = 60;
 
        // Define a refletância do material 
        glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE, especularidade);
        // Define a concentração do brilho
        glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
 
        // Ativa o uso da luz ambiente 
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
 
        // Define os parâmetros da luz de número 0
        glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
        glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
        glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
        glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );   
        
        glShadeModel(GL_FLAT);
        glEnable(GL_LIGHT0);
}

void PosicionaObservador(void)
{
        // Especifica sistema de coordenadas do modelo
        glMatrixMode(GL_MODELVIEW);
        // Inicializa sistema de coordenadas do modelo
        glLoadIdentity();
        ConfigurarIluminacao(); // INCLUA ESTA LINHA
}

void DesenharParedeFrente(void){
	glNormal3f (0.0f, 0.0f, 1.0f);
	glColorMaterial (GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glColor3f(0.45,0.20,color);
	glPushMatrix();
		glBegin(GL_QUADS);
			glVertex3f(-5.0,-5.0,5.0);
			glVertex3f(-5.0,-2.0,5.0);
			glVertex3f(-1.0,-2.0,5.0);
			glVertex3f(-1.0,-5.0,5.0);
		glEnd();
			glBegin(GL_QUADS);
			glVertex3f(5.0,-5.0,5.0);
			glVertex3f(5.0,-2.0,5.0);
			glVertex3f(1.0,-2.0,5.0);
			glVertex3f(1.0,-5.0,5.0);
		glEnd();
		glBegin(GL_QUADS);
			glVertex3f(-5.0,-2.0,5.0);
			glVertex3f(-5.0,0.0,5.0);
			glVertex3f(-4.0,0.0,5.0);
			glVertex3f(-4.0,-2.0,5.0);
		glEnd();
		glBegin(GL_QUADS);
			glVertex3f(-2.0,-2.0,5.0);
			glVertex3f(-2.0,0.0,5.0);
			glVertex3f(-1.0,0.0,5.0);
			glVertex3f(-1.0,-2.0,5.0);
		glEnd();
		glBegin(GL_QUADS);
			glVertex3f(5.0,-2.0,5.0);
			glVertex3f(5.0,0.0,5.0);
			glVertex3f(4.0,0.0,5.0);
			glVertex3f(4.0,-2.0,5.0);
		glEnd();
		glBegin(GL_QUADS);
			glVertex3f(2.0,-2.0,5.0);
			glVertex3f(2.0,0.0,5.0);
			glVertex3f(1.0,0.0,5.0);
			glVertex3f(1.0,-2.0,5.0);
		glEnd();
		glBegin(GL_QUADS);
			glVertex3f(-5.0,0.0,5.0);
			glVertex3f(-5.0,1.0,5.0);
			glVertex3f(5.0,1.0,5.0);
			glVertex3f(5.0,0.0,5.0);
		glEnd();
	glPopMatrix();
}

void DesenharParedeLateralEsquerda(void){
	glNormal3f (-1.0f, 0.0f, 0.0f);
	glColor3f(0.45,0.20,color);
	glPushMatrix();
		glBegin(GL_QUADS);
			glVertex3f(-5.0,-5.0,5.0);
			glVertex3f(-5.0,1.0,5.0);
			glVertex3f(-5.0,1.0,-5.0);
			glVertex3f(-5.0,-5.0,-5.0);
		glEnd();
	glPopMatrix();
}

void DesenharParedeLateralDireita(void){
	glNormal3f (1.0f, 0.0f, 0.0f);
	glColor3f(0.45,0.20,color);
	glPushMatrix();
		glBegin(GL_QUADS);
			glVertex3f(5.0,-5.0,5.0);
			glVertex3f(5.0,1.0,5.0);
			glVertex3f(5.0,1.0,-5.0);
			glVertex3f(5.0,-5.0,-5.0);
		glEnd();
	glPopMatrix();
}

void DesenharFundo(void){
	glNormal3f (0.0f, 1.0f, -1.0f);
	glColor3f(0.45,0.20,color);
	glPushMatrix();
		glBegin(GL_QUADS);
			glVertex3f(-5.0,-5.0,-5.0);
			glVertex3f(-5.0,1.0,-5.0);
			glVertex3f(5.0,1.0,-5.0);
			glVertex3f(5.0,-5.0,-5.0);
		glEnd();
	glPopMatrix();
}

void DesenharChao(void){
	glNormal3f (1.0f, 1.0f, 0.0f);
	glColor3f(0.7215,0.6078,0.2);
	glPushMatrix();
		glBegin(GL_QUADS);
			glVertex3f(-5.0,-5.0,5.0);
			glVertex3f(-5.0,-5.0,-5.0);
			glVertex3f(5.0,-5.0,-5.0);
			glVertex3f(5.0,-5.0,5.0);
		glEnd();
	glPopMatrix();
}

void DesenharPorta(void){

	glNormal3f (0.0f, 0.0f, 1.0f);
	glColor3f(0.7215,0.6078,0.2);
	glPushMatrix();
	glBegin(GL_QUADS);
			glVertex3f(0.0,-5.0,0.0);
			glVertex3f(2.0,-5.0,0.0);
			glVertex3f(2.0,0.0,0.0);
			glVertex3f(0.0,0.0,0.0);
	glEnd();
			glTranslated(1.5,-2.5,0.0);
        	glutSolidSphere(0.2,50,50);
	glPopMatrix();
}



void DesenharTeto(void){
	glNormal3f (1.0f, 1.0f, 1.0f);
	glColorMaterial (GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glColor3f(1.0,0.0,0.2);
	glPushMatrix();
		glBegin(GL_POLYGON);
			glVertex3f(-7.0,1.0,7.0);
			glVertex3f(7.0,1.0,7.0);
			glVertex3f(4.0,4.0,5.0);
			glVertex3f(-4.0,4.0,5.0);
		glEnd();
		glBegin(GL_POLYGON);
			glVertex3f(-7.0,1.0,-7.0);
			glVertex3f(7.0,1.0,-7.0);
			glVertex3f(4.0,4.0,-5.0);
			glVertex3f(-4.0,4.0,-5.0);
		glEnd();
		glBegin(GL_POLYGON);
			glVertex3f(-7.0,1.0,7.0);
			glVertex3f(-7.0,1.0,-7.0);
			glVertex3f(-4.0,4.0,-7.0);
			glVertex3f(-4.0,4.0,7.0);
		glEnd();
		glBegin(GL_POLYGON);
			glVertex3f(7.0,1.0,7.0);
			glVertex3f(7.0,1.0,-7.0);
			glVertex3f(4.0,4.0,-7.0);
			glVertex3f(4.0,4.0,7.0);
		glEnd();
		glBegin(GL_POLYGON);
			glVertex3f(4.0,4.0,7.0);
			glVertex3f(4.0,4.0,-7.0);
			glVertex3f(-4.0,4.0,-7.0);
			glVertex3f(-4.0,4.0,7.0);
		glEnd();
	glPopMatrix();
}

void DesenharJanelaL(void){
	glNormal3f (0.0f, 0.0f, 1.0f);
	glColorMaterial (GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glColor3f(0.7215,0.6078,0.2);
	glPushMatrix();
		glBegin(GL_QUADS);
			glVertex3f(0.0,-2.0,0.0);
			glVertex3f(0.0,0.0,0.0);
			glVertex3f(0.25,0.0,0.0);
			glVertex3f(0.25,-2.0,0.0);
		glEnd();
		glBegin(GL_QUADS);
			glVertex3f(0.75,-2.0,0.0);
			glVertex3f(0.75,0.0,0.0);
			glVertex3f(1.0,0.0,0.0);
			glVertex3f(1.00,-2.0,0.0);
		glEnd();
		glBegin(GL_QUADS);
			glVertex3f(0.25, 0.0,0.0);
			glVertex3f(0.25, -0.25,0.0);
			glVertex3f(0.75,-0.25,0.0);
			glVertex3f(0.75,0.0,0.0);
		glEnd();
		glBegin(GL_QUADS);
			glVertex3f(0.25, -1.75,0.0);
			glVertex3f(0.25, -2.00,0.0);
			glVertex3f(0.75,-2.00,0.0);
			glVertex3f(0.75,-1.75,0.0);
		glEnd();
		//vidro
		glColor4f(1.0,1.0,1.0,0.5);
		glBegin(GL_QUADS);
			glVertex3f(0.25,-1.75,0.0);
			glVertex3f(0.75,-1.75,0.0);
			glVertex3f(0.75,-0.25,0.0);
			glVertex3f(0.25,-0.25,0.0);
		glEnd();
	glPopMatrix();
}

void DesenharJanelaR(void){
	glNormal3f (0.0f, 0.0f, 1.0f);
	glColorMaterial (GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glColor3f(0.7215,0.6078,0.2);
	glPushMatrix();
		glBegin(GL_QUADS);
			glVertex3f(0.0,-2.0,0.0);
			glVertex3f(0.0,0.0,0.0);
			glVertex3f(-0.25,0.0,0.0);
			glVertex3f(-0.25,-2.0,0.0);
		glEnd();
		glBegin(GL_QUADS);
			glVertex3f(-0.75,-2.0,0.0);
			glVertex3f(-0.75,0.0,0.0);
			glVertex3f(-1.0,0.0,0.0);
			glVertex3f(-1.00,-2.0,0.0);
		glEnd();
		glBegin(GL_QUADS);
			glVertex3f(-0.25, 0.0,0.0);
			glVertex3f(-0.25, -0.25,0.0);
			glVertex3f(-0.75,-0.25,0.0);
			glVertex3f(-0.75,0.0,0.0);
		glEnd();
		glBegin(GL_QUADS);
			glVertex3f(-0.25, -1.75,0.0);
			glVertex3f(-0.25, -2.00,0.0);
			glVertex3f(-0.75,-2.00,0.0);
			glVertex3f(-0.75,-1.75,0.0);
		glEnd();
		//vidro
		glColor4f(1.0,1.0,1.0,0.5);
		glBegin(GL_QUADS);
			glVertex3f(-0.25,-1.75,0.0);
			glVertex3f(-0.75,-1.75,0.0);
			glVertex3f(-0.75,-0.25,0.0);
			glVertex3f(-0.25,-0.25,0.0);
		glEnd();
	glPopMatrix();
}



void DesenharParedes(void){

		DesenharParedeFrente();
		DesenharParedeLateralEsquerda();
		DesenharParedeLateralDireita();
		DesenharFundo();
	// Executa os comandos OpenGL
	
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
ConfigurarIluminacao();
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

DesenharChao();
DesenharParedes();
DesenharTeto();
desenharObjeto(&DesenharPorta,-1.0,0.0,5.0,yai);
desenharObjeto(&DesenharJanelaL,-4.0,0.0,5.0,yai);
desenharObjeto(&DesenharJanelaR,-2.0,0.0,5.0,ybi);
desenharObjeto(&DesenharJanelaL,2.0,0.0,5.0,yai);
desenharObjeto(&DesenharJanelaR,4.0,0.0,5.0,ybi);

glutSwapBuffers();

}

// Inicializa parâmetros de rendering
void Inicializa (void)
{ 
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    glEnable (GL_POINT_SMOOTH);
    glEnable (GL_LINE_SMOOTH);
    glEnable (GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    // Habilita o modelo de colorização de Gouraud
    glShadeModel(GL_SMOOTH);
    glEnable (GL_NORMALIZE);
	glEnable (GL_COLOR_MATERIAL);
	glEnable (GL_TEXTURE_2D); 
    angle=50;  
    glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho (-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	
    // Inicializa as variáveis usadas para alterar a posição do 
    // observador virtual
    rotX = 30;
    rotY = 0;
    obsZ = 180; 

}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
    gluPerspective(angle,fAspect,0.5,500);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
    gluLookAt(20,10,30, 0,0,0, 0,1,0);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
    glViewport(0, 0, w, h);
 
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}



void mouseInput(int button, int state, int x, int y){

	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130) angle += 5;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
	
}

void keyInput(unsigned char key, int x, int y){

   switch(key) 
   {
      case 27:
         exit(0);
         break;
      case 'o': //abre porta
      	glutTimerFunc(30,Abre, 1);
         break;
      case 'c': //fecha
        glutTimerFunc(30,Fecha, 1);
         break;
      case '0': //muda coir
        glutTimerFunc(10,MudaCorMarron, 1);
         break;
      case '1': //muda coir
        glutTimerFunc(10,MudaCorAzul, 1);
         break;
    
   }
}


// Programa Principal
int main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(500, 150); 
	glutCreateWindow("CASA");
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutKeyboardFunc(keyInput);
    glutMouseFunc(mouseInput);
	Inicializa();
	glutMainLoop();
}
