void	ft_swap(void *obj1, void *obj2)
{
	void	buf;

	buf = *obj1;
	*obj1 = *obj2;
	*obj2 = buf;
}
