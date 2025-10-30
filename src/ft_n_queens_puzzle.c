/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_queens_puzzle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:41:41 by kebris-c          #+#    #+#             */
/*   Updated: 2025/09/02 14:56:10 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	ft_safe_cell(int *board, int col, int row)
{
	int	prev_col;
	int	prev_row;

	prev_col = 0;
	while (prev_col < col)
	{
		prev_row = board[prev_col];
		if (prev_row == row || prev_row - prev_col == row - col
			|| prev_row + prev_col == row + col)
			return (FALSE);
		prev_col++;
	}
	return (TRUE);
}

static void	ft_setup_display(int n, int *board, char **table, int *sol_num)
{
	int	i;
	int	j;
	int	col;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			table[i][j] = '.';
			j++;
		}
		i++;
	}
	col = 0;
	while (col < n)
	{
		table[board[col]][col] = 'Q';
		col++;
	}
	(*sol_num)++;
	printf("\nSolution nº%d:\n", *sol_num);
}

static int	ft_print_solution(int n, int *board, int *sol_num)
{
	char	**table;
	int		i;
	int		j;

	table = (char **)malloc(sizeof(char *) * n);
	if (!table)
		return (-1);
	i = 0;
	while (i++ < n)
	{
		table[i - 1] = (char *)malloc(sizeof(char) * n);
		if (!table[i - 1])
			return (ft_free_matrix(table), -1);
	}
	ft_setup_display(n, board, table, sol_num);
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			printf(" %c\n", table[i][j]);
	}
	ft_free_matrix(table);
	return (0);
}

static void	ft_queen_backtrack(int *board, int n, int col, int *sol_num)
{
	int	row;

	if (col == n)
	{
		ft_print_solution(n, board, sol_num);
		return ;
	}
	row = 0;
	while (row < n)
	{
		if (ft_safe_cell(board, col, row))
		{
			board[col] = row;
			ft_queen_backtrack(board, n, col + 1, sol_num);
		}
		row++;
	}
}

void	ft_n_queens_puzzle(int n)
{
	int	*board;
	int	sol_num;
	int	i;

	board = (int *)malloc(sizeof(int) * n);
	if (!board)
		return ;
	i = 0;
	while (i < n)
	{
		board[i] = 0;
		i++;
	}
	sol_num = 0;
	ft_queen_backtrack(board, n, 0, &sol_num);
	free(board);
}
