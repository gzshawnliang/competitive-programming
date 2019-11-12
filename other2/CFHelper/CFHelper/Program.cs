using System;
using System.Collections.Generic;
using System.IO;
using System.Net.Http;
using System.Runtime.Serialization.Json;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using Newtonsoft.Json.Linq;

namespace CFHelper
{
    class Program
    {
        static void Main(string[] args)
        {

            string currDir = GetApplicationRoot();
            if (args.Length > 0)
            {
                currDir = args[0];
            }
            Console.WriteLine($"当前目录：{currDir}");

            Console.Write("请输入 codeforces 的 problemId：");
            string input= Console.ReadLine();
            if (int.TryParse(Regex.Replace(input, @"[^0-9]+", ""), out int contestId) == false)
            {
                Console.Write("输入 problemId 无效.");
                Environment.Exit(0);
            }
            string problemId = string.Empty;

            //HttpClient client = new HttpClient();
            string url =
                $"https://codeforces.com/api/contest.standings?contestId={contestId}&from=1&count=1&showUnofficial=true";

            if (Regex.Matches(input, "[a-zA-Z]").Count > 0)
            {
                problemId= Regex.Replace(input, "[0-9]", "", RegexOptions.IgnoreCase);
            }

            Task<string> problems = GetProblemInfo(url);
            Console.WriteLine("----------------------------------");

            dynamic o = JObject.Parse(problems.Result);
            string ids = string.Empty;
            Dictionary<string, string> problemDict=new Dictionary<string, string>();
            if (o.status == "OK")
            {
                dynamic problemsList = o.result.problems;
                foreach (dynamic problem in problemsList)
                {
                    string problemindex = problem.index.ToString();

                    if (!string.IsNullOrEmpty(problemId))
                        if(problemId.ToUpper()!= problemindex.ToUpper())
                            continue;

                    problemDict.Add(problemindex.ToUpper(), problem.name.ToString());
                    string s = $"({problemindex.ToUpper()}){problem.name}";
                    ids += $"{problem.index} ";
                    Console.WriteLine(s);
                }

                Console.WriteLine("----------------------------------");

                string pathName = string.Empty;
                while (true)
                {
                    if (string.IsNullOrEmpty(problemId))
                    {
                        Console.Write($"请输入字母({ids.Trim()})选择problem：");
                        problemId = Console.ReadLine();
                        if (!problemDict.ContainsKey(problemId.ToUpper()))
                        {
                            problemId = string.Empty;
                            continue;
                        }
                            
                    }
                    string choose = "N";

                    Console.WriteLine(
                        $"您已经选择：({problemId.ToUpper()}){problemDict[problemId.ToUpper()]}，是否继续？");
                    Console.Write(
                        $"输入 N 重新选择，输入任何键继续：");

                    choose = Console.ReadLine().ToUpper();
                    if (choose == "N")
                    {
                        problemId = string.Empty;
                        continue;
                    }
                        

                    pathName = FormatPathName($"CF_{contestId}{problemId.ToUpper()}_{problemDict[problemId.ToUpper()]}");
                    Console.Write($"即将创建C++文件夹：{pathName}，是否继续？输入N重新选择，输入任何键继续：");
                    choose = Console.ReadLine().ToUpper();
                    if (choose == "N")
                    {
                        problemId = string.Empty;
                        continue;
                    }
                    break;
                }

                string cppCode = "";
                cppCode += $"/*\n";
                cppCode += $"===========================================================\n";
                cppCode += $"* @Name:           {contestId}{problemId.ToUpper()}_{problemDict[problemId.ToUpper()]}\n";
                cppCode += $"* @Author:         \n";
                cppCode += $"* @create Time:    {DateTime.Now.ToString("G")}\n";
                cppCode += $"* @url:            https://codeforces.com/contest/{contestId}/problem/{problemId}\n";
                cppCode += $"* @Description:    \n";
                cppCode += $"===========================================================\n";
                cppCode += $"*/";
                CreateDirAndCppFile($"{currDir}\\{pathName}", $"{pathName}", cppCode);
                Console.WriteLine($"创建C++文件夹：\n{currDir}\\{pathName}\n完毕!输入任何键退出。");
            }
            else
            {
                Console.WriteLine(o);
            }
            
            Console.ReadLine();

        }
        static string GetApplicationRoot()
        {
            var exePath = Path.GetDirectoryName(System.Reflection
                .Assembly.GetExecutingAssembly().CodeBase);
            Regex appPathMatcher = new Regex(@"(?<!fil)[A-Za-z]:\\+[\S\s]*?(?=\\+bin)");
            var appRoot = appPathMatcher.Match(exePath).Value;
            return appRoot;
        }

        static bool CreateDirAndCppFile(string path,string fileName,string cppCode)
        {
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

            string infileName = $"{path}\\{fileName}.in";
            if (!File.Exists(infileName))
            {
                using (StreamWriter sw = File.CreateText(infileName))
                {
                    
                }
            }
            return true;
        }

        static string FormatPathName(string name)
        {
            string invalid = new string(Path.GetInvalidFileNameChars()) + new string(Path.GetInvalidPathChars());

            string pathName = name;
            foreach (char c in invalid)
            {
                pathName = pathName.Replace(c.ToString(), "");
            }
            pathName = pathName.Replace("-", "_");
            pathName = pathName.Replace(" ", "");
            return pathName;
        }

        static async Task<string> GetProblemInfo(string url)
        {
            using (HttpClient client = new HttpClient())
            {
                //client.BaseAddress = new Uri(url);
                client.DefaultRequestHeaders.Accept.Clear();
                client.DefaultRequestHeaders.Accept.Add(new System.Net.Http.Headers.MediaTypeWithQualityHeaderValue("application/json"));

                HttpResponseMessage response = await client.GetAsync(url);
                //response.EnsureSuccessStatusCode();
                //if (response.IsSuccessStatusCode)
                //{
                //    using (HttpContent content = response.Content)
                //    {
                //        string s = await content.ReadAsStringAsync();
                //        return s;
                //    }
                //}


                using (HttpContent content = response.Content)
                {
                    string s = await content.ReadAsStringAsync();
                    return s;
                }
            }
        }
    }
}
