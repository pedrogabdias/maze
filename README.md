<div align="center"  >
  <h1 align="center" >
    Labirinto 2D com OpenGL
    <br />
  </h1>
   <img src="https://skillicons.dev/icons?i=cpp" alt="">&nbsp;
   <img src="https://i.ytimg.com/vi/W3gAzLwfIP0/hq720.jpg?sqp=-oaymwEXCK4FEIIDSFryq4qpAwkIARUAAIhCGAE=&rs=AOn4CLD6WXnjAMyPiDxecgFfF0c6fNdkmw" height="45" alt="">&nbsp;
   <img src="https://skillicons.dev/icons?i=vscode" alt="">
</div>

## Introdução
Desenvolver uma aplicação em OpenGL que modele um labirinto em 2D representado por uma matriz de valores. O jogador deve ser capaz de se mover pelo labirinto, coletando tesouros e evitando paredes. <br><br>
<b>Descrição da Matriz:</b><br>
<ul>
  <li> 0: Espaço livre (caminho onde o jogador pode se mover).</li>
  <li> 1: Parede (obstáculo que o jogador não pode atravessar).</li>
  <li> *: Tesouro (local onde o jogador pode coletar um item).</li>
</ul>

## Objetivos do Projeto
<ol>
  <li>Implementar as funções para desenho do jogo (mapa, tesouros e jogador).</li>
  <li>Implementar a movimentação do jogador usando as teclas &#39;w&#39;, &#39;a&#39;, &#39;s&#39;, &#39;d&#39; ou as teclas direcionais, sempre controladas por variáveis de estado na função timer.</li>
  <li>Adicionar a lógica para coletar tesouros removendo-os do labirinto.</li>
  <li>Implementar um sistema de colisão simples para que o jogador não possa atravessar paredes.</li>
  <li>Adicionar uma contagem de tesouros coletados e de tempo de execução e exibi-los na tela.</li>
  <li>Criar uma tela de fim de jogo quando todos os tesouros forem coletados exibindo o tempo gasto pelo jogador.</li>
</ol>

## Instalação das Dependências
1. *Ubuntu*

    ```sh
    sudo apt-get install mesa-utils
    sudo apt-get install freeglut3-dev
    ```
2. *Windows*
    - Instalar o VSCode e as extensôes C/C++ e CMake Tools 
    - Instalar o msys2 para atualizar o compilador gcc para ultima versão
    - Atualizar o msys2:
    ```sh
    pacman -Suy
    ```
    - Reiniciar o terminal msys2
    - Dar o comando novamente:
    ```sh
    pacman -Suy
    ```
    - Instalar os pacotes de desenvolvimento e a freeglut
    ```sh
    pacman -S --needed base-devel mingw-w64-x86_64-toolchain
    pacman -S mingw-w64-x86_64-freeglut
    ```
    - Adicionar ao Path do windows:
     ```sh
    C:\msys64\mingw64\bin
    C:\msys64\mingw64\include
    C:\msys64\usr\bin
    ```
    - Reiniciar o sistema
      <br> <br>
    - Instalar o vcpkg
	  - Realizar um git clone (git clone https://github.com/Microsoft/vcpkg.git) ou baixar direto do github (https://github.com/Microsoft/vcpkg/) para alguma pasta do seu sistema. Exemplo -> c:\vcpkg\
	  - Executar o arquivo bat da pasta "vcpkg"
     ```sh
    .\vcpkg\bootstrap-vcpkg.bat
    ```
	  - Instalar o Freeglut
    ```sh
    vcpkg install freeglut
    ```
	  - Linkar a pasta de instalação de pacotes do VCPKG ao VSCode
     ```sh
    vcpkg integrate install
    ```
	  - Após isto, todos os pacotes instalados com o VCPKG serão automaticamente reconhecidos pelo Intellisense.
  
## Compilação e Execução
1. *Compilar o Projeto*
    ```sh
    make
    ```
2. *Executar o Projeto*
    ```sh
    make run
    ```
3. *Limpar Arquivos Compilados*
    ```sh
    make clean
    ```
     
