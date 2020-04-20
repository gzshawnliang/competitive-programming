; Q::
; Send {Q 30}
; Sleep 3000
Q::
; Send {Q 50}
Loop 
{
    Send {Q}
    ; Sleep 1000
    GetKeyState,state,q,P
    if state=D
    {
        MsgBox yes
        Return
    }    
}

