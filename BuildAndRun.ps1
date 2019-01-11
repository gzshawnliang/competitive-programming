# /***********************************************************
#  * @����:     ���벢����c++���룬�Զ���������ʱ��
#  * @����:	  ����ʥ 
#  * @����ʱ��: 2017-11-23 21:06:03 
#  * @�޸���:   ����ʥ 
#  * @�޸�ʱ��: 2017-12-23 21:07:12
#  * @��ע:     ��Ҫpowershell 5.1����,���ص�ַ����
#               (Windows Management Framework 5.1)
#               https://www.microsoft.com/en-us/download/details.aspx?id=54616
#  * @����:     2017-12-23 21:07:42,���ӱ�������֮ǰ�ж϶�Ӧ�Ľ����Ƿ�������,�����������������ֹͣ
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

    #������������
    $gplusplus = "g++.exe"

    #��ʾ��������Ϣ
    start-process $gplusplus "--version" -wait -NoNewWindow

    $exeFileName = $File.DirectoryName + "\" + $File.BaseName + ".exe" 

    #�����exe�ļ���ɾ��
    if (Test-Path $exeFileName) {

        # �����������������ֹͣ
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

        # ɾ��exe�ļ�
        Write-Host  "delete the old executable file $exeFileName"
        Remove-Item $exeFileName -Force
    }
    
    #�������
    $arguments = "$SourceFileName -o $exeFileName"
    if (-not [string]::IsNullOrEmpty($CompilerArgs)) {
        $arguments += " " + $CompilerArgs
    }
   
    #��ʼ����
    Write-Host $gplusplus $arguments 
    start-process $gplusplus $arguments -wait -NoNewWindow

    #�Ƿ�ɹ�����exe�ļ�
    if (Test-Path $exeFileName) {

        #��ȡ��ǰexe�ļ���Ϣ
        $File = Get-Item -Path $exeFileName

        Write-Host "g++ compile successfully."
        Write-Host "now run $($File.BaseName + $File.Extension)"

        # $sw = [Diagnostics.Stopwatch]::StartNew()
        # & $exeFileName 
        # $sw.Stop()
        # Write-Host "$($File.BaseName + $File.Extension) program exited after $($sw.Elapsed) "  
        # Write-Host "[start-process]-------------------------------���1s�������������̵�ʱ�䲻��"
        # $sw = [Diagnostics.Stopwatch]::StartNew()
        # $process = start-process -FilePath $exeFileName -WorkingDirectory $File.DirectoryName -Wait -NoNewWindow -PassThru
        # $sw.Stop()
        # Write-Host "the program exited after $($sw.Elapsed) with return value $($process.ExitCode)"  
        # Write-Host "[linux time]-------------------------------"
        # C:\cygwin64\bin\time.exe -f "Process exited after %e seconds" $exeFileName
        
        if ($ShowShellConsole.IsPresent) {
            # ʹ��System.Diagnostics.Process��ʽ����exe
            # ����ʵ��ʾ�նˣ�ʵ��cin���룬��������ʱ����Щ�����н��̷���ֵ"
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
            # ʹ�� & ���ŷ�ʽ����exe��û�п���̨�նˣ�����cin���룬��������ʱ��ȽϾ�׼���޽��̷���ֵ"
            
            # ���õ�ǰĿ¼Ϊexe�ļ�Ŀ¼
            Set-Location $File.DirectoryName            
            $sw = [Diagnostics.Stopwatch]::StartNew()
            & $exeFileName 
            $sw.Stop()
            $msg="$($File.BaseName + $File.Extension) program exited after $($sw.Elapsed)"
            Write-Host $msg  -ForegroundColor Green
        }

        # Write-Host "\n[Measure-Command]-------------------------------��׼"
        # $processRunElapsed = (Measure-Command {& $exeFileName }).ToString()
        # Write-Host "the program exited after $processRunElapsed"  -ForegroundColor Green
        
        #  Write-Host "\n[cmd /c]-------------------------------��׼"
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

