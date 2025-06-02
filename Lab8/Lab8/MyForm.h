#pragma once

namespace Lab8 {

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
			UpdateObjectSelection(); // Початкова позначка
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
	private:
		MenuStrip^ menuStrip;
		ToolStripMenuItem^ файлToolStripMenuItem;
		ToolStripMenuItem^ обєктиToolStripMenuItem;
		ToolStripMenuItem^ довідкаToolStripMenuItem;

		ToolStripMenuItem^ крапкаToolStripMenuItem;
		ToolStripMenuItem^ лініяToolStripMenuItem;
		ToolStripMenuItem^ прямокутникToolStripMenuItem;
		ToolStripMenuItem^ еліпсToolStripMenuItem;

		int selectedObjectIndex = 0; // 0 = крапка, 1 = лінія, 2 = прямокутник, 3 = еліпс
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Lab8::MyForm::Form1_Paint);


			this->menuStrip = gcnew MenuStrip();
			this->файлToolStripMenuItem = gcnew ToolStripMenuItem();
			this->обєктиToolStripMenuItem = gcnew ToolStripMenuItem();
			this->довідкаToolStripMenuItem = gcnew ToolStripMenuItem();

			this->крапкаToolStripMenuItem = gcnew ToolStripMenuItem();
			this->лініяToolStripMenuItem = gcnew ToolStripMenuItem();
			this->прямокутникToolStripMenuItem = gcnew ToolStripMenuItem();
			this->еліпсToolStripMenuItem = gcnew ToolStripMenuItem();

			// MenuStrip
			this->menuStrip->Items->AddRange(gcnew cli::array<ToolStripItem^> {
				this->файлToolStripMenuItem,
					this->обєктиToolStripMenuItem,
					this->довідкаToolStripMenuItem
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(800, 24);
			this->menuStrip->TabIndex = 0;
			this->menuStrip->Text = L"menuStrip";

			// Файл
			this->файлToolStripMenuItem->Text = L"Файл";

			// Об’єкти
			this->обєктиToolStripMenuItem->Text = L"Об’єкти";
			this->обєктиToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array<ToolStripItem^> {
				this->крапкаToolStripMenuItem,
					this->лініяToolStripMenuItem,
					this->прямокутникToolStripMenuItem,
					this->еліпсToolStripMenuItem
			});

			// Довідка
			this->довідкаToolStripMenuItem->Text = L"Довідка";

			// Підпункти "Об’єкти"
			this->крапкаToolStripMenuItem->Text = L"Крапка";
			this->лініяToolStripMenuItem->Text = L"Лінія";
			this->прямокутникToolStripMenuItem->Text = L"Прямокутник";
			this->еліпсToolStripMenuItem->Text = L"Еліпс";

			this->крапкаToolStripMenuItem->Click += gcnew EventHandler(this, &MyForm::крапкаToolStripMenuItem_Click);
			this->лініяToolStripMenuItem->Click += gcnew EventHandler(this, &MyForm::лініяToolStripMenuItem_Click);
			this->прямокутникToolStripMenuItem->Click += gcnew EventHandler(this, &MyForm::прямокутникToolStripMenuItem_Click);
			this->еліпсToolStripMenuItem->Click += gcnew EventHandler(this, &MyForm::еліпсToolStripMenuItem_Click);

			// Форму
			this->ClientSize = System::Drawing::Size(800, 450);
			this->Controls->Add(this->menuStrip);
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"Form1";
			this->Text = L"Графічний редактор Lab8";
		}
#pragma endregion

		// Метод для позначки поточного об’єкта
		void UpdateObjectSelection() {
			array<ToolStripMenuItem^>^ items = {
				крапкаToolStripMenuItem,
				лініяToolStripMenuItem,
				прямокутникToolStripMenuItem,
				еліпсToolStripMenuItem
			};
			for (int i = 0; i < items->Length; i++) {
				items[i]->Checked = (i == selectedObjectIndex);
			}
		}
		private: System::Void Form1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			Graphics^ g = e->Graphics;

			// Сталі координати для демонстрації
			System::Drawing::Point A(50, 50);
			System::Drawing::Point B(200, 150);
			System::Drawing::Point center(300, 200);
			System::Drawing::Point corner(400, 280);

			switch (selectedObjectIndex) {
			case 0: { // Крапка
				Pen^ pen = gcnew Pen(Color::Black, 3); // Чорна товста крапка
				g->DrawEllipse(pen, A.X - 2, A.Y - 2, 4, 4); // Малюємо маленький круг як крапку
				delete pen;
				break;
			}
			case 1: { // Лінія
				Pen^ pen = gcnew Pen(Color::Black, 2); // Чорна лінія товщиною 2
				g->DrawLine(pen, A, B);
				delete pen;
				break;
			}
			case 2: { // Прямокутник по двох протилежних кутах
				int x = Math::Min(A.X, B.X);
				int y = Math::Min(A.Y, B.Y);
				int w = Math::Abs(A.X - B.X);
				int h = Math::Abs(A.Y - B.Y);

				SolidBrush^ fillBrush = gcnew SolidBrush(Color::LightBlue); // Блакитний
				Pen^ borderPen = gcnew Pen(Color::Black);

				g->FillRectangle(fillBrush, x, y, w, h);
				g->DrawRectangle(borderPen, x, y, w, h);

				delete fillBrush;
				delete borderPen;
				break;
			}
			case 3: { // Еліпс від центру до кута прямокутника
				int rx = Math::Abs(corner.X - center.X);
				int ry = Math::Abs(corner.Y - center.Y);
				int x = center.X - rx;
				int y = center.Y - ry;
				int w = rx * 2;
				int h = ry * 2;

				SolidBrush^ fillBrush = gcnew SolidBrush(Color::LightGreen); // Світло-зелений
				Pen^ borderPen = gcnew Pen(Color::Black);

				g->FillEllipse(fillBrush, x, y, w, h);
				g->DrawEllipse(borderPen, x, y, w, h);

				delete fillBrush;
				delete borderPen;
				break;
			}
			}
		}



		// Обробники подій:
	private: System::Void крапкаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		selectedObjectIndex = 0;
		this->Text = L"Графічний редактор Lab8 — Крапка";
		UpdateObjectSelection();
		this->Invalidate();
	}
	private: System::Void лініяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		selectedObjectIndex = 1;
		this->Text = L"Графічний редактор Lab8 — Лінія";
		UpdateObjectSelection();
		this->Invalidate();
	}
	private: System::Void прямокутникToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		selectedObjectIndex = 2;
		this->Text = L"Графічний редактор Lab8 — Прямокутник";
		UpdateObjectSelection();
		this->Invalidate();
	}
	private: System::Void еліпсToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		selectedObjectIndex = 3;
		this->Text = L"Графічний редактор Lab8 — Еліпс";
		UpdateObjectSelection();
		this->Invalidate();
	}

	};
}
