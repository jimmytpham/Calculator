#pragma once
#include "Basic.h"
#include "Scientific.h"

/* Jimmy Pham
*  T00629354
*  COMP 3141
*  Final Project
*/

namespace Calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Calculator : public System::Windows::Forms::Form
	{
	public:
		//Constructor
		Calculator(void);
		//Calculate result function
		int calculateResult();


	protected:
		//Destructor
		~Calculator();

	private: 
		//Basic Calculator buttons
		System::Windows::Forms::Label^ resultBox;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::Button^ button4;
		System::Windows::Forms::Button^ button5;
		System::Windows::Forms::Button^ button6;
		System::Windows::Forms::Button^ button7;
		System::Windows::Forms::Button^ button8;
		System::Windows::Forms::Button^ button9;
		System::Windows::Forms::Button^ button0;
		System::Windows::Forms::Button^ decimalButton;
		System::Windows::Forms::Button^ addButton;
		System::Windows::Forms::Button^ subtractButton;
		System::Windows::Forms::Button^ multiplyButton;
		System::Windows::Forms::Button^ divideButton;
		System::Windows::Forms::Button^ resultButton;
		System::Windows::Forms::Button^ clearButton;
		System::Windows::Forms::Button^ deleteButton;
		System::Windows::Forms::Button^ squareRootButton;
		System::Windows::Forms::Button^ squaredButton;
		System::Windows::Forms::Button^ scientificButton;

	private:
		bool isScientificMode; //start as a basic calculator
		double currentResult;  
		String^ currentOperator; 
		double firstNum;
		double secondNum;
		double result;
		double memoryNumber;

	private: System::Windows::Forms::Label^ inputBox;

		   char operation;


	private:
		//Button click functions
		System::Void btnNumber_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void decimalButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void subtractButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void multiplyButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void divideButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void clearButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void squareRootButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void squaredButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void resultButton_Click(System::Object^ sender, System::EventArgs^ e);

	protected:
		//Scientific Calculator button click functions
		System::Void scientificButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void openButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void closeButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void mcButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void mrButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void msButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void sinButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void cosButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void tanButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void logButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void lnButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void factorialButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void posNegButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void powerButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void cubedButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void piButton_Click(System::Object^ sender, System::EventArgs^ e);


	private:
		//scientific calulator buttons
		System::Windows::Forms::Button^ openButton; 
		System::Windows::Forms::Button^ closeButton; 
		System::Windows::Forms::Button^ mcButton;
		System::Windows::Forms::Button^ mrButton;
		System::Windows::Forms::Button^ msButton;
		System::Windows::Forms::Button^ sinButton;
		System::Windows::Forms::Button^ cosButton;
		System::Windows::Forms::Button^ tanButton;
		System::Windows::Forms::Button^ logButton;
		System::Windows::Forms::Button^ lnButton;
		System::Windows::Forms::Button^ factorialButton;
		System::Windows::Forms::Button^ posNegButton; 
		System::Windows::Forms::Button^ powerButton;
		System::Windows::Forms::Button^ cubedButton;
		System::Windows::Forms::Button^ piButton;


	private:

		Basic^ basicCalculator;
		Scientific^ scientificCalculator; 

		//UI for basic and scientific calculators
		void InitializeBasicCalculatorUI(); 
		void InitializeScientificCalculatorUI(); 


	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		//Layout
		void InitializeComponent(void)
		{
			this->resultBox = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button0 = (gcnew System::Windows::Forms::Button());
			this->decimalButton = (gcnew System::Windows::Forms::Button());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->subtractButton = (gcnew System::Windows::Forms::Button());
			this->multiplyButton = (gcnew System::Windows::Forms::Button());
			this->divideButton = (gcnew System::Windows::Forms::Button());
			this->resultButton = (gcnew System::Windows::Forms::Button());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->squareRootButton = (gcnew System::Windows::Forms::Button());
			this->squaredButton = (gcnew System::Windows::Forms::Button());
			this->scientificButton = (gcnew System::Windows::Forms::Button());
			this->inputBox = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// resultBox
			// 
			this->resultBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->resultBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.875F));
			this->resultBox->Location = System::Drawing::Point(21, 40);
			this->resultBox->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->resultBox->Name = L"resultBox";
			this->resultBox->Size = System::Drawing::Size(253, 40);
			this->resultBox->TabIndex = 0;
			this->resultBox->Text = L"0";
			this->resultBox->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(21, 318);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(46, 41);
			this->button1->TabIndex = 1;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(86, 318);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(46, 41);
			this->button2->TabIndex = 2;
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(158, 318);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(46, 41);
			this->button3->TabIndex = 3;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(21, 260);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(46, 41);
			this->button4->TabIndex = 4;
			this->button4->Text = L"4";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(86, 260);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(46, 41);
			this->button5->TabIndex = 5;
			this->button5->Text = L"5";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(158, 260);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(46, 41);
			this->button6->TabIndex = 6;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(21, 198);
			this->button7->Margin = System::Windows::Forms::Padding(2);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(46, 41);
			this->button7->TabIndex = 7;
			this->button7->Text = L"7";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(86, 198);
			this->button8->Margin = System::Windows::Forms::Padding(2);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(46, 41);
			this->button8->TabIndex = 8;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(158, 198);
			this->button9->Margin = System::Windows::Forms::Padding(2);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(46, 41);
			this->button9->TabIndex = 9;
			this->button9->Text = L"9";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button0
			// 
			this->button0->Location = System::Drawing::Point(21, 377);
			this->button0->Margin = System::Windows::Forms::Padding(2);
			this->button0->Name = L"button0";
			this->button0->Size = System::Drawing::Size(46, 41);
			this->button0->TabIndex = 10;
			this->button0->Text = L"0";
			this->button0->UseVisualStyleBackColor = true;
			// 
			// decimalButton
			// 
			this->decimalButton->Location = System::Drawing::Point(86, 377);
			this->decimalButton->Margin = System::Windows::Forms::Padding(2);
			this->decimalButton->Name = L"decimalButton";
			this->decimalButton->Size = System::Drawing::Size(46, 41);
			this->decimalButton->TabIndex = 11;
			this->decimalButton->Text = L".";
			this->decimalButton->UseVisualStyleBackColor = true;
			// 
			// addButton
			// 
			this->addButton->Location = System::Drawing::Point(158, 377);
			this->addButton->Margin = System::Windows::Forms::Padding(2);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(46, 41);
			this->addButton->TabIndex = 12;
			this->addButton->Text = L"+";
			this->addButton->UseVisualStyleBackColor = true;
			// 
			// subtractButton
			// 
			this->subtractButton->Location = System::Drawing::Point(226, 291);
			this->subtractButton->Margin = System::Windows::Forms::Padding(2);
			this->subtractButton->Name = L"subtractButton";
			this->subtractButton->Size = System::Drawing::Size(46, 24);
			this->subtractButton->TabIndex = 13;
			this->subtractButton->Text = L"-";
			this->subtractButton->UseVisualStyleBackColor = true;
			// 
			// multiplyButton
			// 
			this->multiplyButton->Location = System::Drawing::Point(226, 250);
			this->multiplyButton->Margin = System::Windows::Forms::Padding(2);
			this->multiplyButton->Name = L"multiplyButton";
			this->multiplyButton->Size = System::Drawing::Size(46, 25);
			this->multiplyButton->TabIndex = 14;
			this->multiplyButton->Text = L"x";
			this->multiplyButton->UseVisualStyleBackColor = true;
			// 
			// divideButton
			// 
			this->divideButton->Location = System::Drawing::Point(226, 198);
			this->divideButton->Margin = System::Windows::Forms::Padding(2);
			this->divideButton->Name = L"divideButton";
			this->divideButton->Size = System::Drawing::Size(46, 34);
			this->divideButton->TabIndex = 15;
			this->divideButton->Text = L"÷";
			this->divideButton->UseVisualStyleBackColor = true;
			// 
			// resultButton
			// 
			this->resultButton->Location = System::Drawing::Point(226, 332);
			this->resultButton->Margin = System::Windows::Forms::Padding(2);
			this->resultButton->Name = L"resultButton";
			this->resultButton->Size = System::Drawing::Size(46, 86);
			this->resultButton->TabIndex = 16;
			this->resultButton->Text = L"=";
			this->resultButton->UseVisualStyleBackColor = true;
			// 
			// clearButton
			// 
			this->clearButton->Location = System::Drawing::Point(21, 142);
			this->clearButton->Margin = System::Windows::Forms::Padding(2);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(46, 41);
			this->clearButton->TabIndex = 17;
			this->clearButton->Text = L"C";
			this->clearButton->UseVisualStyleBackColor = true;
			// 
			// deleteButton
			// 
			this->deleteButton->Location = System::Drawing::Point(226, 142);
			this->deleteButton->Margin = System::Windows::Forms::Padding(2);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(46, 41);
			this->deleteButton->TabIndex = 18;
			this->deleteButton->Text = L"DEL";
			this->deleteButton->UseVisualStyleBackColor = true;
			// 
			// squareRootButton
			// 
			this->squareRootButton->Location = System::Drawing::Point(86, 142);
			this->squareRootButton->Margin = System::Windows::Forms::Padding(2);
			this->squareRootButton->Name = L"squareRootButton";
			this->squareRootButton->Size = System::Drawing::Size(46, 41);
			this->squareRootButton->TabIndex = 19;
			this->squareRootButton->Text = L"√";
			this->squareRootButton->UseVisualStyleBackColor = true;
			// 
			// squaredButton
			// 
			this->squaredButton->Location = System::Drawing::Point(158, 142);
			this->squaredButton->Margin = System::Windows::Forms::Padding(2);
			this->squaredButton->Name = L"squaredButton";
			this->squaredButton->Size = System::Drawing::Size(46, 41);
			this->squaredButton->TabIndex = 20;
			this->squaredButton->Text = L"^2";
			this->squaredButton->UseVisualStyleBackColor = true;
			// 
			// scientificButton
			// 
			this->scientificButton->Location = System::Drawing::Point(21, 11);
			this->scientificButton->Margin = System::Windows::Forms::Padding(2);
			this->scientificButton->Name = L"scientificButton";
			this->scientificButton->Size = System::Drawing::Size(78, 23);
			this->scientificButton->TabIndex = 21;
			this->scientificButton->Text = L"Scientific";
			this->scientificButton->UseVisualStyleBackColor = true;
			// 
			// inputBox
			// 
			this->inputBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->inputBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.875F));
			this->inputBox->Location = System::Drawing::Point(21, 90);
			this->inputBox->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(253, 40);
			this->inputBox->TabIndex = 22;
			this->inputBox->Text = L"0";
			this->inputBox->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// Calculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(304, 435);
			this->Controls->Add(this->inputBox);
			this->Controls->Add(this->scientificButton);
			this->Controls->Add(this->squaredButton);
			this->Controls->Add(this->squareRootButton);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->clearButton);
			this->Controls->Add(this->resultButton);
			this->Controls->Add(this->divideButton);
			this->Controls->Add(this->multiplyButton);
			this->Controls->Add(this->subtractButton);
			this->Controls->Add(this->addButton);
			this->Controls->Add(this->decimalButton);
			this->Controls->Add(this->button0);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->resultBox);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Calculator";
			this->Text = L"Calculator";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
