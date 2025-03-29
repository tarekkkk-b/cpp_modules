/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:32:31 by tabadawi          #+#    #+#             */
/*   Updated: 2024/12/11 21:01:31 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);

    std::cout << "\n------ - - -- - ---- -- --- - -- --- -- \n" << std::endl;   
    std::cout << "For vertices { (0,0) , (5,0) , (0,5) }: \n" << std::endl;
    std::cout << "------ - - -- - ---- -- --- - -- --- -- \n" << std::endl;
    if (bsp(a, b, c, Point(1, 1))) {
        std::cout << "Point (1,1) is inside the triangle.\n";
    } else {
        std::cout << "Point (1,1) is outside the triangle.\n";
    }

    if (bsp(a, b, c, Point(100, 100))) {
        std::cout << "Point (100,100) is inside the triangle.\n";
    } else {
        std::cout << "Point (100,100) is outside the triangle.\n";
    }

    if (bsp(a, b, c, Point(0, 5))) {
        std::cout << "Point (0,5) is inside the triangle.\n";
    } else {
        std::cout << "Point (0,5) is outside the triangle.\n";
    }

    if (bsp(a, b, c, Point(5, 0))) {
        std::cout << "Point (5,0) is inside the triangle.\n";
    } else {
        std::cout << "Point (5,0) is outside the triangle.\n";
    }
    std::cout << "------ - - -- - ---- -- --- - -- --- -- \n" << std::endl;

    Point d(-2, -15);
    Point e(-15, -2);
    Point f(0, 0);
    std::cout << "For vertices { (-2,-15) , (-15,-2) , (0,0) }: \n" << std::endl;
    std::cout << "------ - - -- - ---- -- --- - -- --- -- \n" << std::endl;
    if (bsp(d, e, f, Point(1, 1))) {
        std::cout << "Point (1,1) is inside the triangle.\n";
    } else {
        std::cout << "Point (1,1) is outside the triangle.\n";
    }

    if (bsp(d, e, f, Point(0, -1))) {
        std::cout << "Point (0,-1) is inside the triangle.\n";
    } else {
        std::cout << "Point (0,-1) is outside the triangle.\n";
    }

    if (bsp(d, e, f, Point(-500, 5))) {
        std::cout << "Point (-500,5) is inside the triangle.\n";
    } else {
        std::cout << "Point (-500,5) is outside the triangle.\n";
    }

    if (bsp(d, e, f, Point(-12, -13))) {
        std::cout << "Point (-12, -13) is inside the triangle.\n";
    } else {
        std::cout << "Point (-12, -13) is outside the triangle.\n";
    }
    std::cout << "------ - - -- - ---- -- --- - -- --- -- \n" << std::endl;
}