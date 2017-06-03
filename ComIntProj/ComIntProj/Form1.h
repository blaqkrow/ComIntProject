#pragma once
#include <Windows.h>
#include "stdafx.h"
#include <conio.h>

extern "C"
{

	extern int HID_GetHandle(unsigned int VendorID, unsigned int ProductID, unsigned long DesiredAccess, HANDLE *Handle);
}

extern "C" 
{
	extern int	Serial_SetComport(unsigned char Comport);
	extern int	Serial_SetBaudrate(unsigned int Baudrate);
	extern int	Serial_SetNumDataBit(unsigned char NumStartBit);
	extern int	Serial_SetNumStopBit(unsigned char NumStopBit);
	extern int	Serial_SetParity(unsigned char Parity);
	extern int	Serial_Open(void);
	extern int	Serial_Close(void);
	extern int	Serial_ClearBuffer(void);
	extern void Serial_SetReceiveTimeout(unsigned int TimeoutMsec);
	extern int	Serial_Send(unsigned char *SendPacketPtr, unsigned int SendLen);
	extern int	Serial_Receive(unsigned char *ReceivePacketPtr, unsigned int BytesToReceive, unsigned int *ActualBytesReceived);
}

HANDLE HID_Handle = INVALID_HANDLE_VALUE;
unsigned char Send_Alarm_Cancel = 0;

unsigned char tx_buffer[5];	// tx_buffer array to store tx data
unsigned char rx_buffer[5];	// rx_buffer array to store rx data
unsigned int bytes_recvd;	// store number of bytes received
namespace ComIntProj {

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
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txtBoxVID;
	private: System::Windows::Forms::TextBox^  txtBoxPID;
	private: System::Windows::Forms::Button^  btnConnect;
	private: System::Windows::Forms::Button^  btnDisconnect;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  labelStatus;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  btnAlarmCancel;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  pictureBoxGreen2;
	private: System::Windows::Forms::PictureBox^  pictureBoxRed2;
	private: System::Windows::Forms::PictureBox^  pictureBoxRed3;
	private: System::Windows::Forms::PictureBox^  pictureBoxGreen3;

	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  pHLabel;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::PictureBox^  pictureBoxRed1;
	private: System::Windows::Forms::PictureBox^  pictureBoxGreen1;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::PictureBox^  pictureBoxRed0;
	private: System::Windows::Forms::PictureBox^  pictureBoxGreen0;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;

	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  pHLabel2;
	private: System::Windows::Forms::ProgressBar^  progressBar2;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  txtBoxCOM;
	private: System::Windows::Forms::Button^  btnChange;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtBoxVID = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxPID = (gcnew System::Windows::Forms::TextBox());
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->btnDisconnect = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->labelStatus = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnAlarmCancel = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBoxGreen2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxRed2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxRed3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxGreen3 = (gcnew System::Windows::Forms::PictureBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pHLabel = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->pictureBoxRed1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxGreen1 = (gcnew System::Windows::Forms::PictureBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->pictureBoxRed0 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxGreen0 = (gcnew System::Windows::Forms::PictureBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->pHLabel2 = (gcnew System::Windows::Forms::Label());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->txtBoxCOM = (gcnew System::Windows::Forms::TextBox());
			this->btnChange = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxGreen2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxRed2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxRed3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxGreen3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxRed1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxGreen1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxRed0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxGreen0))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 89);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Vendor ID:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 115);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Product ID:";
			// 
			// txtBoxVID
			// 
			this->txtBoxVID->Location = System::Drawing::Point(74, 86);
			this->txtBoxVID->Name = L"txtBoxVID";
			this->txtBoxVID->Size = System::Drawing::Size(100, 20);
			this->txtBoxVID->TabIndex = 2;
			this->txtBoxVID->Text = L"4d8";
			// 
			// txtBoxPID
			// 
			this->txtBoxPID->Location = System::Drawing::Point(74, 112);
			this->txtBoxPID->Name = L"txtBoxPID";
			this->txtBoxPID->Size = System::Drawing::Size(100, 20);
			this->txtBoxPID->TabIndex = 3;
			this->txtBoxPID->Text = L"3f";
			// 
			// btnConnect
			// 
			this->btnConnect->Location = System::Drawing::Point(13, 152);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(161, 32);
			this->btnConnect->TabIndex = 4;
			this->btnConnect->Text = L"Connect";
			this->btnConnect->UseVisualStyleBackColor = true;
			this->btnConnect->Click += gcnew System::EventHandler(this, &Form1::btnConnect_Click);
			// 
			// btnDisconnect
			// 
			this->btnDisconnect->Location = System::Drawing::Point(13, 190);
			this->btnDisconnect->Name = L"btnDisconnect";
			this->btnDisconnect->Size = System::Drawing::Size(161, 32);
			this->btnDisconnect->TabIndex = 5;
			this->btnDisconnect->Text = L"Disconnected";
			this->btnDisconnect->UseVisualStyleBackColor = true;
			this->btnDisconnect->Click += gcnew System::EventHandler(this, &Form1::btnDisconnect_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 232);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Status:";
			// 
			// labelStatus
			// 
			this->labelStatus->AutoSize = true;
			this->labelStatus->Location = System::Drawing::Point(58, 232);
			this->labelStatus->Name = L"labelStatus";
			this->labelStatus->Size = System::Drawing::Size(79, 13);
			this->labelStatus->TabIndex = 7;
			this->labelStatus->Text = L"Not Connected";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(69, 16);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(65, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Test Tube 2";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(285, 16);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(65, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Test Tube 3";
			// 
			// btnAlarmCancel
			// 
			this->btnAlarmCancel->Location = System::Drawing::Point(13, 266);
			this->btnAlarmCancel->Name = L"btnAlarmCancel";
			this->btnAlarmCancel->Size = System::Drawing::Size(161, 68);
			this->btnAlarmCancel->TabIndex = 10;
			this->btnAlarmCancel->Text = L"Alarm Cancel";
			this->btnAlarmCancel->UseVisualStyleBackColor = true;
			this->btnAlarmCancel->Click += gcnew System::EventHandler(this, &Form1::btnAlarmCancel_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// pictureBoxGreen2
			// 
			this->pictureBoxGreen2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBoxGreen2.Image")));
			this->pictureBoxGreen2->Location = System::Drawing::Point(16, 32);
			this->pictureBoxGreen2->Name = L"pictureBoxGreen2";
			this->pictureBoxGreen2->Size = System::Drawing::Size(80, 80);
			this->pictureBoxGreen2->TabIndex = 11;
			this->pictureBoxGreen2->TabStop = false;
			// 
			// pictureBoxRed2
			// 
			this->pictureBoxRed2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBoxRed2.Image")));
			this->pictureBoxRed2->Location = System::Drawing::Point(111, 32);
			this->pictureBoxRed2->Name = L"pictureBoxRed2";
			this->pictureBoxRed2->Size = System::Drawing::Size(80, 80);
			this->pictureBoxRed2->TabIndex = 12;
			this->pictureBoxRed2->TabStop = false;
			this->pictureBoxRed2->Visible = false;
			// 
			// pictureBoxRed3
			// 
			this->pictureBoxRed3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBoxRed3.Image")));
			this->pictureBoxRed3->Location = System::Drawing::Point(327, 32);
			this->pictureBoxRed3->Name = L"pictureBoxRed3";
			this->pictureBoxRed3->Size = System::Drawing::Size(80, 80);
			this->pictureBoxRed3->TabIndex = 14;
			this->pictureBoxRed3->TabStop = false;
			this->pictureBoxRed3->Visible = false;
			// 
			// pictureBoxGreen3
			// 
			this->pictureBoxGreen3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBoxGreen3.Image")));
			this->pictureBoxGreen3->Location = System::Drawing::Point(232, 32);
			this->pictureBoxGreen3->Name = L"pictureBoxGreen3";
			this->pictureBoxGreen3->Size = System::Drawing::Size(80, 80);
			this->pictureBoxGreen3->TabIndex = 13;
			this->pictureBoxGreen3->TabStop = false;
			// 
			// progressBar1
			// 
			this->progressBar1->ForeColor = System::Drawing::SystemColors::Desktop;
			this->progressBar1->Location = System::Drawing::Point(124, 129);
			this->progressBar1->Maximum = 260;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(177, 23);
			this->progressBar1->TabIndex = 16;
			this->progressBar1->Value = 50;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 136);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(54, 13);
			this->label6->TabIndex = 17;
			this->label6->Text = L"pH Value:";
			// 
			// pHLabel
			// 
			this->pHLabel->AutoSize = true;
			this->pHLabel->Location = System::Drawing::Point(69, 136);
			this->pHLabel->Name = L"pHLabel";
			this->pHLabel->Size = System::Drawing::Size(25, 13);
			this->pHLabel->TabIndex = 18;
			this->pHLabel->Text = L"N.A";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 9);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(120, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Communication method:";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(138, 7);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(51, 17);
			this->radioButton1->TabIndex = 20;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Serial";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(138, 30);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(47, 17);
			this->radioButton2->TabIndex = 21;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"USB";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// pictureBoxRed1
			// 
			this->pictureBoxRed1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBoxRed1.Image")));
			this->pictureBoxRed1->Location = System::Drawing::Point(111, 36);
			this->pictureBoxRed1->Name = L"pictureBoxRed1";
			this->pictureBoxRed1->Size = System::Drawing::Size(80, 80);
			this->pictureBoxRed1->TabIndex = 24;
			this->pictureBoxRed1->TabStop = false;
			this->pictureBoxRed1->Visible = false;
			// 
			// pictureBoxGreen1
			// 
			this->pictureBoxGreen1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBoxGreen1.Image")));
			this->pictureBoxGreen1->Location = System::Drawing::Point(16, 36);
			this->pictureBoxGreen1->Name = L"pictureBoxGreen1";
			this->pictureBoxGreen1->Size = System::Drawing::Size(80, 80);
			this->pictureBoxGreen1->TabIndex = 23;
			this->pictureBoxGreen1->TabStop = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(281, 32);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(65, 13);
			this->label8->TabIndex = 22;
			this->label8->Text = L"Test Tube 1";
			// 
			// pictureBoxRed0
			// 
			this->pictureBoxRed0->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBoxRed0.Image")));
			this->pictureBoxRed0->Location = System::Drawing::Point(327, 36);
			this->pictureBoxRed0->Name = L"pictureBoxRed0";
			this->pictureBoxRed0->Size = System::Drawing::Size(80, 80);
			this->pictureBoxRed0->TabIndex = 27;
			this->pictureBoxRed0->TabStop = false;
			this->pictureBoxRed0->Visible = false;
			// 
			// pictureBoxGreen0
			// 
			this->pictureBoxGreen0->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBoxGreen0.Image")));
			this->pictureBoxGreen0->Location = System::Drawing::Point(232, 36);
			this->pictureBoxGreen0->Name = L"pictureBoxGreen0";
			this->pictureBoxGreen0->Size = System::Drawing::Size(80, 80);
			this->pictureBoxGreen0->TabIndex = 26;
			this->pictureBoxGreen0->TabStop = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(497, 32);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(65, 13);
			this->label9->TabIndex = 25;
			this->label9->Text = L"Test Tube 0";
			// 
			// groupBox1
			// 
			this->groupBox1->Location = System::Drawing::Point(212, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(421, 142);
			this->groupBox1->TabIndex = 28;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Controlled through Serial";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->pictureBoxRed0);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->pictureBoxGreen0);
			this->groupBox2->Controls->Add(this->pHLabel);
			this->groupBox2->Controls->Add(this->progressBar1);
			this->groupBox2->Controls->Add(this->pictureBoxRed1);
			this->groupBox2->Controls->Add(this->pictureBoxGreen1);
			this->groupBox2->Location = System::Drawing::Point(212, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(421, 168);
			this->groupBox2->TabIndex = 28;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Controlled through Serial";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &Form1::groupBox2_Enter);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Controls->Add(this->pictureBoxGreen2);
			this->groupBox3->Controls->Add(this->pHLabel2);
			this->groupBox3->Controls->Add(this->pictureBoxRed2);
			this->groupBox3->Controls->Add(this->progressBar2);
			this->groupBox3->Controls->Add(this->pictureBoxGreen3);
			this->groupBox3->Controls->Add(this->pictureBoxRed3);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Location = System::Drawing::Point(212, 186);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(421, 165);
			this->groupBox3->TabIndex = 29;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Controlled through USB";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(13, 135);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(54, 13);
			this->label10->TabIndex = 29;
			this->label10->Text = L"pH Value:";
			// 
			// pHLabel2
			// 
			this->pHLabel2->AutoSize = true;
			this->pHLabel2->Location = System::Drawing::Point(69, 135);
			this->pHLabel2->Name = L"pHLabel2";
			this->pHLabel2->Size = System::Drawing::Size(25, 13);
			this->pHLabel2->TabIndex = 30;
			this->pHLabel2->Text = L"N.A";
			// 
			// progressBar2
			// 
			this->progressBar2->ForeColor = System::Drawing::SystemColors::Desktop;
			this->progressBar2->Location = System::Drawing::Point(124, 128);
			this->progressBar2->Maximum = 260;
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(177, 23);
			this->progressBar2->TabIndex = 28;
			this->progressBar2->Value = 50;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(21, 51);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(47, 26);
			this->label11->TabIndex = 30;
			this->label11->Text = L"COM\r\nNumber:";
			// 
			// txtBoxCOM
			// 
			this->txtBoxCOM->Location = System::Drawing::Point(74, 57);
			this->txtBoxCOM->Name = L"txtBoxCOM";
			this->txtBoxCOM->Size = System::Drawing::Size(33, 20);
			this->txtBoxCOM->TabIndex = 31;
			this->txtBoxCOM->Text = L"5";
			// 
			// btnChange
			// 
			this->btnChange->Location = System::Drawing::Point(113, 53);
			this->btnChange->Name = L"btnChange";
			this->btnChange->Size = System::Drawing::Size(61, 27);
			this->btnChange->TabIndex = 32;
			this->btnChange->Text = L"Change";
			this->btnChange->UseVisualStyleBackColor = true;
			this->btnChange->Click += gcnew System::EventHandler(this, &Form1::btnChange_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(671, 363);
			this->Controls->Add(this->btnChange);
			this->Controls->Add(this->txtBoxCOM);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->btnAlarmCancel);
			this->Controls->Add(this->labelStatus);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnDisconnect);
			this->Controls->Add(this->btnConnect);
			this->Controls->Add(this->txtBoxPID);
			this->Controls->Add(this->txtBoxVID);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox3);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxGreen2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxRed2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxRed3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxGreen3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxRed1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxGreen1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxRed0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxGreen0))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

			Serial_SetComport(Convert::ToInt32(txtBoxCOM->Text));
			Serial_SetBaudrate(9600);
			Serial_SetNumDataBit(8);
			Serial_SetNumStopBit(1);
			Serial_SetParity('N');
			Serial_Open();

			 }
private: System::Void btnConnect_Click(System::Object^  sender, System::EventArgs^  e) {

			 unsigned int vendor_id;
			 unsigned int product_id;
			 int		  status;

			//Read in vendor id + product id (in hex) from text boxes
			 vendor_id = Convert::ToInt32(txtBoxVID->Text, 16);
			 product_id = Convert::ToInt32(txtBoxPID->Text, 16);

			 //Check whether handle was opened previously
			 //if yes, close handle first. Otherwise, HID_GetHandle() will fail later

			 if(HID_Handle != INVALID_HANDLE_VALUE)
					CloseHandle(HID_Handle);

			 status = HID_GetHandle(vendor_id,product_id, GENERIC_READ|GENERIC_WRITE, &HID_Handle);

			 if(status == 0)
			 {
				 labelStatus->Text = "Connected!";
				 timer1->Enabled = true;
			 }
			 else
			 {
				 labelStatus->Text = "Not Connected.";
				 timer1->Enabled = true;
			 }

			 labelStatus->Refresh();
		 }
private: System::Void btnDisconnect_Click(System::Object^  sender, System::EventArgs^  e) {
			 timer1->Enabled = false;

			 if(HID_Handle != INVALID_HANDLE_VALUE)
			 CloseHandle(HID_Handle);

			 HID_Handle = INVALID_HANDLE_VALUE;

			 labelStatus->Text = "Not Connected.";
		 }

private: System::Void btnAlarmCancel_Click(System::Object^  sender, System::EventArgs^  e) {

			 Send_Alarm_Cancel = 1;
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

			 unsigned char write_buffer[6];
			 unsigned char read_buffer[6];
			 unsigned long bytes_written, bytes_read;
			 BOOL			result;
			 int serialResult = 1;
			 int pH;
			if(radioButton1->Checked == true) //if Serial is selected
			{
				if(Send_Alarm_Cancel == 0)
				{
				tx_buffer[0] = 0xAB;	// Start Byte				
				tx_buffer[1] = 0x02;	// Receiver's Addr
				tx_buffer[2] = 0x80;	// Cmd
				tx_buffer[3] = 0x00;	// Data
				tx_buffer[4] = 0xFF - 0x02 - 0x80 - 0x00;	// Check sum
				Serial_Send(&tx_buffer[0], 5); // address of tx_buffer[0], 5 bytes to send
				}

			serialResult = Serial_Receive(&rx_buffer[0], 5, &bytes_recvd);
			if(serialResult == 0)
				 {
					if(rx_buffer[2] == 0x80) //test tube 0 and 1
					{
						if(rx_buffer[3] == 0x01) //test tube 0
						{
						 pictureBoxGreen0->Visible = false;
						 pictureBoxRed0->Visible = true;
						}
						else if(rx_buffer[3] == 0x02) //test tube 1
						{
						 pictureBoxGreen1->Visible = false;
						 pictureBoxRed1->Visible = true;
						}
					}
					if(rx_buffer[2] == 0x82) //test tube 0 and 1
					{
						 progressBar1->Value = rx_buffer[3];
					
						 pH = (rx_buffer[3])/18;
						 pHLabel->Text = Convert::ToString(pH);
					}
				 }

				 
			}
		if(radioButton2->Checked == true) //if USB is selected
			{
				 write_buffer[0] = 0x00;
				 write_buffer[1] = 0xAB;
				 write_buffer[2] = 0x02; //device adress
				 write_buffer[3] = 0x41; //temperature checking command
				 write_buffer[4] = 0x00;
				 write_buffer[5] = 0xFF -  write_buffer[2] - write_buffer[3] - write_buffer[4];

				 result = WriteFile(HID_Handle, write_buffer,6,&bytes_written,0);
				 if(result == false)
				 {
					 return;
				 }

				 result = ReadFile(HID_Handle, read_buffer,6,&bytes_read,0);
				 if(result != false)
				 {
					 if(read_buffer[3] == 0x42) //adc progress bar
					 {
						 //ALL TEST TUBES ARE NORMAL
						 progressBar2->Value = read_buffer[4];
					
						 pH = (read_buffer[4])/18;
						 pHLabel2->Text = Convert::ToString(pH);
					
						 if(pH>=0 && pH<7)
						 {
							//acidic 
						 }
						 if(pH == 7)
						 {
							 //neutral
						 }
						 if(pH>7)
						 {
							 //alkaline
						 }
					 }
					 else if(read_buffer[3] == 0x41)
					 {
						 if(read_buffer[4] == 0x02) //test tube 2
						 {
							 //test tube 2 temp exceed
							 pictureBoxGreen2->Visible = false;
							 pictureBoxRed2->Visible = true;
						
						 }
						 else if(read_buffer[4] == 0x03)//test tube 3 temp exceed
						 {
						 
							 pictureBoxGreen3->Visible = false;
							 pictureBoxRed3->Visible = true;
						 }
					 }
				 }
			 }

			 if(Send_Alarm_Cancel == 1)
			 {

				 if(radioButton2->Checked == true){ //usb

					write_buffer[0] = 0x00;
					write_buffer[1] = 0xAB;
					write_buffer[2] = 0x02;
					write_buffer[3] = 0x44; //cmd for alarm cancel
					write_buffer[4] = 0x00;
					write_buffer[5] = 0xFF - write_buffer[2] - write_buffer[3] - write_buffer[4];

					result = WriteFile(HID_Handle, write_buffer,6,&bytes_written,0);
					if(read_buffer[3] == 0x44)
					{
						if(read_buffer[4] == 0x00)
						{
						pictureBoxGreen2->Visible = true;
						pictureBoxRed2->Visible = false;
						pictureBoxGreen3->Visible = true;
						pictureBoxRed3->Visible = false;

						Send_Alarm_Cancel = 0;
						}
					}
				 }

				 if(radioButton1->Checked == true){ //serial

					tx_buffer[0] = 0xAB;
					tx_buffer[1] = 0x02;
					tx_buffer[2] = 0x81; //cmd for alarm cancel
					tx_buffer[3] = 0x00;
					tx_buffer[4] = 0xFF - tx_buffer[1] - tx_buffer[2] - tx_buffer[3];

					Serial_Send(&tx_buffer[0], 5);

					if(rx_buffer[2] == 0x81)
					{
						if(rx_buffer[3] == 0x00)
						{
						pictureBoxGreen0->Visible = true;
						pictureBoxRed0->Visible = false;
						pictureBoxGreen1->Visible = true;
						pictureBoxRed1->Visible = false;

						Send_Alarm_Cancel = 0;
						}
					}
				 }
			 }
			 

		}
		
private: System::Void btnToggleLED_Click(System::Object^  sender, System::EventArgs^  e) {
	////int status;
	//unsigned char tx_buffer[5];	// tx_buffer array to store tx data
	//unsigned char rx_buffer[5];	// rx_buffer array to store rx data
	//unsigned int bytes_recvd;	// store number of bytes received

	//// Configure and open com port
	//Serial_SetComport(1);
	//Serial_SetBaudrate(19200);
	//Serial_SetNumDataBit(8);
	//Serial_SetNumStopBit(1);
	//Serial_SetParity('N');
	//Serial_Open();

	//		tx_buffer[0] = 0xAB;	// Start Byte				
	//		tx_buffer[1] = 0x01;	// Receiver's Addr
	//		tx_buffer[2] = 0x80;	// Cmd
	//		tx_buffer[3] = 0x00;	// Data
	//		tx_buffer[4] = 0xFF - 0x01 - 0x80 - 0x00;	// Check sum
	//		Serial_Send(&tx_buffer[0], 5); // address of tx_buffer[0], 5 bytes to send

		 }
private: System::Void btnChange_Click(System::Object^  sender, System::EventArgs^  e) {
			Serial_SetComport(Convert::ToInt32(txtBoxCOM->Text));
			Serial_SetBaudrate(19200);
			Serial_SetNumDataBit(8);
			Serial_SetNumStopBit(1);
			Serial_SetParity('N');
			Serial_Open();
		 }
private: System::Void groupBox2_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

