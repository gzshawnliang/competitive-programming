using System.Windows.Forms;
using Microsoft.Win32;

namespace OJAssistantUI
{
	public static class Registry
	{
		public static string RegRead(string keyName)
		{
			string subKey = "SOFTWARE\\" + Application.ProductName;

			RegistryKey sk = Microsoft.Win32.Registry.CurrentUser.OpenSubKey(subKey);
			if (sk != null)
			{
				var o = sk.GetValue(keyName);
				if (o != null)
					return o.ToString();
			}

			return null;
		}

		public static void RegWrite(string keyName, string value)
		{
			string subKey = "SOFTWARE\\" + Application.ProductName;

			RegistryKey sk1 = Microsoft.Win32.Registry.CurrentUser.CreateSubKey(subKey);
			sk1.SetValue(keyName, value);
		}
	}
}