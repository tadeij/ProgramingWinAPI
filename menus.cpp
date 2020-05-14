#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CreateMenu(HWND);

#define MENU_FILE_NEW 1
#define MENU_FILE_OPEN 2
#define MENU_FILE_EXIT 3

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmsShow) 
{                   
    MSG  msg;    
    WNDCLASSEX wc_myex;
    const char classname = "the menu example classname by ©tadeij";

    wc_myex.lpszClassName = classname;
    wc_myex.hInstance     = hInst;
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(nullptr, IDC_ARROW);
    wc_myex.lpIconName = LoadIcon(nullptr, IDI_INFORMATION);
    
    RegisterClassEx(&wc_myex);

    CreateWindowEx(wc_myex.lpszClassName, L"Simple menu",
                  WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  100, 100, 350, 250, 0, 0, hInstance, 0);

    while (GetMessage(&msg, NULL, 0, 0)) {
    
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, 
    WPARAM wParam, LPARAM lParam) {
    
  switch(msg) {
  
      case WM_CREATE:
      
          AddMenus(hwnd);
          break;

      case WM_COMMAND:
      
          switch(LOWORD(wParam)) {
          
              case IDM_FILE_NEW:
              case IDM_FILE_OPEN:
              
                  MessageBeep(MB_ICONINFORMATION);
                  break;
                  
              case IDM_FILE_QUIT:
              
                  SendMessage(hwnd, WM_CLOSE, 0, 0);
                  break;
           }
           
           break;

      case WM_DESTROY:
      
          PostQuitMessage(0);
          break;
  }

  return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void AddMenus(HWND hwnd) 
{
    HMENU menubar = CreateMenu();
    HMENU menu_file = CreateMenu();

    hMenubar = CreateMenu();
    hMenu = CreateMenu();

    AppendMenuA(menu_file, MF_STRING, IDM_FILE_NEW, "New");
    AppendMenuA(menu_file, MF_STRING, IDM_FILE_OPEN, "Open");
    AppendMenuA(menu_file, MF_SEPARATOR, 0, NULL);
    AppendMenuA(menu_file, MF_STRING, IDM_FILE_QUIT, "Quit \t Ctrl-E");

    AppendMenuA(menuabar, MF_POPUP, (UINT_PTR)menu_file, "F&ile");
    SetMenu(hwnd, hMenubar);
}
