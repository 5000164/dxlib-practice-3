#include "../Header/system.h"

void System::Watch() {
  // 異常処理で強制終了
  if (ProcessMessage() == -1) {
    // DXライブラリ使用終了処理
    DxLib_End();

    exit(1);
  }

  return;
}
