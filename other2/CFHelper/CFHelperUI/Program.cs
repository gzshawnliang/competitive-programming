using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace CFHelperUI
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main(string[] args)
        {
            string defaultDir = string.Empty;
            if (args.Length > 0)
            {
                defaultDir = args[0];
            }
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new frmCFHelper(defaultDir));
        }
    }
}
