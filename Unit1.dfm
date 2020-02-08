object Form1: TForm1
  Left = 192
  Top = 145
  Width = 410
  Height = 477
  Caption = 'Notatnik'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object tresc: TMemo
    Left = 0
    Top = 0
    Width = 394
    Height = 418
    Align = alClient
    ScrollBars = ssBoth
    TabOrder = 0
    OnKeyDown = trescKeyDown
  end
  object MainMenu1: TMainMenu
    Left = 272
    Top = 8
    object Plik1: TMenuItem
      Caption = '&Plik'
      object Nowy1: TMenuItem
        Caption = '&Nowy'
        OnClick = Nowy1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Otwrz1: TMenuItem
        Caption = '&Otw'#243'rz'
        OnClick = Otwrz1Click
      end
      object Zapisz1: TMenuItem
        Caption = '&Zapisz     Ctrl+S'
        OnClick = Zapisz1Click
      end
      object Zapiszjako1: TMenuItem
        Caption = 'Zapi&sz jako'
        OnClick = Zapiszjako1Click
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Zakocz1: TMenuItem
        Caption = 'Zako'#324'&cz'
        OnClick = Zakocz1Click
      end
    end
    object Edycja1: TMenuItem
      Caption = '&Edycja'
      object WytnijCtrlX1: TMenuItem
        Caption = 'W&ytnij       Ctrl+X'
        OnClick = WytnijCtrlX1Click
      end
      object KopiujCtrlC1: TMenuItem
        Caption = 'Kop&iuj     Ctrl+C'
        OnClick = KopiujCtrlC1Click
      end
      object WklejCtrlV1: TMenuItem
        Caption = 'Wkle&j     Ctrl +V'
        OnClick = WklejCtrlV1Click
      end
      object ZaznaczwszystkoCtrlA1: TMenuItem
        Caption = 'Zaznacz wszystko   Ctrl+A'
        OnClick = ZaznaczwszystkoCtrlA1Click
      end
    end
    object Format1: TMenuItem
      Caption = '&Format'
      object Zawijaniewierszy1: TMenuItem
        AutoCheck = True
        Caption = 'Z&awijanie wierszy'
        OnClick = Zawijaniewierszy1Click
      end
      object Czcionka2: TMenuItem
        Caption = 'Czcionka'
        OnClick = Czcionka2Click
      end
    end
    object Pomoc1: TMenuItem
      Caption = 'P&omoc'
      object informacje1: TMenuItem
        Caption = 'i&nformacje'
        object Oprogramie1: TMenuItem
          Caption = 'O programie'
          OnClick = Oprogramie1Click
        end
        object Zapraszamnabloga1: TMenuItem
          Caption = 'Zapraszam na bloga'
          OnClick = Zapraszamnabloga1Click
        end
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = 'Pliki Tekstowe (txt)|*.txt|Wszystkie pliki|*.*'
    Left = 208
    Top = 8
  end
  object SaveDialog1: TSaveDialog
    Filter = 'Plik tekstowy (TXT)|*.txt|Dowolny plik|*.*'
    Options = [ofOverwritePrompt, ofFileMustExist, ofEnableSizing]
    Left = 240
    Top = 8
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Left = 304
    Top = 8
  end
end
