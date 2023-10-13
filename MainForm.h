//Made by AlSch092 @ github
#pragma once
#include <vcclr.h>
#include "Network/Packets/Packets.hpp"
#include "Offsets.hpp"
#include "Hooks.hpp"
#pragma comment(lib, "ws2_32")

bool g_StreamingPacketsToFile = false;
bool g_LoggingSendPackets = false;

extern "C" void EncryptSendPacketHook();

namespace HoHPacketEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_Packets;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^  copyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearAllToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  blockOpcodeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ignoreOpcodeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  findToolStripMenuItem;

		Thread^ SendPacketThread;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage_Packets;
	private: System::Windows::Forms::TextBox^  textBox_SpamPacketDelay;
	private: System::Windows::Forms::CheckBox^  checkBox_LogRecv;
	private: System::Windows::Forms::CheckBox^  checkBox_SpamPacket;
	private: System::Windows::Forms::ComboBox^  comboBox_DeleteModifyRule;
	private: System::Windows::Forms::Button^  button_ModifyPacketRule;
	private: System::Windows::Forms::TextBox^  textBox_ModifyPacketRule;
	private: System::Windows::Forms::Button^  button_SendPacket;
	private: System::Windows::Forms::TextBox^  textBox_SendPacketInput;
	private: System::Windows::Forms::CheckBox^  checkBox_LogSendPacket;
	private: System::Windows::Forms::ListView^  listView_Packets;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_Direction;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_SPLength;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_SPOpcode;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_SPData;
	private: System::Windows::Forms::TabPage^  tabPage_Hacks;
	private: System::Windows::Forms::GroupBox^  groupBox_Hacks;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button_SetX;
	private: System::Windows::Forms::Button^  button_SetCoordinates;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_Z;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_Y;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_X;
	private: System::Windows::Forms::CheckBox^  checkBox_HookPlayerPosition;
	private: System::Windows::Forms::GroupBox^  groupBox_MountExploit;
	private: System::Windows::Forms::Button^  button_MountExploit;
	private: System::Windows::Forms::ComboBox^  comboBox_MountExploit;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label_Unrandom;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_RandValue;
	private: System::Windows::Forms::CheckBox^  checkBox_Unrandomizer;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_CPUReducerTime;
	private: System::Windows::Forms::CheckBox^  checkBox_StopRender;
	private: System::Windows::Forms::CheckBox^  checkBox_ReduceCPU;
	private: System::Windows::Forms::CheckBox^  checkBox_RAMReduce;
	private: System::Windows::Forms::GroupBox^  groupBox_CharInfo;
	private: System::Windows::Forms::CheckBox^  checkBox_StatsBuff;
	private: System::Windows::Forms::CheckBox^  checkBox_LogDebugMsg;
	private: System::Windows::Forms::CheckBox^  checkBox_DisplayPlayerData;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label_GridY;
	private: System::Windows::Forms::Label^  label_Exp;
	private: System::Windows::Forms::Label^  label_PlayerClass;
	private: System::Windows::Forms::Label^  label_GridX;
	private: System::Windows::Forms::Label^  label_Level;
	private: System::Windows::Forms::Label^  label_Status;
	private: System::Windows::Forms::Label^  label_HP;
	private: System::Windows::Forms::Label^  label_MP;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  checkBox_IncreaseAcceleration;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_Speed;
	private: System::Windows::Forms::CheckBox^  checkBox_SetGameSpeed;
	private: System::Windows::Forms::TabPage^  tabPage_Scripting;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::CheckBox^  checkBox_RepeatScript;
	private: System::Windows::Forms::CheckBox^  checkBox_RandomizingLUAName;
	private: System::Windows::Forms::Button^  button_DownloadLUA;
	private: System::Windows::Forms::Button^  button_LoadLUA;
	private: System::Windows::Forms::Button^  button_SaveLUA;
	private: System::Windows::Forms::Button^  button_RunLUA;
	private: System::Windows::Forms::Button^  button_StopLUA;
	private: System::Windows::Forms::TextBox^  textBox_ScriptText;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage_Packets = (gcnew System::Windows::Forms::TabPage());
			this->textBox_SpamPacketDelay = (gcnew System::Windows::Forms::TextBox());
			this->checkBox_LogRecv = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_SpamPacket = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox_DeleteModifyRule = (gcnew System::Windows::Forms::ComboBox());
			this->button_ModifyPacketRule = (gcnew System::Windows::Forms::Button());
			this->textBox_ModifyPacketRule = (gcnew System::Windows::Forms::TextBox());
			this->button_SendPacket = (gcnew System::Windows::Forms::Button());
			this->textBox_SendPacketInput = (gcnew System::Windows::Forms::TextBox());
			this->checkBox_LogSendPacket = (gcnew System::Windows::Forms::CheckBox());
			this->listView_Packets = (gcnew System::Windows::Forms::ListView());
			this->columnHeader_Direction = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_SPLength = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_SPOpcode = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_SPData = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip_Packets = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->blockOpcodeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ignoreOpcodeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->findToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabPage_Hacks = (gcnew System::Windows::Forms::TabPage());
			this->groupBox_Hacks = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button_SetX = (gcnew System::Windows::Forms::Button());
			this->button_SetCoordinates = (gcnew System::Windows::Forms::Button());
			this->numericUpDown_Z = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_Y = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_X = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox_HookPlayerPosition = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox_MountExploit = (gcnew System::Windows::Forms::GroupBox());
			this->button_MountExploit = (gcnew System::Windows::Forms::Button());
			this->comboBox_MountExploit = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label_Unrandom = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_RandValue = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox_Unrandomizer = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_CPUReducerTime = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox_StopRender = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_ReduceCPU = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_RAMReduce = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox_CharInfo = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_StatsBuff = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_LogDebugMsg = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_DisplayPlayerData = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label_GridY = (gcnew System::Windows::Forms::Label());
			this->label_Exp = (gcnew System::Windows::Forms::Label());
			this->label_PlayerClass = (gcnew System::Windows::Forms::Label());
			this->label_GridX = (gcnew System::Windows::Forms::Label());
			this->label_Level = (gcnew System::Windows::Forms::Label());
			this->label_Status = (gcnew System::Windows::Forms::Label());
			this->label_HP = (gcnew System::Windows::Forms::Label());
			this->label_MP = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_IncreaseAcceleration = (gcnew System::Windows::Forms::CheckBox());
			this->numericUpDown_Speed = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox_SetGameSpeed = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage_Scripting = (gcnew System::Windows::Forms::TabPage());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_RepeatScript = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_RandomizingLUAName = (gcnew System::Windows::Forms::CheckBox());
			this->button_DownloadLUA = (gcnew System::Windows::Forms::Button());
			this->button_LoadLUA = (gcnew System::Windows::Forms::Button());
			this->button_SaveLUA = (gcnew System::Windows::Forms::Button());
			this->button_RunLUA = (gcnew System::Windows::Forms::Button());
			this->button_StopLUA = (gcnew System::Windows::Forms::Button());
			this->textBox_ScriptText = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1->SuspendLayout();
			this->tabPage_Packets->SuspendLayout();
			this->contextMenuStrip_Packets->SuspendLayout();
			this->tabPage_Hacks->SuspendLayout();
			this->groupBox_Hacks->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Z))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Y))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_X))->BeginInit();
			this->groupBox_MountExploit->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_RandValue))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CPUReducerTime))->BeginInit();
			this->groupBox_CharInfo->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Speed))->BeginInit();
			this->tabPage_Scripting->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage_Packets);
			this->tabControl1->Controls->Add(this->tabPage_Hacks);
			this->tabControl1->Controls->Add(this->tabPage_Scripting);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(763, 556);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage_Packets
			// 
			this->tabPage_Packets->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage_Packets->Controls->Add(this->textBox_SpamPacketDelay);
			this->tabPage_Packets->Controls->Add(this->checkBox_LogRecv);
			this->tabPage_Packets->Controls->Add(this->checkBox_SpamPacket);
			this->tabPage_Packets->Controls->Add(this->comboBox_DeleteModifyRule);
			this->tabPage_Packets->Controls->Add(this->button_ModifyPacketRule);
			this->tabPage_Packets->Controls->Add(this->textBox_ModifyPacketRule);
			this->tabPage_Packets->Controls->Add(this->button_SendPacket);
			this->tabPage_Packets->Controls->Add(this->textBox_SendPacketInput);
			this->tabPage_Packets->Controls->Add(this->checkBox_LogSendPacket);
			this->tabPage_Packets->Controls->Add(this->listView_Packets);
			this->tabPage_Packets->Location = System::Drawing::Point(4, 22);
			this->tabPage_Packets->Name = L"tabPage_Packets";
			this->tabPage_Packets->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_Packets->Size = System::Drawing::Size(755, 530);
			this->tabPage_Packets->TabIndex = 0;
			this->tabPage_Packets->Text = L"Packets";
			// 
			// textBox_SpamPacketDelay
			// 
			this->textBox_SpamPacketDelay->Location = System::Drawing::Point(587, 481);
			this->textBox_SpamPacketDelay->Name = L"textBox_SpamPacketDelay";
			this->textBox_SpamPacketDelay->Size = System::Drawing::Size(100, 20);
			this->textBox_SpamPacketDelay->TabIndex = 27;
			this->textBox_SpamPacketDelay->Text = L"Milliseconds...";
			// 
			// checkBox_LogRecv
			// 
			this->checkBox_LogRecv->AutoSize = true;
			this->checkBox_LogRecv->Location = System::Drawing::Point(7, 512);
			this->checkBox_LogRecv->Name = L"checkBox_LogRecv";
			this->checkBox_LogRecv->Size = System::Drawing::Size(86, 17);
			this->checkBox_LogRecv->TabIndex = 26;
			this->checkBox_LogRecv->Text = L"Log Inbound";
			this->checkBox_LogRecv->UseVisualStyleBackColor = true;
			// 
			// checkBox_SpamPacket
			// 
			this->checkBox_SpamPacket->AutoSize = true;
			this->checkBox_SpamPacket->Location = System::Drawing::Point(697, 483);
			this->checkBox_SpamPacket->Name = L"checkBox_SpamPacket";
			this->checkBox_SpamPacket->Size = System::Drawing::Size(53, 17);
			this->checkBox_SpamPacket->TabIndex = 24;
			this->checkBox_SpamPacket->Text = L"Spam";
			this->checkBox_SpamPacket->UseVisualStyleBackColor = true;
			// 
			// comboBox_DeleteModifyRule
			// 
			this->comboBox_DeleteModifyRule->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->comboBox_DeleteModifyRule->FormattingEnabled = true;
			this->comboBox_DeleteModifyRule->Location = System::Drawing::Point(7, 446);
			this->comboBox_DeleteModifyRule->Name = L"comboBox_DeleteModifyRule";
			this->comboBox_DeleteModifyRule->Size = System::Drawing::Size(87, 21);
			this->comboBox_DeleteModifyRule->TabIndex = 23;
			this->comboBox_DeleteModifyRule->Visible = false;
			// 
			// button_ModifyPacketRule
			// 
			this->button_ModifyPacketRule->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_ModifyPacketRule->Location = System::Drawing::Point(688, 441);
			this->button_ModifyPacketRule->Name = L"button_ModifyPacketRule";
			this->button_ModifyPacketRule->Size = System::Drawing::Size(58, 20);
			this->button_ModifyPacketRule->TabIndex = 22;
			this->button_ModifyPacketRule->Text = L"Modify Rule";
			this->button_ModifyPacketRule->UseVisualStyleBackColor = true;
			this->button_ModifyPacketRule->Visible = false;
			// 
			// textBox_ModifyPacketRule
			// 
			this->textBox_ModifyPacketRule->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox_ModifyPacketRule->Location = System::Drawing::Point(108, 448);
			this->textBox_ModifyPacketRule->Name = L"textBox_ModifyPacketRule";
			this->textBox_ModifyPacketRule->Size = System::Drawing::Size(569, 20);
			this->textBox_ModifyPacketRule->TabIndex = 21;
			this->textBox_ModifyPacketRule->Text = L"Packet to replace (same opcode)";
			this->textBox_ModifyPacketRule->Visible = false;
			// 
			// button_SendPacket
			// 
			this->button_SendPacket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_SendPacket->Location = System::Drawing::Point(690, 502);
			this->button_SendPacket->Margin = System::Windows::Forms::Padding(1, 2, 1, 2);
			this->button_SendPacket->Name = L"button_SendPacket";
			this->button_SendPacket->Size = System::Drawing::Size(58, 22);
			this->button_SendPacket->TabIndex = 20;
			this->button_SendPacket->Text = L"Send Outbound";
			this->button_SendPacket->UseVisualStyleBackColor = true;
			this->button_SendPacket->Click += gcnew System::EventHandler(this, &MainForm::button_SendPacket_Click);
			// 
			// textBox_SendPacketInput
			// 
			this->textBox_SendPacketInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox_SendPacketInput->Location = System::Drawing::Point(108, 503);
			this->textBox_SendPacketInput->Margin = System::Windows::Forms::Padding(1, 2, 1, 2);
			this->textBox_SendPacketInput->Name = L"textBox_SendPacketInput";
			this->textBox_SendPacketInput->Size = System::Drawing::Size(578, 20);
			this->textBox_SendPacketInput->TabIndex = 19;
			this->textBox_SendPacketInput->Text = L"Packet to Send...";
			// 
			// checkBox_LogSendPacket
			// 
			this->checkBox_LogSendPacket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->checkBox_LogSendPacket->AutoSize = true;
			this->checkBox_LogSendPacket->Location = System::Drawing::Point(7, 489);
			this->checkBox_LogSendPacket->Margin = System::Windows::Forms::Padding(1, 2, 1, 2);
			this->checkBox_LogSendPacket->Name = L"checkBox_LogSendPacket";
			this->checkBox_LogSendPacket->Size = System::Drawing::Size(94, 17);
			this->checkBox_LogSendPacket->TabIndex = 3;
			this->checkBox_LogSendPacket->Text = L"Log Outbound";
			this->checkBox_LogSendPacket->UseVisualStyleBackColor = true;
			this->checkBox_LogSendPacket->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox_LogSendPacket_CheckedChanged);
			// 
			// listView_Packets
			// 
			this->listView_Packets->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listView_Packets->AutoArrange = false;
			this->listView_Packets->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->listView_Packets->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->columnHeader_Direction,
					this->columnHeader_SPLength, this->columnHeader_SPOpcode, this->columnHeader_SPData
			});
			this->listView_Packets->ContextMenuStrip = this->contextMenuStrip_Packets;
			this->listView_Packets->FullRowSelect = true;
			this->listView_Packets->GridLines = true;
			this->listView_Packets->Location = System::Drawing::Point(4, 0);
			this->listView_Packets->Margin = System::Windows::Forms::Padding(1, 2, 1, 2);
			this->listView_Packets->Name = L"listView_Packets";
			this->listView_Packets->Size = System::Drawing::Size(747, 436);
			this->listView_Packets->TabIndex = 1;
			this->listView_Packets->UseCompatibleStateImageBehavior = false;
			this->listView_Packets->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader_Direction
			// 
			this->columnHeader_Direction->Text = L"S/R";
			this->columnHeader_Direction->Width = 34;
			// 
			// columnHeader_SPLength
			// 
			this->columnHeader_SPLength->Tag = L"";
			this->columnHeader_SPLength->Text = L"Length";
			this->columnHeader_SPLength->Width = 45;
			// 
			// columnHeader_SPOpcode
			// 
			this->columnHeader_SPOpcode->Text = L"Opcode";
			this->columnHeader_SPOpcode->Width = 50;
			// 
			// columnHeader_SPData
			// 
			this->columnHeader_SPData->Text = L"Data";
			this->columnHeader_SPData->Width = 874;
			// 
			// contextMenuStrip_Packets
			// 
			this->contextMenuStrip_Packets->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->copyToolStripMenuItem,
					this->clearAllToolStripMenuItem, this->blockOpcodeToolStripMenuItem, this->ignoreOpcodeToolStripMenuItem, this->findToolStripMenuItem
			});
			this->contextMenuStrip_Packets->Name = L"contextMenuStrip_Packets";
			this->contextMenuStrip_Packets->Size = System::Drawing::Size(154, 114);
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->copyToolStripMenuItem->Text = L"Copy";
			this->copyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::copyToolStripMenuItem_Click);
			// 
			// clearAllToolStripMenuItem
			// 
			this->clearAllToolStripMenuItem->Name = L"clearAllToolStripMenuItem";
			this->clearAllToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->clearAllToolStripMenuItem->Text = L"Clear All";
			this->clearAllToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::clearAllToolStripMenuItem_Click);
			// 
			// blockOpcodeToolStripMenuItem
			// 
			this->blockOpcodeToolStripMenuItem->Name = L"blockOpcodeToolStripMenuItem";
			this->blockOpcodeToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->blockOpcodeToolStripMenuItem->Text = L"Block Opcode";
			// 
			// ignoreOpcodeToolStripMenuItem
			// 
			this->ignoreOpcodeToolStripMenuItem->Name = L"ignoreOpcodeToolStripMenuItem";
			this->ignoreOpcodeToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->ignoreOpcodeToolStripMenuItem->Text = L"Ignore Opcode";
			// 
			// findToolStripMenuItem
			// 
			this->findToolStripMenuItem->Name = L"findToolStripMenuItem";
			this->findToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->findToolStripMenuItem->Text = L"Find";
			// 
			// tabPage_Hacks
			// 
			this->tabPage_Hacks->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage_Hacks->Controls->Add(this->groupBox_Hacks);
			this->tabPage_Hacks->Controls->Add(this->groupBox_CharInfo);
			this->tabPage_Hacks->Controls->Add(this->groupBox1);
			this->tabPage_Hacks->Location = System::Drawing::Point(4, 22);
			this->tabPage_Hacks->Name = L"tabPage_Hacks";
			this->tabPage_Hacks->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_Hacks->Size = System::Drawing::Size(755, 530);
			this->tabPage_Hacks->TabIndex = 1;
			this->tabPage_Hacks->Text = L"Hacks";
			// 
			// groupBox_Hacks
			// 
			this->groupBox_Hacks->Controls->Add(this->groupBox4);
			this->groupBox_Hacks->Controls->Add(this->groupBox_MountExploit);
			this->groupBox_Hacks->Controls->Add(this->groupBox2);
			this->groupBox_Hacks->Location = System::Drawing::Point(286, 6);
			this->groupBox_Hacks->Name = L"groupBox_Hacks";
			this->groupBox_Hacks->Size = System::Drawing::Size(463, 520);
			this->groupBox_Hacks->TabIndex = 3;
			this->groupBox_Hacks->TabStop = false;
			this->groupBox_Hacks->Text = L"Options";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button2);
			this->groupBox4->Controls->Add(this->button1);
			this->groupBox4->Controls->Add(this->button_SetX);
			this->groupBox4->Controls->Add(this->button_SetCoordinates);
			this->groupBox4->Controls->Add(this->numericUpDown_Z);
			this->groupBox4->Controls->Add(this->numericUpDown_Y);
			this->groupBox4->Controls->Add(this->numericUpDown_X);
			this->groupBox4->Controls->Add(this->checkBox_HookPlayerPosition);
			this->groupBox4->Location = System::Drawing::Point(14, 219);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(245, 197);
			this->groupBox4->TabIndex = 5;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Movement, Teleporter";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(134, 114);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(102, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Set";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(134, 85);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Set";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button_SetX
			// 
			this->button_SetX->Location = System::Drawing::Point(134, 56);
			this->button_SetX->Name = L"button_SetX";
			this->button_SetX->Size = System::Drawing::Size(102, 23);
			this->button_SetX->TabIndex = 5;
			this->button_SetX->Text = L"Set";
			this->button_SetX->UseVisualStyleBackColor = true;
			// 
			// button_SetCoordinates
			// 
			this->button_SetCoordinates->Location = System::Drawing::Point(6, 157);
			this->button_SetCoordinates->Name = L"button_SetCoordinates";
			this->button_SetCoordinates->Size = System::Drawing::Size(230, 23);
			this->button_SetCoordinates->TabIndex = 4;
			this->button_SetCoordinates->Text = L"Set Coordinates";
			this->button_SetCoordinates->UseVisualStyleBackColor = true;
			// 
			// numericUpDown_Z
			// 
			this->numericUpDown_Z->DecimalPlaces = 2;
			this->numericUpDown_Z->Location = System::Drawing::Point(7, 115);
			this->numericUpDown_Z->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000000, 0, 0, 0 });
			this->numericUpDown_Z->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500000, 0, 0, System::Int32::MinValue });
			this->numericUpDown_Z->Name = L"numericUpDown_Z";
			this->numericUpDown_Z->Size = System::Drawing::Size(120, 20);
			this->numericUpDown_Z->TabIndex = 3;
			// 
			// numericUpDown_Y
			// 
			this->numericUpDown_Y->DecimalPlaces = 2;
			this->numericUpDown_Y->Location = System::Drawing::Point(7, 88);
			this->numericUpDown_Y->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000000, 0, 0, 0 });
			this->numericUpDown_Y->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500000, 0, 0, System::Int32::MinValue });
			this->numericUpDown_Y->Name = L"numericUpDown_Y";
			this->numericUpDown_Y->Size = System::Drawing::Size(120, 20);
			this->numericUpDown_Y->TabIndex = 2;
			// 
			// numericUpDown_X
			// 
			this->numericUpDown_X->DecimalPlaces = 2;
			this->numericUpDown_X->Location = System::Drawing::Point(7, 57);
			this->numericUpDown_X->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000000, 0, 0, 0 });
			this->numericUpDown_X->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500000, 0, 0, System::Int32::MinValue });
			this->numericUpDown_X->Name = L"numericUpDown_X";
			this->numericUpDown_X->Size = System::Drawing::Size(120, 20);
			this->numericUpDown_X->TabIndex = 1;
			// 
			// checkBox_HookPlayerPosition
			// 
			this->checkBox_HookPlayerPosition->AutoSize = true;
			this->checkBox_HookPlayerPosition->Location = System::Drawing::Point(8, 29);
			this->checkBox_HookPlayerPosition->Name = L"checkBox_HookPlayerPosition";
			this->checkBox_HookPlayerPosition->Size = System::Drawing::Size(124, 17);
			this->checkBox_HookPlayerPosition->TabIndex = 0;
			this->checkBox_HookPlayerPosition->Text = L"Hook Player Position";
			this->checkBox_HookPlayerPosition->UseVisualStyleBackColor = true;
			// 
			// groupBox_MountExploit
			// 
			this->groupBox_MountExploit->Controls->Add(this->button_MountExploit);
			this->groupBox_MountExploit->Controls->Add(this->comboBox_MountExploit);
			this->groupBox_MountExploit->Location = System::Drawing::Point(14, 154);
			this->groupBox_MountExploit->Name = L"groupBox_MountExploit";
			this->groupBox_MountExploit->Size = System::Drawing::Size(265, 59);
			this->groupBox_MountExploit->TabIndex = 4;
			this->groupBox_MountExploit->TabStop = false;
			this->groupBox_MountExploit->Text = L"Mount Exploit";
			// 
			// button_MountExploit
			// 
			this->button_MountExploit->Location = System::Drawing::Point(182, 19);
			this->button_MountExploit->Name = L"button_MountExploit";
			this->button_MountExploit->Size = System::Drawing::Size(75, 23);
			this->button_MountExploit->TabIndex = 1;
			this->button_MountExploit->Text = L"Set Mount";
			this->button_MountExploit->UseVisualStyleBackColor = true;
			// 
			// comboBox_MountExploit
			// 
			this->comboBox_MountExploit->FormattingEnabled = true;
			this->comboBox_MountExploit->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Brown Horse", L"Hell Horse", L"White Horse",
					L"Ebony Horse", L""
			});
			this->comboBox_MountExploit->Location = System::Drawing::Point(8, 21);
			this->comboBox_MountExploit->Name = L"comboBox_MountExploit";
			this->comboBox_MountExploit->Size = System::Drawing::Size(168, 21);
			this->comboBox_MountExploit->TabIndex = 0;
			this->comboBox_MountExploit->Text = L"Hell Horse";
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::Transparent;
			this->groupBox2->Controls->Add(this->label_Unrandom);
			this->groupBox2->Controls->Add(this->numericUpDown_RandValue);
			this->groupBox2->Controls->Add(this->checkBox_Unrandomizer);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->numericUpDown_CPUReducerTime);
			this->groupBox2->Controls->Add(this->checkBox_StopRender);
			this->groupBox2->Controls->Add(this->checkBox_ReduceCPU);
			this->groupBox2->Controls->Add(this->checkBox_RAMReduce);
			this->groupBox2->ForeColor = System::Drawing::Color::Black;
			this->groupBox2->Location = System::Drawing::Point(14, 19);
			this->groupBox2->Margin = System::Windows::Forms::Padding(1, 2, 1, 2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(1, 2, 1, 2);
			this->groupBox2->Size = System::Drawing::Size(265, 130);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Resources";
			// 
			// label_Unrandom
			// 
			this->label_Unrandom->AutoSize = true;
			this->label_Unrandom->Location = System::Drawing::Point(168, 87);
			this->label_Unrandom->Name = L"label_Unrandom";
			this->label_Unrandom->Size = System::Drawing::Size(37, 13);
			this->label_Unrandom->TabIndex = 6;
			this->label_Unrandom->Text = L"Value:";
			// 
			// numericUpDown_RandValue
			// 
			this->numericUpDown_RandValue->Location = System::Drawing::Point(208, 83);
			this->numericUpDown_RandValue->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1410065408, 2, 0, 0 });
			this->numericUpDown_RandValue->Name = L"numericUpDown_RandValue";
			this->numericUpDown_RandValue->Size = System::Drawing::Size(50, 20);
			this->numericUpDown_RandValue->TabIndex = 5;
			// 
			// checkBox_Unrandomizer
			// 
			this->checkBox_Unrandomizer->AutoSize = true;
			this->checkBox_Unrandomizer->Location = System::Drawing::Point(6, 86);
			this->checkBox_Unrandomizer->Name = L"checkBox_Unrandomizer";
			this->checkBox_Unrandomizer->Size = System::Drawing::Size(91, 17);
			this->checkBox_Unrandomizer->TabIndex = 4;
			this->checkBox_Unrandomizer->Text = L"Unrandomizer";
			this->checkBox_Unrandomizer->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(131, 43);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(73, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Reducer (ms):";
			// 
			// numericUpDown_CPUReducerTime
			// 
			this->numericUpDown_CPUReducerTime->Location = System::Drawing::Point(207, 41);
			this->numericUpDown_CPUReducerTime->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDown_CPUReducerTime->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_CPUReducerTime->Name = L"numericUpDown_CPUReducerTime";
			this->numericUpDown_CPUReducerTime->Size = System::Drawing::Size(50, 20);
			this->numericUpDown_CPUReducerTime->TabIndex = 3;
			this->numericUpDown_CPUReducerTime->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// checkBox_StopRender
			// 
			this->checkBox_StopRender->AutoSize = true;
			this->checkBox_StopRender->Enabled = false;
			this->checkBox_StopRender->Location = System::Drawing::Point(6, 64);
			this->checkBox_StopRender->Margin = System::Windows::Forms::Padding(1, 2, 1, 2);
			this->checkBox_StopRender->Name = L"checkBox_StopRender";
			this->checkBox_StopRender->Size = System::Drawing::Size(100, 17);
			this->checkBox_StopRender->TabIndex = 2;
			this->checkBox_StopRender->Text = L"Stop Rendering";
			this->checkBox_StopRender->UseVisualStyleBackColor = true;
			// 
			// checkBox_ReduceCPU
			// 
			this->checkBox_ReduceCPU->AutoSize = true;
			this->checkBox_ReduceCPU->Enabled = false;
			this->checkBox_ReduceCPU->Location = System::Drawing::Point(6, 41);
			this->checkBox_ReduceCPU->Margin = System::Windows::Forms::Padding(1, 2, 1, 2);
			this->checkBox_ReduceCPU->Name = L"checkBox_ReduceCPU";
			this->checkBox_ReduceCPU->Size = System::Drawing::Size(123, 17);
			this->checkBox_ReduceCPU->TabIndex = 1;
			this->checkBox_ReduceCPU->Text = L"Reduce CPU Usage";
			this->checkBox_ReduceCPU->UseVisualStyleBackColor = true;
			// 
			// checkBox_RAMReduce
			// 
			this->checkBox_RAMReduce->AutoSize = true;
			this->checkBox_RAMReduce->Location = System::Drawing::Point(6, 19);
			this->checkBox_RAMReduce->Margin = System::Windows::Forms::Padding(1, 2, 1, 2);
			this->checkBox_RAMReduce->Name = L"checkBox_RAMReduce";
			this->checkBox_RAMReduce->Size = System::Drawing::Size(94, 17);
			this->checkBox_RAMReduce->TabIndex = 0;
			this->checkBox_RAMReduce->Text = L"Reduce RAM ";
			this->checkBox_RAMReduce->UseVisualStyleBackColor = true;
			// 
			// groupBox_CharInfo
			// 
			this->groupBox_CharInfo->Controls->Add(this->checkBox_StatsBuff);
			this->groupBox_CharInfo->Controls->Add(this->checkBox_LogDebugMsg);
			this->groupBox_CharInfo->Controls->Add(this->checkBox_DisplayPlayerData);
			this->groupBox_CharInfo->Controls->Add(this->label1);
			this->groupBox_CharInfo->Controls->Add(this->label_GridY);
			this->groupBox_CharInfo->Controls->Add(this->label_Exp);
			this->groupBox_CharInfo->Controls->Add(this->label_PlayerClass);
			this->groupBox_CharInfo->Controls->Add(this->label_GridX);
			this->groupBox_CharInfo->Controls->Add(this->label_Level);
			this->groupBox_CharInfo->Controls->Add(this->label_Status);
			this->groupBox_CharInfo->Controls->Add(this->label_HP);
			this->groupBox_CharInfo->Controls->Add(this->label_MP);
			this->groupBox_CharInfo->Location = System::Drawing::Point(6, 107);
			this->groupBox_CharInfo->Name = L"groupBox_CharInfo";
			this->groupBox_CharInfo->Size = System::Drawing::Size(259, 413);
			this->groupBox_CharInfo->TabIndex = 2;
			this->groupBox_CharInfo->TabStop = false;
			this->groupBox_CharInfo->Text = L"Character Information";
			// 
			// checkBox_StatsBuff
			// 
			this->checkBox_StatsBuff->AutoSize = true;
			this->checkBox_StatsBuff->Location = System::Drawing::Point(6, 276);
			this->checkBox_StatsBuff->Name = L"checkBox_StatsBuff";
			this->checkBox_StatsBuff->Size = System::Drawing::Size(119, 17);
			this->checkBox_StatsBuff->TabIndex = 6;
			this->checkBox_StatsBuff->Text = L"Max Evasion + Crits";
			this->checkBox_StatsBuff->UseVisualStyleBackColor = true;
			// 
			// checkBox_LogDebugMsg
			// 
			this->checkBox_LogDebugMsg->AutoSize = true;
			this->checkBox_LogDebugMsg->Location = System::Drawing::Point(6, 253);
			this->checkBox_LogDebugMsg->Name = L"checkBox_LogDebugMsg";
			this->checkBox_LogDebugMsg->Size = System::Drawing::Size(124, 17);
			this->checkBox_LogDebugMsg->TabIndex = 6;
			this->checkBox_LogDebugMsg->Text = L"Log Client Messages";
			this->checkBox_LogDebugMsg->UseVisualStyleBackColor = true;
			// 
			// checkBox_DisplayPlayerData
			// 
			this->checkBox_DisplayPlayerData->AutoSize = true;
			this->checkBox_DisplayPlayerData->Location = System::Drawing::Point(105, 25);
			this->checkBox_DisplayPlayerData->Margin = System::Windows::Forms::Padding(1, 4, 1, 4);
			this->checkBox_DisplayPlayerData->Name = L"checkBox_DisplayPlayerData";
			this->checkBox_DisplayPlayerData->Size = System::Drawing::Size(147, 17);
			this->checkBox_DisplayPlayerData->TabIndex = 3;
			this->checkBox_DisplayPlayerData->Text = L"Display Local Player Data";
			this->checkBox_DisplayPlayerData->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 224);
			this->label1->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 13);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Z: ";
			// 
			// label_GridY
			// 
			this->label_GridY->AutoSize = true;
			this->label_GridY->Location = System::Drawing::Point(8, 199);
			this->label_GridY->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->label_GridY->Name = L"label_GridY";
			this->label_GridY->Size = System::Drawing::Size(17, 13);
			this->label_GridY->TabIndex = 13;
			this->label_GridY->Text = L"Y:";
			// 
			// label_Exp
			// 
			this->label_Exp->AutoSize = true;
			this->label_Exp->Location = System::Drawing::Point(6, 147);
			this->label_Exp->Name = L"label_Exp";
			this->label_Exp->Size = System::Drawing::Size(66, 13);
			this->label_Exp->TabIndex = 19;
			this->label_Exp->Text = L"Experience: ";
			// 
			// label_PlayerClass
			// 
			this->label_PlayerClass->AutoSize = true;
			this->label_PlayerClass->Location = System::Drawing::Point(7, 99);
			this->label_PlayerClass->Name = L"label_PlayerClass";
			this->label_PlayerClass->Size = System::Drawing::Size(38, 13);
			this->label_PlayerClass->TabIndex = 20;
			this->label_PlayerClass->Text = L"Class: ";
			// 
			// label_GridX
			// 
			this->label_GridX->AutoSize = true;
			this->label_GridX->Location = System::Drawing::Point(8, 176);
			this->label_GridX->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->label_GridX->Name = L"label_GridX";
			this->label_GridX->Size = System::Drawing::Size(20, 13);
			this->label_GridX->TabIndex = 12;
			this->label_GridX->Text = L"X: ";
			// 
			// label_Level
			// 
			this->label_Level->AutoSize = true;
			this->label_Level->Location = System::Drawing::Point(7, 123);
			this->label_Level->Name = L"label_Level";
			this->label_Level->Size = System::Drawing::Size(39, 13);
			this->label_Level->TabIndex = 18;
			this->label_Level->Text = L"Level: ";
			// 
			// label_Status
			// 
			this->label_Status->AutoSize = true;
			this->label_Status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Status->ForeColor = System::Drawing::Color::Maroon;
			this->label_Status->Location = System::Drawing::Point(6, 26);
			this->label_Status->Name = L"label_Status";
			this->label_Status->Size = System::Drawing::Size(79, 13);
			this->label_Status->TabIndex = 18;
			this->label_Status->Text = L"Status: IDLE";
			// 
			// label_HP
			// 
			this->label_HP->AutoSize = true;
			this->label_HP->ForeColor = System::Drawing::Color::DarkRed;
			this->label_HP->Location = System::Drawing::Point(6, 50);
			this->label_HP->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->label_HP->Name = L"label_HP";
			this->label_HP->Size = System::Drawing::Size(44, 13);
			this->label_HP->TabIndex = 4;
			this->label_HP->Text = L"Health: ";
			// 
			// label_MP
			// 
			this->label_MP->AutoSize = true;
			this->label_MP->ForeColor = System::Drawing::Color::Blue;
			this->label_MP->Location = System::Drawing::Point(6, 74);
			this->label_MP->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->label_MP->Name = L"label_MP";
			this->label_MP->Size = System::Drawing::Size(40, 13);
			this->label_MP->TabIndex = 5;
			this->label_MP->Text = L"Mana: ";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkBox_IncreaseAcceleration);
			this->groupBox1->Controls->Add(this->numericUpDown_Speed);
			this->groupBox1->Controls->Add(this->checkBox_SetGameSpeed);
			this->groupBox1->Location = System::Drawing::Point(6, 6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(189, 95);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Speed Hacks";
			// 
			// checkBox_IncreaseAcceleration
			// 
			this->checkBox_IncreaseAcceleration->AutoSize = true;
			this->checkBox_IncreaseAcceleration->Location = System::Drawing::Point(6, 42);
			this->checkBox_IncreaseAcceleration->Name = L"checkBox_IncreaseAcceleration";
			this->checkBox_IncreaseAcceleration->Size = System::Drawing::Size(148, 17);
			this->checkBox_IncreaseAcceleration->TabIndex = 6;
			this->checkBox_IncreaseAcceleration->Text = L"Fast Movement Recovery";
			this->checkBox_IncreaseAcceleration->UseVisualStyleBackColor = true;
			// 
			// numericUpDown_Speed
			// 
			this->numericUpDown_Speed->DecimalPlaces = 3;
			this->numericUpDown_Speed->Location = System::Drawing::Point(100, 16);
			this->numericUpDown_Speed->Name = L"numericUpDown_Speed";
			this->numericUpDown_Speed->Size = System::Drawing::Size(65, 20);
			this->numericUpDown_Speed->TabIndex = 2;
			this->numericUpDown_Speed->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// checkBox_SetGameSpeed
			// 
			this->checkBox_SetGameSpeed->AutoSize = true;
			this->checkBox_SetGameSpeed->Location = System::Drawing::Point(6, 19);
			this->checkBox_SetGameSpeed->Name = L"checkBox_SetGameSpeed";
			this->checkBox_SetGameSpeed->Size = System::Drawing::Size(88, 17);
			this->checkBox_SetGameSpeed->TabIndex = 0;
			this->checkBox_SetGameSpeed->Text = L"Game Speed";
			this->checkBox_SetGameSpeed->UseVisualStyleBackColor = true;
			// 
			// tabPage_Scripting
			// 
			this->tabPage_Scripting->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage_Scripting->Controls->Add(this->groupBox3);
			this->tabPage_Scripting->Controls->Add(this->textBox_ScriptText);
			this->tabPage_Scripting->Location = System::Drawing::Point(4, 22);
			this->tabPage_Scripting->Name = L"tabPage_Scripting";
			this->tabPage_Scripting->Size = System::Drawing::Size(755, 530);
			this->tabPage_Scripting->TabIndex = 2;
			this->tabPage_Scripting->Text = L"Scripting";
			// 
			// groupBox3
			// 
			this->groupBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->groupBox3->BackColor = System::Drawing::Color::Transparent;
			this->groupBox3->Controls->Add(this->checkBox_RepeatScript);
			this->groupBox3->Controls->Add(this->checkBox_RandomizingLUAName);
			this->groupBox3->Controls->Add(this->button_DownloadLUA);
			this->groupBox3->Controls->Add(this->button_LoadLUA);
			this->groupBox3->Controls->Add(this->button_SaveLUA);
			this->groupBox3->Controls->Add(this->button_RunLUA);
			this->groupBox3->Controls->Add(this->button_StopLUA);
			this->groupBox3->Location = System::Drawing::Point(3, 454);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(749, 72);
			this->groupBox3->TabIndex = 17;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Scripting Menu";
			// 
			// checkBox_RepeatScript
			// 
			this->checkBox_RepeatScript->AutoSize = true;
			this->checkBox_RepeatScript->Location = System::Drawing::Point(516, 50);
			this->checkBox_RepeatScript->Name = L"checkBox_RepeatScript";
			this->checkBox_RepeatScript->Size = System::Drawing::Size(80, 17);
			this->checkBox_RepeatScript->TabIndex = 20;
			this->checkBox_RepeatScript->Text = L"Loop Script";
			this->checkBox_RepeatScript->UseVisualStyleBackColor = true;
			// 
			// checkBox_RandomizingLUAName
			// 
			this->checkBox_RandomizingLUAName->AutoSize = true;
			this->checkBox_RandomizingLUAName->Location = System::Drawing::Point(603, 49);
			this->checkBox_RandomizingLUAName->Name = L"checkBox_RandomizingLUAName";
			this->checkBox_RandomizingLUAName->Size = System::Drawing::Size(140, 17);
			this->checkBox_RandomizingLUAName->TabIndex = 19;
			this->checkBox_RandomizingLUAName->Text = L"Randomize Script Name";
			this->checkBox_RandomizingLUAName->UseVisualStyleBackColor = true;
			// 
			// button_DownloadLUA
			// 
			this->button_DownloadLUA->BackColor = System::Drawing::Color::Transparent;
			this->button_DownloadLUA->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_DownloadLUA.BackgroundImage")));
			this->button_DownloadLUA->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button_DownloadLUA->Enabled = false;
			this->button_DownloadLUA->Location = System::Drawing::Point(263, 19);
			this->button_DownloadLUA->Name = L"button_DownloadLUA";
			this->button_DownloadLUA->Size = System::Drawing::Size(52, 47);
			this->button_DownloadLUA->TabIndex = 18;
			this->button_DownloadLUA->UseVisualStyleBackColor = false;
			// 
			// button_LoadLUA
			// 
			this->button_LoadLUA->BackColor = System::Drawing::Color::Transparent;
			this->button_LoadLUA->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_LoadLUA.BackgroundImage")));
			this->button_LoadLUA->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button_LoadLUA->Location = System::Drawing::Point(201, 20);
			this->button_LoadLUA->Name = L"button_LoadLUA";
			this->button_LoadLUA->Size = System::Drawing::Size(50, 46);
			this->button_LoadLUA->TabIndex = 17;
			this->button_LoadLUA->UseVisualStyleBackColor = false;
			// 
			// button_SaveLUA
			// 
			this->button_SaveLUA->BackColor = System::Drawing::Color::Transparent;
			this->button_SaveLUA->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_SaveLUA.BackgroundImage")));
			this->button_SaveLUA->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button_SaveLUA->Location = System::Drawing::Point(137, 20);
			this->button_SaveLUA->Name = L"button_SaveLUA";
			this->button_SaveLUA->Size = System::Drawing::Size(53, 46);
			this->button_SaveLUA->TabIndex = 16;
			this->button_SaveLUA->UseVisualStyleBackColor = false;
			// 
			// button_RunLUA
			// 
			this->button_RunLUA->BackColor = System::Drawing::Color::Transparent;
			this->button_RunLUA->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_RunLUA.BackgroundImage")));
			this->button_RunLUA->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button_RunLUA->Location = System::Drawing::Point(10, 20);
			this->button_RunLUA->Name = L"button_RunLUA";
			this->button_RunLUA->Size = System::Drawing::Size(52, 46);
			this->button_RunLUA->TabIndex = 14;
			this->button_RunLUA->UseVisualStyleBackColor = false;
			// 
			// button_StopLUA
			// 
			this->button_StopLUA->BackColor = System::Drawing::Color::Transparent;
			this->button_StopLUA->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_StopLUA.BackgroundImage")));
			this->button_StopLUA->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button_StopLUA->Location = System::Drawing::Point(74, 20);
			this->button_StopLUA->Name = L"button_StopLUA";
			this->button_StopLUA->Size = System::Drawing::Size(50, 46);
			this->button_StopLUA->TabIndex = 15;
			this->button_StopLUA->UseVisualStyleBackColor = false;
			// 
			// textBox_ScriptText
			// 
			this->textBox_ScriptText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_ScriptText->BackColor = System::Drawing::Color::White;
			this->textBox_ScriptText->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_ScriptText->Location = System::Drawing::Point(1, 2);
			this->textBox_ScriptText->Margin = System::Windows::Forms::Padding(1, 2, 1, 2);
			this->textBox_ScriptText->Multiline = true;
			this->textBox_ScriptText->Name = L"textBox_ScriptText";
			this->textBox_ScriptText->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_ScriptText->Size = System::Drawing::Size(753, 447);
			this->textBox_ScriptText->TabIndex = 5;
			this->textBox_ScriptText->Text = L"Enter Script...";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(787, 580);
			this->Controls->Add(this->tabControl1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->Text = L"Honor of Heirs Packet Editor (AlSch092 @ Github)";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage_Packets->ResumeLayout(false);
			this->tabPage_Packets->PerformLayout();
			this->contextMenuStrip_Packets->ResumeLayout(false);
			this->tabPage_Hacks->ResumeLayout(false);
			this->groupBox_Hacks->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Z))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Y))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_X))->EndInit();
			this->groupBox_MountExploit->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_RandValue))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CPUReducerTime))->EndInit();
			this->groupBox_CharInfo->ResumeLayout(false);
			this->groupBox_CharInfo->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Speed))->EndInit();
			this->tabPage_Scripting->ResumeLayout(false);
			this->tabPage_Scripting->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		private: System::Void ProcessSendQueue() {

			if (SendPacketQueue.size() > 0)
			{
				for (int i = 0; i < SendPacketQueue.size(); i++)
				{
					SendPacketQueue.pop();
				}
			}

			while (g_LoggingSendPackets)
			{
				if (SendPacketQueue.size() > 0)
				{
					PacketWriter* sendPacket = SendPacketQueue.front();

					if (sendPacket == NULL)
					{
						SendPacketQueue.pop();
						continue;
					}

					wchar_t pwDataText[4096] = { 0 };
					wchar_t pwLengthText[10];
					wchar_t pwOpcodeText[10];
					DWORD dataSize = 0; //subtract 4 for length

					LPBYTE pBuffer = (LPBYTE)sendPacket->GetBuffer();
					LPBYTE pData = (LPBYTE)sendPacket->GetBuffer() + 2;

					//gets full packet as string
					std::string packetString = PacketHelper::ToString(pData, sendPacket->GetSize() - 2);

					if (DereferenceSafe<uint16_t>((UINT64)pBuffer) != NULL)
					{
						memcpy(&dataSize, (void*)&pBuffer[0], sizeof(uint16_t)); //size of opcode + data (length not inclusive)
					}

					if (sendPacket->GetSize() < 4 || dataSize > 4096 || dataSize < 4) //bad case, clean object and move on
					{
						SendPacketQueue.pop();
						//delete[] sendPacket->GetBuffer();
						//delete sendPacket;
						continue;
					}

					_itow_s(dataSize, pwLengthText, 10); //set LENGTH text

					DWORD dwNum = MultiByteToWideChar(CP_UTF8, 0, packetString.c_str(), -1, NULL, 0);
					MultiByteToWideChar(CP_UTF8, 0, packetString.c_str(), -1, pwDataText, dwNum); //set data text

					pwOpcodeText[0] = pwDataText[0]; 
					pwOpcodeText[1] = pwDataText[1]; 
					pwOpcodeText[2] = pwDataText[2];
					pwOpcodeText[3] = pwDataText[3];
					pwOpcodeText[4] = pwDataText[4];
					pwOpcodeText[5] = 0x0000;
					
					cli::array<String^>^ subItems = gcnew cli::array<String^>(4);
					subItems[0] = gcnew String("S");
					subItems[1] = gcnew String(pwLengthText);
					subItems[2] = gcnew String(pwOpcodeText);
					subItems[3] = gcnew String(pwDataText);

					ListViewItem^ itm = gcnew ListViewItem(subItems);
					listView_Packets->Items->Add(itm);

					SendPacketQueue.pop();

					if (g_StreamingPacketsToFile)
					{
						PacketHelper::WriteToFile(sendPacket, L"send_out.txt", TRUE);
					}

					//delete[] sendPacket->GetBuffer();
					//delete sendPacket; //these fucking crash, no idea why. does pop() free them too??

				}
				else
					Thread::Sleep(100);
			}
		}

	private: System::Void checkBox_LogSendPacket_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		UINT64 HoHAddress = (UINT64)GetModuleHandleA(NULL);

		if (checkBox_LogSendPacket->Checked)
		{
			if (HoHAddress)
			{
				Hooks::InstallHook((void*)(g_LogSendPacketReturnAddress - 5), EncryptSendPacketHook);

				g_LoggingSendPackets = TRUE;

				SendPacketThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::ProcessSendQueue));
				SendPacketThread->Start();
			}
		}
		else
		{
			Hooks::RemoveHook((g_LogSendPacketReturnAddress - 5), 5,  (BYTE*)"\x4C\x89\x4c\x24\x20");

			g_LoggingSendPackets = FALSE;
			SendPacketThread->Abort();
			SendPacketThread = nullptr;
		}

	}
private: System::Void copySendPacket()
{
	ListViewItem^ selectedItem;

	for (int i = 0; i < listView_Packets->Items->Count; i++)
	{
		selectedItem = listView_Packets->Items[i];

		if (selectedItem != nullptr) //weird one-off crash
		{
			if (selectedItem->Selected == true)
			{
				String^ packetString = selectedItem->SubItems[3]->Text;
				Clipboard::SetDataObject(packetString, true);
			}
		}
	}
}

private: System::Void copyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Thread^ newThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::copySendPacket));
	newThread->SetApartmentState(System::Threading::ApartmentState::STA);
	newThread->Start();
}
private: System::Void clearAllToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->listView_Packets->Items->Clear();
}
private: System::Void button_SendPacket_Click(System::Object^  sender, System::EventArgs^  e) {

	String^ s_packet = gcnew String(this->textBox_SendPacketInput->Text);
	pin_ptr<const wchar_t> wch = PtrToStringChars(s_packet); //vcclr.h
	
	int len = ((s_packet->Length + 1) * 2);
	char* target = new char[len];
	wcstombs(target, wch, len);

	BYTE* Packet = PacketHelper::ToPacketFormat(target);

	if (Packet == NULL)
	{
		printf("Couldn't parse packet into packet format!\n");
		delete[] target;
		return;
	}

	int length = PacketHelper::GetPacketLength(target);

	if (PacketBuilder::EncryptPacket((LPVOID)g_SendKeyPtr, &Packet[0], length) != 0x10)
	{
		BYTE* bPacketWithHeader = new BYTE[length + 2];
		memcpy((void*)bPacketWithHeader, (void*)&length, sizeof(uint16_t));
		memcpy((void*)&bPacketWithHeader[2], (void*)Packet, sizeof(byte)*length);

		SOCKET s = 0xEF0;

		int bytesSent = send(s, (const char*)bPacketWithHeader, length + 2, 0);

		delete[] bPacketWithHeader;
	}

}
private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
	
	UINT64 HoHAddress = (UINT64)GetModuleHandleA(NULL);

	g_LogSendPacketReturnAddress = HoHAddress + Offsets::EncryptPacket + 5;
	g_LogSendPacketCallback = (UINT64)PacketHelper::CreatePacket;

	Hooks::InstallHook((void*)(g_LogSendPacketReturnAddress - 5), EncryptSendPacketHook);
}
};
}
