#include <iostream>
#include <cstdlib>

// Libraries For Create Specific Delay In The Plase That You Call It.
#include <chrono>
#include <thread>

// Using Namespaces For Make Code Write Easier.
using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until.
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

// My Created Functions From Scratch.

enum enType {SamallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4};

enum enOpType  {Add = 43, Sub = 45, Mul = 42, Div = 47, OpMix = 5};

enum enQuestionsLevelType {Easy = 1, Medium = 2, Hard = 3, QlMix = 4};

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;

	return RandNumber;
}

int ReadPositiveNumber(string Message)
{
    int Number = 0;  
    do
    {
        cout << Message; 
        cin >> Number;   

    } while (Number <= 0 && Number <= 100);  

    return Number;
}

char RandomOpt()
{
	int Number = RandomNumber(1, 4);
	switch (Number)
	{
	case 1:
		return char(enOpType::Add);
		break;
	case 2:
		return char(enOpType::Sub);
		break;
	case 3:
		return char(enOpType::Mul);
		break;
	case 4:
		return char(enOpType::Div);
	}
}

int QuestionsNumber()
{
	int QuestionsNumber = ReadPositiveNumber("Hello Human, How Many Questions Do You Want To Test Your Skills? : ");
	return QuestionsNumber;
}

int QuestionLevelNumber()
{
	int QuestionLevelNumber = ReadPositiveNumber("Now Enter Question Level [1] Easy, [2] Medium, [3] Hard, [4] Mix : ");
	return QuestionLevelNumber;
}

int OperationNumber()
{
	int OperationNumber = ReadPositiveNumber("Now Enter Operation Type [1] Add, [2] Sub [3] Mul [4] Div [5] Mix : ");
	return OperationNumber;
}

enQuestionsLevelType QuestionLeve(int Number)
{
	switch(Number)
	{
	case 1:
		return enQuestionsLevelType::Easy;
		break;
	case 2:
		return enQuestionsLevelType::Medium;
		break;
	case 3:
		return enQuestionsLevelType::Hard;
		break;
	case 4:
		return enQuestionsLevelType::QlMix;
		break;
	}
}

enOpType OperationType(int Number)
{
	switch(Number)
	{
	case 1:
		return enOpType::Add;
		break;
	case 2:
		return enOpType::Sub;
		break;
	case 3:
		return enOpType::Mul;
		break;
	case 4:
		return enOpType::Div;
		break;
	case 5:
		return enOpType::OpMix;
		break;
	}
}

int GenerateQuestionLeve(enQuestionsLevelType Ql)
{
	switch(Ql)
	{
	case enQuestionsLevelType::Easy:
		return RandomNumber(1, 10);
		break;
	case enQuestionsLevelType::Medium:
		return RandomNumber(10, 20);
		break;
	case enQuestionsLevelType::Hard:
		return RandomNumber(20, 50);
		break;
	case enQuestionsLevelType::QlMix:
		return RandomNumber(1, 50);
		break;
	}
}

string GetLevelType(enQuestionsLevelType Ql)
{
	switch(Ql)
	{
	case enQuestionsLevelType::Easy:
		return "Easy";
		break;
	case enQuestionsLevelType::Medium:
		return "Medium";
		break;
	case enQuestionsLevelType::Hard:
		return "Hard";
		break;
	case enQuestionsLevelType::QlMix:
		return "Mix";
		break;
	}
}

string GetOpType(enOpType Op)
{
	switch(Op)
	{
	case enOpType::Add:
		return "Addition";
		break;
	case enOpType::Sub:
		return "Subtract";
		break;
	case enOpType::Mul:
		return "Multiplication";
		break;
	case enOpType::Div:
		return "Division";
		break;
	case enOpType::OpMix:
		return "Mix";
		break;
	}
}

char GenerateOpType(enOpType Op)
{
	switch(Op)
	{
	case enOpType::Add:
		return '+';
		break;
	case enOpType::Sub:
		return '-';
		break;
	case enOpType::Mul:
		return '*';
		break;
	case enOpType::Div:
		return '/';
		break;
	case enOpType::OpMix:
		return RandomOpt();
		break;
	}
}

float ClaculateNumbers(float Number1, float Number2, int OpType)
{
	switch(OpType)
	{
	case '+':
		return Number1 + Number2;
		break;
	case '-':
		return Number1 - Number2;
		break;
	case '*':
		return Number1 * Number2;
		break;
	case '/':
		return Number1 / Number2;
		break;
	}
}

void CheckFinalReslut(int NumberOfRightQuestions, int NumberOfFalseQuestions)
{
	if (NumberOfRightQuestions > NumberOfFalseQuestions)
	{
		system("color 27");
		cout << "Final Reslut Is [ ++ PASS!!! ++ ]" << endl;\

	}
	else if (NumberOfRightQuestions < NumberOfFalseQuestions)
	{
		cout << "\a";
		system("color 47");
		cout << "Final Reslut Is [ ++ FAIL :( ++ ]" << endl;
	}
	else
	{
		system("color 67");
		cout << "Final Reslut Is [ ++ DRAW ++ ]" << endl;
	}
}

void Statistics(int& NumberOfQuestions, enQuestionsLevelType questionsLevel, enOpType OpType, int& NumberOfRightQuestions, int& NumberOfFalseQuestions)
{
	cout << "----------------------------------------" << endl;
	CheckFinalReslut(NumberOfRightQuestions, NumberOfFalseQuestions);
	cout << "----------------------------------------" << endl;
	cout << "Number Of Questions: " << NumberOfQuestions << endl;
	cout << "Questions Level    : " << GetLevelType(questionsLevel) << endl;
	cout << "Operation Type     : " << GetOpType(OpType) << endl;
	cout << "Number Of Right Questions: " << NumberOfRightQuestions << endl;
	cout << "Number Of False Questions: " << NumberOfFalseQuestions << endl;
	cout << "----------------------------------------" << endl << endl;
	
}

void PlayMathGame()
{
	int Counter = 0;
	int QuesiontsNumber = QuestionsNumber();
	int QuestionLevelNum = QuestionLevelNumber();
	enOpType enOpType = OperationType(OperationNumber());
	int NumberOfRightQuestions = 0;
	int NumberOfFalseQuestions = 0;

	do
	{
		cout << "\nQuestion Number [" << Counter + 1 << "/" << QuesiontsNumber << "]" << endl << endl;

		float Number1 = GenerateQuestionLeve(QuestionLeve(QuestionLevelNum));
		float Number2 = GenerateQuestionLeve(QuestionLeve(QuestionLevelNum));
		
		char OpType = GenerateOpType(enOpType);
		cout << Number1 << endl << Number2 << " " << OpType << endl << "-----------------" << endl;
		float CorrectAnswer = ClaculateNumbers(Number1, Number2, OpType);

		float Answer;
		cin >> Answer;

		if(Answer == CorrectAnswer)
		{
			system("color 27");
			cout << "Correct Answer :)" << endl << endl;
			NumberOfRightQuestions++;
		}
		else
		{
			cout << "\a";
			system("color 47");
			cout << "Wrong Answer :(" << endl;
			cout << "The Correct Answer Is: " << CorrectAnswer << endl << endl << endl;
			NumberOfFalseQuestions++;
		}

		Counter++;
	} while (Counter < QuesiontsNumber);
	
	sleep_for(1s);
    sleep_until(system_clock::now() + 1s);
	cout << "\nWhait For Final Result........." << endl;
	sleep_for(3s);
    sleep_until(system_clock::now() + 1s);
	Statistics(QuesiontsNumber, QuestionLeve(QuestionLevelNum), enOpType, NumberOfRightQuestions, NumberOfFalseQuestions);
}

char DoYouWantToPlayAgain()
{
	char DoYouWantToPlayAgain;
	cout << "\nHuman Do You Want To Play Again? ([Y,y] For Yes, [N,n] For No) : ";
	cin >> DoYouWantToPlayAgain;
	return DoYouWantToPlayAgain;
}

void ResetTheGame()
{
	char Again = DoYouWantToPlayAgain();

	while (Again == 'Y' || Again == 'y')
	{
		system("cls");
		system("color 07");
		PlayMathGame();
		Again = DoYouWantToPlayAgain();
	}
	cout << "\nOk Human See You Again, Stay Safe :)" << endl;
}

void StartMathGame()
{
	PlayMathGame();
	ResetTheGame();
}

// End Of My Functions.


// Main Function From C++ Language That Program Start From It.
int main()
{
	// Seed the random number generator with the current time.
	srand((unsigned)time(NULL));

	// Call The Program To Start.
	StartMathGame();
	
	return 0;
}

