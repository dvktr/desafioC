#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <math.h>
#include <unistd.h>

int main()
{
  srand(time(NULL));
  int p, n;
  int aux;
  unsigned char armarios = 0;
  
  aux = pow(2, 7);


  while (n != 3)
  {
    printf("\nEscolha uma opção: \n1. Ocupar armário.\n2. Liberar armário.\n3. Sair\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
      if (armarios == 255)
      {
        printf("Sem armários livres!\n");
        break;
      }
      else
      {
        do
        {
          p = rand() % 8;
        } while ((armarios & (int)pow(2, p)) != 0);

        printf("Armário ocupado com sucesso: %d\n", armarios);
        armarios |= (int)pow(2, p);
        
      }
      break;

    case 2:
      printf("Digite a posição do armário que deseja desocupar: \n");
      scanf("%d", &p);
      if (armarios * (int)pow(2, p) == 0)
      {
        printf("Armário já está livre\n");
      }
      else
      {
        armarios &= ~(int)pow(2, p);
        printf("Armário livre\n");
      }
      break;
    case 3:
      break;
    }

    for (int i = 0; i <= 7; i++)
    {
      p = pow(2, i);
      printf((armarios & p) ? " X " : " %d ", i);
    }
    printf("\n");
  }
}
