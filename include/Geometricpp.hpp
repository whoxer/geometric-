/* Geometricpp - escrito por @whoxer */

/*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*  
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*  GNU General Public License for more details.
*  
*  You should have received a copy of the GNU General Public License
*  along with this program. If not, see <https://www.gnu.org/licenses/>.
*/ 

#ifndef GEOMETRICPP_HPP
#define GEOMETRICPP_HPP

#include <iostream>
#include <cmath>
#include <stdexcept>

#include <type_traits>
#include <utility>

namespace Geometricpp 
{

    // Tipos definidos.
    typedef double_t GEOMETRIC_SIDE;
    typedef double_t DIAGONAL;


    // ``PI`` Armazena constante valor de PI
    const double_t PI = 3.141592654;

    /* Teorema de Pitágoras aplicada a Diagonais
     *
     *  Calcula e retorna o comprimento dos lados usando as diagonais
     *  de quatro triângulos retângulos.
     * 
     *  exemplo:
     *       
     *      L² = (D / 2)² + (d / 2)²
     * 
     * 
     *      ...
     */
    template <typename length> 
    typename std::enable_if<std::is_arithmetic<length>::value, length>::type 
    pitagoras_diagonais(length largest_diagonal, length smallest_diagonal) 
    {
        if (largest_diagonal < smallest_diagonal)
        {
            throw std::invalid_argument("largest_diagonal parameter cannot be smaller than smallest_diagonal parameter");
        }

        return sqrt((largest_diagonal / 2) * (largest_diagonal / 2) + 
                    (smallest_diagonal / 2) * (smallest_diagonal / 2));
    }


    // TODO* Implementar assim que terminar losango.
    /* Teorema de Pitágoras
    *  
    *  a² = b² + c²
    */
    // template <typename hipotenusa, >
    // typename std::enable_if<std::is_arithmetic<hipotenusa>::value, hipotenusa>::type
    // pitagoras()
    

    /*
     * O namespace ``Quadrilaterals`` é responsável por agrupar as funções que
     * realizam cálculos relacionados a objetos geométricos planos do tipo quadrilátero.
     * Quadriláteros são figuras geométricas com quatro lados e ângulos internos que
     * somam 360 graus, sendo representados por tipos específicos como o "Quadrado"
     * e o "Retângulo", entre outros.
     *
     * Este namespace serve para organizar o código de maneira lógica, separando as
     * funções de cálculo associadas a quadriláteros em uma única área. Isso facilita
     * a manutenção do código e evita conflitos de nomes com outras funções ou classes
     * que não estão relacionadas a quadriláteros.
     *
     * Funções dentro deste namespace podem incluir:
     * - Cálculo de área: diferentes fórmulas para quadrados, retângulos e outros tipos
     *   de quadriláteros.
     * - Cálculo de perímetro: soma dos comprimentos de todos os lados de um quadrilátero.
     * - Verificação de propriedades: funções que verificam se um quadrilátero é regular,
     *   ou se os lados opostos são paralelos, por exemplo.
     *
     * Ao agrupar essas funcionalidades no namespace "Quadrilaterals", o código se torna
     * modular e organizado, permitindo fácil expansão e reutilização. Um usuário da
     * biblioteca pode acessar todas as funções relacionadas a quadriláteros usando o
     * prefixo "Quadrilaterals::", o que melhora a legibilidade e claridade do código.
     */
    namespace Quadrilaterals 
    {
        /**
         * @class Square
         * @brief Representa um quadrado definido por um lado.
         *
         * Esta classe encapsula a lógica para calcular propriedades de um quadrado,
         * que é uma forma geométrica com todos os lados de igual comprimento.
         *
         * A classe possui os seguintes métodos:
         * - size(): Retorna o comprimento do lado do quadrado.
         * - area(): Calcula e retorna a área do quadrado.
         * - perimeter(): Calcula e retorna o perímetro do quadrado.
         * - diagonal(): Calcula e retorna o comprimento da diagonal do quadrado.
         *
         * @param side_length Comprimento do lado do quadrado.
         */
        class Square 
        {
            private:
                GEOMETRIC_SIDE side_length;
            public:
                Square(GEOMETRIC_SIDE side_length) : side_length(side_length) {};

                double_t size() const;

                double_t area() const;
                double_t perimeter() const;
                double_t diagonal() const;
        };

        /**
         * @class Rectangle
         * @brief Representa um retângulo definido por dois lados (altura e largura).
         *
         * Esta classe encapsula a lógica para garantir que um retângulo não
         * possa ser criado com lados iguais, prevenindo a formação de um quadrado.
         *
         * A classe possui os seguintes métodos:
         * - size(): Retorna um par contendo a altura e a largura do retângulo.
         * - area(): Calcula e retorna a área do retângulo.
         * - perimeter(): Calcula e retorna o perímetro do retângulo.
         * - diagonal(): Calcula e retorna o comprimento da diagonal do retângulo.
         *
         * @param height Altura do retângulo.
         * @param width Largura do retângulo.
         * @throws std::invalid_argument Se os lados fornecidos forem iguais.
         */
        class Rectangle 
        {
            private:
                GEOMETRIC_SIDE height, width;

            public:
                explicit Rectangle(GEOMETRIC_SIDE h, GEOMETRIC_SIDE w) : height(h), width(w) 
                {
                    if (height == width) 
                    {
                        throw std::invalid_argument("Sides can't be equal, at least one needs to be different.");
                    }
                }

                std::pair<Geometricpp::GEOMETRIC_SIDE, Geometricpp::GEOMETRIC_SIDE> size() const;

                double_t area() const;
                double_t perimeter() const;
                double_t diagonal() const;
        };

        class Rhombus 
        {
            private:
                DIAGONAL diagonal_a, diagonal_b;
            public:
                explicit Rhombus(double_t side, double_t angle) {
                    diagonal_a = side * sqrt(2 * (1 + cos(angle)));
                    diagonal_b = side * sqrt(2 * (1 - cos(angle)));
                }

                double_t area() const;
                double_t perimeter() const;
                double_t height() const;
        };
    };
    
    // TODO
    namespace Triangles {};
}


#endif