//Dafni Skiadopoulou AM: 3075, Vasileios Kakionis AM: 2981, Nafsika Tzatzaki AM: 3087
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define sizeS1 3000
#define sizeS2 100

float s1a[sizeS1][3];
float s1b[sizeS1][3];
float C1[sizeS1][2];
int indexC1 = 0;
float C2[sizeS1][2];
int indexC2 = 0;
float C3[sizeS1][2];
int indexC3 = 0;

float s2a[sizeS2][2];
float s2b[sizeS2][2];
float s2c[sizeS2][2];
float s2d[sizeS2][2];
float s2e[sizeS2][2];


float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

float categ(float x1, float x2){
	
	if( pow((x1-1),2) + pow((x2-1),2) <= 0.16){
		C1[indexC1][0] = x1;
		C1[indexC1][1] = x2;
		indexC1++;
		return 1.0;
	}
	else if( pow((x1+1),2) + pow((x2+1),2) <= 0.16){
		C1[indexC1][0] = x1;
		C1[indexC1][1] = x2;
		indexC1++;
		return 1.0;
	}
	else if( (pow((x1-1),2) + pow((x2-1),2) > 0.16) && (pow((x1-1),2) + pow((x2-1),2) < 0.64) ){
		C2[indexC2][0] = x1;
		C2[indexC2][1] = x2;
		indexC2++;
		return 2.0;
	}
	else if( (pow((x1+1),2) + pow((x2+1),2) > 0.16) && (pow((x1+1),2) + pow((x2+1),2) < 0.64) ){
		C2[indexC2][0] = x1;
		C2[indexC2][1] = x2;
		indexC2++;
		return 2.0;
	}
	else{
		C3[indexC3][0] = x1;
		C3[indexC3][1] = x2;
		indexC3++;
		return 3.0;
	}

}

int main () {
   FILE * fp1;
   FILE * fp2;
   fp1 = fopen ("dataSet1.txt", "w+");
   fp2 = fopen ("dataSet2.txt", "w+");
   int i,j;
   for (i=0;i<sizeS1;i++){
	float x1A = RandomFloat(0.0,2.0);
	float x2A = RandomFloat(0.0,2.0);
	float x1B = RandomFloat(-2.0,0.0);
	float x2B = RandomFloat(-2.0,0.0);

	s1a[i][0] = x1A;
	s1a[i][1] = x2A;
	s1b[i][0] = x1B;
	s1b[i][1] = x2B;

	float ca = categ(x1A,x2A);
	float cb = categ(x1B,x2B);

	s1a[i][2] = ca;
	s1b[i][2] = cb;

   }

   for (i=0;i<sizeS2;i++){
	float x1A = RandomFloat(-0.3,0.3);
	float x2A = RandomFloat(-0.3,0.3);
	float x1B = RandomFloat(-1.1,-0.5);
	float x2B = RandomFloat(0.5,1.1);
	float x1C = RandomFloat(-1.1,-0.5);
	float x2C = RandomFloat(-1.1,-0.5);
	float x1D = RandomFloat(0.5,1.1);
	float x2D = RandomFloat(-1.1,-0.5);
	float x1E = RandomFloat(0.5,1.1);
	float x2E = RandomFloat(0.5,1.1);

	s2a[i][0] = x1A;
	s2a[i][1] = x2A;
	s2b[i][0] = x1B;
	s2b[i][1] = x2B;
	s2c[i][0] = x1C;
	s2c[i][1] = x2C;
	s2d[i][0] = x1D;
	s2d[i][1] = x2D;
	s2e[i][0] = x1E;
	s2e[i][1] = x2E;

   }


   for(i=0;i<sizeS1;i++){

	fprintf(fp1,"%f %f %f ",s1a[i][0],s1a[i][1],s1a[i][2]);
	fprintf(fp1,"%f %f %f ",s1b[i][0],s1b[i][1],s1b[i][2]);
   }
   fprintf(fp1,"\n");

   for(i=0;i<sizeS2;i++){
	fprintf(fp2,"%f %f ",s2a[i][0],s2a[i][1]);
   }
   fprintf(fp2,"\n");

   for(i=0;i<sizeS2;i++){
	fprintf(fp2,"%f %f ",s2b[i][0],s2b[i][1]);
   }
   fprintf(fp2,"\n");

   for(i=0;i<sizeS2;i++){
	fprintf(fp2,"%f %f ",s2c[i][0],s2c[i][1]);
   }
   fprintf(fp2,"\n");

   for(i=0;i<sizeS2;i++){
	fprintf(fp2,"%f %f ",s2d[i][0],s2d[i][1]);
   }
   fprintf(fp2,"\n");

   for(i=0;i<sizeS2;i++){
	fprintf(fp2,"%f %f ",s2e[i][0],s2e[i][1]);
   }
   fprintf(fp2,"\n");


   fclose(fp1);
   fclose(fp2);
   return(0);

}

//      fscanf(myfile,"%lf",&myvariable); for reading










