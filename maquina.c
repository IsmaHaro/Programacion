#include<stdio.h>
main()
{
    char opc;
    float pago1, costo, pago, cambio, band=0, faltante=0;
    printf("Programa que emula una maquina de Dulces \n");
    do
    {       
    printf("Menu \n");
    printf("P) paleta $3.50 \n");
    printf("D) dulce $1.80 \n");
    printf("R) refresco $7.00 \n");
    printf("S) Salir\n");
    printf("De su opción \n");
    scanf("%s",&opc);
    opc=toupper(opc);
        switch (opc)
        {
            case 'P': costo=3.50; band=2; break;
            case 'D': costo=1.80; band=2; break;
            case 'R': costo=7.00; band=2; break;           
            case 'S': printf("Saliendo, Hasta Luego! \n");
                      band=3; break;
            
            
            default: printf("Opcion no valida\n");
                     band=1; break;           
                
        }
     }while(band==1);
        if (band==2)
        {
           printf("Introdusca su pago\n");
           scanf("%f",&pago);
           if (pago==costo)
            printf("Tome su producto\n");
           else if (pago<costo)
               do { 
                         faltante=costo-pago;
                         if(pago<costo)
                         {    
                             printf("Falta por pagar: %3.2f \n",faltante);
                             printf("Introdusca su pago \n");
                             scanf("%f",&pago1);
                             pago=pago+pago1; 
                         }  
                         else if(pago==costo)
                             {
                                 printf("Tome su producto \n");
                                 band=1;
                             }    
                         else
                                {
                                    cambio=pago-costo;
                                    printf("Su cambio es: %3.2f \n",cambio);
                                    printf("Tome su Producto \n");
                                    
                                    band=1;
                                }
                                           

                  }while(band!=1);
           else
           { 
                cambio=pago-costo;
                printf("Su cambio es: %3.2f \n",cambio);
                printf("Tome su Producto \n");
                
                    
           } 
            
           
           
        } 
    
}
    
    
    
    
