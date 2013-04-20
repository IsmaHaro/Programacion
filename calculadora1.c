#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main()

{
	int i, band;
	double logaritmo;
	float num,num2, exp, res;
	char car2[20],car1[20],opc[2];

	printf("\n\n\t\tEste programa emula una Calculadora \n\n");
	
	
	/* Menu */

do
    {

    do
	{
	
	printf("\t\t#############################################\n");
	printf("\t\t#\t                                    #\n");
	printf("\t\t#\t\tMenu                        #\n");
	printf("\t\t#\t1) Sumar dos números                #\n");
	printf("\t\t#\t2) Restar dos números               #\n");
	printf("\t\t#\t3) Dividir dos números              #\n");
	printf("\t\t#\t4) Elevar un número a un Exponente  #\n");
	printf("\t\t#\t5) Logaritmo                        #\n");
	printf("\t\t#\t6) Salir                            #\n");
	printf("\t\t#\t                                    #\n");
	printf("\t\t#############################################\n");
	printf("\n");
	printf("\t\tRespuesta: ");scanf("%s", opc);
	
    if(!(isdigit(opc[0])))
            {
            printf("\n\t\t| Teclea una opcion correcta Lelouch !! :D !\n \n");
            }
    }
    while(!(isdigit(opc[0])));
	
    /* Operaciones */

	switch(opc[0])
	{
		case '1': /* Suma */		
			    system("clear");
			    printf("\t\t| Suma \n\n");
                  	
                            do
			    {  
			    	printf("\n\t\t| Inserte el primer Sumando: ");
			    	scanf("%s",car1);
					printf("\n");
			    	
				/*Verificar si lo leido es un numero*/	
				for(i=0; i<strlen(car1); i++)
				{
					if(isdigit(car1[i]))
					{
						band=1;
					}
					else
					{
						band=2;
						break;
			    		}
				}
					
				if(band==1)
				{
					do
					{
			    			printf("\t\t| Inserte el segundo Sumando: ");
			    			scanf("%s",car2);
							printf("\n");
						/*Verificar si lo leido es un numero*/
							for(i=0; i<strlen(car2); i++)
							{
								if(isdigit(car2[i]))
								{
									band=1;
								}
								else
								{
									band=2;
									break;
								}
							}
							if(band==1)
							{
								num=atoi(car1);
								num2=atoi(car2);
			    					res=num+num2;
			    					printf("\t\t| El resultado de sumar %5.2f + %5.2f es: %5.2f \n\n",num,num2,res);
								band=1;
							}
							else
							{
								printf("\n\t\t>> Te Cache Lelouch :D ! Digita un numero \n \n");
							}
					}
					while(band==2);
                	    	}
			    	else
			     	{
					printf("\n\t\t>> Te Cache Lelouch :D ! Digita un numero \n \n");
			     	}
			   }
			   while(band==2);

			  band=1;
			  break;

		case '2': 
				system("clear");
			    printf("\t\t| Resta \n\n");
                  	
                do
			    {  
			    	printf("\n\t\t| Inserte el Minuendo: ");
			    	scanf("%s",car1);
					printf("\n");
			    	
				/*Verificar si lo leido es un numero*/	
				for(i=0; i<strlen(car1); i++)
				{
					if(isdigit(car1[i]))
					{
						band=1;
					}
					else
					{
						band=2;
						break;
			    		}
				}
					
				if(band==1)
				{
					do
					{
			    			printf("\t\t| Inserte el Sustraendo: ");
			    			scanf("%s",car2);
							printf("\n");
						/*Verificar si lo leido es un numero*/
							for(i=0; i<strlen(car2); i++)
							{
								if(isdigit(car2[i]))
								{
									band=1;
								}
								else
								{
									band=2;
									break;
								}
							}
							if(band==1)
							{
								num=atoi(car1);
								num2=atoi(car2);
			    					res=num-num2;
			    					printf("\t\t| El resultado de restar %5.2f - %5.2f es: %5.2f \n\n",num,num2,res);
								band=1;
							}
							else
							{
								printf("\n\t\t>> Te Cache Lelouch :D ! Digita un numero \n \n");
							}
					}
					while(band==2);
                	    	}
			    	else
			     	{
					printf("\n\t\t>> Te Cache Lelouch :D ! Digita un numero \n \n");
			     	}
			   }
			   while(band==2);

			  band=1;
			  break;

			  break;

		case '3': /* División */
                  system("clear");
			    printf("\t\t| Division \n\n");
                  	
                do
			    {  
			    	printf("\n\t\t| Inserte el Dividendo: ");
			    	scanf("%s",car1);
					printf("\n");
			    	
				/*Verificar si lo leido es un numero*/	
				for(i=0; i<strlen(car1); i++)
				{
					if(isdigit(car1[i]))
					{
						band=1;
					}
					else
					{
						band=2;
						break;
			    		}
				}
					
				if(band==1)
				{
					do
					{
			    			printf("\t\t| Inserte el Divisor: ");
			    			scanf("%s",car2);
							printf("\n");
						/*Verificar si lo leido es un numero*/
							for(i=0; i<strlen(car2); i++)
							{
								if(isdigit(car2[i]))
								{
									band=1;
								}
								else
								{
									band=2;
									break;
								}
							}
							if(band==1)
							{
								num=atoi(car1);
								num2=atoi(car2);
								if(num2!=0)
								{
									res=num/num2;
									band=1;
									printf("\t\t| El resultado de dividir %5.2f entre %5.2f es: %5.2f \n", num,num2,res);
								}
								else
									printf("\t\t| El Dividendo debe ser diferente de Cero \n");
							}
							else
							{
								printf("\n\t\t>> Te Cache Lelouch :D ! Digita un numero \n \n");
							}
					}
					while(band==2);
                	    	}
			    	else
			     	{
					printf("\n\t\t>> Te Cache Lelouch :D ! Digita un numero \n \n");
			     	}
			   }
			   while(band==2);
                
		      band=1;
		
			  break;

		case '4': /* Elevar un número a un Exponente */
	
			    system("clear");
			    printf("\t\t| Elevar un número a un Exponente \n\n");
                  	
                            do
			    {  
			    	printf("\n\t\t| Inserte el número a Elevar ");
			    	scanf("%s",car1);
					printf("\n");
			    	
				/*Verificar si lo leido es un numero*/	
				for(i=0; i<strlen(car1); i++)
				{
					if(isdigit(car1[i]))
					{
						band=1;
					}
					else
					{
						band=2;
						break;
			    		}
				}
					
				if(band==1)
				{
					do
					{
			    			printf("\t\t| Inserte el Exponente ");
			    			scanf("%s",car2);
							printf("\n");
						/*Verificar si lo leido es un numero*/
							for(i=0; i<strlen(car2); i++)
							{
								if(isdigit(car2[i]))
								{
									band=1;
								}
								else
								{
									band=2;
									break;
								}
							}
							if(band==1)
							{
								num=atoi(car1);
								num2=atoi(car2);
			    				if(num2>0)
								{
									exp=1;
									for(i=0;i<num2;i++)
									{
										exp=exp*num;
									}
									printf("\t\t| El resultado de elevar %5.2f al exponente %5.2f es: %5.2f \n", num, num2, exp);

								}
								if(num2==0)
								printf("\t\t| El resultado de elevar %5.2f al exponente %5.2f es: 1 \n", num, num2);

								if(num2<0)
								{
									exp=1;
									for(i=0;i<num2;i++)
									{
										exp=exp*num;
								}
								res=1/exp;
								printf("\t\t| El resultado de elevar %5.2f al exponente %5.2f es: %5.3f \n", num, num2, res);

								}
			
							}
							else
							{
								printf("\n\t\t>> Te Cache Lelouch :D ! Digita un numero \n \n");
							}
					}
					while(band==2);
                	    	}
			    	else
			     	{
					printf("\n\t\t>> Te Cache Lelouch :D ! Digita un numero \n \n");
					}
			   }
			   while(band==2);

			  band=1;
			  break;
			
		
		case '5': /* Calcular Logaritmo Natural */
	
			   system("clear");
			    printf("\t\t| Logaritmo Natural \n\n");
                  	
                            do
			    {  
			    	printf("\n\t\t| Ingrese un numero para calcular su Logaritmo Natural: ");
			    	scanf("%s",car1);
					printf("\n");
			    	
				/*Verificar si lo leido es un numero*/	
				for(i=0; i<strlen(car1); i++)
				{
					if(isdigit(car1[i]))
					{
						band=1;
					}
					else
					{
						band=2;
						break;
			    		}
				}
					
				if(band==1)
				{
					
								num=atoi(car1);
								if(num>0)
								{
									logaritmo=log(num);
									printf("\t\t| El logaritmo natural de %5.2f es: %5.2lf \n\n",num,logaritmo);
									band=1;
								}
								else
								{
									printf("\t\t| El numero tiene que ser mayor que cero \n\n");
									band=2;
								}

                }
			    	else
			     	{
					printf("\n\t\t>> Te Cache Lelouch :D ! Digita un numero \n \n");
			     	}
			   }
			   while(band==2);

			  band=1;
			  break;
			  
        case '6': /* Salir */
                  printf("\n\t\t|| Hasta Luego !!\n\n");
                  band=2;
                  break;
	default:
		printf("\n\t\t| Teclea una opcion correcta Lelouch!! :D!  \n\n");
		band=1;
		break;		
	  }
	
	}
	while(band==1);
	
	return 0;

}
