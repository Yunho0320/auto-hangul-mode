# auto-hangul-mode

## Problem statement: 
When using the Korean Microsoft IME with a UK keyboard layout on Windows, switching between input languages (via Left Alt + Shift) does not always enter Hangul input mode (가). Instead, it often defaults to A mode, requiring an additional manual toggle to reach 가. This creates unnecessary friction for users who always want to type in Hangul when switching to the Korean IME.

## Solution
This application automatically ensures that the Korean IME enters Hangul mode (가) immediately upon switching.
### How it works
1. The app continuously monitors the current input language and IME mode:
- English (UK)
- Korean IME in 가 mode
- Korean IME in A mode
2. When it detects Korean IME in A mode, it sends a simulated keypress of virtual key 0x15, which toggles to 가 mode.
(Note: On some systems, VK_RMENU (Right Alt) doesn't toggle the mode, but 0x15 does. This key was discovered via experimentation and may be tied to custom keyboard firmware or IME behavior.)

## Setup Instructions
### Build the application
1. Open Visual Studio.
2. Create a Console Application project.
3. Copy and paste the provided source code.
4. Go to: Project Properties → Linker → System → Subsystem -> Change from: Console → Windows (This hides the console window.)
5. Build the project (e.g. x64 → Debug).
6. Locate the generated .exe file (e.g. in x64\Debug\)

### Set it to run on startup
1. Press Windows + R, type: shell:startup
2. This opens your Startup folder.
3. Create a shortcut to your .exe and place it in this folder.
