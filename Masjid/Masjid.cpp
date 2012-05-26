#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>


static int slices = 25;
static int stacks = 25;

float ratio;					// Full-Screen Kamera
float yCord = -2.5;				// Koordinat Y
float zCord = -60.0;			// Koordinat Z
float xCord = 0.0;				// Koordinat X
float RotateX = -210.0f;			// Posisi Awal 
float RotasiKipas = 0.0f;		// Posisi Awal Kipas Kamar
float RotasiKipas2 = 0.0f;		// Posisi Awal Kipas Ruang Tamu
float RotationSpeedX = 0.0f;	// Kecepatan Rotasi Sumbu
float KecRot = 0.0f;			// Kecepatan Rotasi Kamar
float KecRot2 = 0.0f;			// Kecepatan Rotasi Ruang Tamu
float LightZ = 26.0f;			// Posisi cahaya Z
float LightX = 0.0f;			// Posisi cahaya X
float LightY = 5.0f;			// Posisi cahaya Y

bool fullscreenexit = true; 
unsigned int 	windowWidth= 800, 
				windowHeight= 600, 
				windowPosX= 50, 
				windowPosY= 50; 



GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat light_position[] = { LightX, LightY, LightZ, 0.0f };

GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat high_shininess[] = { 100.0f };

void sumbu (void){
    glColor3f(1.0, 0.0, 0.0);    
    glBegin(GL_LINES);  //=======================> Sumbu x (MERAH)
        glVertex3f(0.0, 0.0, 0.0); //titik kiri
        glVertex3f(0.0, 0.0, 0.0); //titik kanan
    glEnd();
    
    glColor3f(0.0, 1.0, 0.0);   
    glBegin(GL_LINES);  //=======================> Sumbu y (HIJAU)
        glVertex3f(0.0, 0, 0.0); //titik atas
        glVertex3f(0.0, 0.0, 0.0); //titik bawah
    glEnd();
    
    glColor3f(0.0, 0.0, 1.0);    
    glBegin(GL_LINES);  //=======================> Sumbu z (BIRU)
        glVertex3f(0.0, 0.0,0.0); //titik belakang
        glVertex3f(0.0, 0.0,0.0); //titik depan
    glEnd();     
}

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;
    
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
	const double t= glutGet(GLUT_ELAPSED_TIME) /15000.0;
	const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,yCord,zCord);
	glTranslatef(0.0,yCord,0.0);
	glTranslatef(xCord,0.0,0.0);
	glRotatef(RotateX, 0, 1.0, 0);
	RotasiKipas += KecRot;
	RotasiKipas2 += KecRot2;
	RotateX += RotationSpeedX;
    
    glPushMatrix();
        sumbu();
    glPopMatrix();

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX R. Bangunan Utama XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    // bagian dalam

    //lampu 1
	glPushMatrix();  // Dudukan Lampu  ========================================>
        glTranslated(18,9.5,0);
		glScaled(2.5,1.0,2.5);
        glColor3d(0.0,0.0,0.0);
        glutSolidCube(1);
    glPopMatrix();    
	glPushMatrix();  // Bola Lampu  ===========================================>
        glTranslated(18,9.0,0);
		glScaled(2.5,0.8,2.5);
        glColor3d(1.0,1.0,1.0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
    //lampu 2
	glPushMatrix();  // Dudukan Lampu  ========================================>
        glTranslated(-18,9.5,0);
		glScaled(2.5,1.0,2.5);
        glColor3d(0.0,0.0,0.0);
        glutSolidCube(1);
    glPopMatrix();    
	glPushMatrix();  // Bola Lampu  ===========================================>
        glTranslated(-18,9.0,0);
		glScaled(2.5,0.8,2.5);
        glColor3d(1.0,1.0,1.0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
    //lampu 3
	glPushMatrix();  // Dudukan Lampu  ========================================>
        glTranslated(0,9.5,-18);
		glScaled(2.5,1.0,2.5);
        glColor3d(0.0,0.0,0.0);
        glutSolidCube(1);
    glPopMatrix();    
	glPushMatrix();  // Bola Lampu  ===========================================>
        glTranslated(0,9.0,-18);
		glScaled(2.5,0.8,2.5);
        glColor3d(1.0,1.0,1.0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
    //lampu 4
	glPushMatrix();  // Dudukan Lampu  ========================================>
        glTranslated(0,9.5,18);
		glScaled(2.5,1.0,2.5);
        glColor3d(0.0,0.0,0.0);
        glutSolidCube(1);
    glPopMatrix();    
	glPushMatrix();  // Bola Lampu  ===========================================>
        glTranslated(0,9.0,18);
		glScaled(2.5,0.8,2.5);
        glColor3d(1.0,1.0,1.0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();


    //Tempat imam    
    //mimbar
   	glPushMatrix();  // Kotak Utama  ==========================================>
        glTranslated(14,-1.5,8);
		glScaled(4.0,6,3.6);
        glColor3d(1,0.4,0.0);
        glutSolidCube(1);
    glPopMatrix();
    
   	glPushMatrix();  // gagang mic  =================================>
        glTranslated(13,1.5,8);
		glScaled(0.2,2.5,0.2);
        glColor3d(0.0,0.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
	glPushMatrix();  // busa mic  ===========================================>
        glTranslated(13,3,8);
		glScaled(0.3,0.3,0.3);
        glColor3d(0.5,0.5,0.5);
        glutWireSphere(1,slices,stacks);
    glPopMatrix();

    
   	glPushMatrix();  // Textur mimbar bawah 1        ===========================>
        glTranslated(14,-3,9.8);
		glScaled(2.5,0.8,0.2);
        glColor3d(1.0,0.6,0.0);
        glutSolidCube(1);
    glPopMatrix();

   	glPushMatrix();  // Textur mimbar atas 1        ===========================>
        glTranslated(14,0,9.8);
		glScaled(2.5,0.8,0.2);
        glColor3d(1.0,0.6,0.0);
        glutSolidCube(1);
    glPopMatrix();

   	glPushMatrix();  // Textur mimbar bawah 2        ===========================>
        glTranslated(14,-3,6.2);
		glScaled(2.5,0.8,0.2);
        glColor3d(1.0,0.6,0.0);
        glutSolidCube(1);
    glPopMatrix();

   	glPushMatrix();  // Textur mimbar atas 2        ===========================>
        glTranslated(14,0,6.2);
		glScaled(2.5,0.8,0.2);
        glColor3d(1.0,0.6,0.0);
        glutSolidCube(1);
    glPopMatrix();


  
    // Kursi
	glPushMatrix();  // Bantalan Kursi 1 Dari Belakang  =======================>
        glTranslated(20.0,-3,8);
		glScaled(2,1.5,2);
        glColor3d(0.5,0.5,0.5);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();

	glPushMatrix();  // Sandaran Kursi 1 Dari Belakang  =======================>
        glTranslated(22.0,-2,8);
		glScaled(0.5,2.0,2);
        glColor3d(0.5,0.5,0.5);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
	
    glPushMatrix();  // Sandaran Kursi 1 Dari kanan  =======================>
        glTranslated(20.0,-2,6);
		glScaled(2,1.5,0.5);
        glColor3d(0.5,0.5,0.5);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
    glPushMatrix();  // Sandaran Kursi 1 Dari kiri  =======================>
        glTranslated(20.0,-2,10);
		glScaled(2,1.5,0.5);
        glColor3d(0.5,0.5,0.5);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();

    
    //ruang imam
	glPushMatrix();  // Bingkai ruang kanan Sumbu X Berdiri  ========================>
        glTranslated(23.5,0.25,4);
		glScaled(8,10,0.8);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
	glPushMatrix();  // Bingkai ruang kiri Sumbu X Berdiri  ========================>
        glTranslated(23.5,0.25,-4);
		glScaled(8,10,0.8);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();  // Bingkai ruang atas Sumbu X Baring  =========================>
        glTranslated(23.5,4.85,0);
		glScaled(8,0.8,8);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    
	// Jendela ruang imam
    glPushMatrix();  // Dudukan Besi Kecil Kanan  =============================>
        glTranslated(27,4,-2);
		glScaled(0.8,0.2,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Dudukan Besi Kecil Kiri  ==============================>
        glTranslated(27,4,2);
		glScaled(0.8,0.2,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Dudukan Besi Panjang  =================================>
        glTranslated(27.4,4,0);
		glScaled(0.2,0.2,4.0);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tali Pengaturan Tirai  ================================>
        glTranslated(27.4,1,-2.1);
		glScaled(0.06,6,0.06);
        glColor3d(0.0,0.0,0.0);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Gantelan Tali  ========================================>
        glTranslated(27.4,-2,-2.1);
		glScaled(0.1,0.4,0.1);
        glColor3d(0.0,0.0,1.0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
	
	glPushMatrix();  // Tirai Besi 1 Dari Kiri  ===============================>
        glTranslated(27.4,0.2,2);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 2 Dari Kiri  ===============================>
        glTranslated(27.4,0.2,1.8);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 3 Dari Kiri  ===============================>
        glTranslated(27.4,0.2,1.6);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 4 Dari Kiri  ===============================>
        glTranslated(27.4,0.2,1.4);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 5 Dari Kiri  ===============================>
        glTranslated(27.4,0.2,1.2);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 6 Dari Kiri  ===============================>
        glTranslated(27.4,0.2,1);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 7 Dari Kiri  ===============================>
        glTranslated(27.4,0.2,0.8);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tirai Besi 8 Dari Kiri  ===============================>
        glTranslated(27.4,0.2,0.6);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tirai Besi 9 Dari Kiri  ===============================>
        glTranslated(27.4,0.2,0.4);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 10 Dari Kiri  ==============================>
        glTranslated(27.4,0.2,0.2);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();
	
	glPushMatrix();  // Tirai Besi 11 Dari Kiri  ==============================>
        glTranslated(27.4,0.2,0);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 12 Dari Kiri  ==============================>
        glTranslated(27.4,0.2,-0.2);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 13 Dari Kiri  ==============================>
        glTranslated(27.4,0.2,-0.4);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 14 Dari Kiri  ==============================>
        glTranslated(27.4,0.2,-0.6);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 15 Dari Kiri  ==============================>
        glTranslated(27.4,0.2,-0.8);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 16 Dari Kiri  ==============================>
        glTranslated(27.4,0.2,-1);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 17 Dari Kiri  ==============================>
        glTranslated(27.4,0.2,-1.2);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 18 Dari Kiri  ==============================>
        glTranslated(27.4,0.2,-1.4);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 19 Dari Kiri  ==============================>
        glTranslated(27.4,0.2,-1.6);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 20 Dari Kiri  ==============================>
        glTranslated(27.4,0.2,-1.8);
		glScaled(0.2,7.5,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();
    
    
    
	// Lantai  ==========================================================================>
	//lantai1
	glPushMatrix();  // lantai Dasar  ===========================================>
        glTranslated(0,-5,0);
		glScaled(55,0.3,55);
        glColor3d(0.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();

	//Pintu 1
	glPushMatrix();  // Bingkai Pintu kanan Sumbu X Berdiri  ========================>
        glTranslated(4,0.2,27.25);
		glScaled(0.8,10,0.5);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
	glPushMatrix();  // Bingkai Pintu kiri Sumbu X Berdiri  ========================>
        glTranslated(-4,0.2,27.25);
		glScaled(0.8,10,0.5);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();  // Bingkai Pintu atas Sumbu X Baring  =========================>
        glTranslated(0,4.8,27.25);
		glScaled(8,0.8,0.5);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();

	
    //Pintu 2
	glPushMatrix();  // Bingkai Pintu kanan Sumbu X Berdiri  ========================>
        glTranslated(4,0.2,-27.25);
		glScaled(0.8,10,0.5);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
	glPushMatrix();  // Bingkai Pintu kiri Sumbu X Berdiri  ========================>
        glTranslated(-4,0.2,-27.25);
		glScaled(0.8,10,0.5);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();  // Bingkai Pintu atas Sumbu X Baring  =========================>
        glTranslated(0,4.8,-27.25);
		glScaled(8,0.8,0.5);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
	
    //Pintu 3
	glPushMatrix();  // Bingkai Pintu kanan Sumbu X Berdiri  ========================>
        glTranslated(-27.25,0.2,4);
		glScaled(0.5,10,0.8);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
	glPushMatrix();  // Bingkai Pintu kiri Sumbu X Berdiri  ========================>
        glTranslated(-27.25,0.2,-4);
		glScaled(0.5,10,0.8);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();  // Bingkai Pintu atas Sumbu X Baring  =========================>
        glTranslated(-27.25,4.85,0);
		glScaled(0.5,0.8,8);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();


    //Tembok 
    //tembok 1
    glPushMatrix();  // Bingkai tembok kanan Sumbu X Berdiri  ========================>
        glTranslated(27.1,2.85,27.25);
		glScaled(0.8,15,0.5);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();  // Bingkai tembok kiri Sumbu X Berdiri  ========================>
        glTranslated(-27.1,2.85,27.25);
		glScaled(0.8,15,0.5);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();  // Bingkai tembok atas Sumbu X Baring  =========================>
        glTranslated(0,10,27.25);
		glScaled(55,0.8,0.5);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();  // Bingkai tembok bawah kanan Sumbu X Baring  =========================>
        glTranslated(15.6,-4.4,27.25);
		glScaled(23.8,0.8,0.5);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();  // Bingkai tembok bawah kiri Sumbu X Baring  =========================>
        glTranslated(-15.55,-4.4,27.25);
		glScaled(23.8,0.8,0.5);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    
    //tembok 2
    glPushMatrix();  // Bingkai tembok kanan Sumbu X Berdiri  ========================>
        glTranslated(-27.1,2.85,-27.25);
		glScaled(0.8,15,0.5);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();  // Bingkai tembok kiri Sumbu X Berdiri  ========================>
        glTranslated(27.1,2.85,-27.25);
		glScaled(0.8,15,0.5);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();  // Bingkai tembok atas Sumbu X Baring  =========================>
        glTranslated(0,10,-27.25);
		glScaled(55,0.8,0.5);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();  // Bingkai tembok bawah kanan Sumbu X Baring  =========================>
        glTranslated(-15.6,-4.4,-27.25);
		glScaled(23.8,0.8,0.5);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();  // Bingkai tembok bawah kiri Sumbu X Baring  =========================>
        glTranslated(15.55,-4.4,-27.25);
		glScaled(23.8,0.8,0.5);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    
    //tembok 3
    glPushMatrix();  // Bingkai tembok kanan Sumbu X Berdiri  ========================>
        glTranslated(-27.25,2.8,27.1);
		glScaled(0.5,15,0.8);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();  // Bingkai tembok kiri Sumbu X Berdiri  ========================>
        glTranslated(-27.25,2.8,-27.1);
		glScaled(0.5,15,0.8);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();  // Bingkai tembok atas Sumbu X Baring  =========================>
        glTranslated(-27.25,10,0);
		glScaled(0.5,0.8,55);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();  // Bingkai tembok kiri Sumbu X Baring  =========================>
        glTranslated(-27.25,-4.4,-15.9);
		glScaled(0.5,0.8,23.15);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();    
    glPushMatrix();  // Bingkai tembok kanan Sumbu X Baring  =========================>
        glTranslated(-27.25,-4.4,15.9);
		glScaled(0.5,0.8,23.15);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();  
     // tembok 4
    glPushMatrix();  // Bingkai tembok kanan Sumbu X Berdiri  ========================>
        glTranslated(27.25,2.8,-27.1);
		glScaled(0.5,15,0.8);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();  // Bingkai tembok kiri Sumbu X Berdiri  ========================>
        glTranslated(27.25,2.8,27.1);
		glScaled(0.5,15,0.8);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();  // Bingkai tembok atas Sumbu X Baring  =========================>
        glTranslated(27.25,10,0);
		glScaled(0.5,0.8,55);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();  // Bingkai tembok bawah Sumbu X Baring  =========================>
        glTranslated(27.25,-4.4,0);
		glScaled(0.5,0.8,55);
        glColor3d(1.0,1.0,0.0);
        glutSolidCube(1);
    glPopMatrix();
    
    //jendela 
    //jendela 1 kiri
    glPushMatrix();  // Dudukan Besi Panjang  =================================>
        glTranslated(15.5,9,-27.25);
		glScaled(18,0.2,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tali Pengaturan Tirai  ================================>
        glTranslated(24.5,4,-27.25);
		glScaled(0.06,10,0.06);
        glColor3d(0.0,0.0,0.0);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Gantelan Tali  ========================================>
        glTranslated(24.5,-1,-27.25);
		glScaled(0.1,0.4,0.1);
        glColor3d(0.0,0.0,1.0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
	
	glPushMatrix();  // Tirai Besi 1 Dari Kiri  ===============================>
        glTranslated(23.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 2 Dari Kiri  ===============================>
        glTranslated(22.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 3 Dari Kiri  ===============================>
        glTranslated(21.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 4 Dari Kiri  ===============================>
        glTranslated(20.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 5 Dari Kiri  ===============================>
        glTranslated(19.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 6 Dari Kiri  ===============================>
        glTranslated(18.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 7 Dari Kiri  ===============================>
        glTranslated(17.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tirai Besi 8 Dari Kiri  ===============================>
        glTranslated(16.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tirai Besi 9 Dari Kiri  ===============================>
        glTranslated(15.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 10 Dari Kiri  ==============================>
        glTranslated(14.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();
	
	glPushMatrix();  // Tirai Besi 11 Dari Kiri  ==============================>
        glTranslated(13.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 12 Dari Kiri  ==============================>
        glTranslated(12.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 13 Dari Kiri  ==============================>
        glTranslated(11.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 14 Dari Kiri  ==============================>
        glTranslated(10.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 15 Dari Kiri  ==============================>
        glTranslated(9.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 16 Dari Kiri  ==============================>
        glTranslated(8.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 17 Dari Kiri  ==============================>
        glTranslated(7.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 18 Dari Kiri  ==============================>
        glTranslated(6.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    //jendela 1 KAnan
    glPushMatrix();  // Dudukan Besi Panjang  =================================>
        glTranslated(-15.5,9,-27.25);
		glScaled(18,0.2,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tali Pengaturan Tirai  ================================>
        glTranslated(-24.5,4,-27.25);
		glScaled(0.06,10,0.06);
        glColor3d(0.0,0.0,0.0);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Gantelan Tali  ========================================>
        glTranslated(-24.5,-1,-27.25);
		glScaled(0.1,0.4,0.1);
        glColor3d(0.0,0.0,1.0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
	
	glPushMatrix();  // Tirai Besi 1 Dari Kiri  ===============================>
        glTranslated(-23.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 2 Dari Kiri  ===============================>
        glTranslated(-22.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 3 Dari Kiri  ===============================>
        glTranslated(-21.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 4 Dari Kiri  ===============================>
        glTranslated(-20.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 5 Dari Kiri  ===============================>
        glTranslated(-19.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 6 Dari Kiri  ===============================>
        glTranslated(-18.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 7 Dari Kiri  ===============================>
        glTranslated(-17.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tirai Besi 8 Dari Kiri  ===============================>
        glTranslated(-16.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tirai Besi 9 Dari Kiri  ===============================>
        glTranslated(-15.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 10 Dari Kiri  ==============================>
        glTranslated(-14.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();
	
	glPushMatrix();  // Tirai Besi 11 Dari Kiri  ==============================>
        glTranslated(-13.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 12 Dari Kiri  ==============================>
        glTranslated(-12.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 13 Dari Kiri  ==============================>
        glTranslated(-11.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 14 Dari Kiri  ==============================>
        glTranslated(-10.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 15 Dari Kiri  ==============================>
        glTranslated(-9.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 16 Dari Kiri  ==============================>
        glTranslated(-8.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 17 Dari Kiri  ==============================>
        glTranslated(-7.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 18 Dari Kiri  ==============================>
        glTranslated(-6.5,3,-27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();



    //jendela 2 kanan
    glPushMatrix();  // Dudukan Besi Panjang  =================================>
        glTranslated(15.5,9,27.25);
		glScaled(18,0.2,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tali Pengaturan Tirai  ================================>
        glTranslated(24.5,4,27.25);
		glScaled(0.06,10,0.06);
        glColor3d(0.0,0.0,0.0);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Gantelan Tali  ========================================>
        glTranslated(24.5,-1,27.25);
		glScaled(0.1,0.4,0.1);
        glColor3d(0.0,0.0,1.0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
	
	glPushMatrix();  // Tirai Besi 1 Dari Kiri  ===============================>
        glTranslated(23.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 2 Dari Kiri  ===============================>
        glTranslated(22.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 3 Dari Kiri  ===============================>
        glTranslated(21.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 4 Dari Kiri  ===============================>
        glTranslated(20.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 5 Dari Kiri  ===============================>
        glTranslated(19.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 6 Dari Kiri  ===============================>
        glTranslated(18.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 7 Dari Kiri  ===============================>
        glTranslated(17.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tirai Besi 8 Dari Kiri  ===============================>
        glTranslated(16.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tirai Besi 9 Dari Kiri  ===============================>
        glTranslated(15.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 10 Dari Kiri  ==============================>
        glTranslated(14.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();
	
	glPushMatrix();  // Tirai Besi 11 Dari Kiri  ==============================>
        glTranslated(13.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 12 Dari Kiri  ==============================>
        glTranslated(12.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 13 Dari Kiri  ==============================>
        glTranslated(11.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 14 Dari Kiri  ==============================>
        glTranslated(10.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 15 Dari Kiri  ==============================>
        glTranslated(9.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 16 Dari Kiri  ==============================>
        glTranslated(8.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 17 Dari Kiri  ==============================>
        glTranslated(7.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 18 Dari Kiri  ==============================>
        glTranslated(6.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    //jendela 2 kiri
    glPushMatrix();  // Dudukan Besi Panjang  =================================>
        glTranslated(-15.5,9,27.25);
		glScaled(18,0.2,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tali Pengaturan Tirai  ================================>
        glTranslated(-24.5,4,27.25);
		glScaled(0.06,10,0.06);
        glColor3d(0.0,0.0,0.0);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Gantelan Tali  ========================================>
        glTranslated(-24.5,-1,27.25);
		glScaled(0.1,0.4,0.1);
        glColor3d(0.0,0.0,1.0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
	
	glPushMatrix();  // Tirai Besi 1 Dari Kiri  ===============================>
        glTranslated(-23.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 2 Dari Kiri  ===============================>
        glTranslated(-22.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 3 Dari Kiri  ===============================>
        glTranslated(-21.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 4 Dari Kiri  ===============================>
        glTranslated(-20.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 5 Dari Kiri  ===============================>
        glTranslated(-19.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 6 Dari Kiri  ===============================>
        glTranslated(-18.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 7 Dari Kiri  ===============================>
        glTranslated(-17.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tirai Besi 8 Dari Kiri  ===============================>
        glTranslated(-16.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tirai Besi 9 Dari Kiri  ===============================>
        glTranslated(-15.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 10 Dari Kiri  ==============================>
        glTranslated(-14.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();
	
	glPushMatrix();  // Tirai Besi 11 Dari Kiri  ==============================>
        glTranslated(-13.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 12 Dari Kiri  ==============================>
        glTranslated(-12.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 13 Dari Kiri  ==============================>
        glTranslated(-11.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 14 Dari Kiri  ==============================>
        glTranslated(-10.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 15 Dari Kiri  ==============================>
        glTranslated(-9.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 16 Dari Kiri  ==============================>
        glTranslated(-8.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 17 Dari Kiri  ==============================>
        glTranslated(-7.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 18 Dari Kiri  ==============================>
        glTranslated(-6.5,3,27.25);
		glScaled(0.01,12,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();


    
    
    //jendela 3 Kanan
    glPushMatrix();  // Dudukan Besi Panjang  =================================>
        glTranslated(-27.25,9,15.5);
		glScaled(0.2,0.2,18);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tali Pengaturan Tirai  ================================>
        glTranslated(-27.25,4,24.5);
		glScaled(0.06,10,0.06);
        glColor3d(0.0,0.0,0.0);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Gantelan Tali  ========================================>
        glTranslated(-27.25,-1,24.5);
		glScaled(0.1,0.4,0.1);
        glColor3d(0.0,0.0,1.0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
	
	glPushMatrix();  // Tirai Besi 1 Dari Kiri  ===============================>
        glTranslated(-27.25,3,6.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 2 Dari Kiri  ===============================>
        glTranslated(-27.25,3,7.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 3 Dari Kiri  ===============================>
        glTranslated(-27.25,3,8.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 4 Dari Kiri  ===============================>
        glTranslated(-27.25,3,9.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 5 Dari Kiri  ===============================>
        glTranslated(-27.25,3,10.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 6 Dari Kiri  ===============================>
        glTranslated(-27.25,3,11.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 7 Dari Kiri  ===============================>
        glTranslated(-27.25,3,12.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tirai Besi 8 Dari Kiri  ===============================>
        glTranslated(-27.25,3,13.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tirai Besi 9 Dari Kiri  ===============================>
        glTranslated(-27.25,3,14.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 10 Dari Kiri  ==============================>
        glTranslated(-27.25,3,15.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();
	
	glPushMatrix();  // Tirai Besi 11 Dari Kiri  ==============================>
        glTranslated(-27.25,3,16.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 12 Dari Kiri  ==============================>
        glTranslated(-27.25,3,17.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 13 Dari Kiri  ==============================>
        glTranslated(-27.25,3,18.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 14 Dari Kiri  ==============================>
        glTranslated(-27.25,3,19.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 15 Dari Kiri  ==============================>
        glTranslated(-27.25,3,20.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 16 Dari Kiri  ==============================>
        glTranslated(-27.25,3,21.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 17 Dari Kiri  ==============================>
        glTranslated(-27.25,3,22.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 18 Dari Kiri  ==============================>
        glTranslated(-27.25,3,23.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    //jendela 3 kiri
    glPushMatrix();  // Dudukan Besi Panjang  =================================>
        glTranslated(-27.25,9,-15.5);
		glScaled(0.2,0.2,18);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tali Pengaturan Tirai  ================================>
        glTranslated(-27.25,4,-24.5);
		glScaled(0.06,10,0.06);
        glColor3d(0.0,0.0,0.0);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Gantelan Tali  ========================================>
        glTranslated(-27.25,-1,-24.5);
		glScaled(0.1,0.4,0.1);
        glColor3d(0.0,0.0,1.0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
	
	glPushMatrix();  // Tirai Besi 1 Dari Kiri  ===============================>
        glTranslated(-27.25,3,-6.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 2 Dari Kiri  ===============================>
        glTranslated(-27.25,3,-7.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 3 Dari Kiri  ===============================>
        glTranslated(-27.25,3,-8.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 4 Dari Kiri  ===============================>
        glTranslated(-27.25,3,-9.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 5 Dari Kiri  ===============================>
        glTranslated(-27.25,3,-10.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 6 Dari Kiri  ===============================>
        glTranslated(-27.25,3,-11.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 7 Dari Kiri  ===============================>
        glTranslated(-27.25,3,-12.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tirai Besi 8 Dari Kiri  ===============================>
        glTranslated(-27.25,3,-13.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tirai Besi 9 Dari Kiri  ===============================>
        glTranslated(-27.25,3,-14.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 10 Dari Kiri  ==============================>
        glTranslated(-27.25,3,-15.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();
	
	glPushMatrix();  // Tirai Besi 11 Dari Kiri  ==============================>
        glTranslated(-27.25,3,-16.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 12 Dari Kiri  ==============================>
        glTranslated(-27.25,3,-17.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 13 Dari Kiri  ==============================>
        glTranslated(-27.25,3,-18.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 14 Dari Kiri  ==============================>
        glTranslated(-27.25,3,-19.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 15 Dari Kiri  ==============================>
        glTranslated(-27.25,3,-20.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 16 Dari Kiri  ==============================>
        glTranslated(-27.25,3,-21.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 17 Dari Kiri  ==============================>
        glTranslated(-27.25,3,-22.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 18 Dari Kiri  ==============================>
        glTranslated(-27.25,3,-23.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    //jendela 4 kiri
    glPushMatrix();  // Dudukan Besi Panjang  =================================>
        glTranslated(27.25,9,-15.5);
		glScaled(0.2,0.2,18);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tali Pengaturan Tirai  ================================>
        glTranslated(27.25,4,-24.5);
		glScaled(0.06,10,0.06);
        glColor3d(0.0,0.0,0.0);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Gantelan Tali  ========================================>
        glTranslated(27.25,-1,-24.5);
		glScaled(0.1,0.4,0.1);
        glColor3d(0.0,0.0,1.0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
	
	glPushMatrix();  // Tirai Besi 1 Dari Kiri  ===============================>
        glTranslated(27.25,3,-6.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 2 Dari Kiri  ===============================>
        glTranslated(27.25,3,-7.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 3 Dari Kiri  ===============================>
        glTranslated(27.25,3,-8.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 4 Dari Kiri  ===============================>
        glTranslated(27.25,3,-9.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 5 Dari Kiri  ===============================>
        glTranslated(27.25,3,-10.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 6 Dari Kiri  ===============================>
        glTranslated(27.25,3,-11.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 7 Dari Kiri  ===============================>
        glTranslated(27.25,3,-12.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tirai Besi 8 Dari Kiri  ===============================>
        glTranslated(27.25,3,-13.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tirai Besi 9 Dari Kiri  ===============================>
        glTranslated(27.25,3,-14.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 10 Dari Kiri  ==============================>
        glTranslated(27.25,3,-15.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();
	
	glPushMatrix();  // Tirai Besi 11 Dari Kiri  ==============================>
        glTranslated(27.25,3,-16.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 12 Dari Kiri  ==============================>
        glTranslated(27.25,3,-17.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 13 Dari Kiri  ==============================>
        glTranslated(27.25,3,-18.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 14 Dari Kiri  ==============================>
        glTranslated(27.25,3,-19.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 15 Dari Kiri  ==============================>
        glTranslated(27.25,3,-20.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 16 Dari Kiri  ==============================>
        glTranslated(27.25,3,-21.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 17 Dari Kiri  ==============================>
        glTranslated(27.25,3,-22.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 18 Dari Kiri  ==============================>
        glTranslated(27.25,3,-23.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();
    
    
    //jendela 4 kiri
    glPushMatrix();  // Dudukan Besi Panjang  =================================>
        glTranslated(27.25,9,15.5);
		glScaled(0.2,0.2,18);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tali Pengaturan Tirai  ================================>
        glTranslated(27.25,4,24.5);
		glScaled(0.06,10,0.06);
        glColor3d(0.0,0.0,0.0);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Gantelan Tali  ========================================>
        glTranslated(27.25,-1,24.5);
		glScaled(0.1,0.4,0.1);
        glColor3d(0.0,0.0,1.0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
	
	glPushMatrix();  // Tirai Besi 1 Dari Kiri  ===============================>
        glTranslated(27.25,3,6.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 2 Dari Kiri  ===============================>
        glTranslated(27.25,3,7.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 3 Dari Kiri  ===============================>
        glTranslated(27.25,3,8.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 4 Dari Kiri  ===============================>
        glTranslated(27.25,3,9.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 5 Dari Kiri  ===============================>
        glTranslated(27.25,3,10.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 6 Dari Kiri  ===============================>
        glTranslated(27.25,3,11.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 7 Dari Kiri  ===============================>
        glTranslated(27.25,3,12.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tirai Besi 8 Dari Kiri  ===============================>
        glTranslated(27.25,3,13.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Tirai Besi 9 Dari Kiri  ===============================>
        glTranslated(27.25,3,14.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 10 Dari Kiri  ==============================>
        glTranslated(27.25,3,15.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();
	
	glPushMatrix();  // Tirai Besi 11 Dari Kiri  ==============================>
        glTranslated(27.25,3,16.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 12 Dari Kiri  ==============================>
        glTranslated(27.25,3,17.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 13 Dari Kiri  ==============================>
        glTranslated(27.25,3,18.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 14 Dari Kiri  ==============================>
        glTranslated(27.25,3,19.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 15 Dari Kiri  ==============================>
        glTranslated(27.25,3,20.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 16 Dari Kiri  ==============================>
        glTranslated(27.25,3,21.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 17 Dari Kiri  ==============================>
        glTranslated(27.25,3,22.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Tirai Besi 18 Dari Kiri  ==============================>
        glTranslated(27.25,3,23.5);
		glScaled(0.2,12,0.01);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    
    
    //Bagian atas masjid
  	//ATAP 1
	glPushMatrix();
        glTranslated(0,22,0);
		glScaled(30,0.3,30);
        glColor3d(1.0,1.0,1.0);
        glutSolidCube(1);
    glPopMatrix();
  	//ATAP 2
	glPushMatrix();
        glTranslated(0,10.2,21);
		glScaled(54.5,0.3,12.7);
        glColor3d(1.0,1.0,1.0);
        glutSolidCube(1);
    glPopMatrix();
  	//ATAP 3
	glPushMatrix();
        glTranslated(0,10.2,-21);
		glScaled(54.5,0.3,12.7);
        glColor3d(1.0,1.0,1.0);
        glutSolidCube(1);
    glPopMatrix();
  	//ATAP 4
	glPushMatrix();
        glTranslated(-21,10.2,0);
		glScaled(12,0.3,54.5);
        glColor3d(1.0,1.0,1.0);
        glutSolidCube(1);
    glPopMatrix();
  	//ATAP 5
	glPushMatrix();
        glTranslated(21,10.2,0);
		glScaled(12,0.3,54.5);
        glColor3d(1.0,1.0,1.0);
        glutSolidCube(1);
    glPopMatrix();

    // penyangga kubah 1
	glPushMatrix();
        glTranslated(0,16.1,-14.84);
		glScaled(29.9,12,0.3);
        glColor3d(0,1,0);
        glutSolidCube(1);
    glPopMatrix();    

    // penyangga kubah 2
	glPushMatrix();
        glTranslated(0,16.1,14.84);
		glScaled(29.9,12,0.3);
        glColor3d(0,1,0);
        glutSolidCube(1);
    glPopMatrix();    
    // penyangga kubah 3
	glPushMatrix(); 
        glTranslated(14.84,16.1,0);
		glScaled(0.3,12,30);
        glColor3d(0,1,0);
        glutSolidCube(1);
    glPopMatrix();    
    // penyangga kubah 4
	glPushMatrix(); 
        glTranslated(-14.84,16.1,0);
		glScaled(0.3,12,30);
        glColor3d(0,1,0);
        glutSolidCube(1);
    glPopMatrix();    

	glPushMatrix();  // Kubah ===========================================>
        glTranslated(0,25,0);
		glScaled(12,7,12);
        glColor3d(0.8,0.5,0.0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
    
    // pengeras suara1
	glPushMatrix();
        glTranslated(-26.0,12,-27.0);
		glRotated(0,0,0,0);
		glScaled(2,2,4);
        glColor3d(0.0,0.3,1.0);
        glutSolidCone(1,1,slices,stacks);
    glPopMatrix();
	glPushMatrix();  // Dudukan pengeras suara1  =================================>
        glTranslated(-26.0,12,-24);
		glScaled(0.2,3,0.2);
        glColor3d(0.0,0.0,0.0);
        glutSolidCube(1);
    glPopMatrix();

    
    

	


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

    glutSwapBuffers();
	glutPostRedisplay();									// Redisplay Screen
}


void keyboard( unsigned char key, int x, int y ) {			// Pada Keyboard
	switch ( key ) 
	{														// Inisialisasi Keyboard
		case 27:											// Jika ESC D tekan
			exit( 0 );										// Tutup Program
		break;
	}
glutPostRedisplay();										// Redisplay screen
}

void specialkeys (int key, int x, int y){
	switch (key) {



		case GLUT_KEY_F8:
         fullscreenexit = !fullscreenexit;
         if (fullscreenexit) {
            windowPosX   = glutGet(GLUT_WINDOW_X);
            windowPosY   = glutGet(GLUT_WINDOW_Y);
            windowWidth  = glutGet(GLUT_WINDOW_WIDTH);
            windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
            glutFullScreen();
         } else {
            glutReshapeWindow(windowWidth, windowHeight);
            glutPositionWindow(windowPosX, windowPosX);
         }
		break;

		case GLUT_KEY_LEFT:
			RotationSpeedX -= 0.1;
			if ( RotationSpeedX <= -2.0 )
				RotationSpeedX = -2.0;
		break;
		case GLUT_KEY_RIGHT:
			RotationSpeedX += 0.1;
			if ( RotationSpeedX >= 1.5 )
				RotationSpeedX = 1.5;
		break;
		case GLUT_KEY_UP:
			zCord += 0.2;
			if ( zCord >= -10.0 )
				zCord = -10.0;
		break;
 		case GLUT_KEY_DOWN:
			zCord -= 0.2;
			if ( zCord <= -60.0 )
				zCord = -60.0;
		break;
		case GLUT_KEY_PAGE_UP:
			yCord += 0.2;
			if ( yCord >= 15.0 )
				yCord = 15.0;
		break;
		case GLUT_KEY_PAGE_DOWN:
			yCord -= 0.2;
			if ( yCord <= -15.0 )
				yCord = -15.0;
		break;
		case GLUT_KEY_F1:
			KecRot += 0.3;
			if ( KecRot >= 0.0 )
				KecRot = 0.0;
		break;
		case GLUT_KEY_F2:
			KecRot -= 0.2;
			if ( KecRot <= -50.0 )
				KecRot = -50.0;
		break;
		case GLUT_KEY_F3:
			KecRot2 += 0.3;
			if ( KecRot2 >= 0.0 )
				KecRot2 = 0.0;
		break;
		case GLUT_KEY_F4:
			KecRot2 -= 0.2;
			if ( KecRot2 <= -50.0 )
				KecRot2 = -50.0;
		break;
		case GLUT_KEY_F5:
			xCord -= 0.2;
			if ( xCord <= -25.0 )
				 xCord = -25.0;
		break;
		case GLUT_KEY_F6:
			xCord += 0.2;
			if ( xCord >= 25.0 )
				 xCord = 25.0;
		break;
		case GLUT_KEY_F7:
			xCord = 0.0;
		break;
	default:
		break;
	}
    glutPostRedisplay();
}

// ProgramUtama 

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow ("MASJID 3D");
    glutFullScreen();

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialkeys); 

    glClearColor(0.5,0.5,0.5,0.5); 
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}

