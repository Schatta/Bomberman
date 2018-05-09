# Bomberman

Installation SDL

- sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev libsdl1.2debian libsdl2-dev libsdl-ttf2.0-dev

NB : Nous utiliserons la version 1.2 de SDl pour l'instant, n'ayant pas trouvé de "tuto"
suffisament conséquent pour démarrer rapidement.

le dossier comporte un Makefile ainsi qu'un fichier de test.
pour lancer le test , et vérifier que sdl fonctionne correctement faites :
- make

- ./bomberman

une fenêtre devrais apparaitre , pour la fermer appuyer sur une touche de votre clavier.

NB : il n'y a pas les flags -W -Wall et -Werror dans le makefile car il considère que la variable ecran n'est pas utilisé,
or elle est primordiale pour le bon fonctionnement du test.
