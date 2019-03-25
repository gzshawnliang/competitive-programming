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
#  * @更新:     2019-03-15 20:17:00,stdin/stdout重新定向到.in/.out文件，指定参数RedirectStdInOut即可。
#              vscode绑定的快捷键是ctl+f11
#  * @更新:     2019-03-17 13:28 解决java代码中有中文注释，会编译出现error: unmappable character for encoding GBK
#  * @更新:     2019-03-23 08:10 编译运行C++/Java文件之后，检测如存在out、ok文件就比较结果
# ***********************************************************/
[CmdletBinding()]
param(
    [String] $SourceFileName = $(throw "Source File Name is required."),
    [switch] $ShowShellConsole,
    [switch] $DoTest,
    [switch] $RedirectStdInOut,
    [String] $CompilerArgs,
    [String] $WorkspaceFolder 
)

Set-Variable TLEWarningMsec -option Constant -value 1600        #Time Limit Exceeded 超时警告（毫秒）
Set-Variable TLEErrorMsec -option Constant -value 2000          #Time Limit Exceeded 超时错误（毫秒）
Set-Variable TLETerminateMsec -option Constant -value 60000      #Time Limit Exceeded 超时终止（毫秒）
$JavaMainClassName = "Main" #Java Main Class Name

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

        if (Test-Path $currOutFile) {
            # 运行之前先移除上次的out文件
            Remove-Item $currOutFile -Force
        }

        StartProcessWithNewInputFile $exeFileName $currInFile
        
        Rename-Item $currInFileWithPath $currInTmpFile

        if (Test-Path $currOutFile) {
            #
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

        if (Test-Path $currOutFile) {
            # 运行之前先移除上次的out文件
            Remove-Item $currOutFile -Force
        }

        StartProcessWithNewInputFile $exeFileName $($inputFile.Name)

        if (Test-Path $currOutFile) {
            # 成功运行
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

    if (Test-Path $currOutTmpFile) {
        #
        Rename-Item $currOutTmpFile $currOutFile 
    }
}

# 编译C++并且执行
function BuildCppAndRun($SourceFileName) {
    $SourFile = Get-Item -Path $SourceFileName

    #编译器命令行
    if ([String]::IsNullOrEmpty($env:CppCompiler)) {
        $cppCompilerCmd = "g++.exe"
    }
    else {
        $cppCompilerCmd = $env:CppCompiler + "\g++.exe"
    }

    #显示编译器信息
    Write-Host
    start-process $cppCompilerCmd "--version" -wait -NoNewWindow

    $exeFileName = $SourFile.DirectoryName + "\" + $SourFile.BaseName + ".exe" 

    #如果有exe文件则删除
    if (Test-Path $exeFileName) {

        # 如果进程在运行则先停止
        $processName = $SourFile.BaseName
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
    Write-Host
    Write-Host $cppCompilerCmd $arguments 
    start-process $cppCompilerCmd $arguments -wait -NoNewWindow

    #是否成功生成exe文件
    if (Test-Path $exeFileName) {

        #获取当前exe文件信息
        $ExeFile = Get-Item -Path $exeFileName
        Write-Host
        Write-Host "g++ compile successfully."
        Write-Host

        # 设置当前目录为源码目录
        Set-Location -Path $ExeFile.DirectoryName 

        if ($DoTest.IsPresent) {
            Write-Host "now run $($ExeFile.BaseName + $ExeFile.Extension)"
            RunTest($exeFileName)
        }
        else {
            $currInFile = $ExeFile.DirectoryName + "\" + $ExeFile.BaseName + ".in" 
            $isRedirectStdInOut = $false
            #检测in文件，规则：
            #1）c++文件移除拓展名cpp.in
            #2）c++文件移除拓展名移除OJ后缀.in
            #3）Input.in
            #4）Input.txt
            #5）input.in
            #6）input.txt
            #out文件=in文件名移除拓展名.out
            $inputFileArray = @(($ExeFile.BaseName + ".in").ToString(), ($ExeFile.BaseName.Trim("OJ") + ".in").ToString() , "Input.in", "Input.txt", "input.in", "input.txt");

            foreach ($n in $inputFileArray) {
                if (Test-Path ($ExeFile.DirectoryName + "\" + $n)) {
                    # Write-Host($n + ":OK")
                    $currInFile = $ExeFile.DirectoryName + "\" + $n
                    # Write-Host($currInFile)
                    break
                }
                else {
                    # Write-Host($n + ":Not OK")
                } 
            }
            $currOutFile = ""
            if ($RedirectStdInOut.IsPresent -and (Test-Path $currInFile)) {
                $isRedirectStdInOut = $true
                $inFileObj = Get-Item -Path $currInFile
                $currOutFile = $inFileObj.DirectoryName + "\" + $inFileObj.BaseName + ".out"
                Write-Host "now run $($ExeFile.BaseName + $ExeFile.Extension) redirecting $($inFileObj.BaseName).in and $($inFileObj.BaseName).out into Stdin and Stdout"
            }
            else {
                Write-Host "now run $($ExeFile.BaseName + $ExeFile.Extension)"
            }
            
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
            $msg = "$($ExeFile.BaseName + $ExeFile.Extension) program exited after $($sw.Elapsed) with return value $($LASTEXITCODE)."

            Write-Host
            if ($LASTEXITCODE -eq 0 ) {
                if (Test-Path $currInFile) {
                    $inFileObj = Get-Item -Path $currInFile
                    $leftFile = $inFileObj.BaseName + ".ok"
                    $rightFile = $inFileObj.BaseName + ".out"
                    if ((Test-Path $leftFile) -and (Test-Path $rightFile)) {
                        if (-Not([String]::IsNullOrEmpty($WorkspaceFolder))) {
                            Write-Host "Compare $leftFile -> $rightFile : " -NoNewline
                            & "$WorkspaceFolder\compareTextFiles.ps1" $leftFile $rightFile
                        }
                    }
                }
            }
            Write-Host
            Write-Host $msg -ForegroundColor Green -NoNewline
            showExitCodeInfo $LASTEXITCODE
            Write-Host
        }
    }
}

# 编译Java并且执行
function BuildJavaAndRun($SourceFileName) {
    #编译器命令行
    $javaCompilerCmd = "javac.exe"
    $javacmd = 'java'

    #显示编译器信息
    Write-Host
    start-process $javaCompilerCmd "-version" -wait -NoNewWindow
    start-process $javacmd "-version" -wait -NoNewWindow    
    
    $SourFile = Get-Item -Path $SourceFileName
    Write-Host
    Write-Host "removing $($SourFile.Directory.FullName)\*.class"
    Remove-Item -Path "$($SourFile.Directory.FullName)\*.class"

   
    #编译参数
    $arguments = "-g:none -encoding UTF8 -J-Duser.language=en $SourceFileName"

    #开始编译
    Write-Host
    Write-Host $javaCompilerCmd $arguments 
    start-process $javaCompilerCmd $arguments -wait -NoNewWindow
    
    $exeFileName = $SourFile.DirectoryName + "\*.class" 
    $exeMainFileName = $SourFile.DirectoryName + "\" + $JavaMainClassName + ".class" 

    #是否成功生成class文件
    if (Test-Path $exeFileName ) {
        Write-Host "java compile successfully."

        #获取当前class文件信息
        $FirstClassFile = (Get-Item $exeFileName)[0]

        if (-Not (Test-Path $exeMainFileName)) {
            $JavaMainClassName = $FirstClassFile.BaseName
        }

        if ($DoTest.IsPresent) {
            Write-Host "now test $($FirstClassFile.BaseName + $FirstClassFile.Extension)"
            RunTest($exeFileName)
        }
        else {
            # Write-Host "now run $($FirstClassFile.BaseName + $FirstClassFile.Extension):   " -NoNewline
            # New-Variable -Name exitCode
            # 使用System.Diagnostics.Process方式启动exe
            # 可现实显示终端，实现cin输入，计算运行时间有些误差。可有进程返回值"
            # 2019-2-14 此方法，如开三维vector可能会引发std::bad_alloc，暂时屏蔽
            # StartProcess $exeFileName
            # StartProcessWithNewInputFile $exeFileName 
            Write-Host
            Set-Location -Path $FirstClassFile.DirectoryName 
            
            Write-Host "Change to current directory:"
            Write-Host $FirstClassFile.DirectoryName

            # Write-Host $javacmd -cp $($FirstClassFile.DirectoryName) $($FirstClassFile.BaseName)
            Write-Host "run command:    " -NoNewline
            Write-Host $javacmd '-D"user.language=en"' $JavaMainClassName
            $sw = [Diagnostics.Stopwatch]::StartNew()
            # &$javacmd -cp $($FirstClassFile.DirectoryName) $($FirstClassFile.BaseName)
            # & $javacmd -cp $($FirstClassFile.DirectoryName) $JavaMainClassName
            & $javacmd '-D"user.language=en"' $JavaMainClassName
            $sw.Stop()
            $msg = "$($JavaMainClassName + $FirstClassFile.Extension) program exited after $($sw.Elapsed) with return value $($LASTEXITCODE)."
            Write-Host
            if ($LASTEXITCODE -eq 0 ) {
                $leftFile = $SourFile.BaseName + ".ok"
                $rightFile = $SourFile.BaseName + ".out"
                if ((Test-Path $leftFile) -and (Test-Path $rightFile)) {
                    if (-Not([String]::IsNullOrEmpty($WorkspaceFolder))) {
                        Write-Host "Compare $leftFile -> $rightFile"
                        & "$WorkspaceFolder\compareTextFiles.ps1" $leftFile $rightFile
                        Write-Host
                    }
                }
            }
            Write-Host $msg -ForegroundColor Green -NoNewline
            showExitCodeInfo $LASTEXITCODE
            Write-Host 
        }
    }
}


# [Threading.Thread]::CurrentThread.CurrentCulture = 'en-US'
# [cultureinfo]::CurrentCulture = 'en-US'

#主程序，编译C++/Java并且执行
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

