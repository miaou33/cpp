# DEF

- découvert par Ford et Johnson, probablement nommé par D. Knuth
- algo qui cherche a **minimiser le nombre de comparaisons effectuées** pour trier une liste.

- utilise la ### recherche dichotomique (binary search en anglais, parfois appelé recherche par dictionnaire) 
    : je compare mon élément à celui du milieu de la liste, pour diviser la taille de mon champ de recherche par deux, et je recommence)
    Cette technique permet d'insérer un élément dans une liste de taille n en log2(taille liste) comparaisons

--- 

# L'ALGO

**En entrée**: une liste non vide d'éléments.
**En sortie**: une liste triée de ces éléments.

### Etape 1: Merge
= fusionner = faire des paires
- Si il y n'y a qu'un élément dans la liste: la retourner 
- Sinon: 
    - appairer les éléments
    - trier les deux éléments de chaque paire
    - faire une liste de ces paires

**Exemple** : `1, 8, 6, 3, 75, 20, 5`
Recursion 0 -> `(1,8), (3,6), (20,75), (5)` 
Recursion 1 -> `((3,6),(1,8)), ((5),(20,75))`

### Etape 2: Récursion
- Appeler cet algorithme sur cette liste de paire.

### Etape 3:  Insert
- Extraire de la liste de paire (qui a donc été triée lors de l'appel récursif à l'étape 2) une liste triée des plus grands éléments de chaque paire. 
- Insérer le plus petit élément de chaque paire dans la liste triée en suivant une progression de Jacobsthal.
- Retourner la liste triée.

N.B. attention au terme "élément": lors de l'appel récursif, on appelle notre fonction sur une liste de paires d'éléments. 
Pour l'instance de la fonction qui recevra cette liste de paires, cette liste est une liste d'éléments.


--- 

# EXPLICATIONS

### Étape 1: 

Je fais des paires d'éléments (e.g. en doublant la longueur de mes itérateurs), et je trie les deux éléments entre eux.
A la fin de l’étape 1, j'ai une liste de paires d'éléments 
    -> *dans l'explication de l’étape 3, cette paire sera notée P(a, b) avec a le petit élément, et b le grand*
Si on me donne le plus grand élément d'une paire, il faut que je puisse retourner le plus petit immédiatement 
    -> *c'est à dire sans faire de comparaisons, de parcours de liste (et donc de comparaisons...)... l’idée, c'est de faire le moins de comparaisons possible*


### Etape 2:

Je suis en train de coder un algo de tri. Quand j'aurais fini et que je l'aurais compilé, j'aurais une fonction qui, quand on lui passe une liste d'éléments, la trie. 
Il se trouve que dans cet algorithme, j'ai besoin de trier une liste deux fois plus petite que celle reçue en entrée: j'utilise cette fonction.

**Pourquoi ça marche**:  
- une liste de taille 1 est triée
- a force de diviser la taille de notre liste par deux (au fil des appels récursifs successifs), on va bien arriver à une liste de taille 1
- la, la fonction pourra me renvoyer une liste triée. 
- de cette liste triée, je vais donc pouvoir produire une liste triée de taille deux et la renvoyer. 
- l'appel récursif du dessus va recevoir une liste de taille deux triée et pouvoir produire une liste triée de taille 4...
- j'ai maintenant une liste de paires d'éléments triée suivant le plus grand élément de chaque paire.

*Une première observation ici*: le petit élément de la paire la plus petite (donc dont le plus grand élément est plus petit que tous les autres plus grands éléments)
est plus petit que tous les éléments de cette liste (la liste des plus grands éléments de chaque paire... )
-> je vais donc pouvoir l'insérer à l'étape trois sans avoir à effectuer aucune comparaison... 
(Et c'est là qu'il faut pouvoir accéder à cet élément depuis l'élément avec lequel il a été appairé sans avoir à faire de comparaisons).

*Une deuxième observation*: après une insertion, la liste sera toujours triée.

*Une digression*:vu que je vais devoir insérer des éléments dans une liste triée, je vais pouvoir faire des recherches par dichotomie. C'est donc mieux si j'ai 2^n-1 éléments dans ma liste (pour un certain n... encore une histoire de log).
Plus concrètement: on va commencer par regarder combien de comparaisons je dois faire pour insérer un élément dans des listes de différentes tailles; et on va essayer de remarquer que le nombre de comparaisons nécessaires augmente de un quand on passe d'une liste de taille 2^n-1 à une liste de taille 2^n. Si je veux insérer un élément dans une liste de:
0 (= 2^0-1) éléments: j'ai juste à l'insérer: 0 comparaisons
1 (= 2^1-1 = 2^0) élément: j'ai une comparaison à faire et à insérer: 1 comparaison
2 éléments: une (si j'ai de la chance: je devais insérer 1 dans la liste (3,5), j'ai choisi de commencer par comparer avec 3, et j'ai pu l'insérer direct) ou deux comparaisons (si j'ai eu moins de chance: je devais insérer 4); on se base sur le pire cas: 2 comparaisons
3 (= 2^2-1) éléments: une comparaison avec celui de milieu qui va me dire de quel côté me diriger, une liste de un de chaque cote(et j'ai déjà noté que pour une liste de un, il me fallait une comparaison): 1 + 1 = 2 comparaisons, comme pour une liste de 2 éléments.
4 éléments: un peu comme pour les listes de deux éléments, ça va dépendre de si j'ai de la chance ou pas; deux ou trois comparaison: 3 comparaisons
5 éléments: une comparaison avec celui du milieu, une liste de deux de chaque côté: 3 comparaisons aussi
6 éléments: je te la fais courte: encore 3 comparaisons
7 (= 2^2-1) éléments: une comparaison avec celui du milieu, une liste de trois de chaque côté: toujours 3 comparaisons
et à 8 éléments, on passe à 4 comparaisons; à 16 à 5... Et donc avec une recherche par dichotomie, rechercher dans une liste de 8 ou de 15 éléments, ça prend le même temps.

Étape 3: En reprenant la notation des paire P(a, b), j'insère donc le petit élément "a1" de la paire la plus petite P1(a1, b1) (P1 parce que c'est la plus petite, ensuite, P2, P3...) sans faire de comparaisons. Conceptuellement, j'ai maintenant une liste a1, b1, P2, P3... (Conceptuellement parce que je suis en train de faire une liste ou je mélange des éléments (a1, b1), et des paires d'éléments (P2...): mon compilateur me ferait la gueule)
J'ai commencé par P1.
Je pourrais insérer le petit élément a2 de P2(a2, b2), mais je l'insérerai  dans une liste de taille 2: 2 comparaisons, et ensuite, je devrais insérer le petit élément a3 de P3 dans une liste de 4 éléments (a1, b1, a2 et b2): donc 3 comparaisons (le nombre de comparaisons pour les listes de taille n est juste au dessus), pour un total de 5 comparaisons.
 Alors que si j'insère le petit élément a3 de P3(a3, b3) dans la liste [a1, b1, P2] (techniquement, on l'insérera dans [a1, b1, b2]), puis que j'insère a2 (soit dans la liste [a1, b1], soit dans une liste composée de a1, b1 et a3), donc deux insertions dans des listes de taille 3, ça fait chuter le total à 4 comparaisons.
Donc les suivants, c'est P3 puis P2.
Maintenant, j'ai dans ma liste a1, b1, a2, b2, a3 et b3 triés: 6 éléments. Exactement comme la fois précédente, si j'essaye d'insérer a4 dans une liste de 6, j'insérerai a5 dans une liste de 8: donc 3 + 4 = 7 comparaisons, alors que si j’insère a5 puis a4, les deux seront dans des listes d'au plus 7, pour un total de 6 comparaisons.
Et les suivants: P5, P4.Next one.
Maintenant, dans ma liste, j'ai a1, b1, a2, b2, a3, b3, a4, b4 a5 et b5: 10 éléments. Le prochain 2^n-1, c'est 15: je peux donc aller jusqu’à P11 (j'ai 10 éléments, dans ma liste, et j'en veux 15: il m'en manque 5, je suis a P5, il me faut donc ceux de P6à P10, il faut donc que je commence par P11), et je ne ferais que des insertions dans des listes de 15 éléments (donc max 4 comparaisons !) .
Puis P11, P10, P9, P8, P7, P6.
un petit dernier:
Quand j'aurais inséré P11, P10, P9, P8, P7 et P6, j'aurais 22 éléments dans ma liste, le prochain 2^n-1, ça sera 31; 31 - 22, il en manque 9, je suis à p11, et je dois prendre le suivant: 11 + 9 + 1 = 21
Et P21...
A chaque étape,on a fissionné des paires pour les insérer dans une liste de taille 2^(n-1)-1, et on cherche de combien il faut qu'on avance pour insérer nos éléments dans une liste de taille 2^n-1; on commence à voir un motif émerger:
A la prochaine étape, il nous manquera ce qu'il nous manque plus deux fois ce qu'il nous manquait à l'étape précédente...
Donc j’insère mes éléments suivant la suite de Jacobsthal'  j(n+1) = jn + 2* j(n-1)  (j0 = 1, J1 = 3) pour minimiser le nombre de comparaisons (sur Jacobsthal, l'explication de Knuth est plus rigoureuse, même si il va un peu vite dans ses calculs: quand il divise par 3, il "oublie" de multiplier par (2+1) et d'étendre le tout... Mais si on rajoute ces étapes, ça se lit bien; le lien est juste en dessous)

Et j'ai une liste d'éléments triée à renvoyer.

### Des liens pour aller plus loin:
- [Pour implémenter Jacobsthal et apprendre des trucs sur les templates](https://medium.com/zerone-magazine/templates-and-compile-time-execution-c22234a6cd66)
- [Pour y comprendre quelque chose à ces histoires de log](https://www.youtube.com/live/cEvgcoyZvB4?feature=share)
    > ce mec est un génie de pédagogie : pour tous ceux qui se disent qu'ils veulent rattraper leur niveau en maths, je ne saurais que trop conseiller sa chaîne Youtube
- [Une implémentation en cpp pas 98](https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort)
- [Knuth (p. 185)](https://doc.lagout.org/science/0_Computer%20Science/2_Algorithms/The%20Art%20of%20Computer%20Programming%20%28vol.%203_%20Sorting%20and%20Searching%29%20%282nd%20ed.%29%20%5BKnuth%201998-05-04%5D.pdf)


# RECHERCHE PAR DICHOTOMIE

Vu que je vais devoir insérer des éléments dans une liste triée, je vais pouvoir faire des recherches par dichotomie (= commencer par le milieu)
    > faire au plus log2(nb d'éléments dans ma liste) comparaisons; 
    > mieux si j'ai 2^n -1 éléments dans ma liste

Explication:

Combien de comparaisons je dois faire pour insérer par dichotomie un élément dans des listes de différentes tailles ?
On remarque que le nombre de comparaisons nécessaires augmente de un quand on passe d'une liste de taille 2^n-1 à une liste de taille 2^n. 

Si je veux insérer un élément dans une liste de:
- ~~0 élément~~: 
        j'ai juste à l'insérer: 
        ~~0~~ comparaisons
- ~~1 élément~~: 
        j'ai une comparaison à faire et à insérer: 
        ~~1~~ comparaison
- ~~2 éléments~~: 
        une (si j'ai de la chance: je devais insérer 1 dans la liste (3,5), j'ai choisi de commencer par comparer avec 3, et j'ai pu l'insérer direct)
        ou deux comparaisons (si j'ai eu moins de chance: je devais insérer 4); 
        on se base sur le pire cas: 
        ~~2~~ comparaisons
- 3 éléments: 
        une comparaison avec celui de milieu qui va me dire de quel côté me diriger, 
        une liste de un de chaque cote (et j'ai déjà noté que pour une liste de un, il me fallait une comparaison): 1 + 1 = 
        2 comparaisons
- ~~4 éléments~~: 
        un peu comme pour les listes de deux éléments, ça va dépendre de si j'ai de la chance ou pas; 
        deux ou trois comparaison: 
        ~~3~~ comparaisons
- 5 éléments: 
        une comparaison avec celui du milieu, une liste de deux de chaque côté: 
        3 comparaisons aussi
- 6 éléments: 
        je te la fais courte: 
        3 comparaisons
- 7 éléments: 
        une comparaison avec celui du milieu, une liste de trois de chaque côté: 
        3 comparaisons
- ~~8 éléments~~ 
        ~~4~~ comparaisons; 
...etc.
- ~~16 elements:~~
        ~~5~~ comparaisons 

Et donc avec une recherche par dichotomie, rechercher dans une liste de 8 ou de 15 éléments, ça prend le même temps.
