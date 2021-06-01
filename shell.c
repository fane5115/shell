#include "shell.h"

void shell()
{
    CHAR16 command[MAX_COMMAND_LEN];

    while (TRUE) {
        Input(L"shell> ", command, MAX_COMMAND_LEN);
        Print(L"\r\n");

        if (StrLen(command) == 0) {
            continue;
        }

        if (!StrCmp(L"hello", command)) {
            Print(L"Hello UEFI!\r\n");
        } else if (!StrCmp(L"rect", command)) {
            rect();
        } else if( !StrCmp(L"time", command) ) {
            time();
        } else if( !StrCmp(L"help", command) ) {
            help();
        } else {
            Print(L"Command not found.\r\n");
        }
    }
}

void rect() {
    struct Rect rect = {10, 10, 100, 200};
    draw_rect(rect, white);
}

void time() {
    EFI_TIME Time;
    uefi_call_wrapper( RT->GetTime, 2, &Time, NULL );
    Print(L"Data: %d/%d/%d\r\n", Time.Year, Time.Month, Time.Day);
    Print(L"Ora: %d:%d:%d\r\n", Time.Hour, Time.Minute, Time.Second);
}

void help() {
    Print(L"Functie help\r\n");
}