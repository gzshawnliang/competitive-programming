<#
.Synopsis
   Compares two text/code files and comes up with not-matching lines, excluding lines with whitespace, tab, line break.

.DESCRIPTION
   Many of the times, we want to compare 2 sets of code files line by line to take a quick look for differences. 
   This script is for quick use/check to look at 2 files side by side with line numbers. 

.EXAMPLE
   .\compareTextFiles.ps1 -leftFile $leftFile -rightFile $rightFile

.INPUTS
   inputFilePath: The file for which we want to compare with original file.
   compareFilePath: the file for which we want comparison. the original file.

.OUTPUTS
   1. line number
   2. line from the left file
   3. line from the right file.

.FUNCTIONALITY
   file compare for compare for mismatches. 
   
    Script by         : Ketan Thakkar (KetanBhut@live.com)
    Script version    : v0.2
    Release date      : 29-Mar-2018
#>
param(
    [Parameter(Mandatory=$true)]
    [System.IO.FileInfo]
    $leftFile,
    [Parameter(Mandatory=$true)]
    [System.IO.FileInfo]
    $rightFile

)

$leftLines = Get-Content -Path $leftFile
$rightLines = Get-Content -Path $rightFile

if($leftLines -eq $Null)
{
    Write-Host " [error]left File is empty" -ForegroundColor Red
    return
}

if($rightLines -eq $Null)
{
    Write-Host " [error]right File is empty" -ForegroundColor Red
    return
}

function OutputLineText{
    param (
        $i
    )

    Write-Host "        [$($i+1)]: " -NoNewline
    Write-Host $leftLines[$i] -NoNewline
    Write-Host " -> " -NoNewline
    Write-Host $rightLines[$i] 
}

$isEq = $true

$linesCount =($leftLines.count,$rightLines.count | Measure -Max).Maximum

if($linesCount -eq 1)
{
    if($leftLines -cne $rightLines)
    {
        Write-Host " [error]" -ForegroundColor Red
        $isEq = $false 

        Write-Host "        [1]: " -NoNewline
        Write-Host $leftLines -NoNewline
        Write-Host " -> " -NoNewline
        Write-Host $rightLines 
    }
}
else
{
    for ($i=0; $i -lt $linesCount; $i++)
    {
        #compare line against line
        if($leftLines[$i] -cne $rightLines[$i])
        {
            if($isEq -eq $true)
            {
                Write-Host " [error]" -ForegroundColor Red
                $isEq = $false    
            }
            OutputLineText($i)         
        }
    }
}

if($isEq -eq $true)
{
    Write-Host "OK" -ForegroundColor Green
}