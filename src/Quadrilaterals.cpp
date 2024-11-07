#include "Geometricpp.hpp"

/**
 * @brief Retorna o tamanho do lado do quadrado.
 *
 * Esta função retorna o valor do comprimento de um lado do quadrado.
 * Como um quadrado possui lados de tamanho igual, o valor do lado é
 * suficiente para representar seu tamanho.
 *
 * @return double_t Comprimento do lado do quadrado.
 */
double_t Geometricpp::Quadrilaterals::Square::size() const 
{
    return side_length;
}

/**
 * @brief Calcula a área do quadrado.
 *
 * Esta função calcula e retorna a área do quadrado, que é obtida
 * elevando o comprimento do lado ao quadrado.
 *
 * @return double_t Área do quadrado.
 */
double_t Geometricpp::Quadrilaterals::Square::area() const 
{
    return side_length * side_length;
}

/**
 * @brief Calcula o perímetro do quadrado.
 *
 * Esta função calcula e retorna o perímetro do quadrado,
 * multiplicando o comprimento do lado pelos seus quatro lados.
 *
 * @return double_t Perímetro do quadrado.
 */
double_t Geometricpp::Quadrilaterals::Square::perimeter() const 
{
    return side_length * 4;
}

/**
 * @brief Calcula o comprimento da diagonal do quadrado.
 *
 * Esta função calcula e retorna o comprimento da diagonal do quadrado,
 * usando a fórmula diagonal = lado * √2, que deriva das propriedades dos quadrados.
 *
 * @return double_t Comprimento da diagonal do quadrado.
 */

double_t Geometricpp::Quadrilaterals::Square::diagonal() const 
{
    return std::sqrt(2) * side_length;
}

/**
 * @brief Retorna as dimensões do retângulo.
 *
 * Esta função retorna as dimensões do retângulo, com a altura e a largura
 * representadas como um par de valores.
 *
 * @return std::pair<Geometricpp::GEOMETRIC_SIDE, Geometricpp::GEOMETRIC_SIDE>
 * Par contendo a altura e a largura do retângulo, onde o primeiro elemento
 * representa a altura e o segundo a largura.
 */
std::pair<Geometricpp::GEOMETRIC_SIDE, Geometricpp::GEOMETRIC_SIDE> 
Geometricpp::Quadrilaterals::Rectangle::size() const 
{
    return std::make_pair(height, width);
}

/**
 * @brief Calcula a área do retângulo.
 *
 * Esta função calcula e retorna a área do retângulo, obtida pela multiplicação
 * da altura pela largura.
 *
 * @return double_t Área do retângulo.
 */
double_t Geometricpp::Quadrilaterals::Rectangle::area() const 
{
    return height * width;
}

/**
 * @brief Calcula o perímetro do retângulo.
 *
 * Esta função calcula e retorna o perímetro do retângulo, que é
 * obtido pela fórmula 2 * (altura + largura).
 *
 * @return double_t Perímetro do retângulo.
 */
double_t Geometricpp::Quadrilaterals::Rectangle::perimeter() const 
{
    return 2 * (height + width);
}

/**
 * @brief Calcula o comprimento da diagonal do retângulo.
 *
 * Esta função calcula e retorna o comprimento da diagonal do retângulo,
 * utilizando o Teorema de Pitágoras: diagonal = √(altura² + largura²).
 *
 * @return double_t Comprimento da diagonal do retângulo.
 */
double_t Geometricpp::Quadrilaterals::Rectangle::diagonal() const 
{
    return sqrt(pow(height, 2) + pow(width, 2));
}

/**
 * @brief Calcula a área do losango.
 *
 * Esta função calcula e retorna a área do losango, utilizando a fórmula
 * área = (diagonal_a * diagonal_b) / 2, onde diagonal_a e diagonal_b são
 * as diagonais do losango.
 *
 * @return double_t Área do losango.
 */
double_t Geometricpp::Quadrilaterals::Rhombus::area() const 
{
    return (diagonal_a * diagonal_b) / 2;
}

/**
 * @brief Calcula o perímetro do losango.
 *
 * Esta função calcula e retorna o perímetro do losango, utilizando a fórmula
 * perímetro = 4 * lado, onde o lado é calculado usando o Teorema de Pitágoras
 * a partir das diagonais, por meio da função `pitagoras_diagonais()`.
 *
 * @return double_t Perímetro do losango.
 */
double_t Geometricpp::Quadrilaterals::Rhombus::perimeter() const 
{
    return 4 * Geometricpp::pitagoras_diagonais(diagonal_a, diagonal_b);
}

/**
 * @brief Calcula a altura do losango.
 *
 * Esta função calcula e retorna a altura do losango, utilizando a fórmula
 * altura = área / comprimento do lado. A área é calculada com base nas diagonais
 * do losango, e o comprimento do lado é obtido utilizando o Teorema de Pitágoras
 * através da função `pitagoras_diagonais()`.
 *
 * @return double_t Altura do losango.
 */
double_t Geometricpp::Quadrilaterals::Rhombus::height() const 
{
    
    double_t area = (diagonal_a * diagonal_b) / 2,
    side_length = pitagoras_diagonais(diagonal_a, diagonal_b);

    return area / side_length;
}

/**
 * @brief Calcula o raio da circunferência inscrita no losango.
 *
 * Esta função calcula e retorna o raio da circunferência inscrita no losango
 * utilizando a fórmula inradius = área / perímetro. A área é calculada com
 * base nas diagonais do losango, e o perímetro é obtido multiplicando o
 * comprimento do lado (calculado usando o Teorema de Pitágoras) por 4.
 *
 * @return double_t Raio da circunferência inscrita no losango.
 */
double_t Geometricpp::Quadrilaterals::Rhombus::inradius() const 
{

    double_t area = (diagonal_a * diagonal_b) / 2, 
    side_length = pitagoras_diagonais(diagonal_a, diagonal_b);

    double_t perimeter = 4 * side_length;

    return area / perimeter;
}

/**
 * @brief Exibe as diagonais do losango.
 *
 * Esta função exibe os valores das duas diagonais do losango (diagonal_a e diagonal_b)
 * no console, utilizando o fluxo de saída padrão.
 */
void Geometricpp::Quadrilaterals::Rhombus::show_diagonals() const
{
    std::cout << "DIAGONAL_1: " << diagonal_a;
    std::cout << "DIAGONAL_2: " << diagonal_b;
}


/*
double_t Geometricpp::Quadrilaterals::Rhombus::circumradius() const {
    // code
}
 */
