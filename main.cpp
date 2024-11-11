#include "Calculator.h"
#include "Basic.h"
#include "Scientific.h"

using namespace System;

using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ args)

{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Calculator::Calculator form;
    Application::Run(% form);
}