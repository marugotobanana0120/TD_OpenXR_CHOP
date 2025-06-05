# TD_OpenXR_CHOP
OpenXR View/Projection Matrix exporter for TouchDesigner

# TD_OpenXR_CHOP プロジェクト

このリポジトリは、TouchDesigner用のOpenXR統合CHOPプラグインを提供します。  
左右のView/Projection Matrix（それぞれ16要素、合計64チャンネル）を取得し、CHOPとして出力可能です。

---

## 🔧 対応環境

- TouchDesigner 2023.12370 以降
- Windows 11
- Visual Studio 2022
- OpenXR Runtime: Sony_SpatialRealityDisplay_OpenXrRuntime または互換HMD

---

## 📦 内容物

- `MyOpenXRCHOP.dll`：C++でビルドされたCHOP DLL（Base64形式で提供）
- `src/`：C++ソースコード
- `test_project.toe`：TouchDesigner用の動作サンプル
- `README_ja.md`：このファイル

---

## 🧪 機能概要

| チャンネル名       | 内容                           |
|--------------------|--------------------------------|
| `projL_0`〜`15`     | 左目のProjection行列（列優先） |
| `viewL_0`〜`15`     | 左目のView行列（列優先）       |
| `projR_0`〜`15`     | 右目のProjection行列（列優先） |
| `viewR_0`〜`15`     | 右目のView行列（列優先）       |

---

## 🔨 セットアップ手順

1. `MyOpenXRCHOP.dll` をBase64チャンクを結合して復元
2. `C:/Users/<あなたのユーザー名>/Documents/Derivative/Plugins/` に配置
3. TouchDesignerで `C++ CHOP` を配置し、このDLLを指定
4. 自動で64チャンネルが出力される

---

## 🛠 ビルド方法（Visual Studio 2022）

1. `src/` フォルダにある `.vcxproj` を開く
2. ビルドターゲットを `Release x64` に設定
3. `F7` または `Ctrl+Shift+B` でビルド

---

## 👁 サンプルプロジェクト

- `test_project.toe` を開き、動作確認が可能
- 行列の変化が CHOP で可視化されます

---

## 📩 作者

- @marugotobanana0120
- Special thanks to ChatGPT assistant for C++ integration guidance
