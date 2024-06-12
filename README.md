# Cub3d - (Cybercube)

## Sommaire
- [À propos](#à-propos)
- [Fonctionnalités](#fonctionnalités)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Dépendances](#dépendances)
- [Auteurs](#auteurs)

## À propos

Cub3d est un projet de jeu en 3D développé dans le cadre de mon cursus 42. Il s'inspire du jeu Wolfenstein 3D (ou Doom) et met en œuvre des techniques de raycasting pour créer un environnement de jeu immersif.
Je vous conseils de jouer au bonus, vu que c'est le manda mais en mieux ! Il faut noter aussi que nous avons fait le projet en 3 semaines environs. Nous avons un rendu sympa mais il reste toujours des choses que nous avons prevu mais abandonné du au manque de temps (On voulait passer a un autre projet.) Notamment la randomisation des murs, l'affichage correct des portes, ennemis ou impact de balle.

![Screencast from 06-12-2024 03_55_23 PM](https://github.com/Misthaa/cub3D/assets/113677180/705f018a-a424-44aa-bbf9-4d8c19409ed0)

## Fonctionnalités

- Chargement de cartes depuis des fichiers texte (Manda)
- Moteur de rendu 3D utilisant le raycasting (Manda)
- Déplacement du joueur (avant, arrière, gauche, droite) (Manda)
- Rotation de la caméra (Manda)
- Gestion des collisions avec les murs (Bonus)
- Mini-carte affichant la position du joueur (Bonus)
- Jouabilité avec la souris (PDV et Shoot) (Bonus)
- Porte (Bonus)
- Menu + Settings (Bonus)

![Screenshot from 2024-06-12 15-22-28](https://github.com/Misthaa/cub3D/assets/113677180/bdf42194-2c5a-46b5-a1c4-7a04186fda88)

## Installation

Pour installer et exécuter Cub3d, suivez ces étapes :

1. Clonez le dépôt Git :
    ```bash
    git clone https://github.com/Misthaa/cub3D.git cub3d
    cd cub3d
    ```

2. Compilez le projet (Manda) :
    ```bash
    make
    ```
(Bonus) :
    ```bash
    make
    make bonus
    ```

3. Lancez le jeu :
    ```bash
    ./cub3d assets/maps/map_manda/bonus.cub
    ```

## Utilisation

Utilisez les touches suivantes pour jouer au jeu :

- **W** : Avancer
- **S** : Reculer
- **A** : Aller à gauche
- **D** : Aller à droite
- **Shift** : Courrir
- **Flèche gauche** : Tourner la caméra à gauche
- **Flèche droite** : Tourner la caméra à droite
- **Échap** : Quitter le jeu / Menu
- **Souris** : Tourner la caméra à gauche/droite
- **Click gauche** : Tirer

## Dépendances

Cub3d nécessite les dépendances suivantes :

- **OS** : Ne fonctionne pas correctement sur MacOS.
- **Vulkan** : Cette mlx (MacroLibx), est dependante de Vulkan pour fonctionner.
- **gcc** : Le compilateur C.

Assurez-vous que ces dépendances sont installées avant de compiler le projet.

## Auteurs

- **Mathis** (madegryc), 42 Angouleme. [https://github.com/Misthaa]
- **Emile** (ehalliez), 42 Angouleme [https://github.com/Ehlzz]
