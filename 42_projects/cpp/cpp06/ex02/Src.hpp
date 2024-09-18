/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Src.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:37:35 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/16 12:28:43 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);
bool downcastA(Base& p);
bool downcastB(Base& p);
bool downcastC(Base& p);
