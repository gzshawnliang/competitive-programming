param(
    [string]$InitialDirectory
)

#获取父目录
$parentDirectory = [System.IO.Directory]::GetParent($InitialDirectory)

function Read-FolderBrowserDialog([string]$Message, [string]$InitialDirectory)
{
    $app = New-Object -ComObject Shell.Application
    $folder = $app.BrowseForFolder(0, $Message, '&h201', $InitialDirectory)
    if ($folder) { return $folder.Self.Path } else { return '' }

    # Add-Type -AssemblyName System.Windows.Forms
    # $FolderBrowser = New-Object System.Windows.Forms.FolderBrowserDialog
    # $FolderBrowser.Description = $Message
    # $FolderBrowser.SelectedPath = $InitialDirectory
    # $FolderBrowser.ShowNewFolderButton = $false
    # $result = $FolderBrowser.ShowDialog((New-Object System.Windows.Forms.Form -Property @{TopMost = $true }))
    # if ($result -eq [Windows.Forms.DialogResult]::OK){
    #     return $FolderBrowser.SelectedPath
    # }
    # else {
    #     return ''
    # }
}

$firstDirectory = Read-FolderBrowserDialog "Please Select First Folder" $parentDirectory
if([string]::IsNullOrEmpty($firstDirectory))
{
    return
}

$secondDirectory = Read-FolderBrowserDialog "Please Select Second Folder" $parentDirectory
if([string]::IsNullOrEmpty($secondDirectory))
{
    return
}

if($firstDirectory -eq $secondDirectory)
{
    return
}
Write-Host $PSScriptRoot
Write-Host $firstDirectory -NoNewline
Write-Host " -> " -NoNewline
Write-Host $secondDirectory

$allOutputFiles1 = Get-ChildItem -Path $firstDirectory | Where-Object {$_.FullName -like "*.out" } 
$allOutputFiles2 = Get-ChildItem -Path $secondDirectory | Where-Object {$_.FullName -like "*.out" }

foreach ($file1 in $allOutputFiles1)
{
    $leftFile  = $firstDirectory + "\" + $file1.Name
    $rightFile = $secondDirectory + "\" + $file1.Name
    if (Test-Path $rightFile) 
    {
        Write-Host $file1.Name -NoNewline
        Write-Host ":" -NoNewline
        $command = "$PSScriptRoot\compareTextFiles.ps1 -leftFile $leftFile -rightFile $rightFile"
        Invoke-Expression -command $command
    }
    else 
    {
        Write-Host $file1.Name -NoNewline
        Write-Host ": [error]right file does not exist" -ForegroundColor Red
    }
}

foreach ($file2 in $allOutputFiles2)
{
    $leftFile  = $firstDirectory + "\" + $file2.Name
    $rightFile = $secondDirectory + "\" + $file2.Name
    $isFileExists = Test-Path $leftFile
    if ($isFileExists -eq $false) 
    {
        Write-Host $file2.Name -NoNewline
        Write-Host ": [error]left file does not exist" -ForegroundColor Red
    }
}