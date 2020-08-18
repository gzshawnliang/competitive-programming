# ===========================================================
#  * @Name:         run and test OJ 2 cpp out file
#  * @Author:       Thomas 
#  * @Create Time:  2020-07-03 15:35:58 
#  * @Description:  运行命令行 
#                   PS > & "C:\competitive-programming\.vscode\runTest.ps1" -firstDirectory "c:\competitive-programming\other2\thomas\1374E1"
#                   第二个目录自动是第一个目录名+AC
#                   或 
#                   PS > & "C:\competitive-programming\.vscode\runTest.ps1" -firstDirectory "c:\competitive-programming\other2\thomas\1374E1" -secondDirectory "c:\competitive-programming\other2\thomas\1374E1AC"
# ===========================================================

param(
    [string]$firstDirectory,
    [string]$secondDirectory
)

Write-Host $PSScriptRoot
Write-Host $PSScriptRoot\..\include

if(-not (Test-Path $firstDirectory))
{
    Write-Host "Cannot find path $firstDirectory , because it does not exist." -ForegroundColor Red
    return
}

if([string]::IsNullOrEmpty($secondDirectory))
{
    $secondDirectory = $firstDirectory + "AC";

    if(-not (Test-Path $secondDirectory))
    {
        Write-Host "Cannot find path $secondDirectory , because it does not exist." -ForegroundColor Red
        return
    }
}
Write-Host $secondDirectory

Remove-Item "$firstDirectory\*.in" -ErrorAction SilentlyContinue
Remove-Item "$firstDirectory\*.out" -ErrorAction SilentlyContinue
Remove-Item "$firstDirectory\*.exe" -ErrorAction SilentlyContinue

Remove-Item "$secondDirectory\*.in" -ErrorAction SilentlyContinue
Remove-Item "$secondDirectory\*.out" -ErrorAction SilentlyContinue
Remove-Item "$secondDirectory\*.exe" -ErrorAction SilentlyContinue


$files = Get-ChildItem "$firstDirectory"
foreach ($file in $files)
{
    if($file.Extension  -eq ".cpp" -and $file.Name  -ne "data.cpp")
    {
        $firstCpp = $file.Name
    }
    elseif($file.Name  -eq "data.cpp")
    {
        $dataCpp = $file.Name
    }
}

Write-Host "generating test data via $dataCpp" -ForegroundColor Green
& "$PSScriptRoot\BuildAndTest.ps1" -SourceFileName "$firstDirectory\$dataCpp" -CompilerArgs "-DLOCAL_DEBUG -Wl,--stack=268435456 -std=gnu++11 -O2 -lm -lstdc++fs -I $PSScriptRoot\..\include"
Copy-Item "$firstDirectory\*.in" -Destination "$secondDirectory" -Force

Write-Host
Write-Host "***********************************************************************************" -ForegroundColor Green
Write-Host "runing first cpp file $firstCpp" -ForegroundColor Green
& "$PSScriptRoot\BuildAndTest.ps1" -SourceFileName "$firstDirectory\$firstCpp" -DoTest -CompilerArgs "-DLOCAL_DEBUG -Wl,--stack=268435456 -std=gnu++11 -O2 -lm -lstdc++fs -I $PSScriptRoot\..\include"


$files = Get-Childitem $secondDirectory 
foreach ($file in $files)
{
    if($file.Extension  -eq ".cpp" -and $file.Name  -ne "data.cpp")
    {
        $secondCpp = $file.Name
        break
    }
}
Write-Host
Write-Host "***********************************************************************************" -ForegroundColor Green
Write-Host "runing second cpp file $secondCpp" -ForegroundColor Green

& "$PSScriptRoot\BuildAndTest.ps1" -SourceFileName "$secondDirectory\$secondCpp" -DoTest -CompilerArgs "-DLOCAL_DEBUG -Wl,--stack=268435456 -std=gnu++11 -O2 -lm -lstdc++fs -I C:\code\competitive-programming\include"

Write-Host
Write-Host "***********************************************************************************" -ForegroundColor Green
Write-Host "comparing out file" -ForegroundColor Green

& "$PSScriptRoot\CompareMultilFiles.ps1" -firstDirectory "$firstDirectory" -secondDirectory "$secondDirectory"

