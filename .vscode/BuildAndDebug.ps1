# /***********************************************************
#  * @名称:   编译并启用VSCode C++调试器
#  * @作者:	  梁珞圣 
#  * @创建时间: 2020-02-05 21:05:42
#  * @备注:     需要powershell 5.1运行,下载地址如下
#               (Windows Management Framework 5.1)
#               https://www.microsoft.com/en-us/download/details.aspx?id=54616
#              Win10第一次使用如遇到SecurityError: (:) [], PSSecurityException，解决办法
#               1.管理员进入powershell命令行 
#               2.执行命令：Set-ExecutionPolicy RemoteSigned
# ***********************************************************/
[CmdletBinding()]
param(
    [String] $SourceFileName = $(throw "Source File Name is required."),
    [String] $CompilerArgs,
    [String] $WorkspaceFolder 
)

# [Threading.Thread]::CurrentThread.CurrentCulture = 'en-US'
# [cultureinfo]::CurrentCulture = 'en-US'
$PSDefaultParameterValues['Out-File:Encoding'] = 'utf8'

function CheckProcessAndStop {
    param (
        $processName
    )

    if ($null -eq (Get-Process $processName  -ErrorAction SilentlyContinue)) {
        # Write-Host "`"$processName.exe`" is not running"
    } 
    else {
        Write-Host "`"$processName.exe`" is running,try to stop the process."
        # Stop-Process -Name $processName
        # $procs = Get-Process -Name $processName | Stop-Process -Force
        $procs = Get-Process -Name $processName 
        Write-Output $procs

        $procs | Stop-Process -Force
        Get-Process | Where-Object {$_.HasExited}
        $procs | Wait-Process
        Get-Process | Where-Object {$_.HasExited}
        Start-Sleep -s 1
        
        Write-Host "`"$processName.exe`" is stoped."
    }

}


#主程序，编译C++并且启动调试
if (Test-Path $SourceFileName) {
    
    $SrcFile = Get-Item -Path $SourceFileName
    if ($SrcFile.Extension.ToLower() -eq ".cpp") 
    {
        $cppCompilerCmd=""
        $gdbCompilerCmd=""
        if ([String]::IsNullOrEmpty($env:CppCompiler)) {
            $cppCompilerCmd = "g++.exe"
            $gdbCompilerCmd = "gdb.exe"
        }
        else {
            $cppCompilerCmd = $env:CppCompiler + "\g++.exe"
            $gdbCompilerCmd = $env:CppCompiler + "\gdb.exe"
        }
        $argument = "--version"
        #如果调试进程gdb.exe在运行则先停止，如果目标文件exe正在运行则停止
        CheckProcessAndStop("gdb")
        CheckProcessAndStop($SrcFile.BaseName)

        Write-Host ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        & $gdbCompilerCmd $argument
        Write-Host ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        $pinfo = New-Object System.Diagnostics.ProcessStartInfo
        $pinfo.FileName = $cppCompilerCmd
        $pinfo.RedirectStandardError = $true
        $pinfo.RedirectStandardOutput = $true
        $pinfo.UseShellExecute = $false
        $pinfo.Arguments = "--version"
        $p = New-Object System.Diagnostics.Process
        $p.StartInfo = $pinfo
        $p.Start() | Out-Null
        $p.WaitForExit()
        $stdout = $p.StandardOutput.ReadToEnd()
        
        if($p.ExitCode -eq 0)
        {
            # 取出版本9.2.0
            $cppVersion2 = $stdout.Split("`n`r")[0].Split(' ')[-1];
            # Write-Host $cppVersion2
            
            # 取出版本9
            $cppVersion2 = $cppVersion2.Split('.')[0]

            Write-Host $stdout
            $exeFileName = $SrcFile.DirectoryName + "\" + $SrcFile.BaseName + ".exe"

            $argument = "-g " + "`"$SourceFileName`" -o `"$exeFileName`""
            if (-not [string]::IsNullOrEmpty($CompilerArgs)) 
            {
                if([int]$cppVersion2 -lt 8)
                {
                    # GCC版本小于8不使用-lstdc++fs,-O2编译参数
                    $CompilerArgs = $CompilerArgs.Replace("-lstdc++fs","")
                    $CompilerArgs = $CompilerArgs.Replace("-O2","")
                }
                $argument += " " + $CompilerArgs
            }
            #开始编译
            Write-Host "`"$cppCompilerCmd`"" $argument 
            $x = start-process $cppCompilerCmd $argument -wait -NoNewWindow -PassThru 
            if([int]$x.ExitCode -eq 0)
            {
                Write-Host "g++ compile successfully and launching debuger..."
            }
            Write-Host
            exit $x.ExitCode
        }
    }
}
else {
    Write-Host  "source file $SourceFileName does not exist" -ForegroundColor Red
    exit 1
}