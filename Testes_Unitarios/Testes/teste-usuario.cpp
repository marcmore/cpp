#include "catch.hpp"
#include "Usuario.hpp"

TEST_CASE("Usu�rio deve saber informar seu primeiro nome")
{
  Usuario vinicius("Vinicius");

  std::string primeiroNome = vinicius.recuperaPrimeiroNome();

  REQUIRE("Vinicius" == primeiroNome);
}