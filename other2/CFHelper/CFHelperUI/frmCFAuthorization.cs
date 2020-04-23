﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CFHelperUI
{
    public partial class frmCFAuthorization : Form
    {
        public frmCFAuthorization()
        {
            InitializeComponent();
        }

        private void butOK_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;
            Registry.RegWrite("CFKey", txtKey.Text);
            Registry.RegWrite("CFSecret", StringCipher.Encrypt(txtsecret.Text, Config.EncryptKey));
        }

        private void frmCFAuthorization_Load(object sender, EventArgs e)
        {
            txtKey.Text = Registry.RegRead("CFKey");
            string s = Registry.RegRead("CFSecret");
            if (!string.IsNullOrEmpty(s))
                s = StringCipher.Decrypt(s, Config.EncryptKey);

            txtsecret.Text = s;
        }
    }
}
