# Pathfinder

Plutôt que d’utiliser directement un algorithme de pathfinding existant, ce projet adopte une approche exploratoire basée sur l’observation de la structure du problème. L’objectif est de concevoir et d’implémenter un algorithme capable de déterminer s’il existe un chemin valide entre un point A et un point B.

Les problèmes comme le pathfinding sur grille ont été étudiés pendant longtemps, donc les solutions efficaces ont déjà été découvertes mais redécouvrir une idée existante par soi-même est une excellente façon de comprendre profondément le problème.

![Alt text](shemas/shemas.png)

# Etape N-1

On remarque que chaque noeud a au maximum deux noeud parent et deux noeud enfant. Nous pouvons donc etablire cette structure de noeud:

```

typedef struct s_node
{
	int		value;
	void	*parent_right;
	void	*parent_left;
	void	*children_right;
	void	*children_left;

} t_node;

```