/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:13:30 by hhammiou          #+#    #+#             */
/*   Updated: 2026/01/23 13:13:31 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av){
    if(ac >= 2){
        for(int i = 1; i < ac; i++){
            std::string text = av[i];
            for(int j = 0; text[j]; j++){
                text[j] = std::toupper(text[j]);
            }
            std::cout << text;
            if (i < ac - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
        return 0;
    }
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 1;
}