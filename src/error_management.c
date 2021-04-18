//
// Created by Podrick payne Corlys velaryon on 4/18/21.
//

#include "lem-in.h"

void		error_management(char *msg)
{
	ft_putendl(msg);
	exit(-1);
}

void		safe_call_int(int check, char *msg)
{
	static int		error_code = 0;

	error_code--;
	if (check != 0)
	{
		ft_putendl(msg);
		exit(error_code);
	}
}

void		safe_call_ptr(void *check, char *msg)
{
	static int		error_code = 0;

	error_code++;
	if (check != NULL)
	{
		ft_putendl(msg);
		exit(error_code);
	}
}
