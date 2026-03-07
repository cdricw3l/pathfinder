typedef struct s_node
{
	int		value;
	void	*parent_right;
	void	*parent_left;
	void	*children_right;
	void	*children_left;

} t_node;
