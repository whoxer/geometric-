/**
 * @whoxer
 *
 * @brief Biblioteca de geometria plana para o C++
 * */

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
    /**
     * @typedef GEOMETRIC_SIDE
     * @brief Tipo definido para lados de objetos geométricos planos.
     *
     * Este tipo representa os lados de formas geométricas,
     * sendo um alias para double_t.
     */
    typedef double_t GEOMETRIC_SIDE;

    /**
     * @typedef DIAGONAL
     * @brief Tipo definido para as diagonais de objetos geométricos.
     *
     * Este tipo representa as diagonais de formas geométricas,
     * sendo um alias para double_t.
     */
    typedef double_t DIAGONAL;

    /**
     * @var PI
     * @brief Armazena o valor constante de PI.
     *
     * Esta constante é usada em cálculos geométricos que envolvem
     * círculos e outras formas baseadas em pi.
     */
    const double_t PI = 3.14159265358979323846;

    /**
     * @brief Calcula a diagonal de um retângulo usando o teorema de Pitágoras.
     *
     * Esta função recebe as duas diagonais de um retângulo e calcula o comprimento da
     * diagonal resultante com base nas medidas fornecidas. O cálculo é feito usando
     * o teorema de Pitágoras, considerando a maior diagonal como um dos catetos
     * de um triângulo retângulo, e a menor diagonal como o outro cateto.
     *
     * @tparam length Tipo numérico que deve ser aritmético (int, float, double, etc.).
     *
     * @param largest_diagonal O comprimento da maior diagonal do retângulo. Este valor
     * deve ser maior que o comprimento da menor diagonal.
     * @param smallest_diagonal O comprimento da menor diagonal do retângulo. Este valor
     * deve ser menor que o comprimento da maior diagonal.
     *
     * @return O comprimento da diagonal resultante calculada.
     *
     * @throws std::invalid_argument Se largest_diagonal for menor ou igual a
     * smallest_diagonal.
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

    /**
     * @brief Calcula a hipotenusa de um triângulo retângulo usando o Teorema de Pitágoras.
     *
     * Essa função recebe os comprimentos de dois catetos e retorna o comprimento da hipotenusa
     * de um triângulo retângulo. A fórmula utilizada é: c² = a + b²,
     * onde 'a' e 'b' são os catetos e 'c' é o comprimento da hipotenusa.
     *
     */
    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, T>::type
    pitagoras(T a, T b)
    {
        return std::sqrt(a * a + b * b);
    }

    /**
     * @namespace Quadrilaterals
     *
     * @brief
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
            /**
             * @brief Construtor para a classe Square.
             *
             * Este construtor inicializa um objeto da classe `Square` com o comprimento
             * de um lado fornecido como parâmetro. O valor de `side_length` é armazenado
             * no atributo correspondente da classe para representar o tamanho do lado do quadrado.
             *
             * @param side_length Comprimento do lado do quadrado.
             */
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
            /**
             * @brief Construtor para a classe Rectangle.
             *
             * Este construtor inicializa um objeto da classe `Rectangle` com os valores
             * fornecidos para altura (`h`) e largura (`w`). Se os valores de altura e
             * largura forem iguais, uma exceção do tipo `std::invalid_argument` é lançada,
             * garantindo que o retângulo não seja um quadrado.
             *
             * @param h Altura do retângulo.
             * @param w Largura do retângulo.
             *
             * @throws std::invalid_argument Se os valores de altura e largura forem iguais.
             */
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

        /**
         * @class Rhombus
         * @brief Classe que representa um losango e fornece métodos para calcular suas propriedades geométricas.
         *
         * Esta classe utiliza as diagonais do losango, que são calculadas com base no comprimento do lado
         * e no ângulo fornecido. A classe fornece funções para calcular a área, o perímetro, a altura,
         * o raio interno e o raio circunscrito do losango.
         *
         * @note As diagonais são calculadas usando as seguintes fórmulas:
         *       - diagonal_a = lado * sqrt(2 * (1 + cos(angulo)));
         *       - diagonal_b = lado * sqrt(2 * (1 - cos(angulo)));
         *
         * @warning O ângulo deve ser fornecido em radianos.
         */
        class Rhombus
        {
        private:
            DIAGONAL diagonal_a, diagonal_b;

        public:
            /**
             * @brief Construtor para a classe Rhombus.
             *
             * Este construtor inicializa um objeto da classe `Rhombus` com o comprimento
             * do lado (`side`) e o ângulo entre as diagonais (`angle`). O valor do ângulo
             * é convertido para radianos, e as diagonais do losango são calculadas com base
             * na fórmula geométrica que envolve o lado e o ângulo.
             *
             * @param side Comprimento do lado do losango.
             * @param angle Ângulo entre as diagonais em graus.
             */
            explicit Rhombus(double_t side, double_t angle)
            {
                double_t angle_radians = angle * PI / 180.0;

                diagonal_a = side * sqrt(2 * (1 + cos(angle_radians)));
                diagonal_b = side * sqrt(2 * (1 - cos(angle_radians)));
            }

            void show_diagonals() const;

            double_t area() const;
            double_t perimeter() const;
            double_t height() const;

            double_t inradius() const;
            double_t circumradius() const;
        };
    };

    // TODO
    // namespace Triangles
    // {
    // };
}

#endif