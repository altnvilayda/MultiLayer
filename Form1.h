#pragma once
#include <Windows.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include <iomanip>
#include "Resource.h"
#include "Process.h"
#define INPUTSIZE 3
#define CLASS_COUNT comboBox1->Items->Count
#define HiddenLayerSize 6
#define MAX_Cycle 5e6
#define FileWeights "Weights.txt"
#define FileSamples "Samples.txt"

namespace WinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->comboBox1->SelectedIndex = 0;
			Size = 0; // Baslangıcta örnek yok.
			random =  gcnew Random();
			randomColor = gcnew Color();
			ClassColorTable = gcnew Hashtable();

			for (int i = 0; i < this->CLASS_COUNT; i++)
			{
				randomColor = Color::FromArgb(random->Next(0, 255), random->Next(0, 255), random->Next(0, 255));
				ClassColorTable->Add(comboBox1->Items[i]->ToString(), randomColor);
				
			}
			
			bitmap = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			pictureBox1->Image = bitmap;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			// Collect Garbage: w , p etc.

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		
		Samples* p; // örneklerimizi alıyoruz.
		double **w;
		double** V;
		int Size;
		float c;
		
		Hashtable^ ClassColorTable;
		Random^ random;
		Color^ randomColor;
		Bitmap^ bitmap;

		// Normalizasyon parametreleri
		float m1, m2;
		float s1, s2;
		
#pragma region WinForm Objects


	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ initialToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ randomToolStripMenuItem;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ToolStripMenuItem^ traningToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deltaLearningToolStripMenuItem;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ loadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ showSamplesToolStripMenuItem;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::ComponentModel::IContainer^ components;

#pragma endregion

		
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->initialToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->randomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->traningToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deltaLearningToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showSamplesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Lavender;
			this->pictureBox1->Location = System::Drawing::Point(12, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(448, 421);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(525, 40);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(59, 24);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::SystemColors::Window;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Class 1", L"Class 2" });
			this->comboBox1->Location = System::Drawing::Point(525, 79);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 3;
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->processToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(959, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->loadToolStripMenuItem,
					this->saveToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			this->loadToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->loadToolStripMenuItem->Text = L"Load";
			this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::loadToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveToolStripMenuItem_Click);
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->initialToolStripMenuItem,
					this->traningToolStripMenuItem, this->showSamplesToolStripMenuItem
			});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// initialToolStripMenuItem
			// 
			this->initialToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->randomToolStripMenuItem });
			this->initialToolStripMenuItem->Name = L"initialToolStripMenuItem";
			this->initialToolStripMenuItem->Size = System::Drawing::Size(147, 22);
			this->initialToolStripMenuItem->Text = L"initial";
			// 
			// randomToolStripMenuItem
			// 
			this->randomToolStripMenuItem->Name = L"randomToolStripMenuItem";
			this->randomToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->randomToolStripMenuItem->Text = L"random";
			this->randomToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::randomToolStripMenuItem_Click);
			// 
			// traningToolStripMenuItem
			// 
			this->traningToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->deltaLearningToolStripMenuItem });
			this->traningToolStripMenuItem->Name = L"traningToolStripMenuItem";
			this->traningToolStripMenuItem->Size = System::Drawing::Size(147, 22);
			this->traningToolStripMenuItem->Text = L"Training";
			// 
			// deltaLearningToolStripMenuItem
			// 
			this->deltaLearningToolStripMenuItem->Name = L"deltaLearningToolStripMenuItem";
			this->deltaLearningToolStripMenuItem->Size = System::Drawing::Size(147, 22);
			this->deltaLearningToolStripMenuItem->Text = L"DeltaLearning";
			this->deltaLearningToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::deltaLearningToolStripMenuItem_Click);
			// 
			// showSamplesToolStripMenuItem
			// 
			this->showSamplesToolStripMenuItem->Name = L"showSamplesToolStripMenuItem";
			this->showSamplesToolStripMenuItem->Size = System::Drawing::Size(147, 22);
			this->showSamplesToolStripMenuItem->Text = L"ShowSamples";
			this->showSamplesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::showSamplesToolStripMenuItem_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(590, 40);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(56, 24);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Remove";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(522, 133);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Size : ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(522, 161);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Cycle : ";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(727, 65);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(204, 296);
			this->richTextBox1->TabIndex = 8;
			this->richTextBox1->Text = L"";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(794, 40);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"WEIGHT";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(959, 489);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Multilayer FeedForward Network";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		this->comboBox1->Items->Add("Class " + (CLASS_COUNT + 1) );

		randomColor = Color::FromArgb(random->Next(0, 255), random->Next(0, 255), random->Next(0, 255));
		ClassColorTable->Add(comboBox1->Items[CLASS_COUNT -1], randomColor);

	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		this->comboBox1->Items->Remove("Class " + (CLASS_COUNT));
		//ClassColorTable->Remove(comboBox1->Items[CLASS_COUNT - 1], randomColor);
		//ClassColorTable->Remove(comboBox1->Items[comboBox1->SelectedIndex]);
	}

	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			
		//Ana eksen dogruları cizdir.
		Pen^ pen = gcnew Pen(Color::Black, 1.0f);
		int center_width, center_height;
		center_width = (int)(pictureBox1->Width / 2);
		center_height = (int)(pictureBox1->Height / 2);
		e->Graphics->DrawLine(pen, center_width, 0, center_width, pictureBox1->Height);
		e->Graphics->DrawLine(pen, 0, center_height, pictureBox1->Width, center_height);

	}	

	private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {


		Pen^ pen = gcnew Pen((Color)ClassColorTable[comboBox1->SelectedItem], 2.0f);
		
		int temp_x, temp_y;
		float x1, x2;
		temp_x = (System::Convert::ToInt32(e->X));
		temp_y = (System::Convert::ToInt32(e->Y));
		x1 = (float)(temp_x - (pictureBox1->Width / 2));
		x2 = (float)((pictureBox1->Height / 2) - temp_y);

		if (Size == 0)
		{
			p = new Samples[1];
			p[0].x1 = x1;
			p[0].x2 = x2;
			p[0].id = comboBox1->SelectedIndex;
			Size++;
		}
		else
		{
			Samples* temp; //data lar temp de tutuluyor.
			temp = p;
			Size++;
			p = new Samples[Size];

			for (int i = 0; i < Size-1; i++)
			{

				p[i].x1 = temp[i].x1;
				p[i].x2 = temp[i].x2;
				p[i].id = temp[i].id;

			}
			p[Size - 1].x1 = x1;
			p[Size - 1].x2 = x2;
			p[Size - 1].id = comboBox1->SelectedIndex;
			delete temp;

		}
		
		pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
		pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
		label1->Text = "Size : " + Convert::ToString(Size);

	}
	
    private: System::Void randomToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Pen^ pen = gcnew Pen(Color::RoyalBlue, 2.0f);

		int min_x, min_y, max_x, max_y;
		
		w = new double*[CLASS_COUNT];
		for (int i = 0; i < CLASS_COUNT; i++)
		{
			w[i] = new double[HiddenLayerSize + 1];
		}
		srand(time(0));
		
		for (int i = 0; i < CLASS_COUNT; i++)	//w[nöron][input]  nöron : sınıf sayısı kadar olmalı 
		{
			label3->Text = Convert::ToString(w[i]);
			for (int j = 0; j < HiddenLayerSize + 1; j++)						//input : x1, x2, bias olacak.
			{
				w[i][j] = ((double)rand() / (RAND_MAX));
			}
		}
		// HiddenLayer weights
		V = new double* [HiddenLayerSize];
		for (int i = 0; i < HiddenLayerSize; i++)
		{
			V[i] = new double[INPUTSIZE];
		}
		srand(time(0));

		for (int i = 0; i < HiddenLayerSize; i++)	//w[nöron][input]  nöron : sınıf sayısı kadar olmalı 
		{
			label3->Text = Convert::ToString(w[i]);
			for (int j = 0; j < INPUTSIZE; j++)						//input : x1, x2, bias olacak.
			{
				V[i][j] = ((double)rand() / (RAND_MAX));
			}
		}
		//SHOW WEIGHT 
		for (size_t i = 0; i < HiddenLayerSize; i++)
		{
			for (size_t j = 0; j < INPUTSIZE; j++)
			{
				richTextBox1->Text += " V[" + i + "][" + j + "] : " + Convert::ToString(V[i][j]) + "\n";
			}
			richTextBox1->Text += "\n";
		}

		for (size_t i = 0; i < CLASS_COUNT; i++)
		{
			for (size_t j = 0; j < HiddenLayerSize; j++)
			{
				richTextBox1->Text += " w[" + i + "][" + j + "] : " + Convert::ToString(w[i][j] ) + "\n";
			}
			richTextBox1->Text += "\n";
		}

		//Rastgele ağırlıklarla doğru çizme
		/*min_x = (this->pictureBox1->Width) / (-2);
		max_x = (this->pictureBox1->Width) / 2;
		for (size_t i = 0; i < comboBox1->Items->Count; i++)
		{
			min_y = YPoint(min_x, w[i]);
			max_y = YPoint(max_x, w[i]);
			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, 
														 (pictureBox1->Height / 2) - min_y,
														 (pictureBox1->Width / 2) + max_x, 
														 (pictureBox1->Height / 2) - max_y);
		}
		*/
	}

	private: System::Void PerceptronLearningToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		//SINGLE-LAYER PERCEPTRON LEARNING

		// W = rand Mx3
		// y = [x bias]'	----> [ 3x1 ]
		// Net Mx1  = W[M][3] x y[3][1]
		//d1 = [1 -1 -1], d2 = [-1 1 -1] ....  yani d[p[i].id] = 1 olacak şekilde ayarlanmalı.
		// d - o kıyaslaması yapılır ve örtüşmeyen nörondaki ağırlık güncellenir.
		// Ağırlık güncelleme = Wk = 1/2 * c *(d-o)y'
		// cycle tamamlanınca E > 0 ? eğitime devam : eğitim sonlanır.
		
		Pen^ pen = gcnew Pen(Color::Black, 2.0f);
		Graphics^ GFX = pictureBox1->CreateGraphics();

		int min_x, min_y, max_x, max_y;
		min_x = (this->pictureBox1->Width) / (-2);
		max_x = (this->pictureBox1->Width) / 2;

		int* y = new int[INPUTSIZE]; // Input vektörü , Son eleman BIAS
		y[INPUTSIZE - 1] = -1;

		float* net = new float[CLASS_COUNT];
		int* d = new int[CLASS_COUNT];
		int *o = new int[CLASS_COUNT];
	    int*E = new int[CLASS_COUNT];
		int cycle = 0;

		int TotalError = 0;

		c = 0.5;

		while (true)
		{
			// 1. TotalError Sıfırlanacak:
			TotalError = 0;

			// Her bir sample gezilsin
			for (size_t idx = 0; idx < Size; idx++)
			{
				// d vektörünü -1 ile başlat; sonradan uygun yer +1 e eşitlenecek
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					d[i] = -1;
				}
				d[p[idx].id] = 1;

				// 2. Net Hesapla : önce y vektörü yüklenmeli [x y -1]
				y[0] = p[idx].x1;
				y[1] = p[idx].x2;

				//	Net = W*y
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					float sum = 0;
					for (size_t j = 0; j < INPUTSIZE; j++)
					{
						sum += w[i][j] * y[j];
					}
					net[i] = sum;
					o[i] = sgn(net[i]); //
					E[i] = d[i] - o[i];	//
					for (size_t j = 0; j < INPUTSIZE; j++)//		
					{
						w[i][j] += 0.5 * c * E[i] * y[j];
					}
	
				}

				/*// 3. o Hesapla : sgn()
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					o[i] = sgn(net[i]);
				}*/

				/*// 4. E Hesapla : d - o , önce d vektörünü düzenle ( Uygun Yere +1, gerisi -1)
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					E[i] = d[i] - o[i];
				}*/

				/*// 5. W Güncelle : 0.5 * c * (d-o) * y
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					for (size_t j = 0; j < INPUTSIZE; j++)
					{
						w[i][j] += 0.5 * c * E[i] * y[j];
					}
				}*/
				
				TotalError += Sum(E, CLASS_COUNT);
			}                                        

			// Toplam Hata;
			if (TotalError == 0)
			{
				break;
			}
			
			cycle++;	
			if (cycle % 1000 == 0)
			{
				UpDateFeatureSpace();
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					pen->Color = (Color)ClassColorTable[comboBox1->Items[i]];

					min_y = YPoint(min_x, w[i]);
					max_y = YPoint(max_x, w[i]);
					pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x,
						                                         (pictureBox1->Height / 2) - min_y,
						                                         (pictureBox1->Width / 2) + max_x,
						                                         (pictureBox1->Height / 2) - max_y);
				}
			}
			if (cycle > MAX_Cycle)
			{
				MessageBox::Show("max cycle sayısına ulasıldı.");
				break;
			}
				
		}
		UpDateFeatureSpace();

		for (size_t i = 0; i < CLASS_COUNT; i++)
		{
			pen->Color = (Color)ClassColorTable[comboBox1->Items[i]];
			
			min_y = YPoint(min_x, w[i]);
			max_y = YPoint(max_x, w[i]);
			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x,
														 (pictureBox1->Height / 2) - min_y,
														 (pictureBox1->Width / 2) + max_x,
														 (pictureBox1->Height / 2) - max_y);
		}

		label2->Text = "cycle : " + Convert::ToString(cycle);
	}
	private: System::Void deltaLearningToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
		Pen^ pen = gcnew Pen(Color::Black, 2.0f);
		Graphics^ GFX = pictureBox1->CreateGraphics();

		int min_x, min_y, max_x, max_y;
		min_x = (this->pictureBox1->Width) / (-2);
		max_x = (this->pictureBox1->Width) / 2;


		float* z = new float[INPUTSIZE];					//ilk girişler (normalleştirilmiş)
		z[INPUTSIZE - 1] = -1;
		float* net1 = new float[HiddenLayerSize];			//ilk katman net1 = Vz
		float* y = new float[HiddenLayerSize + 1];			// y = 1. katmanın outputu 2. katman inputu , y = f(net1)
		y[HiddenLayerSize] = -1;
		//f'(net) = 0.5 * (1 - o2)
		float* net2 = new float[CLASS_COUNT];				//net2 = W*y
		float* O = new float[CLASS_COUNT];					//O = f(net2)
		int* d = new int[CLASS_COUNT];
		float* E = new float[CLASS_COUNT];					// E = E + 0.5 * (d - o)^2
		//Calculate error So, Sy
		float* delta_o = new float[CLASS_COUNT];			//So = 0.5 * (d - O)(1 - O) ^ 2;
		float* delta_y = new float[HiddenLayerSize + 1];	//W*So*f'y2 , f'y2 = 0.5*[1 - z^2]
		//Adjust weight of output layer						// w = w + n*So*y2
		//Adjust weight of hidden layer						// V = V + n*Sy*y1
		//E < E_max? stop : (E = 0) 
		int cycle = 0;
		float TotalError = 0.0;
		c = 0.1;
		
		calcMeans();
		calcStds();

		while (true)
		{
			
			// TotalError Sıfırlanacak:
			TotalError = 0.0f;
			// Her bir sample gezilsin
			for (size_t idx = 0; idx < Size; idx++)
			{
				// d vektörünü -1 ile başlat; sonradan uygun yer +1 e eşitlenecek
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					d[i] = -1;
				}
				d[p[idx].id] = 1;

				//  Net Hesapla : önce z vektörü yüklenmeli (normalize edilerek). [x y -1]
				z[0] = (p[idx].x1 - m1) / s1;
				z[1] = (p[idx].x2 - m2) / s2;

				// Net1 = V*z
				for (size_t i = 0; i < HiddenLayerSize; i++)
				{
					float sum = 0.0f;
					for (size_t j = 0; j < INPUTSIZE; j++)
					{
						sum += V[i][j] * z[j];
					}
					net1[i] = sum;
					y[i] = SigmoidFunc(net1[i]);
				}
				// 2.katman hesaplaması
				// Net2 = W * y
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					float sum = 0.0f;
					for (size_t j = 0; j < HiddenLayerSize + 1; j++)
					{
						sum += w[i][j] * y[j];
					}
					net2[i] = sum;
					O[i] = SigmoidFunc(net2[i]);
				}
				// Hata hesaplama: E = 0.5 *  (d - o)^2
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					E[i] = (d[i] - O[i]) * (d[i] - O[i]);
				}
				// Öğrenme sinyalleri hesaplama
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					delta_o[i] = 0.5f * (d[i] - O[i]) * (1 - O[i] * O[i]);

				}
				
				for (size_t i = 0; i < HiddenLayerSize + 1; i++) // --
				{
					float sum = 0.0f;
					for (size_t j = 0; j < CLASS_COUNT; j++)
					{
						sum += w[j][i] * delta_o[j];
					}
					delta_y[i] = sum * 0.5f * (1 - y[i] * y[i]);
				}

				// Ağırlıkları güncelle.
				for (size_t i = 0; i < CLASS_COUNT; i++)   // ++
				{
					for (size_t j = 0; j < HiddenLayerSize + 1; j++)
					{
						w[i][j] += c * delta_o[i] * y[j];
					}
				}

				

				for (size_t i = 0; i < HiddenLayerSize; i++)
				{
					for (size_t j = 0; j < INPUTSIZE; j++)
					{
						V[i][j] += c * delta_y[i] * z[j];
					}
				}

				// Toplam hata güncelle
				TotalError += Sum(E, CLASS_COUNT);
				
			}
			// Toplam Hata;
			float Erms = Math::Sqrt(TotalError) / (Size * CLASS_COUNT);
			if ( Erms < 0.05)
			{
				break;
			}
			cycle++;

			
			if (cycle > MAX_Cycle)
			{
				MessageBox::Show("max cycle sayısına ulasıldı.");
				break;
			}
			
		}
		label2->Text = "cycle : " + Convert::ToString(cycle);
		Test();

	}
	
	public: void UpDateFeatureSpace()
	{
		// Variables:
		Graphics^ GFX = pictureBox1->CreateGraphics();

		// 1 - Kanvası sıfırla sil
		GFX->Clear(pictureBox1->BackColor);

		// 2 - Eksenleri çiz
		Pen^ pen = gcnew Pen(Color::Black, 1.0f);
		int center_width, center_height;
		center_width = (int)(pictureBox1->Width / 2);
		center_height = (int)(pictureBox1->Height / 2);
		GFX->DrawLine(pen, center_width, 0, center_width, pictureBox1->Height);
		GFX->DrawLine(pen, 0, center_height, pictureBox1->Width, center_height);

		// 3 - Örnekleri çiz (p ile)
		       //SIKINTI BURADA GALİBA
		for (size_t i = 0; i < Size; i++)
		{
			pen->Color = (Color)ClassColorTable[comboBox1->Items[p[i].id]];
			GFX->DrawLine(pen, (pictureBox1->Width / 2) + p[i].x1 - 5, (pictureBox1->Height / 2) - p[i].x2,
							    (pictureBox1->Width / 2) + p[i].x1 + 5, (pictureBox1->Height / 2) - p[i].x2);

			GFX->DrawLine(pen, (pictureBox1->Width / 2) + p[i].x1, (pictureBox1->Height / 2) - p[i].x2 - 5,
							    (pictureBox1->Width / 2) + p[i].x1, (pictureBox1->Height / 2) - p[i].x2 + 5);
		}

		//pictureBox1->Refresh();

	}
	public: void calcMeans()
	{
		float total1, total2;

		for (size_t i = 0; i < Size; i++)
		{
			total1 += p[i].x1;
			total2 += p[i].x2;
		}

		this->m1 = total1 / Size;
		this->m2 = total2 / Size;

	}
	public: void calcStds()
	{
		// m1 , m2 biliniyor...
		/*
		Vi = Xi - m
		V : vektörel

		variance = V'V / N
		std = sqrt(variance)


		*/
		float sqSum1 = 0;
		float sqSum2 = 0;

		for (size_t i = 0; i < Size; i++)
		{
			sqSum1 += (p[i].x1 - m1) * (p[i].x1 - m1);
			sqSum2 += (p[i].x2 - m2) * (p[i].x2 - m2);
		}

		this->s1 = sqrtf(sqSum1) / Size;
		this->s2 = sqrtf(sqSum2) / Size;
	}
	public: void Test()
	{
		float z[3] = { 0 , 0 , -1.0f };
		float net1[HiddenLayerSize] = { 0.0f };
		float y[HiddenLayerSize + 1] = { 0.0f };
		y[HiddenLayerSize] = -1.0f; // BIAS
		
		float* net2 = new float[CLASS_COUNT];
		float* O	= new float[CLASS_COUNT];

		// input : Her bir pikselin koordinatları
		for (int row = 0; row < pictureBox1->Height; row++)
		{
			for (int col = 0; col < pictureBox1->Width; col++)
			{
				// 1
				z[0] = ((float)(col - (pictureBox1->Width / 2)) - m1) / s1;
				z[1] = ((float)((pictureBox1->Height / 2) - row) - m2) / s2;

				// Net1 = V*z
				for (size_t i = 0; i < HiddenLayerSize; i++)
				{
					float sum = 0.0f;
					for (size_t j = 0; j < INPUTSIZE; j++)
					{
						sum += V[i][j] * z[j];
					}
					net1[i] = sum;
					y[i] = SigmoidFunc(net1[i]);
				}

				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					float sum = 0.0f;
					for (size_t j = 0; j < HiddenLayerSize + 1; j++)
					{
						sum += w[i][j] * y[j];
					}
					net2[i] = sum;
					O[i] = SigmoidFunc(net2[i]);
				}

				int ClassID = 0;
				float max = O[0];
				for (size_t i = 1; i < CLASS_COUNT; i++)
				{
					if ( O[i] > max)
					{
						max = O[i];
						ClassID = i;
					}
				}

				Color LabelColor = (Color)ClassColorTable[comboBox1->Items[ClassID]];
				bitmap->SetPixel(col, row, LabelColor);

			}
		}
		pictureBox1->Refresh();

	}

	private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		std::fstream WFileStream;	//Ağırlıklar icin
		std::fstream SFileStream; // Örnekler için

		// 1. Dosyaya Yaz
		//Örnekler için
		SFileStream.open(FileSamples, std::ios::out);

		if (!SFileStream.is_open())
		{
			MessageBox::Show("HATA! Samples dosyası açılamadı!");
			return;
		}
		else
		{
			SFileStream << CLASS_COUNT << std::endl;
			SFileStream << Size << std::endl;
			for (size_t i = 0; i < Size; i++)
			{
				SFileStream << p[i].id << " " << p[i].x1 << " " << p[i].x2 << std::endl;
			}

			SFileStream.close();
		}

		//Ağırlıklar için
		WFileStream.open(FileWeights, std::ios::out);

		if (!WFileStream.is_open())
		{
			MessageBox::Show("HATA! Weights dosyası açılamadı!");
			return;
		}
		else
		{
			WFileStream << HiddenLayerSize << std::endl;
			WFileStream << INPUTSIZE << std::endl;
			for (size_t i = 0; i < HiddenLayerSize; i++)
			{
				for (size_t j = 0; j < INPUTSIZE; j++)
				{
					WFileStream << std::setprecision(15) << V[i][j] << std::endl;
				}
			}

			WFileStream << CLASS_COUNT << std::endl;
			WFileStream << HiddenLayerSize + 1 << std::endl;
			for (size_t i = 0; i < CLASS_COUNT; i++)
			{
				for (size_t j = 0; j < HiddenLayerSize + 1; j++)
					WFileStream<< std::setprecision(15) << w[i][j] << std::endl;
			}
			WFileStream.close();
		}
	}
	private: System::Void loadToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		std::fstream WFileStream; // Ağırlıklar için  
		std::fstream SFileStream; // Örnekler için
		int ClassCount;	//dosyadan gelen class sayısı
		int SampleSize;


		// 1. Ekrana Al
		//Örnekler için
		SFileStream.open(FileSamples, std::ios::in);

		if (!SFileStream.is_open())
		{
			MessageBox::Show("HATA! Sample dosyası açılamadı!");
			return;
		}
		else
		{
			SFileStream >> ClassCount;
			SFileStream >> SampleSize;
			this->Size = SampleSize;
			this->p = new Samples[SampleSize];

			while (CLASS_COUNT != ClassCount)
			{
				button1_Click(this, nullptr);
			}

			int idx = 0;

			while (SFileStream.good())
			{
				SFileStream >> p[idx].id;
				SFileStream >> p[idx].x1;
				SFileStream >> p[idx].x2;

				idx++;
			}

			SFileStream.close();
		}
		//Ağırlıklar için
		int row, col;
		WFileStream.open(FileWeights, std::ios::in);
		if (!WFileStream.is_open())
		{
			MessageBox::Show("HATA! Weights dosyası açılamadı!");
			return;
		}
		else
		{
			WFileStream >> row;
			WFileStream >> col;
			this->V = new double* [row];
			for (int i = 0; i < row; i++)
				this->V[i] = new double[col];

			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
					WFileStream >> V[i][j];
			}

			WFileStream >> row;
			WFileStream >> col;
			this->w = new double*[row];
			for (int i = 0; i < row; i++)
				this->w[i] = new double[col];

			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
					WFileStream >> w[i][j];
			}

			WFileStream.close();
		}		
		UpDateFeatureSpace();
	}
	private: System::Void showSamplesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
		Pen^ pen = gcnew Pen(Color::Black, 1.0f);
		Graphics^ GFX = pictureBox1->CreateGraphics();

		for (size_t i = 0; i < Size; i++)
		{
			pen->Color = (Color)ClassColorTable[comboBox1->Items[p[i].id]];
			GFX->DrawLine(pen, (pictureBox1->Width / 2) + p[i].x1 - 5, (pictureBox1->Height / 2) - p[i].x2,
				(pictureBox1->Width / 2) + p[i].x1 + 5, (pictureBox1->Height / 2) - p[i].x2);

			GFX->DrawLine(pen, (pictureBox1->Width / 2) + p[i].x1, (pictureBox1->Height / 2) - p[i].x2 - 5,
				(pictureBox1->Width / 2) + p[i].x1, (pictureBox1->Height / 2) - p[i].x2 + 5);
		}
		GFX->DrawString("OK", gcnew System::Drawing::Font("Arial", 10), Brushes::Black, 100, 100);
		//pictureBox1->Refresh();
	}
};
}
