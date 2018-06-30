# Bomberman

Installation SDL

> sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev libsdl1.2debian libsdl2-dev libsdl-ttf2.0-dev

> sudo apt-get install libsdl2-image-2.0-0
> sudo apt-get install libsdl2-image-dev

NB : Nous utiliserons la version 1.2 de SDl pour l'instant, n'ayant pas trouvé de "tuto"
suffisament conséquent pour démarrer rapidement.

le dossier comporte un Makefile ainsi qu'un fichier de test.
pour lancer le test , et vérifier que sdl fonctionne correctement faites :
> make

> ./bomberman

une fenêtre devrais apparaitre , en touchant les flèches de votre clavier la bonne direction devrait être signalée

NB : il n'y a pas les flags -W -Wall et -Werror dans le makefile car il considère que la variable ecran n'est pas utilisé,
or elle est primordiale pour le bon fonctionnement du test.

EDIT:
Si pendant le make vous avez des problèmes au niveau du sdl_image (principalement, mais je pense que sdl tout court ça marche aussi)
>sudo apt-get install libsdl1.2-dev

S'il y a une erreur avec la ligne du dessus c'est sans doute avec cette ligne que ça va marcher :
>sudo apt-get install libexempi3:i386

refaites la première commande
>sudo apt-get update

>sudo apt-get install libsdl-image1.2-dev

>sudo apt-get upgrade

Voilà.
