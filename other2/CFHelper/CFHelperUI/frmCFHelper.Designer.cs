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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmCFHelper));
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
            this.linkCFAuthorization = new System.Windows.Forms.LinkLabel();
            this.PicCFAuth = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.PicCFAuth)).BeginInit();
            this.SuspendLayout();
            // 
            // txtProblemId
            // 
            this.txtProblemId.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txtProblemId.Location = new System.Drawing.Point(138, 82);
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
            this.butGo.Location = new System.Drawing.Point(900, 80);
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
            this.listView1.Location = new System.Drawing.Point(138, 116);
            this.listView1.Margin = new System.Windows.Forms.Padding(4);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(754, 481);
            this.listView1.TabIndex = 6;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.View = System.Windows.Forms.View.Details;
            this.listView1.DoubleClick += new System.EventHandler(this.listView1_DoubleClick);
            // 
            // butOK
            // 
            this.butOK.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.butOK.Location = new System.Drawing.Point(792, 677);
            this.butOK.Margin = new System.Windows.Forms.Padding(4);
            this.butOK.Name = "butOK";
            this.butOK.Size = new System.Drawing.Size(100, 31);
            this.butOK.TabIndex = 11;
            this.butOK.Text = "OK";
            this.butOK.UseVisualStyleBackColor = true;
            this.butOK.Click += new System.EventHandler(this.butOK_Click);
            // 
            // butCancel
            // 
            this.butCancel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.butCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.butCancel.Location = new System.Drawing.Point(900, 677);
            this.butCancel.Margin = new System.Windows.Forms.Padding(4);
            this.butCancel.Name = "butCancel";
            this.butCancel.Size = new System.Drawing.Size(100, 31);
            this.butCancel.TabIndex = 12;
            this.butCancel.Text = "Quit";
            this.butCancel.UseVisualStyleBackColor = true;
            this.butCancel.Click += new System.EventHandler(this.butCancel_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Location = new System.Drawing.Point(21, 82);
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
            this.label2.Location = new System.Drawing.Point(21, 115);
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
            this.lblContest.Location = new System.Drawing.Point(21, 19);
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
            this.label3.Location = new System.Drawing.Point(21, 608);
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
            this.txtWorkingDir.Location = new System.Drawing.Point(138, 605);
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
            this.butBrowse.Location = new System.Drawing.Point(900, 601);
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
            this.label4.Location = new System.Drawing.Point(21, 639);
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
            this.txtAuthor.Location = new System.Drawing.Point(138, 634);
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
            this.txtError.Location = new System.Drawing.Point(138, 116);
            this.txtError.Margin = new System.Windows.Forms.Padding(4);
            this.txtError.Multiline = true;
            this.txtError.Name = "txtError";
            this.txtError.ReadOnly = true;
            this.txtError.Size = new System.Drawing.Size(754, 481);
            this.txtError.TabIndex = 7;
            this.txtError.Visible = false;
            // 
            // codeforces
            // 
            this.codeforces.AutoSize = true;
            this.codeforces.Checked = true;
            this.codeforces.Location = new System.Drawing.Point(140, 55);
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
            this.uva.Location = new System.Drawing.Point(301, 55);
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
            this.usaco.Location = new System.Drawing.Point(357, 55);
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
            this.spoj.Location = new System.Drawing.Point(429, 55);
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
            this.ural.Location = new System.Drawing.Point(493, 55);
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
            this.poj.Location = new System.Drawing.Point(717, 55);
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
            this.hdu.Location = new System.Drawing.Point(773, 55);
            this.hdu.Name = "hdu";
            this.hdu.Size = new System.Drawing.Size(50, 20);
            this.hdu.TabIndex = 6;
            this.hdu.Text = "HDU";
            this.hdu.UseVisualStyleBackColor = true;
            this.hdu.CheckedChanged += new System.EventHandler(this.CheckedChanged);
            // 
            // linkCFAuthorization
            // 
            this.linkCFAuthorization.AutoSize = true;
            this.linkCFAuthorization.Location = new System.Drawing.Point(243, 57);
            this.linkCFAuthorization.Name = "linkCFAuthorization";
            this.linkCFAuthorization.Size = new System.Drawing.Size(40, 16);
            this.linkCFAuthorization.TabIndex = 13;
            this.linkCFAuthorization.TabStop = true;
            this.linkCFAuthorization.Text = "认证";
            this.linkCFAuthorization.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkCFAuthorization_LinkClicked);
            // 
            // PicCFAuth
            // 
            this.PicCFAuth.Image = global::CFHelperUI.Properties.Resources.user_ok;
            this.PicCFAuth.Location = new System.Drawing.Point(114, 55);
            this.PicCFAuth.Name = "PicCFAuth";
            this.PicCFAuth.Size = new System.Drawing.Size(20, 20);
            this.PicCFAuth.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.PicCFAuth.TabIndex = 14;
            this.PicCFAuth.TabStop = false;
            this.PicCFAuth.Visible = false;
            // 
            // frmCFHelper
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.butCancel;
            this.ClientSize = new System.Drawing.Size(1008, 729);
            this.Controls.Add(this.PicCFAuth);
            this.Controls.Add(this.linkCFAuthorization);
            this.Controls.Add(this.hdu);
            this.Controls.Add(this.poj);
            this.Controls.Add(this.ural);
            this.Controls.Add(this.spoj);
            this.Controls.Add(this.usaco);
            this.Controls.Add(this.uva);
            this.Controls.Add(this.codeforces);
            this.Controls.Add(this.txtError);
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
            this.Font = new System.Drawing.Font("SimSun", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "frmCFHelper";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "CFHelper";
            this.Activated += new System.EventHandler(this.frmCFHelper_Activated);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.frmCFHelper_FormClosed);
            this.Load += new System.EventHandler(this.frmCFHelper_Load);
            ((System.ComponentModel.ISupportInitialize)(this.PicCFAuth)).EndInit();
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
        private System.Windows.Forms.LinkLabel linkCFAuthorization;
        private System.Windows.Forms.PictureBox PicCFAuth;
    }
}

