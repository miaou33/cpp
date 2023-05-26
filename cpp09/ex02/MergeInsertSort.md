
- Combinaison du *tri fusion* et du *tri par insertion*

    > **tri fusion** = tri récursif (complexite temporelle de O (n log n) ou n est la taille de la liste)
        - divise la liste à trier en deux moitiés
        - les trie séparément
        - les fusionne pour obtenir une liste triée

    > **tri par insertion** : (complexite temporelle de O (n^2) -> bonne option pour petites listes)
        - construit la liste triée élément par élément
        -> a chaque itération, un nv elem est inséré à sa position correcte dans la portion **déjà triée** de la liste

- Utilise le tri par insertion sur de petites sous-listes générées lors de la division.

=> Réduit le nombre d'opérations de comparaison et de déplacement lors du tri par insertion.
=> Les sous-listes triées sont fusionnées efficacement grâce au tri fusion.
=> Performances optimales pour les petites listes et les sous-listes déjà partiellement triées.

- Complexité temporelle généralement meilleure que le tri fusion et le tri par insertion individuellement dans certains cas.
- Complexité temporelle globale de O(n log n) dans la plupart des cas.
- Peut nécessiter plus de mémoire pour stocker les sous-listes temporaires.
- Moins efficace que d'autres algorithmes de tri optimisés pour des scénarios spécifiques.
- Le choix de la taille des sous-listes peut affecter les performances globales.

