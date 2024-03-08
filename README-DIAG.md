
# Programme diag

Le programme diag est un utilitaire en ligne de commande permettant de générer des fichiers JavaScript contenant des données au format JSON pour une utilisation ultérieure dans un outil de diagnostic web.

## Compilation

Avant d'exécuter le programme, assurez-vous de le compiler en utilisant la commande make. Naviguez d'abord vers le répertoire contenant le code source, puis exécutez :

```bash
make
```

## Utilisation

1. **Exécution du programme :**

   Après la compilation, utilisez la commande suivante dans le terminal :

   ```bash
   cd build
   source dyn.sh
   ./diag.exe [numDiag] [fen]
   ```

   Par exemple :

   ```bash
   ./diag.exe 2 "tdtUDU40 r"
   ```

   Si vous ne fournissez pas d'arguments, le programme peut être exécuté sans eux.

2. **Saisie de l'adresse du fichier de destination :**

   Le programme vous demandera de fournir le chemin vers le répertoire où vous souhaitez enregistrer le fichier généré. Vous pouvez saisir l'adresse, par exemple, "../web/data/" suivi du nom du fichier que vous souhaitez créer (avec l'extension ".js").

   ```bash
   Renseignez le nom du fichier à créer : monFichier
   ```

3. **Confirmation ou modification du chemin du fichier de destination :**

   Le programme affichera le chemin par défaut pour le fichier généré, et vous demandera si vous souhaitez le modifier. Vous pouvez répondre "N" pour non, ou "O" pour oui.

   ```bash
   Nom du fichier : ../web/data/monFichier.js
   Le fichier de destination par défaut est : ../web/data/monFichier.js
   Voulez-vous le modifier ? (N,o): N
   ```

4. **Ajout d'un commentaire :**

   Ensuite, le programme vous demandera de saisir un commentaire, qui sera inclus dans le fichier généré.

   ```bash
   Renseignez une description (max. 1000 caractères) :
   ```

   Vous pouvez saisir votre commentaire et appuyer sur la touche "Entrée".

5. **Enregistrement du fichier et confirmation :**

   Une fois le commentaire ajouté, vous pouvez appuyer sur la combinaison de touches "Espace" puis "CTRL + D" pour enregistrer le fichier et terminer le processus.

   ```bash
   Réussite !
   ```

## Exemple d'utilisation

1. Exécutez le programme avec les paramètres nécessaires.

   ```bash
   ./diag.exe 2 "tdtUDU40 r"
   ```

2. Saisissez l'adresse du fichier de destination.

   ```bash
   Renseignez le nom du fichier à créer : monFichier
   ```

3. Confirmez le chemin du fichier de destination.

   ```bash
   Nom du fichier : ../web/data/monFichier.js
   Le fichier de destination par défaut est : ../web/data/monFichier.js
   Voulez-vous le modifier ? (N,o): N
   ```

4. Ajoutez un commentaire.

   ```bash
   Renseignez une description (max. 1000 caractères) :
   ```

   Saisissez votre commentaire et appuyez sur "Entrée".

5. Terminez en appuyant sur "Espace" et "CTRL + D".

   ```bash
   Réussite !
   ```
  
Assurez-vous d'adapter ces instructions en fonction de la structure réelle de votre programme et de vos besoins spécifiques.
