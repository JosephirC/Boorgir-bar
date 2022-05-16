| EL-SAIDI Yara P2018561 | HANNA Sandrine P1906670 | ABIDA Youssef P2024398 |
| -----------------------|--------------------|------------------|

## La description du projet :
* Ce jeu peut etre joue en mode txt ou sdl en utilisant le makefile.
* C'est un jeu de restauration rapide dans lequel le joeur recoit des client et doit leur preparer les commandes.

* Le code txt est manipulable grace aux touches du clavier tout est explique durant le deroulement du jeu.
* Deroulement du jeu:
    - Au debut 3 choix de niveau sont présentés, dépendament du Niveau choisi il y aura un objectif d'argent a collecter avant la fin du temps.
    - Ensuite des clients arrive (touche C) il faut verifier les commandes du client puis le preperer la commande
    - Au debut il faut OBLIGATOIREMENT poser (touche G pour give) un PAINB ou PAINHD grace a son numero que vous pouver trouver dans la liste d'ingredients (I) puis la viande dans cet ordre
    - Ensuite vous pouvez ajouter (touche G) les garniture dans l'ordre que vous voulez.
    - Si le client veux des accompagnements (touche D) pour donner les frites soda ou jus

    - Si le temps est fini sans que l'objectif soit atteint sa affiche Perdu Sinon si l'objectif est atteint sa affiche Gagne
    - Puis vous pouvez recommencer ou sortir

* Le code SDL2 est manipulable grace a la souris pour jouer il suffit de cliquer sur l'objet a selectionne puis sur un autre pour que l'evenement ce produit. 
    - Les clients s'affiche avec leur commande au dessus de leur tete
    - Il suffit de preparer les commande en cliquant (CLIQUE GAUCHE) sur la nourriture puis sur le bar de preparation (4 blocs blancs)
    - Puis pour la donner au client (CLIQUE DROIT) sur le bar de preparation puis sur le clients de meme pour leur donner les accompagnements.


* Pour rendre le jeu plus personalisable nous offrons la possiblité a l'utilisateur d'ajouter des garnitures de son choix aux burgers et hotdog grace aux fichiers txt mais il faut suivre une demarche precise dans le dossier txt:
    - _Ingredients.txt_ il faut ecrire son nom puis un espace avec 0 0 0.
    - _test.txt_ il faut ecrire le nom des combinaisons obligatoiremenent elle doit commencer par un PainBSteak ou PainHD puis le chiffre 2 puis l'ancienne combnaison avec le nouvel ingredient ajouté puis le prix qui doit etre un entier positif.
    - _testSDL.txt_ il faut ecrire a la fin du fichier le nom de la combinaison puis un entier positif superieur a 100 puis le nom de l'image ./img/nomImage.png sous cette forme et finalement 0 0 0 0 0 car le code lui meme prendra en charge de placer l'image.
    - _Carte.txt_ finalement dans la carte affichez votre nouvelle combinaison et son prix.



    
* Une documentation doxyfile pour pouvoir lire en details les utilit�s des fonctions.

## Le contenu du projet :

Apr�s tant de recherche notre projet est enfin pr�t ! Le dossier src contient :
* Le code Jeu contient: 
    - Constructeur/Destructeur Jeu.
    - Tous les chargement des fichiers txt en rapport avec le core du code:Ingredients,Recette,Carte.
    - Accesseur et mutateur des parametres en prive.
    - Procedures qui cree les clients, efface les recettes et les accompagnement une fois servi,genere de nouveau. Client une fois qu'ils sont tous servi,calcule l'argent collecte durant le jeu.
* Le code Client contient:
    - Un Constructeur/Destructeur.
    - Accesseur et mutateur des parametres en prive.
    - Procedure qui charge une commende aleatoire dans le vecteur prive com et une autre qui calcule prix que doit payer le client dans l'int prixTot.
    - Finalement erase qui efface .
* Le code Commade contient:
    - Un Constructeur/Destructeur.
    - Accesseur et mutateur des parametres en prive.
* Le code Ingredient contient:
    - Un Constructeur/Destructeur.
    - Accesseur et mutateur des parametres en prive.
* Le code Objectif contient:
    - Un Constructeur/Destructeur.
    - Accesseur et mutateur des parametres en prive.
    - Procedure aui permet de choisir le niveau et initialiser le temps et l'argent qu'il faut ramasser.
    - Booleen finJeu qui verifie si le temps est ecoule.
* Le code Temps contient:
    - Un Constructeur/Destructeur.
    - Accesseur et mutateur des parametres en prive.
    - Fonction qui retourne le temps restant passe et atteint.
* Le code txt/txtJeu contient
   - Les procedures Boucle qui lance jeu et l'affiche
* Le code sdl2/sdlJeu contient
    - Un Constructeur/Destructeur.
    - Accesseur et mutateur des parametres en prive.
    - Les procedures Boucle qui lance jeu et l'affiche
    - Les procedures Load et Draw qui dessine et charge les images.
* Le code sdl2/sdlImage contient
    - Un Constructeur/Destructeur.
    - Accesseur et mutateur des parametres en prive.
    - Les procedures Load et Draw qui dessine et charge les images.

* Les 3 main :
    - mainSdl : compile le jeu avec SDL.
    - mainTxt : compile le jeu en Txt.
    - main : fait le test de regression.



## Comment compiler et executer le programme :

Pour compiler le programme il suffit d'utiliser le makefile � la racine avec la commande " make " qui genere dans bin les ex�cutables.
* ./bin/mainSdl : compile le jeu avec SDL.
* ./bin/mainTxt : compile le jeu en Txt.
* ./bin/main : fait le test de regression.


## Oranisation des archives :

| repertoire | contenu |
| -----------|----------|
| ./bin | les ex�cutables |
| ./data | les images |
| ./doc | la documentation |
| ./obj | les fichiers "*.o" |
| ./src | le code core (.cpp et .h) |
| ./src/txt | le code affichage console (.cpp et .h)|
| ./src/sdl2 | le code SDL2 (.cpp et .h)|
| . | Makefile et Readme |

