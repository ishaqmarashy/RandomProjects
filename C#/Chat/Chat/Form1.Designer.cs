namespace Chat
{
    partial class CChat
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
            System.Windows.Forms.Button sendButton;
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.sendTextField = new System.Windows.Forms.TextBox();
            this.flowLayoutPanel2 = new System.Windows.Forms.FlowLayoutPanel();
            this.vScrollBar1 = new System.Windows.Forms.VScrollBar();
            this.connectLabel = new System.Windows.Forms.Label();
            this.flowLayoutPanel3 = new System.Windows.Forms.FlowLayoutPanel();
            this.connectionInfo = new System.Windows.Forms.Label();
            this.textboxLabel = new System.Windows.Forms.Label();
            tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            sendButton = new System.Windows.Forms.Button();
            tableLayoutPanel1.SuspendLayout();
            this.flowLayoutPanel1.SuspendLayout();
            this.flowLayoutPanel2.SuspendLayout();
            this.flowLayoutPanel3.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            tableLayoutPanel1.AutoSize = true;
            tableLayoutPanel1.ColumnCount = 2;
            tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 21.7354F));
            tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 78.2646F));
            tableLayoutPanel1.Controls.Add(this.flowLayoutPanel1, 1, 1);
            tableLayoutPanel1.Controls.Add(this.flowLayoutPanel2, 0, 0);
            tableLayoutPanel1.Controls.Add(this.flowLayoutPanel3, 0, 1);
            tableLayoutPanel1.Controls.Add(this.textboxLabel, 1, 0);
            tableLayoutPanel1.Location = new System.Drawing.Point(12, 12);
            tableLayoutPanel1.Name = "tableLayoutPanel1";
            tableLayoutPanel1.RowCount = 2;
            tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 83.12884F));
            tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 16.87117F));
            tableLayoutPanel1.Size = new System.Drawing.Size(1164, 652);
            tableLayoutPanel1.TabIndex = 0;
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.Controls.Add(this.sendTextField);
            this.flowLayoutPanel1.Controls.Add(sendButton);
            this.flowLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.flowLayoutPanel1.Location = new System.Drawing.Point(256, 545);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(905, 104);
            this.flowLayoutPanel1.TabIndex = 1;
            // 
            // sendTextField
            // 
            this.sendTextField.Location = new System.Drawing.Point(3, 3);
            this.sendTextField.Multiline = true;
            this.sendTextField.Name = "sendTextField";
            this.sendTextField.Size = new System.Drawing.Size(817, 101);
            this.sendTextField.TabIndex = 0;
            // 
            // sendButton
            // 
            sendButton.AutoSize = true;
            sendButton.Location = new System.Drawing.Point(826, 3);
            sendButton.Name = "sendButton";
            sendButton.Size = new System.Drawing.Size(73, 104);
            sendButton.TabIndex = 1;
            sendButton.Text = "SEND";
            sendButton.UseVisualStyleBackColor = true;
            sendButton.Click += new System.EventHandler(this.button1_Click);
            // 
            // flowLayoutPanel2
            // 
            this.flowLayoutPanel2.Controls.Add(this.vScrollBar1);
            this.flowLayoutPanel2.Controls.Add(this.connectLabel);
            this.flowLayoutPanel2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.flowLayoutPanel2.Location = new System.Drawing.Point(3, 3);
            this.flowLayoutPanel2.Name = "flowLayoutPanel2";
            this.flowLayoutPanel2.Size = new System.Drawing.Size(247, 536);
            this.flowLayoutPanel2.TabIndex = 2;
            this.flowLayoutPanel2.Paint += new System.Windows.Forms.PaintEventHandler(this.flowLayoutPanel2_Paint);
            // 
            // vScrollBar1
            // 
            this.vScrollBar1.Location = new System.Drawing.Point(0, 0);
            this.vScrollBar1.Name = "vScrollBar1";
            this.vScrollBar1.Size = new System.Drawing.Size(25, 536);
            this.vScrollBar1.TabIndex = 0;
            // 
            // connectLabel
            // 
            this.connectLabel.Dock = System.Windows.Forms.DockStyle.Top;
            this.connectLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.connectLabel.Location = new System.Drawing.Point(28, 0);
            this.connectLabel.Name = "connectLabel";
            this.connectLabel.Size = new System.Drawing.Size(215, 23);
            this.connectLabel.TabIndex = 1;
            this.connectLabel.Text = "Connect";
            this.connectLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // flowLayoutPanel3
            // 
            this.flowLayoutPanel3.Controls.Add(this.connectionInfo);
            this.flowLayoutPanel3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.flowLayoutPanel3.Location = new System.Drawing.Point(3, 545);
            this.flowLayoutPanel3.Name = "flowLayoutPanel3";
            this.flowLayoutPanel3.Size = new System.Drawing.Size(247, 104);
            this.flowLayoutPanel3.TabIndex = 4;
            // 
            // connectionInfo
            // 
            this.connectionInfo.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.connectionInfo.Location = new System.Drawing.Point(3, 0);
            this.connectionInfo.Name = "connectionInfo";
            this.connectionInfo.Size = new System.Drawing.Size(247, 107);
            this.connectionInfo.TabIndex = 0;
            this.connectionInfo.Text = "Connection Info";
            this.connectionInfo.Click += new System.EventHandler(this.label1_Click_1);
            // 
            // textboxLabel
            // 
            this.textboxLabel.Dock = System.Windows.Forms.DockStyle.Top;
            this.textboxLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textboxLabel.Location = new System.Drawing.Point(256, 0);
            this.textboxLabel.Name = "textboxLabel";
            this.textboxLabel.Size = new System.Drawing.Size(905, 542);
            this.textboxLabel.TabIndex = 5;
            this.textboxLabel.Click += new System.EventHandler(this.textboxLabel_Click);
            // 
            // CChat
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1188, 676);
            this.Controls.Add(tableLayoutPanel1);
            this.Name = "CChat";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            tableLayoutPanel1.ResumeLayout(false);
            this.flowLayoutPanel1.ResumeLayout(false);
            this.flowLayoutPanel1.PerformLayout();
            this.flowLayoutPanel2.ResumeLayout(false);
            this.flowLayoutPanel3.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.TextBox sendTextField;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel2;
        private System.Windows.Forms.VScrollBar vScrollBar1;
        private System.Windows.Forms.Label connectLabel;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel3;
        private System.Windows.Forms.Label connectionInfo;
        private System.Windows.Forms.Label textboxLabel;
    }
}

