# /***********************************************************
#  * @名称:     编译并运行c++代码，自动计算运行时间
#  * @作者:	  梁珞圣 
#  * @创建时间: 2017-11-23 21:06:03 
#  * @修改人:   梁珞圣 
#  * @修改时间: 2017-12-23 21:07:12
#  * @备注:     需要powershell 5.1运行,下载地址如下
#               (Windows Management Framework 5.1)
#               https://www.microsoft.com/en-us/download/details.aspx?id=54616
#  * @更新:     2017-12-23 21:07:42,增加编译运行之前判断对应的进程是否在运行,如果进程在运行则先停止
# ***********************************************************/
[CmdletBinding()]
param(
    [String] $SourceFileName = $(throw "Source File Name is required."),
    [switch] $ShowShellConsole,
    [String] $CompilerArgs 
)

# Write-Host $SourceFileName 

if (Test-Path $SourceFileName) {

    $File = Get-Item -Path $SourceFileName

    #编译器命令行
    $gplusplus = "g++.exe"

    #显示编译器信息
    start-process $gplusplus "--version" -wait -NoNewWindow

    $exeFileName = $File.DirectoryName + "\" + $File.BaseName + ".exe" 

    #如果有exe文件则删除
    if (Test-Path $exeFileName) {

        # 如果进程在运行则先停止
        $processName=$File.BaseName
        if((Get-Process $processName  -ErrorAction SilentlyContinue) -eq $null) 
        {
            Write-Host "$processName.exe is not running"
        } 
        else 
        {
            Write-Host "$processName.exe is running,try to stop the process."
            Stop-Process -Name $processName
            Sleep 1
            Write-Host "$processName.exe is stoped."
        }

        # 删除exe文件
        Write-Host  "delete the old executable file $exeFileName"
        Remove-Item $exeFileName -Force
    }
    
    #编译参数
    $arguments = "$SourceFileName -o $exeFileName"
    if (-not [string]::IsNullOrEmpty($CompilerArgs)) {
        $arguments += " " + $CompilerArgs
    }
   
    #开始编译
    Write-Host $gplusplus $arguments 
    start-process $gplusplus $arguments -wait -NoNewWindow

    #是否成功生成exe文件
    if (Test-Path $exeFileName) {

        #获取当前exe文件信息
        $File = Get-Item -Path $exeFileName

        Write-Host "g++ compile successfully."
        Write-Host "now run $($File.BaseName + $File.Extension)"

        # $sw = [Diagnostics.Stopwatch]::StartNew()
        # & $exeFileName 
        # $sw.Stop()
        # Write-Host "$($File.BaseName + $File.Extension) program exited after $($sw.Elapsed) "  
        # Write-Host "[start-process]-------------------------------误差1s，可能启动进程的时间不用"
        # $sw = [Diagnostics.Stopwatch]::StartNew()
        # $process = start-process -FilePath $exeFileName -WorkingDirectory $File.DirectoryName -Wait -NoNewWindow -PassThru
        # $sw.Stop()
        # Write-Host "the program exited after $($sw.Elapsed) with return value $($process.ExitCode)"  
        # Write-Host "[linux time]-------------------------------"
        # C:\cygwin64\bin\time.exe -f "Process exited after %e seconds" $exeFileName
        
        if ($ShowShellConsole.IsPresent) {
            # 使用System.Diagnostics.Process方式启动exe
            # 可现实显示终端，实现cin输入，计算运行时间有些误差。可有进程返回值"
            $ps = new-object System.Diagnostics.Process
            $ps.StartInfo.Filename = $exeFileName 
            $ps.StartInfo.UseShellExecute = $true
            $ps.StartInfo.WorkingDirectory = $File.DirectoryName
            $ps.start() | Out-Null
            $sw = [Diagnostics.Stopwatch]::StartNew()
            $ps.WaitForExit()
            $sw.Stop()
            $msg="the program exited after $($sw.Elapsed) with return value $($ps.ExitCode)"
            Write-Host $msg -ForegroundColor Green
        }
        else {
            # 使用 & 符号方式启动exe，没有控制台终端，不能cin输入，计算运行时间比较精准，无进程返回值"
            
            # 设置当前目录为exe文件目录
            Set-Location $File.DirectoryName            
            $sw = [Diagnostics.Stopwatch]::StartNew()
            & $exeFileName 
            $sw.Stop()
            $msg="$($File.BaseName + $File.Extension) program exited after $($sw.Elapsed)"
            Write-Host $msg  -ForegroundColor Green
        }

        # Write-Host "\n[Measure-Command]-------------------------------精准"
        # $processRunElapsed = (Measure-Command {& $exeFileName }).ToString()
        # Write-Host "the program exited after $processRunElapsed"  -ForegroundColor Green
        
        #  Write-Host "\n[cmd /c]-------------------------------精准"
        #  $sw = [Diagnostics.Stopwatch]::StartNew()
        #  cmd /c $exeFileName
        #  $sw.Stop()
        #  Write-Host "the program exited after $($sw.Elapsed)"  
        
        # (Measure-Command {start-process -FilePath $exeFileName -WorkingDirectory $File.DirectoryName -Wait -NoNewWindow -PassThru}).ToString()
    }
}
else {
    Write-Host  "file $SourceFileName does not exist" -ForegroundColor Red
}

