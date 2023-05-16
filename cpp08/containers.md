## LISTE DES CONTAINEURS D'ENTIERS MIS A PART CONTAINEURS ASSOCIATIFS (--> elements ne sont pas associes a des cles):

| Container	            | Description	                                                                            | Accès aux éléments                                        |
|-----------------------|-------------------------------------------------------------------------------------------|-----------------------------------------------------------|
| std::vector	        | Tableau dynamique qui peut stocker un nombre variable d'entiers.	                        | operator[], at(), data(), itérateurs                      |
|                       |   > peut etre redimensionné a la volee                                                    |                                                           |
|                       |                                                                                           |                                                           |
| std::deque	        | File à deux extrémités qui peut stocker un nombre variable d'entiers.	                    | operator[], at(), front(), back(), data(), itérateurs     |
|                       |   > permet insert et suppr facile des elem a l avant et arriere                           |                                                           |
|                       |   > elems dans blocs de memoire separes                                                   |                                                           |
|                       |                                                                                           |                                                           |
| std::list	            | Liste doublement chaînée qui peut stocker un nombre variable d'entiers.	                | itérateurs                                                |
|                       |   > permet insert et suppr facile des elem n importe ou                                   |                                                           |
|                       |                                                                                           |                                                           |
| std::forward_list     | Liste simplement chaînée qui peut stocker un nombre variable d'entiers.	                | itérateurs                                                |
|                       |   > permet insert et suppr facile des elem a l'avant                                      |                                                           |
|                       |                                                                                           |                                                           |
| std::stack	        | Pile qui suit le principe LIFO (Last-In-First-Out).                                       | top(), pas d'accès direct aux autres éléments             |
|                       |   > généralement implémenté en utilisant conteneur sous-jacent eg. std::deque / std::list |                                                           |
|                       |                                                                                           |                                                           |
| std::queue	        | File qui suit le principe FIFO (First-In-First-Out)                                       | front(), back(), pas d'accès direct aux autres éléments   |
|                       |   > généralement implémenté en utilisant conteneur sous-jacent eg. std::deque / std::list |                                                           |
|                       |                                                                                           |                                                           |
| std::priority_queue   | File de priorité qui stocke les éléments dans un ordre trié                               | top(), pas d'accès direct aux autres éléments             |
|                       |   > généralement implémenté en utilisant conteneur sous-jacent eg. std::deque / std::list |                                                           |
|                       |                                                                                           |                                                           |
| Since C++11           |                                                                                           |                                                           |
|-----------------------|-------------------------------------------------------------------------------------------|-----------------------------------------------------------|
| std::array	        | Tableau statique qui peut stocker un nombre fixe d'entiers déterminé à la compilation.	| operator[], at(), data(), itérateurs                      |
|                       |   > elements stockes dans un bloc continu de memoire                                      |                                                           |

