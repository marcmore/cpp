#include "nao_acertou.hpp"

//extern std::string palavra_secreta; // usa o extern para avisar que essa variável já está declarada em outra lugar
//extern std::map<char, bool> chutou;

bool nao_acertou(std::string& palavra_secreta, const std::map<char, bool>& chutou) {
	for (char letra : palavra_secreta) {
		if (chutou.find(letra) == chutou.end() || !chutou.at(letra)) {
			return true;
		}
	}
	return false;
}