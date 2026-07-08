
# $Id: testreg.tcl,v 1.4 2025/08/01 04:56:10 cvswxc Exp $
#argv should be list of languages assumed to be enabled
set testlog [format "/tmp/testlog%d" [pid]]
set bindingdir [format "/tmp/bindingdir%d" [pid]]
set serverlog [format "%s%s" $testlog "-server"]
set clientlog [format "%s%s" $testlog "-client"]

set iluhome $env(ILUHOME)

set iserror 0

set env(ILU_BINDING_DIRECTORY) $bindingdir

source testprocs.tcl 

# run regression test

run-regression

exit $iserror
