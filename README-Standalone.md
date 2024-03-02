# README - Programme Standalone

## Aperçu
Ce programme sert de simulateur pour le jeu Avalam. Il permet aux utilisateurs de jouer et de simuler des parties d'Avalam, en fournissant une interface en ligne de commande pour l'interaction.

## Comment Utiliser

1. **Compiler le Programme:**
   - Assurez-vous d'avoir un compilateur C installé sur votre système.
   - Compilez le programme à l'aide du code source fourni. Par exemple :
     ```bash
     make
     ```

2. **Exécuter le Programme:**
   - Exécutez le binaire compilé en fournissant les arguments nécessaires en ligne de commande :
     ```bash
     ./standalone.exe [NOM_FICHIER_JSON]
     ```
     - `[NOM_FICHIER_JSON]` : Argument facultatif. S'il est fourni, il spécifie le nom du fichier JSON à générer. Sinon, un fichier par défaut nommé "avalam-refresh.js" sera créé dans le répertoire "web/data".

3. **Initialisation du Jeu:**
   - Le programme initialisera l'état du jeu et générera un fichier JSON initial. Suivez les instructions à l'écran pour configurer les positions de bonus et de malus pour les joueurs jaune et rouge.

4. **Déroulement du Jeu:**
   - Entrez les coordonnées d'origine et de destination pour vos mouvements pendant votre tour.
   - Le jeu se poursuivra jusqu'à ce qu'il n'y ait plus de mouvements légaux.

5. **Génération du Fichier JSON:**
   - Après chaque mouvement, le programme mettra à jour le fichier JSON contenant l'état actuel du jeu. Le fichier se trouve dans le répertoire "web/data" (ou tel que spécifié par l'argument `[NOM_FICHIER_JSON]` facultatif).

6. **Fin du Jeu:**
   - Une fois le jeu terminé, le score final sera affiché, indiquant le vainqueur ou un match nul.

## Exemple d'Utilisation

```bash
./standalone.exe ma_partie
```

Cette commande lance une partie, permettant à l'utilisateur de spécifier un nom de fichier JSON personnalisé ("ma_partie.js"). Le programme guidera l'utilisateur à travers la configuration, le déroulement du jeu et générera le fichier JSON correspondant.

## Remarques
- Ce programme suppose une compilation correcte et un lien avec les bibliothèques nécessaires.
- Consultez les commentaires du code source pour plus de détails sur l'implémentation des fonctions.
- Pour une utilisation avancée et les règles détaillées d'Avalam, consultez la documentation officielle d'Avalam.

