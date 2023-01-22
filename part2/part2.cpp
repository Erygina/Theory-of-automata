#pragma once
#include <map>
#include <stack>
#include <vector>
#include <string>
#include <string>

using namespace std;

struct debugInfo
{
    int line;
    int pos;
};

struct InterpretException : public std::exception
{
    std::string msg;
    const char* what() const throw () {
        return msg.c_str();
    }

    InterpretException(std::string m, debugInfo i) {
        m += "\nError found at line=" + std::to_string(i.line) + ", pos=" + std::to_string(i.pos) + "\n";
        msg = m;
    }
};

enum class lexemeType
{
	VarName, //имя (идентификатор переменной)
	IntNum, //целое число без знака
	IntType, //int
	ArrayType,
	If,
	Else,
	While,
	Read,
	Write,
	Allocate, //new
	LeftBrace, //{
	RightBrace, //}
	LeftSquareBracket, //[
	RightSquareBracket, //]
	LeftRoundBracket, //(
	RightRoundBracket, //)
	Plus,
	Minus,
	Multiply,
	Divide,
	Semicolon, //;
	Comma,
	Less, //<
	Assign, //=
	More, //>
	Equal, //==
	LessOrEqual, //<=
	MoreOrEqual, //>=
	NotEqual, //!=
	Finish,
	Error
};

struct lexeme
{
	lexemeType lexeme_type;
	string value;
	debugInfo info;
};

class Analyzer {
public:
	void Run();
	vector<lexeme> GetData();
	Analyzer(const string&);

private:
	lexeme NextLexeme();
	bool ischar(char ch);

	string program_text;
	int current_index;
	debugInfo current_info;
	vector<lexeme> data;
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\
//Тип элемента в ОПС
enum class OpsItemType {
	IntVariable,
	IntNumber,
	Operation,
	Error
};
//Операция элемента в ОПС
enum class OpsItemOperation {
	Read,
	Write,
	Plus,
	Minus,
	UnarMinus,
	Miltiply,
	Divide,
	Less,
	Assign,
	More,
	Equal,
	LessOrEqual,
	MoreOrEqual,
	NotEqual,
	Jump,
	JumpIfFalse,
	Index,
	Memory,
	Error
};

//Структура описывающая элемент ОПС
struct OpsItem {
	OpsItemType type = OpsItemType::Error; //Изначально тип элемента - ошибка
	OpsItemOperation operation = OpsItemOperation::Error; // И операция тоже ошибка
	string var_name;
	int int_num = 0;
	debugInfo info;
	//Если у нас переменная в ОПС
	OpsItem(string name, OpsItemType t, debugInfo i)
	{
		type = t;
		var_name = name;
		info = i;
	}
	//Если у нас операция в ОПС
	OpsItem(OpsItemOperation op, debugInfo i)
	{
		type = OpsItemType::Operation;
		operation = op;
		info = i;
	}
	//Если у нас число в ОПС
	OpsItem(int number, debugInfo i)
	{
		type = OpsItemType::IntNumber;
		int_num = number;
		info = i;
	}
};
//Структура описывающая данных для интерпритатора (то что мы передадим интерпритатору ОПС)
struct InterpretData
{
	vector<OpsItem> ops; //Вектор ОПС
	map<string, int> int_table; //Таблица интов
	map<string, vector<int>> massInt_table; //Таблица массивов
};
//Генератор ОПС
class Generator {
public:
	void Run(); //Запускаем генератор ОПС
	InterpretData GetData(); //Получаем данные от него
	Generator(vector<lexeme>); //Передача генератору вектора лексем

private:
	void RecognizeNonterminal(); //Разложение нетерминалов
	void DoTask(); //Выполнения действий
	//Структура описывающая числа и массивы
	enum class table {
		Int, //числа
		MassInt, //массивы
	};

	//Все возможные нетерминалы для распознования генератора
	enum class Nonterminal {
		S, // → intIS | arrayIS | aH=E;Q | read(aH);Q | write(E);Q | new(a, E);Q | if (C) {SQ} KZQ | while (C) {SQ} Q
		Q, // → aH = E; Q | read(aH); Q | write(E); Q | new(a, E);Q | if (C) {SQ} KZQ |  while (C)  {SQ}Q | λ
		A, // → aH = E; | read(aH); |  write(E); | new(a, E); | if (C) {SQ} KZ | while (C) {SQ}
		I, // → aM
		M, // → ,aM | ;
		H, // → [E] | λ
		C, // → (E)VUL | aHVUL | kVUL | +GVUL | -GVUL
		L, // → <EZ | >EZ | == EZ | ≤EZ | ≥EZ | !=EZ
		K, // → else {SQ} | λ
		E, // → (E)VU | aHVU | +GVU | -GVU
		U, // → +TU | -TU | λ
		T, // → (E)V | aHV | kV | +GV | -GV
		V, // → *FV | /FV | λ
		F, // → +G | -GZ | (E) | aH | k
		G, // → (E) | aH | k
		Z, // → λ
		Error // ошибочное состояние
	};
	//Все возможные действия (задания) генератора
	enum class GeneratorTask
	{
		Empty,
		VariableId,
		IntNumber,
		Read,
		Write,
		Plus,
		Minus,
		UnarMinus,
		Multiply,
		Divide,
		Less,
		Assign,
		Memory,
		More,
		Equal,
		LessOrEqual,
		MoreOrEqual,
		NotEqual,
		Index,
		Task1,
		Task2,
		Task3,
		Task4,
		Task5,
		Task6,
		Task7,
		Task8,
		Task9,
		Task10,
		Task11,
	};
	//Структура описывающая элемент магазина
	struct MagazineItem
	{
		bool is_lexeme;
		lexemeType lexeme;
		Nonterminal nonterminal;
		//Эл-т магазина - лексема
		MagazineItem(lexemeType l) {
			is_lexeme = true;
			lexeme = l;
			nonterminal = Nonterminal::Error;
		}
		//Эл-т магазина - не лексема
		MagazineItem(Nonterminal s) {
			is_lexeme = false;
			lexeme = lexemeType::Error;
			nonterminal = s;
		}
	};

	//Создание экземпляров
	GeneratorTask current_task; //Выбранное действие генератора
	lexeme current_lexeme; //Выбранныя лекмсема
	Nonterminal current_nonterminal; //Нетерминал
	table current_table; //Выбранная таблица (переменных / массивов)
	string last_array_name; //Последнее имя массива
	stack<MagazineItem> magazine; //Магазин нетерминалов
	stack<GeneratorTask> generator; //Генератор
	stack<int> marks; //Стэк меок для действий генератора
	InterpretData data; //Возвращаемые данные
	vector<lexeme> input_data; //Вводимый вектор лексем
};

//Распознование не терминалов по средствам перехода по кейсам и последовательного разбора не терминала с помощью emplace
//Эмитация всех возможных переходов по таблице с помощью типов лексем
void Generator::RecognizeNonterminal() {
    switch (current_nonterminal)
    {
    case Nonterminal::S:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::VarName:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::Assign);
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Assign);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            break;
        }
        case lexemeType::IntType:
        {
            magazine.emplace(Nonterminal::S);
            magazine.emplace(Nonterminal::I);
            magazine.emplace(lexemeType::IntType);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task6);
            break;
        }
        case lexemeType::ArrayType:
        {
            magazine.emplace(Nonterminal::S);
            magazine.emplace(Nonterminal::I);
            magazine.emplace(lexemeType::ArrayType);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task7);
            break;
        }
        case lexemeType::If:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::K);
            magazine.emplace(lexemeType::RightBrace);
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(Nonterminal::S);
            magazine.emplace(lexemeType::LeftBrace);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::C);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::If);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task3);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task1);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::While:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::RightBrace);
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(Nonterminal::S);
            magazine.emplace(lexemeType::LeftBrace);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::C);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::While);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task5);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task1);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task4);
            break;
        }
        case lexemeType::Read:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::Read);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Read);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Write:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::Write);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Write);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Allocate:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::Comma);
            magazine.emplace(lexemeType::VarName);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::Allocate);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Memory); // буква m
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            //Ошибка если не нашлось нужного перехода по таблице
            string msg = "Generator error - Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::Q:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::VarName:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::Assign);
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Assign);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            break;
        }
        case lexemeType::If:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::K);
            magazine.emplace(lexemeType::RightBrace);
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(Nonterminal::S);
            magazine.emplace(lexemeType::LeftBrace);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::C);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::If);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task3);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task1);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::While:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::RightBrace);
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(Nonterminal::S);
            magazine.emplace(lexemeType::LeftBrace);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::C);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::While);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task5);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task1);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task4);
            break;
        }
        case lexemeType::Read:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::Read);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Read);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Write:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::Write);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Write);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Allocate:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::Comma);
            magazine.emplace(lexemeType::VarName);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::Allocate);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Memory); // буква m
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }
    case Nonterminal::A:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::VarName:
        {
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::Assign);
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);

            generator.emplace(GeneratorTask::Assign);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            break;
        }
        case lexemeType::If:
        {
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::K);
            magazine.emplace(lexemeType::RightBrace);
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(Nonterminal::S);
            magazine.emplace(lexemeType::LeftBrace);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::C);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::If);

            generator.emplace(GeneratorTask::Task3);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task1);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::While:
        {
            magazine.emplace(lexemeType::RightBrace);
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(Nonterminal::S);
            magazine.emplace(lexemeType::LeftBrace);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::C);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::While);

            generator.emplace(GeneratorTask::Task5);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task1);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task4);
            break;
        }
        case lexemeType::Read:
        {
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::Read);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Read);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Write:
        {
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::Write);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Write);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Allocate:
        {
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::Comma);
            magazine.emplace(lexemeType::VarName);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::Allocate);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Memory); // буква m
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            //Ошибка если не нашлось нужного перехода по таблице
            string msg = "Generator error - Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::I:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::VarName:
        {
            magazine.emplace(Nonterminal::M);
            magazine.emplace(lexemeType::VarName);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task8);
            break;
        }
        default:
        {
            //Ошибка если не нашлось нужного перехода по таблице
            string msg = "Generator error - Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::M:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::Semicolon:
        {
            magazine.emplace(lexemeType::Semicolon);

            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Comma:
        {
            magazine.emplace(Nonterminal::M);
            magazine.emplace(lexemeType::VarName);
            magazine.emplace(lexemeType::Comma);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task8);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            //Ошибка если не нашлось нужного перехода по таблице
            string msg = "Generator error - Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::H:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::LeftSquareBracket:
        {
            magazine.emplace(lexemeType::RightSquareBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LeftSquareBracket);

            generator.emplace(GeneratorTask::Index);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }
    case Nonterminal::C:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::VarName:
        {
            magazine.emplace(Nonterminal::L);
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            break;
        }
        case lexemeType::IntNum:
        {
            magazine.emplace(Nonterminal::L);
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(lexemeType::IntNum);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::IntNumber);
            break;
        }
        case lexemeType::LeftRoundBracket:
        {
            magazine.emplace(Nonterminal::L);
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LeftRoundBracket);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Plus:
        {
            magazine.emplace(Nonterminal::L);
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::G);
            magazine.emplace(lexemeType::Plus);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Minus:
        {
            magazine.emplace(Nonterminal::L);
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::G);
            magazine.emplace(lexemeType::Minus);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::UnarMinus);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            //Ошибка если не нашлось нужного перехода по таблице
            string msg = "Generator error - Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::L:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::Less:
        {
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::Less);

            generator.emplace(GeneratorTask::Less);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::More:
        {
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::More);

            generator.emplace(GeneratorTask::More);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Equal:
        {
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::Equal);

            generator.emplace(GeneratorTask::Equal);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::LessOrEqual:
        {
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LessOrEqual);

            generator.emplace(GeneratorTask::LessOrEqual);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::MoreOrEqual:
        {
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::MoreOrEqual);

            generator.emplace(GeneratorTask::MoreOrEqual);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::NotEqual:
        {
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::NotEqual);

            generator.emplace(GeneratorTask::NotEqual);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            //Ошибка если не нашлось нужного перехода по таблице
            string msg = "Generator error - Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::K:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::Else:
        {
            magazine.emplace(lexemeType::RightBrace);
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(Nonterminal::S);
            magazine.emplace(lexemeType::LeftBrace);
            magazine.emplace(lexemeType::Else);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task2);
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }
    case Nonterminal::E:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::VarName:
        {
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            break;
        }
        case lexemeType::IntNum:
        {
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(lexemeType::IntNum);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::IntNumber);
            break;
        }
        case lexemeType::LeftRoundBracket:
        {
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LeftRoundBracket);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Plus:
        {
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::G);
            magazine.emplace(lexemeType::Plus);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Minus:
        {
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::G);
            magazine.emplace(lexemeType::Minus);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::UnarMinus);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            //Ошибка если не нашлось нужного перехода по таблице
            string msg = "Generator error - Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::U:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::Plus:
        {
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::T);
            magazine.emplace(lexemeType::Plus);

            generator.emplace(GeneratorTask::Plus);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Minus:
        {
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::T);
            magazine.emplace(lexemeType::Minus);

            generator.emplace(GeneratorTask::Minus);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }
    case Nonterminal::T:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::VarName:
        {
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            break;
        }
        case lexemeType::IntNum:
        {
            magazine.emplace(Nonterminal::V);
            magazine.emplace(lexemeType::IntNum);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::IntNumber);
            break;
        }
        case lexemeType::LeftRoundBracket:
        {
            magazine.emplace(Nonterminal::V);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LeftRoundBracket);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Plus:
        {
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::G);
            magazine.emplace(lexemeType::Plus);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Minus:
        {
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::G);
            magazine.emplace(lexemeType::Minus);

            generator.emplace(GeneratorTask::UnarMinus);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            //Ошибка если не нашлось нужного перехода по таблице
            string msg = "Generator error - Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::V:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::Multiply:
        {
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::F);
            magazine.emplace(lexemeType::Multiply);

            generator.emplace(GeneratorTask::Multiply);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Divide:
        {
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::F);
            magazine.emplace(lexemeType::Divide);

            generator.emplace(GeneratorTask::Divide);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }
    case Nonterminal::F:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::VarName:
        {
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            break;
        }
        case lexemeType::IntNum:
        {
            magazine.emplace(lexemeType::IntNum);

            generator.emplace(GeneratorTask::IntNumber);
            break;
        }
        case lexemeType::LeftRoundBracket:
        {
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LeftRoundBracket);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Plus:
        {
            magazine.emplace(Nonterminal::G);
            magazine.emplace(lexemeType::Plus);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Minus:
        {
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::G);
            magazine.emplace(lexemeType::Minus);

            generator.emplace(GeneratorTask::UnarMinus);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            //Ошибка если не нашлось нужного перехода по таблице
            string msg = "Generator error - Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::G:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::VarName:
        {
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            break;
        }
        case lexemeType::IntNum:
        {
            magazine.emplace(lexemeType::IntNum);

            generator.emplace(GeneratorTask::IntNumber);
            break;
        }
        case lexemeType::LeftRoundBracket:
        {
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LeftRoundBracket);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            //Ошибка если не нашлось нужного перехода по таблице
            string msg = "Generator error - Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::Z:
    {
        break;
    }
    case Nonterminal::Error:
    default:
        //Ошибка если в конце получили ошибочное состояние
        string msg = "Generator error - Error or unknown state;";
        throw InterpretException(msg, current_lexeme.info);
    }
}
//Выполнение действий
void Generator::DoTask() {
    switch (current_task)
    {
        //Ничего
    case GeneratorTask::Empty:
        break;
        //Добавление в ОПС названия и типа переменной или массива
    case GeneratorTask::VariableId:
    {
        string name = current_lexeme.value;
        if (data.int_table.count(name) ||
            data.massInt_table.count(name))
        {
            data.ops.emplace_back(name, OpsItemType::IntVariable, current_lexeme.info); //Добаляем в ОПС
        }
        else
        {
            string msg = "Generator error - Unknown variable name = '" + name + "';";
            throw InterpretException(msg, current_lexeme.info);
        }

        break;
    }
    //Добавление в ОПС значение переменной
    case GeneratorTask::IntNumber:
    {
        int num = stoi(current_lexeme.value); //Преобразование типа (str -> int)
        data.ops.emplace_back(num, current_lexeme.info); //Добавляем в ОПС
        break;
    }
    //Добавление в ОПС различных операций
    case GeneratorTask::Read:
        data.ops.emplace_back(OpsItemOperation::Read, current_lexeme.info);
        break;
    case GeneratorTask::Write:
        data.ops.emplace_back(OpsItemOperation::Write, current_lexeme.info);
        break;
    case GeneratorTask::Plus:
        data.ops.emplace_back(OpsItemOperation::Plus, current_lexeme.info);
        break;
    case GeneratorTask::Minus:
        data.ops.emplace_back(OpsItemOperation::Minus, current_lexeme.info);
        break;
    case GeneratorTask::UnarMinus:
        data.ops.emplace_back(OpsItemOperation::UnarMinus, current_lexeme.info);
        break;
    case GeneratorTask::Multiply:
        data.ops.emplace_back(OpsItemOperation::Miltiply, current_lexeme.info);
        break;
    case GeneratorTask::Divide:
        data.ops.emplace_back(OpsItemOperation::Divide, current_lexeme.info);
        break;
    case GeneratorTask::Less:
        data.ops.emplace_back(OpsItemOperation::Less, current_lexeme.info);
        break;
    case GeneratorTask::Assign:
        data.ops.emplace_back(OpsItemOperation::Assign, current_lexeme.info);
        break;
    case GeneratorTask::More:
        data.ops.emplace_back(OpsItemOperation::More, current_lexeme.info);
        break;
    case GeneratorTask::Equal:
        data.ops.emplace_back(OpsItemOperation::Equal, current_lexeme.info);
        break;
    case GeneratorTask::LessOrEqual:
        data.ops.emplace_back(OpsItemOperation::LessOrEqual, current_lexeme.info);
        break;
    case GeneratorTask::MoreOrEqual:
        data.ops.emplace_back(OpsItemOperation::MoreOrEqual, current_lexeme.info);
        break;
    case GeneratorTask::NotEqual:
        data.ops.emplace_back(OpsItemOperation::NotEqual, current_lexeme.info);
        break;
    case GeneratorTask::Index:
        data.ops.emplace_back(OpsItemOperation::Index, current_lexeme.info);
        break;
        //Переход если лож
    case GeneratorTask::Task1:
    {
        marks.push(data.ops.size());
        data.ops.emplace_back(0, current_lexeme.info);
        data.ops.emplace_back(OpsItemOperation::JumpIfFalse, current_lexeme.info);
        break;
    }
    //Переход
    case GeneratorTask::Task2:
    {
        int place = marks.top(); marks.pop();
        marks.push(data.ops.size());
        data.ops.emplace_back(0, current_lexeme.info);
        data.ops.emplace_back(OpsItemOperation::Jump, current_lexeme.info);
        data.ops[place].int_num = data.ops.size();
        break;
    }
    // ??
    case GeneratorTask::Task3:
    {
        int place = marks.top(); marks.pop();
        data.ops[place].int_num = data.ops.size();
        break;
    }
    // ??
    case GeneratorTask::Task4:
    {
        marks.push(data.ops.size());
        break;
    }
    // ??
    case GeneratorTask::Task5:
    {
        int place = marks.top(); marks.pop();
        data.ops.emplace_back(marks.top(), current_lexeme.info); marks.pop();
        data.ops.emplace_back(OpsItemOperation::Jump, current_lexeme.info);
        data.ops[place].int_num = data.ops.size();
        break;
    }
    //Выборка числа
    case GeneratorTask::Task6:
    {
        current_table = table::Int;
        break;
    }
    //Выборка массива
    case GeneratorTask::Task7:
    {
        current_table = table::MassInt;
        break;
    }
    //Обработка переменной или массива (внесение)
    case GeneratorTask::Task8:
    {
        string name = current_lexeme.value;

        if (data.int_table.count(name) ||
            data.massInt_table.count(name)) {
            string msg = "Generator error - Redefine a variable name = '" + name + "';";
            throw InterpretException(msg, current_lexeme.info);
        }
        //Переменная
        if (current_table == table::Int) {
            data.int_table.insert({ name, 0 });
        }
        //Массив
        else if (current_table == table::MassInt) {
            data.massInt_table.insert({ name, vector<int>(0) });
        }

        break;
    }
    //Память ??
    case GeneratorTask::Memory:
    {
        data.ops.emplace_back(OpsItemOperation::Memory, current_lexeme.info);
        break;
    }
    //Если не подошел ни один кейс - ошибка
    default: {
        string msg = "Generator error - Unknown generator task;";
        throw InterpretException(msg, current_lexeme.info);
    }
    }
}
//Работа генератора ОПС
void Generator::Run() {
    magazine.emplace(Nonterminal::S); //Изначально в магазине хранится S
    generator.push(GeneratorTask::Empty); //Изначально задания для генератора отсутствуют

    int current_lexeme_idx = 0; //Начинаем с первой лексемы
    current_lexeme = input_data[current_lexeme_idx]; //Берем эту лексему
    //Цикл работы генератора пока генератор и магазин полностью не опустеют
    while (!generator.empty() && !magazine.empty())
    {
        // Берем верхний эл-т из стека магазина (и удаляем его от туда)
        MagazineItem current_magazine_item = magazine.top(); magazine.pop();
        current_nonterminal = current_magazine_item.nonterminal;
        // Берем верхний эл-т из стека заданий (и удаляем его от туда)
        current_task = generator.top(); generator.pop();

        DoTask();
        //Если мы получили лексему:
        if (current_magazine_item.is_lexeme) {
            //Не выполнили ли мы все?
            if (current_lexeme.lexeme_type == lexemeType::Finish) {
                string msg = "Generator error - All lexemes are read, but magazine is not empty;";
                throw InterpretException(msg, current_lexeme.info);
            }
            //Передвижения индекса для последущих переводов в ОПС, если мы получили готовую лексему,
            // с которой ничего не нужно делать
            if (current_magazine_item.lexeme == current_lexeme.lexeme_type) {
                current_lexeme_idx++;
                current_lexeme = input_data[current_lexeme_idx];
            }
            //Ошибка в ином случае
            else {
                string msg = "Generator error - Unexpected lexeme;";
                throw InterpretException(msg, current_lexeme.info);
            }
        }
        //Если из магазина мы получили не лексему - распонаем не терминал
        else {
            RecognizeNonterminal();
        }
    }
    //Ошибка, если остались нераспознанные лексемы
    if (current_lexeme.lexeme_type != lexemeType::Finish) {
        string msg = "Generator error - There are unrecognized lexemes;";
        throw InterpretException(msg, current_lexeme.info);
    }
}
//Гетер итоговых данных
InterpretData Generator::GetData() {
    return data;
}
//Сеттер лексем в виде входных данных
Generator::Generator(vector<lexeme> lexemes) {
    input_data = lexemes;
}


