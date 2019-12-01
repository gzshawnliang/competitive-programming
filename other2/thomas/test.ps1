Try {
    $resp =  Invoke-RestMethod -Uri "https://localhost:44318/api/OAuth/token?appid=user1&secret=1234561" -ContentType 'application/json' | ConvertTo-Json
    Write-Host  $resp
}
Catch {
    # Obtain some information
    $expMessage = $_.Exception.Message
    $failedItem = $_.Exception.Source
    $line = $_.InvocationInfo.ScriptLineNumber

    # Check if there is a response.
    if ($_.Exception.Response -eq $null) {
        Write-Host "At $($line):`r`n$expMessage" -ForeGroundColor Red
    }
    else {
        # Get the response body with more error detail.
        $respStream = $_.Exception.Response.GetResponseStream()
        $reader = New-Object System.IO.StreamReader($respStream)
        $respBody = $reader.ReadToEnd() | ConvertFrom-Json
        $errorCode = $respBody.code
        $errorMessage = $respBody.message
        $causeDetails = $respBody.causeDetails
       # Write-Host "At line $($line):`r`n$expMessage`r`n$($errorCode): $errorMessage`n`r $causeDetails" -ForegroundColor Red
       Write-Host "$($errorCode): $errorMessage`n`r $causeDetails" -ForegroundColor Red
    } 
}