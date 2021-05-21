void procesar(unsigned char *mata, unsigned char *matb, unsigned char *matc, int n) {
  int i, j; 
  
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      matc[i*n+j]=(mata[i*n+j] - matb[i*n+j]);
      if (matc[i*n+j]>0)
	matc[i*n+j]=255;
      else
	matc[i*n+j]=0;
    }
  }
}