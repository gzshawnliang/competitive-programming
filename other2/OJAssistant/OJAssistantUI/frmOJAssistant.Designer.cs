namespace OJAssistantUI
{
    partial class frmOJAssistant
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmOJAssistant));
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
            this.label4 = new System.Windows.Forms.Label();
            this.txtAuthor = new System.Windows.Forms.TextBox();
            this.txtError = new System.Windows.Forms.TextBox();
            this.codeforces = new System.Windows.Forms.RadioButton();
            this.uva = new System.Windows.Forms.RadioButton();
            this.usaco = new System.Windows.Forms.RadioButton();
            this.spoj = new System.Windows.Forms.RadioButton();
            this.ural = new System.Windows.Forms.RadioButton();
            this.poj = new System.Windows.Forms.RadioButton();
            this.hdu = new System.Windows.Forms.RadioButton();
            this.label5 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.sourceJava = new System.Windows.Forms.RadioButton();
            this.sourceCpp = new System.Windows.Forms.RadioButton();
            this.emptyCode = new System.Windows.Forms.RadioButton();
            this.panel2 = new System.Windows.Forms.Panel();
            this.picIntelliJOK = new System.Windows.Forms.PictureBox();
            this.chkIntelliJ = new System.Windows.Forms.RadioButton();
            this.chkvscode = new System.Windows.Forms.RadioButton();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picIntelliJOK)).BeginInit();
            this.SuspendLayout();
            // 
            // txtProblemId
            // 
            this.txtProblemId.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txtProblemId.Location = new System.Drawing.Point(130, 81);
            this.txtProblemId.Margin = new System.Windows.Forms.Padding(4);
            this.txtProblemId.Name = "txtProblemId";
            this.txtProblemId.Size = new System.Drawing.Size(754, 26);
            this.txtProblemId.TabIndex = 4;
            this.txtProblemId.KeyDown += new System.Windows.Forms.KeyEventHandler(this.txtProblemId_KeyDown);
            // 
            // butGo
            // 
            this.butGo.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.butGo.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.butGo.Location = new System.Drawing.Point(892, 79);
            this.butGo.Margin = new System.Windows.Forms.Padding(4);
            this.butGo.Name = "butGo";
            this.butGo.Size = new System.Drawing.Size(100, 28);
            this.butGo.TabIndex = 5;
            this.butGo.Text = "Go";
            this.butGo.UseVisualStyleBackColor = true;
            this.butGo.Click += new System.EventHandler(this.butGo_Click);
            // 
            // listView1
            // 
            this.listView1.Activation = System.Windows.Forms.ItemActivation.OneClick;
            this.listView1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.listView1.CheckBoxes = true;
            this.listView1.FullRowSelect = true;
            this.listView1.GridLines = true;
            this.listView1.HideSelection = false;
            this.listView1.HotTracking = true;
            this.listView1.HoverSelection = true;
            this.listView1.Location = new System.Drawing.Point(130, 115);
            this.listView1.Margin = new System.Windows.Forms.Padding(4);
            this.listView1.Name = "listView1";
            this.listView1.OwnerDraw = true;
            this.listView1.Size = new System.Drawing.Size(754, 357);
            this.listView1.TabIndex = 6;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.View = System.Windows.Forms.View.Details;
            this.listView1.ColumnClick += new System.Windows.Forms.ColumnClickEventHandler(this.listView1_ColumnClick);
            this.listView1.DrawColumnHeader += new System.Windows.Forms.DrawListViewColumnHeaderEventHandler(this.listView1_DrawColumnHeader);
            this.listView1.DrawItem += new System.Windows.Forms.DrawListViewItemEventHandler(this.listView1_DrawItem);
            this.listView1.DrawSubItem += new System.Windows.Forms.DrawListViewSubItemEventHandler(this.listView1_DrawSubItem);
            this.listView1.DoubleClick += new System.EventHandler(this.listView1_DoubleClick);
            // 
            // butOK
            // 
            this.butOK.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.butOK.Location = new System.Drawing.Point(786, 549);
            this.butOK.Margin = new System.Windows.Forms.Padding(4);
            this.butOK.Name = "butOK";
            this.butOK.Size = new System.Drawing.Size(100, 31);
            this.butOK.TabIndex = 15;
            this.butOK.Text = "OK";
            this.butOK.UseVisualStyleBackColor = true;
            this.butOK.Click += new System.EventHandler(this.butOK_Click);
            // 
            // butCancel
            // 
            this.butCancel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.butCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.butCancel.Location = new System.Drawing.Point(894, 549);
            this.butCancel.Margin = new System.Windows.Forms.Padding(4);
            this.butCancel.Name = "butCancel";
            this.butCancel.Size = new System.Drawing.Size(100, 31);
            this.butCancel.TabIndex = 16;
            this.butCancel.Text = "Quit";
            this.butCancel.UseVisualStyleBackColor = true;
            this.butCancel.Click += new System.EventHandler(this.butCancel_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Location = new System.Drawing.Point(13, 81);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(80, 16);
            this.label1.TabIndex = 5;
            this.label1.Text = "ProblemId";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.Location = new System.Drawing.Point(13, 114);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(72, 16);
            this.label2.TabIndex = 6;
            this.label2.Text = "Problems";
            // 
            // lblContest
            // 
            this.lblContest.AutoSize = true;
            this.lblContest.BackColor = System.Drawing.Color.Transparent;
            this.lblContest.Font = new System.Drawing.Font("SimSun", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lblContest.ForeColor = System.Drawing.Color.Maroon;
            this.lblContest.Location = new System.Drawing.Point(13, 18);
            this.lblContest.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblContest.Name = "lblContest";
            this.lblContest.Size = new System.Drawing.Size(620, 16);
            this.lblContest.TabIndex = 7;
            this.lblContest.Text = "Input the Codeforces/UVa problemId or USACO URL or SPOJ URL, please ";
            // 
            // label3
            // 
            this.label3.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.Color.Transparent;
            this.label3.Location = new System.Drawing.Point(15, 480);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(96, 16);
            this.label3.TabIndex = 9;
            this.label3.Text = "Working Dir";
            // 
            // txtWorkingDir
            // 
            this.txtWorkingDir.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txtWorkingDir.Font = new System.Drawing.Font("SimSun", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.txtWorkingDir.ForeColor = System.Drawing.Color.Maroon;
            this.txtWorkingDir.Location = new System.Drawing.Point(130, 480);
            this.txtWorkingDir.Margin = new System.Windows.Forms.Padding(4);
            this.txtWorkingDir.Name = "txtWorkingDir";
            this.txtWorkingDir.ReadOnly = true;
            this.txtWorkingDir.Size = new System.Drawing.Size(754, 21);
            this.txtWorkingDir.TabIndex = 8;
            // 
            // butBrowse
            // 
            this.butBrowse.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.butBrowse.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.butBrowse.Location = new System.Drawing.Point(894, 477);
            this.butBrowse.Margin = new System.Windows.Forms.Padding(4);
            this.butBrowse.Name = "butBrowse";
            this.butBrowse.Size = new System.Drawing.Size(100, 29);
            this.butBrowse.TabIndex = 9;
            this.butBrowse.Text = "Browse";
            this.butBrowse.UseVisualStyleBackColor = true;
            this.butBrowse.Click += new System.EventHandler(this.butBrowse_Click);
            // 
            // label4
            // 
            this.label4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.Color.Transparent;
            this.label4.Location = new System.Drawing.Point(15, 513);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(56, 16);
            this.label4.TabIndex = 12;
            this.label4.Text = "Author";
            // 
            // txtAuthor
            // 
            this.txtAuthor.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txtAuthor.Location = new System.Drawing.Point(130, 509);
            this.txtAuthor.Margin = new System.Windows.Forms.Padding(4);
            this.txtAuthor.Name = "txtAuthor";
            this.txtAuthor.Size = new System.Drawing.Size(754, 26);
            this.txtAuthor.TabIndex = 10;
            // 
            // txtError
            // 
            this.txtError.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txtError.Font = new System.Drawing.Font("SimSun", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.txtError.ForeColor = System.Drawing.Color.Maroon;
            this.txtError.Location = new System.Drawing.Point(130, 114);
            this.txtError.Margin = new System.Windows.Forms.Padding(4);
            this.txtError.Multiline = true;
            this.txtError.Name = "txtError";
            this.txtError.ReadOnly = true;
            this.txtError.Size = new System.Drawing.Size(754, 357);
            this.txtError.TabIndex = 7;
            this.txtError.Visible = false;
            // 
            // codeforces
            // 
            this.codeforces.AutoSize = true;
            this.codeforces.Checked = true;
            this.codeforces.Location = new System.Drawing.Point(132, 54);
            this.codeforces.Name = "codeforces";
            this.codeforces.Size = new System.Drawing.Size(106, 20);
            this.codeforces.TabIndex = 0;
            this.codeforces.TabStop = true;
            this.codeforces.Text = "codeforces";
            this.codeforces.UseVisualStyleBackColor = true;
            this.codeforces.CheckedChanged += new System.EventHandler(this.CheckedChanged);
            // 
            // uva
            // 
            this.uva.AutoSize = true;
            this.uva.Location = new System.Drawing.Point(244, 54);
            this.uva.Name = "uva";
            this.uva.Size = new System.Drawing.Size(50, 20);
            this.uva.TabIndex = 1;
            this.uva.Text = "UVa";
            this.uva.UseVisualStyleBackColor = true;
            this.uva.CheckedChanged += new System.EventHandler(this.CheckedChanged);
            // 
            // usaco
            // 
            this.usaco.AutoSize = true;
            this.usaco.Location = new System.Drawing.Point(300, 54);
            this.usaco.Name = "usaco";
            this.usaco.Size = new System.Drawing.Size(66, 20);
            this.usaco.TabIndex = 2;
            this.usaco.Text = "USACO";
            this.usaco.UseVisualStyleBackColor = true;
            this.usaco.CheckedChanged += new System.EventHandler(this.CheckedChanged);
            // 
            // spoj
            // 
            this.spoj.AutoSize = true;
            this.spoj.Location = new System.Drawing.Point(372, 54);
            this.spoj.Name = "spoj";
            this.spoj.Size = new System.Drawing.Size(58, 20);
            this.spoj.TabIndex = 3;
            this.spoj.Text = "SPOJ";
            this.spoj.UseVisualStyleBackColor = true;
            this.spoj.CheckedChanged += new System.EventHandler(this.CheckedChanged);
            // 
            // ural
            // 
            this.ural.AutoSize = true;
            this.ural.Location = new System.Drawing.Point(436, 54);
            this.ural.Name = "ural";
            this.ural.Size = new System.Drawing.Size(218, 20);
            this.ural.TabIndex = 4;
            this.ural.Text = "Timus Online Judge(Ural)";
            this.ural.UseVisualStyleBackColor = true;
            this.ural.CheckedChanged += new System.EventHandler(this.CheckedChanged);
            // 
            // poj
            // 
            this.poj.AutoSize = true;
            this.poj.Location = new System.Drawing.Point(660, 54);
            this.poj.Name = "poj";
            this.poj.Size = new System.Drawing.Size(50, 20);
            this.poj.TabIndex = 5;
            this.poj.Text = "POJ";
            this.poj.UseVisualStyleBackColor = true;
            this.poj.CheckedChanged += new System.EventHandler(this.CheckedChanged);
            // 
            // hdu
            // 
            this.hdu.AutoSize = true;
            this.hdu.Location = new System.Drawing.Point(716, 54);
            this.hdu.Name = "hdu";
            this.hdu.Size = new System.Drawing.Size(50, 20);
            this.hdu.TabIndex = 6;
            this.hdu.Text = "HDU";
            this.hdu.UseVisualStyleBackColor = true;
            this.hdu.CheckedChanged += new System.EventHandler(this.CheckedChanged);
            // 
            // label5
            // 
            this.label5.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.Color.Transparent;
            this.label5.Location = new System.Drawing.Point(15, 549);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(96, 16);
            this.label5.TabIndex = 15;
            this.label5.Text = "Source Code";
            // 
            // panel1
            // 
            this.panel1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.panel1.BackColor = System.Drawing.SystemColors.Control;
            this.panel1.Controls.Add(this.sourceJava);
            this.panel1.Controls.Add(this.sourceCpp);
            this.panel1.Location = new System.Drawing.Point(132, 546);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(124, 34);
            this.panel1.TabIndex = 16;
            // 
            // sourceJava
            // 
            this.sourceJava.AutoSize = true;
            this.sourceJava.Location = new System.Drawing.Point(59, 3);
            this.sourceJava.Name = "sourceJava";
            this.sourceJava.Size = new System.Drawing.Size(58, 20);
            this.sourceJava.TabIndex = 12;
            this.sourceJava.Text = "Java";
            this.sourceJava.UseVisualStyleBackColor = true;
            this.sourceJava.Click += new System.EventHandler(this.sourceJava_Click);
            // 
            // sourceCpp
            // 
            this.sourceCpp.AutoSize = true;
            this.sourceCpp.Checked = true;
            this.sourceCpp.Location = new System.Drawing.Point(3, 3);
            this.sourceCpp.Name = "sourceCpp";
            this.sourceCpp.Size = new System.Drawing.Size(50, 20);
            this.sourceCpp.TabIndex = 11;
            this.sourceCpp.TabStop = true;
            this.sourceCpp.Text = "C++";
            this.sourceCpp.UseVisualStyleBackColor = true;
            this.sourceCpp.Click += new System.EventHandler(this.sourceCpp_Click);
            // 
            // emptyCode
            // 
            this.emptyCode.AutoSize = true;
            this.emptyCode.Location = new System.Drawing.Point(772, 54);
            this.emptyCode.Name = "emptyCode";
            this.emptyCode.Size = new System.Drawing.Size(162, 20);
            this.emptyCode.TabIndex = 7;
            this.emptyCode.Text = "Empty Code(No OJ)";
            this.emptyCode.UseVisualStyleBackColor = true;
            this.emptyCode.CheckedChanged += new System.EventHandler(this.CheckedChanged);
            // 
            // panel2
            // 
            this.panel2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.panel2.BackColor = System.Drawing.SystemColors.Control;
            this.panel2.Controls.Add(this.picIntelliJOK);
            this.panel2.Controls.Add(this.chkIntelliJ);
            this.panel2.Controls.Add(this.chkvscode);
            this.panel2.Location = new System.Drawing.Point(303, 546);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(242, 34);
            this.panel2.TabIndex = 20;
            // 
            // picIntelliJOK
            // 
            this.picIntelliJOK.Image = global::OJAssistantUI.Properties.Resources.user_ok;
            this.picIntelliJOK.Location = new System.Drawing.Point(218, 3);
            this.picIntelliJOK.Name = "picIntelliJOK";
            this.picIntelliJOK.Size = new System.Drawing.Size(20, 20);
            this.picIntelliJOK.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picIntelliJOK.TabIndex = 15;
            this.picIntelliJOK.TabStop = false;
            this.picIntelliJOK.Visible = false;
            // 
            // chkIntelliJ
            // 
            this.chkIntelliJ.AutoSize = true;
            this.chkIntelliJ.Enabled = false;
            this.chkIntelliJ.Location = new System.Drawing.Point(90, 3);
            this.chkIntelliJ.Name = "chkIntelliJ";
            this.chkIntelliJ.Size = new System.Drawing.Size(130, 20);
            this.chkIntelliJ.TabIndex = 14;
            this.chkIntelliJ.Text = "IntelliJ IDEA";
            this.chkIntelliJ.UseVisualStyleBackColor = true;
            this.chkIntelliJ.CheckedChanged += new System.EventHandler(this.IntelliJ_CheckedChanged);
            // 
            // chkvscode
            // 
            this.chkvscode.AutoSize = true;
            this.chkvscode.Checked = true;
            this.chkvscode.Location = new System.Drawing.Point(2, 3);
            this.chkvscode.Name = "chkvscode";
            this.chkvscode.Size = new System.Drawing.Size(82, 20);
            this.chkvscode.TabIndex = 13;
            this.chkvscode.TabStop = true;
            this.chkvscode.Text = "VS Code";
            this.chkvscode.UseVisualStyleBackColor = true;
            // 
            // frmOJAssistant
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.butCancel;
            this.ClientSize = new System.Drawing.Size(1008, 601);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.emptyCode);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.hdu);
            this.Controls.Add(this.poj);
            this.Controls.Add(this.ural);
            this.Controls.Add(this.spoj);
            this.Controls.Add(this.usaco);
            this.Controls.Add(this.uva);
            this.Controls.Add(this.codeforces);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.txtAuthor);
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
            this.Controls.Add(this.txtError);
            this.Font = new System.Drawing.Font("SimSun", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(4);
            this.MinimumSize = new System.Drawing.Size(950, 480);
            this.Name = "frmOJAssistant";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Online Judge Assistant";
            this.Activated += new System.EventHandler(this.frmCFHelper_Activated);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.frmCFHelper_FormClosed);
            this.Load += new System.EventHandler(this.frmCFHelper_Load);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picIntelliJOK)).EndInit();
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
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtAuthor;
        private System.Windows.Forms.TextBox txtError;
        private System.Windows.Forms.RadioButton codeforces;
        private System.Windows.Forms.RadioButton uva;
        private System.Windows.Forms.RadioButton usaco;
        private System.Windows.Forms.RadioButton spoj;
        private System.Windows.Forms.RadioButton ural;
        private System.Windows.Forms.RadioButton poj;
        private System.Windows.Forms.RadioButton hdu;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.RadioButton sourceJava;
        private System.Windows.Forms.RadioButton sourceCpp;
        private System.Windows.Forms.RadioButton emptyCode;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.RadioButton chkIntelliJ;
        private System.Windows.Forms.RadioButton chkvscode;
        private System.Windows.Forms.PictureBox picIntelliJOK;
    }
}

