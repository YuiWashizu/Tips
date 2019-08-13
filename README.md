# Tips
## hist_draw_to_pdf
  ROOTで書いた多数のヒストグラムをpdfファイルにまとめて保存する方法.
  
## canvas_divide
  複数のヒストグラムをまとめて1つのキャンバスに描く.

## scripts
  ROOTでプロットする際に読み込ませると楽に書けるクラス達。シンボリックリンクでマクロと同じディレクトリにリンクさせておくといい。
  ```
  % root -l
  root[0] .L ./scripts/AppGraph.C+
  root[1] .x plotting.C+() //plot作成コード
  ```
  でROOT内で利用可能。
  
