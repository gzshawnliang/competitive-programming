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
using Newtonsoft.Json.Linq;
using System.Threading.Tasks;
using HtmlAgilityPack;
using Microsoft.Win32;
using Newtonsoft.Json;
using HtmlDocument = HtmlAgilityPack.HtmlDocument;

namespace CFHelperUI
{
    public partial class frmCFHelper : Form
    {
        private int contestId=0;
        private Dictionary<string, string> problemDict;
        private readonly string _defaultDir;

        private string inputFileContent;    //USACO SAMPLE INPUT数据

        private string rootDir
        {
            get { return this.txtWorkingDir.Text; }
        }
        private enum ContestType
        {
            codeforces,
            usaco,
            spoj,
            uva,
            ural
        }

        private ContestType contestType;

        public frmCFHelper()
        {
            InitializeComponent();
        }

        public frmCFHelper(string defaultDir):this()
        {
            _defaultDir = defaultDir;
        }

        private void butCancel_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void butGo_Click(object sender, EventArgs e)
        {
            string input = this.txtProblemId.Text.Trim();
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
            else if (uva.Checked)
            {
                GetDataUVa(input);
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
            txtError.Visible = false;
            txtError.Clear();

            

            //HttpClient client = new HttpClient();
            string url =
                $"https://codeforces.com/api/contest.standings?contestId={contestId}&from=1&count=1&showUnofficial=true";

            //if (Regex.Matches(input, "[a-zA-Z]").Count > 0)
            //{
            //    problemId = Regex.Replace(input, "[0-9]", "", RegexOptions.IgnoreCase);
            //}

            //Task<string> problems = GetProblemInfo(url);
            try
            {
                dynamic o = GetResponse(url);
                string ids = string.Empty;

                if (o.status == "OK")
                {
                    problemDict = new Dictionary<string, string>();

                    lblContest.Text = o.result.contest.name;

                    this.listView1.Columns.Add("id", 36, HorizontalAlignment.Left);
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
            catch (Exception e)
            {
                //Console.WriteLine(e);
                txtError.Text = e.ToString();
                txtError.Visible = true;
                lblContest.Text = e.Message;
                //throw;
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
                    lvi.SubItems.Add(s + ".cpp");
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

            string cppFileName = string.Empty;
            /*
             从以下字符串查找paintbarn.in
             INPUT FORMAT (file paintbarn.in):
            */
            Regex reg = new Regex(@"\w*\.\w*");
            Match result = reg.Match(inputFileNode1.InnerText);
            if (result.Success)
            {
                Debug.WriteLine( result.Value);
                cppFileName = result.Value.Split(".".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)[0]+".cpp";
            }


            ListViewItem lvi = new ListViewItem(titleNode2.InnerText.Trim());
            lvi.SubItems.Add(cppFileName);
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

            string cppFileName = s + ".cpp";

            ListViewItem lvi = new ListViewItem(s);
            lvi.SubItems.Add(cppFileName);
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

            string cppFileName = "URAL_" + s + ".cpp";

            ListViewItem lvi = new ListViewItem(titleNode1.InnerText);
            lvi.SubItems.Add(cppFileName);
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
                    string s1 = desc.Split(":".ToCharArray())[0];
                    string s2 = desc.Split(":".ToCharArray())[1];
                    oProperty.Add(s1,s2);
                }

                descNode = doc.DocumentNode.SelectSingleNode("//div[@class='problem_limits']");
                if (descNode != null)
                {
                    foreach (string s0 in descNode.InnerText.Split("<br>".ToCharArray()))
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
            JObject jo = (JObject)JsonConvert.DeserializeObject(result);
            return jo;
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
            //var exePath = Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().CodeBase);
            //Regex appPathMatcher = new Regex(@"(?<!fil)[A-Za-z]:\\+[\S\s]*?(?=\\+bin)");
            //var appRoot = appPathMatcher.Match(exePath).Value;
            //return appRoot;
            if(Directory.Exists(Application.StartupPath+"\\..\\.."))
                return new DirectoryInfo(Application.StartupPath + "\\..\\..").FullName;
            return Application.StartupPath;
        }

        private void butOK_Click(object sender, EventArgs e)
        {
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
            }
        }

        private void CreateFileCF()
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

            msg = $"即将创建以下C++文件夹及相关文件：\n{rootDir}\n\n{msg}\n是否继续？";

            //Dictionary<string, string> createResult = new Dictionary<string, string>();
            if (MessageBox.Show(this, msg, this.Text,
                    MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                foreach (var problemId in problemIdList)
                {

                    string cppCode = "";

                    cppCode += $"/*\n";
                    cppCode += $"===========================================================\n";
                    cppCode +=
                        $"* @Name:           {contestId}{problemId.ToUpper()} {problemDict[problemId.ToUpper()]}\n";
                    cppCode += $"* @Author:         {txtAuthor.Text}\n";
                    cppCode += $"* @create Time:    {DateTime.Now.ToString("G")}\n";
                    cppCode +=
                        $"* @url:            https://codeforces.com/contest/{contestId}/problem/{problemId}\n";
                    cppCode += $"* @Description:    \n";
                    cppCode += $"===========================================================\n";
                    cppCode += $"*/";

                    string fileName = FormatPathName($"CF_{this.contestId}{problemId.ToUpper()}_{problemDict[problemId.ToUpper()]}");

                    CreateDirAndCppFile($"{rootDir}\\{fileName}", fileName, cppCode);

                    string cppfileName = $"{rootDir}\\{fileName}\\{fileName}.cpp";
                    RunVSCode(cppfileName);
                    //System.Diagnostics.Process.Start("cmd.exe",$"/c code \"{cppfileName}\"");

                    //string result = CreateDirAndCppFile($"{rootDir}\\{fileName}", fileName, cppCode);
                    //createResult.Add(problemId.ToUpper(), result);
                }

                //msg = $"创建C++文件夹及相关文件完成：\n{rootDir}\n\n";
                //foreach (var problemId in problemIdList)
                //{
                //    string fileName = FormatPathName($"CF_{this.contestId}{problemId.ToUpper()}_{problemDict[problemId.ToUpper()]}");
                //    msg += $"{fileName}:{(string.IsNullOrEmpty(createResult[problemId]) ? "成功" : createResult[problemId])}\n";
                //}

                //msg += "\n是否打开文件夹查看？";
                //if (MessageBox.Show(this, msg, this.Text, MessageBoxButtons.YesNoCancel, MessageBoxIcon.Information) ==
                //    DialogResult.Yes)
                //{
                //    System.Diagnostics.Process.Start(rootDir);
                //}

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
            string msg = $"即将创建以下C++文件夹及相关文件：\n{rootDir}\n\n{subDirName}\n是否继续？";

            if (MessageBox.Show(this, msg, this.Text,
                    MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                string cppCode = "";

                cppCode += $"/*\n";
                cppCode += $"===========================================================\n";
                cppCode += $"* @Name:           {item.Text.Trim()} \n";
                cppCode += $"* @Author:         {txtAuthor.Text}\n";
                cppCode += $"* @create Time:    {DateTime.Now.ToString("G")}\n";
                cppCode += $"* @url:            {this.txtProblemId.Text}\n";
                cppCode += $"* @Description:    {item.SubItems[2].Text.Trim()}\n";
                cppCode += $"===========================================================\n";
                cppCode += $"*/";

                CreateDirAndCppFile($"{rootDir}\\{subDirName}", fileName, cppCode);

                //msg = $"创建C++文件夹及相关文件完成：\n{rootDir}\n\n";
                //msg += "\n是否打开文件夹查看？";

                //if (MessageBox.Show(this, msg, this.Text, MessageBoxButtons.YesNoCancel, MessageBoxIcon.Information) ==
                //    DialogResult.Yes)
                //{
                //    System.Diagnostics.Process.Start(rootDir);
                //}

                string cppfileName = $"{rootDir}\\{subDirName}\\{fileName}.cpp";
                //System.Diagnostics.Process.Start("cmd.exe", $"/c code \"{cppfileName}\"");
                RunVSCode(cppfileName);

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
            string msg = $"即将创建以下C++文件夹及相关文件：\n{rootDir}\n\n{subDirName}\n是否继续？";

            if (MessageBox.Show(this, msg, this.Text,
                    MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                string cppCode = "";

                cppCode += $"/*\n";
                cppCode += $"===========================================================\n";
                cppCode += $"* @Name:           {item.Text.Trim()} \n";
                cppCode += $"* @Author:         {txtAuthor.Text}\n";
                cppCode += $"* @create Time:    {DateTime.Now.ToString("G")}\n";
                cppCode += $"* @url:            {this.txtProblemId.Text}\n";
                cppCode += $"* @Description:    {item.SubItems[2].Text.Trim()}\n";
                cppCode += $"===========================================================\n";
                cppCode += $"*/";

                CreateDirAndCppFile($"{rootDir}\\{subDirName}", fileName, cppCode);

                //msg = $"创建C++文件夹及相关文件完成：\n{rootDir}\n\n";
                //msg += "\n是否打开文件夹查看？";

                //if (MessageBox.Show(this, msg, this.Text, MessageBoxButtons.YesNoCancel, MessageBoxIcon.Information) ==
                //    DialogResult.Yes)
                //{
                //    System.Diagnostics.Process.Start(rootDir);
                //}
                string cppfileName = $"{rootDir}\\{subDirName}\\{fileName}.cpp";
                RunVSCode(cppfileName);
                //System.Diagnostics.Process.Start("cmd.exe", $"/c code \"{cppfileName}\"");
                Application.Exit();
            }
        }

        //CreateFileUral
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
            string msg = $"即将创建以下C++文件夹及相关文件：\n{rootDir}\n\n{subDirName}\n是否继续？";

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
                cppCode += $"* @Description:     {item.SubItems[2].Text.Trim().Replace("|","\n")}\n";

                foreach (string s in oProperty.Keys)
                    if(s != "filename")
                        cppCode += $"* @{s}:     {oProperty[s]}\n";
                

                cppCode += $"===========================================================\n";
                cppCode += $"*/";

                CreateDirAndCppFile($"{rootDir}\\{subDirName}", fileName, cppCode);

                //msg = $"创建C++文件夹及相关文件完成：\n{rootDir}\n\n";
                //msg += "\n是否打开文件夹查看？";

                //if (MessageBox.Show(this, msg, this.Text, MessageBoxButtons.YesNoCancel, MessageBoxIcon.Information) ==
                //    DialogResult.Yes)
                //{
                //    System.Diagnostics.Process.Start(rootDir);
                //}
                string cppfileName = $"{rootDir}\\{subDirName}\\{fileName}.cpp";
                RunVSCode(cppfileName);
                //System.Diagnostics.Process.Start("cmd.exe", $"/c code \"{cppfileName}\"");
                Application.Exit();
            }
        }

        private void CreateFileUVa()
        {
            if (listView1.CheckedItems.Count == 0)
                return;

            var item = listView1.CheckedItems[0];
            string subDirName = item.Tag.ToString();

            //string pathName = FormatPathName($"CF_{this.contestId}{problemIdList[0].ToUpper()}_{problemDict[problemIdList[0].ToUpper()]}");
            string msg = $"即将创建以下C++文件夹及相关文件：\n{rootDir}\n\n{subDirName}\n是否继续？";

            if (MessageBox.Show(this, msg, this.Text,
                    MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                string cppCode = "";

                cppCode += $"/*\n";
                cppCode += $"===========================================================\n";
                cppCode += $"* @Name:           UVa-{item.Text} {item.SubItems[1].Text}\n";
                cppCode += $"* @Author:         {txtAuthor.Text}\n";
                cppCode += $"* @create Time:    {DateTime.Now.ToString("G")}\n";
                cppCode += $"* @url:            \n";
                cppCode += $"* @Description:    \n";
                cppCode += $"===========================================================\n";
                cppCode += $"*/";

                CreateDirAndCppFile($"{rootDir}\\{subDirName}", subDirName, cppCode);
                
                string cppfileName = $"{rootDir}\\{subDirName}\\{subDirName}.cpp";
                RunVSCode(cppfileName);

                Application.Exit();
            }
        }

        private string CreateDirAndCppFile(string path, string fileName, string cppCode)
        {
            string result = string.Empty;
            if (!Directory.Exists(path))
                Directory.CreateDirectory(path);

            string cppfileName = $"{path}\\{fileName}.cpp";
            if (!File.Exists(cppfileName))
            {
                using (StreamWriter sw = File.CreateText(cppfileName))
                {
                    sw.WriteLine(cppCode);
                }
            }
            else
            {
                result = $"cpp文件已存在";
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
                result += $",in文件已存在";
            }
            return result.TrimStart(",".ToCharArray());
        }

        private void RunVSCode(string cppFile)
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

            System.Diagnostics.Process.Start(vsCodeExe, $"\"{cppFile}\"");

            //string vsCodeExe = System.Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData) + @"\Programs\Microsoft VS Code\Code.exe";
            //if (!System.IO.File.Exists(vsCodeExe))
            //{
            //    vsCodeExe = "code";
            //}
            //System.Diagnostics.Process.Start(vsCodeExe, $"\"{cppFile}\"");
        }

        private string FormatPathName(string name)
        {
            string invalid = new string(Path.GetInvalidFileNameChars()) + new string(Path.GetInvalidPathChars());

            string pathName = name;
            foreach (char c in invalid)
            {
                pathName = pathName.Replace(c.ToString(), "");
            }
            pathName = pathName.Replace("-", "_");
            pathName = pathName.Replace(" ", "");
            pathName = pathName.Replace("'", "");

            return pathName;
        }

        private void butBrowse_Click(object sender, EventArgs e)
        {
            if (Directory.Exists(txtWorkingDir.Text))
                this.folderBrowserDialog1.SelectedPath = txtWorkingDir.Text;

            this.folderBrowserDialog1.ShowNewFolderButton = true;
            if (this.folderBrowserDialog1.ShowDialog(this) == DialogResult.OK)
            {
                RegWrite("WorkingDir", folderBrowserDialog1.SelectedPath);
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
            RegWrite("Author", this.txtAuthor.Text); 
        }

        private void frmCFHelper_Load(object sender, EventArgs e)
        {
            //this.Text += "["+_defaultDir;
            txtWorkingDir.Text = RegRead("WorkingDir");
            if (string.IsNullOrEmpty(txtWorkingDir.Text.TrimEnd()))
                if (!string.IsNullOrEmpty(_defaultDir))
                    txtWorkingDir.Text = _defaultDir;
                else
                    txtWorkingDir.Text = GetApplicationRoot();

            GetWindowsState();
            this.txtAuthor.Text = RegRead("Author");

            string currFilePath = Assembly.GetExecutingAssembly().Location;
            DateTime dt = new FileInfo(currFilePath).LastWriteTime;
            this.Text += $" {dt.ToString("yyyyMMddHHmm")}";

            var ojType = RegRead("OJType");
            if (!string.IsNullOrEmpty(ojType))
            {
                switch (ojType)
                {
                    case "codeforces":
                        codeforces.Checked = true;
                        break;
                    case "uva":
                        uva.Checked = true;
                        break;
                    case "usaco":
                        usaco.Checked = true;
                        break;
                    case "spoj":
                        spoj.Checked = true;
                        break;
                }
            }
        }

        private string RegRead(string keyName)
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

        private void RegWrite(string keyName, string value)
        {
            string subKey = "SOFTWARE\\" + Application.ProductName;

            RegistryKey sk1 = Microsoft.Win32.Registry.CurrentUser.CreateSubKey(subKey);
            sk1.SetValue(keyName, value);
        }

        private void GetWindowsState()
        {
            string sHeight = RegRead("Form.Height");
            string sWidth = RegRead("Form.Width");
            string sWindowState = RegRead("Form.WindowState");
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
            RegWrite("Form.Height", this.Size.Height.ToString());
            RegWrite("Form.Width", this.Size.Width.ToString());
            if (this.WindowState == FormWindowState.Maximized)
                RegWrite("Form.WindowState", "2");
            else
                RegWrite("Form.WindowState", "0");
        }

        private void frmCFHelper_Activated(object sender, EventArgs e)
        {
            this.txtProblemId.Focus();
        }

        private void CheckedChanged(object sender, EventArgs e)
        {
            var objRadioButton =  sender as RadioButton;
            if (objRadioButton != null)
                if(objRadioButton.Checked)
                    RegWrite("OJType", objRadioButton.Name);
        }
    }
}
