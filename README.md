# lem-in

A comprendre :
Theorie des graphes
Recherche de chemin
Algorithme A

- Se deplacer de noeud en noeud en ajoutant la longueur 
- Si longueur non nul et > a la nouvelle longueur modif le trajet
- Si end ateint remettre les len a 0 sauf le chemin trouve mettre busy a 1 pour le chemin
- si ants < len terminer
- sinon refaire l'algo 

ants + len1 - 1 = nbr coup

autre chemin interessant
nbr coup > len2

chemin len1 + len2
nbr coup = nbr coup - len2

nbr coup > len3
chemin len1 len2 len 3
nbr = nbr - len3 ...
