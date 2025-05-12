#pragma once

namespace Lab7task2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox2
			// 
			this->textBox2->ForeColor = System::Drawing::Color::Gray;
			this->textBox2->Location = System::Drawing::Point(91, 81);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(200, 22);
			this->textBox2->TabIndex = 1;
			this->textBox2->Text = L"Your login";
			// 
			// textBox3
			// 
			this->textBox3->ForeColor = System::Drawing::Color::Gray;
			this->textBox3->Location = System::Drawing::Point(91, 125);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(200, 22);
			this->textBox3->TabIndex = 2;
			this->textBox3->Text = L"Your password";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.3F));
			this->button1->Location = System::Drawing::Point(91, 153);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 26);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Згенерувати пароль";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(91, 202);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(200, 57);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Авторизація";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(161, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 29);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Вхід";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Brown;
			this->label2->Location = System::Drawing::Point(19, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 15);
			this->label2->TabIndex = 6;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(382, 353);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Генерація пароля
		String^ password = generatePassword();
		textBox3->Text = password;
	}

	private: String^ generatePassword() {
		Random^ rand = gcnew Random();
		String^ chars = L"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
		String^ password = L"";
		for (int i = 0; i < 12; i++) {
			password += chars[rand->Next(chars->Length)];
		}
		return password;
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ login = textBox2->Text;
			String^ password = textBox3->Text;

			// Перевірка складності логіна
			if (!isValidLogin(login)) {
				throw gcnew Exception(L"Логін не відповідає вимогам: мінімум 8 символів, 1 вел буква, цифра, спецсимвол.");
			}

			// Перевірка складності пароля
			if (!isValidPassword(password)) {
				throw gcnew Exception(L"Пароль не відповідає вимогам: мін. 8 символів, 1 вел. і 1 мала буква, цифра, спецсимвол.");
			}

			label1->Text = "Авторизація успішна!";
			label1->Location = System::Drawing::Point(40, 27);
			label2->Text = " ";
		}
		catch (Exception^ ex) {
			label2->Text = "Помилка: " + ex->Message;
		}

	}
	bool isValidLogin(String^ login) {
		if (login->Length < 8) return false;

		bool hasDigit = false;
		bool hasUpper = false;
		bool hasSpecial = false;

		for (int i = 0; i < login->Length; i++) {
			if (Char::IsDigit(login[i])) hasDigit = true;
			else if (Char::IsUpper(login[i])) hasUpper = true;
			else if (login[i] == L'!' || login[i] == L'@' || login[i] == L'#' || login[i] == L'$' || login[i] == L'%' || login[i] == L'^' || login[i] == L'&' || login[i] == L'*') hasSpecial = true;
		}

		return hasDigit && hasUpper && hasSpecial;
	}

		   // Функція для перевірки складності пароля
	bool isValidPassword(String^ password) {
		if (password->Length < 8) return false;

		bool hasUpper = false;
		bool hasLower = false;
  		bool hasDigit = false;
		bool hasSpecial = false;

		for (int i = 0; i < password->Length; i++) {
			if (Char::IsUpper(password[i])) hasUpper = true;
			else if (Char::IsLower(password[i])) hasLower = true;
		    else if (Char::IsDigit(password[i])) hasDigit = true;
		    else if (password[i] == L'!' || password[i] == L'@' || password[i] == L'#' || password[i] == L'$' || password[i] == L'%' || password[i] == L'^' || password[i] == L'&' || password[i] == L'*') hasSpecial = true;
		}

	     return hasUpper && hasLower && hasDigit && hasSpecial;
	}
};
}
