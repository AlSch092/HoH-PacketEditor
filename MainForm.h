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
			this->tabControl1->SuspendLayout();
			this->tabPage_Packets->SuspendLayout();
			this->contextMenuStrip_Packets->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage_Packets);
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
			this->listView_Packets->Size = System::Drawing::Size(747, 476);
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
