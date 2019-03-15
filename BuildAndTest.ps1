# /***********************************************************
#  * @名称:   编译并用多组数据运行c++代码，自动计算运行时间
#  * @作者:	  梁珞圣 
#  * @创建时间: 2017-11-23 21:06:03 
#  * @修改人:   梁珞圣 
#  * @修改时间: 2019-03-12 21:01:42
#  * @备注:     需要powershell 5.1运行,下载地址如下
#               (Windows Management Framework 5.1)
#               https://www.microsoft.com/en-us/download/details.aspx?id=54616
#  * @更新:     2017-12-23 21:07:42,增加编译运行之前判断对应的进程是否在运行,如果进程在运行则先停止
#  * @更新:     2018-11-13 08:07:42,增加多组数据运行测试，显示程序返回值
#              1.多组数据测试，cpp文件所在的文件夹下所有.in文件都自动用来测试。
#              2.cpp代码标准输入需要读入同名的.in文件，例如 line.cpp，就必须包含freopen("line.in", "r", stdin);或ifstream fin("line.in");
#              3.程序返回非零的值代表运行时错误。
#  * @更新:     2019-03-12 21:01:42,增加java的支持,显示错误消息改成英文
# ***********************************************************/
[CmdletBinding()]
param(
    [String] $SourceFileName = $(throw "Source File Name is required."),
    [switch] $ShowShellConsole,
    [switch] $DoTest,
    [switch] $RedirectStdInOut,
    [String] $CompilerArgs 
)

Set-Variable TLEWarningMsec -option Constant -value 1600        #Time Limit Exceeded 超时警告（毫秒）
Set-Variable TLEErrorMsec -option Constant -value 2000          #Time Limit Exceeded 超时错误（毫秒）
Set-Variable TLETerminateMsec -option Constant -value 60000      #Time Limit Exceeded 超时终止（毫秒）


#执行exe文件，返回exitCode
function StartProcess {
    param (
        $processExecFileName,
        [ref]$exitCode
    )

    # Write-Host $processExecFileName
    $currExecfileName = [System.IO.Path]::GetFileName($processExecFileName)

    $ps = new-object System.Diagnostics.Process
    $ps.StartInfo.Filename = $processExecFileName 
    if ($ShowShellConsole.IsPresent) {
        $ps.StartInfo.UseShellExecute = $true
    }
    else {
        $ps.StartInfo.UseShellExecute = $false
    }
    $ps.StartInfo.WorkingDirectory = $File.DirectoryName
    $sw = [Diagnostics.Stopwatch]::StartNew()
    $ps.start() | Out-Null
    # $ps.WaitForExit()
    $processTimeOut = -1
    if ($DoTest.IsPresent) {
        $processTimeOut = $TLETerminateMsec
    }

    if (!$ps.WaitForExit($processTimeOut) ) { 
        $ps.Kill()
        $ps.WaitForExit()
        
        Start-Sleep -s 1
       
        $msg = "$currExecfileName program timeout after $($processTimeOut / 1000)s,Process was terminated by the system"
        $exitCode.Value = 999
    }
    else {
        $sw.Stop()
        $exitCode.Value = $ps.ExitCode        
        $msg = "$currExecfileName program exited after $($sw.Elapsed) with return value $($exitCode.Value)"
    }
    
    If ($exitCode.Value -eq 0) {
        Write-Host $msg -ForegroundColor Green -NoNewLine
    }  
    Else {
        Write-Host $msg -ForegroundColor Red -NoNewLine
    }
    return $sw.ElapsedMilliseconds
}

function showExitCodeInfo() {
    param (
        $exitCode
    )

    if ($exitCode -ne 0 ) {
        if ($exitCode -eq 999) {
            Write-Host ",error:must be Time Limit Exceeded" -ForegroundColor Red
            return 
        }
        else {
            Write-Host ",error:Run-time error or exceeded memory limits" -ForegroundColor Red
            return 
        }
    }    
}

#执行exe文件，使用不同的.in文件，根据exitCode输出提示
function StartProcessWithNewInputFile {
    param (
        $processExecFileName,
        $inputFileName
    )
    New-Variable -Name exitCode
    # $exitCode=0
    $execTimeMilliseconds = StartProcess $processExecFileName ([ref]$exitCode)

    if ($inputFileName.Length -gt 0) {
        Write-Host ",input file: [$($inputFileName)]" -NoNewline
    }
    showExitCodeInfo $exitCode
    # if ($exitCode -ne 0 ) 
    # {
    #     if($exitCode -eq 999)
    #     {
    #         Write-Host ",error:must be Time Limit Exceeded" -ForegroundColor Red
    #         return 
    #     }
    #     else 
    #     {
    #         Write-Host ",error:Run-time error or exceeded memory limits" -ForegroundColor Red
    #         return 
    #     }
    # }

    if ($DoTest.IsPresent) {
        #检查输出文件是否空，empty or missing output file
        $currExecFileObj = Get-Item -Path $processExecFileName
        $outFileName = $currExecFileObj.DirectoryName + "\" + $currExecFileObj.BaseName + ".out" 
        if (Test-Path $outFileName) {
            $outFileContent = [IO.File]::ReadAllText($outFileName)
            if ($outFileContent.Length -eq 0) {
                Write-Host ",error,should be Wrong Answer:output file is empty" -ForegroundColor Red
                return
            }
        }
        else {
            Write-Host ",error,should be Wrong Answer:missing output file" -ForegroundColor Red
            return
        }

        #检查超时情况
        if ($execTimeMilliseconds -gt $TLEErrorMsec) {
            Write-Host ",error:must be Time Limit Exceeded" -ForegroundColor Red -NoNewline
        }
        elseif ($execTimeMilliseconds -gt $TLEWarningMsec) {
            Write-Host ",warning:possibly Time Limit Exceeded" -ForegroundColor Red -NoNewline
        }
    }

    Write-Host ""
}

#运行测试，找出exe文件所在的文件夹，文件夹下*.in文件作为输入文件,使用copy、rename办法改成exe文件名一样的.in文件，执行多次
function RunTest ($processExecFileName) {
    # $tempPath = [System.IO.Path]::GetTempPath()
    # Copy-Item $processExecFileName -destination $tempPath -force
    
    # Write-Host $currPathName
    $currFileObj = Get-Item -Path $processExecFileName
    $currPathName = $currFileObj.DirectoryName

    $currInFile = $currFileObj.BaseName + ".in" 
    $inFilePadLen = $currInFile.Length + 4
    if ($inFilePadLen -lt 12) {
        $inFilePadLen = 12
    }
    $currInFileWithPath = $currPathName + "\" + $currFileObj.BaseName + ".in" 
    $currOutFile = $currPathName + "\" + $currFileObj.BaseName + ".out" 
    $currInTmpFile = $currPathName + "\" + $currFileObj.BaseName + ".tmp" 
    $currOutTmpFile = $currPathName + "\" + [GUID]::NewGuid() + ".tmp" 

    # Write-Host $currPathName

    if (Test-Path $currInFileWithPath) {
        # Write-Host "Exists $currInFileWithPath"
        if (Test-Path $currInTmpFile) {
            # Write-Host "Remove $currInTmpFile"
            Remove-Item $currInTmpFile -Force
        }

        if (Test-Path $currOutFile) { # 运行之前先移除上次的out文件
            Remove-Item $currOutFile -Force
        }

        StartProcessWithNewInputFile $exeFileName $currInFile
        
        Rename-Item $currInFileWithPath $currInTmpFile

        if (Test-Path $currOutFile) { #
            Rename-Item $currOutFile $currOutTmpFile
        }

    }
    # Write-Host "测试"
    $allInputFiles = Get-ChildItem -Path $currPathName | Where-Object {$_.FullName -like "*.in" } 
    
    foreach ($inputFile in $allInputFiles) {
        #测试随机错误使用以下代码，因为要等C++初始化种子，正式版需要屏蔽
        # Start-Sleep -s 2

        $sourceInName = $currPathName + "\" + $inputFile.Name
        Copy-Item $sourceInName -destination $currInFileWithPath  -force

        if (Test-Path $currOutFile) { # 运行之前先移除上次的out文件
            Remove-Item $currOutFile -Force
        }

        StartProcessWithNewInputFile $exeFileName $($inputFile.Name)

        if (Test-Path $currOutFile) { # 成功运行
            $destOutName = $currPathName + "\" + $inputFile.BaseName + ".out"
            if (Test-Path $destOutName) {
                Remove-Item $destOutName -Force
            }                        
            Rename-Item $currOutFile $destOutName
            Remove-Item $currInFileWithPath -Force
        }
    }

    Write-Host "total $($allInputFiles.Count) files test done"

    if (Test-Path $currInFileWithPath) {
        Remove-Item $currInFileWithPath -Force
    }

    if (Test-Path $currInTmpFile) {
        Rename-Item $currInTmpFile $currInFileWithPath
    }

    if (Test-Path $currOutTmpFile) { #
        Rename-Item $currOutTmpFile $currOutFile 
    }
}

# 编译C++并且执行
function BuildCppAndRun($SourceFileName) {
    $File = Get-Item -Path $SourceFileName

    #编译器命令行
    if ([String]::IsNullOrEmpty($env:CppCompiler)) {
        $cppCompilerCmd = "g++.exe"
    }
    else {
        $cppCompilerCmd = $env:CppCompiler + "\g++.exe"
    }

    #显示编译器信息
    start-process $cppCompilerCmd "--version" -wait -NoNewWindow

    $exeFileName = $File.DirectoryName + "\" + $File.BaseName + ".exe" 

    #如果有exe文件则删除
    if (Test-Path $exeFileName) {

        # 如果进程在运行则先停止
        $processName = $File.BaseName
        if ($null -eq (Get-Process $processName  -ErrorAction SilentlyContinue)) {
            Write-Host "$processName.exe is not running"
        } 
        else {
            Write-Host "$processName.exe is running,try to stop the process."
            # Stop-Process -Name $processName
            # $procs = Get-Process -Name $processName | Stop-Process -Force
            $procs = Get-Process -Name $processName 
            Write-Output $procs

            $procs | Stop-Process -Force
            Get-Process | Where-Object {$_.HasExited}
            $procs | Wait-Process
            Get-Process | Where-Object {$_.HasExited}
            Start-Sleep -s 1
            
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
    Write-Host $cppCompilerCmd $arguments 
    start-process $cppCompilerCmd $arguments -wait -NoNewWindow

    #是否成功生成exe文件
    if (Test-Path $exeFileName) {

        #获取当前exe文件信息
        $File = Get-Item -Path $exeFileName

        Write-Host "g++ compile successfully."

        if ($DoTest.IsPresent) {
            Write-Host "now run $($File.BaseName + $File.Extension)"
            RunTest($exeFileName)
        }
        else {
            $currInFile = $File.DirectoryName + "\" + $File.BaseName + ".in" 
            $currOutFile = $File.DirectoryName + "\" + $File.BaseName + ".out" 
            $isRedirectStdInOut = $false
            if ($RedirectStdInOut.IsPresent -and (Test-Path $currInFile)) {
                $isRedirectStdInOut = $true
            }

            Write-Host "now run $($File.BaseName + $File.Extension)"    
            New-Variable -Name exitCode
            # 使用System.Diagnostics.Process方式启动exe
            # 可现实显示终端，实现cin输入，计算运行时间有些误差。可有进程返回值"
            # 2019-2-14 此方法，如开三维vector可能会引发std::bad_alloc，暂时屏蔽
            # StartProcess $exeFileName
            # StartProcessWithNewInputFile $exeFileName 

            # 使用powershell call operator (&)解决'std::bad_alloc'问题
            $sw = [Diagnostics.Stopwatch]::StartNew()
            if ($isRedirectStdInOut -eq $true) {
                Get-Content $currInFile | & $exeFileName > $currOutFile
            }
            else {
                & $exeFileName     
            }
            
            $sw.Stop()
            $msg = "$($File.BaseName + $File.Extension) program exited after $($sw.Elapsed) with return value $($LASTEXITCODE)."
            Write-Host $msg -ForegroundColor Green -NoNewline
            showExitCodeInfo $LASTEXITCODE
            Write-Host ""
        }
    }
}

# 编译Java并且执行
function BuildJavaAndRun($SourceFileName) {
    $File = Get-Item -Path $SourceFileName

    #编译器命令行
    $javaCompilerCmd = "javac.exe"
    # if([String]::IsNullOrEmpty($env:CppCompiler))
    # {
        
    # }
    # else
    # {
    #     $javaCompilerCmd = $env:CppCompiler+ "\g++.exe"
    # }

    #显示编译器信息
    start-process $javaCompilerCmd "-version" -wait -NoNewWindow

    $exeFileName = $File.DirectoryName + "\" + $File.BaseName + ".class" 

    #如果有exe文件则删除
    if (Test-Path $exeFileName) {

        # 如果进程在运行则先停止
        $processName = $File.BaseName
        if ($null -eq (Get-Process $processName  -ErrorAction SilentlyContinue)) {
            Write-Host "$processName.class is not running"
        } 
        else {
            Write-Host "$processName.class is running,try to stop the process."
            # Stop-Process -Name $processName
            # $procs = Get-Process -Name $processName | Stop-Process -Force
            $procs = Get-Process -Name $processName 
            Write-Output $procs

            $procs | Stop-Process -Force
            Get-Process | Where-Object {$_.HasExited}
            $procs | Wait-Process
            Get-Process | Where-Object {$_.HasExited}
            Start-Sleep -s 1
            
            Write-Host "$processName.class is stoped."
        }

        # 删除exe文件
        Write-Host  "delete the old executable file $exeFileName"
        Remove-Item $exeFileName -Force
    }
    
    #编译参数
    $arguments = "-g:none -J-Duser.language=en $SourceFileName"
    # if (-not [string]::IsNullOrEmpty($CompilerArgs)) {
    #     $arguments += " " + $CompilerArgs
    # }
    # $arguments += " " + $SourceFileName

    #开始编译
    Write-Host $javaCompilerCmd $arguments 
    start-process $javaCompilerCmd $arguments -wait -NoNewWindow

    #是否成功生成class文件
    if (Test-Path $exeFileName) {

        #获取当前class文件信息
        $File = Get-Item -Path $exeFileName

        Write-Host "java compile successfully."

        if ($DoTest.IsPresent) {
            Write-Host "now test $($File.BaseName + $File.Extension)"
            RunTest($exeFileName)
        }
        else {
            Write-Host "now run $($File.BaseName + $File.Extension)"    
            New-Variable -Name exitCode
            # 使用System.Diagnostics.Process方式启动exe
            # 可现实显示终端，实现cin输入，计算运行时间有些误差。可有进程返回值"
            # 2019-2-14 此方法，如开三维vector可能会引发std::bad_alloc，暂时屏蔽
            # StartProcess $exeFileName
            # StartProcessWithNewInputFile $exeFileName 

            # 此方法解决'std::bad_alloc'问题
            Set-Location -Path $File.DirectoryName 
            $sw = [Diagnostics.Stopwatch]::StartNew()
            $javacmd = "java"
            &$javacmd -cp $($File.DirectoryName) $($File.BaseName)
            $sw.Stop()
            $msg = "$($File.BaseName + $File.Extension) program exited after $($sw.Elapsed) with return value $($LASTEXITCODE)."
            Write-Host $msg -ForegroundColor Green -NoNewline
            showExitCodeInfo $LASTEXITCODE
            Write-Host ""
        }
    }
}

[Threading.Thread]::CurrentThread.CurrentUICulture = 'en-US'

#主程序，编译C++并且执行
if (Test-Path $SourceFileName) {
    
    $SrcFile = Get-Item -Path $SourceFileName
    if ($SrcFile.Extension.ToLower() -eq ".cpp") {
        BuildCppAndRun($SourceFileName)
    }
    elseif ($SrcFile.Extension.ToLower() -eq ".java") {
        BuildJavaAndRun($SourceFileName)
    }
}
else {
    Write-Host  "file $SourceFileName does not exist" -ForegroundColor Red
}

