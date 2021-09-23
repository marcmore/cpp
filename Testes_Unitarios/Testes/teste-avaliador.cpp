#include "Avaliador.hpp"
#include <iostream>
#include <string>
#include "catch.hpp"

Leilao emOrdemCrescente()
{
  //Arrange - GIven
  Lance primeiroLance(Usuario("Vinicius Dias"), 1000);
  Lance segundoLance(Usuario("Ana Maria"), 2000);
  Leilao leilao("Fiat 147 0km");
  leilao.recebeLance(primeiroLance);
  leilao.recebeLance(segundoLance);

  return leilao;
}

Leilao emOrdemDecrescente()
{
  //Arrange - GIven
  Lance primeiroLance(Usuario("Vinicius Dias"), 2000);
  Lance segundoLance(Usuario("Ana Maria"), 1000);
  Leilao leilao("Fiat 147 0km");
  leilao.recebeLance(primeiroLance);
  leilao.recebeLance(segundoLance);

  return leilao;
}

TEST_CASE("Avaliador")
{
  //Arrange - GIven
  Avaliador leiloeiro;

  SECTION("Leilões Ordenados")
  {
  Leilao leilao = GENERATE(emOrdemCrescente(), emOrdemDecrescente());

    SECTION("Deve recuperar maior lance do leilão")
    {
      // Act - When  
      leiloeiro.avalia(leilao);

      // Assert - Then
      REQUIRE(2000 == leiloeiro.recuperaMaiorValor());


    }

    SECTION("Deve recuperar menor lance do leilão")
    {
      // Act - When
      leiloeiro.avalia(leilao);

      // Assert - Then
      REQUIRE(1000 == leiloeiro.recuperaMenorValor());


    }
  }

  SECTION("Deve recuperar os 3 maiores lances")
  {
    //Arrange - GIven
    Lance primeiroLance(Usuario("Vinicius Dias"), 1000);
    Lance segundoLance(Usuario("Ana Maria"), 2000);
    Lance terceiroLance(Usuario("JP"), 1500);
    Lance quartoLance(Usuario("RM"), 2500);
    Leilao leilao("Fiat 147 0km");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);
    leilao.recebeLance(terceiroLance);
    leilao.recebeLance(quartoLance);

    // Act - When
    leiloeiro.avalia(leilao);

    // Assert - Then
    std::vector<Lance> maiores3Lances = leiloeiro.recupera3MaioresLances();
    REQUIRE(3 == maiores3Lances.size());
    REQUIRE(2500 == maiores3Lances[0].recuperaValor());
    REQUIRE(2000 == maiores3Lances[1].recuperaValor());
    REQUIRE(1500 == maiores3Lances[2].recuperaValor());
  }
}


