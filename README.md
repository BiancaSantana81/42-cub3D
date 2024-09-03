# Cub3D

<p align="center">
  <img src="cub.gif" alt="cub3d" />
</p>


Inspirado no clássico “Wolfenstein 3D”, o Cub3D é um jogo 3D desenvolvido usando a técnica de raycasting. Em parceria com [@bda-mota](https://github.com/bda-mota/), este projeto foi criado como parte do Common Core na 42 São Paulo e foi desenvolvido em C, utilizando a biblioteca gráfica MLX.
## Funcionalidades
- **Renderização em 3D com Raycasting **: Implementação da técnica para simular uma perspectiva tridimensional em um ambiente 2D.
- **Mini mapa**: Exibe uma visão aérea do ambiente para ajudar na navegação (versão bônus).
- **Colisões com Paredes**: Implementação de colisões para impedir que o jogador atravesse paredes.
- **Rotação do Ponto de Vista com o Mouse**: Movimente o mouse para girar a visão do jogador, melhorando a jogabilidade (versão bônus).
- **Player animado**: Movimente a espada do personagem (versão bônus).
  
## Instalação
1. Clone o repositório:
    ```bash
    > git clone https://github.com/BiancaSantana81/42-cub3D.git
    ```
2. Compile e execute o projeto:
    ```bash
   > make  # para a versão obrigatória
   > make bonus  # para a versão com bônus
   > ./cub3D maps/valid/[nome_mapa]  # para a versão obrigatória
   > ./cub3D_bonus maps/valid/[nome_mapa] # para a versão com bônus
    ```
## Como Usar
Forneça instruções claras sobre como usar ou testar o projeto, incluindo exemplos de comandos e suas saídas esperadas.
## Como Jogar
- Use as teclas `W`, `A`, `S` e `D` para mover o personagem.
- Habilite o mini mapa usando a tecla `M`.
- Para rotacionar a visão do personagem, use as setas do teclado ou o mouse.
- Para mover a arma do personagem use a tecla espaço.
 
## Agradecimentos
Gostaria de agradecer especialmente às seguintes pessoas:
- [@bda-mota](https://github.com/bda-mota/) - Pela parceria e pelo interesse em tornar factível este projeto.
- [@ManualdoCodigo](https://github.com/ManualDoCodigo) - Por compartilhar seus conhecimentos por meio da playlist [_Engine de Raycasting_](https://www.youtube.com/playlist?list=PLLFRf_pkM7b6rBRoTOW64NKdltCLQNpW5). Sua didática nos ajudou a compreender o tema e construir um excelente projeto.
