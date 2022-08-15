

#include <windows.h>
#include "resource.h"
#include <winuser.h>
#include <cstdlib>

int id_button = 10001;
bool imagen[16];
HWND hwndButton[16];

int x = 10;
int y = 10;

int bomba1 = 0, bomba2 = 0, bomba3 = 0;
int bbomba1 = 0, bbomba2 = 0, bbomba3 = 0;

int numbomba = 0;

const char mensaje[50]= "mamaste, better call saul";

HBITMAP bitmap_banderita = NULL;
HBITMAP bitmap_bomba = NULL;
HBITMAP bitmap_num1 = NULL;
HBITMAP bitmap_num2 = NULL;
HBITMAP bitmap_num3 = NULL;


#define id_button_01 10001      
#define id_button_02 10002
#define id_button_03 10003
#define id_button_04 10004
#define id_button_05 10005
#define id_button_06 10006
#define id_button_07 10007
#define id_button_08 10008
#define id_button_09 10009 
#define id_button_10 10010
#define id_button_11 10011
#define id_button_12 10012
#define id_button_13 10013
#define id_button_14 10014
#define id_button_15 10015
#define id_button_16 10016

#define bomba_1 bomba1
#define bomba_2 bomba2
#define bomba_3 bomba3



LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Buscaminas",                  // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,  //en donde aparece la ventana x y, y su altura y anchura

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    //if
    bomba1 = (rand() % 16 + 1); // 8       //tener tres bombas aleaterias que seran los nuevos valores de los botones
    bomba2 = (rand() % 16 + 1); //4
    bomba3 = (rand() % 16 + 1); //13

    //bombas con el valor del boton
    bbomba1 = bomba1 + 10000; // 8       //tener tres bombas aleaterias que seran los nuevos valores de los botones
    bbomba2 = bomba2 + 10000;
    bbomba3 = bomba3 + 10000;

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {

    case WM_CREATE:


        for (int i = 0; i < 16; i++)
        {
            imagen[i] = false;
        }

        for (int i = 0; i < 16; i++)
        {
            hwndButton[i] = CreateWindowA("BUTTON", "", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                x, y, 100, 100, hwnd, NULL, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
            //cambiar el CreateWindow a CreateWindowA y poner la libreria winuser.h

            id_button++;
            x = x + 100;
            if (x > 400)
            {
                x = 10;
                y = y + 100;
            }
        }



        // bitmap_o = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP1));
       // bitmap_x = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP2));

        bitmap_banderita = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP1));
        bitmap_bomba = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP2));
        bitmap_num1 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP3));
        bitmap_num2 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP4));
        bitmap_num3 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP5));

        break;



    case WM_COMMAND:
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        switch (LOWORD(wParam))
        {

        case id_button_01:      //para el primer boton
            numbomba = 0;

            DestroyWindow(hwndButton[0]); //destruye la bomba y evalua

            if (01 != bomba1 && bomba2 && bomba3) { //primero, si no le diste a una bomba

                if (02 != bomba1) { }               //si no le diste la bomba, revisa los alrededores
                else { numbomba++; }
                if (05 != bomba1) {}
                else { numbomba++; }
                if (06 != bomba1) {}
                else { numbomba++; }                //si alguno de los alrededoes tiene bomba, lo suma en la variable numbomba
                //--------------------
                if (02 != bomba2) {}
                else { numbomba++; }
                if (05 != bomba2) {}
                else { numbomba++; }
                if (06 != bomba2) {}
                else { numbomba++; }
                //----------------------
                if (02 != bomba3) { }
                else { numbomba++; }
                if (05 != bomba3) { }
                else { numbomba++; }
                if (06 != bomba3) {}
                else { numbomba++; }
                
                if (numbomba == 1) {          //imprime el numero 1
                    BITMAP bm;
                    HDC hdcMem = CreateCompatibleDC(hdc);
                    HBITMAP hbmOld;
                    hbmOld = (HBITMAP)SelectObject(hdcMem, bitmap_num1);
                    GetObject(bitmap_num1, sizeof(bm), &bm);
                }
                if (numbomba == 2) {           //imprime el numero 2
                    BITMAP bm;
                    HDC hdcMem = CreateCompatibleDC(hdc);
                    HBITMAP hbmOld;
                    hbmOld = (HBITMAP)SelectObject(hdcMem, bitmap_num2);
                    GetObject(bitmap_num2, sizeof(bm), &bm);
                }
                if (numbomba == 3) {           //imprime el numero 3
                    BITMAP bm;
                    HDC hdcMem = CreateCompatibleDC(hdc);
                    HBITMAP hbmOld;
                    hbmOld = (HBITMAP)SelectObject(hdcMem, bitmap_num3);
                    GetObject(bitmap_num3, sizeof(bm), &bm);
                }

            }
            else {
                
                BITMAP bm;
                HDC hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hbmOld;
                hbmOld = (HBITMAP)SelectObject(hdcMem, bitmap_bomba);
                GetObject(bitmap_bomba, sizeof(bm), &bm);     //imprimir la imagen de la bomba


                Sleep(500);
               //MessageBox(0, NULL, NULL, MB_OK);  //mensaje para decir que rip

            }

            break;  //break del boton 1

        case id_button_02:      //para el segundo boton
            numbomba = 0;
            DestroyWindow(hwndButton[1]);

            if (02 != bomba1 && bomba2 && bomba3) {

                if (01 != bomba1) {}
                else { numbomba++; }
                if (03 != bomba1) { }
                else { numbomba++; }
                if (05 != bomba1) { }
                else { numbomba++; }
                if (06 != bomba1) {}
                else { numbomba++; }
                if (07 != bomba1) {}
                else { numbomba++; }
                //--------------------
                if (01 != bomba2) {}
                else { numbomba++; }
                if (03 != bomba2) {}
                else { numbomba++; }
                if (05 != bomba2) {}
                else { numbomba++; }
                if (06 != bomba2) {}
                else { numbomba++; }
                if (07 != bomba2) {}
                else { numbomba++; }
                //----------------------
                if (01 != bomba3) {}
                else { numbomba++; }
                if (03 != bomba3) {}
                else { numbomba++; }
                if (05 != bomba3) {}
                else { numbomba++; }
                if (06 != bomba3) {}
                else { numbomba++; }
                if (07 != bomba3) {}
                else { numbomba++; }

                if (numbomba == 1) {          //imprime el numero 1
                    BITMAP bm;
                    HDC hdcMem = CreateCompatibleDC(hdc);
                    HBITMAP hbmOld;
                    hbmOld = (HBITMAP)SelectObject(hdcMem, bitmap_num1);
                    GetObject(bitmap_num1, sizeof(bm), &bm);
                }
                if (numbomba == 2) {           //imprime el numero 2
                    BITMAP bm;
                    HDC hdcMem = CreateCompatibleDC(hdc);
                    HBITMAP hbmOld;
                    hbmOld = (HBITMAP)SelectObject(hdcMem, bitmap_num2);
                    GetObject(bitmap_num2, sizeof(bm), &bm);
                }
                if (numbomba == 3) {           //imprime el numero 3
                    BITMAP bm;
                    HDC hdcMem = CreateCompatibleDC(hdc);
                    HBITMAP hbmOld;
                    hbmOld = (HBITMAP)SelectObject(hdcMem, bitmap_num3);
                    GetObject(bitmap_num3, sizeof(bm), &bm);
                }
               
            }
            else {

                BITMAP bm;
                HDC hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hbmOld;
                hbmOld = (HBITMAP)SelectObject(hdcMem, bitmap_bomba);
                GetObject(bitmap_bomba, sizeof(bm), &bm);     //imprimir la imagen de la bomba


                Sleep(500);
                //MessageBox(0, NULL, NULL, MB_OK);  //mensaje para decir que rip

            }

            break;  //break del boton 2


        case WM_DESTROY:        //cerrar el programa
            
            
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

            EndPaint(hwnd, &ps);
        }
        return 0;

        }
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}