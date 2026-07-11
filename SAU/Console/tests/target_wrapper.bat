@echo off
SetLocal EnableDelayedExpansion
(set PATH=D:\Application\conda\Library\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=D:\Application\conda\Library\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=D:\Application\conda\Library\plugins
)
%*
EndLocal
