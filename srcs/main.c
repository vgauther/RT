/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 00:55:44 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/03 15:26:33 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int main(int ac, char **av)
{
	SDL_Event		event;
	SDL_Renderer	*renderer;
	SDL_Window		*window;
	t_obj			obj;

	if (ac != 2)
		usage();
	obj = parser(av[1]);
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(SIZE_X, SIZE_Y, 0,
		&window, &renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawPoint(renderer, 100, 200);
	SDL_RenderDrawPoint(renderer, 100, 201);
	SDL_RenderDrawPoint(renderer, 100, 202);
	SDL_RenderDrawPoint(renderer, 100, 203);
	SDL_RenderDrawPoint(renderer, 98, 204);
	SDL_RenderDrawPoint(renderer, 98, 199);
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderDrawPoint(renderer, 100, 199);
	SDL_RenderDrawPoint(renderer, 100, 205);
	SDL_RenderDrawPoint(renderer, 100, 206);
	SDL_RenderPresent(renderer);
	while (1)
	{
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
			break ;
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}
