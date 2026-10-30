# Robot Arduino avec évitement d’obstacles

Projet de première année : un robot à deux moteurs avance et change de direction lorsqu’un capteur ultrason détecte un obstacle à dix centimètres ou moins.

## Fonctionnement

Le programme déclenche une mesure sur le HC-SR04, mesure la durée de l’écho avec `pulseIn`, puis calcule une distance en centimètres. Si la distance est comprise entre 0 et 10 cm, les moteurs tournent dans des sens opposés. Sinon, les deux moteurs font avancer le robot. La commande PWM est fixée à 100 sur une échelle de 0 à 255.

## Matériel et branchements

- Carte compatible Arduino et shield moteur Roboduino.
- Deux moteurs à courant continu et leur alimentation adaptée.
- Capteur ultrason HC-SR04.

| Signal | Broche Arduino |
| --- | --- |
| PWM moteur 1 | 5 |
| Direction moteur 1 | 4 |
| PWM moteur 2 | 6 |
| Direction moteur 2 | 7 |
| Trig HC-SR04 | 9 |
| Echo HC-SR04 | 10 |

Les masses de la carte, du capteur et du contrôleur moteur doivent être communes. Le sens mécanique dépend du câblage des moteurs.

## Utilisation

1. Ouvrir `firmware/code_projet/code_projet.ino` dans Arduino IDE.
2. Sélectionner la carte et le port correspondant au montage.
3. Vérifier le câblage, téléverser le sketch et essayer le robot sur une surface dégagée.

Le sketch utilise uniquement les fonctions Arduino : aucune bibliothèque supplémentaire n’est requise.

## État du programme

Le code source du projet est conservé tel quel. Il utilise des mesures bloquantes et un seuil unique, sans filtrage ni hystérésis. Une absence d’écho donnant une distance nulle conduit à la branche « avancer ». Les commandes élémentaires de déplacement figurent également en commentaires à la fin du fichier. La compilation et le comportement sur le matériel n’ont pas été revérifiés lors de cette publication.

## Contexte

Travail réalisé dans le cadre du projet d’électronique de première année de Jordan TOE. Ce dépôt présente le programme retrouvé pour ce montage ; il ne contient pas de schéma électrique complet ni de résultat chiffré de validation.
