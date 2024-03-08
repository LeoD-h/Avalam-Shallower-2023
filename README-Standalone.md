# README - Programme Standalone

## Aperçu
Ce programme sert de simulateur pour le jeu Avalam. Il permet aux utilisateurs de jouer et de simuler des parties d'Avalam, en fournissant une interface en ligne de commande pour l'interaction.

## Comment Utiliser

1. **Compilation du Programme:**
   - Assurez-vous d'avoir un compilateur C installé sur votre système.
   - Compilez le programme à l'aide du code source fourni. Par exemple :
     ```bash
     make
     ```

2. **Configuration après Compilation:**
   - Naviguez vers le répertoire de compilation :
     ```bash
     cd build
     ```

   - Sourcez le fichier de configuration dynamique :
     ```bash
     source dyn.sh
     ```

3. **Exécution du Programme:**
   - Exécutez le binaire compilé en fournissant les arguments nécessaires en ligne de commande :
     ```bash
     ./standalone.exe [NOM_FICHIER_JSON]
     ```
     - `[NOM_FICHIER_JSON]` : Argument facultatif. S'il est fourni, il spécifie le nom du fichier JSON à générer. Sinon, un fichier par défaut nommé "avalam-refresh.js" sera créé dans le répertoire "web/data".

4. **Initialisation du Jeu:**
   - Le programme initialisera l'état du jeu et générera un fichier JSON initial. Suivez les instructions à l'écran pour configurer les positions de bonus et de malus pour les joueurs jaune et rouge.

5. **Déroulement du Jeu:**
   - Entrez les coordonnées d'origine et de destination pour vos mouvements pendant votre tour.
   - Le jeu se poursuivra jusqu'à ce qu'il n'y ait plus de mouvements légaux.

6. **Génération du Fichier JSON:**
   - Après chaque mouvement, le programme mettra à jour le fichier JSON contenant l'état actuel du jeu. Le fichier se trouve dans le répertoire "web/data" (ou tel que spécifié par l'argument `[NOM_FICHIER_JSON]` facultatif).

7. **Fin du Jeu:**
   - Une fois le jeu terminé, le score final sera affiché, indiquant le vainqueur ou un match nul.

## Exemple d'Utilisation

```bash
./standalone.exe ma_partie
