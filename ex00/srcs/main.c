#include "../include/rush02.h"
int main(int argc, char **argv)
{
    t_dict  *dict;
    char    **split;
    int     split_size;

    //ft_dict.c
    if (argc == 2)
		dict = ft_dict("numbers.dict");
	else if (argc == 3)
		dict = ft_dict(argv[1]);
	else
		return (1);
	if (!dict)
		return (1);


    //ft_splitstr.c
    if (argc == 2)
		split = ft_splitstr(argv[1], &split_size);
	else
		split = ft_splitstr(argv[2], &split_size);
	if (!split)
		return (1);

    //// ft_print_result.c
	ft_print_result(split, split_size, dict);

	return (0);
}
