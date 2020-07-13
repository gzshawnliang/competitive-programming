using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net.Configuration;
using System.Text;
using System.Dynamic;
using System.Windows.Forms;
using System.Text.RegularExpressions;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Reflection;
using System.Security.AccessControl;
using System.Threading;
using Newtonsoft.Json.Linq;
using System.Threading.Tasks;
using OJAssistantUI.Properties;
using HtmlAgilityPack;
using Microsoft.Win32;
using Newtonsoft.Json;
using HtmlDocument = HtmlAgilityPack.HtmlDocument;
using System.Globalization;
using System.CodeDom;

namespace OJAssistantUI
{
    public partial class frmCFHelper : Form
    {
        private int contestId=0;
        private Dictionary<string, string> problemDict;
        private readonly string _defaultDir;

        private string inputFileContent;    //USACO SAMPLE INPUT Data

        private readonly Dictionary<string, string> _timeZoneDict = new Dictionary<string, string>()
        {
        { "Dateline Standard Time"," (UTC-12:00) International Date Line West" },
        { "UTC-11"," (UTC-11:00) Coordinated Universal Time-11" },
        { "Hawaiian Standard Time"," (UTC-10:00) Hawaii" },
        { "Alaskan Standard Time"," (UTC-09:00) Alaska" },
        { "Pacific Standard Time (Mexico)"," (UTC-08:00) Baja California" },
        { "Pacific Standard Time"," (UTC-08:00) Pacific Time (US & Canada)" },
        { "US Mountain Standard Time"," (UTC-07:00) Arizona" },
        { "Mountain Standard Time (Mexico)"," (UTC-07:00) Chihuahua, La Paz, Mazatlan" },
        { "Mountain Standard Time"," (UTC-07:00) Mountain Time (US & Canada)" },
        { "Central America Standard Time"," (UTC-06:00) Central America" },
        { "Central Standard Time"," (UTC-06:00) Central Time (US & Canada)" },
        { "Central Standard Time (Mexico)"," (UTC-06:00) Guadalajara, Mexico City, Monterrey" },
        { "Canada Central Standard Time"," (UTC-06:00) Saskatchewan" },
        { "SA Pacific Standard Time"," (UTC-05:00) Bogota, Lima, Quito, Rio Branco" },
        { "Eastern Standard Time (Mexico)"," (UTC-05:00) Chetumal" },
        { "Eastern Standard Time"," (UTC-05:00) Eastern Time (US & Canada)" },
        { "US Eastern Standard Time"," (UTC-05:00) Indiana (East)" },
        { "Venezuela Standard Time"," (UTC-04:30) Caracas" },
        { "Paraguay Standard Time"," (UTC-04:00) Asuncion" },
        { "Atlantic Standard Time"," (UTC-04:00) Atlantic Time (Canada)" },
        { "Central Brazilian Standard Time"," (UTC-04:00) Cuiaba" },
        { "SA Western Standard Time"," (UTC-04:00) Georgetown, La Paz, Manaus, San Juan" },
        { "Newfoundland Standard Time"," (UTC-03:30) Newfoundland" },
        { "E. South America Standard Time"," (UTC-03:00) Brasilia" },
        { "SA Eastern Standard Time"," (UTC-03:00) Cayenne, Fortaleza" },
        { "Argentina Standard Time"," (UTC-03:00) City of Buenos Aires" },
        { "Greenland Standard Time"," (UTC-03:00) Greenland" },
        { "Montevideo Standard Time"," (UTC-03:00) Montevideo" },
        { "Bahia Standard Time"," (UTC-03:00) Salvador" },
        { "Pacific SA Standard Time"," (UTC-03:00) Santiago" },
        { "UTC-02"," (UTC-02:00) Coordinated Universal Time-02" },
        { "Mid-Atlantic Standard Time"," (UTC-02:00) Mid-Atlantic - Old" },
        { "Azores Standard Time"," (UTC-01:00) Azores" },
        { "Cape Verde Standard Time"," (UTC-01:00) Cabo Verde Is." },
        { "Morocco Standard Time"," (UTC) Casablanca" },
        { "UTC"," (UTC) Coordinated Universal Time" },
        { "GMT Standard Time"," (UTC) Dublin, Edinburgh, Lisbon, London" },
        { "Greenwich Standard Time"," (UTC) Monrovia, Reykjavik" },
        { "W. Europe Standard Time"," (UTC+01:00) Amsterdam, Berlin, Bern, Rome, Stockholm, Vienna" },
        { "Central Europe Standard Time"," (UTC+01:00) Belgrade, Bratislava, Budapest, Ljubljana, Prague" },
        { "Romance Standard Time"," (UTC+01:00) Brussels, Copenhagen, Madrid, Paris" },
        { "Central European Standard Time"," (UTC+01:00) Sarajevo, Skopje, Warsaw, Zagreb" },
        { "W. Central Africa Standard Time"," (UTC+01:00) West Central Africa" },
        { "Namibia Standard Time"," (UTC+01:00) Windhoek" },
        { "Jordan Standard Time"," (UTC+02:00) Amman" },
        { "GTB Standard Time"," (UTC+02:00) Athens, Bucharest" },
        { "Middle East Standard Time"," (UTC+02:00) Beirut" },
        { "Egypt Standard Time"," (UTC+02:00) Cairo" },
        { "Syria Standard Time"," (UTC+02:00) Damascus" },
        { "E. Europe Standard Time"," (UTC+02:00) E. Europe" },
        { "South Africa Standard Time"," (UTC+02:00) Harare, Pretoria" },
        { "FLE Standard Time"," (UTC+02:00) Helsinki, Kyiv, Riga, Sofia, Tallinn, Vilnius" },
        { "Turkey Standard Time"," (UTC+02:00) Istanbul" },
        { "Israel Standard Time"," (UTC+02:00) Jerusalem" },
        { "Kaliningrad Standard Time"," (UTC+02:00) Kaliningrad (RTZ 1)" },
        { "Libya Standard Time"," (UTC+02:00) Tripoli" },
        { "Arabic Standard Time"," (UTC+03:00) Baghdad" },
        { "Arab Standard Time"," (UTC+03:00) Kuwait, Riyadh" },
        { "Belarus Standard Time"," (UTC+03:00) Minsk" },
        { "Russian Standard Time"," (UTC+03:00) Moscow, St. Petersburg, Volgograd (RTZ 2)" },
        { "E. Africa Standard Time"," (UTC+03:00) Nairobi" },
        { "Iran Standard Time"," (UTC+03:30) Tehran" },
        { "Arabian Standard Time"," (UTC+04:00) Abu Dhabi, Muscat" },
        { "Azerbaijan Standard Time"," (UTC+04:00) Baku" },
        { "Russia Time Zone 3"," (UTC+04:00) Izhevsk, Samara (RTZ 3)" },
        { "Mauritius Standard Time"," (UTC+04:00) Port Louis" },
        { "Georgian Standard Time"," (UTC+04:00) Tbilisi" },
        { "Caucasus Standard Time"," (UTC+04:00) Yerevan" },
        { "Afghanistan Standard Time"," (UTC+04:30) Kabul" },
        { "West Asia Standard Time"," (UTC+05:00) Ashgabat, Tashkent" },
        { "Ekaterinburg Standard Time"," (UTC+05:00) Ekaterinburg (RTZ 4)" },
        { "Pakistan Standard Time"," (UTC+05:00) Islamabad, Karachi" },
        { "India Standard Time"," (UTC+05:30) Chennai, Kolkata, Mumbai, New Delhi" },
        { "Sri Lanka Standard Time"," (UTC+05:30) Sri Jayawardenepura" },
        { "Nepal Standard Time"," (UTC+05:45) Kathmandu" },
        { "Central Asia Standard Time"," (UTC+06:00) Astana" },
        { "Bangladesh Standard Time"," (UTC+06:00) Dhaka" },
        { "N. Central Asia Standard Time"," (UTC+06:00) Novosibirsk (RTZ 5)" },
        { "Myanmar Standard Time"," (UTC+06:30) Yangon (Rangoon)" },
        { "SE Asia Standard Time"," (UTC+07:00) Bangkok, Hanoi, Jakarta" },
        { "North Asia Standard Time"," (UTC+07:00) Krasnoyarsk (RTZ 6)" },
        //{ "China Standard Time"," (UTC+08:00) Beijing, Guangzhou, Chongqing, Hong Kong, Urumqi" },
        { "China Standard Time"," (UTC+08:00)" },
        { "North Asia East Standard Time"," (UTC+08:00) Irkutsk (RTZ 7)" },
        { "Singapore Standard Time"," (UTC+08:00) Kuala Lumpur, Singapore" },
        { "W. Australia Standard Time"," (UTC+08:00) Perth" },
        { "Taipei Standard Time"," (UTC+08:00) Taipei" },
        { "Ulaanbaatar Standard Time"," (UTC+08:00) Ulaanbaatar" },
        { "North Korea Standard Time"," (UTC+08:30) Pyongyang" },
        { "Tokyo Standard Time"," (UTC+09:00) Osaka, Sapporo, Tokyo" },
        { "Korea Standard Time"," (UTC+09:00) Seoul" },
        { "Yakutsk Standard Time"," (UTC+09:00) Yakutsk (RTZ 8)" },
        { "Cen. Australia Standard Time"," (UTC+09:30) Adelaide" },
        { "AUS Central Standard Time"," (UTC+09:30) Darwin" },
        { "E. Australia Standard Time"," (UTC+10:00) Brisbane" },
        { "AUS Eastern Standard Time"," (UTC+10:00) Canberra, Melbourne, Sydney" },
        { "West Pacific Standard Time"," (UTC+10:00) Guam, Port Moresby" },
        { "Tasmania Standard Time"," (UTC+10:00) Hobart" },
        { "Magadan Standard Time"," (UTC+10:00) Magadan" },
        { "Vladivostok Standard Time"," (UTC+10:00) Vladivostok, Magadan (RTZ 9)" },
        { "Russia Time Zone 10"," (UTC+11:00) Chokurdakh (RTZ 10)" },
        { "Central Pacific Standard Time"," (UTC+11:00) Solomon Is., New Caledonia" },
        { "Russia Time Zone 11"," (UTC+12:00) Anadyr, Petropavlovsk-Kamchatsky (RTZ 11)" },
        { "New Zealand Standard Time"," (UTC+12:00) Auckland, Wellington" },
        { "UTC+12"," (UTC+12:00) Coordinated Universal Time+12" },
        { "Fiji Standard Time"," (UTC+12:00) Fiji" },
        { "Kamchatka Standard Time"," (UTC+12:00) Petropavlovsk-Kamchatsky - Old" },
        { "Tonga Standard Time"," (UTC+13:00) Nuku'alofa" },
        { "Samoa Standard Time"," (UTC+13:00) Samoa" },
        { "Line Islands Standard Time"," (UTC+14:00) Kiritimati Island" },
    };

        private string _javaModuleDir = string.Empty;

        private string rootDir
        {
            get
            {
                if (chkIntelliJ.Checked && !string.IsNullOrEmpty(_javaModuleDir))
                    return _javaModuleDir;
                
                return this.txtWorkingDir.Text;
            }
        }
        private enum ContestType
        {
            codeforces,
            usaco,
            spoj,
            uva,
            ural,
            poj,
            hdu,
            none
        }

        //Enum: CF, IOI, ICPC. Scoring system used for the contest.
        //https://codeforces.com/apiHelp/objects#Contest
        private string CfContestType;

        private ContestType contestType;

        private string sourceCodeFileExt="cpp";

        public frmCFHelper()
        {
            InitializeComponent();
        }

        public frmCFHelper(string defaultDir):this()
        {
            _defaultDir = defaultDir;
            Config.EncryptKey = UHWID.GetID();
            //Config.EncryptKey = "123";
        }

        private void frmCFHelper_Load(object sender, EventArgs e)
        {
            //this.Text += "["+_defaultDir;
            string saveWorkingDir = Registry.RegRead("WorkingDir");
            if(!string.IsNullOrEmpty(saveWorkingDir))
                saveWorkingDir = saveWorkingDir.TrimEnd();
            string workspaceFolder = _defaultDir;
            if (string.IsNullOrEmpty(workspaceFolder))
                workspaceFolder = GetApplicationRoot();

            if (string.IsNullOrEmpty(saveWorkingDir))
                    txtWorkingDir.Text = workspaceFolder;
            else if (Directory.Exists(saveWorkingDir))
            {
                DirectoryInfo di1 = new DirectoryInfo(workspaceFolder);
                DirectoryInfo di2 = new DirectoryInfo(saveWorkingDir);
                bool isParent = false;
                while (di2.Parent != null)
                {
                    if (di2.Parent.FullName == di1.FullName)
                    {
                        isParent = true;
                        break;
                    }
                    else di2 = di2.Parent;
                }

                if (isParent)
                    txtWorkingDir.Text = saveWorkingDir;
                else
                    txtWorkingDir.Text = workspaceFolder;
            }
            else
                txtWorkingDir.Text = workspaceFolder;

            //CheckCFAuth();

            GetWindowsState();
            this.txtAuthor.Text = Registry.RegRead("Author");

            this.Text += $" {Application.ProductVersion}";
            var ojType = Registry.RegRead("OJType");

            if (!string.IsNullOrEmpty(ojType))
            {
                foreach (Control ctl in this.Controls)
                    if (ctl is RadioButton)
                        if (ctl.Name == ojType)
                        {
                            ((RadioButton)ctl).Checked = true;
                            break;
                        }
            }
        }

        private void butCancel_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void butGo_Click(object sender, EventArgs e)
        {
            RefreshtProblem();
        }

        private void RefreshtProblem()
        {
            string input = this.txtProblemId.Text.Trim();

            bool isInt = int.TryParse(input, out int inputNumber);
            Debug.WriteLine(inputNumber);

            if (Regex.IsMatch(input, @"usaco.org", RegexOptions.IgnoreCase))
            {
                usaco.Checked = true;
                GetDataUSACO((new UriBuilder(input)).ToString());
            }
            else if (Regex.IsMatch(input, @"spoj.com", RegexOptions.IgnoreCase))
            {
                spoj.Checked = true;
                GetDataSPOJ((new UriBuilder(input)).ToString());
            }
            else if (Regex.IsMatch(input, @"timus.ru", RegexOptions.IgnoreCase))
            {
                ural.Checked = true;
                GetDataUral((new UriBuilder(input)).ToString());
            }
            else if (Regex.IsMatch(input, @"poj.org", RegexOptions.IgnoreCase))
            {
                poj.Checked = true;
                GetDataPOJ((new UriBuilder(input)).ToString());
            }
            else if (Regex.IsMatch(input, @"hdu.edu.cn", RegexOptions.IgnoreCase))
            {
                hdu.Checked = true;
                GetDataHDU((new UriBuilder(input)).ToString());
            }
            else if (uva.Checked)
            {
                GetDataUVa(input);
            }
            else if (codeforces.Checked)
            {
                GetDataCF(input);
            }
            else if(emptyCode.Checked)
            {
                contestType = ContestType.none;
            }
            else if (isInt)
            {
                codeforces.Checked = true;
                GetDataCF(input);
            }
            else if (Regex.IsMatch(input, @"^\d{1,}[0-9]([A-Za-z])?[0-9]$", RegexOptions.IgnoreCase)) //一定是201A,201A2的格式：数字+单个字母或者数字
            {
                codeforces.Checked = true;
                GetDataCF(input);
            }
            else if (Regex.IsMatch(input, @"^\d{1,}[0-9]([A-Za-z])$", RegexOptions.IgnoreCase)) //一定是201A的格式：数字+单个字母或者数字
            {
                codeforces.Checked = true;
                GetDataCF(input);
            }
        }

        private dynamic GetCfContest(string contestId,out Exception ex)
        {
            ex = null;
            string url =
                $"https://codeforces.com/api/contest.standings?contestId={contestId}&from=1&count=1&showUnofficial=true";


            string apiKey = Registry.RegRead("CFKey");
            string apiSecret = Registry.RegRead("CFSecret");

            //CF认证
            //https://codeforces.com/apiHelp
            if (!string.IsNullOrEmpty(apiKey) && !string.IsNullOrEmpty(apiSecret))
            {
                try
                {
                    apiSecret = StringCipher.Decrypt(apiSecret, Config.EncryptKey);
                }
                catch (Exception e)
                {
                    ex = e;
                    return null;
                }
                //apiSecret = StringCipher.Decrypt(apiSecret, Config.EncryptKey);

                string random6 = new Random().Next(100000, 999999).ToString();
                string unixTimestamp = DateTimeOffset.Now.ToUnixTimeSeconds().ToString();
                string apiSig = $"{random6}/contest.standings?apiKey={apiKey}&contestId={contestId}&count=1&from=1&showUnofficial=true&time={unixTimestamp}#{apiSecret}";
                apiSig = SHA.GenerateSHA512String(apiSig).ToLower();

                url += $"&apiKey={apiKey}&time={unixTimestamp}&apiSig={random6}{apiSig}";
            }

            try
            {
                dynamic o = GetResponse(url);
                return o;
            }
            catch (Exception e)
            {
                ex = e;

            }

            return null;
        }

        private void GetDataCF(string input)
        {
            contestType = ContestType.codeforces;

            string s1 = string.Empty;
            string problemId = string.Empty;
            bool isBeginProblemId = false;
            foreach (char c in input)
            {
                if (Char.IsDigit(c) && !isBeginProblemId)
                    s1 += c;
                else
                {
                    isBeginProblemId = true;
                    problemId += c;
                }
            }

            if (int.TryParse(s1, out contestId) == false)
            {
                MessageBox.Show(this, "输入 problemId 无效.", this.Text, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return;
            }
            inputFileContent = string.Empty;
            lblContest.Text = "";
            listView1.Columns.Clear();
            listView1.Items.Clear();
            this.listView1.Visible = true;
            txtError.Visible = false;
            txtError.Clear();

            dynamic o = GetCfContest(contestId.ToString(), out Exception ex);
            if (o != null)
            {
                string ids = string.Empty;

                if (o.status == "OK")
                {
                    CfContestType = o.result.contest.type.ToString();

                    problemDict = new Dictionary<string, string>();

                    lblContest.Text = o.result.contest.name;
                    //Debug.WriteLine(o.result.contest.type.ToString());

                    this.listView1.Columns.Add("", 36, HorizontalAlignment.Left);
                    this.listView1.Columns.Add("name", 300, HorizontalAlignment.Left);
                    this.listView1.Columns.Add("rating", 64, HorizontalAlignment.Left);
                    this.listView1.Columns.Add("tag", 300, HorizontalAlignment.Left);
                    this.listView1.BeginUpdate();
                    dynamic problemsList = o.result.problems;
                    foreach (dynamic problem in problemsList)
                    {
                        string problemindex = problem.index.ToString();

                        if (!string.IsNullOrEmpty(problemId))
                            if (problemId.ToUpper() != problemindex.ToUpper())
                                continue;

                        problemDict.Add(problemindex.ToUpper(), problem.name.ToString());
                        string s = $"({problemindex.ToUpper()}){problem.name}";
                        ids += $"{problem.index} ";

                        ListViewItem lvi = new ListViewItem(problemindex.ToUpper());
                        lvi.SubItems.Add(problem.name.ToString());
                        if (problem.rating != null)
                            lvi.SubItems.Add(problem.rating.ToString());
                        else
                            lvi.SubItems.Add("");
                        string tags = "";
                        foreach (var tag in problem.tags)
                        {
                            tags += tag.ToString() + ",";
                        }
                        lvi.SubItems.Add(tags);
                        this.listView1.Items.Add(lvi);
                        //Console.WriteLine(s);
                    }
                    this.listView1.EndUpdate();
                    this.listView1.AutoResizeColumns(ColumnHeaderAutoResizeStyle.HeaderSize);
                }
                else if (o.status == "FAILED")
                {
                    lblContest.Text = o.comment;
                }
                else
                {
                    Console.WriteLine(o);
                }
            }
            else if(ex !=null)
            {
                txtError.Text = ex.ToString();
                txtError.Visible = true;
                this.listView1.Visible = false;
                lblContest.Text = ex.Message;
            }
        }

        private void GetDataUVa(string input)
        {
            contestType = ContestType.uva;

            if (int.TryParse(input, out int problemId) == false)
            {
                MessageBox.Show(this, "输入 problemId 无效.", this.Text, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return;
            }
            inputFileContent = string.Empty;
            lblContest.Text = "";
            listView1.Columns.Clear();
            listView1.Items.Clear();
            listView1.Visible = true;
            txtError.Visible = false;
            txtError.Clear();

            //HttpClient client = new HttpClient();
            string url = $"https://uhunt.onlinejudge.org/api/p/num/{problemId}";

            try
            {
                dynamic o = GetResponse(url);

                if (o !=null)
                {
                    lblContest.Text = o.title.ToString();

                    this.listView1.Columns.Add("id", 36, HorizontalAlignment.Left);
                    this.listView1.Columns.Add("name", 300, HorizontalAlignment.Left);
                    this.listView1.Columns.Add("file", 300, HorizontalAlignment.Left);
                    this.listView1.BeginUpdate();
                    string s = $"UVa{problemId}_{o.title.ToString()}";
                    s = FormatPathName(s);
                    ListViewItem lvi = new ListViewItem(problemId.ToString());
                    lvi.Tag = s;
                    lvi.SubItems.Add(o.title.ToString());
                    lvi.SubItems.Add(s + $".{sourceCodeFileExt}");
                    this.listView1.Items.Add(lvi);

                    this.listView1.EndUpdate();
                    this.listView1.AutoResizeColumns(ColumnHeaderAutoResizeStyle.HeaderSize);
                }
                else if (o.status == "FAILED")
                {
                    lblContest.Text = o.comment;
                }
                else
                {
                    Console.WriteLine(o);
                }
            }
            catch (Exception e)
            {
                //Console.WriteLine(e);
                txtError.Text = e.ToString();
                txtError.Visible = true;
                lblContest.Text = e.Message;
                listView1.Visible = false;
                //throw;
            }
        }

        private void GetDataUSACO(string input)
        {
            contestType = ContestType.usaco;

            inputFileContent = string.Empty;
            lblContest.Text = "";
            listView1.Columns.Clear();
            listView1.Items.Clear();
            txtError.Visible = false;
            txtError.Clear();

            var url = input;
            var web = new HtmlWeb();
            HtmlDocument doc = null;
            try
            {
                doc = web.Load(url);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                MessageBox.Show(e.Message, this.Text, MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            HtmlNode titleNode1 = doc.DocumentNode.SelectSingleNode("//div[@class='panel']//h2");
            HtmlNode titleNode2 = doc.DocumentNode.SelectSingleNode("//div[@class='panel']//h2[2]");
            HtmlNode inputFileNode1 = doc.DocumentNode.SelectSingleNode("//div[@class='prob-in-spec']//h4");
            HtmlNode inputDataNode1 = doc.DocumentNode.SelectSingleNode("//pre[@class='in']");

            if (titleNode1 == null || titleNode2 == null || inputFileNode1 == null)
            {
                MessageBox.Show(this, "USACO网页解析错误。", this.Text, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return;
            }

            if (inputDataNode1 != null)
            {
                this.inputFileContent = inputDataNode1.InnerText.TrimStart("\n".ToCharArray());
            }

            string s = titleNode2.InnerText + "_" + titleNode1.InnerText;
            s = s.Replace(" ", "");
            //s = s.Replace(".", "_");
            s = s.Replace(",", "");
            s = s.Replace("Contest", "");
            s = s.Replace("USACO", "");

            s = s.Replace("January", "Jan");
            s = s.Replace("February", "Feb");
            s = s.Replace("March", "Mar");
            s = s.Replace("April", "Apr");
            s = s.Replace("May", "May");
            s = s.Replace("June", "Jun");
            s = s.Replace("July", "Jul");
            s = s.Replace("Septemper", "Sep");
            s = s.Replace("October", "Oct");
            s = s.Replace("November", "Nov");
            s = s.Replace("December", "Dec");
            s = s.Replace("Problem", "Prob");

            var arr = s.Split(".".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            s = "USACO_" + arr[1] + "_" + arr[0];

            lblContest.Text = titleNode1.InnerText;

            this.listView1.Columns.Add("name", 300, HorizontalAlignment.Left);
            this.listView1.Columns.Add("file", 300, HorizontalAlignment.Left);
            this.listView1.Columns.Add("contests", 364, HorizontalAlignment.Left);
            this.listView1.BeginUpdate();

            Debug.WriteLine(s);
            Debug.WriteLine(inputFileNode1.InnerText);

            string codefileName = string.Empty;
            /*
             从以下字符串查找paintbarn.in
             INPUT FORMAT (file paintbarn.in):
            */
            Regex reg = new Regex(@"\w*\.\w*");
            Match result = reg.Match(inputFileNode1.InnerText);
            if (result.Success)
            {
                Debug.WriteLine( result.Value);
                codefileName = result.Value.Split(".".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)[0]+$".{sourceCodeFileExt}";
            }


            ListViewItem lvi = new ListViewItem(titleNode2.InnerText.Trim());
            lvi.SubItems.Add(codefileName);
            lvi.SubItems.Add(titleNode1.InnerText.Trim());
            lvi.Tag = s;
            this.listView1.Items.Add(lvi);
            this.listView1.EndUpdate();
            this.listView1.AutoResizeColumns(ColumnHeaderAutoResizeStyle.HeaderSize);
        }

        private void GetDataSPOJ(string input)
        {
            contestType = ContestType.spoj;

            inputFileContent = string.Empty;
            lblContest.Text = "";
            listView1.Columns.Clear();
            listView1.Items.Clear();
            txtError.Visible = false;
            txtError.Clear();

            var url = input;
            var web = new HtmlWeb();
            HtmlDocument doc = null;
            try
            {
                doc = web.Load(url);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                MessageBox.Show(e.Message, this.Text, MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            HtmlNode titleNode1 = doc.GetElementbyId("problem-name");

            if (titleNode1 == null )
            {
                MessageBox.Show(this, "SPOJ网页解析错误。", this.Text, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return;
            }

            string s = titleNode1.InnerText.Split("-".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)[0];

            s = s.Replace(" ", "");
            s = s.Replace(".", "_");
            s = s.Replace(",", "");
            
            lblContest.Text = titleNode1.InnerText;

            this.listView1.Columns.Add("name", 300, HorizontalAlignment.Left);
            this.listView1.Columns.Add("file", 300, HorizontalAlignment.Left);
            this.listView1.Columns.Add("contests", 364, HorizontalAlignment.Left);
            this.listView1.BeginUpdate();

            Debug.WriteLine(s);
            Debug.WriteLine(titleNode1.InnerText);

            string codefileName = s + $".{sourceCodeFileExt}";

            ListViewItem lvi = new ListViewItem(s);
            lvi.SubItems.Add(codefileName);
            lvi.SubItems.Add(titleNode1.InnerText.Trim());
            lvi.Tag = s;
            this.listView1.Items.Add(lvi);
            this.listView1.EndUpdate();
            this.listView1.AutoResizeColumns(ColumnHeaderAutoResizeStyle.HeaderSize);
        }

        private void GetDataUral(string input)
        {
            contestType = ContestType.ural;

            inputFileContent = string.Empty;
            lblContest.Text = "";
            listView1.Columns.Clear();
            listView1.Items.Clear();
            txtError.Visible = false;
            txtError.Clear();

            var url = input;
            var web = new HtmlWeb();
            HtmlDocument doc = null;
            try
            {
                doc = web.Load(url);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                MessageBox.Show(e.Message, this.Text, MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            HtmlNode titleNode1 = doc.DocumentNode.SelectSingleNode("//div[@class='problem_content']//*[@class='problem_title']");
            

            //HtmlNode titleNode1 = doc.GetElementbyId("problem-name");

            if (titleNode1 == null)
            {
                MessageBox.Show(this, "Timus Online Judge网页解析错误。", this.Text, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return;
            }

            string s = titleNode1.InnerText.Split("-".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)[0];

            s = s.Replace(" ", "");
            s = s.Replace(".", "_");
            s = s.Replace(",", "");

            lblContest.Text = titleNode1.InnerText;

            this.listView1.Columns.Add("name", 300, HorizontalAlignment.Left);
            this.listView1.Columns.Add("file", 300, HorizontalAlignment.Left);
            this.listView1.Columns.Add("contests", 364, HorizontalAlignment.Left);
            this.listView1.BeginUpdate();

            Debug.WriteLine(s);
            Debug.WriteLine(titleNode1.InnerText);

            string codefileName = "URAL_" + s + $".{sourceCodeFileExt}";

            ListViewItem lvi = new ListViewItem(titleNode1.InnerText);
            lvi.SubItems.Add(codefileName);
            string desc = titleNode1.InnerText.Trim();
            HtmlNode descNode = doc.DocumentNode.SelectSingleNode("//div[@class='problem_source']");
            Dictionary<string,string> oProperty= new Dictionary<string, string>();
            oProperty.Add("filename", s);
            if (descNode != null)
            {
                desc = descNode.InnerText.Trim();
                int idx= desc.IndexOf("Problem Source:");
                if (idx > 0)
                {
                    desc = desc.Substring(idx);
                    string s1 = desc.Split(":".ToCharArray()).First();
                    string s2 = desc.Substring(s1.Length+1);
                    oProperty.Add(s1, s2);
                }

                descNode = doc.DocumentNode.SelectSingleNode("//div[@class='problem_limits']");
                if (descNode != null)
                {
                    var sArr = descNode.InnerHtml.Split(new string[] { "<br>" }, StringSplitOptions.RemoveEmptyEntries);
                    foreach (string s0 in sArr)
                    {
                        if (!string.IsNullOrEmpty(s0.Trim()))
                        {
                            string s1 = s0.Split(":".ToCharArray()).First();
                            string s2 = s0.Split(":".ToCharArray()).Last();
                            oProperty.Add(s1, s2);
                        }
                    }
                }
                //desc += $"|{descNode.InnerHtml.Trim().Replace("<br>","|")}";

                descNode = doc.DocumentNode.SelectSingleNode("//div[@class='problem_links']//span");
                if (descNode != null)
                {
                    string s1 = descNode.InnerText.Split(":".ToCharArray()).First();
                    string s2 = descNode.InnerText.Split(":".ToCharArray()).Last();
                    oProperty.Add(s1, s2);
                }
                //desc += $"|{descNode.InnerText.Trim()}";

            }
            lvi.SubItems.Add(desc);
            


            lvi.Tag = oProperty;
            this.listView1.Items.Add(lvi);
            this.listView1.EndUpdate();
            this.listView1.AutoResizeColumns(ColumnHeaderAutoResizeStyle.HeaderSize);
        }

        //GetDataPOJ
        private void GetDataPOJ(string input)
        {
            contestType = ContestType.poj;

            inputFileContent = string.Empty;
            lblContest.Text = "";
            listView1.Columns.Clear();
            listView1.Items.Clear();
            txtError.Visible = false;
            txtError.Clear();

            var url = input;
            var web = new HtmlWeb();
            HtmlDocument doc = null;
            try
            {
                doc = web.Load(url);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                MessageBox.Show(e.Message, this.Text, MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            HtmlNode titleNode1 = doc.DocumentNode.SelectSingleNode("//head/title");

            //HtmlNode titleNode1 = doc.GetElementbyId("problem-name");

            if (titleNode1 == null)
            {
                MessageBox.Show(this, "POJ网页解析错误。", this.Text, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return;
            }

            string s = titleNode1.InnerText.Split("--".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)[0];


            s = s.Trim();

            lblContest.Text = titleNode1.InnerText;

            this.listView1.Columns.Add("name", 300, HorizontalAlignment.Left);
            this.listView1.Columns.Add("file", 300, HorizontalAlignment.Left);
            this.listView1.Columns.Add("contests", 364, HorizontalAlignment.Left);
            this.listView1.BeginUpdate();

            Debug.WriteLine(s);
            Debug.WriteLine(titleNode1.InnerText);

            string codefileName = "POJ_" + s + $".{sourceCodeFileExt}";

            ListViewItem lvi = new ListViewItem(titleNode1.InnerText);
            lvi.SubItems.Add(codefileName);
            string desc = titleNode1.InnerText.Trim();
            lvi.SubItems.Add(desc);
            lvi.Tag = s;
            this.listView1.Items.Add(lvi);
            this.listView1.EndUpdate();
            this.listView1.AutoResizeColumns(ColumnHeaderAutoResizeStyle.HeaderSize);
        }

        //GetDataHDU
        private void GetDataHDU(string input)
        {
            contestType = ContestType.hdu;

            inputFileContent = string.Empty;
            lblContest.Text = "";
            listView1.Columns.Clear();
            listView1.Items.Clear();
            txtError.Visible = false;
            txtError.Clear();

            var url = input;
            var web = new HtmlWeb();
            HtmlDocument doc = null;
            try
            {
                doc = web.Load(url);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                MessageBox.Show(e.Message, this.Text, MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            HtmlNode titleNode1 = doc.DocumentNode.SelectSingleNode("//head/title");
            HtmlNode titleNode2 = doc.DocumentNode.SelectSingleNode("//h1");

            //HtmlNode titleNode1 = doc.GetElementbyId("problem-name");

            if (titleNode1 == null)
            {
                MessageBox.Show(this, "HDU Online Judge网页解析错误。", this.Text, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return;
            }

            string s = titleNode1.InnerText.Split("-".ToCharArray(), StringSplitOptions.RemoveEmptyEntries).Last();

            s = s.Trim();

            string sTitle = titleNode2 == null ? titleNode1.InnerText : titleNode2.InnerText;

            lblContest.Text = sTitle;

            this.listView1.Columns.Add("name", 300, HorizontalAlignment.Left);
            this.listView1.Columns.Add("file", 300, HorizontalAlignment.Left);
            this.listView1.Columns.Add("contests", 364, HorizontalAlignment.Left);
            this.listView1.BeginUpdate();

            Debug.WriteLine(s);
            Debug.WriteLine(titleNode1.InnerText);

            string codefileName = "HDU_" + s + $".{sourceCodeFileExt}";

            ListViewItem lvi = new ListViewItem(sTitle);
            lvi.SubItems.Add(codefileName);
            lvi.SubItems.Add(sTitle);
            lvi.Tag = s;
            this.listView1.Items.Add(lvi);
            this.listView1.EndUpdate();
            this.listView1.AutoResizeColumns(ColumnHeaderAutoResizeStyle.HeaderSize);
        }

        private JObject GetResponse(string url)
        {
            if (string.IsNullOrEmpty(url))
            {
                throw new ArgumentNullException("url");
            }



            HttpClient httpClient = new HttpClient();
            httpClient.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/json"));

            HttpResponseMessage response = httpClient.GetAsync(url).Result;
            
            string result = response.Content.ReadAsStringAsync().Result;
            //JObject jo = (JObject)JsonConvert.DeserializeObject(result);
            try
            {
                JObject jo = JObject.Parse(result);
                return jo;
            }
            catch(Exception ex)
            {
                throw new Exception(result);
            }
        }

        private void txtProblemId_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Return)
            {
                butGo_Click(sender, e);
            }
        }

        static string GetApplicationRoot()
        {
            if(Directory.Exists(Application.StartupPath+"\\..\\.."))
                return new DirectoryInfo(Application.StartupPath + "\\..\\..").FullName;
            return Application.StartupPath;
        }

        private void butOK_Click(object sender, EventArgs e)
        {
            SetSourceCodeType();

            switch (contestType)
            {
                case ContestType.codeforces:
                    CreateFileCF();
                    break;
                case ContestType.spoj:
                    CreateFileSPOJ();
                    break;
                case ContestType.usaco:
                    CreateFileUSACO();
                    break;
                case ContestType.uva:
                    CreateFileUVa();
                    break;
                case ContestType.ural:
                    CreateFileUral();
                    break;
                case ContestType.poj:
                    CreateFilePOJ();
                    break;
                case ContestType.hdu:
                    CreateFileHDU();
                    break;
                case ContestType.none:
                    CreateFileEmpty();
                    break;
            }
        }

        private void CreateFileCF()
        {
            if (listView1.CheckedItems.Count == 0)
                return;
            else if(listView1.CheckedItems.Count==1)
                CreateFileCFProblems();
            else 
                CreateFileCFContest(lblContest.Text);
        }

        private void CreateFileCFContest(string contesName)
        {

            if (listView1.CheckedItems.Count == 0)
                return;

            //Codeforces Round #634 (Div. 3)
            contesName = contesName.Replace("Codeforces", "");
            contesName = contesName.Replace("#", "_");
            contesName = contesName.Replace(".", "");
            contesName = contesName.Replace("(", "");
            contesName = contesName.Replace(")", "");
            contesName = contesName.Replace(" ", "");
            const string contestSubDir = "CF_CONTESTS";

            List<KeyValuePair<string,string>> problemIdList = new List<KeyValuePair<string, string>>();
            string msg = "";
            foreach (ListViewItem item in listView1.CheckedItems)
            {
                problemIdList.Add(new KeyValuePair<string, string>(item.SubItems[0].Text,item.Text));
                msg += item.SubItems[0].Text + "\n";
            }

            string rootPath = $"{rootDir}\\{contestSubDir}\\{contesName}";

            msg = $"即将创建以下{sourceCodeFileExt}文件夹及相关文件：\n{rootPath}\n\n{msg}\n是否继续？";
            if (MessageBox.Show(this, msg, this.Text,
                    MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                foreach (var problem in problemIdList)
                {
                    string problemKey = problem.Key;
                    string problemId = problem.Value;

                    string fileName = FormatPathName($"CF_{this.contestId}{problemId.ToUpper()}_{problemDict[problemId.ToUpper()]}");
                    //if (this.chkIntelliJ.Checked)
                    //    fileName = FormatPathName($"CF_{this.contestId}{problemId.ToUpper()}");

                    string url = $"https://codeforces.com/contest/{contestId}/problem/{problemId}";

                    string cppCode = GetTemplateSourceCode($"{contestId}{problemId.ToUpper()} {problemDict[problemId.ToUpper()]}", txtAuthor.Text, DateTime.Now.ToString("G"), url, "", fileName);
                    string filePath = $"{rootDir}\\{contestSubDir}\\{contesName}\\{problemKey}";
                    IntelliJ intelliJ=null;
                    if (this.chkIntelliJ.Checked)
                        intelliJ = new IntelliJ(txtWorkingDir.Text);
                    
                    CreateDirAndCodeFile(filePath, fileName, cppCode);
                    string srcfileName = $"{filePath}\\{fileName}.{sourceCodeFileExt}";

                    if (this.chkIntelliJ.Checked)
                    {
                        intelliJ.StartIntelliJ();
                        intelliJ.ProcessFile(filePath, fileName);
                    }

                    RunCodeIde(srcfileName);
                }
                Application.Exit();
            }
        }

        private void CreateFileCFProblems()
        {
            if (listView1.CheckedItems.Count == 0)
                return;

            List<string> problemIdList = new List<string>();
            foreach (ListViewItem item in listView1.CheckedItems)
            {
                problemIdList.Add(item.Text);
            }

            //string pathName = FormatPathName($"CF_{this.contestId}{problemIdList[0].ToUpper()}_{problemDict[problemIdList[0].ToUpper()]}");
            string msg = "";

            foreach (var item in problemIdList)
            {
                msg += FormatPathName($"CF_{this.contestId}{item.ToUpper()}_{problemDict[item.ToUpper()]}") + Environment.NewLine;
            }

            msg = $"即将创建以下{sourceCodeFileExt}文件夹及相关文件：\n{rootDir}\n\n{msg}\n是否继续？";

            //Dictionary<string, string> createResult = new Dictionary<string, string>();
            string contesName = lblContest.Text;
            if (MessageBox.Show(this, msg, this.Text,
                    MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                foreach (var problemId in problemIdList)
                {

                    string fileName = FormatPathName($"CF_{this.contestId}{problemId.ToUpper()}_{problemDict[problemId.ToUpper()]}");
                    //if (this.chkIntelliJ.Checked)
                    //    fileName = FormatPathName($"CF_{this.contestId}{problemId.ToUpper()}");

                    string url;
                    if (CfContestType == "CF" || (contesName.Contains("Codeforces") && contesName.Contains("Round")))
                        url = $"https://codeforces.com/contest/{contestId}/problem/{problemId}";
                    else
                        url = $"https://codeforces.com/gym/{contestId}/problem/{problemId}";
                    string cppCode = GetTemplateSourceCode($"{contestId}{problemId.ToUpper()} {problemDict[problemId.ToUpper()]}", txtAuthor.Text, DateTime.Now.ToString("G"), url, "", fileName);
                    string filePath = $"{rootDir}\\{fileName}";
                    IntelliJ intelliJ = null;
                    if (this.chkIntelliJ.Checked)
                        intelliJ = new IntelliJ(this.txtWorkingDir.Text);

                    CreateDirAndCodeFile($"{rootDir}\\{fileName}", fileName, cppCode);

                    string codefileName = $"{rootDir}\\{fileName}\\{fileName}.{sourceCodeFileExt}";
                    if (this.chkIntelliJ.Checked)
                    {
                        intelliJ.StartIntelliJ();
                        intelliJ.ProcessFile(filePath, fileName);
                    }
                    RunCodeIde(codefileName);
                }

                Application.Exit();
            }
        }


        private string genRandProblemId()
        {
            return (new Random(new Guid().GetHashCode()).Next(1, 999999)).ToString().PadLeft(6, '0');
        }

        private void CreateFileEmpty()
        {
            var problemId = genRandProblemId();
            string fileName = FormatPathName($"EM_{problemId}");
            string filePath = $"{rootDir}\\{fileName}";
            while (System.IO.Directory.Exists(filePath))
            {
                problemId = genRandProblemId();
                fileName = FormatPathName($"EM_{problemId}");
                filePath = $"{rootDir}\\{fileName}";
            }
            

            string msg = FormatPathName($"EM_{problemId}") + Environment.NewLine;
            

            msg = $"即将创建以下{sourceCodeFileExt}文件夹及相关文件：\n{rootDir}\n\n{msg}\n是否继续？";

            //Dictionary<string, string> createResult = new Dictionary<string, string>();
            string contesName = lblContest.Text;
            if (MessageBox.Show(this, msg, this.Text,
                    MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {


                    string cppCode = GetTemplateSourceCode("", txtAuthor.Text, DateTime.Now.ToString("G"), "", "", fileName);
                    
                    IntelliJ intelliJ = null;
                    if (this.chkIntelliJ.Checked)
                        intelliJ = new IntelliJ(this.txtWorkingDir.Text);

                    CreateDirAndCodeFile(filePath, fileName, cppCode);

                    string codefileName = $"{filePath}\\{fileName}.{sourceCodeFileExt}";
                    if (this.chkIntelliJ.Checked)
                    {
                        intelliJ.StartIntelliJ();
                        intelliJ.ProcessFile(filePath, fileName);
                    }
                    RunCodeIde(codefileName);
                

                Application.Exit();
            }
        }



        private void CreateFileUSACO()
        {
            if (listView1.CheckedItems.Count == 0)
                return;

            var item = listView1.CheckedItems[0];
            string fileName = FormatPathName(item.SubItems[1].Text.Split(".".ToCharArray())[0]);
            string subDirName = FormatPathName(item.Tag.ToString());

            //string pathName = FormatPathName($"CF_{this.contestId}{problemIdList[0].ToUpper()}_{problemDict[problemIdList[0].ToUpper()]}");
            string msg = $"即将创建以下{sourceCodeFileExt}文件夹及相关文件：\n{rootDir}\n\n{subDirName}\n是否继续？";

            if (MessageBox.Show(this, msg, this.Text,
                    MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                string cppCode = GetTemplateSourceCode(item.Text.Trim(), txtAuthor.Text, DateTime.Now.ToString("G"), this.txtProblemId.Text,item.SubItems[2].Text.Trim(), fileName);
                string filePath = $"{rootDir}\\{subDirName}";
                IntelliJ intelliJ = null;
                if (this.chkIntelliJ.Checked)
                    intelliJ = new IntelliJ(txtWorkingDir.Text);


                CreateDirAndCodeFile(filePath, fileName, cppCode);

                string codefileName = $"{filePath}\\{fileName}.{sourceCodeFileExt}";
                //System.Diagnostics.Process.Start("cmd.exe", $"/c code \"{codefileName}\"");

                if (this.chkIntelliJ.Checked)
                {
                    intelliJ.StartIntelliJ();
                    intelliJ.ProcessFile(filePath, fileName);
                }
                RunCodeIde(codefileName);

                Application.Exit();
            }
        }

        private void CreateFileSPOJ()
        {
            if (listView1.CheckedItems.Count == 0)
                return;

            var item = listView1.CheckedItems[0];
            string subDirName = FormatPathName("SPOJ_" + item.Tag.ToString());
            string fileName = item.Tag.ToString() ;

            //string pathName = FormatPathName($"CF_{this.contestId}{problemIdList[0].ToUpper()}_{problemDict[problemIdList[0].ToUpper()]}");
            string msg = $"即将创建以下{sourceCodeFileExt}文件夹及相关文件：\n{rootDir}\n\n{subDirName}\n是否继续？";

            if (MessageBox.Show(this, msg, this.Text,
                    MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                //string srcCode = "";

                //srcCode += $"/*\n";
                //srcCode += $"===========================================================\n";
                //srcCode += $"* @Name:           {item.Text.Trim()} \n";
                //srcCode += $"* @Author:         {txtAuthor.Text}\n";
                //srcCode += $"* @create Time:    {DateTime.Now.ToString("G")}\n";
                //srcCode += $"* @url:            {this.txtProblemId.Text}\n";
                //srcCode += $"* @Description:    {item.SubItems[2].Text.Trim()}\n";
                //srcCode += $"===========================================================\n";
                //srcCode += $"*/";

                string cppCode = GetTemplateSourceCode(item.Text.Trim(), txtAuthor.Text, DateTime.Now.ToString("G"), this.txtProblemId.Text, item.SubItems[2].Text.Trim(), fileName);

                CreateDirAndCodeFile($"{rootDir}\\{subDirName}", fileName, cppCode);

                string codefileName = $"{rootDir}\\{subDirName}\\{fileName}.{sourceCodeFileExt}";
                RunCodeIde(codefileName);
                //System.Diagnostics.Process.Start("cmd.exe", $"/c code \"{codefileName}\"");
                Application.Exit();
            }
        }

        
        private void CreateFileUral()
        {
            if (listView1.CheckedItems.Count == 0)
                return;

            var item = listView1.CheckedItems[0];

            Dictionary<string, string> oProperty = item.Tag as Dictionary<string, string>;

            if(oProperty==null)
                return;

            string subDirName = FormatPathName("URAL_" + oProperty["filename"]);
            string fileName = "URAL_" + oProperty["filename"];

            //string pathName = FormatPathName($"CF_{this.contestId}{problemIdList[0].ToUpper()}_{problemDict[problemIdList[0].ToUpper()]}");
            string msg = $"即将创建以下{sourceCodeFileExt}文件夹及相关文件：\n{rootDir}\n\n{subDirName}\n是否继续？";

            if (MessageBox.Show(this, msg, this.Text,
                    MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                //string srcCode = "";

                //srcCode += $"/*\n";
                //srcCode += $"===========================================================\n";
                //srcCode += $"* @Name:            {item.Text.Trim()} \n";
                //srcCode += $"* @Author:          {txtAuthor.Text}\n";
                //srcCode += $"* @create Time:     {DateTime.Now.ToString("G")}\n";
                //srcCode += $"* @url:             {this.txtProblemId.Text}\n";
                //srcCode += $"* @Description:     \n";

                //foreach (string s in oProperty.Keys)
                //    if (s != "filename")
                //    {
                //        string temp = $"* @{s}:".PadRight(19);
                //        srcCode += $"{temp}{oProperty[s]}\n";
                //    }


                //srcCode += $"===========================================================\n";
                //srcCode += $"*/";

                string desc = "\n";
                foreach (string s in oProperty.Keys)
                    if (s != "filename")
                    {
                        string temp = $"* @{s}:".PadRight(19);
                        desc += $"{temp}{oProperty[s]}\n";
                    }

                string cppCode = GetTemplateSourceCode(item.Text.Trim(), txtAuthor.Text, DateTime.Now.ToString("G"), this.txtProblemId.Text, desc, fileName);

                CreateDirAndCodeFile($"{rootDir}\\{subDirName}", fileName, cppCode);

                string codefileName = $"{rootDir}\\{subDirName}\\{fileName}.{sourceCodeFileExt}";
                RunCodeIde(codefileName);
                //System.Diagnostics.Process.Start("cmd.exe", $"/c code \"{codefileName}\"");
                Application.Exit();
            }
        }

        //CreateFilePOJ
        private void CreateFilePOJ()
        {
            if (listView1.CheckedItems.Count == 0)
                return;

            var item = listView1.CheckedItems[0];

            string  tag = item.Tag as string;

            if (tag == null)
                return;

            string subDirName = FormatPathName($"POJ_{tag}");
            string fileName = $"POJ_{tag}";

            //string pathName = FormatPathName($"CF_{this.contestId}{problemIdList[0].ToUpper()}_{problemDict[problemIdList[0].ToUpper()]}");
            string msg = $"即将创建以下{sourceCodeFileExt}文件夹及相关文件：\n{rootDir}\n\n{subDirName}\n是否继续？";

            if (MessageBox.Show(this, msg, this.Text,
                    MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                string cppCode = "";

                cppCode += $"/*\n";
                cppCode += $"===========================================================\n";
                cppCode += $"* @Name:            {item.Text.Trim()} \n";
                cppCode += $"* @Author:          {txtAuthor.Text}\n";
                cppCode += $"* @create Time:     {DateTime.Now.ToString("G")}\n";
                cppCode += $"* @url:             {this.txtProblemId.Text}\n";
                cppCode += $"* @Description:     \n";


                cppCode += $"===========================================================\n";
                cppCode += $"*/";

                CreateDirAndCodeFile($"{rootDir}\\{subDirName}", fileName, cppCode);

                string codefileName = $"{rootDir}\\{subDirName}\\{fileName}.{sourceCodeFileExt}";
                RunCodeIde(codefileName);
                Application.Exit();
            }
        }

        //CreateFileHDU
        private void CreateFileHDU()
        {
            if (listView1.CheckedItems.Count == 0)
                return;

            var item = listView1.CheckedItems[0];

            string tag = item.Tag as string;

            if (tag == null)
                return;

            string subDirName = FormatPathName($"HDU_{tag}");
            string fileName = $"HDU_{tag}";

            //string pathName = FormatPathName($"CF_{this.contestId}{problemIdList[0].ToUpper()}_{problemDict[problemIdList[0].ToUpper()]}");
            string msg = $"即将创建以下{sourceCodeFileExt}文件夹及相关文件：\n{rootDir}\n\n{subDirName}\n是否继续？";

            if (MessageBox.Show(this, msg, this.Text,
                MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                //string srcCode = "";

                //srcCode += $"/*\n";
                //srcCode += $"===========================================================\n";
                //srcCode += $"* @Name:            {item.Text.Trim()} \n";
                //srcCode += $"* @Author:          {txtAuthor.Text}\n";
                //srcCode += $"* @create Time:     {DateTime.Now.ToString("G")}\n";
                //srcCode += $"* @url:             {this.txtProblemId.Text}\n";
                //srcCode += $"* @Description:     \n";


                //srcCode += $"===========================================================\n";
                //srcCode += $"*/";

                string cppCode = GetTemplateSourceCode(item.Text.Trim(), txtAuthor.Text, DateTime.Now.ToString("G"), this.txtProblemId.Text, "", fileName);
                CreateDirAndCodeFile($"{rootDir}\\{subDirName}", fileName, cppCode);

                string codefileName = $"{rootDir}\\{subDirName}\\{fileName}.{sourceCodeFileExt}";
                RunCodeIde(codefileName);
                Application.Exit();
            }
        }

        private void CreateFileUVa()
        {
            if (listView1.CheckedItems.Count == 0)
                return;

            var item = listView1.CheckedItems[0];
            string fileName = item.Tag.ToString();

            //string pathName = FormatPathName($"CF_{this.contestId}{problemIdList[0].ToUpper()}_{problemDict[problemIdList[0].ToUpper()]}");
            string msg = $"即将创建以下{sourceCodeFileExt}文件夹及相关文件：\n{rootDir}\n\n{fileName}\n是否继续？";

            if (MessageBox.Show(this, msg, this.Text,
                    MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                string cppCode = GetTemplateSourceCode($"UVa-{item.Text} {item.SubItems[1].Text}", txtAuthor.Text, DateTime.Now.ToString("G"), "","", fileName);
                string filePath = $"{rootDir}\\{fileName}";
                IntelliJ intelliJ = null;
                if (this.chkIntelliJ.Checked)
                    intelliJ = new IntelliJ(this.txtWorkingDir.Text);

                CreateDirAndCodeFile(filePath, fileName, cppCode);
                
                string codefileName = $"{filePath}\\{fileName}.{sourceCodeFileExt}";
                if (this.chkIntelliJ.Checked)
                {
                    intelliJ.StartIntelliJ();
                    intelliJ.ProcessFile(filePath, fileName);
                }
                RunCodeIde(codefileName);

                Application.Exit();
            }
        }

        private string GetTemplateSourceCode(string p_Name,string p_Author,string p_CreateTime, string p_Url,string p_Description,string p_fileNameNoExtension)
        {
            string templateFile = $"{System.IO.Path.GetDirectoryName(Application.ExecutablePath)}\\template.{sourceCodeFileExt}";
            string cppCode = "";
            
            if(_timeZoneDict.ContainsKey(TimeZoneInfo.Local.Id))
                p_CreateTime += $" {_timeZoneDict[TimeZoneInfo.Local.Id]}";

            if (File.Exists(templateFile))
            {
                cppCode = File.ReadAllText(templateFile);
                cppCode = cppCode.Replace("{Name}", p_Name);
                cppCode = cppCode.Replace("{Author}", p_Author);
                cppCode = cppCode.Replace("{CreateTime}", p_CreateTime);
                cppCode = cppCode.Replace("{Url}", p_Url);
                cppCode = cppCode.Replace("{Description}", p_Description);
                cppCode = cppCode.Replace("{fileNameNoExtension}", p_fileNameNoExtension);
            }
            else
            {
                cppCode += $"/*\n";
                cppCode += $"===========================================================\n";
                cppCode += $"* @Name:           {p_Name}\n";
                cppCode += $"* @Author:         {p_Author}\n";
                cppCode += $"* @Create Time:    {p_CreateTime}\n";
                cppCode += $"* @Url:            {p_Url}\n";
                cppCode += $"* @Description:    {p_Description}\n";
                cppCode += $"===========================================================\n";
                cppCode += $"*/";
            }
            return cppCode;
        }

        private string CreateDirAndCodeFile(string path, string fileName, string srcCode)
        {
            string result = string.Empty;
            if (!Directory.Exists(path))
                Directory.CreateDirectory(path);

            string codefileName = $"{path}\\{fileName}.{sourceCodeFileExt}";
            if (!File.Exists(codefileName))
            {
                using (StreamWriter sw = File.CreateText(codefileName))
                {
                    sw.WriteLine(srcCode);
                }
            }
            else
            {
                result = $"Source Code File Existed!";
            }

            string infileName = $"{path}\\{fileName}.in";
            if (!File.Exists(infileName))
            {
                using (StreamWriter sw = File.CreateText(infileName))
                {
                    if(!string.IsNullOrEmpty(inputFileContent))
                        sw.Write(inputFileContent);
                }
            }
            else
            {
                result += $",in File Existed";
            }
            return result.TrimStart(",".ToCharArray());
        }

        private void RunCodeIde(string codeFile)
        {
            if (chkvscode.Checked)
                RunVSCode(codeFile);
            else if (chkIntelliJ.Enabled && chkIntelliJ.Checked)
                RunIntelliJ(codeFile);
        }

        private void RunVSCode(string codeFile)
        {
            //string exe = "\"%LOCALAPPDATA%\\Programs\\Microsoft VS Code\\Code.exe\"";

            string vsCodeExe = string.Empty;
            //从进程中获取vscode路径
            Process[] ps = Process.GetProcessesByName("Code");
            foreach (Process p in ps)
            {
                //输出进程路径
                if (p.MainModule.FileVersionInfo.FileDescription == "Visual Studio Code")
                {
                    Debug.WriteLine(p.MainModule.FileName);
                    vsCodeExe = p.MainModule.FileName;
                    break;
                }
            }

            //获取不到,缺省路径启动一个进程
            if(string.IsNullOrEmpty(vsCodeExe))
                vsCodeExe = System.Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData) + @"\Programs\Microsoft VS Code\Code.exe";

            //缺省路径找不到Code.exe，使用环境变量
            if (!System.IO.File.Exists(vsCodeExe))
                vsCodeExe = "code";

            System.Diagnostics.Process.Start(vsCodeExe, $"\"{codeFile}\"");
        }
        

        private void RunIntelliJ(string codeFile)
        {

            string intelliJExe = IntelliJ.GetIntelliJExePath(out bool isRunning);

            //缺省路径找不到Code.exe，使用环境变量
            if (!System.IO.File.Exists(intelliJExe))
                intelliJExe = "idea64";

            System.Diagnostics.Process.Start(intelliJExe, $"\"{codeFile}\"");

        }

        private string FormatPathName(string name)
        {
            string invalid = new string(Path.GetInvalidFileNameChars()) + new string(Path.GetInvalidPathChars());
            List<string> otherInvalidChars = new List<string>() { ",", " ", "'","(", ")","[", "]","\"","#",".", "+", "-" };

            string pathName = name;
            foreach (char c in invalid)
                pathName = pathName.Replace(c.ToString(), "");
            
            foreach(string s in otherInvalidChars)
                pathName = pathName.Replace(s, "");

            pathName = pathName.Replace("-", "_");

            return pathName;
        }


        private void butBrowse_Click(object sender, EventArgs e)
        {
            if (Directory.Exists(txtWorkingDir.Text))
                this.folderBrowserDialog1.SelectedPath = txtWorkingDir.Text;

            this.folderBrowserDialog1.ShowNewFolderButton = true;
            if (this.folderBrowserDialog1.ShowDialog(this) == DialogResult.OK)
            {
                Registry.RegWrite("WorkingDir", folderBrowserDialog1.SelectedPath);
                this.txtWorkingDir.Text = folderBrowserDialog1.SelectedPath;
            }
        }

        private void listView1_DoubleClick(object sender, EventArgs e)
        {
            if (listView1.FocusedItem != null)
            {
                string url = string.Empty;
                if (contestType == ContestType.codeforces)
                {
                    var id = listView1.FocusedItem.Text;
                    url = $"https://codeforces.com/problemset/problem/{this.contestId}/{id}";
                }
                else if (contestType == ContestType.usaco || contestType == ContestType.spoj || contestType == ContestType.ural)
                {
                    url = this.txtProblemId.Text;
                }

                if(!string.IsNullOrEmpty(url))
                    Process.Start(url);
            }
        }

        private void frmCFHelper_FormClosed(object sender, FormClosedEventArgs e)
        {
            SaveWindowsState();
            Registry.RegWrite("Author", this.txtAuthor.Text); 
        }

        private void CheckCFAuth()
        {
            PicCFAuth.Visible = false;
            string apiKey = Registry.RegRead("CFKey");
            string apiSecret = Registry.RegRead("CFSecret");

            if (!string.IsNullOrEmpty(apiKey) && !string.IsNullOrEmpty(apiSecret))
            {
                contestId = 556;
                dynamic o = GetCfContest(contestId.ToString(), out Exception ex);

                if (o != null)
                {
                    PicCFAuth.Visible = true;
                    if (o.status == "OK")
                    {
                        PicCFAuth.Image = Resources.user_ok;
                    }
                    else
                    {
                        PicCFAuth.Image = Resources.user_error;
                    }
                }

            }
        }

        
        private void GetWindowsState()
        {
            string sHeight = Registry.RegRead("Form.Height");
            string sWidth = Registry.RegRead("Form.Width");
            string sWindowState = Registry.RegRead("Form.WindowState");
            if (sWindowState == "2")
            {
                this.WindowState = FormWindowState.Maximized;
            }
            else if (!string.IsNullOrEmpty(sHeight) && !string.IsNullOrEmpty(sWidth))
            {
                if (int.TryParse(sHeight, out int iHeight) && int.TryParse(sWidth, out int iWidth))
                {
                    if (iHeight > 480 && iHeight <= Screen.PrimaryScreen.WorkingArea.Height && iWidth > 640 && iWidth <= Screen.PrimaryScreen.WorkingArea.Width)
                    {
                        this.Size = new Size(iWidth, iHeight);

                        //居中
                        this.Left = Screen.PrimaryScreen.WorkingArea.Width / 2 - iWidth / 2;
                        this.Top = Screen.PrimaryScreen.WorkingArea.Height / 2 - iHeight / 2;
                    }
                }
            }
        }

        private void SaveWindowsState()
        {
            Registry.RegWrite("Form.Height", this.Size.Height.ToString());
            Registry.RegWrite("Form.Width", this.Size.Width.ToString());
            if (this.WindowState == FormWindowState.Maximized)
                Registry.RegWrite("Form.WindowState", "2");
            else
                Registry.RegWrite("Form.WindowState", "0");
        }

        private void frmCFHelper_Activated(object sender, EventArgs e)
        {
            this.txtProblemId.Focus();
        }

        private void CheckedChanged(object sender, EventArgs e)
        {
            var objRadioButton =  sender as RadioButton;
            if (objRadioButton != null)
            {
                if (objRadioButton.Checked)
                {
                    Registry.RegWrite("OJType", objRadioButton.Name);
                    if (objRadioButton.Name == "emptyCode")
                    {
                        contestType = ContestType.none;
                        this.txtProblemId.Clear();
                        this.listView1.Clear();

                        this.txtProblemId.Enabled = false;
                        this.listView1.Enabled = false;
                        this.butGo.Enabled = false;
                    }
                    else
                    {
                        this.txtProblemId.Enabled = true;
                        this.listView1.Enabled = true;
                        this.butGo.Enabled = true;
                    }
                }
            }
        }

        private void linkCFAuthorization_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            if((new frmCFAuthorization().ShowDialog(this)== DialogResult.OK))
            {
                CheckCFAuth();
            }
        }

        private void SetSourceCodeType()
        {
            if (sourceCpp.Checked)
                sourceCodeFileExt = "cpp";
            else if (sourceJava.Checked)
                sourceCodeFileExt = "java";
        }

        private void sourceCpp_Click(object sender, EventArgs e)
        {
            chkIntelliJ.Enabled = false;
            chkvscode.Checked = true;
            SetSourceCodeType();
            if (!string.IsNullOrEmpty(txtProblemId.Text))
                RefreshtProblem();

        }

        private void sourceJava_Click(object sender, EventArgs e)
        {
            chkIntelliJ.Enabled = true;
            SetSourceCodeType();
            if (!string.IsNullOrEmpty(txtProblemId.Text))
                RefreshtProblem();
        }

        private void IntelliJ_CheckedChanged(object sender, EventArgs e)
        {
            if (chkIntelliJ.Checked)
            {
                var intelliJ = new IntelliJ(txtWorkingDir.Text);
                _javaModuleDir = intelliJ.ModuleDir;
                if (!string.IsNullOrEmpty(intelliJ.ModuleName))
                    picIntelliJOK.Visible = true;
            }
            else
            {
                _javaModuleDir = string.Empty;
                picIntelliJOK.Visible = false;
            }
        }

        private void listView1_DrawColumnHeader(object sender, DrawListViewColumnHeaderEventArgs e)
        {
            if (e.ColumnIndex == 0)
            {
                e.DrawBackground();
                bool value = false;
                try
                {
                    value = Convert.ToBoolean(e.Header.Tag);
                }
                catch (Exception)
                {
                }
                CheckBoxRenderer.DrawCheckBox(e.Graphics,
                    new Point(e.Bounds.Left + 4, e.Bounds.Top + 4),
                    value ? System.Windows.Forms.VisualStyles.CheckBoxState.CheckedNormal :
                    System.Windows.Forms.VisualStyles.CheckBoxState.UncheckedNormal);
            }
            else
            {
                e.DrawDefault = true;
            }
        }

        private void listView1_DrawItem(object sender, DrawListViewItemEventArgs e)
        {
            e.DrawDefault = true;
        }

        private void listView1_DrawSubItem(object sender, DrawListViewSubItemEventArgs e)
        {
            e.DrawDefault = true;
        }

        private void listView1_ColumnClick(object sender, ColumnClickEventArgs e)
        {
            if (e.Column == 0)
            {
                bool value = false;
                try
                {
                    value = Convert.ToBoolean(this.listView1.Columns[e.Column].Tag);
                }
                catch (Exception)
                {
                }
                this.listView1.Columns[e.Column].Tag = !value;
                foreach (ListViewItem item in this.listView1.Items)
                    item.Checked = !value;

                this.listView1.Invalidate();
            }
        }
    }
}
