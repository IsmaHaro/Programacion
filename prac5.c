#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

typedef struct{ 
    int matricula;
    int a_buap;
    int creditos;
    int act;
    char nombre[30];
    char ap_pat[30];
    char ap_mat[30];
}datos;

void iniciaract(datos activo[])
{
	int i;
	for(i=0; i<50; i++)
           {
               activo[i].act=0;
           }
}

void menuPrincipal(char *c)
{
	char opc[3], opc1;
	printf("\n");
    printf("--- Menu Principal --- \n\n");
    printf("a) Dar de Alta un Alumno \n");
    printf("b) Dar de Baja un Alumno \n");
    printf("c) Consultar \n");
    printf("s) Salir\n");
    scanf("%s",opc);
    printf("\n");
    opc1=tolower(opc[0]);
    *c=opc1;
}

void menuConsulta(char *s)
{
	char opc[3], opc2;
	 printf("\n");
     printf("### Menu de Consulta ###\n\n");
	 printf("M) Consultar por Matricula\n");
     printf("N) Consultar por Nombre\n");
     printf("T) Consultar Todos\n");
     printf("R) Regresar al Menu Principal\n");
     scanf("%s",opc);
     printf("\n");
     opc2=toupper(opc[0]);
     *s=opc2;
}

int BuscarSiExisteMat(datos lista[],int matric)
{
		int i, band=0;
	    for(i=0; i<50; i++)
                {  
                        if(lista[i].matricula==matric && lista[i].act==1)
                        {
                            
                            band=3;
                            break;
                  
                        }
                } 
        return (band);  
}

int PosVaciaAlumnosAct(datos lista[])
{
	int band=0, pos, i=0;
    do
     {
       if(lista[i].act==0)
         {
            pos=i;
			band=2;
                           
		}
	i++;
     }
	while(band!=2);	
	return (pos);
}

void leerDatos(datos lista[],int pos,int matric)
{
	  lista[pos].matricula=matric;
      lista[pos].act=1;
      printf("Ingrese el Nombre\n");
      scanf(" %[^\n]s",lista[pos].nombre);
      printf("Ingrese el Apellido Paterno\n");
      scanf(" %[^\n]s",lista[pos].ap_pat);
      printf("Ingrese el Apellido Materno\n");
      scanf(" %[^\n]s",lista[pos].ap_mat);
      printf("Ingrese los Años en la BUAP \n");
      scanf("%d",&lista[pos].a_buap);
      printf("Ingrese los Creditos Aprobados\n");
      scanf("%d",&lista[pos].creditos);
      system("clear");
      printf("\n \n ¡El Alumno ha sido Agregado! \n \n");
}

void eliminarAlumno(datos lista[], int matric)
{
	 int i, band=0;
	 for(i=0; i<50; i++)
              {
                  if(lista[i].matricula==matric && lista[i].act==1)
                  {
                      lista[i].act=0;
                      system("clear");
                      printf("\n \n ¡Se ha Dado de Baja el Alumno!\n \n");
                      band=3;
                      break;
                  }
              }
      if(band!=3)
              {
               printf("El Alumno no existe\n");
              }
              
       return;
}

void MostrarDatos(datos *p, int i)
{
      printf("\nEl nombre es: %s \n", (p+i)->nombre);
      printf("Apellido Paterno: %s \n",(p+i)->ap_pat);
      printf("Apellido Materno: %s \n", (p+i)->ap_mat);
      printf("Matricula: %d \n", (p+i)->matricula);
      printf("Años en la BUAP: %d \n", (p+i)->a_buap);
      if(((p+i)->creditos/(p+i)->a_buap)>=93)
      {
        printf("Es un Buen Alumno tiene %d creditos \n \n", (p+i)->creditos);
      }
      else
      {
        printf("El Alumno es un Flojo tiene %d creditos \n \n", (p+i)->creditos);
      }
                                    
                               
}


int main()
{
	FILE *ap;
    int i, mat, band, pos;
    char opc, nom[30];
    datos alumno[50];
    char archivo[60];
    char nombre[60];

    printf("\n\"Este Programa es un pequeño Sistema \n que maneja Registros de Alumnos de la BUAP \n por medio de Funciones, Apuntadores y Archivos\" \n\n");
    
	printf("\n¿Qué archivo desea abrir (Sin extensión) ? \n");
	scanf("%[^\n]s",nombre);
    
	sprintf(archivo,"%s.txt",nombre);
	ap=fopen(archivo,"rb");
	
	if(ap == NULL)
	{
		printf("Hubo error al abrir el archivo \n");
		iniciaract(alumno);	
	
	}
	
	else
	{
		fread(alumno,sizeof(alumno),1,ap);
			
		for(i=0;i<50;i++)
		{
			if(alumno[i].act==1)
				{
					MostrarDatos(alumno,i);
				}
		}
		fclose(ap);
		
	}
	
	
	

    do
    {
	
	/* Menu Principal*/
	
	menuPrincipal(&opc);
	
    /* Opciones de Acuerdo a lo escogido en el Menu Principal */
    
    switch(opc)
    {
        case 'a':
				system("clear");
                printf("Introduzca la matricula\n");
                scanf("%d",&mat);

                /* Buscar si la matricula dada, ya existe */
				band=BuscarSiExisteMat(alumno, mat);

                if(band!=3)
                {
                 /* Buscar una Posicion Vacia en Alumnos */
                   
				pos=PosVaciaAlumnosAct(alumno);
				
                /* Meter Datos en los Campos Correspondientes */
              
                leerDatos(alumno, pos, mat);
                }
                else
                printf("Esa matricula ya existe \n");

                band=5;

                break;


    case 'b':
			  system("clear");
              printf("Introduzca la matricula del Alumno a Eliminar\n");
              scanf("%d",&mat);
              /* Eliminar Alumno */
             
			  eliminarAlumno(alumno, mat);
              
              band=5;
              break;

    case 'c': system("clear");
              do
              {    
			  menuConsulta(&opc);

              switch(opc)
              {
                  case 'M': band=0;
                            system("clear");
                            printf("\nIngrese la Matricula\n");
                            scanf("%d",&mat);

							band=BuscarSiExisteMat(alumno,mat);

                            if(band==3)
                            {
								for(i=0; i<50; i++)
								{
									if(mat==alumno[i].matricula && alumno[i].act==1)
									{    
										MostrarDatos(alumno, i);
										break;
									}
								}
                            }
                            else
                            {
                                printf("El Alumno no Existe \n");
                            }
                            band=4;
                            break;    

                    case 'N': band=0;
                              system("clear");
                              printf("Ingrese el nombre del Alumno \n");
                              scanf("%s",nom);

                              for(i=0; i<50; i++)
                              {
                                   
                                if(!strcmp(nom,alumno[i].nombre) && alumno[i].act==1)
                                    {
                                        band=3;
                                        break;
                                    }
                             }
                             if(band==3)
                             {
                                 for(i=0; i<50; i++)
                                 {
                                     if(!strcmp(nom,alumno[i].nombre) && alumno[i].act==1)
                                     {
                                         MostrarDatos(alumno,i);
                                     }
                                 }
                             }
                             else
                             {
                                 printf("El Alumno No Existe \n");
                             }
                             band=4;
                             break;

                    case 'T': system("clear"); 
                             for(i=0; i<50; i++)
                                {
                                    if(alumno[i].act==1)
                                    {
                                        MostrarDatos(alumno,i);  
                                    }
                                }
                              band=4;
                            break;

                    case 'R': band=5;
						      system("clear");
                              break;  

                    default:  printf("\nEsa Opcion es incorrecta introduzca otra\n\n");
                              band=4;
                              break;

                  }
                  }while(band==4);
                  break;
 
        case 's': band=6;
				  system("clear");
                  break;

        default: printf("\n Opcion Incorrecta Introduzca Otra \n");
                 band=5;
            
        
     }
     
    }
    while(band==5);

    if(band==6)
    {
		ap=fopen(archivo,"wb");
        fwrite(&alumno,sizeof(alumno),1,ap);
        fclose(ap);
		
        printf("\n\n ¡Hasta Luego! \n\n");
        printf(" Espere unos segundos... \n");
        sleep(2);
        system("clear");
        
    }
return 0;
}



                

