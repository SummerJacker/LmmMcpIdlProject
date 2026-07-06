@echo off
SetLocal EnableDelayedExpansion
(set PATH=H:\computer\qt5.12.4\5.12.4\msvc2017\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=H:\computer\qt5.12.4\5.12.4\msvc2017\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=H:\computer\qt5.12.4\5.12.4\msvc2017\plugins
)
%*
EndLocal
