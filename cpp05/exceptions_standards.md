Exception	Description	Cas où elles sont jetées
std::bad_alloc	Erreur d'allocation de mémoire (épuisement de la mémoire RAM).	Lorsque new échoue pour allouer de la mémoire.
std::bad_cast	Conversion dynamique de type invalide.	Lorsqu'une conversion dynamic_cast échoue.
std::runtime_error	Erreur d'exécution générale.	Lorsqu'une condition d'exécution prévue n'est pas remplie.
std::logic_error	Erreur de logique dans le programme.	Lorsqu'une erreur logique est détectée.
std::out_of_range	Index ou valeur hors limites.	Lorsque l'index d'un tableau est hors de sa plage valide.
std::invalid_argument	Argument de fonction invalide.	Lorsqu'un argument passé à une fonction est invalide.
std::overflow_error	Dépassement de capacité lors d'une opération arithmétique.	Lorsqu'une opération arithmétique dépasse la capacité.
std::underflow_error	Dépassement de capacité lors d'une opération arithmétique.	Lorsqu'une opération arithmétique a une valeur trop petite.
std::range_error	Erreur de plage.	Lorsqu'une erreur de plage est détectée.
std::ios_base::failure	Erreur d'opération d'entrée/sortie.	Lorsqu'une opération d'entrée/sortie échoue.
std::bad_function_call	Appel d'un objet de type std::function non valable.	Lorsqu'une tentative d'appel d'une std::function invalide.
std::system_error	Erreur système.	Lorsqu'une opération système échoue.
std::exception	Classe de base pour les exceptions standard en C++.	Utilisée généralement pour capturer des exceptions génériques.
