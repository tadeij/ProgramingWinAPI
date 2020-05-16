#include <windows.h>

DWORD dwExStyle = WS_EX_CLIENTEDGE;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void CreateMenu(HWND);

#define MENU_FILE_NEW 1
#define MENU_FILE_OPEN 2
#define MENU_FILE_EXIT 3
#definr MENU_VIEW_NORMAL 4
#define MRNU_VIEW_PALETTE 5

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmsShow) 
{                   
    MSG  msg;    
    WNDCLASSEX wc_myex;
    const char classname = "the menu example classname by ©tadeij";

    wc_myex.cbClsExtra = 0;
    wc_myex.cbWndExtra = 0;
    wc_myex.style = 0;
    wc_myex.lpszClassName = classname;
    wc_myex.lpszMenuName = nullptr;
    wc_myex.hIcon = LoadIcon(nullptr, IDI_INFORMATION);
    wc_myex.hIconSm = LoadIcon(nullptr, IDI_INFORMATION);
    wc.hCursor       = LoadCursor(nullptr, IDC_ARROW);
    wc_myex.hInstance     = hInst;
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpfnWndProc   = WndProc;
    
    RegisterClassEx(&wc_myex);

    HWND hWnd = CreateWindowEx(dwExStyle,
                               wc_myex.lpszClassName, 
                               "Simple menu",
                               WS_OVERLAPPEDWINDOW,
                               100, 100, 800, 600, 
                               nullptr, 
                               (HMENU)0,
                               wc_myex.hInstance, 0);

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWqnd);

    while (GetMessage(&msg, NULL, 0, 0)) 
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT u_Msg,  WPARAM wParam, LPARAM lParam) {
    
  switch(msg)
  {
      case WM_CREATE:
      {
          HMENU menubar = CreateMenu();
          HMENU menu_file = CreateMenu();
          HMENU menu_view = CreateMenu();

          AppendMenuA(menu_file, MF_STRING, IDM_FILE_NEW, "New");
          AppendMenuA(menu_file, MF_STRING, IDM_FILE_OPEN, "Open");
          AppendMenuA(menu_file, MF_SEPARATOR, 0, NULL);
          AppendMenuA(menu_file, MF_STRING, IDM_FILE_QUIT, "Quit \t Ctrl-E");
          AppendMenuA(menu_view, MF_STRING, MENU_VIEW_NORMAL, "Normal view");

          AppendMenuA(menubar, MF_POPUP, (UINT_PTR)menu_file, "F&ile");

          CheckMenuRadioItem(menu_view,
          MENU_VIEW_NORMAL, 
          MENU_VIEW_PALETTE, 
          nullptr,
          MF_BYCOMMAND);
   
          SetMenu(hwnd, hMenubar);
       }
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

void AddMenus(HWND hwnd){
    
}
