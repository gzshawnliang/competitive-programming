$cppCompilerCmd=""
if ([String]::IsNullOrEmpty($env:CppCompiler)) {
    $cppCompilerCmd = "g++.exe"
}
else {
    $cppCompilerCmd = $env:CppCompiler + "\g++.exe"
}

# $cppCompilerCmd = "g++.exe"

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
    Write-Host $cppVersion2

    # 取出版本9
    $cppVersion2 = $cppVersion2.Split('.')[0]
    Write-Host $cppVersion2

    if([int]$cppVersion2 -ge 8)
    {
        Write-Host "Large"
    }
    else {
        Write-Host "smart"
    }
}
