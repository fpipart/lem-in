
void	print_room(t_lem *room)
{
	t_lem	*tmp;

	if (room)
	{
		tmp = room;
		while (tmp)
		{
			ft_printf("ROOM = $%s$ len = %d, busy = %d, node->ants = %s\n", tmp->room, tmp->len, tmp->busy, tmp->ant);
			tmp = tmp->next;
		}
	}
}
