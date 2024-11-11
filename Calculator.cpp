#include "Calculator.h"
#include "Scientific.h"
#include "Basic.h"

/* Jimmy Pham
*  T00629354
*  COMP 3141
*  Final Project
*/

using namespace System::Data;

namespace Calculator {

	Calculator::Calculator(void)
	{
		InitializeComponent();

		//initial input
		currentResult = 0.0;
		currentOperator = "";

		isScientificMode = false; // starts the program as basic calculator

		//Initiate instances of calculators
		basicCalculator = gcnew Basic();
		scientificCalculator = gcnew Scientific();

		InitializeBasicCalculatorUI();
		InitializeScientificCalculatorUI();

		//button click functions
		button1->Click += gcnew System::EventHandler(this, &Calculator::btnNumber_Click);
		button2->Click += gcnew System::EventHandler(this, &Calculator::btnNumber_Click);
		button3->Click += gcnew System::EventHandler(this, &Calculator::btnNumber_Click);
		button4->Click += gcnew System::EventHandler(this, &Calculator::btnNumber_Click);
		button5->Click += gcnew System::EventHandler(this, &Calculator::btnNumber_Click);
		button6->Click += gcnew System::EventHandler(this, &Calculator::btnNumber_Click);
		button7->Click += gcnew System::EventHandler(this, &Calculator::btnNumber_Click);
		button8->Click += gcnew System::EventHandler(this, &Calculator::btnNumber_Click);
		button9->Click += gcnew System::EventHandler(this, &Calculator::btnNumber_Click);
		button0->Click += gcnew System::EventHandler(this, &Calculator::btnNumber_Click);
		decimalButton->Click += gcnew System::EventHandler(this, &Calculator::decimalButton_Click);
		addButton->Click += gcnew System::EventHandler(this, &Calculator::addButton_Click);
		subtractButton->Click += gcnew System::EventHandler(this, &Calculator::subtractButton_Click);
		multiplyButton->Click += gcnew System::EventHandler(this, &Calculator::multiplyButton_Click);
		divideButton->Click += gcnew System::EventHandler(this, &Calculator::divideButton_Click);
		deleteButton->Click += gcnew System::EventHandler(this, &Calculator::deleteButton_Click);
		clearButton->Click += gcnew System::EventHandler(this, &Calculator::clearButton_Click);
		squareRootButton->Click += gcnew System::EventHandler(this, &Calculator::squareRootButton_Click);
		squaredButton->Click += gcnew System::EventHandler(this, &Calculator::squaredButton_Click);
		resultButton->Click += gcnew System::EventHandler(this, &Calculator::resultButton_Click);
		scientificButton->Click += gcnew System::EventHandler(this, &Calculator::scientificButton_Click);

	}
	//Destructor
	Calculator::~Calculator()
	{
		if (components)
		{
			delete components;
		}
	}

	//Button click numbers
	void Calculator::InitializeBasicCalculatorUI()
	{
		button1->Text = L"1";
		button2->Text = L"2";
		button3->Text = L"3";
		button4->Text = L"4";
		button5->Text = L"5";
		button6->Text = L"6";
		button7->Text = L"7";
		button8->Text = L"8";
		button9->Text = L"9";
		button0->Text = L"0";
	}

	//Basic calculator functions
	System::Void Calculator::btnNumber_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//adds number to inputbox when they are clicked
		Button^ clickedButton = dynamic_cast<Button^>(sender);
		if (clickedButton != nullptr)
		{
			String^ buttonText = clickedButton->Text;

			if (inputBox->Text == "0") {
				inputBox->Text = buttonText;
			}
			else
			{
				inputBox->Text += clickedButton->Text;
			}
		}
	}
	System::Void Calculator::decimalButton_Click(System::Object^ sender, System::EventArgs^ e)
	{	
		//cannot have two '.' in a single number
		if (!inputBox->Text->Contains("."))
		{
			inputBox->Text += ".";
		}
	}
	System::Void Calculator::addButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ currentText = inputBox->Text;

		if (!String::IsNullOrEmpty(currentText))
		{
			// Check if the last character is an operator
			// Cannot have two operators in a row
			char lastChar = currentText[currentText->Length - 1];

			if (lastChar == '+' || lastChar == '-' || lastChar == '*' || lastChar == '/')
			{
				// Replace the last operator with '+'
				currentText = currentText->Substring(0, currentText->Length - 1) + "+";
			}
			else
			{
				// Add '+' if the last character is not an operator
				currentText += "+";
			}

			// Update the input box with the modified text
			inputBox->Text = currentText;

			// Clear the result box for the next input
			resultBox->Text = "0";
		}
	}
	System::Void Calculator::subtractButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ currentText = inputBox->Text;

		if (!String::IsNullOrEmpty(currentText))
		{
			char lastChar = currentText[currentText->Length - 1];

			if (lastChar == '+' || lastChar == '-' || lastChar == '*' || lastChar == '/')
			{
				currentText = currentText->Substring(0, currentText->Length - 1) + "-";
			}
			else
			{
				currentText += "-";
			}

			inputBox->Text = currentText;
			resultBox->Text = "0";
		}
	}
	System::Void Calculator::multiplyButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ currentText = inputBox->Text;

		if (!String::IsNullOrEmpty(currentText))
		{
			char lastChar = currentText[currentText->Length - 1];

			if (lastChar == '+' || lastChar == '-' || lastChar == '*' || lastChar == '/')
			{
				currentText = currentText->Substring(0, currentText->Length - 1) + "*";
			}
			else
			{
				currentText += "*";
			}

			inputBox->Text = currentText;
			resultBox->Text = "0";
		}
	}
	System::Void Calculator::divideButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ currentText = inputBox->Text;

		if (!String::IsNullOrEmpty(currentText))
		{
			char lastChar = currentText[currentText->Length - 1];

			if (lastChar == '+' || lastChar == '-' || lastChar == '*' || lastChar == '/')
			{
				currentText = currentText->Substring(0, currentText->Length - 1) + "/";
			}
			else
			{
				currentText += "/";
			}

			inputBox->Text = currentText;
			resultBox->Text = "0";
		}
	}
	System::Void Calculator::deleteButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Check if the inputBox is not empty
		if (inputBox->Text->Length > 1)
		{
			// Remove the last character from the inputBox
			inputBox->Text = inputBox->Text->Substring(0, inputBox->Text->Length - 1);
		}
		else
		{	// Removing the last character changes the inputBox to 0
			inputBox->Text = "0";
		}
	}
	System::Void Calculator::resultButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		calculateResult();
	}
	System::Void Calculator::clearButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		resultBox->Text = "0";
		inputBox->Text = "0";
	}
	System::Void Calculator::squareRootButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		calculateResult();
		// Get current input
		String^ currentText = inputBox->Text;

		// Check if empty
		if (!String::IsNullOrEmpty(currentText)) {
			// Converts text to double
			double currentValue = Convert::ToDouble(currentText);
			double result = basicCalculator->squareRoot(currentValue);

			// Update Display
			resultBox->Text = result.ToString();
			inputBox->Text = result.ToString();
		}
		else {
			MessageBox::Show("Error. Input is empty.");
		}
	}
	System::Void Calculator::squaredButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		calculateResult();
		// Get current input
		String^ currentText = inputBox->Text;

		// Check if empty
		if (!String::IsNullOrEmpty(currentText)) {
			// Convert the current text to a double 
			double currentValue = Convert::ToDouble(currentText);
			double result = basicCalculator->squared(currentValue);

			// Update the display with the result
			resultBox->Text = result.ToString();
			inputBox->Text = result.ToString();
		}
		else {
			MessageBox::Show("Error. Input is empty.");
		}
	}
	
	// Calulate result before functions
	int Calculator::calculateResult() {
		String^ inputText = inputBox->Text;

		// If statement to check for exponent function first
		if (inputBox->Text->Contains("^"))
		{	
			// Get the current display text
			String^ currentText = inputBox->Text;

			// Check if the current text is not empty
			if (!String::IsNullOrEmpty(currentText))
			{
				// Split the input when '^' is read
				array<String^>^ parts = currentText->Split('^');

				if (parts->Length == 2)
				{
					try
					{
						// Parse the base and exponent
						double baseValue = Convert::ToDouble(parts[0]->Trim());
						double exponentValue = Convert::ToDouble(parts[1]->Trim());


						double powerXYResult = scientificCalculator->power(baseValue, exponentValue);

						// Update display with x^y result
						resultBox->Text = powerXYResult.ToString();
						inputBox->Text = powerXYResult.ToString();
					}
					catch (Exception^ ex)
					{
						// Handle parsing or calculation errors
						MessageBox::Show("Error: " + ex->Message);
					}
				}
				else
				{
					// Display an error if the input format is incorrect
					MessageBox::Show("Error: Invalid input format for x^y");
				}
			}
		} else	if (!String::IsNullOrWhiteSpace(inputText))
		{
			// the rest of calulcation function
			try
			{
				// calculate using a data table, rows and columns
				DataTable^ table = gcnew DataTable();
				DataColumn^ column = gcnew DataColumn("Expression", System::Type::GetType("System.Double"), inputText);
				table->Columns->Add(column);
				DataRow^ row = table->NewRow();
				table->Rows->Add(row);

				// Result from row
				double result = safe_cast<double>(row["Expression"]);

				// Update with result
				resultBox->Text = result.ToString();
				inputBox->Text = result.ToString();
			}
			catch (Exception^ ex)
			{
				// Handle other exceptions
				MessageBox::Show("Error: " + ex->Message);
			}
		}
		return 0;
	}

	//Scientific Calculator Code portion
	
	//Add all scientific calculator buttons
	void Calculator::InitializeScientificCalculatorUI()
	{
		// Add MCButton to the layout
		mcButton = gcnew System::Windows::Forms::Button();
		mcButton->Text = L"MC";
		mcButton->Size = System::Drawing::Size(46, 41);
		mcButton->Click += gcnew System::EventHandler(this, &Calculator::mcButton_Click);
		mcButton->Location = System::Drawing::Point(21, 40);
		this->Controls->Add(mcButton);

		// Add MRButton to the layout
		mrButton = gcnew System::Windows::Forms::Button();
		mrButton->Text = L"MR";
		mrButton->Size = System::Drawing::Size(46, 41);
		mrButton->Click += gcnew System::EventHandler(this, &Calculator::mrButton_Click);
		mrButton->Location = System::Drawing::Point(21, 40);
		this->Controls->Add(mrButton);

		// Add MSButton to the layout
		msButton = gcnew System::Windows::Forms::Button();
		msButton->Text = L"MS";
		msButton->Size = System::Drawing::Size(46, 41);
		msButton->Click += gcnew System::EventHandler(this, &Calculator::msButton_Click);
		msButton->Location = System::Drawing::Point(21, 40);
		this->Controls->Add(msButton);


		// Add sinButton to the layout
		sinButton = gcnew System::Windows::Forms::Button();
		sinButton->Text = L"sin";
		sinButton->Size = System::Drawing::Size(46, 41);
		sinButton->Click += gcnew System::EventHandler(this, &Calculator::sinButton_Click);
		sinButton->Location = System::Drawing::Point(21, 40); 
		this->Controls->Add(sinButton); 
		
		// Add cosButton to the layout
		cosButton = gcnew System::Windows::Forms::Button();
		cosButton->Text = L"cos";
		cosButton->Location = System::Drawing::Point(21, 40);
		cosButton->Size = System::Drawing::Size(46, 41);
		cosButton->Click += gcnew System::EventHandler(this, &Calculator::cosButton_Click);
		this->Controls->Add(cosButton);
		
		// Add tanButton to the layout
		tanButton = gcnew System::Windows::Forms::Button();
		tanButton->Text = L"tan";
		tanButton->Size = System::Drawing::Size(46, 41);
		tanButton->Location = System::Drawing::Point(21, 40);
		tanButton->Click += gcnew System::EventHandler(this, &Calculator::tanButton_Click);
		this->Controls->Add(tanButton);

		// Add logButton to the layout
		logButton = gcnew System::Windows::Forms::Button();
		logButton->Text = L"log";
		logButton->Size = System::Drawing::Size(46, 41);
		logButton->Location = System::Drawing::Point(21, 40);
		logButton->Click += gcnew System::EventHandler(this, &Calculator::logButton_Click);
		this->Controls->Add(logButton);

		// Add lnButton to the layout
		lnButton = gcnew System::Windows::Forms::Button();
		lnButton->Text = L"ln";
		lnButton->Size = System::Drawing::Size(46, 41);
		lnButton->Location = System::Drawing::Point(21, 40);
		lnButton->Click += gcnew System::EventHandler(this, &Calculator::lnButton_Click);
		this->Controls->Add(lnButton);

		// Add factorialButton to the layout
		factorialButton = gcnew System::Windows::Forms::Button();
		factorialButton->Text = L"n!";
		factorialButton->Size = System::Drawing::Size(46, 41);
		factorialButton->Location = System::Drawing::Point(21, 40);
		factorialButton->Click += gcnew System::EventHandler(this, &Calculator::factorialButton_Click);
		this->Controls->Add(factorialButton);

		// Add piButton to the layout
		piButton = gcnew System::Windows::Forms::Button();
		piButton->Text = L"π";
		piButton->Size = System::Drawing::Size(46, 41);
		piButton->Location = System::Drawing::Point(21, 40);
		piButton->Click += gcnew System::EventHandler(this, &Calculator::piButton_Click);
		this->Controls->Add(piButton);

		// Add cubedButton to the layout
		cubedButton = gcnew System::Windows::Forms::Button();
		cubedButton->Text = L"^3";
		cubedButton->Size = System::Drawing::Size(46, 41);
		cubedButton->Location = System::Drawing::Point(21, 40);
		cubedButton->Click += gcnew System::EventHandler(this, &Calculator::cubedButton_Click);
		this->Controls->Add(cubedButton);

		// Add powerButton to the layout
		powerButton = gcnew System::Windows::Forms::Button();
		powerButton->Text = L"x^y";
		powerButton->Size = System::Drawing::Size(46, 41);
		powerButton->Location = System::Drawing::Point(21, 40);
		powerButton->Click += gcnew System::EventHandler(this, &Calculator::powerButton_Click);
		this->Controls->Add(powerButton);

		// Add openButton to the layout
		openButton = gcnew System::Windows::Forms::Button();
		openButton->Text = L"(";
		openButton->Size = System::Drawing::Size(46, 41);
		openButton->Location = System::Drawing::Point(21, 40);
		openButton->Click += gcnew System::EventHandler(this, &Calculator::openButton_Click);
		this->Controls->Add(openButton);

		// Add closeButton to the layout
		closeButton = gcnew System::Windows::Forms::Button();
		closeButton->Text = L")";
		closeButton->Size = System::Drawing::Size(46, 41);
		closeButton->Location = System::Drawing::Point(21, 40);
		closeButton->Click += gcnew System::EventHandler(this, &Calculator::closeButton_Click);
		this->Controls->Add(closeButton);

		// Add posNegButton to the layout
		posNegButton = gcnew System::Windows::Forms::Button();
		posNegButton->Text = L"+/-";
		posNegButton->Size = System::Drawing::Size(46, 41);
		posNegButton->Location = System::Drawing::Point(21, 40);
		posNegButton->Click += gcnew System::EventHandler(this, &Calculator::posNegButton_Click);
		this->Controls->Add(posNegButton);
	}

	// Scientific button_Click functions
	System::Void Calculator::scientificButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Toggle the mode
		isScientificMode = !isScientificMode;

		if (isScientificMode)
		{
			// Adjust the form size for the scientific mode
			this->Width = 520; 
			this->Height = 474;

			// move buttons for layout
			mcButton->Location = System::Drawing::Point(300, 142);
			mrButton->Location = System::Drawing::Point(370, 142);
			msButton->Location = System::Drawing::Point(440, 142);
			sinButton->Location = System::Drawing::Point(300, 198);
			cosButton->Location = System::Drawing::Point(370, 198);
			tanButton->Location = System::Drawing::Point(440, 198);
			logButton->Location = System::Drawing::Point(300, 260);
			lnButton->Location = System::Drawing::Point(370, 260);
			factorialButton->Location = System::Drawing::Point(440, 260);
			piButton->Location = System::Drawing::Point(300, 318);
			cubedButton->Location = System::Drawing::Point(370, 318);
			powerButton->Location = System::Drawing::Point(440, 318);
			openButton->Location = System::Drawing::Point(300, 377);
			closeButton->Location = System::Drawing::Point(370, 377);
			posNegButton->Location = System::Drawing::Point(440, 377);

			//expand the result/input box
			resultBox->Size = System::Drawing::Size(461, 40);
			inputBox->Size = System::Drawing::Size(461, 40);

		}
		else
		{
			// Change back to basic calculator size
			this->Width = 320;
			this->Height = 474; 
			resultBox->Size = System::Drawing::Size(253, 40);
			inputBox->Size = System::Drawing::Size(253, 40);
		}
	}

	// Open parenthesis
	System::Void Calculator::openButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (inputBox->Text == "0") {
			inputBox->Text = "(";
		}
		else {
			inputBox->Text += "(";
		}
	}
	//Closed Parenthesis
	System::Void Calculator::closeButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		inputBox->Text += ")";
	}
	// Memory Clear
	System::Void Calculator::mcButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		memoryNumber = 0;
	}
	//Memory Recall
	System::Void Calculator::mrButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (inputBox->Text == "0") {
			inputBox->Text += memoryNumber.ToString();
		}
		else {
			inputBox->Text += memoryNumber.ToString();
		}
	}
	// Memory Store
	System::Void Calculator::msButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		memoryNumber = Convert::ToDouble(resultBox->Text);
	}

	//Sin function
	System::Void Calculator::sinButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Calculate inputBox first
		calculateResult();

		String^ currentText = inputBox->Text;

		if (!String::IsNullOrEmpty(currentText))
		{
			double value = Convert::ToDouble(currentText);
			double result = scientificCalculator->sin(value);

			// Update display with result
			resultBox->Text = result.ToString();
			inputBox->Text = result.ToString();
		}
	}
	//Cos function
	System::Void Calculator::cosButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		calculateResult();

		String^ currentText = inputBox->Text;

		if (!String::IsNullOrEmpty(currentText))
		{
			double value = Convert::ToDouble(currentText);
			double result = scientificCalculator->cos(value);


			resultBox->Text = result.ToString();
			inputBox->Text = result.ToString();
		}
	}
	//Tan function
	System::Void Calculator::tanButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		calculateResult();

		String^ currentText = inputBox->Text;

		if (!String::IsNullOrEmpty(currentText))
		{
			double value = Convert::ToDouble(currentText);
			double result = scientificCalculator->tan(value);

			resultBox->Text = result.ToString();
			inputBox->Text = result.ToString();
		}
	}
	//Log function (keeps it simple with base 10)
	System::Void Calculator::logButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		calculateResult();
		String^ currentText = inputBox->Text;

		if (!String::IsNullOrEmpty(currentText))
		{
			double value = Convert::ToDouble(currentText);
			double result = scientificCalculator->log(value);

			resultBox->Text = result.ToString();
			inputBox->Text = result.ToString();
		}
	}
	//Ln function
	System::Void Calculator::lnButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		calculateResult();

		String^ currentText = inputBox->Text;

		if (!String::IsNullOrEmpty(currentText))
		{
			double value = Convert::ToDouble(currentText);
			double result = scientificCalculator->ln(value);

			resultBox->Text = result.ToString();
			inputBox->Text = result.ToString();
		}
	}
	//factorial function
	System::Void Calculator::factorialButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		calculateResult();
		String^ currentText = inputBox->Text;

		if (!String::IsNullOrEmpty(currentText))
		{
			double value = Convert::ToDouble(currentText);
			double result = scientificCalculator->factorial(value);

			resultBox->Text = result.ToString();
			inputBox->Text = result.ToString();
		}
	}

	//changes input number to negative or positive
	System::Void Calculator::posNegButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ currentText = inputBox->Text;

		// Check if the current text is not empty or "0"
		if (!String::IsNullOrEmpty(currentText) && currentText != "0") {
			// Check if the number is positive or negative
			if (currentText[0] == '-') {
				// Remove the negative sign if the number is negative
				inputBox->Text = currentText->Substring(1);
			}
			else {
				// Add a negative sign if the number is positive
				inputBox->Text = "-" + currentText;
			}
		}
	}
	//exponential function
	System::Void Calculator::powerButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (inputBox->Text == "0") {
			inputBox->Text = "^";
		}
		else {
			inputBox->Text += "^";
		}
	}
	//Cubed function
	System::Void Calculator::cubedButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		calculateResult();
		String^ currentText = inputBox->Text;

		if (!String::IsNullOrEmpty(currentText)) {

			double currentValue = Convert::ToDouble(currentText);
			double result = scientificCalculator->cubed(currentValue);

			resultBox->Text = result.ToString();
			inputBox->Text = result.ToString();
		}
		else {
			MessageBox::Show("Error. Input is empty.");
		}
	}
	//pi button
	System::Void Calculator::piButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (inputBox->Text == "0") {
			inputBox->Text = "3.14";
		}
		else {
			inputBox->Text += "3.14";
		}
	}

}