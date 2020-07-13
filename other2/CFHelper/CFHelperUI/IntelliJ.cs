using System;
using System.Collections.Generic;
using System.Linq;
using System.Xml.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;
using System.Diagnostics;
using System.Threading;

namespace OJAssistantUI
{
    public class IntelliJ
    {
        public string ModuleName { get; set; }
        public string ModuleDir { get; set; }

        private string _initDirName;
        private string _moduleFileName;
        private string _fullModuleFileName;
        private string _iprFileName;

        public  IntelliJ(string dirName)
        {
            _initDirName = dirName;
            ModuleName = string.Empty;
            ModuleDir = string.Empty;
            _moduleFileName = string.Empty;
            _iprFileName = string.Empty;

            //获取ipr项目文件路径
            _iprFileName = FindFileInDirectory(dirName, "*.ipr");
            if (!string.IsNullOrEmpty(_iprFileName))
                HandleIpr(_iprFileName);

            //获取模块名称和路径
            _fullModuleFileName = FindFileInDirectory(_initDirName, _moduleFileName);
            if (!string.IsNullOrEmpty(_fullModuleFileName))
                ModuleDir = new FileInfo(_fullModuleFileName).Directory.FullName;
        }

        public void StartIntelliJ()
        {
            if (!string.IsNullOrEmpty(_iprFileName))
            {
                string exeIntelliJFile = GetIntelliJExePath(out bool isRunning);
                if (!string.IsNullOrEmpty(exeIntelliJFile))
                {
                    var process = Process.Start(exeIntelliJFile, $"\"{_iprFileName}\"");

                    var start = DateTime.Now;
                    int timeout = 10000;
                    while (!process.HasExited && process.MainWindowHandle == IntPtr.Zero)
                    {
                        Thread.Sleep(10);
                        if ((DateTime.Now - start).TotalMilliseconds >= timeout)
                        {
                            return ;
                        }
                    }
                }
            }
        }

        public static string GetIntelliJExePath(out bool isRunning)
        {
            //Environment.SpecialFolder.ProgramFiles
            string intelliJExe = string.Empty;
            isRunning = false;

            //从进程中获取vscode路径
            Process[] ps = Process.GetProcessesByName("idea64");
            foreach (Process p in ps)
            {
                //输出进程路径
                if (p.MainModule.FileVersionInfo.FileDescription == "IntelliJ IDEA")
                {
                    Debug.WriteLine(p.MainModule.FileName);
                    intelliJExe = p.MainModule.FileName;
                    isRunning = true;
                    break;
                }
            }

            //获取不到,缺省路径启动一个进程
            if (string.IsNullOrEmpty(intelliJExe))
            {
                string intelliJPath = System.Environment.GetFolderPath(Environment.SpecialFolder.ProgramFiles) + @"\JetBrains";
                List<string> searchNames = new List<string> { "idea64.exe", "idea.bat", "idea.exe" };

                foreach (string fileName in searchNames)
                {
                    string[] fileEntries = Directory.GetFiles(intelliJPath, fileName, SearchOption.AllDirectories);
                    if (fileEntries.Any())
                    {
                        intelliJExe = fileEntries.FirstOrDefault();
                        break;
                    }
                }
            }

            return intelliJExe;
        }

        private void HandleIpr(string fileName)
        {
            XElement root = XElement.Load(fileName);
            XElement xElementProjectModuleManager = root.Elements("component")
                .FirstOrDefault(p => (string)p.Attribute("name") == "ProjectModuleManager");
            if (xElementProjectModuleManager != null)
            {
                var modules = xElementProjectModuleManager.Elements("modules");
                var fileurl =modules.FirstOrDefault().Elements("module").FirstOrDefault().Attribute("fileurl").Value;
                _moduleFileName = fileurl.Split("/".ToCharArray(), StringSplitOptions.RemoveEmptyEntries).LastOrDefault();
                ModuleName = _moduleFileName.Split(".".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)
                    .FirstOrDefault();
            }
        }

        private void HandleModuleFile(string fileName,string newSrcPath)
        {
            XElement root = XElement.Load(fileName);
            XElement xElementContent = root.Elements("component").FirstOrDefault().Elements("content").FirstOrDefault();

            var moduleDir = new FileInfo(fileName).DirectoryName;
            var urlDir = newSrcPath.Replace(moduleDir, "file://$MODULE_DIR$");
            urlDir = urlDir.Replace("\\", "/");

            if (xElementContent != null)
            {
                var configurations = xElementContent.Elements("sourceFolder").ToList();
                foreach (var config in configurations)
                {
                    Debug.WriteLine(config.Attribute("url").Value);
                    if (config.Attribute("url").Value == urlDir)
                        return;
                }

                var newPath = new XElement("sourceFolder",
                    new XAttribute("url", $"{urlDir}"),
                    new XAttribute("isTestSource", $"false")
                    );
                xElementContent.Add(newPath);
            }
            using (System.IO.StreamWriter sw = new  System.IO.StreamWriter(fileName,false, Encoding.ASCII))
            {
                root.Save(sw, SaveOptions.None);
            }
            //root.Save(fileName,SaveOptions.None);
        }

        private void HandleIws(string iwsFileName,string newSrcPath, string newJavaClassName)
        {
            XElement root = XElement.Load(iwsFileName);
            XElement xElementRunManager = root.Elements("component")
                .FirstOrDefault(p => (string)p.Attribute("name") == "RunManager");

            var iwsDir = new FileInfo(iwsFileName).DirectoryName;
            var workingDir = newSrcPath.Replace(iwsDir, "$PROJECT_DIR$");
            workingDir = workingDir.Replace("\\", "/");

            if (xElementRunManager == null)
            {
                xElementRunManager = new XElement("component", new XAttribute("name", "RunManager"));
                root.Add(xElementRunManager);
            }

            if (xElementRunManager != null)
            {
                var configurations = xElementRunManager.Elements("configuration").ToList();
                foreach (var config in configurations)
                {
                    Debug.WriteLine(config.Attribute("name").Value);
                    if (config.Attribute("name").Value == newJavaClassName)
                        return;
                }

                var newConfig = new XElement("configuration",
                    new XAttribute("name",$"{newJavaClassName}"),
                    new XAttribute("type", "Application"),
                    new XAttribute("factoryName", "Application"),
                    new XAttribute("temporary", "true"),
                    new XAttribute("nameIsGenerated", "true"),
                        new XElement("option", 
                            new XAttribute("name", "MAIN_CLASS_NAME"),
                            new XAttribute("value", $"{newJavaClassName}")
                            ),
                        new XElement("module",
                            new XAttribute("name", "solution")
                        ),
                        new XElement("option",
                            new XAttribute("name", "WORKING_DIRECTORY"),
                            new XAttribute("value", workingDir)                     //"$PROJECT_DIR$/solution/CF_CONTESTS/Round_634Div3/A"
                        ),
                        new XElement("method",
                            new XAttribute("v", "2"),
                            new XElement("option",
                                new XAttribute("name", "Make"),
                                new XAttribute("enabled", "true")
                            )
                        )
                    );
                xElementRunManager.Add(newConfig);
            }

            using (System.IO.StreamWriter sw = new System.IO.StreamWriter(iwsFileName, false, Encoding.ASCII))
            {
                root.Save(sw, SaveOptions.None);
            }
            //root.Save(iwsFileName, SaveOptions.None);
        }

        private string FindFileInDirectory(string targetDirectory,string searchPattern)
        {
            string[] fileEntries = Directory.GetFiles(targetDirectory, searchPattern, SearchOption.AllDirectories);

            if (fileEntries.Any())
                return fileEntries.FirstOrDefault();

            return string.Empty;
        }

        public void ProcessFile(string pathName,string fileName)
        {
            //创建源码目录
            if (!string.IsNullOrEmpty(_fullModuleFileName))
                HandleModuleFile(_fullModuleFileName, pathName);

            //创建编译选项
            string iwsFileName = FindFileInDirectory(_initDirName, "*.iws");
            if (!string.IsNullOrEmpty(iwsFileName))
            {
                HandleIws(iwsFileName, pathName,fileName);
            }
        }
    }
}
