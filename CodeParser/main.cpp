#include <iostream>

constexpr auto source = R"(
#include "Test.h"
#include "Test2.h"

namespace NMSPC
{
	class Test3
	{
	public:
		Test3() {}
	};
})";


int main(int argc, char *argv[])
{
	//auto tokenizer = CppTokenizer::Create();
	//auto lexer = CppLexer::Create();

	//Parser parser(tokenizer, lexer);	
	//parser.parse(source);

	//const auto tokens1 = tokenizer->tokens();

	//// #
	//// i
	//// n
	//// c
	//// l
	//// u
	//// d
	//// e
	////
	//// "
	//// ...
	//
	//const auto tokens2 = lexer->tokens();

	//// PRAGMA
	//// INCLUDE
	//// ASTERISK
	//// SYMBOL Test.h
	//// ASTERISK
	//// NEXT_LINE
	//// ...

	//const auto ast = parser->tree();

	//// INCLUDE
	////   Test.h
	//// INCLUDE
	////   Test2.h
	//// NAMESPACE NMSPC
	////   CLASS Test3
	////     PRIVATE_SCOPE
	////     PUBLIC_SCOPE
	////       FUNCTION CTOR NO_ARGS
	////         
	//
	//__debugbreak();
}
