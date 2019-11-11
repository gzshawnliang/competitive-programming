namespace CFHelperUI
{
    partial class frmCFHelper
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
            this.txtProblemId = new System.Windows.Forms.TextBox();
            this.butGo = new System.Windows.Forms.Button();
            this.listView1 = new System.Windows.Forms.ListView();
            this.butOK = new System.Windows.Forms.Button();
            this.butCancel = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.lblContest = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.txtWorkingDir = new System.Windows.Forms.TextBox();
            this.butBrowse = new System.Windows.Forms.Button();
            this.folderBrowserDialog1 = new System.Windows.Forms.FolderBrowserDialog();
            this.SuspendLayout();
            // 
            // txtProblemId
            // 
            this.txtProblemId.Location = new System.Drawing.Point(133, 38);
            this.txtProblemId.Margin = new System.Windows.Forms.Padding(4);
            this.txtProblemId.Name = "txtProblemId";
            this.txtProblemId.Size = new System.Drawing.Size(376, 26);
            this.txtProblemId.TabIndex = 0;
            this.txtProblemId.KeyDown += new System.Windows.Forms.KeyEventHandler(this.txtProblemId_KeyDown);
            this.txtProblemId.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtProblemId_KeyPress);
            // 
            // butGo
            // 
            this.butGo.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.butGo.Location = new System.Drawing.Point(517, 37);
            this.butGo.Margin = new System.Windows.Forms.Padding(4);
            this.butGo.Name = "butGo";
            this.butGo.Size = new System.Drawing.Size(100, 28);
            this.butGo.TabIndex = 1;
            this.butGo.Text = "Go";
            this.butGo.UseVisualStyleBackColor = true;
            this.butGo.Click += new System.EventHandler(this.butGo_Click);
            // 
            // listView1
            // 
            this.listView1.Activation = System.Windows.Forms.ItemActivation.OneClick;
            this.listView1.CheckBoxes = true;
            this.listView1.FullRowSelect = true;
            this.listView1.GridLines = true;
            this.listView1.HideSelection = false;
            this.listView1.HotTracking = true;
            this.listView1.HoverSelection = true;
            this.listView1.Location = new System.Drawing.Point(133, 72);
            this.listView1.Margin = new System.Windows.Forms.Padding(4);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(376, 261);
            this.listView1.TabIndex = 2;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.View = System.Windows.Forms.View.Details;
            // 
            // butOK
            // 
            this.butOK.Location = new System.Drawing.Point(409, 399);
            this.butOK.Margin = new System.Windows.Forms.Padding(4);
            this.butOK.Name = "butOK";
            this.butOK.Size = new System.Drawing.Size(100, 31);
            this.butOK.TabIndex = 3;
            this.butOK.Text = "OK";
            this.butOK.UseVisualStyleBackColor = true;
            this.butOK.Click += new System.EventHandler(this.butOK_Click);
            // 
            // butCancel
            // 
            this.butCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.butCancel.Location = new System.Drawing.Point(517, 399);
            this.butCancel.Margin = new System.Windows.Forms.Padding(4);
            this.butCancel.Name = "butCancel";
            this.butCancel.Size = new System.Drawing.Size(100, 31);
            this.butCancel.TabIndex = 4;
            this.butCancel.Text = "Quit";
            this.butCancel.UseVisualStyleBackColor = true;
            this.butCancel.Click += new System.EventHandler(this.butCancel_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Location = new System.Drawing.Point(16, 41);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(80, 16);
            this.label1.TabIndex = 5;
            this.label1.Text = "problemId";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.Location = new System.Drawing.Point(16, 72);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(72, 16);
            this.label2.TabIndex = 6;
            this.label2.Text = "problems";
            // 
            // lblContest
            // 
            this.lblContest.AutoSize = true;
            this.lblContest.BackColor = System.Drawing.Color.Transparent;
            this.lblContest.Font = new System.Drawing.Font("SimSun", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lblContest.ForeColor = System.Drawing.Color.Maroon;
            this.lblContest.Location = new System.Drawing.Point(16, 9);
            this.lblContest.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblContest.Name = "lblContest";
            this.lblContest.Size = new System.Drawing.Size(359, 16);
            this.lblContest.TabIndex = 7;
            this.lblContest.Text = "Input the Codeforces problemId, please ";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.Color.Transparent;
            this.label3.Location = new System.Drawing.Point(16, 341);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(96, 16);
            this.label3.TabIndex = 9;
            this.label3.Text = "Working Dir";
            // 
            // txtWorkingDir
            // 
            this.txtWorkingDir.Font = new System.Drawing.Font("SimSun", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.txtWorkingDir.ForeColor = System.Drawing.Color.Maroon;
            this.txtWorkingDir.Location = new System.Drawing.Point(133, 341);
            this.txtWorkingDir.Margin = new System.Windows.Forms.Padding(4);
            this.txtWorkingDir.Name = "txtWorkingDir";
            this.txtWorkingDir.ReadOnly = true;
            this.txtWorkingDir.Size = new System.Drawing.Size(376, 21);
            this.txtWorkingDir.TabIndex = 8;
            // 
            // butBrowse
            // 
            this.butBrowse.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.butBrowse.Location = new System.Drawing.Point(517, 337);
            this.butBrowse.Margin = new System.Windows.Forms.Padding(4);
            this.butBrowse.Name = "butBrowse";
            this.butBrowse.Size = new System.Drawing.Size(100, 29);
            this.butBrowse.TabIndex = 10;
            this.butBrowse.Text = "Browse";
            this.butBrowse.UseVisualStyleBackColor = true;
            this.butBrowse.Click += new System.EventHandler(this.butBrowse_Click);
            // 
            // frmCFHelper
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.butCancel;
            this.ClientSize = new System.Drawing.Size(624, 441);
            this.Controls.Add(this.butBrowse);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.txtWorkingDir);
            this.Controls.Add(this.lblContest);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.butCancel);
            this.Controls.Add(this.butOK);
            this.Controls.Add(this.listView1);
            this.Controls.Add(this.butGo);
            this.Controls.Add(this.txtProblemId);
            this.Font = new System.Drawing.Font("SimSun", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Margin = new System.Windows.Forms.Padding(4);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmCFHelper";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "CFHelper";
            this.Load += new System.EventHandler(this.frmCFHelper_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtProblemId;
        private System.Windows.Forms.Button butGo;
        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.Button butOK;
        private System.Windows.Forms.Button butCancel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label lblContest;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtWorkingDir;
        private System.Windows.Forms.Button butBrowse;
        private System.Windows.Forms.FolderBrowserDialog folderBrowserDialog1;
    }
}

